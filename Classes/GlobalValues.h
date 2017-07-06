#ifndef  _GLOBALVALUES_H_
#define  _GLOBALVALUES_H_
#include <string>

using namespace std;

/* File for global values (Probably not best practice for CPP, but what do I know)*/

// Buttons
extern const string startButton;
extern const string closeButton;

extern const string easyButton;
extern const string mediumButton;
extern const string hardButton;
extern const string questionButton;
extern const string backButton;

extern const string dropButton;
extern const string resetButton;

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

// Level Backgrounds
extern const string level1;
extern const string level2;
extern const string level3;

// Current Level
extern string levelName;

#endif // _GLOBALVALUES_H_

