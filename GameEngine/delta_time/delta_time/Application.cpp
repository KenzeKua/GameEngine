#include <GLFW/glfw3.h>
#include <iostream>
#include "stdlib.h"
#include <Windows.h>

#include "matrix.h"

#include "Application.h"
#include "GameObject.h"

Application::Application()
{
	m_referSprite = new Sprite("../media/glass.bmp");

	gameObject = GameObject(m_referSprite);
	gameObject1 = GameObject(m_referSprite);
}
Application::~Application()
{
}

void Application::start()
{
	std::cout << "Application start" << std::endl;
}

void Application::update(float deltaTime, float fps) 
{
	std::cout << "deltaTime in update: " << deltaTime << "\tFPS: " << fps << std::endl;
}

void Application::draw(float deltaTime)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gameObject.setTexture(m_referSprite->m_textureID[1]);
	gameObject.setPosition(340.0, 360.0);
	gameObject.setRotation(1.0, 1.0);
	gameObject.setScale(false, 1.0, 1.0);
	gameObject.setColor(Color::BLUE);
	gameObject.draw(ADDITIVE);

	gameObject1.setTexture(m_referSprite->m_textureID[0]);
	gameObject1.setPosition(940.0, 360.0);
	gameObject1.setRotation(-1.0, 3.0);
	gameObject1.setScale(false, 1.0, 1.0);
	gameObject1.setColor(Color::GREEN);
	gameObject1.draw(ADDITIVE);

	particleSystem.update(deltaTime);
	particleSystem.draw();
}