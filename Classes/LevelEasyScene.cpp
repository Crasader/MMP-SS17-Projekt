#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GlobalValues.h"
#include "LevelEasyScene.h"
#include "MainMenuScene.h"
#include "SlopeSprite.h"
#include "BumperSprite.h"
#include "WallSprite.h"
#include "BlockSprite.h"
#include "RampSprite.h"

USING_NS_CC;

Scene* LevelEasyScene::createScene()
{
	auto scene = Scene::createWithPhysics();;
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0.0f, gravity));
	auto layer = LevelEasyScene::create();

	scene->addChild(layer);

	return scene;
}

// on "init" you need to initialize your instance
bool LevelEasyScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!GenericLevelScene::init())
	{
		return false;
	}

	// SLOPE EXAMPLE (old)
	/*
	auto rampBody = PhysicsBody::createBox(
		Size(32.0f, 32.0f),
		PHYSICSBODY_MATERIAL_DEFAULT
	);
	auto ramp = Sprite::create(spriteObstacleSlope);
	ramp->setPosition(Point(visibleSize.width * 0.15 + origin.x, visibleSize.height * 0.8));
	rampBody->setDynamic(false);
	ramp->setPhysicsBody(rampBody);
	this->addChild(ramp);
	*/

	auto slope = SlopeSprite::createSlopeSprite(true);
	slope->setPosition(Point(visibleSize.width * 0.15 + origin.x, visibleSize.height * 0.8));
	this->addChild(slope);

	auto bumper = BumperSprite::createBumperSprite(true);
	bumper->setPosition(Point(visibleSize.width * 0.15 + origin.x, visibleSize.height * 0.4));
	this->addChild(bumper);

	auto wall = WallSprite::createWallSprite();
	wall->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.5));
	this->addChild(wall);

	auto block = BlockSprite::createBlockSprite(true, 1);
	block->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.9));
	this->addChild(block);

	auto ramp = RampSprite::createRampSprite(true);
	ramp->setPosition(Point(visibleSize.width * 0.85 + origin.x, visibleSize.height * 0.9));
	this->addChild(ramp);

	// Add more obstacles and helper objects


	// Add all help to the obstacleObjects Vector
	GenericLevelScene::helperObjects.pushBack(slope);
	GenericLevelScene::helperObjects.pushBack(bumper);
	GenericLevelScene::helperObjects.pushBack(block);
	GenericLevelScene::helperObjects.pushBack(ramp);

	// Add all obstacle object to the helperObjects Vector
	GenericLevelScene::obstacleObjects.pushBack(wall);

	return true;
}