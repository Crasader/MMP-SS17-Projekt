#include "RampSprite.h"
#include "GlobalValues.h"
#include "MyBodyParser.h"

RampSprite::RampSprite()
{
}

RampSprite::~RampSprite()
{
}

RampSprite * RampSprite::createRampSprite()
{
	auto spritePNG = spriteHelperRampMedium;

	auto ramp = new RampSprite();

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



