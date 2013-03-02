/*
 * GameLayer.h
 *
 *  Created on: 2013-3-2
 *      Author: rescue01
 */

#ifndef GAMELAYER_H_
#define GAMELAYER_H_

#include <cocos2d.h>
#include "Entity/Hero.h"

USING_NS_CC;

enum State{
    statePlaying = 0,
    stateGameOver= 1,
};


class GameLayer : public cocos2d::CCLayer{
public:
	GameLayer();
	virtual ~GameLayer();
	static cocos2d::CCScene* scene();

	virtual bool init();
	virtual void update(float dt);
	virtual void onEnter();
	virtual void onExit();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
	CREATE_FUNC(GameLayer);


private :
	Hero* m_hero;
	CCSize winSize;
	CCSprite * m_backGround;
	State m_state;

	void initBackground();  //初始化背景图片
	void movingBackground(); //每周期转背景
	void gameOver();
	void doPause(CCObject *pSender);
	Hero* getHero();

};

#endif /* GAMELAYER_H_ */
