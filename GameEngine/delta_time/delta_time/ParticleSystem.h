#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include <list>

#include "vector.h"

#include "Sprite.h"
#include "ParticleObject.h"

#include "ParticleAffector.h"
#include "GravityAffector.h"
#include "ColorAffector.h"
#include "ScaleAffector.h"
#include "RotatorAffector.h"

#include "EmitterShape.h"
#include "CircleEmitter.h"
#include "RingEmitter.h"
#include "BoxEmitter.h"

class ParticleSystem
{
private:
	std::list <ParticleObject*> m_particleList;
	std::list <ParticleAffector*> m_affectorList;

	float emissionTimer;
	float emissionRate;
	int emissionCount;
	
	//Vector m_position;
	float m_positionX;
	float m_positionY;
	Sprite* m_sprite;
	ParticleObject* m_particleObject;

public:
	static GravityAffector* gravityAffector;
	static ColorAffector* colorAffector;
	static ScaleAffector* scaleAffector;
	static RotatorAffector* rotatorAffector;

	static bool toggleGravity;
	static bool toggleColor;
	static bool toggleScale;
	static bool toggleRotator;
	static bool velocityTrigger;

	static CircleEmitter* circleEmitter;
	static RingEmitter* ringEmitter;
	static BoxEmitter* boxEmitter;

	static ParticleAffector* particleAffector;
	static EmitterShape* emitterShape;

	ParticleSystem();
	//ParticleSystem(const Vector& pos, Sprite* sprite);
	ParticleSystem(float positionX, float positionY, Sprite* sprite);
	~ParticleSystem();

	//! Initialises all ParticleAffectors
	void initAffectors();
	//! Initialises all EmitterShape
	void initEmitters();

	void update(float deltaTime);

	void draw(void);
};

#endif