#ifndef COLOR_H
#define COLOR_H

#define BACKGROUND Color(5, 5, 40) // Couleur du fond

class Color
{

public :

	int red;
	int green;
	int blue;

	Color();
	Color(const Color& color);
	Color(int red, int green, int blue);

	void operator=(const Color& color);
};

#endif