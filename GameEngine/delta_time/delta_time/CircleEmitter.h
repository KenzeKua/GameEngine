#ifndef CIRCLE_EMITTER_H
#define CIRCLE_EMITTER_H

#include "EmitterShape.h"

class CircleEmitter : public EmitterShape
{
private:
	float m_radius;

public:
	CircleEmitter();
	~CircleEmitter();

	void getParticleEmissionPos(ParticleObject* particle);

	//! Sets the radius of the CircleEmitter
	void setCircleRadius(float radius);
};

#endif // !CIRCLE_EMITTER_H