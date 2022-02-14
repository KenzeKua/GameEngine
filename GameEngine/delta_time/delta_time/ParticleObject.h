#ifndef PARTICLE_OBJECT_H
#define PARTICLE_OBJECT_H

#include "GameObject.h"

class ParticleObject : public GameObject
{
private:
	float m_life;
	float m_maxLife;
	float m_velocityX;
	float m_velocityY;

public:
	ParticleObject();
	ParticleObject(float life, float x, float y);
	~ParticleObject();

	//! Returns the current life of the ParticleObject.
	float getLife();
	//! Returns the maximum life of the ParticleObject.
	float getMaxLife();

	//! Sets a constant velocity along the X and Y axes.
	void setVelocity(float velocityX, float velocityY);

	//! Adds to the current velocity of the ParticleObject on the X and Y axes.
	void accelerateVelocity(float accelerationX, float accelerationY);

	void update(float elapsedTime);
};

#endif