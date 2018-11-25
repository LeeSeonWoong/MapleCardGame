
//
#include "GameScene2.h"
#include "SelectScene.h"

Scene*GameScene2::createScene()
{
	auto scene = Scene::create();

	auto layer = GameScene2::create();

	scene->addChild(layer);

	return scene;
}

// on "init" you need to initialize your instance
bool GameScene2::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size winSize = Director::sharedDirector()->getWinSize();

	//초기 카드 저장셋팅
	m_cardArr = new Array();
	m_cardArr->init();
	//posx = 0;
	posy = 0;
	CardNum = 0;
	SaveNum = 0;
	winCheck = 0;
	secondCheck = false;
	saveObj = NULL;
	saveObj2 = NULL;
	saveObj3 = NULL;
	saveObj4 = NULL;


	touchOnOff = true;

	for (int i = 0; i < 25; i++)
	{
		randNum[i] = 55;
	}

	Sprite *back = Sprite::create("GameBack2.jpg");
	back->setPosition(Point(winSize.width / 2, winSize.height / 2));
	this->addChild(back, 0);

	cardback = Sprite::create("Card_Back/Blue.png");

	//this->addChild(Mcard[CardNum], 1);
	CardInit();
	schedule(schedule_selector(GameScene2::CardSetting), 0.4f, 23, 0.0);//카드셋팅 호출 -> 0.3초간격으로 하나씩셋팅


	this->setTouchEnabled(true);
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(GameScene2::onTouchesBegan, this);
	///*listener->onTouchesMoved = CC_CALLBACK_2(GameStage::onTouchesMoved, this);
	//listener->onTouchesEnded = CC_CALLBACK_2(GameStage::onTouchesEnded, this);
	//listener->onTouchesEnded = CC_CALLBACK_2(GameStage::onTouchesCancelled, this);*/
	//dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//auto listener2 = EventListenerKeyboard::create();
	////listener2->onKeyReleased = CC_CALLBACK_2(GameStage::onKeyReleased, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener2, this);
	return true;
}
//카드초기셋팅
void GameScene2::CardInit()
{
	srand((unsigned)time(NULL));
	int a = rand() % 24;
	int n = 0;
	bool pass = false;
	for (int i = 0; i<24; i++)
	{
		if (randNum[a] == 55)
		{
			randNum[a] = n;
			n += 1;
		}
		else
		{
			a = rand() % 24;
			i -= 1;
		}
	}
}

