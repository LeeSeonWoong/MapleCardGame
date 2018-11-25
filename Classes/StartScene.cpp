#include "StartScene.h"
#include "SelectScene.h"

USING_NS_CC;

Scene* StartScene::createScene()
{
    auto scene = Scene::create();
    
	auto layer = StartScene::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//시작화면
	auto sprite = Sprite::create("back4.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	//메뉴목록
	{
		//시작
		MenuItemSprite* item0 = MenuItemSprite::create(Sprite::create("start1.png"), Sprite::create("start1.png"), Sprite::create("start1.png"), this, menu_selector(StartScene::GameMenu1));
		item0->setPosition(Point(0,0));

		//종료
		MenuItemSprite* item1 = MenuItemSprite::create(Sprite::create("Exit.png"), Sprite::create("Exit.png"), Sprite::create("Exit.png"), this, menu_selector(StartScene::GameMenu3));
		item1->setPosition(Point(0, -150));

		auto storeKindMenu = Menu::create(item0,item1, NULL);
		
		this->addChild(storeKindMenu,2);
	}


    this->addChild(sprite, 0);
    
    return true;
}

void StartScene::GameMenu1(cocos2d::Object* pSender)
{
	//SpriteFrameCache::getInstance()->removeSpriteFrames();

	Scene* s = TransitionFade::create(1.0f, SelectScene::createScene());
	Director::getInstance()->replaceScene( s );	
}
void StartScene::GameMenu3(cocos2d::Object* pSender)
{
	SpriteFrameCache::getInstance()->removeSpriteFrames();
	Director::sharedDirector()->end();
}
void StartScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
