#include "ParticleAffector.h"

ParticleAffector::ParticleAffector()
{
	std::cout << "Constructed ParticleAffector parent" << std::endl;
}
ParticleAffector::~ParticleAffector()
{
	std::cout << "Destructed ParticleAffector parent" << std::endl;
}

float ParticleAffector::lerp(float start, float end, float t)
{
	// Original formula: start * (1.0f - t) + end * t
	return start * t + end * (1.0f - t);
}