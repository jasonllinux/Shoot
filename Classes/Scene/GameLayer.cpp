/*
 * GameLayer.cpp
 *
 *  Created on: 2013-3-2
 *      Author: rescue01
 */

#include "GameLayer.h"
#include "GameOver.h"


GameLayer::GameLayer() {
	m_state = statePlaying;

	//m_time(0),m_ship(NULL),m_backSky(NULL),m_backSkyHeight(0),m_backSkyRe(NULL),m_backTileMap(NULL),m_backTileMapHeight(0),m_backTileMapRe(NULL),m_isBackSkyReload(false),m_isBackTileReload(false),m_lbScore(NULL),m_lifeCount(NULL),
//	    m_tempScore(0)
}

GameLayer::~GameLayer() {
//	  if (m_levelManager) {
//	        delete m_levelManager;
//	    }
//
//	    play_bullet->release();
//	    enemy_bullet->release();
//	    enemy_items->release();
}

CCScene* GameLayer::scene()
{
    CCScene *scene = CCScene::create();

    GameLayer *layer = GameLayer::create();

    scene->addChild(layer);
    return scene;
}


bool GameLayer::init() {

	if (!CCLayer::init()) {
		return false;
	}
	// 开启触摸
	this->setTouchEnabled(true);

	// 创建数组，需要retain一下
//    play_bullet = CCArray::create();
//    play_bullet->retain();
	winSize = CCDirector::sharedDirector()->getWinSize();
	//初始化背景
	initBackground();

	//生成Hero
	 m_hero = Hero::create();
	 addChild(m_hero,m_hero->getZOrder(), 1001);

// 自动每周期调 update函数
	 scheduleUpdate();

	 //加Music


	return true;
}

//没周期更新 检查
void GameLayer::update(float dt)
{
    if (m_state == statePlaying) {
//        checkIsCollide();
//        removeInactiveUnit(dt);
//        checkIsReborn();
//        updateUI();
    }

}



void GameLayer::initBackground() {

//	schedule(schedule_selector(GameLayer::movingBackground()), 3);
}

void GameLayer::movingBackground() {

}


void GameLayer::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCLayer::onEnter();
}

void GameLayer::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}


bool GameLayer::ccTouchBegan(CCTouch *touch, CCEvent *event)
{
//    CCLog("touch began!");
    return true;
}


void GameLayer::ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    if ((m_state == statePlaying) && m_hero) {
		CCPoint pos = touch->getDelta();
		CCPoint currentPos = m_hero->getPosition();
		currentPos = ccpAdd(currentPos, pos);
		currentPos = ccpClamp(currentPos, CCPointZero, ccp(winSize.width, winSize.height));
		m_hero->setPosition(currentPos);
    }

}

void GameLayer::ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
//    CCLog("touch end!");
}

//游戏结束
void GameLayer::gameOver()
{
    CCScene * scene = GameOver::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2, scene));
}

//暂停游戏
void GameLayer::doPause(CCObject *pSender)
{
    CCDirector::sharedDirector()->pause();
//    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
//    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
//    PauseLayer *pauseLayer = PauseLayer::create();
//    addChild(pauseLayer,9999);
}

Hero* GameLayer::getHero()
{
    return m_hero;
}
