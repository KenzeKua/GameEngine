#ifndef ROTATOR_AFFECTOR_H
#define ROTATOR_AFFECTOR_H

#include "ParticleAffector.h"

class RotatorAffector : public ParticleAffector
{
private:
	float m_rotationDir;
	float m_rotationSpeed;

public:
	RotatorAffector();
	~RotatorAffector();

	void affectParticleUpdate(ParticleObject* particle, float deltaTime);

	//! Set rotation direction and rotation speed of ParticleObject. 1 for clockwise, -1 for anti-clockwise.
	void setRotator(float rotationDirection, float rotationSpeed);
};

#endif // !ROTATOR_AFFECTOR_H
