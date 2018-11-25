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
//	//������ �̹��� �׼�
//	Sprite *spr = Sprite::createWithSpriteFrameName( "intro.png" );
//	spr->setAnchorPoint( ccp( 0.5,0.5 ) );
//	spr->setPosition( Point( winSize.width / 2, winSize.height / 2 ) );
//
//	FadeIn *action_0 = FadeIn::create( 1.5f );			//���� �����ֱ�
//	DelayTime *action_1 = DelayTime::create( 1.0f );    //���ð�
//	FadeOut *action_2 = FadeOut::create( 1.0f );		//�ٽ� �������
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
//	//�����̸� �׼� ����.
//	Sprite *spr = Sprite::createWithSpriteFrameName( "StartScene.png" );
//	spr->setAnchorPoint( ccp( 0.5,0.5 ) );
//	spr->setPosition( Point( winSize.width / 2, winSize.height / 2 ) );
//
//	FadeIn *action_0 = FadeIn::create( 1.5f );			//���� �����ֱ�
//	DelayTime *action_1 = DelayTime::create( 0.3f );    //���ð�
//	Sequence *pAction1 = Sequence::create( action_0, action_1, CallFunc::create( this, callfunc_selector( IntroScene::IntroAction2 ) ), NULL );
//	spr->runAction( pAction1 );
//
//	//���� �̸� ���������� �ڷ� ���� Ű ������ ������ ���ü� �ְ��ϱ�.(Ű���� ����)
//	auto dispatcher = Director::getInstance()->getEventDispatcher();
//	auto listener = EventListenerKeyboard::create();
//	listener->onKeyReleased = CC_CALLBACK_2( IntroScene::onKeyReleased, this );
//	dispatcher->addEventListenerWithSceneGraphPriority( listener, this );	
//
//	this->addChild( spr );
//}
//
////�� �̸� �׼��� ������ ���� ���� ��Ÿ�����ϰ� Ű �����ϱ�.
//void IntroScene::IntroAction2()
//{
//	Size winSize = Director::sharedDirector()->getWinSize();
//	//�����̰� �ϱ�.
//	LabelTTF* pLabel = LabelTTF::create( "Game Start ", "Arial", 60 );
//	pLabel->setColor(Color3B::BLACK);
//	pLabel->setPosition( Point( winSize.width / 2, 80 ) );
//	Blink *pAction = Blink::create( 1.0f, 1 );    // �ð�, Ƚ��
//	RepeatForever *actionRep = RepeatForever::create( pAction );// ����ؼ� �ݺ�
//	pLabel->runAction( actionRep );
//	this->addChild( pLabel );
//
//	//��ġ ����(ȭ���� ��ġ������. ���� ������ �ѱ��.)
//	auto dispatcher = Director::getInstance()->getEventDispatcher();
//	auto listener = EventListenerTouchAllAtOnce::create();
//	listener->onTouchesBegan = CC_CALLBACK_2( IntroScene::onTouchBegan, this );
//	dispatcher->addEventListenerWithSceneGraphPriority( listener, this );
//}
//
//void IntroScene::onTouchBegan( const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event )
//{
//	//�����޴��γѾ��
//	Scene* s = TransitionFade::create( 1.0f,StartScene::createScene(), ccWHITE );
//	Director::getInstance()->replaceScene( s );
//}
//
//void IntroScene::onKeyReleased ( EventKeyboard::KeyCode keyCode, Event* event )
//{
//	if( keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE )
//	{
//		Director::sharedDirector()->end();  //���Ḧ ���� �Լ�, KEY_BACKSPACE�� BACK�Դϴ�.
//	}
//}