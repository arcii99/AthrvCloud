//FormAI DATASET v1.0 Category: Memory Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4

int grid[GRID_SIZE][GRID_SIZE];

void initGrid();
void printGrid();
void shuffleGrid();
void swap(int* a, int* b);

int main()
{
    printf("*** Welcome to the Memory Game! ***\n\n");
    printf("Instructions: Flip over two cards and try to match them.\n");
    printf("If the cards match, they will stay flipped over. If not,");
    printf("they will flip back over.\n\n");

    initGrid(); // initialize the grid with numbers
    shuffleGrid(); // shuffle the numbers on the grid

    printGrid(); // print out the grid

    printf("Ready to play? Let's go!\n");

    // add game logic here

    return 0;
}

void initGrid()
{
    int count = 1;

    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = count;
            count++;
        }
    }
}

void printGrid()
{
    printf("   1  2  3  4\n");
    printf("  ------------\n");

    for (int i = 0; i < GRID_SIZE; i++)
    {
        printf("%c ", 'A' + i);

        for (int j = 0; j < GRID_SIZE; j++)
        {
            printf("|%2d", grid[i][j]);
        }

        printf("|\n");
        printf("  ------------\n");
    }
}

void shuffleGrid()
{
    srand(time(NULL));

    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            int swap_i = rand() % GRID_SIZE;
            int swap_j = rand() % GRID_SIZE;

            swap(&grid[i][j], &grid[swap_i][swap_j]);
        }
    }
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}