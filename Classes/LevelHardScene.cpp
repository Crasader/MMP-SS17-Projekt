#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"+
#include "Constants.h"
#include "LevelHardScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* LevelHardScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LevelHardScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LevelHardScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();


	return true;
}
