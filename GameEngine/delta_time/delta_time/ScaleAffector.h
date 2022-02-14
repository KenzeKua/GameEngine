#ifndef SCALE_AFFECTOR_H
#define SCALE_AFFECETOR_H

#include "ParticleAffector.h"

class ScaleAffector : public ParticleAffector
{
private:
	float m_startScaleX;
	float m_startScaleY;

	float m_endScaleX;
	float m_endScaleY;

	float m_updateScaleX;
	float m_updateScaleY;

public:
	ScaleAffector();
	~ScaleAffector();

	void affectParticleUpdate(ParticleObject* particle, float deltaTime);

	//! Set scale sizes from start to end. X and Y can be scaled separately.
	void setScaleSizes(float startScaleX, float startScaleY, float endScaleX, float endScaleY);
};

#endif // !SCALE_AFFECTOR_H
