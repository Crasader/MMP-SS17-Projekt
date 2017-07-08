#ifndef __GENERICLEVEL_SCENE_H__
#define __GENERICLEVEL_SCENE_H__

#include "cocos2d.h"

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

protected:
	Vector<Sprite*> obstacleObjects;
	Vector<Sprite*> helperObjects;

	Sprite* ground;
	
	Sprite* player;

	Sprite* target;
};

#endif // __GENERICLEVEL_SCENE_H__
