#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GlobalValues.h"
#include "GenericLevelScene.h"
#include "MainMenuScene.h"
#include "GenericLevelScene.h"
#include "MyBodyParser.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace CocosDenshion;

// on "init" you need to initialize your instance
bool GenericLevelScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B(bgColorRed, bgColorGreen, bgColorBlue, bgColorAlpha)))
	{
		return false;
	}

	// Initialize private / protected variables
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	obstacleObjects = Vector<Sprite*>();
	helperObjects = Vector<GenericSprite*>();
	time = 0.0f;
	isDroped = false;
	gameOver = false;

	// Create Player Animations
	// PlayerBumper Animation
	Animation* playerAnimationbumper = Animation::createWithSpriteFrames(getAnimation("bumperanimation2.plist",
		"trumpbumper%02d.png", 12), 0.08f);
	playerBumperAnimate = Animate::create(playerAnimationbumper);
	playerBumperAnimate->retain(); // THIS FUCKING SHIT TOOK ME AGES TO FIND OUT 
	// (without this the reference will be null if called in the collision detection)

	// PlayerRamp / Slope Animation
	Animation* playerAnimationRamp = Animation::createWithSpriteFrames(getAnimation("rampeanimation2.plist",
		"trumprampe%02d.png", 30), 1/25.0f);
	playerRampAnimate = Animate::create(playerAnimationRamp);
	playerRampAnimate->retain();

	// Pre-Load sound effects
	auto audio = SimpleAudioEngine::getInstance();
	audio->setEffectsVolume(0.1f);
	audio->preloadEffect("audio/trash.wav");
	audio->preloadEffect("audio/boing.wav");

	// Background
	auto backGround = Sprite::create(currentLevelName);
	backGround->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.5 + origin.y + bottomBarOffset / 2));
	this->addChild(backGround);

	// Back Button
	auto backButtonMenuItem = MenuItemImage::create(spriteBackButton, spriteBackButton,
		CC_CALLBACK_1(GenericLevelScene::goToMainMenuScene, this));
	backButtonMenuItem->setPosition(Point(visibleSize.width * bottomButtonBarLeft + origin.x,
		visibleSize.height * bottomButtonBarVerticalFactor + origin.y));

	// Drop/Reset Button
	dropButtonMenuItem = MenuItemImage::create(spriteDropButton, spriteDropButton,
		CC_CALLBACK_1(GenericLevelScene::dropAction, this));
	dropButtonMenuItem->setPosition(Point(visibleSize.width * bottomButtonBarMiddle + origin.x,
		visibleSize.height * bottomButtonBarVerticalFactor + origin.y));
	auto menu = Menu::create(backButtonMenuItem, dropButtonMenuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	// Time Field
	textFieldTime = ui::TextField::create();
	textFieldTime->setString("00:00");
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
		PhysicsMaterial(1.0f, 0.0f, 2.0f)
	);
	auto ground = Node::create();
	ground->setPosition(Point(visibleSize.width * 0.5 + origin.x, bottomBarOffset + 50));
	groundBody->setDynamic(false);
	groundBody->setCollisionBitmask(colBitMaskGround);
	groundBody->setContactTestBitmask(true);
	ground->setPhysicsBody(groundBody);
	this->addChild(ground);

	// Targetsprite basket, def before player because otherwhise he would fall "behind" the basket
	auto basketSprite = Sprite::create(spriteBasket);
	basketSprite->setScale(0.65f);
	basketSprite->setPosition(Point(visibleSize.width * 0.9 + origin.x, bottomBarOffset + 162));
	this->addChild(basketSprite);

	//ball / Player
	player = Sprite::create("trumpfallingsmall.png");
	player->setScale(1.5, 1.5);
	auto playerBody = PhysicsBody::createBox(
		Size(player->getBoundingBox().size.width / 1.5 - 5, player->getBoundingBox().size.height / 1.5 - 5),
		PhysicsMaterial(0.1f, 0.5f, 0.05f)
	);
	playerBody->setMass(120.0f);

	player->setPosition(Vec2(visibleSize.width * 0.1f, visibleSize.height * 0.92f));
	playerBody->setDynamic(false);
	playerBody->setCollisionBitmask(colBitMaskPlayer);
	playerBody->setContactTestBitmask(true);
	player->setPhysicsBody(playerBody);
	this->addChild(player);

	//Targetsprite bin
	auto binSprite = Sprite::create(spriteBin);
	binSprite->setScale(0.65f);
	MyBodyParser::getInstance()->parseJsonFile(jsonTarget);
	auto targetSpriteBody = MyBodyParser::getInstance()->bodyFormJson(binSprite, jsonNameTarget, PHYSICSBODY_MATERIAL_DEFAULT);

	if (targetSpriteBody != nullptr)
	{
		targetSpriteBody->setDynamic(false);
		binSprite->setPhysicsBody(targetSpriteBody);
	}
	binSprite->setPosition(Point(visibleSize.width * 0.9 + origin.x, bottomBarOffset + 162));
	this->addChild(binSprite);

	// target (inside the bin)
	target = Node::create();
	auto targetBody = PhysicsBody::createBox(
		Size(binSprite->getBoundingBox().size.width * 0.6f, 3),
		PhysicsMaterial(1.0f, 0.0f, 2.5f)
	);
	target->setPosition(Point(visibleSize.width * 0.9 + origin.x, bottomBarOffset + 72));
	targetBody->setDynamic(false);
	targetBody->setCollisionBitmask(colBitMaskTarget);
	targetBody->setContactTestBitmask(true);
	target->setPhysicsBody(targetBody);
	this->addChild(target);

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


