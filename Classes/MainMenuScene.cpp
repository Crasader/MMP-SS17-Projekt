#include "MainMenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainMenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainMenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B(34, 34, 51, 255)))
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();


	return true;
}

void MainMenuScene::GoToMainLevel1Scene(cocos2d::Ref *sender)
{
	// TODO Transition to Level 1
}

void MainMenuScene::GoToMainLevel2Scene(cocos2d::Ref *sender)
{
	// TODO Transition to Level 2
}

void MainMenuScene::GoToMainLevel3Scene(cocos2d::Ref *sender)
{
	// TODO Transition to Level 3
}
