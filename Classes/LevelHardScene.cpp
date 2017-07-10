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


	// Add obstacles and helper objects

	// Add all obstacles to the obstacleObjects Vector
	//GenericLevelScene::obstacleObjects.pushBack(NULL);



	// Add helper objects

	// Add all help object to the helperObjects Vector;
	//GenericLevelScene::helperObjects.pushBack(NULL);

	return true;
}