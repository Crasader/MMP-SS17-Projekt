#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "LevelMediumScene.h"
#include "GlobalValues.h"
#include "MainMenuScene.h"
#include <string>

USING_NS_CC;

Scene* LevelMediumScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LevelMediumScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
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

	return true;
}