void GameScene2::CardSetting(float t)
{
	touchOnOff = false;
	//srand((unsigned)time(NULL));
	//this->addChild(Mcard[0], 1);
	char str[100] = { 0 };
	int sNum = 0;
	if (randNum[CardNum] <= 11)
	{
		sprintf(str, "Card/card%d.png", randNum[CardNum]);
		sNum = randNum[CardNum];
	}
	else
	{
		sprintf(str, "Card/card%d.png", randNum[CardNum] - 12);
		sNum = randNum[CardNum];
	}

	Sprite *cardback2 = Sprite::create("Card_Back/Blue.png");
	cardback2->setVisible(false);

	int x = 0;
	int y = 0;
	Sprite *card = Sprite::create(str);
	if (CardNum == 12)
	{
		posx += 1;
		if (posx == 5)
		{
			posy += 1;
		}
		if (posx < 5)
			x = 280 + (posx + 1) * 120;
		else
		{
			posx = 0;
			x = 280 + (posx + 1) * 120;
		}
		posx += 1;

		y = 615 - posy * 120;
	}
	else
	{
		if (posx == 5)
		{
			posy += 1;
		}
		if (posx < 5)
			x = 280 + (posx + 1) * 120;
		else
		{
			posx = 0;
			x = 280 + (posx + 1) * 120;
		}
		posx += 1;

		y = 615 - posy * 120;
	}
	card->setPosition(Point(x, y));

	cardback2->setPosition(Point(x, y));

	ActionInterval * firstHalf = OrbitCamera::create(0.5f, 1.0f, 0, 0, 90.f, 0, 0);
	Sequence *cardS = Sequence::create(firstHalf, CallFuncN::create(CC_CALLBACK_1(GameScene2::Hide, this)), NULL);
	card->runAction(cardS);
	this->addChild(card, 1);

	FiniteTimeAction* action = Sequence::create(
		DelayTime::create(0.5f),
		CallFuncN::create(CC_CALLBACK_1(GameScene2::doBackFlip, this)), NULL);


	//this->runAction(action);
	cardback2->runAction(action);
	this->addChild(cardback2, 1);

	CardNum += 1;

	CardInfo2* sCard;
	sCard = new CardInfo2;
	sCard->spr = card;
	sCard->spr2 = cardback2;

	sCard->CardCheck = sNum;
	m_cardArr->addObject(sCard);

	//터치잠금
	DelayTime *deT = DelayTime::create(6.0f);
	Sequence *sq = Sequence::create(deT, CallFunc::create(CC_CALLBACK_0(GameScene2::touchOn, this)), NULL);

	this->runAction(sq);

}
void GameScene2::Hide(Node* sender)
{
	sender->setVisible(false);
}
//뒤집는 기능함수
void GameScene2::doFrontFlip(cocos2d::Object* pSender)
{
	/*ActionInterval * firstHalf = OrbitCamera::create(0.5f, 1.0f, 0, 0, 90.f, 0, 0);
	if (card1->isVisible())
	{
	card1->runAction(firstHalf);
	}
	else
	{
	card2->runAction(firstHalf);
	}


	FiniteTimeAction* action = Sequence::create(
	DelayTime::create(0.5f),
	CallFunc::create(this, callfunc_selector(GameScene::doBackFlip)),
	NULL);

	this->runAction(action);*/
}
//
void GameScene2::doBackFlip(Node* sender)
{
	CCActionInterval* secondHalf = OrbitCamera::create(0.4f, 1.0f, 0, 270, 90.f, 0, 0);
	sender->setVisible(true);
	sender->runAction(secondHalf);
	/*if (sender->isVisible())
	{
	sender->setVisible(false);
	card2->setVisible(true);
	}
	else
	{
	card1->setVisible(true);
	card2->setVisible(false);
	}

	CCActionInterval* secondHalf = OrbitCamera::create(0.5f, 1.0f, 0, 270, 90.f, 0, 0);
	if (card1->isVisible()) {
	card2->runAction(secondHalf);
	}
	else {
	card2->runAction(secondHalf);
	}*/
}
void GameScene2::onTouchesBegan(const std::vector<Touch*>& touches, Event *event)
{
	if (touchOnOff)
	{
		auto touch = touches[0];
		auto touchPoint = touch->getLocation();
		touchPoint = this->convertToWorldSpace(touchPoint);

		bool bTouch1 = false;
		Object* jt = NULL;
		int cNum = 0;

		CCARRAY_FOREACH(m_cardArr, jt)
		{
			CardInfo2* target = dynamic_cast<CardInfo2*>(jt);
			Sprite* sprTarget2 = target->spr2;
			Sprite* sprTarget = target->spr;
			bTouch1 = false;
			Rect sprRect2 = sprTarget2->getBoundingBox();

			//if (sprTarget != NULL)
			//{
			//	bTouch1 = sprTarget2->getBoundingBox().containsPoint(touchPoint);
			//	//secondCheck = false;
			//	//SaveNum = 0;
			//}

			if (sprRect2.containsPoint(touchPoint))
			{
				if (secondCheck == false)
				{
					SaveNum = target->CardCheck;
					secondCheck = true;
					saveObj2 = sprTarget2;//카드뒷면저장
					saveObj = sprTarget;
					ActionInterval * firstHalf = OrbitCamera::create(0.4f, 1.0f, 0, 0, 90.f, 0, 0);
					Sequence *cardS = Sequence::create(firstHalf, CallFuncN::create(CC_CALLBACK_1(GameScene2::Hide, this)), NULL);
					sprTarget2->runAction(cardS);

					FiniteTimeAction* action = Sequence::create(
						DelayTime::create(0.5f),
						CallFuncN::create(CC_CALLBACK_1(GameScene2::doBackFlip, this)), NULL);

					sprTarget->runAction(action);
				}
				else
				{
					cNum = target->CardCheck;
					//once 와 second가 같으면
					if (SaveNum == (cNum + 12) || SaveNum == (cNum - 12))
					{
						touchOnOff = false;
						ActionInterval * firstHalf = OrbitCamera::create(0.4f, 1.0f, 0, 0, 90.f, 0, 0);
						Sequence *cardS = Sequence::create(firstHalf, CallFuncN::create(CC_CALLBACK_1(GameScene2::Hide, this)), NULL);
						sprTarget2->runAction(cardS);

						FiniteTimeAction* action = Sequence::create(
							DelayTime::create(0.5f),
							CallFuncN::create(CC_CALLBACK_1(GameScene2::doBackFlip, this)), NULL);
						sprTarget->runAction(action);
						SuccessEffect(sprTarget, saveObj);
						winCheck += 1;
						Sequence *touchof = Sequence::create(DelayTime::create(1.0f), CallFunc::create(CC_CALLBACK_0(GameScene2::touchOn, this)), NULL);
						this->runAction(touchof);

						//saveObj->runAction(cardS);
						if (winCheck == 12)
						{
							winScene();
						}
					}
					//다르면
					else
					{
						touchOnOff = false;
						//새로운용
						FiniteTimeAction* action2 = Sequence::create(
							DelayTime::create(1.5f),
							CallFuncN::create(CC_CALLBACK_1(GameScene2::doBackFlip, this)), NULL);

						//새로운용
						ActionInterval * firstHalf2 = OrbitCamera::create(0.4f, 1.0f, 0, 0, 90.f, 0, 0);
						Sequence *cardS2 = Sequence::create(DelayTime::create(1.0f), firstHalf2, CallFuncN::create(CC_CALLBACK_1(GameScene2::Hide, this)), NULL);

						//기존용
						ActionInterval * firstHalf = OrbitCamera::create(0.4f, 1.0f, 0, 0, 90.f, 0, 0);
						Sequence *cardS = Sequence::create(firstHalf, CallFuncN::create(CC_CALLBACK_1(GameScene2::Hide, this)), NULL);

						//기존용
						FiniteTimeAction* action = Sequence::create(
							DelayTime::create(0.5f),
							CallFuncN::create(CC_CALLBACK_1(GameScene2::doBackFlip, this)), DelayTime::create(1.5f), NULL);

						//1초후딜



						//2초후딜
						//sprTarget2->runAction(cardS);
						//sprTarget->runAction(action);

						sprTarget2->runAction(cardS);//뒷면
						sprTarget->runAction(action);//앞면

						Return(saveObj, saveObj2, sprTarget2, sprTarget);


						//saveObj2->runAction(action2);//앞면
						//saveObj->runAction(cardS2);


						/*FiniteTimeAction* action = Sequence::create(
						DelayTime::create(0.5f),
						CallFuncN::create(CC_CALLBACK_1(GameScene::doBackFlip, this)), NULL);
						saveObj->runAction(action);*/
					}
					secondCheck = false;
					SaveNum = 0;
				}
			}
		}
	}
}
void GameScene2::Return(Node*sender1, Node* sender2, Node *sender3, Node *sender4)
{
	//새로운용
	FiniteTimeAction* action2 = Sequence::create(
		DelayTime::create(1.5f),
		CallFuncN::create(CC_CALLBACK_1(GameScene2::doBackFlip, this)), NULL);

	FiniteTimeAction* action3 = Sequence::create(
		DelayTime::create(1.5f),
		CallFuncN::create(CC_CALLBACK_1(GameScene2::doBackFlip, this)), NULL);

	//새로운용
	ActionInterval * firstHalf2 = OrbitCamera::create(0.4f, 1.0f, 0, 0, 90.f, 0, 0);
	Sequence *cardS2 = Sequence::create(DelayTime::create(1.0f), firstHalf2, CallFuncN::create(CC_CALLBACK_1(GameScene2::Hide, this)), NULL);

	ActionInterval * firstHalf3 = OrbitCamera::create(0.4f, 1.0f, 0, 0, 90.f, 0, 0);
	Sequence *cardS3 = Sequence::create(DelayTime::create(1.0f), firstHalf3, CallFuncN::create(CC_CALLBACK_1(GameScene2::Hide, this)), NULL);

	//터치잠금
	DelayTime *deT = DelayTime::create(1.5f);
	Sequence *sq = Sequence::create(deT, CallFunc::create(CC_CALLBACK_0(GameScene2::touchOn, this)), NULL);

	this->runAction(sq);

	sender1->runAction(cardS2);
	sender2->runAction(action2);
	sender4->runAction(cardS3);
	sender3->runAction(action3);
}
void GameScene2::SuccessEffect(Node*sender1, Node* sender2)
{
	Sprite *ceffect = Sprite::create("effect.png");
	Sprite *ceffect2 = Sprite::create("effect.png");

	int pX = sender1->getPosition().x;
	int pY = sender1->getPosition().y;

	int pX2 = sender2->getPosition().x;
	int pY2 = sender2->getPosition().y;

	DelayTime *deT = DelayTime::create(1.0f);
	Sequence *tq = Sequence::create(deT, CallFuncN::create(CC_CALLBACK_1(GameScene2::selfRemover, this)), NULL);

	DelayTime *deT2 = DelayTime::create(1.0f);
	Sequence *tq2 = Sequence::create(deT2, CallFuncN::create(CC_CALLBACK_1(GameScene2::selfRemover, this)), NULL);

	ceffect->setPosition(Point(pX, pY));
	ceffect->runAction(tq);

	ceffect2->setPosition(Point(pX2, pY2));
	ceffect2->runAction(tq2);

	this->addChild(ceffect2, 2);
	this->addChild(ceffect, 2);
}
void GameScene2::winScene()
{
	Size winSize = Director::sharedDirector()->getWinSize();
	Sprite *wins = Sprite::create("WinEffect/Win3.png");
	wins->setPosition(Point(winSize.width / 2, winSize.height / 2));
	Animation* win = Animation::create();
	win->setDelayPerUnit(0.1);
	this->addChild(wins, 3);
	char str[100] = { 0 };

	for (int i = 3; i <= 14; i++)
	{
		sprintf(str, "WinEffect/Win%d.png", i);
		win->addSpriteFrameWithFileName(str);
	}
	auto ani = Animate::create(win);
	auto rep = Repeat::create(ani, 1);

	FadeOut *action_2 = FadeOut::create(3.0f);		//다시 사라지기
	Sequence *sq = Sequence::create(rep, action_2, CallFuncN::create(CC_CALLBACK_1(GameScene2::backScene, this)), NULL);

	wins->runAction(sq);
	


}
void GameScene2::backScene(Node* sender)
{
	auto scene = TransitionFadeTR::create(1.0, SelectScene::createScene());
	Director::getInstance()->replaceScene(scene);
}
void GameScene2::touchOn()
{
	touchOnOff = true;
}
void GameScene2::selfRemover(Node* sender)
{
	sender->removeFromParentAndCleanup(true);
}