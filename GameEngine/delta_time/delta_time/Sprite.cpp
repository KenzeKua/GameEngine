#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "stdlib.h"
#include "bitmap.h"

#include "matrix.h"

#include "Sprite.h"

Sprite::Sprite()
{
	m_width = 1;
	m_height = 1;
	m_defaultTexture = 1;
}
Sprite::Sprite(const std::string& file) 
{
	m_defaultTexture = 1;

	glGenTextures(TEXTURE_COUNT, &m_defaultTexture);
	loadTexture(file.c_str(), m_defaultTexture);

	init();
}

Sprite::~Sprite()
{
}

void Sprite::loadTexture(const char* path, GLuint textureID)
{
	CBitmap bitmap(path);

	// Create Linear Filtered Texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // apply texture wrapping along horizontal
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // apply texture wrapping along vertical

	// Old school (minecraft_ filtering
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // near filtering/ (For when texture needs to scale up on screen)
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // far filtering/ (For when texture needs to scale down on screen)

	// Bilinear filtering.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // near filtering. (For when texture needs to scale up on screen)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // far filtering. (For when texture needs to scale down on screen)

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 
				 bitmap.GetWidth(), bitmap.GetHeight(), 
				 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap.GetBits());

	m_width = bitmap.GetWidth();
	m_height = bitmap.GetHeight();
}

void Sprite::init()
{
	glGenTextures(TEXTURE_COUNT, m_textureID);
	loadTexture("../media/glass.bmp", m_textureID[0]);
	loadTexture("../media/rocks.bmp", m_textureID[1]);
	loadTexture("../media/star.bmp", m_textureID[2]);
	loadTexture("../media/explosion.bmp", m_textureID[3]);
}

void Sprite::draw(bool originalSize, float width, float height, float x, float y, float rotationAngle, GLuint texture)
{
	if (originalSize)
	{
		width = m_width;
		height = m_height;
	}

	//glColor3f(1.0f, 1.0f, 1.0f);

	// Start of alternative rotation
	/*glPushMatrix();
	glRotatef(45, 0.0, 0.0, 1.0);*/

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_TRIANGLES);

	// Formula to calculate rotation
	// x1 = (x0 – xc)cos(angle) – (y0 – yc)sin(angle) + xc
	// y1 = (x0 – xc)sin(angle) + (y0 – yc)cos(angle) + yc

	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(x + (((x - (width * 0.5)) - x) * cos(rotationAngle)) - (((y + (height * 0.5)) - y) * sin(rotationAngle)),
			   y + (((x - (width * 0.5)) - x) * sin(rotationAngle)) + (((y + (height * 0.5)) - y) * cos(rotationAngle)));

	glTexCoord2f(0.0f, 0.0f); 
	glVertex2f(x + (((x - (width * 0.5)) - x) * cos(rotationAngle)) - (((y - (height * 0.5)) - y) * sin(rotationAngle)),
			   y + (((x - (width * 0.5)) - x) * sin(rotationAngle)) + (((y - (height * 0.5)) - y) * cos(rotationAngle)));
	
	glTexCoord2f(1.0f, 0.0f); 
	glVertex2f(x + (((x + (width * 0.5)) - x) * cos(rotationAngle)) - (((y - (height * 0.5)) - y) * sin(rotationAngle)),
			   y + (((x + (width * 0.5)) - x) * sin(rotationAngle)) + (((y - (height * 0.5)) - y) * cos(rotationAngle)));

	glTexCoord2f(0.0f, 1.0f); 
	glVertex2f(x + (((x - (width * 0.5)) - x) * cos(rotationAngle)) - (((y + (height * 0.5)) - y) * sin(rotationAngle)),
			   y + (((x - (width * 0.5)) - x) * sin(rotationAngle)) + (((y + (height * 0.5)) - y) * cos(rotationAngle)));
	
	glTexCoord2f(1.0f, 1.0f); 
	glVertex2f(x + (((x + (width * 0.5)) - x) * cos(rotationAngle)) - (((y + (height * 0.5)) - y) * sin(rotationAngle)),
		       y + (((x + (width * 0.5)) - x) * sin(rotationAngle)) + (((y + (height * 0.5)) - y) * cos(rotationAngle)));
	
	glTexCoord2f(1.0f, 0.0f); 
	glVertex2f(x + (((x + (width * 0.5)) - x) * cos(rotationAngle)) - (((y - (height * 0.5)) - y) * sin(rotationAngle)),
			   y + (((x + (width * 0.5)) - x) * sin(rotationAngle)) + (((y - (height * 0.5)) - y) * cos(rotationAngle)));

	glEnd();
	glDisable(GL_TEXTURE_2D);

	// end of alternative rotation
	//glPopMatrix();
}