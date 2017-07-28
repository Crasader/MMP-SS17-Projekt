#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "LevelMediumScene.h"
#include "GlobalValues.h"
#include "MainMenuScene.h"
#include "SlopeSprite.h"
#include "BumperSprite.h"
#include "WallSprite.h"
#include "BlockSprite.h"
#include "RampSprite.h"
#include <string>

USING_NS_CC;

Scene* LevelMediumScene::createScene()
{
	auto scene = Scene::createWithPhysics();;
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0.0f, gravity));
	auto layer = LevelMediumScene::create();

	scene->addChild(layer);

	return scene;
}

// on "init" you need to initialize your instance
bool LevelMediumScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!GenericLevelScene::init())
	{
		return false;
	}


	// Add obstacles
    auto wall = WallSprite::createWallSprite();
    wall->setPosition(Point(visibleSize.width * 0.3f + origin.x, visibleSize.height * 0.88));
    this->addChild(wall);
    
    auto wall2 = WallSprite::createWallSprite();
    wall2->setPosition(Point(visibleSize.width * 0.3f + origin.x, bottomBarOffset + 175));
    this->addChild(wall2);
    
    auto block = BlockSprite::createBlockSprite(BlockSprite::TYPE_HORIZONTAL_SAND);
    block->setPosition(Point(visibleSize.width * 0.23f, visibleSize.height * 0.76f));
    block->setScale(0.7f, 0.7f);
    this->addChild(block);
    
    auto block5 = BlockSprite::createBlockSprite(BlockSprite::TYPE_HORIZONTAL_SAND);
    block5->setPosition(Point(visibleSize.width * 0.23f, visibleSize.height * 0.65f));
    block5->setScale(0.7f, 0.7f);
    this->addChild(block5);
    
    auto block2 = BlockSprite::createBlockSprite(BlockSprite::TYPE_VERTICAL_SAND);
    block2->setPosition(Point(visibleSize.width * 0.8f + origin.x, visibleSize.height * 0.35f));
    block2->setScale(0.9f, 0.9f);
    this->addChild(block2);
    
    auto block6 = BlockSprite::createBlockSprite(BlockSprite::TYPE_SQUARE_SAND);
    block6->setPosition(Point(visibleSize.width * 0.65f + origin.x, visibleSize.height * 0.6f));
    block6->setScale(0.9f, 0.6f);
    this->addChild(block6);
    
    auto block3 = BlockSprite::createBlockSprite(BlockSprite::TYPE_HORIZONTAL_SAND);
    block3->setPosition(Point(visibleSize.width * 0.4f + origin.x, visibleSize.height * 0.47f));
    block3->setScale(0.7f, 0.8f);
    this->addChild(block3);
    
    auto block4 = BlockSprite::createBlockSprite(BlockSprite::TYPE_HORIZONTAL_SAND);
    block4->setPosition(Point(visibleSize.width * 0.4f + origin.x, visibleSize.height * 0.64f));
    block4->setScale(0.7f, 0.8f);
    this->addChild(block4);
    
    auto block7 = BlockSprite::createBlockSprite(BlockSprite::TYPE_VERTICAL_SAND);
    block7->setPosition(Point(visibleSize.width * 0.98f + origin.x, visibleSize.height * 0.45f));
    block7->setScale(0.9f, 0.5f);
    this->addChild(block7);

	// Add all obstacles to the obstacleObjects Vector
	GenericLevelScene::obstacleObjects.pushBack(block);
    GenericLevelScene::obstacleObjects.pushBack(block2);
    GenericLevelScene::obstacleObjects.pushBack(block3);
    GenericLevelScene::obstacleObjects.pushBack(block4);
    GenericLevelScene::obstacleObjects.pushBack(block5);
    GenericLevelScene::obstacleObjects.pushBack(block6);
    GenericLevelScene::obstacleObjects.pushBack(block7);
    GenericLevelScene::obstacleObjects.pushBack(wall);
    GenericLevelScene::obstacleObjects.pushBack(wall2);

	auto booster = SpeedBoosterSprite::createSpeedBoosterSprite();
	booster->setPosition(Point(visibleSize.width * 0.3f + origin.x, visibleSize.height * 0.7f));
	this->addChild(booster);
    

	// Add helper objects
    auto slope = SlopeSprite::createSlopeSprite(SlopeSprite::TYPE_MEDIUM);
    slope->setPosition(Point(visibleSize.width * 0.12f + origin.x, visibleSize.height * 0.7f));
    slope->setScale(0.5f, 0.5f);
    this->addChild(slope);
    
   
 
    auto bumper = BumperSprite::createBumperSprite();
    bumper->setPosition(Point(visibleSize.width * 0.7f + origin.x, visibleSize.height * 0.4f));
    bumper->setScale(0.6f, 0.6f);
    this->addChild(bumper);
    

    auto bumper2 = BumperSprite::createBumperSprite();
    bumper2->setPosition(Point(visibleSize.width * 0.5f + origin.x, visibleSize.height * 0.4f));
    bumper2->setScale(0.8f, 0.8f);
    this->addChild(bumper2);
    
    auto ramp = RampSprite::createRampSprite(RampSprite::TYPE_STEEP);
    ramp->setPosition(Point(visibleSize.width * 0.8f + origin.x, visibleSize.height * 0.8f));
    this->addChild(ramp);

	// Add all help object to the helperObjects Vector;
    GenericLevelScene::helperObjects.pushBack(slope);
    GenericLevelScene::helperObjects.pushBack(bumper);
    GenericLevelScene::helperObjects.pushBack(bumper2);
    GenericLevelScene::helperObjects.pushBack(ramp);

	return true;
}
