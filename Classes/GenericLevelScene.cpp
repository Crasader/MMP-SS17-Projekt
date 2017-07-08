#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GlobalValues.h"
#include "GenericLevelScene.h"
#include "MainMenuScene.h"
#include "GenericLevelScene.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool GenericLevelScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B(bgColorRed, bgColorGreen, bgColorBlue, bgColorAlpha)))
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto backGround = Sprite::create(currentLevelName);
	backGround->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.5 + origin.y + bottomBarOffset / 2));
	this->addChild(backGround);

	// Back Button
	auto backButtonMenuItem = MenuItemImage::create(backButton, backButton,
		CC_CALLBACK_1(GenericLevelScene::goToMainMenuScene, this));
	backButtonMenuItem->setPosition(Point(visibleSize.width * bottomButtonBarLeft + origin.x,
		visibleSize.height * bottomButtonBarVerticalFactor + origin.y));

	// Drop Button
	auto dropButtonMenuItem = MenuItemImage::create(dropButton, dropButton,
		CC_CALLBACK_1(GenericLevelScene::dropAction, this));
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
	ground = Sprite::create(bottom);
	ground->setPosition(Point(visibleSize.width * 0.5 + origin.x, bottomBarOffset + 50));
	this->addChild(ground);
	groundBody->setDynamic(false);
	ground->setPhysicsBody(groundBody);

	//Target
	target = Sprite::create(basket);
	target->setScale(0.6f);
	auto targetBody = PhysicsBody::createBox(
		Size(target->getBoundingBox().size.width * 1.6f, target->getBoundingBox().size.height * 1.6f),
		PhysicsMaterial(0.1f, 1.0f, 0.5f)
	);
	target->setPosition(Point(visibleSize.width * 0.9 + origin.x, bottomBarOffset + 155));
	this->addChild(target);
	targetBody->setDynamic(false);
	target->setPhysicsBody(targetBody);

	//ball / Player
	auto ballBody = PhysicsBody::createCircle(
		17.5f,
		PhysicsMaterial(0.5f, 0.4f, 1.0f)
	);
	ballBody->setMass(10.0f);
	player = Sprite::create("ball.png");
	player->setPosition(Vec2(visibleSize.width * 0.1f, visibleSize.height * 0.95f));
	this->addChild(player);
	ballBody->setDynamic(false);
	player->setPhysicsBody(ballBody);

	// Initialise Vectors for child classes (if size ever my be necessary, move initialisation to child classes)
	obstacleObjects = Vector<Sprite*>();
	helperObjects = Vector<Sprite*>();

	return true;
}

void GenericLevelScene::goToMainMenuScene(cocos2d::Ref * sender)
{
	// Clear the vectors, so that they are empty for the next level
	// Probably not necessary since they are initialised at the start of a level, but better safe than sorry
	obstacleObjects.clear();
	helperObjects.clear();

	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(transitionDuration, scene));
}

void GenericLevelScene::dropAction(cocos2d::Ref * sender)
{
	player->getPhysicsBody()->setDynamic(true);
	//obstacleObjects.at(0)->getPhysicsBody()->setDynamic(true);

	// TODO Lock Movement of helper objects
}
