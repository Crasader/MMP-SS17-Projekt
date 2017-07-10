#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "LevelMediumScene.h"
#include "GlobalValues.h"
#include "MainMenuScene.h"
#include <string>

USING_NS_CC;

Scene* LevelMediumScene::createScene()
{
	auto scene = Scene::createWithPhysics();;
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0.0f, gravity));
	auto layer = LevelMediumScene::create();

	scene->addChild(layer);

	return scene;
}

// on "init" you need to initialize your instance
bool LevelMediumScene::init()
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