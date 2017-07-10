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
			Size(bumper->getBoundingBox().size.width, bumper->getBoundingBox().size.height),
			PhysicsMaterial(0.1f, 1.8f, 0.5f)
		);

		bumperBody->setDynamic(false);
		bumperBody->setCollisionBitmask(colBitMaskBumper);
		bumperBody->setContactTestBitmask(true);
		bumper->autorelease();
		bumper->setPhysicsBody(bumperBody);
		return bumper;
	}
	CC_SAFE_DELETE(bumper);
	return bumper = nullptr;
}



