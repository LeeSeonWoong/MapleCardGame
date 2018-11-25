#include "LogoScene.h"
#include "StartScene.h"

USING_NS_CC;

Scene* LogoScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LogoScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LogoScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	//Size visibleSize = Director::getInstance()->getVisibleSize();
	//Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size winSize = Director::sharedDirector()->getWinSize();
	//
	//Sprite *spr = Sprite::create("ylstudio.png");

	//spr->setAnchorPoint(ccp(0.5, 0.5));
	//spr->setPosition(Point(winSize.width / 2, winSize.height / 2));

	//FadeIn *action_0 = FadeIn::create(1.5f);			//점점 보여주기
	//DelayTime *action_1 = DelayTime::create(1.0f);    //대기시간
	//FadeOut *action_2 = FadeOut::create(1.0f);		//다시 사라지기
	//Sequence *pAction1 = Sequence::create(action_0, action_1, action_2, CallFunc::create(this, callfunc_selector(LogoScene::IntroAction1)), NULL);
	//spr->runAction(pAction1);
	//

	//this->addChild(spr,0);


	auto spr = Sprite::create("ylstudio/ylstudio1.png");
	spr->setPosition(Vec2(winSize.width / 2 , winSize.height / 2));
	this->addChild(spr);

	auto Ani = Animation::create();
	Ani->setDelayPerUnit(0.1);

	Ani->addSpriteFrameWithFile("ylstudio/ylstudio1.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio2.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio3.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio4.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio5.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio6.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio7.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio8.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio9.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio10.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio11.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio12.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio13.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio14.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio15.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio16.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio17.png");
	Ani->addSpriteFrameWithFile("ylstudio/ylstudio18.png");

	auto animate = Animate::create(Ani);
	auto action = Repeat::create(animate, 1);

	Sequence *sq = Sequence::create(action, CallFunc::create(this, callfunc_selector(LogoScene::IntroAction1)), NULL);
	spr->runAction(sq);

	return true;
}
void LogoScene::IntroAction1()
{
	Size winSize = Director::sharedDirector()->getWinSize();
	//게임이름 액션 시작.
	Sprite *spr = Sprite::create("back3.png");
	spr->setAnchorPoint(ccp(0.5, 0.5));
	spr->setPosition(Point(winSize.width / 2, winSize.height / 2));

	FadeIn *action_0 = FadeIn::create(1.5f);			//점점 보여주기
	DelayTime *action_1 = DelayTime::create(0.3f);    //대기시간
	Sequence *pAction1 = Sequence::create(action_0, action_1, CallFunc::create(this, callfunc_selector(LogoScene::IntroAction2)), NULL);
	spr->runAction(pAction1);

	//게임 이름 나오기전에 뒤로 가기 키 누르면 게임을 나올수 있게하기.(키설정 먼저)
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerKeyboard::create();
	listener->onKeyReleased = CC_CALLBACK_2(LogoScene::onKeyReleased, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	this->addChild(spr);
}
void LogoScene::IntroAction2()
{
	Size winSize = Director::sharedDirector()->getWinSize();
	//깜박이게 하기.
	LabelTTF* pLabel = LabelTTF::create("Game Start ", "Arial", 60);
	pLabel->setColor(Color3B::WHITE);
	pLabel->setPosition(Point(winSize.width / 2, 280));
	Blink *pAction = Blink::create(1.0f, 1);    // 시간, 횟수
	RepeatForever *actionRep = RepeatForever::create(pAction);// 계속해서 반복
	pLabel->runAction(actionRep);
	this->addChild(pLabel);

	//터치 설정(화면을 터치했을때. 다음 씬으로 넘기기.)
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(LogoScene::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
void LogoScene::onTouchBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	////다음메뉴로넘어가기
	Scene* s = TransitionFade::create(1.0f, StartScene::createScene());
	Director::getInstance()->replaceScene(s);
}