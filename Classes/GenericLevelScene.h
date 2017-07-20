#ifndef __GENERICLEVEL_SCENE_H__
#define __GENERICLEVEL_SCENE_H__

#include "cocos2d.h"
#include "GenericSprite.h"
#include<vector>

using namespace cocos2d;

class GenericLevelScene : public cocos2d::LayerColor
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GenericLevelScene);

private:
	void goToMainMenuScene(cocos2d::Ref *sender);

	void dropAction(cocos2d::Ref *sender);

	bool onContact(cocos2d::PhysicsContact &contact);

	void playWinLoosAnimation(std::string spriteToAnimate);

	ui::TextField* textFieldTime;
	float time;
	virtual void update(float delta);

	void updateTimer(float delta);

	MenuItemImage* dropButtonMenuItem;
	bool isDroped;

	Sprite* winLooseSprite;

	bool gameOver;
    
    //Spritesheet Try
   //cocos2d::Vector getAnimation(const char *format, int count);
    void animationbumper();

protected:
	void onTouchesBegan(const std::vector<Touch*> &touches, Event* event);
	void onTouchesMoved(const std::vector<Touch*> &touches, Event* event);
	void onTouchesEnded(const std::vector<Touch*> &touches, Event* event);

	Vector<Sprite*> obstacleObjects;
	Vector<GenericSprite*> helperObjects;

	Sprite* ground;
	
	Sprite* player;

	Node* target;

	Size visibleSize;
	Vec2 origin;

};

#endif // __GENERICLEVEL_SCENE_H__
