//¼±ÅÃÁö¾À
#include "SelectScene.h"
#include "GameScene.h"
#include "GameScene2.h"


USING_NS_CC;

Scene* SelectScene::createScene()
{
	auto scene = Scene::create();

	auto layer = SelectScene::create();

	scene->addChild(layer);

	return scene;
}

bool SelectScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initData();
	selectMenu();
	initBG();

	return true;
}

void SelectScene::initData(){
	winSize = Director::getInstance()->getWinSize();
}

void SelectScene::selectMenu(){
	auto item_0 = MenuItemImage::create("menu/4by4_Menu3.png", "menu/4by4_Menu4.png", CC_CALLBACK_1(SelectScene::menuCloseCallback, this));
	auto item_1 = MenuItemImage::create("menu/5by5_Menu3.png", "menu/5by5_Menu4.png", CC_CALLBACK_1(SelectScene::menuCloseCallback, this));

	item_0->setTag(TAG_SELECT_4);
	item_1->setTag(TAG_SELECT_5);

	auto menu = Menu::create(item_0, item_1, NULL);
	menu->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	menu->alignItemsHorizontallyWithPadding(100);
	this->addChild(menu, 3);
}
void SelectScene::initBG(){
	auto BG = Sprite::create("SelectBack.jpg");
	winSize = Director::getInstance()->getWinSize();
	BG->setAnchorPoint(Vec2(0.5, 0.5));
	BG->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(BG);
}
void SelectScene::menuCloseCallback(Ref* pSender)
{
	auto item = (MenuItem*)pSender;

	switch (item->getTag()){
	case TAG_SELECT_4:
	{
		auto scene = TransitionCrossFade::create(1.0, GameScene::createScene());
		Director::getInstance()->replaceScene(scene);
	}
	break;
	case TAG_SELECT_5:
	{
		auto scene = TransitionFadeTR::create(1.0, GameScene2::createScene());
		Director::getInstance()->replaceScene(scene);
	}
	/*Director::getInstance()->end();
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
	#endif*/
	break;
	default:
		break;
	}
}