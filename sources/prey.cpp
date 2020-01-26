#include "display.h"
#include "prey.h"



// Met à jour l'état d'une proie

void update_prey(std::vector<std::vector<Cell>>& world, int x, int y, int zoom, int prey_time_no_eat_max, int prey_nb_eat_kid, int number_plants)
{
	world[x][y].done = true;

	if (world[x][y].time_no_eat >= prey_time_no_eat_max)
	{
		world[x][y] = Cell();
		show_cell(x, y, empty, zoom);
		return;
	}

	if (world[x][y].nb_eat >= prey_nb_eat_kid)
	{
		prey_make_kid(world, x, y, zoom);
		world[x][y].nb_eat = 0;
		return;
	}

	if ((x > 0 and world[x - 1][y].type == plant) or (y > 0 and world[x][y - 1].type == plant) or (y < world.front().size() - 1 and world[x][y + 1].type == plant) or (x < world.size() - 1 and world[x + 1][y].type == plant))
	{
		world[x][y].time_no_eat = 0;
		world[x][y].nb_eat++;
		eat_plant(world, x, y, zoom);
	}

	else if (number_plants > 0)
	{
		world[x][y].time_no_eat++;
		move_prey(world, x, y, zoom);
	}

	else
		world[x][y].time_no_eat++;
}



// Fais bouger une proie vers la plante la plus proche

void move_prey(std::vector<std::vector<Cell>>& world, int x, int y, int zoom)
{
	int max_size;
	int j;
	bool random_1 = rand() % 2;
	bool random_2 = rand() % 2;

	if (world.front().size() > world.size())
		max_size = world.front().size();

	else
		max_size = world.size();

	for (int size = 1; size < max_size; size++)
	{
		if (random_2)
		{
			for (int i = x - (size - random_1); i <= x + (size - random_1); i++)
			{
				j = y - size;

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y > 0 and world[i][j].type == plant and world[x][y - 1].type == empty)
				{
					world[x][y - 1] = world[x][y];
					show_cell(x, y - 1, prey, zoom);

					world[x][y] = Cell();
					show_cell(x, y, empty, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x - size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x > 0 and world[j][i].type == plant and world[x - 1][y].type == empty)
				{
					world[x - 1][y] = world[x][y];
					show_cell(x - 1, y, prey, zoom);

					world[x][y] = Cell();
					show_cell(x, y, empty, zoom);

					return;
				}
			}

			for (int i = x - (size - random_1); i <= x + (size - random_1); i++)
			{
				j = y + size;

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y < world.front().size() - 1 and world[i][j].type == plant and world[x][y + 1].type == empty)
				{
					world[x][y + 1] = world[x][y];
					show_cell(x, y + 1, prey, zoom);

					world[x][y] = Cell();
					show_cell(x, y, empty, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x + size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x < world.size() - 1 and world[j][i].type == plant and world[x + 1][y].type == empty)
				{
					world[x + 1][y] = world[x][y];
					show_cell(x + 1, y, prey, zoom);

					world[x][y] = Cell();
					show_cell(x, y, empty, zoom);

					return;
				}
			}
		}

		else
		{
			for (int i = x - (size - random_1); i <= x + (size - random_1); i++)
			{
				j = y + size;

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y < world.front().size() - 1 and world[i][j].type == plant and world[x][y + 1].type == empty)
				{
					world[x][y + 1] = world[x][y];
					show_cell(x, y + 1, prey, zoom);

					world[x][y] = Cell();
					show_cell(x, y, empty, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x + size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x < world.size() - 1 and world[j][i].type == plant and world[x + 1][y].type == empty)
				{
					world[x + 1][y] = world[x][y];
					show_cell(x + 1, y, prey, zoom);

					world[x][y] = Cell();
					show_cell(x, y, empty, zoom);

					return;
				}
			}

			for (int i = x - (size - random_1); i <= x + (size - random_1); i++)
			{
				j = y - size;

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y > 0 and world[i][j].type == plant and world[x][y - 1].type == empty)
				{
					world[x][y - 1] = world[x][y];
					show_cell(x, y - 1, prey, zoom);

					world[x][y] = Cell();
					show_cell(x, y, empty, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x - size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x > 0 and world[j][i].type == plant and world[x - 1][y].type == empty)
				{
					world[x - 1][y] = world[x][y];
					show_cell(x - 1, y, prey, zoom);

					world[x][y] = Cell();
					show_cell(x, y, empty, zoom);

					return;
				}
			}
		}
	}
}



