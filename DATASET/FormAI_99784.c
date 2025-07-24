//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the array
void shuffle(int *arr, int n)
{
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--)
    {

        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to check if a row or column or diagonal is marked
int checkForWin(int arr[5][5], int n)
{
    // Checking for rows
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
                count++;
        }
        if (count == n)
            return 1;
    }

    // Checking for columns
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] == 0)
                count++;
        }
        if (count == n)
            return 1;
    }

    // Checking for the diagonal from top left corner to bottom right corner
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][i] == 0)
            count++;
    }
    if (count == n)
        return 1;

    // Checking for the diagonal from top right corner to bottom left corner
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][n - i - 1] == 0)
            count++;
    }
    if (count == n)
        return 1;

    return 0;
}

// Function to display the grid
void printGrid(int arr[5][5], int n)
{
    printf("\n------------------\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("|%2d|", arr[i][j]);
        }
        printf("\n------------------\n");
    }
}

// Main function
int main()
{
    int arr[5][5];
    int n = 5;
    int num = 1;

    // Initializing the grid with numbers
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = num;
            num++;
        }
    }

    // Shuffling the grid
    shuffle((int *)arr, n * n);

    // Setting the middle number as 0
    arr[2][2] = 0;

    // Displaying the grid
    printGrid(arr, n);

    // Game loop
    while (1)
    {
        int input;
        printf("Enter the number called or 0 to exit: ");
        scanf("%d", &input);

        if (input == 0)
            break;

        // Marking the called number
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == input)
                    arr[i][j] = 0;
            }
        }

        // Displaying the grid
        printGrid(arr, n);

        // Checking for win condition
        if (checkForWin(arr, n))
        {
            printf("\nBINGO! You have won!\n");
            break;
        }
    }

    return 0;
}