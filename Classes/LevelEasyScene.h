#ifndef __LEVELEASY_SCENE_H__
#define __LEVELEASY_SCENE_H__

#include "cocos2d.h"

class LevelEasyScene : public cocos2d::LayerColor
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(LevelEasyScene);

private:
	void goToMainMenuScene(cocos2d::Ref *sender);

};

#endif // __LEVELEASY_SCENE_H__
