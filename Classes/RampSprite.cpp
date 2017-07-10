#include "RampSprite.h"
#include "GlobalValues.h"
#include "MyBodyParser.h"

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

	auto ramp = new RampSprite(isHelper);

	if (ramp && ramp->initWithFile(spritePNG)) {
		ramp->autorelease();

		MyBodyParser::getInstance()->parseJsonFile(jsonRamp);
		auto rampBody = MyBodyParser::getInstance()->bodyFormJson(ramp, jsonNameRamp, PHYSICSBODY_MATERIAL_DEFAULT);

		if (rampBody != nullptr)
		{
			rampBody->setDynamic(false);
			ramp->setPhysicsBody(rampBody);
		}

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



