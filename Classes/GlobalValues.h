#ifndef  _GLOBALVALUES_H_
#define  _GLOBALVALUES_H_
#include <string>

using namespace std;

/* File for global values (Probably not best practice for CPP, but what do I know)*/

// Sprites

extern const string spriteLogo;

// Buttons
extern const string spriteStartButton;
extern const string spriteCloseButton;

extern const string spriteEasyButton;
extern const string spriteMediumButton;
extern const string spriteHardButton;
extern const string spriteQuestionButton;
extern const string spriteBackButton;

extern const string spriteDropButton;
extern const string spriteResetButton;

// Obstacle
extern const string spriteObstacleBlock1;
extern const string spriteObstacleBlock12;
extern const string spriteObstacleBlock13;

extern const string spriteObstacleBlock2;
extern const string spriteObstacleBlock22;
extern const string spriteObstacleBlock23;

extern const string spriteObstacleBlock3;
extern const string spriteObstacleBlock32;
extern const string spriteObstacleBlock33;

extern const string spriteObstacleWall;

// Helper
extern const string spriteHelperRampExtreme;
extern const string spriteHelperRampMedium;
extern const string spriteHelperRampFlat;

extern const string spriteHelperSlopeExtreme;
extern const string spriteHelperSlopeMedium;
extern const string spriteHelperSlopeFlat;

extern const string spriteHelperBumper;
extern const string spriteHelperBumperUsed;

// Target
extern const string spriteBasket;
extern const string spriteBin;

// Bottom
extern const string spriteGround;

// Win / Lose Screen
extern const string spriteWinScreen;
extern const string spriteLooseScreen;



// Collision Bitmasks
extern const int colBitMaskPlayer;
extern const int colBitMaskTarget;
extern const int colBitMaskGround;
extern const int colBitMaskBumper;
extern const int colBitMaskSlopeRamp;
extern const int colBitMaskSpeedRight;
extern const int colBitMaskSpeedUp;
extern const int colBitMaskSpeedDown;
extern const int colBitMaskSpeedLeft;

// JSON Files
extern const string jsonSlope;
extern const string jsonSlope2;
extern const string jsonSlope3;

extern const string jsonRamp;
extern const string jsonRamp2;
extern const string jsonRamp3;

extern const string jsonTarget;

extern const string jsonPlayer;


extern const string jsonNameSlope;
extern const string jsonNameSlope2;
extern const string jsonNameSlope3;

extern const string jsonNameRamp;
extern const string jsonNameRamp2;
extern const string jsonNameRamp3;

extern const string jsonNameTarget;

extern const string jsonNamePlayer;

// Position
// Bottom Buttons
extern const double bottomButtonBarVerticalFactor;
extern const double bottomButtonBarLeft;
extern const double bottomButtonBarMiddle;
extern const double bottomButtonBarRight;


// Color
// Background Color (for start and main menu)
extern const int bgColorRed;
extern const int bgColorGreen;
extern const int bgColorBlue;
extern const int bgColorAlpha;

// Logo Color
extern const int logoColorRed;
extern const int logoColorGreen;
extern const int logoColorBlue;

// Transitions
extern const double transitionDuration;

// Misc
extern const int logoFontSize;
extern const string logoText;
extern const string logoFont;
extern const int bottomBarOffset;

extern const float gravity;

// Level Backgrounds
extern const string level1;
extern const string level2;
extern const string level3;

// Current Level
extern string currentLevelName;

#endif // _GLOBALVALUES_H_

