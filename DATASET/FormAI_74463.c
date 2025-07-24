//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 20

void printMaze(int maze[][COLUMNS], int playerRow, int playerCol)
{
    system("cls");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (maze[i][j] == 0)
                printf(" ");

            else if (i == playerRow && j == playerCol)
                printf("!");

            else
                printf("o");
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));

    int maze[ROWS][COLUMNS] = { 0 };
    int playerRow = rand() % ROWS;
    int playerCol = rand() % COLUMNS;
    char input;

    while (1)
    {
        printMaze(maze, playerRow, playerCol);

        printf("\nUse arrow keys to move\n");

        input = getchar();

        switch (input)
        {
        case 'w':
            if (playerRow - 1 >= 0)
                playerRow--;
            break;

        case 's':
            if (playerRow + 1 < ROWS)
                playerRow++;
            break;

        case 'a':
            if (playerCol - 1 >= 0)
                playerCol--;
            break;

        case 'd':
            if (playerCol + 1 < COLUMNS)
                playerCol++;
            break;

        default:
            break;
        }
    }

    return 0;
}