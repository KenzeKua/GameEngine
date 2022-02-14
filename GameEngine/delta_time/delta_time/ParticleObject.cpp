#include "ParticleObject.h"

ParticleObject::ParticleObject()
{
	m_life = 3.0;
	m_maxLife = 3.0;
	m_posX = 0.0;
	m_posY = 0.0;
	m_velocityX = 0.0;
	m_velocityY = 0.0;
}
ParticleObject::ParticleObject(float life, float x, float y)
{
	m_life = life;
	m_maxLife = life;
	m_posX = x;
	m_posY = y;
	m_velocityX = 0.0;
	m_velocityY = 0.0;
}
ParticleObject::~ParticleObject() { }

float ParticleObject::getLife()
{
	return m_life;
}
float ParticleObject::getMaxLife()
{
	return m_maxLife;
}

void ParticleObject::setVelocity(float velocityX, float velocityY)
{
	m_velocityX = velocityX;
	m_velocityY = velocityY;
}

void ParticleObject::accelerateVelocity(float accelerationX, float accelerationY)
{
	m_velocityX += accelerationX;
	m_velocityY += accelerationY;
}

void ParticleObject::update(float elapsedTime) // elapsedTime is also known as deltaTime
{
	// TODO update the position

	// Acceleration affects velocity
	m_posX += m_velocityX * elapsedTime;
	m_posY += m_velocityY * elapsedTime;

	// Velocity affects position
	this->setPosition(m_posX, m_posY);

	// Decrease the life of particle every update
	m_life -= elapsedTime;
}


// TODO
// ParticleSystem
// List of particle object
// List of particle affectors
// emitterShape (set to null by default, null:point emitter)

// ParticleAffector
// - ColorAffector
// - RotateAffector
// - ...

// EmitterShape
// - CircleEmitter
// -RectangleEmitter
// - ...