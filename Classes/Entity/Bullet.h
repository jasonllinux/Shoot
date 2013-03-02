/*
 * Bullet.h
 *
 *  Created on: 2013-3-2
 *      Author: rescue01
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "AdvanceSprite.h"

class Bullet: public AdvanceSprite {
public:
	bool m_active;
	int m_zorder;
	Bullet();
	virtual ~Bullet();
	virtual bool init();
	virtual void update(float dt);
	virtual void hurt();
	virtual void destroy();
	virtual CCRect collideRect();
	virtual bool isActive();

	void removeExplode(CCNode *pSender);CREATE_FUNC(Bullet)
	;

private:
	float m_velocityx;
	float m_velocityy;
	int m_power;
	int m_Hp;
	int m_attackMode;
	int m_parentType;
};

#endif /* BULLET_H_ */
