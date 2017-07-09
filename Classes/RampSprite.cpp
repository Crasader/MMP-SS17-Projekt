#include "RampSprite.h"
#include "GlobalValues.h"

RampSprite::RampSprite(bool isHelper)
{
	this->isHelper = isHelper;
}

RampSprite::~RampSprite()
{
}

RampSprite * RampSprite::createRampSprite(bool isHelper)
{
	auto spritePNG = spriteHelperRamp;
	if (!isHelper)
	{
		spritePNG = spriteObstacleRamp;
	}

	auto rampBody = PhysicsBody::createBox(
		Size(32.0f, 32.0f),
		PHYSICSBODY_MATERIAL_DEFAULT
	);

	rampBody->setDynamic(false);

	auto ramp = new RampSprite(isHelper);

	if (ramp && ramp->initWithFile(spritePNG)) {
		ramp->autorelease();
		ramp->setPhysicsBody(rampBody);
		return ramp;
	}
	CC_SAFE_DELETE(ramp);
	return ramp = nullptr;
}

void RampSprite::setPosition(const Point& pos) {
	Sprite::setPosition(pos);
	//if (!_nextPosition.equals(pos)) {
	//	_nextPosition = pos;
	//}
}



