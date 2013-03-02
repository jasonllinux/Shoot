/*
 * Hero.cpp
 *
 *  Created on: 2013-3-2
 *      Author: rescue01
 */

#include "Hero.h"

Hero::Hero() {
	m_speed = 220;
			m_bulletSpeed = 900;
			m_HP = 100 ;
			m_bulletTypeValue = 1;
//			m_bulletPowerValue(1);
//			m_throwBombing(false);
			m_canBeAttack = true;
////			m_isThrowBomb(false);
			m_zOder = 3000;
//			m_maxBulletPowerValue(4);
			m_appearPosition = ccp(160, 60);
//			m_hurtColorLife(0);
			m_active= true;

}

Hero::~Hero() {

}

bool Hero::init()
{
    // super init first
    if ( !CCSprite::init() )
    {
        return false;
    }

    // init life
    CCTexture2D * heroTextureCache = CCTextureCache::sharedTextureCache()->addImage(s_hero);
    CCRect rec = CCRectMake(0, 0, 96, 96);
    this->initWithTexture(heroTextureCache,  rec);
//
//
    this->setPosition(m_appearPosition);
//
//
//    // set frame
//    CCSpriteFrame *frame0 = CCSpriteFrame::createWithTexture(shipTextureCache, CCRectMake(0, 0, 60, 38));
//    CCSpriteFrame *frame1 = CCSpriteFrame::createWithTexture(shipTextureCache, CCRectMake(60, 0, 60, 38));
//
//    CCArray *animFrames = CCArray::create();
//    animFrames->addObject(frame0);
//    animFrames->addObject(frame1);
//
//    // ship animate
//    // 这个方法有差异
//    CCAnimation *animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1);
//    CCAnimate *animate = CCAnimate::create(animation);
//    this->runAction(CCRepeatForever::create(animate));
//
    // 子弹发射
//    this->schedule(schedule_selector(Ship::shoot), 0.16);
//
//    // revive effect
//    this->m_canBeAttack = false;
//    CCSprite *ghostSprite = CCSprite::createWithTexture(shipTextureCache, CCRectMake(0, 45, 60, 38));
//    ccBlendFunc cbl = {GL_SRC_ALPHA, GL_ONE};
//    ghostSprite->setBlendFunc(cbl);
//    ghostSprite->setScale(8);
//    ghostSprite->setPosition(ccp(this->getContentSize().width / 2, 12));
//    this->addChild(ghostSprite, 3000, 99999);
//    ghostSprite->runAction(CCScaleTo::create(0.5, 1, 1));
//
//    // 闪烁动画
//    CCBlink *blinks = CCBlink::create(3, 9);
//
//    // 回调，攻击使能
//    // 带执行者回调，谁执行Action传谁。这里是this执行的动作，所以传的就是this
//    CCCallFuncN *makeBeAttack = CCCallFuncN::create(this, callfuncN_selector(Ship::makeAttack));
//
//    this->runAction(CCSequence::create(CCDelayTime::create(0.5), blinks, makeBeAttack, NULL));

    return true;

}


//每周期检测
void Hero::update(float dt)
{

    if (m_HP <= 0) {
        m_active = false;
    }

}


//产生碰撞
void Hero::makeAttack(CCNode * pSender)
{
//    CCLog("pSend tag %d",pSender->getTag());
    this->m_canBeAttack = true;
    this->setVisible(true);
    pSender->removeChildByTag(99999);
//    CCLog("make Attack !");

}


void Hero::shoot(float dt)
{


    int offset = 13;
    CCPoint position = this->getPosition();
    CCSize contentSize = this->getContentSize();
//    Bullet *bullet_a = new Bullet(m_bulletSpeed, "W1.png", 1);
//    if (bullet_a) {
//        bullet_a->autorelease();
//        play_bullet->addObject(bullet_a);
//        this->getParent()->addChild(bullet_a, bullet_a->m_zorder, 901);
//        bullet_a->setPosition(ccp(position.x + offset, position.y + 3 + contentSize.height * 0.3));
//
//    }else{
//        delete bullet_a;
//        bullet_a = 0;
//    }
//
//
//    Bullet *bullet_b = new Bullet(m_bulletSpeed, "W1.png", 1);
//    if (bullet_b) {
//        bullet_b->autorelease();
//        play_bullet->addObject(bullet_b);
//        this->getParent()->addChild(bullet_b, bullet_b->m_zorder, 901);
//        bullet_b->setPosition(ccp(position.x - offset, position.y + 3 + contentSize.height * 0.3));
//    }else{
//        delete bullet_b;
//        bullet_a = 0;
//    }

}

//hp自我减少1
void Hero::hurt()
{
    if (m_canBeAttack) {
        CCLog("under fire!");
        m_HP--;
        this->setColor(ccc3(255, 0, 0));
    }

}


//Dead
void Hero::destroy()
{
    CCLOG("destroy one ship");
//    Config::sharedConfig()->updateLifeCount();

//    CCLOG("life count is %d",Config::sharedConfig()->getLifeCount());

//    Effect *effect = Effect::create();

//    effect->explode(this->getParent(), this->getPosition());

    this->removeFromParent();

//    if (Config::sharedConfig()->getAudioState()){
//        CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(s_shipDestroyEffect);
//
//    }
}


CCRect Hero::collideRect()
{
    CCPoint pos = getPosition();
    CCSize cs = getContentSize();

    return CCRectMake(pos.x - cs.width / 2 , pos.y - cs.height / 2, cs.width, cs.height / 2);
}


bool Hero::isActive()
{
    return m_active;
}

int Hero::getZoder()
{
    return m_zOder;
}
