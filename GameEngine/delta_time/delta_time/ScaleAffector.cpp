#include "ScaleAffector.h"

ScaleAffector::ScaleAffector()
{
	std::cout << "Constructed ScaleAffector" << std::endl;

	m_startScaleX = 100.0;
	m_startScaleY = 100.0;

	m_endScaleX = 200.0;
	m_endScaleY = 200.0;
}
ScaleAffector::~ScaleAffector() 
{
	std::cout << "Destructed ScaleAffector" << std::endl;
}

void ScaleAffector::affectParticleUpdate(ParticleObject* particle, float deltaTime)
{
	float t = particle->getLife() / particle->getMaxLife();

	m_updateScaleX = lerp(m_startScaleX, m_endScaleX, t);
	m_updateScaleY = lerp(m_startScaleY, m_endScaleY, t);

	particle->setScale(false, m_updateScaleX, m_updateScaleY);
}

void ScaleAffector::setScaleSizes(float startScaleX, float startScaleY, float endScaleX, float endScaleY)
{
	m_startScaleX = startScaleX;
	m_startScaleY = startScaleY;

	m_endScaleX = endScaleX;
	m_endScaleY = endScaleY;
}