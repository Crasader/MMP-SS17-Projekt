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
		bumperBody->setPositionOffset(Vec2(0.0f, - bumper->getBoundingBox().size.height * 0.19f));
		bumper->autorelease();
		bumper->setPhysicsBody(bumperBody);
		return bumper;
	}
	CC_SAFE_DELETE(bumper);
	return bumper = nullptr;
}

void BumperSprite::setScale(float x, float y)
{
	if (x > 0 && y > 0)
	{
		Sprite::setScale(x, y);
		this->getPhysicsBody()->removeFromWorld();
		this->removeAllComponents();
		
		auto bumperBody = PhysicsBody::createBox(
			// Not excatly sure why '* (1/ x)' and '* (1/ y)' is needed
			// getBoundingBox().size should be the same size as the scaled sprite (scale factor * original size),
			// but instead the value is even smaller 
			Size(this->getBoundingBox().size.width * (1 / x), this->getBoundingBox().size.height * 0.65f * (1 / y)),
			PhysicsMaterial(0.1f, 1.8f, 0.5f)
		);

		bumperBody->setDynamic(false);
		bumperBody->setCollisionBitmask(colBitMaskBumper);
		bumperBody->setContactTestBitmask(true);
		bumperBody->setPositionOffset(Vec2(0.0f, - this->getBoundingBox().size.height * 0.19f));
		this->setPhysicsBody(bumperBody);
	}
}



