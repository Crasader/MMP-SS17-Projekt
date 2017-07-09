#include "WallSprite.h"
#include "GlobalValues.h"

WallSprite::WallSprite()
{
}

WallSprite::~WallSprite()
{
}

WallSprite* WallSprite::createWallSprite()
{
	auto wall = new WallSprite();

	if (wall && wall->initWithFile(spriteObstacleWall)) {
		auto wallBody = PhysicsBody::createBox(
			Size(wall->getBoundingBox().size.width, wall->getBoundingBox().size.height),
			PHYSICSBODY_MATERIAL_DEFAULT
		);

		wallBody->setDynamic(false);
		wall->autorelease();
		wall->setPhysicsBody(wallBody);
		return wall;
	}
	CC_SAFE_DELETE(wall);
	return wall = nullptr;
}