// Fais manger une plante à une proie

void eat_plant(std::vector<std::vector<Cell>>& world, int x, int y, int zoom)
{
	std::vector<int> order = random_order_4();

	for (int r = 0; r < 4; r++)
	{
		switch (order[r])
		{

		case 0:

			if (x > 0 and world[x - 1][y].type == plant)
			{
				world[x - 1][y] = Cell();
				show_cell(x - 1, y, empty, zoom);

				return;
			}

			break;

		case 1:

			if (y > 0 and world[x][y - 1].type == plant)
			{
				world[x][y - 1] = Cell();
				show_cell(x, y - 1, empty, zoom);

				return;
			}

			break;

		case 2:

			if (y < world.front().size() - 1 and world[x][y + 1].type == plant)
			{
				world[x][y + 1] = Cell();
				show_cell(x, y + 1, empty, zoom);

				return;
			}

			break;

		case 3:

			if (x < world.size() - 1 and world[x + 1][y].type == plant)
			{
				world[x + 1][y] = Cell();
				show_cell(x + 1, y, empty, zoom);

				return;
			}

			break;
		}
	}
}



// Crée une nouvelle proie à côté d'une autre

void prey_make_kid(std::vector<std::vector<Cell>>& world, int x, int y, int zoom)
{
	int max_size;
	int j;
	bool random_1 = rand() % 2;
	bool random_2 = rand() % 2;

	if (world.front().size() > world.size())
		max_size = world.front().size();

	else
		max_size = world.size();

	for (int size = 1; size < max_size; size++)
	{
		if (random_2)
		{
			for (int i = x - (size - random_1); i <= x + (size - random_1); i++)
			{
				j = y - size;

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y > 0 and world[i][j].type == empty)
				{
					world[i][j] = Cell(prey);
					show_cell(i, j, prey, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x - size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x > 0 and world[j][i].type == empty)
				{
					world[j][i] = Cell(prey);
					show_cell(j, i, prey, zoom);

					return;
				}
			}

			for (int i = x - (size - random_1); i <= x + (size - random_1); i++)
			{
				j = y + size;

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y < world.front().size() - 1 and world[i][j].type == empty)
				{
					world[i][j] = Cell(prey);
					show_cell(i, j, prey, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x + size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x < world.size() - 1 and world[j][i].type == empty)
				{
					world[j][i] = Cell(prey);
					show_cell(j, i, prey, zoom);

					return;
				}
			}
		}

		else
		{
			for (int i = x - (size - random_1); i <= x + (size - random_1); i++)
			{
				j = y + size;

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y < world.front().size() - 1 and world[i][j].type == empty)
				{
					world[i][j] = Cell(prey);
					show_cell(i, j, prey, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x + size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x < world.size() - 1 and world[j][i].type == empty)
				{
					world[j][i] = Cell(prey);
					show_cell(j, i, prey, zoom);

					return;
				}
			}

			for (int i = x - (size - random_1); i <= x + (size - random_1); i++)
			{
				j = y - size;

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y > 0 and world[i][j].type == empty)
				{
					world[i][j] = Cell(prey);
					show_cell(i, j, prey, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x - size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x > 0 and world[j][i].type == empty)
				{
					world[j][i] = Cell(prey);
					show_cell(j, i, prey, zoom);

					return;
				}
			}
		}
	}
}