#ifndef __GENERICLEVEL_SCENE_H__
#define __GENERICLEVEL_SCENE_H__

#include "cocos2d.h"

class GenericLevelScene : public cocos2d::LayerColor
{
	// TODO Make custom Sprite Classes?
	//Sprite* figure;

	//Vector<Sprite*> obstacleObjects;
	//Vector<Sprite*> supportObjects;


public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GenericLevelScene);

private:
	void goToMainMenuScene(cocos2d::Ref *sender);
};

#endif // __GENERICLEVEL_SCENE_H__
