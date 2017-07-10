#pragma once
#ifndef __BLOCKSPRITE_H__
#define __BLOCKSPRITE_H__
#include "cocos2d.h"
#include "GenericSprite.h"

using namespace cocos2d;

class BlockSprite : public GenericSprite
{
public:
	virtual ~BlockSprite();
	static BlockSprite* createBlockSprite(bool isHelper, int type);

private:
	BlockSprite(bool isHelper, int type);
	bool isHelper;
	int blockType;
};

#endif //__BLOCKSPRITE_H__

