//управление происходит через пустышку, с помощью стрелок можно указать в какую сторону переместить пустышку.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

enum keys { UP, DOWN, LEFT, RIGHT };

int difficulty = 10;
int spacex;
int spacey;


void mystart(int **puzzle, int size);
void myprint(int **puzzle, int size);
void mymove(keys key, int **puzzle,int size);
void myrandom(int **puzzle,int size);
void myrandomMain(int **puzzle, int size);
bool checkWin(int **puzzle, int size);

int main()
{
	char c;
	int size;

	printf("Enter the size of the side from 2 to 9\n");
	scanf_s("%d", &size);

	int **puzzle = (int**)malloc(sizeof(int*) * size);
	for (int i = 0; i < size; ++i)
		puzzle[i] = (int*)malloc(sizeof(int) * size);

	mystart(puzzle, size);
	myrandomMain(puzzle,size);
	myprint(puzzle, size);

	while (!checkWin(puzzle,size))
	{
		c = _getch();
		switch (c)
		{
		case 72: mymove(UP,puzzle,size); break;
		case 80: mymove(DOWN,puzzle,size); break;
		case 75: mymove(LEFT,puzzle,size); break;
		case 77: mymove(RIGHT,puzzle,size); break;
		}
		myprint(puzzle,size);
	}

	printf("This is victory\n");
	return 0;
}

void mystart(int **puzzle,int size)
{
	int k = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			puzzle[i][j] = ++k;
		}

	puzzle[size - 1][size - 1] = 0;
	spacex = size - 1;
	spacey = size - 1;
}

void myprint(int **puzzle, int size)
{
	char c = '0';
	system("cls");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (puzzle[i][j] == 0)
			{
				printf("%4s|", "");
			}
			else
			{
				printf("%4d|", puzzle[i][j]);
			}
		}
		printf("\n");
	}
}

void mymove(keys key, int **puzzle,int size)
{
	switch (key)
	{
	case UP:
	{
		if (spacex > 0)
		{
			puzzle[spacex][spacey] = puzzle[spacex - 1][spacey];
			puzzle[spacex - 1][spacey] = 0;
			--spacex;
		}
		break;
	}
	case DOWN:
	{
		if (spacex < size-1)
		{
			puzzle[spacex][spacey] = puzzle[spacex + 1][spacey];
			puzzle[spacex + 1][spacey] = 0;
			++spacex;
		}
		break;
	}
	case RIGHT:
	{
		if (spacey < size-1)
		{
			puzzle[spacex][spacey] = puzzle[spacex][spacey + 1];
			puzzle[spacex][spacey + 1] = 0;
			++spacey;
		}
		break;
	}
	case LEFT:
	{
		if (spacey > 0)
		{
			puzzle[spacex][spacey] = puzzle[spacex][spacey - 1];
			puzzle[spacex][spacey - 1] = 0;
			--spacey;
		}
		break;
	}
	}
}

void myrandom(int **puzzle,int size)
{
	int a = rand() % 4;
	switch (a)
	{
	case 0:mymove(UP,puzzle,size); break;
	case 1:mymove(DOWN,puzzle,size); break;
	case 2:mymove(LEFT,puzzle,size); break;
	case 3:mymove(RIGHT,puzzle,size); break;
	}
}

void myrandomMain(int **puzzle, int size)
{
	for (int i = 0; i < difficulty; i++)
		myrandom(puzzle,size);
}
bool checkWin(int **puzzle, int size)
{
	if (puzzle[size - 1][size - 1] != 0)

		for (int i = 0; i < size*size - 1; i++)
			if (puzzle[i / size][i%size] != i + 1)
				return false;

	return true;
}