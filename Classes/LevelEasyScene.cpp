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
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();


	// SLOPE EXAMPLE
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

	// This does the same as the lines above (35 - 46)
	auto slope = SlopeSprite::createSlopeSprite(false);
	slope->setPosition(Point(visibleSize.width * 0.15 + origin.x, visibleSize.height * 0.8));
	this->addChild(slope);

	auto bumper = BumperSprite::createBumperSprite(false);
	bumper->setPosition(Point(visibleSize.width * 0.15 + origin.x, visibleSize.height * 0.4));
	this->addChild(bumper);

	auto wall = WallSprite::createWallSprite();
	wall->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.5));
	this->addChild(wall);

	auto block = BlockSprite::createBlockSprite(false, 1);
	block->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.9));
	this->addChild(block);

	auto ramp = RampSprite::createRampSprite(false);
	ramp->setPosition(Point(visibleSize.width * 0.85 + origin.x, visibleSize.height * 0.9));
	this->addChild(ramp);

	// Add more obstacles and helper objects


	// Add all obstacles to the obstacleObjects Vector
	GenericLevelScene::obstacleObjects.pushBack(slope);
	GenericLevelScene::obstacleObjects.pushBack(bumper);
	GenericLevelScene::obstacleObjects.pushBack(wall);
	GenericLevelScene::obstacleObjects.pushBack(block);
	GenericLevelScene::obstacleObjects.pushBack(ramp);

	// Add all help object to the helperObjects Vector
	//GenericLevelScene::helperObjects.pushBack(NULL);

	return true;
}