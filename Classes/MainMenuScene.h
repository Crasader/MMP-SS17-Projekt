#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"

class MainMenuScene : public cocos2d::LayerColor
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(MainMenuScene);

private:
	void goToMainLevel1Scene(cocos2d::Ref *sender);

	void goToMainLevel2Scene(cocos2d::Ref *sender);

	void goToMainLevel3Scene(cocos2d::Ref *sender);

	void goToGuideScene(cocos2d::Ref *sender);

	void goToStartMenuScene(cocos2d::Ref *sender);

};

#endif // __MAINMENU_SCENE_H__
