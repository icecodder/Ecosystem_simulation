#ifndef CELL_H
#define CELL_H
#include "color.h"
#include <vector>
#include <random>

enum Type { empty, plant, prey, predator };

class Cell
{

public:

	Type type;
	bool done;
	int nb_eat;
	int time_no_eat;
	Color color;

	Cell();
	Cell(const Cell& cell);
	Cell(Type type);

	void operator=(const Cell& cell);
};

void initialize_world(std::vector<std::vector<Cell>>& world, int world_width, int world_height, int nb_plants, int nb_preys, int nb_predators, int zoom);
void grow_plant(std::vector<std::vector<Cell>>& world, int x, int y, int growth_rate, int zoom);
void update_world(std::vector<std::vector<Cell>>& world);
std::vector<int> random_order_4();

#endif