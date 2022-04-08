#pragma once
#include "GameManager.h"
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
#include <string.h>
#include <msclr\marshal_cppstd.h> 
#include "GamePanel.h"

#include "AudioManager.h"

//#include <SFML/Audio.hpp>

//#define __NOFLICKER //Uncomment this so there is no flickering Recomment this so you can edit the GUI
//#define __NOFLICKER2

namespace TheMazeGame
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

   using namespace System::Threading;

	typedef std::pair<int, int> Key;

	/// Summary for Maze
	/// </summary>
	public ref class Maze : public System::Windows::Forms::Form
	{
	public:
		GameManager *Manager;
      AudioManager * audioManager;
		const int EASY = 10;
		const int MEDIUM = 20;
		const int HARD = 30;
		const int TUT = 10;
      Bitmap^ tileFloor = gcnew Bitmap("tileFloor.png");
		Bitmap^ tileUp = gcnew Bitmap("tileUpstairs.png");
		Bitmap^ tileDown = gcnew Bitmap("tileDownstairs.png");
		Bitmap^ doorTile = gcnew Bitmap("door.png");
		Bitmap^ heart = gcnew Bitmap("heart.png");
		Bitmap^ flashlight = gcnew Bitmap("flashlight.png");
		Bitmap^ estrg = gcnew Bitmap("ignoreThisImage.png");
		Bitmap^ flashlight_special =
			gcnew Bitmap("flashlight_special.png");
		Bitmap^ HelmZero = gcnew Bitmap("armor0.png");
		Bitmap^ HelmOne = gcnew Bitmap("armor1.png");
		Bitmap^ HelmTwo = gcnew Bitmap("armor2.png");
		Bitmap^ HelmThree = gcnew Bitmap("armor3.png");
		Bitmap^ doorKey = gcnew Bitmap("itemKey.png");

		//Character Movement


		Bitmap^ heroIrLeft = gcnew Bitmap("heroIronArmor_L.png");
		Bitmap^ heroIrRight = gcnew Bitmap("heroIronArmor_R.png");
		Bitmap^ heroIrDown = gcnew Bitmap("heroIronArmor_D.png");
		Bitmap^ heroIrUp = gcnew Bitmap("heroIronArmor_U.png");

		Bitmap^ heroNoLeft = gcnew Bitmap("heroNoArmor_L.png");
		Bitmap^ heroNoRight = gcnew Bitmap("heroNoArmor_R.png");
		Bitmap^ heroNoDown = gcnew Bitmap("heroNoArmor_D.png");
		Bitmap^ heroNoUp = gcnew Bitmap("heroNoArmor_U.png");

      Bitmap^ heroTwoLeft = gcnew Bitmap("heroArmorTwo_L.png");
      Bitmap^ heroTwoRight = gcnew Bitmap("heroArmorTwo_R.png");
      Bitmap^ heroTwoDown = gcnew Bitmap("heroArmorTwo_D.png");
      Bitmap^ heroTwoUp = gcnew Bitmap("heroArmorTwo_U.png");

      Bitmap^ heroThreeLeft = gcnew Bitmap("heroArmorThree_L.png");
      Bitmap^ heroThreeRight = gcnew Bitmap("heroArmorThree_R.png");
      Bitmap^ heroThreeDown = gcnew Bitmap("heroArmorThree_D.png");
      Bitmap^ heroThreeUp = gcnew Bitmap("heroArmorThree_U.png");

      // Image if proper Image is missing
		Bitmap^ charLeft = gcnew Bitmap("default_L.png");
		Bitmap^ charRight = gcnew Bitmap("default_R.png");
		Bitmap^ charDown = gcnew Bitmap("default_D.png");
		Bitmap^ charUp = gcnew Bitmap("default_U.png");

      // Bat enemy image
		Bitmap^ batLeft = gcnew Bitmap("enemyBat_L.png");
		Bitmap^ batRight = gcnew Bitmap("enemyBat_R.png");
		Bitmap^ batDown = gcnew Bitmap("enemyBat_D.png");
		Bitmap^ batUp = gcnew Bitmap("enemyBat_U.png");

		Bitmap^ slimeDown = gcnew Bitmap("enemySlime_D.png");
      Bitmap^ slimeUp = gcnew Bitmap("enemySlime_U.png");
      Bitmap^ slimeRight = gcnew Bitmap("enemySlime_R.png");
      Bitmap^ slimeLeft = gcnew Bitmap("enemySlime_L.png");

      Bitmap^ spiderDown = gcnew Bitmap("enemySpider_D.png");
      Bitmap^ spiderUp = gcnew Bitmap("enemySpider_U.png");
      Bitmap^ spiderRight = gcnew Bitmap("enemySpider_R.png");
      Bitmap^ spiderLeft = gcnew Bitmap("enemySpider_L.png");

		Bitmap^ curWeapon;

      Bitmap^ SwordZero = gcnew Bitmap("weapon0.png");
		Bitmap^ SwordZeroU = gcnew Bitmap("weapon0.png");
		Bitmap^ SwordZeroL = gcnew Bitmap("weapon0.png");
		Bitmap^ SwordZeroD = gcnew Bitmap("weapon0.png");

		Bitmap^ SwordOne = gcnew Bitmap("weapon1.png");
		Bitmap^ SwordOneU = gcnew Bitmap("weapon1.png");
		Bitmap^ SwordOneL = gcnew Bitmap("weapon1.png");
		Bitmap^ SwordOneD = gcnew Bitmap("weapon1.png");

		Bitmap^ SwordTwo = gcnew Bitmap("weapon2.png");
		Bitmap^ SwordTwoU = gcnew Bitmap("weapon2.png");
		Bitmap^ SwordTwoL = gcnew Bitmap("weapon2.png");
		Bitmap^ SwordTwoD = gcnew Bitmap("weapon2.png");

		Bitmap^ SwordThree = gcnew Bitmap("weapon3.png");
		Bitmap^ SwordThreeU = gcnew Bitmap("weapon3.png");
		Bitmap^ SwordThreeL = gcnew Bitmap("weapon3.png");
		Bitmap^ SwordThreeD = gcnew Bitmap("weapon3.png");

		int screenHeight;
		int screenWidth;
		bool gameRunning = false;
		int size = TUT;
		int attackAnamationStage = 0;
		int playerDir = 0;
		int attackType = 1;
		int easyScore = 0;
		int mediumScore = 0;
		int hardScore = 0;
   private: System::Windows::Forms::GroupBox^  grpSettings;
   public:

   //private: System::Media::SoundPlayer^ Intro = gcnew System::Media::SoundPlayer("tetris-gameboy-02.wav");
   //private: System::Media::SoundPlayer^ BGM = gcnew System::Media::SoundPlayer("98_Lost_Mine.wav");
   //private: System::Media::SoundPlayer^ Death = gcnew System::Media::SoundPlayer("LastCallForAHero.wav");

	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::GroupBox^  grpDifficutly;

	private: System::Windows::Forms::RadioButton^  radHard;

	private: System::Windows::Forms::RadioButton^  radEasy;
	private: System::Windows::Forms::RadioButton^  radMedium;
	private: System::Windows::Forms::GroupBox^  grpAdvanced;
	private: System::Windows::Forms::GroupBox^  grpExtra;


	private: System::Windows::Forms::Label^  lblScore;
	private: System::Windows::Forms::Label^  lblHealth;
	private: System::Windows::Forms::ProgressBar^  progHealthBar;
	private: System::Windows::Forms::Label^  lblHealthOutput;
	private: System::Windows::Forms::Label^  lblLevel;

	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::GroupBox^  grpGameStats;
	private: System::Windows::Forms::Label^  lblHighScore;



	private: System::Windows::Forms::Label^  lblHighHard;

	private: System::Windows::Forms::Label^  lblHighMedium;

	private: System::Windows::Forms::Label^  lblHighEasy;
	private: System::Windows::Forms::Label^  lblDamage;
	private: System::Windows::Forms::Label^  lblArmor;
	private: System::Windows::Forms::Button^  btnQuit;
	private: System::Windows::Forms::ProgressBar^  progBonus;

	private: System::Windows::Forms::Label^  lblBonus;
	private: System::Windows::Forms::Label^  lblBPoints;



	public:
		int temp = 10;

		Maze(void)
		{
			InitializeComponent();
			txtInstructions->Text = gcnew String(Manager->GetInstructions().c_str());
			RECT desktop;
			const HWND hDesktop = GetDesktopWindow();
			GetWindowRect(hDesktop, &desktop);
			this->Height = desktop.bottom;
			this->Width = desktop.right;

         audioManager = new AudioManager();

			SwordOneU->RotateFlip(RotateFlipType::Rotate270FlipNone);
			SwordOneD->RotateFlip(RotateFlipType::Rotate90FlipX);
			SwordOneL->RotateFlip(RotateFlipType::Rotate180FlipNone);

			SwordZeroU->RotateFlip(RotateFlipType::Rotate270FlipNone);
			SwordZeroD->RotateFlip(RotateFlipType::Rotate90FlipX);
			SwordZeroL->RotateFlip(RotateFlipType::Rotate180FlipNone);

			SwordTwoU->RotateFlip(RotateFlipType::Rotate270FlipNone);
			SwordTwoD->RotateFlip(RotateFlipType::Rotate90FlipX);
			SwordTwoL->RotateFlip(RotateFlipType::Rotate180FlipNone);

			SwordThreeU->RotateFlip(RotateFlipType::Rotate270FlipNone);
			SwordThreeD->RotateFlip(RotateFlipType::Rotate90FlipX);
			SwordThreeL->RotateFlip(RotateFlipType::Rotate180FlipNone);

         //Intro->PlayLooping();
         audioManager->PlayIntro();

         //audioManager->PlayBackground();
         //audioManager.StopBackground();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Maze()
		{
			if (components)
			{
				delete components;
			}
			if (Manager)
				delete Manager;
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:






   private: GamePanel^  panel1;
	//private: System::Windows::Forms::Panel^  panel1;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::ToolStripMenuItem^  instructionsToolStripMenuItem;
	private: System::Windows::Forms::Panel^  pnlInstructions;
	private: System::Windows::Forms::TextBox^  txtInstructions;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
	  /// <summary>
	  /// Required method for Designer support - do not modify
	  /// the contents of this method with the code editor.
	  /// </summary>
		void InitializeComponent(void)
		{
         this->components = (gcnew System::ComponentModel::Container());
         this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
         this->instructionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         //this->panel1 = (gcnew System::Windows::Forms::Panel());
         this->panel1 = (gcnew GamePanel());
         this->pnlInstructions = (gcnew System::Windows::Forms::Panel());
         this->lblHighHard = (gcnew System::Windows::Forms::Label());
         this->lblHighMedium = (gcnew System::Windows::Forms::Label());
         this->lblHighEasy = (gcnew System::Windows::Forms::Label());
         this->lblHighScore = (gcnew System::Windows::Forms::Label());
         this->grpSettings = (gcnew System::Windows::Forms::GroupBox());
         this->grpAdvanced = (gcnew System::Windows::Forms::GroupBox());
         this->grpExtra = (gcnew System::Windows::Forms::GroupBox());
         this->grpDifficutly = (gcnew System::Windows::Forms::GroupBox());
         this->radHard = (gcnew System::Windows::Forms::RadioButton());
         this->radEasy = (gcnew System::Windows::Forms::RadioButton());
         this->radMedium = (gcnew System::Windows::Forms::RadioButton());
         this->btnStart = (gcnew System::Windows::Forms::Button());
         this->txtInstructions = (gcnew System::Windows::Forms::TextBox());
         this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
         this->lblScore = (gcnew System::Windows::Forms::Label());
         this->lblHealth = (gcnew System::Windows::Forms::Label());
         this->progHealthBar = (gcnew System::Windows::Forms::ProgressBar());
         this->lblHealthOutput = (gcnew System::Windows::Forms::Label());
         this->lblLevel = (gcnew System::Windows::Forms::Label());
         this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
         this->grpGameStats = (gcnew System::Windows::Forms::GroupBox());
         this->lblBPoints = (gcnew System::Windows::Forms::Label());
         this->progBonus = (gcnew System::Windows::Forms::ProgressBar());
         this->lblBonus = (gcnew System::Windows::Forms::Label());
         this->lblDamage = (gcnew System::Windows::Forms::Label());
         this->lblArmor = (gcnew System::Windows::Forms::Label());
         this->btnQuit = (gcnew System::Windows::Forms::Button());
         this->menuStrip1->SuspendLayout();
         this->panel1->SuspendLayout();
         this->pnlInstructions->SuspendLayout();
         this->grpSettings->SuspendLayout();
         this->grpDifficutly->SuspendLayout();
         this->grpGameStats->SuspendLayout();
         this->SuspendLayout();
         // 
         // menuStrip1
         // 
         this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->instructionsToolStripMenuItem });
         this->menuStrip1->Location = System::Drawing::Point(0, 0);
         this->menuStrip1->Name = L"menuStrip1";
         this->menuStrip1->Size = System::Drawing::Size(741, 24);
         this->menuStrip1->TabIndex = 0;
         this->menuStrip1->Text = L"menuStrip1";
         // 
         // instructionsToolStripMenuItem
         // 
         this->instructionsToolStripMenuItem->Name = L"instructionsToolStripMenuItem";
         this->instructionsToolStripMenuItem->Size = System::Drawing::Size(50, 20);
         this->instructionsToolStripMenuItem->Text = L"Menu";
         this->instructionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Maze::instructionsToolStripMenuItem_Click);
         // 
         // panel1
         // 
         this->panel1->BackColor = System::Drawing::SystemColors::Control;
         this->panel1->Controls->Add(this->pnlInstructions);
         this->panel1->Location = System::Drawing::Point(0, 24);
         this->panel1->Margin = System::Windows::Forms::Padding(0);
         this->panel1->Name = L"panel1";
         this->panel1->Size = System::Drawing::Size(452, 452);
         this->panel1->TabIndex = 1;
         this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Maze::panel1_Paint);
         // 
         // pnlInstructions
         // 
         this->pnlInstructions->BackColor = System::Drawing::SystemColors::Control;
         this->pnlInstructions->Controls->Add(this->lblHighHard);
         this->pnlInstructions->Controls->Add(this->lblHighMedium);
         this->pnlInstructions->Controls->Add(this->lblHighEasy);
         this->pnlInstructions->Controls->Add(this->lblHighScore);
         this->pnlInstructions->Controls->Add(this->grpSettings);
         this->pnlInstructions->Controls->Add(this->btnStart);
         this->pnlInstructions->Controls->Add(this->txtInstructions);
         this->pnlInstructions->Location = System::Drawing::Point(0, 1);
         this->pnlInstructions->Margin = System::Windows::Forms::Padding(0);
         this->pnlInstructions->Name = L"pnlInstructions";
         this->pnlInstructions->Size = System::Drawing::Size(449, 447);
         this->pnlInstructions->TabIndex = 1;
         // 
         // lblHighHard
         // 
         this->lblHighHard->AutoSize = true;
         this->lblHighHard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblHighHard->Location = System::Drawing::Point(169, 376);
         this->lblHighHard->Name = L"lblHighHard";
         this->lblHighHard->Size = System::Drawing::Size(110, 31);
         this->lblHighHard->TabIndex = 6;
         this->lblHighHard->Text = L"Hard: 0";
         // 
         // lblHighMedium
         // 
         this->lblHighMedium->AutoSize = true;
         this->lblHighMedium->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblHighMedium->Location = System::Drawing::Point(151, 345);
         this->lblHighMedium->Name = L"lblHighMedium";
         this->lblHighMedium->Size = System::Drawing::Size(148, 31);
         this->lblHighMedium->TabIndex = 5;
         this->lblHighMedium->Text = L"Medium: 0";
         // 
         // lblHighEasy
         // 
         this->lblHighEasy->AutoSize = true;
         this->lblHighEasy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblHighEasy->ForeColor = System::Drawing::SystemColors::ControlText;
         this->lblHighEasy->Location = System::Drawing::Point(167, 314);
         this->lblHighEasy->Name = L"lblHighEasy";
         this->lblHighEasy->Size = System::Drawing::Size(112, 31);
         this->lblHighEasy->TabIndex = 4;
         this->lblHighEasy->Text = L"Easy: 0";
         // 
         // lblHighScore
         // 
         this->lblHighScore->AutoSize = true;
         this->lblHighScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblHighScore->Location = System::Drawing::Point(127, 283);
         this->lblHighScore->Name = L"lblHighScore";
         this->lblHighScore->Size = System::Drawing::Size(190, 31);
         this->lblHighScore->TabIndex = 3;
         this->lblHighScore->Text = L"High Scores: ";
         // 
         // grpSettings
         // 
         this->grpSettings->Controls->Add(this->grpAdvanced);
         this->grpSettings->Controls->Add(this->grpExtra);
         this->grpSettings->Controls->Add(this->grpDifficutly);
         this->grpSettings->Location = System::Drawing::Point(3, 93);
         this->grpSettings->Name = L"grpSettings";
         this->grpSettings->Size = System::Drawing::Size(440, 113);
         this->grpSettings->TabIndex = 2;
         this->grpSettings->TabStop = false;
         this->grpSettings->Text = L"Settings";
         // 
         // grpAdvanced
         // 
         this->grpAdvanced->Location = System::Drawing::Point(302, 19);
         this->grpAdvanced->Name = L"grpAdvanced";
         this->grpAdvanced->RightToLeft = System::Windows::Forms::RightToLeft::No;
         this->grpAdvanced->Size = System::Drawing::Size(132, 88);
         this->grpAdvanced->TabIndex = 2;
         this->grpAdvanced->TabStop = false;
         this->grpAdvanced->Text = L"Advanced";
         // 
         // grpExtra
         // 
         this->grpExtra->Location = System::Drawing::Point(154, 19);
         this->grpExtra->Name = L"grpExtra";
         this->grpExtra->Size = System::Drawing::Size(132, 88);
         this->grpExtra->TabIndex = 1;
         this->grpExtra->TabStop = false;
         this->grpExtra->Text = L"Extra";
         // 
         // grpDifficutly
         // 
         this->grpDifficutly->Controls->Add(this->radHard);
         this->grpDifficutly->Controls->Add(this->radEasy);
         this->grpDifficutly->Controls->Add(this->radMedium);
         this->grpDifficutly->Location = System::Drawing::Point(6, 19);
         this->grpDifficutly->Name = L"grpDifficutly";
         this->grpDifficutly->Size = System::Drawing::Size(132, 88);
         this->grpDifficutly->TabIndex = 0;
         this->grpDifficutly->TabStop = false;
         this->grpDifficutly->Text = L"Difficutly";
         // 
         // radHard
         // 
         this->radHard->AutoSize = true;
         this->radHard->Location = System::Drawing::Point(6, 65);
         this->radHard->Name = L"radHard";
         this->radHard->Size = System::Drawing::Size(48, 17);
         this->radHard->TabIndex = 2;
         this->radHard->Text = L"Hard";
         this->radHard->UseVisualStyleBackColor = true;
         // 
         // radEasy
         // 
         this->radEasy->AutoSize = true;
         this->radEasy->Checked = true;
         this->radEasy->Location = System::Drawing::Point(6, 19);
         this->radEasy->Name = L"radEasy";
         this->radEasy->Size = System::Drawing::Size(48, 17);
         this->radEasy->TabIndex = 0;
         this->radEasy->TabStop = true;
         this->radEasy->Text = L"Easy";
         this->radEasy->UseVisualStyleBackColor = true;
         // 
         // radMedium
         // 
         this->radMedium->AutoSize = true;
         this->radMedium->Location = System::Drawing::Point(6, 42);
         this->radMedium->Name = L"radMedium";
         this->radMedium->Size = System::Drawing::Size(62, 17);
         this->radMedium->TabIndex = 1;
         this->radMedium->Text = L"Medium";
         this->radMedium->UseVisualStyleBackColor = true;
         // 
         // btnStart
         // 
         this->btnStart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
         this->btnStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnStart->Location = System::Drawing::Point(96, 212);
         this->btnStart->Name = L"btnStart";
         this->btnStart->Size = System::Drawing::Size(235, 68);
         this->btnStart->TabIndex = 1;
         this->btnStart->Text = L"Enter";
         this->btnStart->UseVisualStyleBackColor = false;
         this->btnStart->Click += gcnew System::EventHandler(this, &Maze::btnStart_Click);
         // 
         // txtInstructions
         // 
         this->txtInstructions->Location = System::Drawing::Point(3, 6);
         this->txtInstructions->Multiline = true;
         this->txtInstructions->Name = L"txtInstructions";
         this->txtInstructions->ReadOnly = true;
         this->txtInstructions->Size = System::Drawing::Size(440, 81);
         this->txtInstructions->TabIndex = 0;
         this->txtInstructions->TextChanged += gcnew System::EventHandler(this, &Maze::txtInstructions_TextChanged);
         // 
         // timer1
         // 
         this->timer1->Enabled = true;
         this->timer1->Interval = 20;
         this->timer1->Tick += gcnew System::EventHandler(this, &Maze::timer1_Tick);
         // 
         // lblScore
         // 
         this->lblScore->AutoSize = true;
         this->lblScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblScore->Location = System::Drawing::Point(6, 215);
         this->lblScore->Name = L"lblScore";
         this->lblScore->Size = System::Drawing::Size(123, 31);
         this->lblScore->TabIndex = 2;
         this->lblScore->Text = L"Score: 0";
         // 
         // lblHealth
         // 
         this->lblHealth->AutoSize = true;
         this->lblHealth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblHealth->Location = System::Drawing::Point(6, 16);
         this->lblHealth->Name = L"lblHealth";
         this->lblHealth->Size = System::Drawing::Size(108, 31);
         this->lblHealth->TabIndex = 3;
         this->lblHealth->Text = L"Health:";
         // 
         // progHealthBar
         // 
         this->progHealthBar->Location = System::Drawing::Point(120, 19);
         this->progHealthBar->MarqueeAnimationSpeed = 0;
         this->progHealthBar->Name = L"progHealthBar";
         this->progHealthBar->Size = System::Drawing::Size(100, 23);
         this->progHealthBar->Step = 1;
         this->progHealthBar->TabIndex = 4;
         // 
         // lblHealthOutput
         // 
         this->lblHealthOutput->AutoSize = true;
         this->lblHealthOutput->BackColor = System::Drawing::SystemColors::Control;
         this->lblHealthOutput->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->lblHealthOutput->ForeColor = System::Drawing::SystemColors::ControlText;
         this->lblHealthOutput->Location = System::Drawing::Point(153, 45);
         this->lblHealthOutput->Name = L"lblHealthOutput";
         this->lblHealthOutput->Size = System::Drawing::Size(36, 13);
         this->lblHealthOutput->TabIndex = 5;
         this->lblHealthOutput->Text = L"0/100";
         // 
         // lblLevel
         // 
         this->lblLevel->AutoSize = true;
         this->lblLevel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblLevel->Location = System::Drawing::Point(6, 252);
         this->lblLevel->Name = L"lblLevel";
         this->lblLevel->Size = System::Drawing::Size(117, 31);
         this->lblLevel->TabIndex = 6;
         this->lblLevel->Text = L"Level: 0";
         // 
         // grpGameStats
         // 
         this->grpGameStats->Controls->Add(this->lblBPoints);
         this->grpGameStats->Controls->Add(this->progBonus);
         this->grpGameStats->Controls->Add(this->lblBonus);
         this->grpGameStats->Controls->Add(this->lblDamage);
         this->grpGameStats->Controls->Add(this->lblArmor);
         this->grpGameStats->Controls->Add(this->lblHealth);
         this->grpGameStats->Controls->Add(this->lblLevel);
         this->grpGameStats->Controls->Add(this->progHealthBar);
         this->grpGameStats->Controls->Add(this->lblScore);
         this->grpGameStats->Controls->Add(this->lblHealthOutput);
         this->grpGameStats->Location = System::Drawing::Point(455, 25);
         this->grpGameStats->Name = L"grpGameStats";
         this->grpGameStats->Size = System::Drawing::Size(274, 295);
         this->grpGameStats->TabIndex = 7;
         this->grpGameStats->TabStop = false;
         // 
         // lblBPoints
         // 
         this->lblBPoints->AutoSize = true;
         this->lblBPoints->BackColor = System::Drawing::SystemColors::Control;
         this->lblBPoints->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
         this->lblBPoints->ForeColor = System::Drawing::SystemColors::ControlText;
         this->lblBPoints->Location = System::Drawing::Point(162, 200);
         this->lblBPoints->Name = L"lblBPoints";
         this->lblBPoints->RightToLeft = System::Windows::Forms::RightToLeft::No;
         this->lblBPoints->Size = System::Drawing::Size(13, 13);
         this->lblBPoints->TabIndex = 11;
         this->lblBPoints->Text = L"0";
         // 
         // progBonus
         // 
         this->progBonus->Location = System::Drawing::Point(120, 174);
         this->progBonus->Name = L"progBonus";
         this->progBonus->Size = System::Drawing::Size(100, 23);
         this->progBonus->Step = -1;
         this->progBonus->TabIndex = 10;
         this->progBonus->Value = 100;
         // 
         // lblBonus
         // 
         this->lblBonus->AutoSize = true;
         this->lblBonus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblBonus->Location = System::Drawing::Point(6, 166);
         this->lblBonus->Name = L"lblBonus";
         this->lblBonus->Size = System::Drawing::Size(105, 31);
         this->lblBonus->TabIndex = 9;
         this->lblBonus->Text = L"Bonus:";
         // 
         // lblDamage
         // 
         this->lblDamage->AutoSize = true;
         this->lblDamage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblDamage->Location = System::Drawing::Point(6, 115);
         this->lblDamage->Name = L"lblDamage";
         this->lblDamage->Size = System::Drawing::Size(130, 31);
         this->lblDamage->TabIndex = 8;
         this->lblDamage->Text = L"Attack: 0";
         // 
         // lblArmor
         // 
         this->lblArmor->AutoSize = true;
         this->lblArmor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblArmor->Location = System::Drawing::Point(6, 76);
         this->lblArmor->Name = L"lblArmor";
         this->lblArmor->Size = System::Drawing::Size(125, 31);
         this->lblArmor->TabIndex = 7;
         this->lblArmor->Text = L"Armor: 0";
         // 
         // btnQuit
         // 
         this->btnQuit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
         this->btnQuit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnQuit->Location = System::Drawing::Point(455, 411);
         this->btnQuit->Margin = System::Windows::Forms::Padding(0);
         this->btnQuit->Name = L"btnQuit";
         this->btnQuit->RightToLeft = System::Windows::Forms::RightToLeft::No;
         this->btnQuit->Size = System::Drawing::Size(274, 65);
         this->btnQuit->TabIndex = 8;
         this->btnQuit->Text = L"Quit";
         this->btnQuit->UseVisualStyleBackColor = false;
         this->btnQuit->Click += gcnew System::EventHandler(this, &Maze::btnQuit_Click);
         // 
         // Maze
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(741, 508);
         this->Controls->Add(this->btnQuit);
         this->Controls->Add(this->grpGameStats);
         this->Controls->Add(this->panel1);
         this->Controls->Add(this->menuStrip1);
         this->DoubleBuffered = true;
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
         this->MainMenuStrip = this->menuStrip1;
         this->Name = L"Maze";
         this->Text = L"Maze";
         this->TopMost = true;
         this->SizeChanged += gcnew System::EventHandler(this, &Maze::Maze_SizeChanged);
         this->menuStrip1->ResumeLayout(false);
         this->menuStrip1->PerformLayout();
         this->panel1->ResumeLayout(false);
         this->pnlInstructions->ResumeLayout(false);
         this->pnlInstructions->PerformLayout();
         this->grpSettings->ResumeLayout(false);
         this->grpDifficutly->ResumeLayout(false);
         this->grpDifficutly->PerformLayout();
         this->grpGameStats->ResumeLayout(false);
         this->grpGameStats->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
		//-----------------------------------------------------------------------
		// Closes the application
		//-----------------------------------------------------------------------
	private: System::Void closeToolStripMenuItem_Click
			 (System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}

			 //-----------------------------------------------------------------------
			 // Updates gui for changes in player and enemy position
			 //-----------------------------------------------------------------------
	private: System::Void timer1_Tick
			 (System::Object^ sender, System::EventArgs^ e)
	{

		if (Manager)
		{
			if (Manager->GetCharacterManager()->GetHero()->GetHealth() <= 0)
				GameOver();
			else
			{
				size = Manager->gameMap->GetMapSize();

            bool walking = false;
			Manager->GetCharacterManager()->GetHero()->SetIsStraffing(false);

				//keycheck, then move player
			if (GetKeyState(VK_LSHIFT) & 0x8000)
			{
				Manager->GetCharacterManager()->GetHero()->SetIsStraffing(true);
			}
            if (GetKeyState(VK_UP) & 0x8000)
            {
               Manager->MovePlayer(5);
               walking = true;
            }		
            if (GetKeyState(VK_DOWN) & 0x8000)
            {
               Manager->MovePlayer(2);
               walking = true;
            }
            if (GetKeyState(VK_LEFT) & 0x8000)
            {
               Manager->MovePlayer(1);
               walking = true;
            }
            if (GetKeyState(VK_RIGHT) & 0x8000)
            {
               Manager->MovePlayer(3);
               walking = true;
            }

            if (walking && !audioManager->PlayingWalk())
               audioManager->PlayWalk();

            if (!walking && audioManager->PlayingWalk())
               audioManager->StopWalk();

            if (Manager->GetCharacterManager()->GetHero()->FlashlightJustCollected())
               audioManager->PlayFlipSwitchOn();

            if (Manager->GetCharacterManager()->GetHero()->FlashlightJustExpired())
               audioManager->PlayFlipSwitchOff();

            if (Manager->GetCharacterManager()->GetHero()->WeaponArmorJustCollected())
               audioManager->PlayEquipArmor();

            if (Manager->GetCharacterManager()->GetHero()->CharacterJustHit())
               if (Manager->GetCharacterManager()->GetHero()->GetArmorRarity() > 0)
                  audioManager->PlayHitArmor();
               else
                  audioManager->PlayHitSkin();

            if (Manager->GetCharacterManager()->EnemyHit() || Manager->GetCharacterManager()->GetEnemyDied())
               audioManager->PlayHitEnemy();

            if (Manager->gameMap->DoorJustUnlocked())
            {
               audioManager->PlayDoorUnlock();
               audioManager->PlayDoorOpen();
            }

            if (Manager->GetCharacterManager()->GetHero()->KeyJustCollected())
               audioManager->PlayCollectKey();

            if (Manager->GetCharacterManager()->GetHero()->HealthJustCollected())
               audioManager->PlayRestoreHealth();

				//move enemies
				Manager->GetCharacterManager()->MoveAllEnemies();
				Manager->checkPlayerHit();
				//counter for animating sword swing
				if (attackAnamationStage > 0)
					--attackAnamationStage;
				if (attackAnamationStage == 0)
				{
					Manager->GetCharacterManager()->ResetEnemyIsHit();
				}

				if (Manager->GetCharacterManager()->GetHero()->AttackCoolDown() == 0 )// PlayerAttackCoolDown() == 0)
				{
					if (GetKeyState(0x46) & 0x8000) // if F is pressed
					{
						Manager->GetCharacterManager()->GetHero()->Attack();
						attackAnamationStage = 5;
						attackType = 1;

                  audioManager->PlaySwordSwing();
					}
					if (GetKeyState(0x44) & 0x8000) // if D is pressed
					{
						Manager->GetCharacterManager()->GetHero()->Attack();
						attackAnamationStage = 5;
						attackType = 2;

                  audioManager->PlaySwordSwing();
					}

				}

				//update bonus
				progBonus->Value = Manager->getBonus();

				//pictureBox1->Location = Point(Manager->GetLocation()->first,
				//   Manager->GetLocation()->second);

				if (Manager->gameMap->PathsNeeded()) //For when creating a new map
				{
					Manager->gameMap->MakePaths();
					Manager->gameMap->addExtraPaths();
				}
				DrawMap();





				//Displaying Details/Player stats
				progHealthBar->Value = Manager->GetCharacterManager()->GetHero()->GetHealth();// getPlayerHealth();
				lblHealthOutput->Text = Manager->GetCharacterManager()->GetHero()->GetHealth() + "/100";

				lblArmor->Text = "Armor: " + Manager->GetCharacterManager()->GetHero()->GetArmor();// getPlayerArmor();
				lblDamage->Text = "Attack: " + Manager->GetCharacterManager()->GetHero()->GetAttackDamage();// getPlayerDamage();
				lblBPoints->Text = progBonus->Value + "";
				lblScore->Text = "Score: " + Manager->getScore();
				lblLevel->Text = "Level: " + Manager->gameMap->GetLevel();

				if (radEasy->Checked)
					if (easyScore < Manager->getScore())
						lblHighEasy->Text = "Easy: " + Manager->getScore();
					else if (radMedium->Checked)
						if (mediumScore < Manager->getScore())
							lblHighMedium->Text = "Medium: " + Manager->getScore();
						else if (radHard->Checked)
							if (hardScore < Manager->getScore())
								lblHighHard->Text = "Hard: " + Manager->getScore();

				Manager->coolDownTick();
			}
		}
	}

	private: System::Void instructionsToolStripMenuItem_Click
			 (System::Object^  sender, System::EventArgs^  e)
	{

		//txtInstructions->Text = gcnew String(map->getInstructions().c_str());
		//if (Manager)
		//{
      if (gameRunning)
         pnlInstructions->Visible = !pnlInstructions->Visible;
      else
      {
         pnlInstructions->Visible = true;
         if (audioManager->PlayingDeath())
            audioManager->StopDeath();
         if (!audioManager->PlayingIntro())
            audioManager->PlayIntro();
      }
		//DrawMap();
	 //}
	}

	private: System::Void DrawMap()
	{
		panel1->Invalidate();
	}

	private: System::Void easyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		size = EASY; //For Now
	}

	private: System::Void mediumToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		size = MEDIUM;
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{
		if (gameRunning)
		{
			//sets tile spacing and wall girth based on map and panel size
			int ySpacing = panel1->Height / size;
			int xSpacing = panel1->Width / size;
			int lr_wallGirth = (xSpacing / 25) + 1;
			int tb_wallGirth = (ySpacing / 25) + 1;


			Manager->SetLineOfSightHelper();
			System::Drawing::SolidBrush ^myBrush =
				gcnew System::Drawing::SolidBrush(Color::Black);
			std::map<Key, Tile*> *tileMap = Manager->gameMap->GetTileMap();

			// Draw Player Attack
			playerDir = Manager->GetCharacterManager()->GetHero()->GetDirection();
			int PX = Manager->GetCharacterManager()->GetHero()->GetLocation()->first;
			int PY = Manager->GetCharacterManager()->GetHero()->GetLocation()->second;
			int curx = PX / xSpacing;
			int cury = PY / ySpacing;
			int pwidth = Manager->GetCharacterManager()->GetHero()->GetWidth();
			int pheight = Manager->GetCharacterManager()->GetHero()->GetHeight();
			int swingDistance = 0;

			//draw sword swing for up and right
			if (attackAnamationStage > 0)
			{
				if (Manager->GetCharacterManager()->GetHero()->GetWeaponRarity() == 0)
				{
					if (playerDir == 5)
					{
						curWeapon = SwordZeroU;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							swingDistance = (Manager->GetCharacterManager()->GetHero()->GetWidth() / 2) - ((Manager->GetCharacterManager()->GetHero()->GetWidth() / 2) / 5) * attackAnamationStage;
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}

					}
					else if (playerDir == 3)
					{
						curWeapon = SwordZero;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2);

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2);

							Manager->checkCollision(attackType);
						}
					}
				}
				if (Manager->GetCharacterManager()->GetHero()->GetWeaponRarity() == 1)
				{
					if (playerDir == 5)
					{
						curWeapon = SwordOneU;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}

					}
					else if (playerDir == 3)
					{
						curWeapon = SwordOne;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2);

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2);

							Manager->checkCollision(attackType);
						}
					}
				}
				if (Manager->GetCharacterManager()->GetHero()->GetWeaponRarity() == 2)
				{
					if (playerDir == 5)
					{
						curWeapon = SwordTwoU;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}

					}
					else if (playerDir == 3)
					{
						curWeapon = SwordTwo;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2);

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2);

							Manager->checkCollision(attackType);
						}
					}
				}
				if (Manager->GetCharacterManager()->GetHero()->GetWeaponRarity() == 3)
				{
					if (playerDir == 5)
					{
						curWeapon = SwordThreeU;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}

					}
					else if (playerDir == 3)
					{
						curWeapon = SwordThree;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2);

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2);

							Manager->checkCollision(attackType);
						}
					}
				}
			}


			//draw maze in current view
			for (int y = 0; y < size; y++)
				for (int x = 0; x < size; x++)
				{
					//draws tile details if the tile is visible
					if ((*tileMap)[Key(x, y)]->GetLightLevel() > 0)
					{
						Key startOrigin = Manager->gameMap->GetStartPoint();
						Key finishOrigin = Manager->gameMap->GetFinishPoint();

						//draw start tile
						if (x == startOrigin.first && y == startOrigin.second)
						{
							//Bitmap^ tempTile = gcnew Bitmap("tileUpstairs.png");
							e->Graphics->DrawImage(tileUp,
								xSpacing * startOrigin.first,
								ySpacing * startOrigin.second,
								xSpacing,
								ySpacing);
						}
						//draw door
						else if (x == finishOrigin.first && y == finishOrigin.second)
						{
                     if(!Manager->gameMap->isUnlocked())
							   //Bitmap^ tempTile = gcnew Bitmap("door.png");
							   e->Graphics->DrawImage(doorTile,
								   xSpacing*finishOrigin.first,
								   ySpacing*finishOrigin.second,
								   xSpacing, ySpacing);
                     else
                        //Bitmap^ tempTile = gcnew Bitmap("tileDownstairs.png");
                        e->Graphics->DrawImage(tileDown,
								   xSpacing * finishOrigin.first,
								   ySpacing * finishOrigin.second,
								   xSpacing,
								   ySpacing);
						}
                  //draw finish tile     
                  /*else
                     e->Graphics->DrawImage(tileFloor,
                        xSpacing*x,
                        ySpacing*y,
                        xSpacing, ySpacing); */

						//draw powerups
						if ((*tileMap)[Key(x, y)]->HasPowerUp())
						{
							//draw restore health powerup
							if ((*tileMap)[Key(x, y)]->GetPowerUpType() == 3)
							{
								//Bitmap^ heart = gcnew Bitmap("heart.png");
								e->Graphics->DrawImage(heart,
									xSpacing * x,
									ySpacing * y,
									xSpacing,
									ySpacing);
							}
							//draw vision boost powerup
							if ((*tileMap)[Key(x, y)]->GetPowerUpType() == 2)
							{
								//Bitmap^ flashlight = gcnew Bitmap("flashlight.png");
								e->Graphics->DrawImage(flashlight,
									xSpacing * x,
									ySpacing * y,
									xSpacing,
									ySpacing);
							}
							//draw full visibility powerup
							if ((*tileMap)[Key(x, y)]->GetPowerUpType() == 1)
							{
								//Bitmap^ flashlight_special =
								//  gcnew Bitmap("flashlight_special.png");
								e->Graphics->DrawImage(flashlight_special,
									xSpacing * x,
									ySpacing * y,
									xSpacing,
									ySpacing);
							}
						}

						//draw in items
						if ((*tileMap)[Key(x, y)]->HasItem())
						{
							if ((*tileMap)[Key(x, y)]->GetItemType() == 1)
							{
								if ((*tileMap)[Key(x, y)]->GetItemRarity() == 1)
								{
									//Bitmap^ SwordOne = gcnew Bitmap("tileSwordOne.png");
									e->Graphics->DrawImage(SwordOne,
										xSpacing * x,
										ySpacing * y + ySpacing / 4,
										xSpacing,
										ySpacing / 2);
								}
								if ((*tileMap)[Key(x, y)]->GetItemRarity() == 2)
								{
									//Bitmap^ SwordTwo = gcnew Bitmap("tileSwordTwo.png");
									e->Graphics->DrawImage(SwordTwo,
										xSpacing * x,
										ySpacing * y + ySpacing / 4,
										xSpacing,
										ySpacing / 2);
								}
								if ((*tileMap)[Key(x, y)]->GetItemRarity() == 3)
								{
									//Bitmap^ SwordThree = gcnew Bitmap("tileSwordThree.png");
									e->Graphics->DrawImage(SwordThree,
										xSpacing * x,
										ySpacing * y + ySpacing / 4,
										xSpacing,
										ySpacing / 2);
								}
							}
							else if ((*tileMap)[Key(x, y)]->GetItemType() == 2)
							{
								if ((*tileMap)[Key(x, y)]->GetItemRarity() == 1)
								{
									//Bitmap^ HelmOne = gcnew Bitmap("tileHelmetOne.png");
									e->Graphics->DrawImage(HelmOne,
										xSpacing * x,
										ySpacing * y,
										xSpacing,
										ySpacing);
								}
								if ((*tileMap)[Key(x, y)]->GetItemRarity() == 2)
								{
									//Bitmap^ HelmTwo = gcnew Bitmap("tileHelmetTwo.png");
									e->Graphics->DrawImage(HelmTwo,
										xSpacing * x,
										ySpacing * y,
										xSpacing,
										ySpacing);
								}
								if ((*tileMap)[Key(x, y)]->GetItemRarity() == 3)
								{
									//Bitmap^ HelmThree = gcnew Bitmap("tileHelmetThree.png");
									e->Graphics->DrawImage(HelmThree,
										xSpacing * x,
										ySpacing * y,
										xSpacing,
										ySpacing);
								}
							}
							else if ((*tileMap)[Key(x, y)]->GetItemType() == 3)
							{
								//Bitmap^ doorKey = gcnew Bitmap("tileKey.png");
								e->Graphics->DrawImage(doorKey,
									xSpacing * x,
									ySpacing * y,
									xSpacing,
									ySpacing);
							}
						}

						//shade tile for its light level
						int opacity = 255 - (255 / Manager->GetCharacterManager()->GetHero()->GetSightRange() * //GetPlayerSightRange() *
							(*tileMap)[Key(x, y)]->GetLightLevel());
						myBrush->Color = Color::FromArgb(opacity, Color::Black);
						e->Graphics->FillRectangle(myBrush,
							System::Drawing::Rectangle(x*xSpacing, y*ySpacing,
								xSpacing, ySpacing));
					}
				}

			//draw enemies
			int tempPosX = Manager->GetCharacterManager()->GetHero()->GetLocation()->first;
			int tempPosY = Manager->GetCharacterManager()->GetHero()->GetLocation()->second;
			int tempWidth = Manager->GetCharacterManager()->GetHero()->GetWidth();
			int tempHeight = Manager->GetCharacterManager()->GetHero()->GetHeight();
			int tempDir = Manager->GetCharacterManager()->GetHero()->GetDirection();
			int tempArmor = Manager->GetCharacterManager()->GetHero()->GetArmor();
			Bitmap^ characterImg;

			int index = 0;
			string tempImgName;
			Enemy* tempEnemy = Manager->GetCharacterManager()->GetEnemy(index);
			while (tempEnemy != NULL)
			{
				tempPosX = tempEnemy->GetLocation()->first;
				tempPosY = tempEnemy->GetLocation()->second;
				tempWidth = tempEnemy->GetWidth();
				tempHeight = tempEnemy->GetHeight();
				tempDir = tempEnemy->GetDirection();

				tempImgName = tempEnemy->GetImgName();

				if (tempImgName == "enemyBat")
				{
					if (tempDir == 1)
						characterImg = batLeft;
					if (tempDir == 3)
						characterImg = batRight;
					if (tempDir == 2)
						characterImg = batDown;
					if (tempDir == 5)
						characterImg = batUp;
				}
				else if (tempImgName == "enemySlime")
				{
					if (tempDir == 1)
						characterImg = slimeLeft;
					if (tempDir == 3)
						characterImg = slimeRight;
					if (tempDir == 2)
						characterImg = slimeDown;
					if (tempDir == 5)
						characterImg = slimeUp;
				}
				else if(tempImgName == "enemySpider")
            {
               if (tempDir == 1)
                  characterImg = spiderLeft;
               if (tempDir == 3)
                  characterImg = spiderRight;
               if (tempDir == 2)
                  characterImg = spiderDown;
               if (tempDir == 5)
                  characterImg = spiderUp;
            }
            else
				{
					if (tempDir == 1)
						characterImg = charLeft;
					if (tempDir == 3)
						characterImg = charRight;
					if (tempDir == 2)
						characterImg = charDown;
					if (tempDir == 5)
						characterImg = charUp;
				}

				e->Graphics->DrawImage(characterImg,
					tempPosX,
					tempPosY,
					tempWidth,
					tempHeight);

            //if (Manager->GetCharacterManager()->GetEnemy(index) == NULL)
            tempEnemy = NULL;
            if(index < Manager->GetCharacterManager()->getNumEnemies())
				   tempEnemy = Manager->GetCharacterManager()->GetEnemy(++index);

			}

			//draw player
			tempPosX = Manager->GetCharacterManager()->GetHero()->GetLocation()->first;
			tempPosY = Manager->GetCharacterManager()->GetHero()->GetLocation()->second;
			tempWidth = Manager->GetCharacterManager()->GetHero()->GetWidth();
			tempHeight = Manager->GetCharacterManager()->GetHero()->GetHeight();
			tempDir = Manager->GetCharacterManager()->GetHero()->GetDirection();
			tempArmor = Manager->GetCharacterManager()->GetHero()->GetArmorRarity();


			switch (tempArmor)
			{
			case 0:
				if (tempDir == 1)
					characterImg = heroNoLeft;
				if (tempDir == 2)
					characterImg = heroNoDown;
				if (tempDir == 3)
					characterImg = heroNoRight;
				if (tempDir == 5)
					characterImg = heroNoUp;
				break;
         case 1:
            if (tempDir == 1)
               characterImg = heroIrLeft;
            if (tempDir == 2)
               characterImg = heroIrDown;
            if (tempDir == 3)
               characterImg = heroIrRight;
            if (tempDir == 5)
               characterImg = heroIrUp;
            break;
         case 2:
            if (tempDir == 1)
               characterImg = heroTwoLeft;
            if (tempDir == 2)
               characterImg = heroTwoDown;
            if (tempDir == 3)
               characterImg = heroTwoRight;
            if (tempDir == 5)
               characterImg = heroTwoUp;
            break;
         case 3:
            if (tempDir == 1)
               characterImg = heroThreeLeft;
            if (tempDir == 2)
               characterImg = heroThreeDown;
            if (tempDir == 3)
               characterImg = heroThreeRight;
            if (tempDir == 5)
               characterImg = heroThreeUp;
            break;
			default:
				if (tempDir == 1)
					characterImg = heroNoLeft;
				if (tempDir == 2)
					characterImg = heroNoDown;
				if (tempDir == 3)
					characterImg = heroNoRight;
				if (tempDir == 5)
					characterImg = heroNoUp;
			}

			e->Graphics->DrawImage(characterImg,
				tempPosX,
				tempPosY,
				tempWidth,
				tempHeight);

			// Draw Player Attack
			playerDir = Manager->GetCharacterManager()->GetHero()->GetDirection();
			PX = Manager->GetCharacterManager()->GetHero()->GetLocation()->first;
			PY = Manager->GetCharacterManager()->GetHero()->GetLocation()->second;
			curx = PX / xSpacing;
			cury = PY / ySpacing;
			pwidth = Manager->GetCharacterManager()->GetHero()->GetWidth();
			pheight = Manager->GetCharacterManager()->GetHero()->GetHeight();
			swingDistance = 0;

			//draw sword swing for left and down
			if (attackAnamationStage > 0)
			{
				if (Manager->GetCharacterManager()->GetHero()->GetWeaponRarity() == 0)
				{
					if (playerDir == 2)
					{
						curWeapon = SwordZeroD;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}
					}
					else if (playerDir == 1)
					{
						curWeapon = SwordZeroL;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetWidth() / 2);

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetWidth() / 2);

							Manager->checkCollision(attackType);
						}
					}
				}
				if (Manager->GetCharacterManager()->GetHero()->GetWeaponRarity() == 1)
				{
					if (playerDir == 2)
					{
						curWeapon = SwordOneD;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}
					}
					else if (playerDir == 1)
					{
						curWeapon = SwordOneL;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetWidth() / 2);

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetWidth() / 2);

							Manager->checkCollision(attackType);
						}
					}
				}
				if (Manager->GetCharacterManager()->GetHero()->GetWeaponRarity() == 2)
				{
					if (playerDir == 2)
					{
						curWeapon = SwordTwoD;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}
					}
					else if (playerDir == 1)
					{
						curWeapon = SwordTwoL;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetWidth() / 2);

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetWidth() / 2);

							Manager->checkCollision(attackType);
						}
					}
				}
				if (Manager->GetCharacterManager()->GetHero()->GetWeaponRarity() == 3)
				{
					if (playerDir == 2)
					{
						curWeapon = SwordThreeD;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);

						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetHeight() / 2,
								Manager->GetCharacterManager()->GetHero()->GetHeight());

							Manager->checkCollision(attackType);
						}
					}
					else if (playerDir == 1)
					{
						curWeapon = SwordThreeL;
						if (attackType == 1)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetWidth() / 2);

							Manager->checkCollision(attackType);
						}
						else if (attackType == 2)
						{
							Manager->GetCharacterManager()->GetHero()->caculateSwingDistance(attackAnamationStage, attackType);
							e->Graphics->DrawImage(curWeapon,
								Manager->GetCharacterManager()->GetHero()->GetSXBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetSYBounds(attackType).first,
								Manager->GetCharacterManager()->GetHero()->GetWidth(),
								Manager->GetCharacterManager()->GetHero()->GetWidth() / 2);

							Manager->checkCollision(attackType);
						}
					}
				}
			}

         // draw the black sections and the walls
         for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++)
            {
               Key startOrigin = Manager->gameMap->GetStartPoint();
               Key finishOrigin = Manager->gameMap->GetFinishPoint();
               //darkens tile to black if not visible and/or not visited
               if (((*tileMap)[Key(x, y)]->GetLightLevel() <= 0)
                  && !Manager->GetCharacterManager()->GetHero()->GetFullVisibility())//GetPlayerFullVisibility()
                  
               {
                  myBrush->Color = Color::Black;
                  e->Graphics->FillRectangle(myBrush,
                     System::Drawing::Rectangle(x*xSpacing, y*ySpacing,
                        xSpacing, ySpacing));
               }
				
               // Draws walls
               if ((*tileMap)[Key(x, y)]->GetPlayerVisited() ||
                  Manager->GetCharacterManager()->GetHero()->GetFullVisibility())//GetPlayerFullVisibility())
               {
                  myBrush->Color = Color::Blue;
                  if ((*tileMap)[Key(x, y)]->HasLeftWall())
                     e->Graphics->FillRectangle(myBrush,
                        System::Drawing::Rectangle(x*xSpacing, y*ySpacing,
                           lr_wallGirth, ySpacing));
                  if ((*tileMap)[Key(x, y)]->HasTopWall())
                     e->Graphics->FillRectangle(myBrush,
                        System::Drawing::Rectangle(x*xSpacing, y*ySpacing,
                           xSpacing, tb_wallGirth));
                  if ((*tileMap)[Key(x, y)]->HasRightWall())
                     e->Graphics->FillRectangle(myBrush,
                        System::Drawing::Rectangle(
                        (x + 1)*xSpacing - lr_wallGirth, y*ySpacing,
                           lr_wallGirth, ySpacing));
                  if ((*tileMap)[Key(x, y)]->HasBottomWall())
                     e->Graphics->FillRectangle(myBrush,
                        System::Drawing::Rectangle(
                           x*xSpacing, (y + 1)*ySpacing - tb_wallGirth,
                           xSpacing, tb_wallGirth));
               }
            }

			delete myBrush;
		}


		//delete formGraphics;
	}

	private: System::Void hardToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		size = HARD;
	}
	private: System::Void txtInstructions_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void Maze_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->Height < this->Width)
		{
			panel1->Height = this->Height - menuStrip1->Height;
			panel1->Width = panel1->Height;
		}
		else if (this->Height > this->Width)
		{
			panel1->Width = this->Width;
			panel1->Height = panel1->Height;
		}

		//May need a scaling factor or base it off screen res for smaller screens
		grpGameStats->Location = Point(panel1->Width, grpGameStats->Location.Y);
		grpGameStats->Size = System::Drawing::Size(this->Width - grpGameStats->Location.X, grpGameStats->Height);

		btnQuit->Location = Point(panel1->Width, panel1->Size.Height - btnQuit->Height);
		btnQuit->Size = System::Drawing::Size(this->Width - btnQuit->Location.X, btnQuit->Height);

		progHealthBar->Size = System::Drawing::Size(this->Width - (grpGameStats->Location.X + progHealthBar->Location.X), progHealthBar->Height);
		lblHealthOutput->Location = Point(progHealthBar->Location.X + (progHealthBar->Width - lblHealthOutput->Width) / 2, lblHealthOutput->Location.Y);

		progBonus->Size = System::Drawing::Size(this->Width - (grpGameStats->Location.X + progBonus->Location.X), progBonus->Height);
		lblBPoints->Location = Point(progBonus->Location.X + (progBonus->Width - lblBPoints->Width) / 2, lblBPoints->Location.Y);

      pnlInstructions->Size = System::Drawing::Size(panel1->Width, panel1->Height);
      txtInstructions->Location = Point(pnlInstructions->Location.X + (pnlInstructions->Width - txtInstructions->Width) / 2, txtInstructions->Location.Y);
      grpSettings->Location = Point(pnlInstructions->Location.X + (pnlInstructions->Width - grpSettings->Width) / 2, grpSettings->Location.Y);
      btnStart->Location = Point(pnlInstructions->Location.X + (pnlInstructions->Width - btnStart->Width) / 2, btnStart->Location.Y);
      lblHighScore->Location = Point(pnlInstructions->Location.X + (pnlInstructions->Width - lblHighScore->Width) / 2, lblHighScore->Location.Y);
      lblHighEasy->Location = Point(pnlInstructions->Location.X + (pnlInstructions->Width - lblHighEasy->Width) / 2, lblHighEasy->Location.Y);
      lblHighMedium->Location = Point(pnlInstructions->Location.X + (pnlInstructions->Width - lblHighMedium->Width) / 2, lblHighMedium->Location.Y);
      lblHighHard->Location = Point(pnlInstructions->Location.X + (pnlInstructions->Width - lblHighHard->Width) / 2, lblHighHard->Location.Y);
	}
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!Manager)//&& if tutorial is selected
		{
         //BGM->PlayLooping();
         audioManager->StopIntro();
         audioManager->PlayBackground();
			if (radEasy->Checked)
				size = EASY;
			else if (radMedium->Checked)
				size = MEDIUM;
			else
				size = HARD;
         btnQuit->Text = "End Game";
			grpSettings->Enabled = false;
			pnlInstructions->Visible = false;

			//map->tutorial(true); //Create the tutorial level


			Manager = new GameManager(panel1->Width, size); //TEN for tutorial

												//generates map procedurally
			Manager->gameMap->GenerateMap(Manager->gameMap->GetGeneratorPostion());
			Manager->gameMap->MakePaths(); //Cuts out paths based on 0,1,2,3,-1
			Manager->gameMap->addExtraPaths();

			//spawn enemies
			Manager->GetCharacterManager()->SpawnEnemies();

			DrawMap(); //Draw or redraw the graphics
			gameRunning = true;
		}
	}
	private: System::Void btnQuit_Click(System::Object^  sender, System::EventArgs^  e) {
      if(!gameRunning)
		   this->Close();
      else
         GameOver();
	}

	private: void GameOver()
	{
      //Death->Play();
      audioManager->StopBackground();
      if (audioManager->PlayingWalk())
         audioManager->StopWalk();
      audioManager->PlayDeath();
      btnQuit->Text = "Quit";
		gameRunning = false;
		delete Manager;
		Manager = NULL;
		System::Drawing::Graphics ^g = panel1->CreateGraphics();
		System::Drawing::SolidBrush ^myBrush =
			gcnew System::Drawing::SolidBrush(Color::Red);
		System::Drawing::Font ^f = gcnew System::Drawing::Font(lblArmor->Font->FontFamily, 150);
		g->DrawString("GAME OVER!", f, myBrush, System::Drawing::RectangleF(0.0, 0.0, panel1->Width, panel1->Height));
		delete f;
		delete myBrush;
		grpSettings->Enabled = true;
	}

	};
}