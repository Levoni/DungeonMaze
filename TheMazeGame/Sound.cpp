#include "Sound.h"

Sound::Sound(TCHAR * name, bool loop)
{
   strFileName = name;
   playing = false;

   if (loop)
      buffer.LoopCount = XAUDIO2_LOOP_INFINITE;

   InitializePlayer();
   Populate();
}

HRESULT Sound::Play()
{
   HRESULT hr = S_OK;
   
   PrepareSound();

   if (FAILED(hr = pSourceVoice->Start(0)))
      return hr;
   playing = true;
   return hr;
}

HRESULT Sound::Stop()
{
   HRESULT hr = S_OK;
   if (FAILED(hr = pSourceVoice->Stop()))
      return hr;
   playing = false;
   return hr;
}

bool Sound::On()
{
   return playing;
}

HRESULT Sound::InitializePlayer()
{
   pXAudio2 = NULL;
   HRESULT hr = S_OK;
   if (FAILED(hr = XAudio2Create(&pXAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR)))
      return hr;

   IXAudio2MasteringVoice* pMasterVoice = NULL;
   if (FAILED(hr = pXAudio2->CreateMasteringVoice(&pMasterVoice)))
      return hr;

   return hr;
}

HRESULT Sound::Populate()
{
   HANDLE hFile = CreateFile(strFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

   if (INVALID_HANDLE_VALUE == hFile)
      return HRESULT_FROM_WIN32(GetLastError());

   if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, 0, NULL, FILE_BEGIN))
      return HRESULT_FROM_WIN32(GetLastError());

   DWORD dwChunkSize;
   DWORD dwChunkPosition;
   FindChunk(hFile, fourccRIFF, dwChunkSize, dwChunkPosition);
   DWORD filetype;
   ReadChunkData(hFile, &filetype, sizeof(DWORD), dwChunkPosition);
   if (filetype != fourccWAVE)
      return S_FALSE;

   FindChunk(hFile, fourccFMT, dwChunkSize, dwChunkPosition);
   ReadChunkData(hFile, &wfx, dwChunkSize, dwChunkPosition);

   FindChunk(hFile, fourccDATA, dwChunkSize, dwChunkPosition);
   BYTE * pDataBuffer = new BYTE[dwChunkSize];
   ReadChunkData(hFile, pDataBuffer, dwChunkSize, dwChunkPosition);

   buffer.AudioBytes = dwChunkSize;
   buffer.pAudioData = pDataBuffer;
   buffer.Flags = XAUDIO2_END_OF_STREAM;

   return S_OK;
}

HRESULT Sound::FindChunk(HANDLE hFile, DWORD fourcc, DWORD & dwChunkSize, DWORD & dwChunkDataPosition)
{
   HRESULT hr = S_OK;
   if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, 0, NULL, FILE_BEGIN))
      return HRESULT_FROM_WIN32(GetLastError());

   DWORD dwChunkType;
   DWORD dwChunkDataSize;
   DWORD dwRIFFDataSize = 0;
   DWORD dwFileType;
   DWORD bytesRead = 0;
   DWORD dwOffset = 0;

   while (hr == S_OK)
   {
      DWORD dwRead;
      if (0 == ReadFile(hFile, &dwChunkType, sizeof(DWORD), &dwRead, NULL))
         hr = HRESULT_FROM_WIN32(GetLastError());
      if (0 == ReadFile(hFile, &dwChunkDataSize, sizeof(DWORD), &dwRead, NULL))
         hr = HRESULT_FROM_WIN32(GetLastError());

      switch (dwChunkType)
      {
      case fourccRIFF:
         dwRIFFDataSize = dwChunkDataSize;
         dwChunkDataSize = 4;
         if (0 == ReadFile(hFile, &dwFileType, sizeof(DWORD), &dwRead, NULL))
            hr = HRESULT_FROM_WIN32(GetLastError());
         break;
      default:
         if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, dwChunkDataSize, NULL, FILE_CURRENT))
            return HRESULT_FROM_WIN32(GetLastError());
      }

      dwOffset += sizeof(DWORD) * 2;

      if (dwChunkType == fourcc)
      {
         dwChunkSize = dwChunkDataSize;
         dwChunkDataPosition = dwOffset;
         return S_OK;
      }

      dwOffset += dwChunkDataSize;

      if (bytesRead >= dwRIFFDataSize)
         return S_FALSE;
   }

   return S_OK;
}

HRESULT Sound::ReadChunkData(HANDLE hFile, void * buffer, DWORD buffersize, DWORD bufferoffset)
{
   HRESULT hr = S_OK;
   if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, bufferoffset, NULL, FILE_BEGIN))
      return HRESULT_FROM_WIN32(GetLastError());
   DWORD dwRead;
   if (0 == ReadFile(hFile, buffer, buffersize, &dwRead, NULL))
      hr = HRESULT_FROM_WIN32(GetLastError());
   return hr;
}

HRESULT Sound::PrepareSound()
{
   HRESULT hr = S_OK;
   
   if (FAILED(hr = pXAudio2->CreateSourceVoice(&pSourceVoice, (WAVEFORMATEX*)&wfx)))
      return hr;
   if (FAILED(hr = pSourceVoice->SubmitSourceBuffer(&buffer)))
      return hr;
   return hr;
}