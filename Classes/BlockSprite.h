#pragma once
#ifndef __BLOCKSPRITE_H__
#define __BLOCKSPRITE_H__
#include "cocos2d.h"

using namespace cocos2d;

class BlockSprite : public Sprite
{
public:
	virtual ~BlockSprite();
	static BlockSprite* createBlockSprite(bool isHelper, int type);
	
	virtual void setPosition(const Point& pos) override;

private:
	BlockSprite(bool isHelper, int type);
	bool isHelper;
	int blockType;
};

#endif //__BLOCKSPRITE_H__

