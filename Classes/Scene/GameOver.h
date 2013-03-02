/*
 * GameOver.h
 *
 *  Created on: 2013-1-5
 *      Author: rescue01
 */

#ifndef GAMEOVER_H_
#define GAMEOVER_H_

#include "cocos2d.h"

using namespace cocos2d;

class GameOver : public cocos2d::CCLayer {

public:
	GameOver();
	~GameOver();

	virtual bool init();
	static cocos2d::CCScene* scene();
	CREATE_FUNC(GameOver);

private:
	void menuBackCallback(CCObject* pSender);  //返回传递函数


};

#endif /* GAMEOVER_H_ */
