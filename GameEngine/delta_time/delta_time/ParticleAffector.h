#ifndef PARTICLE_AFFECTOR_H
#define PARTICLE_AFFECTOR_H

#include <iostream>

#include "ParticleObject.h"

class ParticleAffector
{
public:
	ParticleAffector();
	virtual ~ParticleAffector(); // Remember parent destructor needs virtual so it will delete properly after creating an object

	//! Updates the ParticleObjects based on the type of affectors.
	virtual void affectParticleUpdate(ParticleObject* particle, float deltaTime) = 0;

	//! To lerp from a starting value to an end value using parameter t.
	float lerp(float start, float end, float t);
};

#endif