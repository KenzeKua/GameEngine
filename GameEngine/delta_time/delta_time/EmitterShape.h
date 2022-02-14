#ifndef EMITTER_SHAPE_H
#define EMITTER_SHAPE_H

#include <iostream>
#include "vector.h"
#include "matrix.h"

#include "ParticleObject.h"

class EmitterShape
{
protected:
	float randomFloat(float minValue, float maxValue);

public:
	EmitterShape();
	virtual ~EmitterShape();

	// This method is called by particle system
	//virtual Vector getParticleEmissionPos(Vector* particleSystemPos) = 0;
	//! Updates the particles location based on the EmitterShapes
	virtual void getParticleEmissionPos(ParticleObject* particle) = 0;
};

#endif