Vector<SpriteFrame*> GenericLevelScene::getAnimation(const char* plist, const char* format, int count)
{
    SpriteFrameCache* bumperCache = SpriteFrameCache::getInstance();
	bumperCache->addSpriteFramesWithFile(plist);
    
    Vector<SpriteFrame*> animFrames(count);
    char str[100];
    for(int i = 1; i < count; i++)
	{
        sprintf(str, format, i);
        SpriteFrame* frame = bumperCache->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }

	return animFrames;
}


void GenericLevelScene::update(float delta)
{
	updateTimer(delta);

	// Loose when ball stops
	//if (player->getPhysicsBody()->getVelocity().getLength() == 0)
	//{
	//	playWinLoosAnimation(spriteLooseScreen);
	//}
}

void GenericLevelScene::updateTimer(float delta)
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

	textFieldTime->setString(leadingMinuteZero + to_string(minutes) + ":" + leadingSecondZero + to_string(seconds));
}

void GenericLevelScene::onTouchesBegan(const std::vector<Touch*>& touches, Event * event)
{
	if (!isDroped)
	{
		for (auto touch : touches) {
			if (touch != nullptr) {
				auto tap = touch->getLocation();
				for (auto helperObject : helperObjects) {
					if (helperObject->getBoundingBox().containsPoint(tap)) {
						helperObject->setTouch(touch);
					}
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

					// Obstacle object
					//for each (auto obstacle in obstacleObjects)
					//{
					//	// Y - AXIS
					//	if (touchPosition.x < obstacle->getPosition().x + (obstacle->getBoundingBox().size.width / 2) + halfWidth
					//		&& touchPosition.x > obstacle->getPosition().x - (obstacle->getBoundingBox().size.width / 2) - halfWidth)
					//	{
					//		// TOP CHECK
					//		if ((touchPosition.y < obstacle->getPosition().y + (obstacle->getBoundingBox().size.height / 2) + halfHeight) 
					//			&& (touchPosition.y > obstacle->getPosition().y))
					//		{
					//			touchPosition.y = obstacle->getPosition().y + (obstacle->getBoundingBox().size.height / 2) + halfHeight;
					//		}
					//		// BOTTOM CHECK
					//		else if ((touchPosition.y > obstacle->getPosition().y - (obstacle->getBoundingBox().size.height / 2) - halfHeight)
					//			&& (touchPosition.y < obstacle->getPosition().y))
					//		{
					//			touchPosition.y = obstacle->getPosition().y - (obstacle->getBoundingBox().size.height / 2) - halfHeight;
					//		}
					//	}

					//	// X - AXIS
					//	if (touchPosition.y < obstacle->getPosition().y + (obstacle->getBoundingBox().size.height / 2) + halfHeight
					//		&& touchPosition.y > obstacle->getPosition().y - (obstacle->getBoundingBox().size.height / 2) - halfHeight)
					//	{
					//		// TOP CHECK
					//		if ((touchPosition.x < obstacle->getPosition().x + (obstacle->getBoundingBox().size.width / 2) + halfWidth)
					//			&& (touchPosition.x > obstacle->getPosition().x))
					//		{
					//			touchPosition.x = obstacle->getPosition().x + (obstacle->getBoundingBox().size.width / 2) + halfWidth;
					//		}
					//		// BOTTOM CHECK
					//		else if ((touchPosition.x > obstacle->getPosition().x - (obstacle->getBoundingBox().size.width / 2) - halfWidth)
					//			&& (touchPosition.x < obstacle->getPosition().x))
					//		{
					//			touchPosition.x = obstacle->getPosition().x - (obstacle->getBoundingBox().size.width / 2) - halfWidth;
					//		}
					//	}
					//}
			
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
					//if touch ending belongs to this object, clear it
					helperObject->setTouch(nullptr);
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
	isDroped = !isDroped;
	if(isDroped)
	{
		// Drop button
		dropButtonMenuItem->setSelectedImage(Sprite::create(spriteResetButton));
		dropButtonMenuItem->setNormalImage(Sprite::create(spriteResetButton));

		player->getPhysicsBody()->setDynamic(true);
	}
	else
	{
		// Reset button
		dropButtonMenuItem->setSelectedImage(Sprite::create(spriteDropButton));
		dropButtonMenuItem->setNormalImage(Sprite::create(spriteDropButton));

		// Reset Animation
		if (player->getNumberOfRunningActions() > 0)
		{
			player->stopAllActions();
			// Looks ugly, but it works
			player->setSpriteFrame(playerBumperAnimate->getAnimation()->getFrames().front()->getSpriteFrame());
		}

		// Reset Player position
		player->getPhysicsBody()->setDynamic(false);
		player->getPhysicsBody()->setVelocityLimit(FLT_MAX);
		player->setPosition(Vec2(visibleSize.width * 0.1f, visibleSize.height * 0.92f));
		player->setRotation(0);

		gameOver = false;

		this->removeChild(winLooseSprite);
	}
}

bool GenericLevelScene::onContact(cocos2d::PhysicsContact & contact)
{
	PhysicsBody *bodyA = contact.getShapeA()->getBody();
	PhysicsBody *bodyB = contact.getShapeB()->getBody();

	// Check if player collided with ground
	if ((bodyA->getCollisionBitmask() == colBitMaskGround && bodyB->getCollisionBitmask() == colBitMaskPlayer) ||
		(bodyB->getCollisionBitmask() == colBitMaskGround && bodyA->getCollisionBitmask() == colBitMaskPlayer)) 
	{
		// Fixes weird bounce back issue that sometimes happens when the player hits the ground at a specific angle
		player->getPhysicsBody()->setVelocityLimit(250);

		playWinLoosAnimation(spriteLooseScreen);
	}

	// Check if player collided with target
	else if ((bodyA->getCollisionBitmask() == colBitMaskTarget && bodyB->getCollisionBitmask() == colBitMaskPlayer) ||
		(bodyB->getCollisionBitmask() == colBitMaskTarget && bodyA->getCollisionBitmask() == colBitMaskPlayer))
	{
		// Fixes weird bounce back issue that sometimes happens when the player hits the ground at a specific angle
		player->getPhysicsBody()->setVelocityLimit(0);

		if (!gameOver)
		{
			SimpleAudioEngine::getInstance()->playEffect("audio/trash.wav");
		}

		playWinLoosAnimation(spriteWinScreen);
	}

	// Check if player collided with bumper (necessary for bumper animation)
	else if ((bodyA->getCollisionBitmask() == colBitMaskBumper && bodyB->getCollisionBitmask() == colBitMaskPlayer) ||
		(bodyB->getCollisionBitmask() == colBitMaskBumper && bodyA->getCollisionBitmask() == colBitMaskPlayer))
	{
		Sprite* bumperSprite;
		if (bodyA->getCollisionBitmask() == colBitMaskBumper)
		{
			bumperSprite = (Sprite*)bodyA->getOwner();
		}
		else
		{
			bumperSprite = (Sprite*)bodyB->getOwner();
		}

		HandleBumperCollision(bumperSprite);
	}

	// Check if player collided with ramp (for player animation)
	// Animation won't play if palyer collides with a slope, disabled the collisionbitmask
	// in the SlopeSprite.cpp (animation does not work with the slope)
	else if ((bodyA->getCollisionBitmask() == colBitMaskSlopeRamp && bodyB->getCollisionBitmask() == colBitMaskPlayer) ||
		(bodyB->getCollisionBitmask() == colBitMaskSlopeRamp && bodyA->getCollisionBitmask() == colBitMaskPlayer))
	{
		if (player->getNumberOfRunningActions() == 0 && isDroped)
		{
			player->runAction(playerRampAnimate);
		}
	}

	return true;
}

void GenericLevelScene::HandleBumperCollision(cocos2d::Sprite * bumperSprite)
{
	// Can't really put the creation of the Animation in the levelcreation, since you need the size of the bumper to animate
	// Maybe it works by changing the Rect of every spriteframe in the animation?
	// Still too much hassle and performs well enough anyway
	Vector<SpriteFrame*> bumperAnimFrames;

	auto rect = Rect(0, 0, bumperSprite->getBoundingBox().size.width * (1 / bumperSprite->getScale()),
		bumperSprite->getBoundingBox().size.height * (1 / bumperSprite->getScale()));

	auto bumperUnused = SpriteFrame::create(spriteHelperBumper, rect);
	auto bumperUsed = SpriteFrame::create(spriteHelperBumperUsed, rect);

	bumperAnimFrames.reserve(8);
	bumperAnimFrames.pushBack(bumperUnused);
	for (int i = 0; i < 6; i++)
	{
		bumperAnimFrames.pushBack(bumperUsed);
	}
	bumperAnimFrames.pushBack(bumperUnused);

	Animation* bumerAnimation = Animation::createWithSpriteFrames(bumperAnimFrames, 0.04f);
	Animate* bumperAnimate = Animate::create(bumerAnimation);

	// Check if force is enough for bounce
	if (player->getPhysicsBody()->getVelocity().getLength() > 100)
	{
		if (bumperSprite->getNumberOfRunningActions() == 0)
		{
			bumperSprite->runAction(bumperAnimate);
		}
		if (player->getNumberOfRunningActions() == 0)
		{
			player->runAction(playerBumperAnimate);
		}
		SimpleAudioEngine::getInstance()->playEffect("audio/boing.wav");
	}
	else
	{
		// Stop Ball from doing too many small bounces
		// Maybe not the best way
		player->getPhysicsBody()->setVelocity(Vec2(0, 0));
	}
}

void GenericLevelScene::playWinLoosAnimation(string spriteToAnimate)
{
	if (!gameOver)
	{
		gameOver = true;
		this->removeChild(winLooseSprite);
		winLooseSprite = Sprite::create(spriteToAnimate);
		winLooseSprite->setPosition(Vec2(visibleSize.width * 0.5f, (visibleSize.height + bottomBarOffset) * 0.5f));
		winLooseSprite->setScale(0.0f);
		this->addChild(winLooseSprite);

		auto scaleTo = ScaleTo::create(2.0f, 0.8f);
		winLooseSprite->runAction(scaleTo);
	}
}


