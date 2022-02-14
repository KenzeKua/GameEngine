#ifndef COLOR_H
#define COLOR_H

struct Color
{
public:
	float r;
	float g;
	float b;
	float a;

	Color();
	Color(float r, float g, float b, float a);

	static Color WHITE;
	static Color RED;
	static Color GREEN;
	static Color BLUE;
	static Color YELLOW;
	static Color MAGENTA;
	static Color CYAN;
};

#endif // !COLOR_H