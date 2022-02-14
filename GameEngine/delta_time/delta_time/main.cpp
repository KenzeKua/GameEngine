#include <GLFW/glfw3.h>
#include <Windows.h>
#include <GL/GLU.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>

//#include <chrono>

#include "matrix.h"

#include "Application.h"

const int RESOLUTION_X = 1280;
const int RESOLUTION_Y = 720;

void onWindowResized(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Ue orthod 2D view
	gluOrtho2D(0, width, 0, height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Change affector
	if (key == GLFW_KEY_Q && action == GLFW_PRESS)
	{
		//ParticleSystem::particleAffector = ParticleSystem::gravityAffector;
		if (ParticleSystem::toggleGravity) ParticleSystem::toggleGravity = false;
		else ParticleSystem::toggleGravity = true;
	}
	if (key == GLFW_KEY_W && action == GLFW_PRESS)
	{
		//ParticleSystem::particleAffector = ParticleSystem::colorAffector;
		if (ParticleSystem::toggleColor) ParticleSystem::toggleColor = false;
		else ParticleSystem::toggleColor = true;
	}
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
	{
		//ParticleSystem::particleAffector = ParticleSystem::scaleAffector;
		if (ParticleSystem::toggleScale) ParticleSystem::toggleScale = false;
		else ParticleSystem::toggleScale = true;
	}
	if (key == GLFW_KEY_R && action == GLFW_PRESS)
	{
		//ParticleSystem::particleAffector = ParticleSystem::rotatorAffector;
		if (ParticleSystem::toggleRotator) ParticleSystem::toggleRotator = false;
		else ParticleSystem::toggleRotator = true;
	}

	// Set velocity
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
	{
		if (ParticleSystem::velocityTrigger) ParticleSystem::velocityTrigger = false;
		else ParticleSystem::velocityTrigger = true;
	}

	// Change emitter
	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		ParticleSystem::emitterShape = ParticleSystem::circleEmitter;
	}
	if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
		ParticleSystem::emitterShape = ParticleSystem::ringEmitter;
	}
	if (key == GLFW_KEY_D && action == GLFW_PRESS)
	{
		ParticleSystem::emitterShape = ParticleSystem::boxEmitter;
	}
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(RESOLUTION_X, RESOLUTION_Y, "Delta Time", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetWindowSizeCallback(window, onWindowResized);

	glfwSetKeyCallback(window, key_callback);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	onWindowResized(window, RESOLUTION_X, RESOLUTION_Y);

	glfwSwapInterval(0); //enable/disable vsync

	Application app;
	app.start();

	double maxFPS = 60.0;
	double minDeltaTime = 1.0 / maxFPS;

	double deltaTime = 0.0;
	double fps = 0.0;

	double currentTime = 0.0;
	double prevTime = glfwGetTime();
	double printerTime = glfwGetTime();

	//game loop
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		currentTime = glfwGetTime();
		deltaTime = currentTime - prevTime;
		/*
		if (currentTime - printerTime > 1.0)
		{
			update(deltaTime, fps);
			printerTime = currentTime;
		}
		*/

		// My sleeper
		// empty

		// ==================================
		// Lecturer's Sleeper
		int minSleepTimeTH = 10;
		// Conservatively asking the system to sleep
		int sleepTime = (minDeltaTime - deltaTime) * 1000 - minSleepTimeTH;
		if (sleepTime >= minSleepTimeTH)
		{
			Sleep(sleepTime);
		}
		// Sleep time is not precise, use loop to "waste" extra cpu cycles
		while (deltaTime < minDeltaTime)
		{
			deltaTime = glfwGetTime() - prevTime;
		}
		// ==================================

		/// Lecturer's
		prevTime = glfwGetTime();
		fps = 1.0 / deltaTime;

		char str[32];
		sprintf_s(str, "%f, %f", fps, (float)deltaTime);
		glfwSetWindowTitle(window, str);

		app.draw(deltaTime);
		//app.update(deltaTime, fps);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}