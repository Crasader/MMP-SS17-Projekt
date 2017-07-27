#pragma once
#ifndef __SPEEDBOOSTERSPRITE_H__
#define __SPEEDBOOSTERSPRITE_H__
#include "cocos2d.h"
#include "GenericSprite.h"

using namespace cocos2d;

class SpeedBoosterSprite : public GenericSprite
{
public:
	virtual ~SpeedBoosterSprite();
	static SpeedBoosterSprite* createSpeedBoosterSprite();

private:
	SpeedBoosterSprite();
};

#endif //__SPEEDBOOSTERSPRITE_H__

