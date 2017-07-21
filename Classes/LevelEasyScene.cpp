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
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
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

	// Examples:
	// Add helper objects
	auto slopeMedium = SlopeSprite::createSlopeSprite(SlopeSprite::TYPE_MEDIUM);
	slopeMedium->setPosition(Point(visibleSize.width * 0.15 + origin.x, visibleSize.height * 0.5));
	this->addChild(slopeMedium);

	auto slopeSteep = SlopeSprite::createSlopeSprite(SlopeSprite::TYPE_STEEP);
	slopeSteep->setPosition(Point(visibleSize.width * 0.15 + origin.x, visibleSize.height * 0.8));
	this->addChild(slopeSteep);

	auto bumper = BumperSprite::createBumperSprite();
	bumper->setPosition(Point(visibleSize.width * 0.15 + origin.x, visibleSize.height * 0.4));
	bumper->setScale(0.8f, 0.8f);
	this->addChild(bumper);

	auto ramp = RampSprite::createRampSprite(RampSprite::TYPE_MEDIUM);
	ramp->setPosition(Point(visibleSize.width * 0.85 + origin.x, visibleSize.height * 0.9));
	this->addChild(ramp);

	// Add all helper objects to the helperObjects Vector
	GenericLevelScene::helperObjects.pushBack(slopeMedium);
	GenericLevelScene::helperObjects.pushBack(slopeSteep);
	GenericLevelScene::helperObjects.pushBack(bumper);
	GenericLevelScene::helperObjects.pushBack(ramp);




	// Add obstacles
	auto wall = WallSprite::createWallSprite();
	wall->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.45));
	this->addChild(wall);

	auto block = BlockSprite::createBlockSprite(BlockSprite::TYPE_SQUARE_EARTH);
	block->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.65));
	this->addChild(block);

	// Add all obstacle object to the helperObjects Vector
	// GenericLevelScene::obstacleObjects.pushBack(wall);
	GenericLevelScene::obstacleObjects.pushBack(block);
    GenericLevelScene::obstacleObjects.pushBack(wall);

	return true;
}
