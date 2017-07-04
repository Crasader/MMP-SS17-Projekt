#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"+
#include "Constants.h"
#include "LevelHardScene.h"
#include "MainMenuScene.h"

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
	if (!LayerColor::initWithColor(Color4B(bgColorRed, bgColorGreen, bgColorBlue, bgColorAlpha)))
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto backGround = Sprite::create(level3);
	backGround->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.5 + origin.y + bottomBarOffset / 2));
	this->addChild(backGround);

	// Back Button
	auto backButtonMenuItem = MenuItemImage::create(backButton, "Back Button clicked",
		CC_CALLBACK_1(LevelHardScene::goToMainMenuScene, this));
	backButtonMenuItem->setPosition(Point(visibleSize.width * 0.1 + origin.x, visibleSize.height * 0.1 + origin.y));

	auto menu = Menu::create(backButtonMenuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	return true;
}

void LevelHardScene::goToMainMenuScene(cocos2d::Ref * sender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(transitionDuration, scene));
}
