#ifndef COLOR_AFFECTOR_H
#define COLOR_AFFECTOR_H

#include "ParticleAffector.h"
#include "Color.h"

class ColorAffector : public ParticleAffector
{
private:
	Color m_startColor;
	Color m_endColor;
	Color m_updatedColor;

public:
	ColorAffector();
	~ColorAffector();

	void affectParticleUpdate(ParticleObject* particle, float deltaTime);

	//! Sets the starting color and the end color to fade into
	void setFadeColor(Color startColor, Color endColor);
};

#endif