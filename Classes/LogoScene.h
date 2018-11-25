#ifndef __LOGO_SCENE_h__
#define __LOGO_SCENE_h__

#include "cocos2d.h"

class LogoScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// here's a difference. method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	void onTouchBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);

	//인트로액션
	void IntroAction1();
	void IntroAction2();

	// a selector callback

	// implement the "static create()" method manually
	CREATE_FUNC(LogoScene);
};

#endif // __helloworld_scene_h__