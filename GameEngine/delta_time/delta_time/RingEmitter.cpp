#include "RingEmitter.h"

RingEmitter::RingEmitter()
{
	std::cout << "Constructed RingEmitter" << std::endl;

	m_outerRadius = 1.0;
	m_innerRadius = 0.5;
}
RingEmitter::~RingEmitter()
{
	std::cout << "Destructed RingEmitter" << std::endl;
}

void RingEmitter::getParticleEmissionPos(ParticleObject* particle)
{
	// Ring without using PI
	/*float m_randomX = 0.0;
	float m_randomY = randomFloat(-1, 1);
	float m_angle = asin(m_randomY);
	float m_convertedX = cos(m_angle);

	// Small circle
	if (abs(m_randomY) < m_innerRadius)
	{
		float smallY = m_randomY / m_innerRadius;
		float smallAngle = asin(smallY);
		float smallConvertX = cos(smallAngle);
		smallConvertX = smallConvertX * m_innerRadius;

		float temp = rand() % 2;
		if (temp == 0)
		{
			m_randomX = randomFloat(-m_convertedX, -smallConvertX);
		}
		else if (temp == 1)
		{
			m_randomX = randomFloat(smallConvertX, m_convertedX);
		}
	}
	else
	{
		m_randomX = randomFloat(-m_convertedX, m_convertedX);
	}*/

	float randomAngle = (randomFloat(0, 360)) * M_PI / 180;
	float randomRadius = randomFloat(m_innerRadius, m_outerRadius);

	particle->addPosition(cos(randomAngle) * randomRadius, sin(randomAngle) * randomRadius);
}

void RingEmitter::setRingRadius(float outerRadius, float innerRadius)
{
	m_outerRadius = outerRadius;
	m_innerRadius = innerRadius;
}