//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generateRandomNumbers(int *arr, int size)
{
    int i, j, temp;

    srand(time(NULL));
    for(i = 0; i < size; i++)
        arr[i] = rand()%75 + 1;

    for(i = 0; i < size; i++){
        for(j = i+1; j < size; j++){
            if(arr[i] == arr[j]){
                temp = rand()%75 + 1;
                arr[j] = temp;
            }
        }
    }
}

void display_Bingo_card(int board[ROWS][COLS], int *nums)
{
    int i, j, k;

    printf("\n     B  I  N  G  O\n");

    for(i = 0; i < ROWS; i++){
        printf("%d  ", i+1);
        for(j = 0; j < COLS; j++){
            if(i == 2 && j == 2){
                printf("   ");
                continue;
            }
            for(k = 0; k < 25; k++){
                if(board[i][j] == *(nums + k)){
                    printf("\033[0;32m%2d\033[0m ", board[i][j]);
                    break;
                }
            }
            if(k == 25)
                printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int board[ROWS][COLS], i, j, nums[25];

    generateRandomNumbers(nums, 25);

    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            board[i][j] = nums[5*j + i];
        }
    }

    display_Bingo_card(board, nums);

    printf("\nThe list of 25 random numbers is:\n\n");

    for(i = 0; i < 25; i++)
        printf("%d ", nums[i]);

    printf("\n\nHope you enjoy the Bingo game!\n");

    return 0;
}