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
	static BlockSprite* createBlockSprite(int type);

private:
	BlockSprite(int type);
	int blockType;
};

#endif //__BLOCKSPRITE_H__

