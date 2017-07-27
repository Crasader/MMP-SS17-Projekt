#include "SpeedBoosterSprite.h"
#include "GlobalValues.h"

SpeedBoosterSprite::SpeedBoosterSprite()
{
}

SpeedBoosterSprite::~SpeedBoosterSprite()
{
}

SpeedBoosterSprite* SpeedBoosterSprite::createSpeedBoosterSprite()
{
	auto speedBooster = new SpeedBoosterSprite();
	auto spritePNG = spriteSpeedBooster;

	if (speedBooster && speedBooster->initWithFile(spritePNG)) {
		auto speedBoosterBody = PhysicsBody::createCircle(
			35.0f,
			PhysicsMaterial(0.0f, 0.0f, 0.0f)
		);
		speedBoosterBody->setDynamic(false);
		speedBoosterBody->setCollisionBitmask(colBitMaskSpeedRight);
		speedBoosterBody->setContactTestBitmask(true);
		speedBoosterBody->autorelease();
		speedBooster->setPhysicsBody(speedBoosterBody);

		speedBooster->setScale(0.4f, 0.4f);

		return speedBooster;
	}
	CC_SAFE_DELETE(speedBooster);
	return speedBooster = nullptr;
}



