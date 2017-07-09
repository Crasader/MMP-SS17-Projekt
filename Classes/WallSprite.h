#pragma once
#ifndef __WALLSPRITE_H__
#define __WALLSPRITE_H__
#include "cocos2d.h"

using namespace cocos2d;

// Does not inherit Generic sprite because wall is never moveable
class WallSprite : public Sprite
{
public:
	WallSprite();
	virtual ~WallSprite();
	static WallSprite* createWallSprite();

private:
	
};

#endif //__WALLSPRITE_H__

