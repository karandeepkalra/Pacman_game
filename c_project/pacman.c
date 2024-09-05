#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "my_lib.h"
#define SIZE_R 21
#define SIZE_C 77
#define ITEM_TOTAL 263
void moveghost(void (*func[])(position *, int *, int *, int *, char maze[SIZE_R][SIZE_C + 1]), position *ghost, int *deathf, int *changef, int *itemf, char maze[SIZE_R][SIZE_C + 1], position player, int items)
{
	int temp = rand() % 10; // value from 0 to 9
	*changef = 0;
	if (ghost->cols - player.cols < 0)
	{
		ghost_add_col(ghost, changef, deathf, itemf, maze);
	}
	else if (ghost->cols - player.cols > 0)
	{
		ghost_min_col(ghost, changef, deathf, itemf, maze);
	}
	if ((ghost->rows - player.rows) < 0)
	{
		ghost_add_row(ghost, changef, deathf, itemf, maze);
	}
	else if ((ghost->rows - player.rows) > 0)
	{
		ghost_min_row(ghost, changef, deathf, itemf, maze);
	}
	if (!*changef)
	{
		func[0](ghost, changef, deathf, itemf, maze);
		func[1](ghost, changef, deathf, itemf, maze);
		func[2](ghost, changef, deathf, itemf, maze);
		func[3](ghost, changef, deathf, itemf, maze);
	}
}
void update_ghosts2(position *ghost, int count, int *deathf, int *print_f, char maze[SIZE_R][SIZE_C + 1], position player, int items)
{
	void (*func[])(position *, int *, int *, int *, char maze[SIZE_R][SIZE_C + 1]) = {ghost_add_col, ghost_add_row, ghost_min_row, ghost_min_col};
	if ((*deathf == 0) && (*print_f == 0))
	{
		int changef = 0;
		moveghost(func, ghost, deathf, &changef, &ghost->itemf, maze, player, items);
	}
}
int main()
{
	printf("WELCOME TO PACMAN!\n");
	printf("Short Guide: '@' is PACMAN, '^' is your objectives, and '&' are the ghosts! \n");
	int i = 0, j = 0;
	int user_input = 0;
	int print_flag = 0;
	int deathf = 0, changef = 0, temp = 0, item1 = 0;
	int item2 = 0, item3 = 0, item4 = 0;
	int items = 0;

	char maze[SIZE_R][SIZE_C + 1] =
		{
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
			"*****************************************************************************"};
	items = ITEM_TOTAL;
	printf("press any key to start...\n");
	getchar();
	for (int i = 0; i < SIZE_R; i++)
	{
		maze[i][SIZE_C] = '\0';
	}
	update_screen(maze, SIZE_R, SIZE_C, items);
	printf("\n");
	printf("items left:%d\n", items);
	position player = {7, 36, 0};
	position ghost1 = {1, 6, 0};
	position ghost2 = {1, 70, 0};
	position ghost3 = {19, 6, 0};
	position ghost4 = {19, 70, 0};
	while (1)
	{
		if (user_input == 0)
		{
			user_input = getchar();
		}
		else
		{
			printf("bug detected\n");
			return -1;
		}

		switch (user_input)
		{
		case 'a':
			// for left movement
			if (player.cols - 2 < 0 || player.cols - 2 < 0 || maze[player.rows][player.cols - 1] == '*' || maze[player.rows][player.cols - 2] == '*')
			{
				print_flag = -1;
			}
			else
			{
				// if the location has an item, erase the item and reduce the number of items that should be collected.
				if (maze[player.rows][player.cols - 2] == '^')
				{
					maze[player.rows][player.cols - 2] = ' ';
					items--;
				}
				// if the location is a ghost, end the game.
				if (maze[player.rows][player.cols - 2] == '&')
				{
					maze[player.rows][player.cols] = ' ';
					maze[player.rows][player.cols - 2] = '&';
					deathf = 1;
				}
				else
				{
					// erase the user's original position and place user in the new position.
					maze[player.rows][player.cols] = ' ';
					maze[player.rows][player.cols - 2] = '@';
					// update user's current location.
					player.cols -= 2;
				}
			}
			break;

		case 'd':
			// move right if possible..
			if (player.cols + 2 >= SIZE_C || maze[player.rows][player.cols + 1] == '*' || maze[player.rows][player.cols + 2] == '*')
			{
				print_flag = -1;
			}
			else
			{
				if (maze[player.rows][player.cols + 2] == '^')
				{
					maze[player.rows][player.cols + 2] = ' ';
					items--;
				}
				if (maze[player.rows][player.cols + 2] == '&')
				{
					maze[player.rows][player.cols] = ' ';
					maze[player.rows][player.cols + 2] = '&';
					deathf = 1;
				}
				else
				{
					maze[player.rows][player.cols] = ' ';
					maze[player.rows][player.cols + 2] = '@';
					player.cols += 2;
				}
			}
			break;
		case 'w':
			// for upward direction
			if (player.rows - 1 < 0 || maze[player.rows - 1][player.cols] == '*')
			{
				print_flag = -1;
			}
			else
			{

				if (maze[player.rows - 1][player.cols] == '^')
				{
					maze[player.rows - 1][player.cols] = ' ';
					items--;
				}
				if (maze[player.rows - 1][player.cols] == '&')
				{
					maze[player.rows][player.cols] = ' ';
					maze[player.rows - 1][player.cols] = '&';
					deathf = 1;
				}
				else
				{
					maze[player.rows - 1][player.cols] = '@';
					maze[player.rows][player.cols] = ' ';
					player.rows -= 1;
				}
			}
			break;

		case 's':
			// downward direction
			if (player.rows + 1 > SIZE_R || maze[player.rows + 1][player.cols] == '*')
			{
				print_flag = -1;
			}
			else
			{

				if (maze[player.rows + 1][player.cols] == '^')
				{
					maze[player.rows + 1][player.cols] = ' ';
					items--;
				}
				if (maze[player.rows + 1][player.cols] == '&')
				{
					maze[player.rows][player.cols] = ' ';
					maze[player.rows + 1][player.cols] = '&';
					deathf = 1;
				}
				else
				{
					maze[player.rows + 1][player.cols] = '@';
					maze[player.rows][player.cols] = ' ';
					player.rows += 1;
				}
			}
			break;
		case 'q':
			printf("Are you sure you want to quit the game? \n");
			printf("<- to quit, -> to play again \n");
			while (1)
			{
				user_input = getch(); // Wait for user input
				if (user_input == 'a')
				{
					printf("See you!\n");
					return 0; // Quit the game
				}
				if (user_input == 'd')
				{
					printf("Game Continue! \n");
					break; // Continue game
				}
			}
			break;

		default:
			print_flag = -1;
			break;
		}
		int ghost_count = 4;
		position ghost[4] = {ghost1, ghost2, ghost3, ghost4};
		if (deathf == 0 && print_flag == 0)
		{
			update_ghosts2(&ghost1, ghost_count, &deathf, &print_flag, maze, player, items);
			update_ghosts2(&ghost2, ghost_count, &deathf, &print_flag, maze, player, items);
			update_ghosts2(&ghost3, ghost_count, &deathf, &print_flag, maze, player, items);
			update_ghosts2(&ghost4, ghost_count, &deathf, &print_flag, maze, player, items);
			update_screen(maze, SIZE_R, SIZE_C, items);
		}

		if (deathf)
		{
			break;
		}

		if (!items)
		{

			break;
		}
		user_input = 0;
		print_flag = 0;
	}
	if (!deathf || !items)
	{
		printf("Congratulations!You Win!\n");
	}
	else
	{
		printf("Aw...You Lose!\n");
	}
	printf("Press any key to proceed...\n");
	getchar();
	while (1)
	{
		user_input = getchar();
		if (user_input == 'd')
		{
			printf("\n");
			printf("\n");
			printf("\n");
			break;
		}
		if (user_input == 'a')
		{
			printf("Press any key to exit...\n");
			getch();
			return 0;
		}
	}
	return 0;
}
