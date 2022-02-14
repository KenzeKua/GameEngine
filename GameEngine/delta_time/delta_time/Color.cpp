#include "Color.h"

Color::Color()
{
	r = 0.0;
	g = 0.0;
	b = 0.0;
	a = 0.0;
}
Color::Color(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Color Color::WHITE = Color(1.0, 1.0, 1.0, 1.0);
Color Color::RED = Color(1.0, 0.0, 0.0, 1.0);
Color Color::GREEN = Color(0.0, 1.0, 0.0, 1.0);
Color Color::BLUE = Color(0.0, 0.0, 1.0, 1.0);
Color Color::YELLOW = Color(1.0, 1.0, 0.0, 1.0);
Color Color::MAGENTA = Color(1.0, 0.0, 1.0, 1.0);
Color Color::CYAN = Color(0.0, 1.0, 1.0, 1.0);