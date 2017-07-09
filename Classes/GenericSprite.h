#pragma once
#ifndef __GENERICSPRITE_H__
#define __GENERICSPRITE_H__
#include "cocos2d.h"

using namespace cocos2d;

class GenericSprite : public Sprite
{
public:
	CC_SYNTHESIZE(Touch*, _touch, Touch);
private:
	
};

#endif //__GENERICSPRITE_H__

