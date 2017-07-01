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

	// Easy Button
	auto easyButtonMenuItem = MenuItemImage::create("EasyButton.png", "Easy Button clicked",
		CC_CALLBACK_1(MainMenuScene::GoToMainLevel1Scene, this));
	easyButtonMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height * 0.5 + origin.y + 150));

	// Medium Button
	auto mediumButtonMenuItem = MenuItemImage::create("MediumButton.png", "Medium Button clicked",
		CC_CALLBACK_1(MainMenuScene::GoToMainLevel2Scene, this));
	mediumButtonMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height * 0.5 + origin.y));

	// Hard Button
	auto hardButtonMenuItem = MenuItemImage::create("HardButton.png", "Hard Button clicked",
		CC_CALLBACK_1(MainMenuScene::GoToMainLevel3Scene, this));
	hardButtonMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height * 0.5 + origin.y - 150));

	// Guide Button
	auto guideButtonMenuItem = MenuItemImage::create("QuestionButton.png", "Question Button clicked",
		CC_CALLBACK_1(MainMenuScene::GoToGuideScene, this));
	guideButtonMenuItem->setPosition(Point(visibleSize.width * 0.9 + origin.x, visibleSize.height * 0.15 + origin.y));

	// Back Button

	// Close Button

	auto menu = Menu::create(easyButtonMenuItem, mediumButtonMenuItem, hardButtonMenuItem, guideButtonMenuItem,  NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);


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

void MainMenuScene::GoToGuideScene(cocos2d::Ref *sender)
{
	// TODO Transition to Guide
}