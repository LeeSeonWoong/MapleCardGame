#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

//카드클래스
class CardInfo : public cocos2d::Object
{
public:
	cocos2d::Sprite *spr;
	cocos2d::Sprite *spr2;//뒷면

	int CardCheck;//중복체크용
	int FlipCheck;//뒤집기체크용
	int TagNum;//자신의 테그값
	CardInfo() : CardCheck(0), FlipCheck(0)
	{}
};

class GameScene : public Layer
{
public:
	static Scene* createScene();
	Size winSize;


	cocos2d::Array *m_cardArr;//카드객체배열저장
	int CardNum;//카드 사용한 스프라이트확인

	Sprite *Mcard[12];
	Sprite *cardback;
	bool touchOnOff;
	int randNum[16];
	int SaveNum;
	int winCheck; 
	bool secondCheck;
	int posx=0;
	int posy;
	virtual bool init();
	char str[100][12];
	void CardInit();
	void menuCloseCallback(Ref* pSender);
	void CardSetting(float t);
	Node *saveObj;
	Node *saveObj2;
	Node *saveObj3;
	Node *saveObj4;

	void selfRemover(Node* sender);
	void winScene();
	void backScene(Node* sender);
	void Return(Node* sender1,Node* sender2,Node *sender3,Node *sender4);

	void doBackFlip(Node* sender);
	void doFrontFlip(cocos2d::Object* pSender);
	void Hide(Node* sender);
	void touchOn();
	void SuccessEffect(Node*sender1, Node* sender2);


	virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *event);
	/*virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *event);
	virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *event);
	virtual void onTouchesCancelled(const std::vector<Touch*>& touches, Event *event);*/

	CREATE_FUNC(GameScene);
};

#endif