#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"

class StartScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    
    virtual bool init();
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	void GameMenu1(cocos2d::Object* pSender);
	void GameMenu2(cocos2d::Object* pSender);
	void GameMenu3(cocos2d::Object* pSender);

	CREATE_FUNC(StartScene);
};

#endif // __HELLOWORLD_SCENE_H__
