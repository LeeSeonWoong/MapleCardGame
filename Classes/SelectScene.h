//#ifndef __SELECT_SCENE_H__
//#define __SELECT_SCENE_H__
//
//#include "cocos2d.h"
//
//#define TAG_SELECT_4 4
//#define TAG_SELECT_5 5
//
//USING_NS_CC;
//
//class SelectScene : public Layer
//{
//public:
//	// there's no 'id' in cpp, so we recommend returning the class instance pointer
//	static Scene* createScene();
//	Size winSize;
//
//	virtual bool init();
//
//	void selectMenu();
//	void initData();
//
//	void menuCloseCallback(Ref* pSender);
//
//	CREATE_FUNC(SelectScene);
//};
//
//#endif // __HELLOWORLD_SCENE_H__
#ifndef __SELECT_SCENE_H__
#define __SELECT_SCENE_H__

#include "cocos2d.h"

#define TAG_SELECT_4 4
#define TAG_SELECT_5 5

USING_NS_CC;

class SelectScene : public Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static Scene* createScene();
	Size winSize;

	virtual bool init();

	void selectMenu();
	void initData();
	void initBG();

	void menuCloseCallback(Ref* pSender);

	CREATE_FUNC(SelectScene);
};

#endif // __HELLOWORLD_SCENE_H__