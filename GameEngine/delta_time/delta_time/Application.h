#ifndef APPLICATION_H
#define APPLICATION_H

#include "Sprite.h"
#include "GameObject.h"
#include "ParticleObject.h"
#include "ParticleSystem.h"

class Application
{
private:
	// May be obsolete
	Sprite* m_referSprite;

	GameObject gameObject;
	GameObject gameObject1;

	ParticleSystem particleSystem;

public:
	Application();
	~Application();
	
	void start();
	//! Updates the Application. Fill in parameters with deltaTime and fps
	void update(float deltaTime, float fps);
	void draw(float deltaTime);
};

#endif