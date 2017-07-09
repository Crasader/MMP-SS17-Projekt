#include "BlockSprite.h"
#include "GlobalValues.h"

BlockSprite::BlockSprite(bool isHelper, int type)
{
	this->isHelper = isHelper;
	this->blockType = type;
}

BlockSprite::~BlockSprite()
{
}

BlockSprite* BlockSprite::createBlockSprite(bool isHelper, int type)
{
	auto block = new BlockSprite(isHelper, type);

	auto blockPNG = spriteObstacleBlock1;
	if (isHelper)
	{
		switch (type)
		{
		case 1: 
			blockPNG = spriteHelperBlock1;
			break;
		case 2:
			blockPNG = spriteHelperBlock2;
			break;
		default:
			blockPNG = spriteHelperBlock3;
		}
	}
	else
	{
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

void BlockSprite::setPosition(const Point & pos)
{
	Sprite::setPosition(pos);
}


