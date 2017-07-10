#pragma once
#ifndef __BUMPERSPRITE_H__
#define __BUMPERSPRITE_H__
#include "cocos2d.h"
#include "GenericSprite.h"

using namespace cocos2d;

class BumperSprite : public GenericSprite
{
public:
	virtual ~BumperSprite();
	static BumperSprite* createBumperSprite();

private:
	BumperSprite();
};

#endif //__BUMPERSPRITE_H__

