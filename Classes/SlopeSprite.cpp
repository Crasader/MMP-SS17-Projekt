#include "SlopeSprite.h"
#include "GlobalValues.h"
#include "MyBodyParser.h"

SlopeSprite::SlopeSprite(int type)
{
	this->type = type;
}

SlopeSprite::~SlopeSprite()
{
}

SlopeSprite * SlopeSprite::createSlopeSprite(int type)
{
	auto spritePNG = spriteHelperSlopeMedium;
	auto jsonFile = jsonSlope;
	auto jsonName = jsonNameSlope;

	switch (type)
	{
	case TYPE_MEDIUM:
		break;
	case TYPE_STEEP:
		spritePNG = spriteHelperSlopeExtreme;
		jsonFile = jsonSlope3;
		jsonName = jsonNameSlope3;
		break;
	case TYPE_FLAT:
		spritePNG = spriteHelperSlopeFlat;
		jsonFile = jsonSlope2;
		jsonName = jsonNameSlope2;
		break;
	default:
		break;
	}
	
	auto slope = new SlopeSprite(type);

	if (slope && slope->initWithFile(spritePNG)) {
		slope->autorelease();
		
		MyBodyParser::getInstance()->parseJsonFile(jsonFile);

		auto sloepBody = MyBodyParser::getInstance()->bodyFormJson(slope, jsonName, PHYSICSBODY_MATERIAL_DEFAULT);
		if (sloepBody != nullptr)
		{
			sloepBody->setDynamic(false);
			// Disabled because animation does not work well enough with the slope
			// an no other sliding animation is available
			/*sloepBody->setCollisionBitmask(colBitMaskSlopeRamp);
			sloepBody->setContactTestBitmask(true);*/
			slope->setPhysicsBody(sloepBody);
		}

		return slope;
	}
	CC_SAFE_DELETE(slope);
	return slope = nullptr;
}



