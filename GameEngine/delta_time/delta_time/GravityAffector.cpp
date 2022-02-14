#include "GravityAffector.h"

GravityAffector::GravityAffector() 
{ 
	std::cout << "Constructed GravityAffector" << std::endl;

	m_gravityStrength = -49;
}
GravityAffector::~GravityAffector() 
{
	std::cout << "Destructed GravityAffector" << std::endl;
}

void GravityAffector::affectParticleUpdate(ParticleObject* particle, float deltaTime)
{
	float t = particle->getLife() / particle->getMaxLife();

	lerp(0, m_gravityStrength, t);

	particle->accelerateVelocity(0, m_gravityStrength);
}

void GravityAffector::setGravity(float gravityStrength)
{
	m_gravityStrength = gravityStrength;
}