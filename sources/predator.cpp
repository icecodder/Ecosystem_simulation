#include "display.h"
#include "predator.h"



// Met à jour l'état d'un prédateur

void update_predator(std::vector<std::vector<Cell>>& world, int x, int y, int zoom, int predator_time_no_eat_max, int predator_nb_eat_kid, int number_preys)
{
	world[x][y].done = true;

	if (world[x][y].time_no_eat >= predator_time_no_eat_max)
	{
		world[x][y] = Cell();
		show_cell(x, y, empty, zoom);
		return;
	}

	if (world[x][y].nb_eat >= predator_nb_eat_kid)
	{
		predator_make_kid(world, x, y, zoom);
		world[x][y].nb_eat = 0;
	}

	if ((x > 0 and world[x - 1][y].type == prey) or (y > 0 and world[x][y - 1].type == prey) or (y < world.front().size() - 1 and world[x][y + 1].type == prey) or (x < world.size() - 1 and world[x + 1][y].type == prey))
	{
		world[x][y].time_no_eat = 0;
		world[x][y].nb_eat++;
		eat_prey(world, x, y, zoom);
	}

	else if (number_preys > 0)
	{
		world[x][y].time_no_eat++;
		move_predator(world, x, y, zoom);
	}

	else
		world[x][y].time_no_eat++;
}



// Fais bouger un prédateur vers la proie la plus proche

void move_predator(std::vector<std::vector<Cell>>& world, int x, int y, int zoom)
{
	int max_size;
	int j;
	bool random_1 = rand() % 2;
	bool random_2 = rand() % 2;
	Cell temp;

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

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y > 0 and world[i][j].type == prey and (world[x][y - 1].type == empty or world[x][y - 1].type == plant))
				{
					temp = world[x][y - 1];

					world[x][y - 1] = world[x][y];
					show_cell(x, y - 1, predator, zoom);

					world[x][y] = temp;
					show_cell(x, y, world[x][y].type, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x - size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x > 0 and world[j][i].type == prey and (world[x - 1][y].type == empty or world[x - 1][y].type == plant))
				{
					temp = world[x - 1][y];

					world[x - 1][y] = world[x][y];
					show_cell(x - 1, y, predator, zoom);

					world[x][y] = temp;
					show_cell(x, y, world[x][y].type, zoom);

					return;
				}
			}

			for (int i = x - (size - random_1); i <= x + (size - random_1); i++)
			{
				j = y + size;

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y < world.front().size() - 1 and world[i][j].type == prey and (world[x][y + 1].type == empty or world[x][y + 1].type == plant))
				{
					temp = world[x][y + 1];

					world[x][y + 1] = world[x][y];
					show_cell(x, y + 1, predator, zoom);

					world[x][y] = temp;
					show_cell(x, y, world[x][y].type, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x + size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x < world.size() - 1 and world[j][i].type == prey and (world[x + 1][y].type == empty or world[x + 1][y].type == plant))
				{
					temp = world[x + 1][y];

					world[x + 1][y] = world[x][y];
					show_cell(x + 1, y, predator, zoom);

					world[x][y] = temp;
					show_cell(x, y, world[x][y].type, zoom);

					return;
				}
			}
		}

		else
		{
			for (int i = x - (size - random_1); i <= x + (size - random_1); i++)
			{
				j = y + size;

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y < world.front().size() - 1 and world[i][j].type == prey and (world[x][y + 1].type == empty or world[x][y + 1].type == plant))
				{
					temp = world[x][y + 1];

					world[x][y + 1] = world[x][y];
					show_cell(x, y + 1, predator, zoom);

					world[x][y] = temp;
					show_cell(x, y, world[x][y].type, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x + size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x < world.size() - 1 and world[j][i].type == prey and (world[x + 1][y].type == empty or world[x + 1][y].type == plant))
				{
					temp = world[x + 1][y];

					world[x + 1][y] = world[x][y];
					show_cell(x + 1, y, predator, zoom);

					world[x][y] = temp;
					show_cell(x, y, world[x][y].type, zoom);

					return;
				}
			}

			for (int i = x - (size - random_1); i <= x + (size - random_1); i++)
			{
				j = y - size;

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y > 0 and world[i][j].type == prey and (world[x][y - 1].type == empty or world[x][y - 1].type == plant))
				{
					temp = world[x][y - 1];

					world[x][y - 1] = world[x][y];
					show_cell(x, y - 1, predator, zoom);

					world[x][y] = temp;
					show_cell(x, y, world[x][y].type, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x - size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x > 0 and world[j][i].type == prey and (world[x - 1][y].type == empty or world[x - 1][y].type == plant))
				{
					temp = world[x - 1][y];

					world[x - 1][y] = world[x][y];
					show_cell(x - 1, y, predator, zoom);

					world[x][y] = temp;
					show_cell(x, y, world[x][y].type, zoom);

					return;
				}
			}
		}
	}
}



