#include "vector.h"
#include "matrix.h"

#include "GameObject.h"
#include "Sprite.h"

GameObject::GameObject()
{
	// Killed because of performance reason, can still be used if want to spawn permanent object
	//m_sprite = new Sprite("../media/glass.bmp");
	//m_passedTexture = m_sprite->m_textureID[0];

	m_posX = 1280.0 * 0.5;
	m_posY = 720.0 * 0.5;

	m_rotationDir = 1.0;
	m_rotSpeed = 0.0;
	m_rotationInc = 0.0;

	m_originalScale = false;
	m_scaleX = 1.0;
	m_scaleY = 1.0;

	m_color = Color::WHITE;
	m_blend = NORMAL;
}
GameObject::GameObject(Sprite* sprite)
{
	m_sprite = sprite;

	m_posX = 1280.0 * 0.5;
	m_posY = 720.0 * 0.5;

	m_rotationDir = 1.0;
	m_rotSpeed = 0.0;
	m_rotationInc = 0.0;

	m_originalScale = false;
	m_scaleX = 1.0;
	m_scaleY = 1.0;

	m_color = Color::WHITE;
	m_blend = NORMAL;
}

GameObject::~GameObject()
{
}

Color GameObject::getColor()
{
	return m_color;
}

void GameObject::setTexture(GLuint texture)
{
	m_passedTexture = texture;
}
void GameObject::setPosition(float x, float y)
{
	m_posX = x;
	m_posY = y;
}
void GameObject::setRotation(float rotation, float speed)
{
	m_rotationDir = rotation;
	m_rotSpeed = speed;
}
void GameObject::setScale(bool originalSize, float x, float y)
{
	m_originalScale = originalSize;

	m_scaleX = x;
	m_scaleY = y;
}
void GameObject::setColor(Color color)
{
	m_color = color;
}

void GameObject::addPosition(float x, float y)
{
	m_posX += x;
	m_posY += y;
}

void GameObject::update(float deltaTime)
{
}

void GameObject::draw(BlendingMode blendMode)
{
	m_rotationInc += m_rotSpeed;
	m_blend = blendMode;

	switch (m_blend)
	{
	case NORMAL:
		break;

	case ADDITIVE: 
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		break;

	case ALPHA: 
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		break;

	case MULTIPLY: 
		glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR);
		break;

	default: 
		glDisable(GL_BLEND);
		break;
	}

	glColor4f(m_color.r, m_color.g, m_color.b, m_color.a);

	Matrix translateMatrix = Matrix::makeTranslationMatrix(m_posX, m_posY, 0.0);
	Matrix scaleMatrix = Matrix::makeScaleMatrix(m_scaleX, m_scaleY, 1.0);
	Matrix rotationMatrix = Matrix::makeRotateMatrix(m_rotationInc, Vector(0.0, 0.0, m_rotationDir));
	Matrix finalMatrix = translateMatrix * rotationMatrix * scaleMatrix;
	glLoadMatrixf((GLfloat*)finalMatrix.mVal);

	m_sprite->draw(m_originalScale, 100, 100, 0, 0, 0, m_passedTexture);

	glDisable(GL_BLEND);

	// Test area
	/*Matrix translateMatrix1 = Matrix::makeTranslationMatrix(positionX + 50, positionY + 50, 0.0);
	Matrix scaleMatrix1 = Matrix::makeScaleMatrix(1.0, 1.0, 1.0);
	Matrix rotationMatrix1 = Matrix::makeRotateMatrix(rotationInc, Vector(0.0, 0.0, -1.0));
	Matrix finalMatrix1 = translateMatrix1 * rotationMatrix1 * scaleMatrix1;
	glLoadMatrixf((GLfloat*)finalMatrix1.mVal);

	m_sprite->draw(false, 100, 100, 0.0, 0.0, 0, m_sprite->mTextureID[1]);*/
}