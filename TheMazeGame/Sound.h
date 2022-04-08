#ifndef __SOUND_H
#define __SOUND_H


//#if ( _WIN32_WINNT != 0x0601  &&  _WIN32_WINNT != 0x0A00 /*If current windows doesn't equal possible Windows7 codes*/ )
#pragma comment(lib, "Xaudio2.lib")
#include <xaudio2.h>
//#else
//#include <C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\comdecl.h>
//#include <C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\XAudio2.h>
//#include <C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\X3DAudio.h>
//#endif

#define fourccRIFF 'FFIR'
#define fourccDATA 'atad'
#define fourccFMT ' tmf'
#define fourccWAVE 'EVAW'
#define fourccXWMA 'AMWX'
#define fourccDPDS 'sdpd'


class Sound
{
public:
   Sound() { strFileName = TEXT(""); }
   Sound(TCHAR * name, bool loop);
   HRESULT Play();
   HRESULT Stop();
   bool On();

private:
   HRESULT InitializePlayer();
   HRESULT Populate();
   HRESULT FindChunk(HANDLE hFile, DWORD fourcc, DWORD & dwChunkSize, DWORD & dwChunkDataPosition);
   HRESULT ReadChunkData(HANDLE hFile, void * buffer, DWORD buffersize, DWORD bufferoffset);
   HRESULT PrepareSound();

   IXAudio2 * pXAudio2;

   TCHAR * strFileName;

   IXAudio2SourceVoice* pSourceVoice;

   WAVEFORMATEXTENSIBLE wfx = { 0 };
   XAUDIO2_BUFFER buffer = { 0 };

   bool playing;
};

#endif