// Fais manger une proie à un prédateur

void eat_prey(std::vector<std::vector<Cell>>& world, int x, int y, int zoom)
{
	std::vector<int> order = random_order_4();

	for (int r = 0; r < 4; r++)
	{
		switch (order[r])
		{

		case 0:

			if (x > 0 and world[x - 1][y].type == prey)
			{
				world[x - 1][y] = Cell();
				show_cell(x - 1, y, empty, zoom);

				return;
			}

			break;

		case 1:

			if (y > 0 and world[x][y - 1].type == prey)
			{
				world[x][y - 1] = Cell();
				show_cell(x, y - 1, empty, zoom);

				return;
			}

			break;

		case 2:

			if (y < world.front().size() - 1 and world[x][y + 1].type == prey)
			{
				world[x][y + 1] = Cell();
				show_cell(x, y + 1, empty, zoom);

				return;
			}

			break;

		case 3:

			if (x < world.size() - 1 and world[x + 1][y].type == prey)
			{
				world[x + 1][y] = Cell();
				show_cell(x + 1, y, empty, zoom);

				return;
			}

			break;
		}
	}
}



// Crée un nouveau prédateur à côté d'un autre

void predator_make_kid(std::vector<std::vector<Cell>>& world, int x, int y, int zoom)
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
					world[i][j] = Cell(predator);
					show_cell(i, j, predator, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x - size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x > 0 and world[j][i].type == empty)
				{
					world[j][i] = Cell(predator);
					show_cell(j, i, predator, zoom);

					return;
				}
			}

			for (int i = x - (size - random_1); i <= x + (size - random_1); i++)
			{
				j = y + size;

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y < world.front().size() - 1 and world[i][j].type == empty)
				{
					world[i][j] = Cell(predator);
					show_cell(i, j, predator, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x + size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x < world.size() - 1 and world[j][i].type == empty)
				{
					world[j][i] = Cell(predator);
					show_cell(j, i, predator, zoom);

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
					world[i][j] = Cell(predator);
					show_cell(i, j, predator, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x + size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x < world.size() - 1 and world[j][i].type == empty)
				{
					world[j][i] = Cell(predator);
					show_cell(j, i, predator, zoom);

					return;
				}
			}

			for (int i = x - (size - random_1); i <= x + (size - random_1); i++)
			{
				j = y - size;

				if (i >= 0 and i < world.size() and j >= 0 and j < world.front().size() and y > 0 and world[i][j].type == empty)
				{
					world[i][j] = Cell(predator);
					show_cell(i, j, predator, zoom);

					return;
				}
			}

			for (int i = y - (size - !random_1); i <= y + (size - !random_1); i++)
			{
				j = x - size;

				if (i >= 0 and i < world.front().size() and j >= 0 and j < world.size() and x > 0 and world[j][i].type == empty)
				{
					world[j][i] = Cell(predator);
					show_cell(j, i, predator, zoom);

					return;
				}
			}
		}
	}
}