//FormAI DATASET v1.0 Category: Memory Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main()
{
    int num1[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int num2[ROWS][COLS] = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};
    
    int i, j, k, l, temp, random1, random2, count = 0;
    srand(time(NULL));
    
    printf("Welcome to the Surrealist Memory Game!\n");
    printf("In this game, you will be presented with two matrices.\n");
    printf("Your task is to swap the elements in the matrices to make them match.\n");
    printf("Are you ready to play? (Press enter to continue)\n");
    getchar();
    
    printf("Your matrices are:\n");
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%d ", num1[i][j]);
        }
        printf("\t");
        for(j = 0; j < COLS; j++)
        {
            printf("%d ", num2[i][j]);
        }
        printf("\n");
    }
    
    while(count < 8)
    {
        random1 = rand() % 16;
        random2 = rand() % 16;
        i = random1 / 4;
        j = random1 % 4;
        k = random2 / 4;
        l = random2 % 4;
        
        temp = num1[i][j];
        num1[i][j] = num2[k][l];
        num2[k][l] = temp;
        
        printf("Your new matrices are:\n");
        for(i = 0; i < ROWS; i++)
        {
            for(j = 0; j < COLS; j++)
            {
                printf("%d ", num1[i][j]);
            }
            printf("\t");
            for(j = 0; j < COLS; j++)
            {
                printf("%d ", num2[i][j]);
            }
            printf("\n");
        }
        
        count++;
        
        printf("Press enter to continue.\n");
        getchar();
    }
    
    printf("Congratulations! You have matched all the elements!\n");
    
    return 0;
}