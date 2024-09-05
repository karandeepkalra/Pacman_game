#define SIZE_R 21
#define SIZE_C 77
#define ITEM_TOTAL 263

typedef struct
{
	int rows;
	int cols;
	int itemf;
} position;
int update_screen(char maze[][SIZE_C + 1], int rows, int cols, int items);
void ghost_min_row(position *ghost, int *changef, int *deathf, int *itemf, char arr[SIZE_R][SIZE_C + 1]);
void ghost_add_row(position *ghost, int *changef, int *deathf, int *itemf, char arr[SIZE_R][SIZE_C + 1]);
void ghost_add_col(position *ghost, int *changef, int *deathf, int *itemf, char arr[SIZE_R][SIZE_C + 1]);
void ghost_min_col(position *ghost, int *changef, int *deathf, int *itemf, char arr[SIZE_R][SIZE_C + 1]);