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
	static RampSprite* createRampSprite(bool isHelper);

private:
	RampSprite(bool isHelper);
	bool isHelper;
};

#endif //__RAMPSPRITE_H__

