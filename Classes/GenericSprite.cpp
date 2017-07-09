#include "BumperSprite.h"
#include "GlobalValues.h"

BumperSprite::BumperSprite(bool isHelper)
{
	this->isHelper = isHelper;
}

BumperSprite::~BumperSprite()
{
}

BumperSprite * BumperSprite::createBumperSprite(bool isHelper)
{
	auto bumper = new BumperSprite(isHelper);
	auto spritePNG = spriteHelperBumper;

	if (!isHelper) 
	{
		spritePNG = spriteObstacleBumper;
	} 

	if (bumper && bumper->initWithFile(spritePNG)) {
		auto bumperBody = PhysicsBody::createBox(
			Size(bumper->getBoundingBox().size.width, bumper->getBoundingBox().size.height),
			PhysicsMaterial(0.1f, 1.5f, 0.5f)
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

void BumperSprite::setPosition(const Point& pos) {
	Sprite::setPosition(pos);
	//if (!_nextPosition.equals(pos)) {
	//	_nextPosition = pos;
	//}
}



