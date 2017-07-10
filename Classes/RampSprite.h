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
	static RampSprite* createRampSprite(int type);

	const static int TYPE_STEEP = 3;
	const static int TYPE_MEDIUM = 1;
	const static int TYPE_FLAT = 2;

private:
	RampSprite(int type);
	int type;
};

#endif //__RAMPSPRITE_H__

