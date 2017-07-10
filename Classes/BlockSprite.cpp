#include "BlockSprite.h"
#include "GlobalValues.h"

BlockSprite::BlockSprite(int type)
{
	this->blockType = type;
}

BlockSprite::~BlockSprite()
{
}

BlockSprite* BlockSprite::createBlockSprite(int type)
{
	auto block = new BlockSprite(type);

	auto blockPNG = spriteObstacleBlock1;
		
	switch (type)
	{
	case TYPE_SQUARE_EARTH:
		blockPNG = spriteObstacleBlock1;
		break;
	case TYPE_VERTICAL_EARTH:
		blockPNG = spriteObstacleBlock12;
		break;
	case TYPE_HORIZONTAL_EARTH:
		blockPNG = spriteObstacleBlock13;
		break;
	case TYPE_SQUARE_CITY:
		blockPNG = spriteObstacleBlock2;
		break;
	case TYPE_VERTICAL_CITY:
		blockPNG = spriteObstacleBlock22;
		break;
	case TYPE_HORIZONTAL_CITY:
		blockPNG = spriteObstacleBlock23;
		break;
	case TYPE_SQUARE_SAND:
		blockPNG = spriteObstacleBlock3;
		break;
	case TYPE_VERTICAL_SAND:
		blockPNG = spriteObstacleBlock32;
		break;
	case TYPE_HORIZONTAL_SAND:
		blockPNG = spriteObstacleBlock33;
		break;
	default:
		break;
	}

	if (block && block->initWithFile(blockPNG)) {
		auto blockBody = PhysicsBody::createBox(
			Size(block->getBoundingBox().size.width, block->getBoundingBox().size.height),
			PHYSICSBODY_MATERIAL_DEFAULT
		);

		blockBody->setDynamic(false);
		block->autorelease();
		block->setPhysicsBody(blockBody);
		return block;
	}
	CC_SAFE_DELETE(block);
	return block = nullptr;
}


