#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GlobalValues.h"
#include "LevelHardScene.h"
#include "MainMenuScene.h"
#include "SlopeSprite.h"
#include "BumperSprite.h"
#include "WallSprite.h"
#include "BlockSprite.h"
#include "RampSprite.h"

USING_NS_CC;

Scene* LevelHardScene::createScene()
{
	auto scene = Scene::createWithPhysics();;
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0.0f, gravity));
	auto layer = LevelHardScene::create();

	scene->addChild(layer);

	return scene;
}

// on "init" you need to initialize your instance
bool LevelHardScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!GenericLevelScene::init())
	{
		return false;
	}


	// Add obstacle objects
    auto block = BlockSprite::createBlockSprite(BlockSprite::TYPE_SQUARE_CITY);
    block->setPosition(Point(visibleSize.width * 0.1f, visibleSize.height * 0.6f));
    this->addChild(block);

    auto block2 = BlockSprite::createBlockSprite(BlockSprite::TYPE_SQUARE_CITY);
    block2->setPosition(Point(visibleSize.width * 0.4f, visibleSize.height * 0.5f));
    this->addChild(block2);
    
    
    auto block3 = BlockSprite::createBlockSprite(BlockSprite::TYPE_SQUARE_CITY);
    block3->setPosition(Point(visibleSize.width * 0.7f, visibleSize.height * 0.4f));
    this->addChild(block3);
    
    auto block4 = BlockSprite::createBlockSprite(BlockSprite::TYPE_HORIZONTAL_CITY);
    block4->setPosition(Point(visibleSize.width * 0.4f, visibleSize.height * 0.75f));
    this->addChild(block4);
    
    auto block5 = BlockSprite::createBlockSprite(BlockSprite::TYPE_HORIZONTAL_CITY);
    block5->setPosition(Point(visibleSize.width * 0.7f, visibleSize.height * 0.75f));
    this->addChild(block5);
    
    auto block6 = BlockSprite::createBlockSprite(BlockSprite::TYPE_HORIZONTAL_CITY);
    block6->setPosition(Point(visibleSize.width * 0.4f, visibleSize.height * 0.95f));
    this->addChild(block6);
    
    
    
    auto block8 = BlockSprite::createBlockSprite(BlockSprite::TYPE_VERTICAL_CITY);
    block8->setPosition(Point(visibleSize.width * 0.8f, visibleSize.height * 0.72f));
    block8->setScale(1.0f, 0.5f);
    this->addChild(block8);
    
    auto wall = WallSprite::createWallSprite();
    wall->setPosition(Point(visibleSize.width * 0.83f + origin.x, bottomBarOffset + 175));
    this->addChild(wall);
    
    

	// Add all obstacles to the obstacleObjects Vector
    GenericLevelScene::obstacleObjects.pushBack(block);
    GenericLevelScene::obstacleObjects.pushBack(block2);
    GenericLevelScene::obstacleObjects.pushBack(block3);
    GenericLevelScene::obstacleObjects.pushBack(block4);
    GenericLevelScene::obstacleObjects.pushBack(block5);
    GenericLevelScene::obstacleObjects.pushBack(block6);
 
    GenericLevelScene::obstacleObjects.pushBack(block8);
    GenericLevelScene::obstacleObjects.pushBack(wall);
    


	// Add helper objects
    auto slope = SlopeSprite::createSlopeSprite(SlopeSprite::TYPE_MEDIUM);
    slope->setPosition(Point(visibleSize.width * 0.8f + origin.x, visibleSize.height * 0.8f));
    slope->setScale(0.4f, 0.4f);
    this->addChild(slope);
    
    auto slope2= SlopeSprite::createSlopeSprite(SlopeSprite::TYPE_MEDIUM);
    slope2->setPosition(Point(visibleSize.width * 0.4f + origin.x, visibleSize.height * 0.8f));
    slope2->setScale(0.4f ,0.4f);
    this->addChild(slope2);
    
    auto bumper = BumperSprite::createBumperSprite();
    bumper->setPosition(Point(visibleSize.width * 0.6f + origin.x, visibleSize.height * 0.5f));
    bumper->setScale(0.4f, 0.4f);
    this->addChild(bumper);
    
    auto bumper2 = BumperSprite::createBumperSprite();
    bumper2->setPosition(Point(visibleSize.width * 0.3f + origin.x, visibleSize.height * 0.6f));
    bumper2->setScale(0.4f, 0.4f);
    this->addChild(bumper2);
    
    auto ramp = RampSprite::createRampSprite(RampSprite::TYPE_FLAT);
    ramp->setPosition(Point(visibleSize.width * 0.12f + origin.x, visibleSize.height * 0.8f));
    this->addChild(ramp);

	// Add all help object to the helperObjects Vector;
    GenericLevelScene::helperObjects.pushBack(slope);
    GenericLevelScene::helperObjects.pushBack(slope2);
    GenericLevelScene::helperObjects.pushBack(bumper);
    GenericLevelScene::helperObjects.pushBack(bumper2);
    GenericLevelScene::helperObjects.pushBack(ramp);

	return true;
}
