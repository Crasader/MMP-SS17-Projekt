#include "GlobalValues.h"

// Sprites

extern const string spriteLogo = "Logo.png";

// Buttons
extern const string spriteStartButton = "StartButton.png";
extern const string spriteCloseButton = "CloseButton.png";

extern const string spriteEasyButton = "EasyButton.png";
extern const string spriteMediumButton = "MediumButton.png";
extern const string spriteHardButton = "HardButton.png";
extern const string spriteQuestionButton = "QuestionButton.png";
extern const string spriteBackButton = "BackArrowButton.png";

extern const string spriteDropButton = "DropButton.png";
extern const string spriteResetButton = "ResetButton.png";

// Level Backgrounds
extern const string level1 = "Level1.png";
extern const string level2 = "level2.png";
extern const string level3 = "Level3.png";

// Obstacle
extern const string spriteObstacleBlock1 = "Block1.png";
extern const string spriteObstacleBlock12 = "Box12.png";
extern const string spriteObstacleBlock13 = "Box13.png";

extern const string spriteObstacleBlock2 = "Block2.png";
extern const string spriteObstacleBlock22 = "Box22.png";
extern const string spriteObstacleBlock23 = "Box23.png";

extern const string spriteObstacleBlock3 = "Block3.png";
extern const string spriteObstacleBlock32 = "Box32.png";
extern const string spriteObstacleBlock33 = "Box33.png";

extern const string spriteObstacleWall = "wall.png";

// Helper
extern const string spriteHelperRampExtreme = "rampe3.png";
extern const string spriteHelperRampMedium = "Rampe.png";
extern const string spriteHelperRampFlat = "rampe2.png";

extern const string spriteHelperSlopeExtreme = "Schraege3.png";
extern const string spriteHelperSlopeMedium = "Schraege.png";
extern const string spriteHelperSlopeFlat = "Schraege2.png";

extern const string spriteHelperBumper = "Bumper.png";
extern const string spriteHelperBumperUsed = "BumperBenutzt.png";

// Target
extern const string spriteBasket = "korb.png";

// Bottom
extern const string spriteGround = "dummyPNG.png";

// Collision Bitmasks
extern const int colBitMaskPlayer = 1;
extern const int colBitMaskTarget = 2;
extern const int colBitMaskGround = 3;
extern const int colBitMaskBumper = 4;
extern const int colBitMaskSlopeRamp = 5;

// JSON Files
extern const string jsonSlope = "Schraege.json";
extern const string jsonSlope2 = "Schraege2.json";
extern const string jsonSlope3 = "Schraege3.json";

extern const string jsonRamp = "Rampe.json";
extern const string jsonRamp2 = "Rampe2.json";
extern const string jsonRamp3 = "Rampe3.json";

extern const string jsonNameSlope = "Schraege";
extern const string jsonNameSlope2 = "Schraege2";
extern const string jsonNameSlope3 = "Schraege3";

extern const string jsonNameRamp = "Rampe";
extern const string jsonNameRamp2 = "rampe2";
extern const string jsonNameRamp3 = "rampe3";

// Position
// Bottom Buttons
extern const double bottomButtonBarVerticalFactor = 0.1;
extern const double bottomButtonBarLeft = 0.1;
extern const double bottomButtonBarMiddle = 0.5;
extern const double bottomButtonBarRight = 0.9;


// Color
// Background Color (for start and main menu)
extern const int bgColorRed = 34;
extern const int bgColorGreen = 34;
extern const int bgColorBlue = 51;
extern const int bgColorAlpha = 255;

// Logo Color
extern const int logoColorRed = 255;
extern const int logoColorGreen = 255;
extern const int logoColorBlue = 255;

// Transitions
extern const double transitionDuration = 0.5;

// Misc
extern const int logoFontSize = 100;
extern const string logoText = "DUNK THE TRUMP";
extern const string logoFont = "Helvetica";
extern const int bottomBarOffset = 150; // Sizeadjustment. Makes some space to place buttons below the level background

extern const float gravity = -700.0f;

// Current Level
extern string currentLevelName = "";
