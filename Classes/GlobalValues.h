#ifndef  _GLOBALVALUES_H_
#define  _GLOBALVALUES_H_
#include <string>

using namespace std;

/* File for global values (Probably not best practice for CPP, but what do I know)*/

// Sprites
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
extern const string spriteObstacleBlock2;
extern const string spriteObstacleBlock3;
extern const string spriteObstacleWall;
extern const string spriteObstacleRamp;
extern const string spriteObstacleSlope;
extern const string spriteObstacleBumper;
extern const string spriteObstacleBumperUsed;

// Helper
extern const string spriteHelperBlock1;
extern const string spriteHelperBlock2;
extern const string spriteHelperBlock3;
extern const string spriteHelperRamp;
extern const string spriteHelperSlope;
extern const string spriteHelperBumper;
extern const string spriteHelperBumperUsed;

// Target
extern const string spriteBasket;

// Bottom
extern const string spriteGround;

// Collision Bitmasks
extern const int colBitMaskPlayer;
extern const int colBitMaskTarget;
extern const int colBitMaskGround;
extern const int colBitMaskBumper;
extern const int colBitMaskSlopeRamp;

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

