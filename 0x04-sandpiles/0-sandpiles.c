#include "sandpiles.h"
static void print_g(int grid[3][3]);
/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: first grid to compute
 * @grid2: second grid to compute
 *
 * Return: Always nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int column, row, stable;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			grid1[column][row] += grid2[column][row];
		}
	}
	stable = stable_check(grid1);
	while (stable == 0)
	{
		printf("=\n");
		print_g(grid1);
		topple_sand(grid1);
		stable = stable_check(grid1);
	}
}
/**
 * topple_sand - Topple sands that exist in grid
 * @grid1: 3x3 grid
 *
 */
void topple_sand(int grid1[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (grid1[row][column] > 3)
			{
				grid1[row][column] -= 4;
				if (row > 0)
				{
					grid1[row - 1][column] += 1;
				}
				if (column > 0)
				{
					grid1[row][column - 1] += 1;
				}
				if (row < 2)
				{
					grid1[row + 1][column] += 1;
				}
				if (column < 2)
				{
					grid1[row][column + 1] += 1;
				}
			}
		}
	}
}
/**
 * stable_check - Print 3x3 grid
 * @grid: 3x3 grid
 *
 * Return: 0 if tupples exist, else 1
 */
int stable_check(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}
/**
 * print_g - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_g(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
