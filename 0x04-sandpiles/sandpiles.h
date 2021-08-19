#ifndef SANDPILES_H
#define SANDPILES_H
#include <stdio.h>
#include <stdlib.h>
// static void print_grid_sum(int grid1[3][3], int grid2[3][3]);
// static void print_grid(int grid[3][3]);
int main(void);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void topple_sand(int grid1[3][3]);
int stable_check(int grid[3][3]);

#endif