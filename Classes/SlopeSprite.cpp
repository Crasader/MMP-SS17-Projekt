#include "SlopeSprite.h"
#include "GlobalValues.h"

SlopeSprite::SlopeSprite(bool isHelper)
{
	this->isHelper = isHelper;
}

SlopeSprite::~SlopeSprite()
{
}

SlopeSprite * SlopeSprite::createSlopeSprite(bool isHelper)
{
	auto spritePNG = spriteHelperSlope;
	if (!isHelper)
	{
		spritePNG = spriteObstacleSlope;
	}

	auto slopeBody = PhysicsBody::createBox(
		Size(32.0f, 32.0f),
		PHYSICSBODY_MATERIAL_DEFAULT
	);
	slopeBody->setDynamic(false);
	
	auto slope = new SlopeSprite(isHelper);

	if (slope && slope->initWithFile(spritePNG)) {
		slope->autorelease();
		slope->setPhysicsBody(slopeBody);
		return slope;
	}
	CC_SAFE_DELETE(slope);
	return slope = nullptr;
}

void SlopeSprite::setPosition(const Point& pos) {
	Sprite::setPosition(pos);
	//if (!_nextPosition.equals(pos)) {
	//	_nextPosition = pos;
	//}
}



