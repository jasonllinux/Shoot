/*
 * Enemy.h
 *
 *  Created on: 2013-3-2
 *      Author: rescue01
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "AdvanceSprite.h"

class Enemy: public AdvanceSprite {

public:
	Enemy();
	virtual ~Enemy();
	bool enemyInit(EnemyType type);
	virtual void update(float dt);
	void shoot();
	virtual void hurt();
	virtual void destroy();
	virtual CCRect collideRect();
	virtual bool isActive();

	static void sharedEnemy();
	static Enemy* create(EnemyType type);
	int getMoveType();

private:
	bool m_active;
	int m_speed;
	int m_bulletSpeed;
	int m_HP;
	int m_bulletPowerValure;
	int m_moveType;
	int m_scoreValue;
	int m_zOrder;
	float m_delayTime;
	int m_attackMode;

};

#endif /* ENEMY_H_ */
