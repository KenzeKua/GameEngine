#ifndef GRAVITY_AFFECTOR_H
#define GRAVITY_AFFECTOR_H

#include "ParticleAffector.h"

class GravityAffector : public ParticleAffector
{
private:
	float m_gravityStrength;

public:
	GravityAffector();
	~GravityAffector();

	void affectParticleUpdate(ParticleObject* particle, float deltaTime);

	void setGravity(float gravityStrength);
};

#endif // !GRAVITY_AFFECTOR_H