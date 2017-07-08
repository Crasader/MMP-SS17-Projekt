#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GlobalValues.h"
#include "LevelEasyScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* LevelEasyScene::createScene()
{
	auto scene = Scene::createWithPhysics();;
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0.0f, -200.0f));
	auto layer = LevelEasyScene::create();

	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool LevelEasyScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B(bgColorRed, bgColorGreen, bgColorBlue, bgColorAlpha)))
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto backGround = Sprite::create(level1);
	backGround->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.5 + origin.y + bottomBarOffset / 2));
	this->addChild(backGround);

	// Back Button
	auto backButtonMenuItem = MenuItemImage::create(backButton, "Back Button clicked",
		CC_CALLBACK_1(LevelEasyScene::goToMainMenuScene, this));
	backButtonMenuItem->setPosition(Point(visibleSize.width * bottomButtonBarLeft + origin.x,
		visibleSize.height * bottomButtonBarVerticalFactor + origin.y));

	// Drop Button
	auto dropButtonMenuItem = MenuItemImage::create(dropButton, "Drop Button clicked",
		CC_CALLBACK_1(LevelEasyScene::goToMainMenuScene, this));
	dropButtonMenuItem->setPosition(Point(visibleSize.width * bottomButtonBarMiddle + origin.x,
		visibleSize.height * bottomButtonBarVerticalFactor + origin.y));

	auto menu = Menu::create(backButtonMenuItem, dropButtonMenuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);


	//Ground
	auto groundBody = PhysicsBody::createBox(
		Size(visibleSize.width, 32.0f),
		PhysicsMaterial(0.1f, 1.0f, 0.5f)
	);
	auto ground = Sprite::create(bottom);
	ground->setPosition(Point(visibleSize.width * 0.5 + origin.x, bottomBarOffset + 50));
	this->addChild(ground);
	groundBody->setDynamic(false);
	ground->setPhysicsBody(groundBody);

	//Target
	auto target = Sprite::create(basket);
	target->setScale(0.6f);
	auto targetBody = PhysicsBody::createBox(
		Size(target->getBoundingBox().size.width * 1.6f, target->getBoundingBox().size.height * 1.6f),
		PhysicsMaterial(0.1f, 1.0f, 0.5f)
	);
	target->setPosition(Point(visibleSize.width * 0.9 + origin.x, bottomBarOffset + 155));
	this->addChild(target);
	targetBody->setDynamic(false);
	target->setPhysicsBody(targetBody);



	//Small box Physiks Example
	auto boxBody = PhysicsBody::createBox(
		Size(32.0f, 32.0f),
		PhysicsMaterial(0.1f, 0.1f, 0.5f)
	);

	auto box = Sprite::create("Block2.png");
	box->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.5 + origin.y + bottomBarOffset / 2));
	this->addChild(box);

	//apply physicsBody to the sprite
	box->setPhysicsBody(boxBody);

	return true;
}

void LevelEasyScene::goToMainMenuScene(cocos2d::Ref * sender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(transitionDuration, scene));
}