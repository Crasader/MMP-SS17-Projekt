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

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	auto backGround = Sprite::create(currentLevelName);
	backGround->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.5 + origin.y + bottomBarOffset / 2));
	this->addChild(backGround);

	// Back Button
	auto backButtonMenuItem = MenuItemImage::create(spriteBackButton, spriteBackButton,
		CC_CALLBACK_1(GenericLevelScene::goToMainMenuScene, this));
	backButtonMenuItem->setPosition(Point(visibleSize.width * bottomButtonBarLeft + origin.x,
		visibleSize.height * bottomButtonBarVerticalFactor + origin.y));

	// Drop Button
	auto dropButtonMenuItem = MenuItemImage::create(spriteDropButton, spriteDropButton,
		CC_CALLBACK_1(GenericLevelScene::dropAction, this));
	dropButtonMenuItem->setPosition(Point(visibleSize.width * bottomButtonBarMiddle + origin.x,
		visibleSize.height * bottomButtonBarVerticalFactor + origin.y));

	auto menu = Menu::create(backButtonMenuItem, dropButtonMenuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	// Time Field
	time = 0.0f;

	textFieldTime = ui::TextField::create();
	textFieldTime->setText("00:00");
	textFieldTime->setFontSize(60);
	textFieldTime->setContentSize(CCSize(300, 300));
	textFieldTime->setPosition(Point(visibleSize.width * bottomButtonBarRight + origin.x,
		visibleSize.height * bottomButtonBarVerticalFactor + origin.y));
	this->addChild(textFieldTime);


	// EdgeBorder
	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 2);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);

	// Ground
	auto groundBody = PhysicsBody::createBox(
		Size(visibleSize.width, 32.0f),
		PhysicsMaterial(1.0f, 0.0f, 1.0f)
	);
	auto ground = Node::create();
	ground->setPosition(Point(visibleSize.width * 0.5 + origin.x, bottomBarOffset + 50));
	groundBody->setDynamic(false);
	groundBody->setCollisionBitmask(colBitMaskGround);
	groundBody->setContactTestBitmask(true);
	ground->setPhysicsBody(groundBody);
	this->addChild(ground);

	//Target
	// TODO make collsion body smaller. 
	// Maybe just create a new node with the size of the bin and don't give the sprite itself a body
	auto targetSprite = Sprite::create(spriteBasket);
	target = Node::create();
	targetSprite->setScale(0.6f);
	auto targetBody = PhysicsBody::createBox(
		Size(targetSprite->getBoundingBox().size.width, targetSprite->getBoundingBox().size.height * 0.4f),
		PHYSICSBODY_MATERIAL_DEFAULT
	);
	targetSprite->setPosition(Point(visibleSize.width * 0.9 + origin.x, bottomBarOffset + 155));
	target->setPosition(Point(visibleSize.width * 0.9 + origin.x, bottomBarOffset + 100));
	targetBody->setDynamic(false);
	targetBody->setCollisionBitmask(colBitMaskTarget);
	targetBody->setContactTestBitmask(true);
	target->setPhysicsBody(targetBody);
	this->addChild(targetSprite);
	this->addChild(target);

	//ball / Player
	auto ballBody = PhysicsBody::createCircle(
		17.5f,
		PHYSICSBODY_MATERIAL_DEFAULT
	);
	ballBody->setMass(10.0f);
	player = Sprite::create("ball.png");
	player->setPosition(Vec2(visibleSize.width * 0.1f, visibleSize.height * 0.95f));
	ballBody->setDynamic(false);
	ballBody->setCollisionBitmask(colBitMaskPlayer);
	ballBody->setContactTestBitmask(true);
	player->setPhysicsBody(ballBody);
	this->addChild(player);

	// Initialise Vectors for child classes (if size ever my be necessary, move initialisation to child classes)
	obstacleObjects = Vector<Sprite*>();
	helperObjects = Vector<GenericSprite*>();

	// Collision Detection
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GenericLevelScene::onContact, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	// TouchListener
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(GenericLevelScene::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(GenericLevelScene::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(GenericLevelScene::onTouchesEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	scheduleUpdate();

	return true;
}

void GenericLevelScene::update(float delta)
{
	int minutes = 0;
	int seconds = 0;

	time += delta;

	seconds = (int)time;
	if ((seconds / 60) > 0) 
	{
		minutes = seconds / 60;
		seconds = seconds % 60;
	}

	string leadingSecondZero = "";
	string leadingMinuteZero = "";
	if (seconds < 10) 
	{
		leadingSecondZero = "0";
	}
	if (minutes < 10)
	{
		leadingMinuteZero = "0";
	}

	textFieldTime->setText(leadingMinuteZero + to_string(minutes) + ":" + leadingSecondZero + to_string(seconds));
}

void GenericLevelScene::onTouchesBegan(const std::vector<Touch*>& touches, Event * event)
{
	for (auto touch : touches) {
		if (touch != nullptr) {
			auto tap = touch->getLocation();
			for (auto helperObject : helperObjects) {
				if (helperObject->boundingBox().containsPoint(tap)) {
					helperObject->setTouch(touch);
				}
			}
		}
	}
}

void GenericLevelScene::onTouchesMoved(const std::vector<Touch*>& touches, Event * event)
{
	for (auto touch : touches) 
	{
		if (touch != nullptr) 
		{
			auto tap = touch->getLocation();
			for (auto helperObject : helperObjects) 
			{
				if (helperObject->getTouch() != nullptr && helperObject->getTouch() == touch) 
				{
					Point touchPosition = tap;
					auto halfWidth = helperObject->getBoundingBox().size.width / 2;
					auto halfHeight = helperObject->getBoundingBox().size.height / 2;

					// Left Side
					if (touchPosition.x < halfWidth)
					{
						touchPosition.x = halfWidth;
					}
					// Right side
					if (touchPosition.x > visibleSize.width - halfWidth)
					{
						touchPosition.x = visibleSize.width - halfWidth;
					}

					// Ground
					if (touchPosition.y < halfHeight + bottomBarOffset + 65)
					{
						touchPosition.y = halfHeight + bottomBarOffset + 65;
					}
					// Top
					if (touchPosition.y > visibleSize.height - halfHeight)
					{
						touchPosition.y = visibleSize.height - halfHeight;
					}
			
					helperObject->setPosition(touchPosition);
				}
			}
		}
	}
}


void GenericLevelScene::onTouchesEnded(const std::vector<Touch*>& touches, Event * event)
{
	for (auto touch : touches) {
		if (touch != nullptr) {
			auto tap = touch->getLocation();
			for (auto helperObject : helperObjects) {
				if (helperObject->getTouch() != nullptr && helperObject->getTouch() == touch) {
					//if touch ending belongs to this player, clear it
					helperObject->setTouch(nullptr);
					//player->setVector(Vec2(0, 0));
				}
			}
		}
	}
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

bool GenericLevelScene::onContact(cocos2d::PhysicsContact & contact)
{
	PhysicsBody *bodyA = contact.getShapeA()->getBody();
	PhysicsBody *bodyB = contact.getShapeB()->getBody();

	// Check if player collided with ground
	if ((bodyA->getCollisionBitmask() == colBitMaskGround && bodyB->getCollisionBitmask() == colBitMaskPlayer) ||
		(bodyB->getCollisionBitmask() == colBitMaskGround && bodyA->getCollisionBitmask() == colBitMaskPlayer)) 
	{
		CCLOG(">>> GAME LOST");
	}

	// Check if player collided with target
	else if ((bodyA->getCollisionBitmask() == colBitMaskTarget && bodyB->getCollisionBitmask() == colBitMaskPlayer) ||
		(bodyB->getCollisionBitmask() == colBitMaskTarget && bodyA->getCollisionBitmask() == colBitMaskPlayer))
	{
		CCLOG(">>> GAME WOM");
	}

	// Check if player collided with bumper (necessary for bumper animation)
	else if ((bodyA->getCollisionBitmask() == colBitMaskBumper && bodyB->getCollisionBitmask() == colBitMaskPlayer) ||
		(bodyB->getCollisionBitmask() == colBitMaskBumper && bodyA->getCollisionBitmask() == colBitMaskPlayer))
	{
		CCLOG(">>> Bumper Collision");
	}

	// Check if player collided with slope / ramp (for player animation)

	// Check other collision that should cause any animation

	return true;
}


