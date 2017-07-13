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
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
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
    
    auto wall3 = WallSprite::createWallSprite();
    wall3->setPosition(Point(visibleSize.width * 0.8f + origin.x, bottomBarOffset + 175));
    this->addChild(wall3);
    
    auto block = BlockSprite::createBlockSprite(BlockSprite::TYPE_HORIZONTAL_SAND);
    block->setPosition(Point(visibleSize.width * 0.1f, visibleSize.height * 0.75f));
    this->addChild(block);
    
    auto block2 = BlockSprite::createBlockSprite(BlockSprite::TYPE_HORIZONTAL_SAND);
    block2->setPosition(Point(visibleSize.width * 0.4 + origin.x, visibleSize.height * 0.35));
    block2->setScale(0.8f, 0.8f);
    this->addChild(block2);
    
    auto block3 = BlockSprite::createBlockSprite(BlockSprite::TYPE_HORIZONTAL_SAND);
    block3->setPosition(Point(visibleSize.width * 0.55f + origin.x, visibleSize.height * 0.4f));
    block3->setScale(0.7f, 0.8f);
    this->addChild(block3);
    
    auto block4 = BlockSprite::createBlockSprite(BlockSprite::TYPE_HORIZONTAL_SAND);
    block4->setPosition(Point(visibleSize.width * 0.7f + origin.x, visibleSize.height * 0.45f));
    block4->setScale(0.6f, 0.8f);
    this->addChild(block4);

	// Add all obstacles to the obstacleObjects Vector
	GenericLevelScene::obstacleObjects.pushBack(block);
    GenericLevelScene::obstacleObjects.pushBack(block2);
    GenericLevelScene::obstacleObjects.pushBack(block3);
    GenericLevelScene::obstacleObjects.pushBack(block4);
    GenericLevelScene::obstacleObjects.pushBack(wall);
    GenericLevelScene::obstacleObjects.pushBack(wall2);
    

	// Add helper objects
    auto slope = SlopeSprite::createSlopeSprite(SlopeSprite::TYPE_MEDIUM);
    slope->setPosition(Point(visibleSize.width * 0.12f + origin.x, visibleSize.height * 0.8f));
    slope->setScale(0.4f, 0.4f);
    this->addChild(slope);
    
    auto slope2 = SlopeSprite::createSlopeSprite(SlopeSprite::TYPE_MEDIUM);
    slope2->setPosition(Point(visibleSize.width * 0.5f + origin.x, visibleSize.height * 0.8f));
    slope2->setScale(0.4f, 0.4f);
    this->addChild(slope2);
    
 
    auto bumper = BumperSprite::createBumperSprite();
    bumper->setPosition(Point(visibleSize.width * 0.45f + origin.x, visibleSize.height * 0.38f));
    bumper->setScale(0.4f, 0.4f);
    this->addChild(bumper);
    
    auto bumper2 = BumperSprite::createBumperSprite();
    bumper2->setPosition(Point(visibleSize.width * 0.55f + origin.x, visibleSize.height * 0.43f));
    bumper2->setScale(0.4f, 0.4f);
    this->addChild(bumper2);
    
    auto bumper3 = BumperSprite::createBumperSprite();
    bumper3->setPosition(Point(visibleSize.width * 0.65f + origin.x, visibleSize.height * 0.48f));
    bumper3->setScale(0.4f, 0.4f);
    this->addChild(bumper3);
    
    auto ramp = RampSprite::createRampSprite(RampSprite::TYPE_STEEP);
    ramp->setPosition(Point(visibleSize.width * 0.8f + origin.x, visibleSize.height * 0.6f));
    this->addChild(ramp);

	// Add all help object to the helperObjects Vector;
    GenericLevelScene::helperObjects.pushBack(slope);
    GenericLevelScene::helperObjects.pushBack(slope2);
    GenericLevelScene::helperObjects.pushBack(bumper);
    GenericLevelScene::helperObjects.pushBack(bumper2);
    GenericLevelScene::helperObjects.pushBack(bumper3);
    GenericLevelScene::helperObjects.pushBack(ramp);

	return true;
}
