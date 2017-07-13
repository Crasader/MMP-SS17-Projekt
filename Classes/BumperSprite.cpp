#include "BumperSprite.h"
#include "GlobalValues.h"

BumperSprite::BumperSprite()
{
}

BumperSprite::~BumperSprite()
{
}

BumperSprite * BumperSprite::createBumperSprite()
{
	auto bumper = new BumperSprite();
	auto spritePNG = spriteHelperBumper;

	if (bumper && bumper->initWithFile(spritePNG)) {
		auto bumperBody = PhysicsBody::createBox(
			Size(bumper->getBoundingBox().size.width, bumper->getBoundingBox().size.height * 0.65f),
			PhysicsMaterial(0.1f, 1.8f, 0.5f)
		);

		bumperBody->setDynamic(false);
		bumperBody->setCollisionBitmask(colBitMaskBumper);
		bumperBody->setContactTestBitmask(true);
		bumperBody->setPositionOffset(Vec2(0.0f, -19.0f));
		bumper->autorelease();
		bumper->setPhysicsBody(bumperBody);
		return bumper;
	}
	CC_SAFE_DELETE(bumper);
	return bumper = nullptr;
}



