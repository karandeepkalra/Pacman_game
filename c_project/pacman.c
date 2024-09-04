#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "my_lib.h"
#define SIZE_R 21
#define SIZE_C 77
#define ITEM_TOTAL 263
typedef struct
{
	int row;
	int column;
} position;
// void update_screen(char maze[SIZE_R][SIZE_C + 1], int rows, int cols, int items)
// {
//     if (items)
//     {
//         printf("\nw = move up, s = move down, a = move left, d = move right, q = quit game, items left: %d \n", items);
//     }
//     for (int i = 0; i < rows; i++)
//     {
//         printf("%s\n", maze[i]);
//     }
// }
int main()
{
	printf("WELCOME TO PACMAN! \n");
	printf("Short Guide: '@' is PACMAN, '^' is your objectives, and '&' are the ghosts! \n");

	//    #if 0
	// Game start
	while (1)
	{
		int i = 0;
		int j = 0;

		int user_input = 0;
		int print_flag = 0;
		int death_flag = 0;

		int change_flag = 0;
		int temp = 0;

		int item_flag1 = 0;
		int item_flag2 = 0;
		int item_flag3 = 0;
		int item_flag4 = 0;

		/*
		int add_row = 0;
		int min_row = 0;
		int add_col = 0;
		int min_col = 0;
		*/

		int items = 0;
		position player;
		position ghost_1;
		position ghost_2;
		position ghost_3;
		position ghost_4;

		// The maze blueprint.
		// "@" is the player.
		// "^" is the item that the player has to collect.
		// Player wins when they collect all the "^".
		char maze[SIZE_R][SIZE_C + 1] = {
			"*****************************************************************************",
			"* ^ ^ & ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ & ^ ^ *",
			"* ^ ^ **********  ^  ********** ^ ^ **********  ^  ********** ^ ^ ***********",
			"* ^ ^ *        *  ^  *        * ^ ^ *        *  ^  *        * ^ ^ *         *",
			"* ^ ^ *        *  ^  *        * ^ ^ *        *  ^  *        * ^ ^ *         *",
			"* ^ ^ *        *  ^  *        * ^ ^ *        *  ^  *        * ^ ^ *         *",
			"* ^ ^ **********  ^  ********** ^ ^ **********  ^  ********** ^ ^ ***********",
			"* ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ @ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ *",
			"*********** ^ ^ **********  ^  ********** ^ ^ **********  ^  ********** ^ ^ *",
			"*         * ^ ^ *        *  ^  *        * ^ ^ *        *  ^  *        * ^ ^ *",
			"*         * ^ ^ *        *  ^  *        * ^ ^ *        *  ^  *        * ^ ^ *",
			"*         * ^ ^ *        *  ^  *        * ^ ^ *        *  ^  *        * ^ ^ *",
			"*********** ^ ^ **********  ^  ********** ^ ^ **********  ^  ********** ^ ^ *",
			"* ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ *",
			"* ^ ^ **********  ^  ********** ^ ^ **********  ^  ********** ^ ^ ***********",
			"* ^ ^ *        *  ^  *        * ^ ^ *        *  ^  *        * ^ ^ *         *",
			"* ^ ^ *        *  ^  *        * ^ ^ *        *  ^  *        * ^ ^ *         *",
			"* ^ ^ *        *  ^  *        * ^ ^ *        *  ^  *        * ^ ^ *         *",
			"* ^ ^ **********  ^  ********** ^ ^ **********  ^  ********** ^ ^ ***********",
			"* ^ ^ & ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ & ^ ^ *",
			"*****************************************************************************",
		};

		// Total amount of "^" that has to be collected.
		items = ITEM_TOTAL;

		printf("Press any key to start... \n");
		getch(); // wait for user to press a key.

		for (i = 0; i < SIZE_R; i++)
		{
			maze[i][SIZE_C] = '\0';

			// printf("%s\n",maze[i]);
		}

		update_screen(maze, SIZE_R, SIZE_C, items);
    }
    }