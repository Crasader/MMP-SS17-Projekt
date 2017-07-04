#include "StartMenuScene.h"
#include "MainMenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GlobalValues.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* StartMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = StartMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StartMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
	if (!LayerColor::initWithColor(Color4B(bgColorRed, bgColorGreen, bgColorBlue, bgColorAlpha)))
    {
        return false;
    }

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	// Logo/Name of the Game, could be replaced by sprite/graphic
	auto gameName = CCLabelTTF::create(logoText, logoFont, logoFontSize, CCSizeMake(500, 100), kCCTextAlignmentCenter);
	gameName->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.9 + origin.y));
	gameName->setColor(ccc3(logoColorRed, logoColorGreen, logoColorBlue));
	addChild(gameName);

	// Start Button
	auto startButtonMenuItem = MenuItemImage::create(startButton, "Start Button clicked",
		CC_CALLBACK_1(StartMenuScene::goToMainMenuScene, this));
	startButtonMenuItem->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height / 2 + origin.y));

	// Close Button
	auto closeButtonMenuItem = MenuItemImage::create(closeButton, "Close Button clicked",
		// Note: CC_CALLBACK_1 only works when when function takes an argument?
		CC_CALLBACK_1(StartMenuScene::closeApplication, this));
	closeButtonMenuItem->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height / 2 + origin.y - 125));

	auto menu = Menu::create(startButtonMenuItem, closeButtonMenuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

  
    return true;
}

void StartMenuScene::goToMainMenuScene(cocos2d::Ref *sender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(transitionDuration, scene));
}

void StartMenuScene::closeApplication(cocos2d::Ref *sender)
{
	Director::getInstance()->end();
}
