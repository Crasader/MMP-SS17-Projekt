#include "StartMenuScene.h"
#include "MainMenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

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
    if ( !LayerColor::initWithColor(Color4B(34,34,51,255)) )
    {
        return false;
    }

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	// Logo/Name of the Game, could be replaced by sprite/graphic
	auto gameName = CCLabelTTF::create("DROP IT!", "Zapfino", 100, CCSizeMake(500, 100), kCCTextAlignmentCenter);
	gameName->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 1.2 + origin.y));
	gameName->setColor(ccc3(255,255,255));
	addChild(gameName);

	// Start Button
	auto startButtonMenuItem = MenuItemImage::create("StartButton.png", "Start Button Clicked.png",
		CC_CALLBACK_1(StartMenuScene::GoToMainMenuScene, this));
	startButtonMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 3 + origin.y));

	// Not needed?
	auto menu = Menu::create(startButtonMenuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

  
    return true;
}

void StartMenuScene::GoToMainMenuScene(cocos2d::Ref *sender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}
