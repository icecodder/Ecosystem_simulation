#include "color.h"

Color::Color()
{
	red = 0;
	green = 0;
	blue = 0;
}

Color::Color(const Color& color)
{
	red = color.red;
	green = color.green;
	blue = color.blue;
}

Color::Color(int red, int green, int blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

void Color::operator=(const Color& color)
{
	red = color.red;
	green = color.green;
	blue = color.blue;
}