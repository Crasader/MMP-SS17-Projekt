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

	const static int TYPE_SQUARE_EARTH = 1;
	const static int TYPE_VERTICAL_EARTH = 12;
	const static int TYPE_HORIZONTAL_EARTH = 13;

	const static int TYPE_SQUARE_CITY = 2;
	const static int TYPE_VERTICAL_CITY = 22;
	const static int TYPE_HORIZONTAL_CITY = 23;

	const static int TYPE_SQUARE_SAND = 3;
	const static int TYPE_VERTICAL_SAND = 32;
	const static int TYPE_HORIZONTAL_SAND = 33;


private:
	BlockSprite(int type);
	int blockType;
};

#endif //__BLOCKSPRITE_H__

