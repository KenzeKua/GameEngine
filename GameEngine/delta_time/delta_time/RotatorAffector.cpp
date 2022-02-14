#include "RotatorAffector.h"

RotatorAffector::RotatorAffector()
{
	std::cout << "Constructed RotatorAffector" << std::endl;

	m_rotationDir = 1.0;
	m_rotationSpeed = 1.0;
}
RotatorAffector::~RotatorAffector()
{
	std::cout << "Destructed RotatorAffector" << std::endl;
}

void RotatorAffector::affectParticleUpdate(ParticleObject* particle, float deltaTime)
{
	particle->setRotation(m_rotationDir, m_rotationSpeed);
}

void RotatorAffector::setRotator(float rotationDirection, float rotationSpeed)
{
	m_rotationDir = rotationDirection;
	m_rotationSpeed = rotationSpeed;
}