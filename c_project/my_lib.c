#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "my_lib.h"
#define SIZE_R 21
#define SIZE_C 77
#define ITEM_TOTAL 263
void ghost_add_col(position *ghost, int *changef, int *deathf, int *itemf, char arr[SIZE_R][SIZE_C + 1])
{

	if (*changef == 0)
	{
	
		if (ghost->cols + 2 >= SIZE_C || (arr[ghost->rows][ghost->cols + 1] == '*') || (arr[ghost->rows][ghost->cols + 2] == '*') || (arr[ghost->rows][ghost->cols + 2] == '&'))
		{
			return;
		}
		else
		{
			if (arr[ghost->rows][ghost->cols + 2] == '@')
			{
				*deathf = 1;
			}
			if (*itemf)
			{
				arr[ghost->rows][ghost->cols] = '^';
			}
			else
			{
				arr[ghost->rows][ghost->cols] = ' ';
			}
			if (arr[ghost->rows][ghost->cols + 2] == '^')
			{
				*itemf = 1;
			}
			else
			{
				*itemf = 0;
			}

			arr[ghost->rows][ghost->cols + 2] = '&';
			ghost->cols += 2;
			*changef = 1;
		}
	}
}

void ghost_min_col(position *ghost, int *changef, int *deathf, int *itemf, char arr[SIZE_R][SIZE_C + 1])
{
	if (*changef == 0)
	{
		if (ghost->cols - 2 < 0 || (arr[ghost->rows][ghost->cols - 1] == '*') || ((ghost->cols - 2) > SIZE_C) || (arr[ghost->rows][ghost->cols - 2] == '*') || (arr[ghost->rows][ghost->cols - 2] == '&'))
		{
			return;
		}
		else
		{
			if (arr[ghost->rows][ghost->cols - 2] == '@')
			{
				*deathf = 1;
			}
			if (*itemf)
			{
				arr[ghost->rows][ghost->cols] = '^';
			}
			else
			{
				arr[ghost->rows][ghost->cols] = ' ';
			}
			if (arr[ghost->rows][ghost->cols - 2] == '^')
			{
				*itemf = 1;
			}
			else
			{
				*itemf = 0;
			}

			arr[ghost->rows][ghost->cols - 2] = '&';
			ghost->cols -= 2;
			*changef = 1;
		}
	}
}

void ghost_add_row(position *ghost, int *changef, int *deathf, int *itemf, char arr[SIZE_R][SIZE_C + 1])
{
	if (*changef == 0)
	{
		if ((ghost->rows + 1 >= SIZE_R) || (arr[ghost->rows + 1][ghost->cols] == '*') || (arr[ghost->rows + 1][ghost->cols] == '&'))
		{
			return;
		}
		else
		{
			if (arr[ghost->rows + 1][ghost->cols] == '@')
			{
				*deathf = 1;
			}
			if (*itemf)
			{
				arr[ghost->rows][ghost->cols] = '^';
			}
			else
			{
				arr[ghost->rows][ghost->cols] = ' ';
			}
			if (arr[ghost->rows + 1][ghost->cols] == '^')
			{
				*itemf = 1;
			}
			else
			{
				*itemf = 0;
			}
			arr[ghost->rows + 1][ghost->cols] = '&';
			ghost->rows += 1;
			*changef = 1;
		}
	}
}

void ghost_min_row(position *ghost, int *changef, int *deathf, int *itemf, char arr[SIZE_R][SIZE_C + 1])
{
	if (*changef == 0)
	{
		if (((ghost->rows - 1) < 0) || (arr[ghost->rows - 1][ghost->cols] == '*') || (arr[ghost->rows - 1][ghost->cols] == '&'))
		{
			return;
		}
		else
		{
			if (arr[ghost->rows - 1][ghost->cols] == '@')
			{
				*deathf = 1;
			}
			if (*itemf)
			{
				arr[ghost->rows][ghost->cols] = '^';
			}
			else
			{
				arr[ghost->rows][ghost->cols] = ' ';
			}
			if (arr[ghost->rows - 1][ghost->cols] == '^')
			{
				*itemf = 1;
			}
			else
			{
				*itemf = 0;
			}

			arr[ghost->rows - 1][ghost->cols] = '&';
			ghost->rows -= 1;
		}
	}
}
void update_screen(char maze[][SIZE_C + 1], int rows, int cols, int items)
{
	system("cls");
	int i;
	if (items)
	{
		printf("\nw = move up, s = move down, a = move left, d = move right, q = quit game, items left: %d \n", items);
	}

	for (i = 0; i < rows; i++)
	{

		printf("%s\n", maze[i]);
	}
	return;
}