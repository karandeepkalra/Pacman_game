#include<stdio.h>
#define SIZE_R 21
#define SIZE_C 77
#define ITEM_TOTAL 263
void update_screen(char maze[][SIZE_C + 1], int rows, int cols, int items)
{
	int i;
	if (items)
	{
		printf("\nw = move up, s = move down, a = move left, d = move right, q = quit game, items left: %d \n", items);
	}

	for (i = 0; i < rows; i++)
	{

		printf("%s\n", maze[i]);
	}
}