#include "EmitterShape.h"

EmitterShape::EmitterShape()
{
	std::cout << "Constructed EmitterShape parent" << std::endl;
}
EmitterShape::~EmitterShape()
{
	std::cout << "Destructed EmitterShape parent" << std::endl;
}

float EmitterShape::randomFloat(float minValue, float maxValue)
{
	return ((float)rand() / (float)RAND_MAX) * (maxValue - minValue) + minValue;
}