//#include "IntroScene.h"
//#include "StartScene.h"
//
//
//USING_NS_CC;
//
//
//Scene* IntroScene::createScene()
//{
//    // 'scene' is an autorelease object
//    auto scene = Scene::create();
//    
//    // 'layer' is an autorelease object
//    auto layer = IntroScene::create();
//
//    // add layer as a child to scene
//    scene->addChild( layer );
//
//    // return the scene
//    return scene;
//}
//
//bool IntroScene::init()
//{
//    //////////////////////////////
//    // 1. super init first
//    if ( !Layer::init() )
//    {
//        return false;
//    }
//
//	Size winSize = Director::sharedDirector()->getWinSize();
//	/*CCSpriteFrameCache* frameCacheChar = CCSpriteFrameCache::sharedSpriteFrameCache();
//
//	frameCacheChar->addSpriteFramesWithFile("intro/intro.plist");*/
//
//	//팀으로 이미지 액션
//	Sprite *spr = Sprite::createWithSpriteFrameName( "intro.png" );
//	spr->setAnchorPoint( ccp( 0.5,0.5 ) );
//	spr->setPosition( Point( winSize.width / 2, winSize.height / 2 ) );
//
//	FadeIn *action_0 = FadeIn::create( 1.5f );			//점점 보여주기
//	DelayTime *action_1 = DelayTime::create( 1.0f );    //대기시간
//	FadeOut *action_2 = FadeOut::create( 1.0f );		//다시 사라지기
//	Sequence *pAction1 = Sequence::create( action_0, action_1, action_2, CallFunc::create( this, callfunc_selector( IntroScene::IntroAction1 ) ), NULL );
//	spr->runAction( pAction1 );
//	this->addChild( spr );
//
//	return true;
//}
//
//void IntroScene::IntroAction1()
//{	
//	Size winSize = Director::sharedDirector()->getWinSize();
//	//게임이름 액션 시작.
//	Sprite *spr = Sprite::createWithSpriteFrameName( "StartScene.png" );
//	spr->setAnchorPoint( ccp( 0.5,0.5 ) );
//	spr->setPosition( Point( winSize.width / 2, winSize.height / 2 ) );
//
//	FadeIn *action_0 = FadeIn::create( 1.5f );			//점점 보여주기
//	DelayTime *action_1 = DelayTime::create( 0.3f );    //대기시간
//	Sequence *pAction1 = Sequence::create( action_0, action_1, CallFunc::create( this, callfunc_selector( IntroScene::IntroAction2 ) ), NULL );
//	spr->runAction( pAction1 );
//
//	//게임 이름 나오기전에 뒤로 가기 키 누르면 게임을 나올수 있게하기.(키설정 먼저)
//	auto dispatcher = Director::getInstance()->getEventDispatcher();
//	auto listener = EventListenerKeyboard::create();
//	listener->onKeyReleased = CC_CALLBACK_2( IntroScene::onKeyReleased, this );
//	dispatcher->addEventListenerWithSceneGraphPriority( listener, this );	
//
//	this->addChild( spr );
//}
//
////팀 이름 액션이 끝난후 게임 시작 나타나게하고 키 설정하기.
//void IntroScene::IntroAction2()
//{
//	Size winSize = Director::sharedDirector()->getWinSize();
//	//깜박이게 하기.
//	LabelTTF* pLabel = LabelTTF::create( "Game Start ", "Arial", 60 );
//	pLabel->setColor(Color3B::BLACK);
//	pLabel->setPosition( Point( winSize.width / 2, 80 ) );
//	Blink *pAction = Blink::create( 1.0f, 1 );    // 시간, 횟수
//	RepeatForever *actionRep = RepeatForever::create( pAction );// 계속해서 반복
//	pLabel->runAction( actionRep );
//	this->addChild( pLabel );
//
//	//터치 설정(화면을 터치했을때. 다음 씬으로 넘기기.)
//	auto dispatcher = Director::getInstance()->getEventDispatcher();
//	auto listener = EventListenerTouchAllAtOnce::create();
//	listener->onTouchesBegan = CC_CALLBACK_2( IntroScene::onTouchBegan, this );
//	dispatcher->addEventListenerWithSceneGraphPriority( listener, this );
//}
//
//void IntroScene::onTouchBegan( const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event )
//{
//	//다음메뉴로넘어가기
//	Scene* s = TransitionFade::create( 1.0f,StartScene::createScene(), ccWHITE );
//	Director::getInstance()->replaceScene( s );
//}
//
//void IntroScene::onKeyReleased ( EventKeyboard::KeyCode keyCode, Event* event )
//{
//	if( keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE )
//	{
//		Director::sharedDirector()->end();  //종료를 위한 함수, KEY_BACKSPACE가 BACK입니다.
//	}
//}