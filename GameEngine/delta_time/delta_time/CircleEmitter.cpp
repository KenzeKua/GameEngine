#include "CircleEmitter.h"

CircleEmitter::CircleEmitter()
{
	std::cout << "Constructed CircleEmitter" << std::endl;

	m_radius = 1.0;
}
CircleEmitter::~CircleEmitter()
{
	std::cout << "Destructed CircleEmitter" << std::endl;
}

void CircleEmitter::getParticleEmissionPos(ParticleObject* particle)
{
	// Circle without using PI
	/*float m_randomY = randomFloat(-1, 1);
	float m_angle = asin(m_randomY);
	float m_convertedX = cos(m_angle);
	float m_randomX = randomFloat(-m_convertedX, m_convertedX);*/

	float randomAngle = (randomFloat(0, 360)) * M_PI / 180;
	float randomRadius = randomFloat(0, m_radius);

	particle->addPosition(cos(randomAngle) * randomRadius, sin(randomAngle) * randomRadius);
}

void CircleEmitter::setCircleRadius(float radius)
{
	m_radius = radius;
}