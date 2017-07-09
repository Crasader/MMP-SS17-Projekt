#pragma once
#ifndef __SLOPESPRITE_H__
#define __SLOPESPRITE_H__
#include "cocos2d.h"

using namespace cocos2d;

class SlopeSprite : public Sprite
{
public:
	virtual ~SlopeSprite();
	static SlopeSprite* createSlopeSprite(bool isHelper);

	virtual void setPosition(const Point& pos) override;

private:
	SlopeSprite(bool isHelper);
	bool isHelper;
};

#endif //__SLOPESPRITE_H__

