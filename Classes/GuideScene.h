#ifndef __GUIDE_SCENE_H__
#define __GUIDE_SCENE_H__

#include "cocos2d.h"

class GuideScene : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GuideScene);

private:
	void goToMainMenuScene(cocos2d::Ref *sender);

};

#endif // __GUIDE_SCENE_H__
