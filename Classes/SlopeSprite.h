#pragma once
#ifndef __SLOPESPRITE_H__
#define __SLOPESPRITE_H__
#include "cocos2d.h"
#include "GenericSprite.h"

using namespace cocos2d;

class SlopeSprite : public GenericSprite
{
public:
	virtual ~SlopeSprite();
	static SlopeSprite* createSlopeSprite(int type);

	const static int TYPE_STEEP = 3;
	const static int TYPE_MEDIUM = 1;
	const static int TYPE_FLAT = 2;

private:
	SlopeSprite(int type);
	int type;
};

#endif //__SLOPESPRITE_H__

