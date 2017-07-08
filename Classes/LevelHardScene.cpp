#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GlobalValues.h"
#include "LevelHardScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* LevelHardScene::createScene()
{
	auto scene = Scene::createWithPhysics();;
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0.0f, gravity));
	auto layer = LevelHardScene::create();

	scene->addChild(layer);

	return scene;
}

// on "init" you need to initialize your instance
bool LevelHardScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!GenericLevelScene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();


	// Ramp
	auto rampBody = PhysicsBody::createBox(
		Size(32.0f, 32.0f),
		PhysicsMaterial(0.1f, 0.1f, 0.5f)
	);
	auto ramp = Sprite::create(obstacleSlope);
	ramp->setPosition(Point(visibleSize.width * 0.15 + origin.x, visibleSize.height * 0.5));
	this->addChild(ramp);
	rampBody->setDynamic(false);
	ramp->setPhysicsBody(rampBody);

	// Add more obstacles and helper objects


	// Add all obstacles to the obstacleObjects Vector
	GenericLevelScene::obstacleObjects.pushBack(ramp);

	// Add all help object to the helperObjects Vector;
	//GenericLevelScene::helperObjects.pushBack(NULL);

	return true;
}