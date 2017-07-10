#pragma once
#ifndef __RAMPSPRITE_H__
#define __RAMPSPRITE_H__
#include "cocos2d.h"
#include "GenericSprite.h"

using namespace cocos2d;

class RampSprite : public GenericSprite
{
public:
	virtual ~RampSprite();
	static RampSprite* createRampSprite();

private:
	RampSprite();
};

#endif //__RAMPSPRITE_H__

