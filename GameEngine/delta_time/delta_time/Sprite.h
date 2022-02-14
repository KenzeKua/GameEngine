#ifndef SPRITE_H
#define SPRITE_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "stdlib.h"
#include "bitmap.h"

#define TEXTURE_COUNT 100

enum BlendingMode
{
	NORMAL,
	ADDITIVE,
	ALPHA, 
	MULTIPLY
};

class Sprite {

private:
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_defaultTexture; // Default texture

public:
	GLuint m_textureID[TEXTURE_COUNT];

	Sprite();
	Sprite(const std::string& file);
	~Sprite();

	void loadTexture(const char* path, GLuint textureID);
	void init();
	void draw(bool originalSize, float width, float height, float x, float y, float rotationAngle, GLuint texture);

	/*
	void draw(float width, float height, float x, flot y, float rotation = 0.0 
			  float scaleX = 1.0f, float scaleY = 1.0f,
			  const Color& color = Color::WHITE,
			  BlendingMode blend = Alpha);
	*/
};

#endif
