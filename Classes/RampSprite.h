#pragma once
#ifndef __RAMPSPRITE_H__
#define __RAMPSPRITE_H__
#include "cocos2d.h"

using namespace cocos2d;

class RampSprite : public Sprite
{
public:
	virtual ~RampSprite();
	static RampSprite* createRampSprite(bool isHelper);

	virtual void setPosition(const Point& pos) override;

private:
	RampSprite(bool isHelper);
	bool isHelper;
};

#endif //__RAMPSPRITE_H__

