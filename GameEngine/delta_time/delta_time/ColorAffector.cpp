#include "ColorAffector.h"

ColorAffector::ColorAffector()
{
	std::cout << "Constructed ColorAffector" << std::endl;

	m_startColor = Color::WHITE;
	m_endColor = Color::RED;
}
ColorAffector::~ColorAffector() 
{ 
	std::cout << "Destructed ColorAffector" << std::endl;
}

void ColorAffector::affectParticleUpdate(ParticleObject* particle, float deltaTime)
{
	float t = particle->getLife() / particle->getMaxLife();

	m_updatedColor.r = lerp(m_startColor.r, m_endColor.r, t);
	m_updatedColor.g = lerp(m_startColor.g, m_endColor.g, t);
	m_updatedColor.b = lerp(m_startColor.b, m_endColor.b, t);
	m_updatedColor.a = lerp(m_startColor.a, m_endColor.a, t);

	particle->setColor(m_updatedColor);
}

void ColorAffector::setFadeColor(Color startColor, Color endColor)
{
	m_startColor = startColor;
	m_endColor = endColor;
}