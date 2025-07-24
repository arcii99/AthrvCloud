//FormAI DATASET v1.0 Category: Memory Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int array[], int size)
{
    int i, j;
    srand(time(NULL));
    for (i = size - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        swap(&array[i], &array[j]);
    }
}

void printGrid(int grid[][COLS], int hidden[][COLS], int rows, int cols)
{
    int i, j;
    printf("\n\n    1  2  3  4\n");
    for (i = 0; i < rows; i++)
    {
        printf("   ------------\n");
        printf("%d |", i + 1);
        for (j = 0; j < cols; j++)
        {
            if (hidden[i][j])
                printf(" # ");
            else
                printf("%2d ", grid[i][j]);
        }
        printf("|\n");
    }
    printf("   ------------\n");
}

int checkForMatch(int grid[][COLS], int selections[][2])
{
    int i, j, count = 0;
    for (i = 0; i < 2; i++)
    {
        if (grid[selections[i][0]][selections[i][1]] == grid[selections[(i + 1) % 2][0]][selections[(i + 1) % 2][1]])
            count++;
    }
    return count == 2;
}

void playGame()
{
    int grid[ROWS][COLS] = {{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}};
    int hidden[ROWS][COLS] = {{1, 1, 1, 1},
                              {1, 1, 1, 1},
                              {1, 1, 1, 1},
                              {1, 1, 1, 1}};
    int selections[2][2] = {{-1, -1}, {-1, -1}};
    int count = 0, i, j;

    shuffle(grid[0], ROWS * COLS);
    printGrid(grid, hidden, ROWS, COLS);

    while (count < ROWS * COLS)
    {
        printf("\nEnter the row and column of the first number: ");
        scanf("%d %d", &selections[0][0], &selections[0][1]);
        selections[0][0]--;
        selections[0][1]--;
        hidden[selections[0][0]][selections[0][1]] = 0;
        printGrid(grid, hidden, ROWS, COLS);

        printf("\nEnter the row and column of the second number: ");
        scanf("%d %d", &selections[1][0], &selections[1][1]);
        selections[1][0]--;
        selections[1][1]--;
        hidden[selections[1][0]][selections[1][1]] = 0;
        printGrid(grid, hidden, ROWS, COLS);

        if (checkForMatch(grid, selections))
        {
            printf("\nMatch found!\n");
            count += 2;
        }
        else
        {
            printf("\nNo match found.\n");
            hidden[selections[0][0]][selections[0][1]] = 1;
            hidden[selections[1][0]][selections[1][1]] = 1;
            printGrid(grid, hidden, ROWS, COLS);
        }
    }
    printf("\nCongratulations! You won!!\n");
}

int main()
{
    playGame();
    return 0;
}