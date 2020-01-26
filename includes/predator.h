#ifndef PREDATOR_H
#define PREDATOR_H
#include "cell.h"

void update_predator(std::vector<std::vector<Cell>>& world, int x, int y, int zoom, int predator_time_no_eat_max, int predator_nb_eat_kid, int number_preys);
void move_predator(std::vector<std::vector<Cell>>& world, int x, int y, int zoom);
void eat_prey(std::vector<std::vector<Cell>>& world, int x, int y, int zoom);
void predator_make_kid(std::vector<std::vector<Cell>>& world, int x, int y, int zoom);

#endif