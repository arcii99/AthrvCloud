//FormAI DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

/* Utility function to swap two elements in an array */
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Shuffles an array using the Fisher-Yates shuffle */
void shuffle(int* array, int size)
{
    srand(time(NULL));
    for (int i = size - 1; i >= 1; i--)
    {
        /* Generate a random index between 0 and i, inclusive */
        int j = rand() % (i + 1);
        /* Swap the elements at indices i and j */
        swap(&array[i], &array[j]);
    }
}

/* Prints the grid in its current state */
void printGrid(int grid[ROWS][COLS])
{
    printf("\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

/* Initializes the grid with numbers 1 to (ROWS * COLS) / 2 */
void initGrid(int grid[ROWS][COLS])
{
    int maxNumber = (ROWS * COLS) / 2;
    int numbers[maxNumber];
    for (int i = 0; i < maxNumber; i++)
    {
        numbers[i] = i + 1;
    }
    shuffle(numbers, maxNumber);

    int index = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = numbers[index];
            index++;
        }
    }
}

/* Updates the grid to reveal the number at index (row, col) */
void reveal(int grid[ROWS][COLS], int row, int col)
{
    grid[row][col] *= -1;
}

/* Checks if the selected cells match */
int checkMatch(int grid[ROWS][COLS], int row1, int col1, int row2, int col2)
{
    if (grid[row1][col1] == grid[row2][col2])
    {
        return 1;
    }
    else
    {
        /* Hide the selected cells again */
        grid[row1][col1] *= -1;
        grid[row2][col2] *= -1;
        return 0;
    }
}

int main()
{
    /* Initialize the game grid */
    int grid[ROWS][COLS];
    initGrid(grid);

    /* Game loop */
    int score = 0;
    int matched = 0;
    while (matched < (ROWS * COLS) / 2)
    {
        printGrid(grid);

        /* Get the user's choice of cells to reveal */
        int row1, col1, row2, col2;
        printf("Select the first cell (row col): ");
        scanf("%d %d", &row1, &col1);
        reveal(grid, row1, col1);
        printf("Select the second cell (row col): ");
        scanf("%d %d", &row2, &col2);
        reveal(grid, row2, col2);

        /* Check if the selected cells match */
        if (checkMatch(grid, row1, col1, row2, col2))
        {
            printf("Match found!\n");
            score++;
            matched++;
        }
        else
        {
            printf("Try again!\n");
            score--;
        }

        printf("Score: %d\n", score);
    }

    printf("Congratulations, you won with a score of %d!\n", score);

    return 0;
}