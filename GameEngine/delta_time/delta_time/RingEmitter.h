#ifndef RING_EMITTER_H
#define RING_EMITTER_H

#include "EmitterShape.h"

class RingEmitter : public EmitterShape
{
private:
	float m_outerRadius;
	float m_innerRadius;

public:
	RingEmitter();
	~RingEmitter();

	void getParticleEmissionPos(ParticleObject* particle);

	//! Sets outer and inner radius of the RingEmitter
	void setRingRadius(float outerRadius, float innerRadius);
};

#endif // !RING_EMITTER_H
