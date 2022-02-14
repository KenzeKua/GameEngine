#ifndef BOX_EMITTER_H
#define BOX_EMITTER_H

#include "EmitterShape.h"

class BoxEmitter : public EmitterShape
{
private:
	float m_width;
	float m_height;

	float m_randomPosX;
	float m_randomPosY;

public:
	BoxEmitter();
	~BoxEmitter();

	void getParticleEmissionPos(ParticleObject* particle);

	//! Sets the width and height of the BoxEmitter
	void setBoxSize(float width, float height);
};

#endif // !BOX_EMITTER_H
