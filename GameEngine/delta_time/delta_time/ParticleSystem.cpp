#include "ParticleSystem.h"

GravityAffector* ParticleSystem::gravityAffector;
ColorAffector* ParticleSystem::colorAffector;
ScaleAffector* ParticleSystem::scaleAffector;
RotatorAffector* ParticleSystem::rotatorAffector;

CircleEmitter* ParticleSystem::circleEmitter;
RingEmitter* ParticleSystem::ringEmitter;
BoxEmitter* ParticleSystem::boxEmitter;

//ParticleAffector* ParticleSystem::particleAffector;
EmitterShape* ParticleSystem::emitterShape;

bool ParticleSystem::toggleGravity;
bool ParticleSystem::toggleColor;
bool ParticleSystem::toggleScale;
bool ParticleSystem::toggleRotator;
bool ParticleSystem::velocityTrigger;

ParticleSystem::ParticleSystem()
{
	emissionRate = 0.01f; // In this example, 1 particle/second
	emissionCount = 0.0f;
	m_positionX = 0.0;
	m_positionY = 0.0;

	m_sprite = new Sprite("../media/glass.bmp");
	m_particleObject = new ParticleObject(5.0, 530.0, 250.0);
	m_particleObject->setTexture(m_sprite->m_textureID[1]);

	initAffectors();
	initEmitters();

	//particleAffector = gravityAffector;
	emitterShape = ringEmitter;

	toggleGravity = true;
	toggleColor = true;
	toggleScale = true;
	toggleRotator = true;
	velocityTrigger = true;
}
ParticleSystem::ParticleSystem(float positionX, float positionY, Sprite* sprite)
{
	emissionRate = 0.05f;
	emissionCount = 0.0f;
	//m_position = pos;
	m_positionX = positionX;
	m_positionY = positionY;
	m_sprite = sprite;

	initAffectors();
	initEmitters();

	//particleAffector = gravityAffector;
	emitterShape = boxEmitter;

	toggleGravity = true;
	toggleColor = true;
	toggleScale = true;
	toggleRotator = true;
	velocityTrigger = true;
}
ParticleSystem::~ParticleSystem() 
{ 
	std::cout << "Destructed ParticleSystem" << std::endl;
}

void ParticleSystem::initAffectors()
{
	gravityAffector = new GravityAffector();
	gravityAffector->setGravity(-9.8);

	colorAffector = new ColorAffector();
	colorAffector->setFadeColor(Color::MAGENTA, Color::CYAN); // Color affector overrides original color

	scaleAffector = new ScaleAffector();
	scaleAffector->setScaleSizes(0.1, 0.1, 0.4, 0.4);

	rotatorAffector = new RotatorAffector();
	rotatorAffector->setRotator(-1.0, 1.0);
}

void ParticleSystem::initEmitters()
{
	circleEmitter = new CircleEmitter();
	circleEmitter->setCircleRadius(50.0);

	ringEmitter = new RingEmitter();
	ringEmitter->setRingRadius(100.0, 70.0);

	boxEmitter = new BoxEmitter();
	boxEmitter->setBoxSize(100, 100);
}

void ParticleSystem::update(float deltaTime)
{
	emissionTimer += deltaTime;
	// Check if it's needed to create a new particle
	if (emissionTimer > emissionRate)
	{
		emissionTimer = 0.0f;

		ParticleObject* newParticle = new ParticleObject(5.0, 640.0, 360.0);
		newParticle->setScale(false, 0.1, 0.1);
		newParticle->setTexture(m_sprite->m_textureID[2]);

		if (velocityTrigger)
		{
			newParticle->setVelocity(0, 200);
		}

		emitterShape->getParticleEmissionPos(newParticle);

		m_particleList.push_back(newParticle);
	}

	// Update the particles movement
	std::list<ParticleObject*>::iterator iter = m_particleList.begin();
	while (iter != m_particleList.end())
	{
		ParticleObject* tempObj = *iter;
		if (tempObj->getLife() <= 0)
		{
			delete tempObj;
			iter = m_particleList.erase(iter);
		}
		else
		{
			// Update the particle object
			tempObj->update(deltaTime);

			// Update object with affectors
			if (toggleGravity)
			{
				gravityAffector->affectParticleUpdate(tempObj, deltaTime);
			}
			if (toggleColor)
			{
				colorAffector->affectParticleUpdate(tempObj, deltaTime);
			}
			if (toggleScale)
			{
				scaleAffector->affectParticleUpdate(tempObj, deltaTime);
			}
			if (toggleRotator)
			{
				rotatorAffector->affectParticleUpdate(tempObj, deltaTime);
			}

			iter++;
		}
	}

	// Test single object
	//m_particleObject->update(deltaTime);
}

void ParticleSystem::draw(void)
{
	std::list <ParticleObject*>::iterator iter = m_particleList.begin();
	while (iter != m_particleList.end())
	{
		ParticleObject* tempObj = *iter;
		tempObj->draw(MULTIPLY);
		iter++;
	}

	// Test single object
	//m_particleObject->draw(NORMAL);
}