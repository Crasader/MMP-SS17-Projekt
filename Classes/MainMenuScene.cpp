#include "MainMenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"+
#include "Constants.h"
#include "StartMenuScene.h"

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
	if (!LayerColor::initWithColor(Color4B(bgColorRed, bgColorGreen, bgColorBlue, bgColorAlpha)))
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	// Easy Button
	auto easyButtonMenuItem = MenuItemImage::create(easyButton, "Easy Button clicked",
		CC_CALLBACK_1(MainMenuScene::goToMainLevel1Scene, this));
	easyButtonMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height * 0.5 + origin.y + 150));

	// Medium Button
	auto mediumButtonMenuItem = MenuItemImage::create(mediumButton, "Medium Button clicked",
		CC_CALLBACK_1(MainMenuScene::goToMainLevel2Scene, this));
	mediumButtonMenuItem->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.5 + origin.y));

	// Hard Button
	auto hardButtonMenuItem = MenuItemImage::create(hardButton, "Hard Button clicked",
		CC_CALLBACK_1(MainMenuScene::goToMainLevel3Scene, this));
	hardButtonMenuItem->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.5 + origin.y - 150));

	// Guide Button
	auto guideButtonMenuItem = MenuItemImage::create(questionButton, "Question Button clicked",
		CC_CALLBACK_1(MainMenuScene::goToGuideScene, this));
	guideButtonMenuItem->setPosition(Point(visibleSize.width * 0.9 + origin.x, visibleSize.height * 0.15 + origin.y));

	// Back Button
	auto backButtonMenuItem = MenuItemImage::create(backButton, "Back Button clicked",
		CC_CALLBACK_1(MainMenuScene::goToStartMenuScene, this));
	backButtonMenuItem->setPosition(Point(visibleSize.width * 0.1 + origin.x, visibleSize.height * 0.15 + origin.y));

	auto menu = Menu::create(easyButtonMenuItem, mediumButtonMenuItem, hardButtonMenuItem, guideButtonMenuItem,
		backButtonMenuItem,  NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);


	return true;
}

void MainMenuScene::goToMainLevel1Scene(cocos2d::Ref *sender)
{
	// TODO Transition to Level 1
}

void MainMenuScene::goToMainLevel2Scene(cocos2d::Ref *sender)
{
	// TODO Transition to Level 2
}

void MainMenuScene::goToMainLevel3Scene(cocos2d::Ref *sender)
{
	// TODO Transition to Level 3
}

void MainMenuScene::goToGuideScene(cocos2d::Ref *sender)
{
	// TODO Transition to Guide
}

void MainMenuScene::goToStartMenuScene(cocos2d::Ref *sender) 
{
	auto scene = StartMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(transitionDuration, scene));
}