#include "RampSprite.h"
#include "GlobalValues.h"
#include "MyBodyParser.h"

RampSprite::RampSprite(int type)
{
	this->type = type;
}

RampSprite::~RampSprite()
{
}

RampSprite * RampSprite::createRampSprite(int type)
{
	auto spritePNG = spriteHelperRampMedium;
	auto jsonFile = jsonRamp;
	auto jsonName = jsonNameRamp;

	switch (type)
	{
	case TYPE_MEDIUM:
		break;
	case TYPE_STEEP:
		spritePNG = spriteHelperRampExtreme;
		jsonFile = jsonRamp3;
		jsonName = jsonNameRamp3;
		break;
	case TYPE_FLAT:
		spritePNG = spriteHelperRampFlat;
		jsonFile = jsonRamp2;
		jsonName = jsonNameRamp2;
		break;
	default:
		break;
	}

	auto ramp = new RampSprite(type);

	if (ramp && ramp->initWithFile(spritePNG)) {
		ramp->autorelease();

		MyBodyParser::getInstance()->parseJsonFile(jsonFile);
		auto rampBody = MyBodyParser::getInstance()->bodyFormJson(ramp, jsonName, PHYSICSBODY_MATERIAL_DEFAULT);

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



