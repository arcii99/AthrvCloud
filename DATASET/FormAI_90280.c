//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the array
void shuffle(int arr[], int n)
{
    srand(time(NULL)); // Initialize random number generator
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    int bingo[5][5], i, j;

    // Intialize the bingo board with numbers
    bingo[0][0] = 5;
    bingo[0][1] = 10;
    bingo[0][2] = 15;
    bingo[0][3] = 20;
    bingo[0][4] = 25;

    bingo[1][0] = 30;
    bingo[1][1] = 35;
    bingo[1][2] = 40;
    bingo[1][3] = 45;
    bingo[1][4] = 50;

    bingo[2][0] = 55;
    bingo[2][1] = 60;
    bingo[2][2] = 65;
    bingo[2][3] = 70;
    bingo[2][4] = 75;

    bingo[3][0] = 80;
    bingo[3][1] = 85;
    bingo[3][2] = 90;
    bingo[3][3] = 95;
    bingo[3][4] = 100;

    bingo[4][0] = 1;
    bingo[4][1] = 6;
    bingo[4][2] = 11;
    bingo[4][3] = 16;
    bingo[4][4] = 21;

    shuffle(&bingo[0][0], 25); // Shuffle the numbers

    // Display the shuffled bingo board
    printf("B\tI\tN\tG\tO\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (bingo[i][j] == 0) // If the number is marked
                printf("X\t");
            else
                printf("%d\t", bingo[i][j]);
        }
        printf("\n");
    }

    return 0;
}