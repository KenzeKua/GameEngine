#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "vector.h"

#include "Sprite.h"
#include "Color.h"

class GameObject
{
protected:
    Sprite* m_sprite;

    GLuint m_passedTexture;

    float m_posX;
    float m_posY;

    float m_rotationDir;
    float m_rotSpeed;

    bool m_originalScale;
    float m_scaleX;
    float m_scaleY;

    Color m_color;
    BlendingMode m_blend;

public:
    GameObject();
    GameObject(Sprite* sprite);
    ~GameObject();

    float m_rotationInc;

    //! Returns the color of GameObject
    Color getColor();

    //! Sets the texture of the GameObject
    void setTexture(GLuint texture);
    //! Sets position of GameObject on the X and Y axes
    void setPosition(float x, float y);
    //! Sets rotation direction and rotation speed of GameObject
    void setRotation(float rotation, float speed);
    //! Sets scale of GameObject using X and Y axes. Set originalSize to true to follow the size of the texture loaded.
    void setScale(bool originalSize, float x, float y);
    //! Sets color of GameObject
    void setColor(Color color);

    //! Adds to current position of GameObject. Used to align with EmitterShapes
    void addPosition(float x, float y);

    //void GeteXxx(); ?

    void update(float deltaTime);
    void draw(BlendingMode blendMode);
};

#endif