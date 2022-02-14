#include "BoxEmitter.h"

BoxEmitter::BoxEmitter()
{
	std::cout << "Constructed BoxEmitter" << std::endl;

	m_width = 1.0;
	m_height = 1.0;

	m_randomPosX = 0.0;
	m_randomPosY = 0.0;
}

BoxEmitter::~BoxEmitter()
{
	std::cout << "Destructed BoxEmitter" << std::endl;
}

void BoxEmitter::getParticleEmissionPos(ParticleObject* particle)
{
	m_randomPosX = randomFloat(-(m_width * 0.5), m_width * 0.5);
	m_randomPosY = randomFloat(-(m_height * 0.5), m_height * 0.5);

	particle->addPosition(m_randomPosX, m_randomPosY);
}

void BoxEmitter::setBoxSize(float width, float height)
{
	m_width = width;
	m_height = height;
}