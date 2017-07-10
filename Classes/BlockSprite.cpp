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
	case 1:
		blockPNG = spriteObstacleBlock1;
		break;
	case 2:
		blockPNG = spriteObstacleBlock2;
		break;
	default:
		blockPNG = spriteObstacleBlock3;
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


