//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define constants */
#define ROWS 5
#define COLS 5

/* Function prototypes */
void print_board(int board[ROWS][COLS]);
void generate_numbers(int board[ROWS][COLS]);
int check_bingo(int board[ROWS][COLS]);

/* Main function */
int main()
{
    /* Seed the random number generator */
    srand(time(NULL));
    
    /* Create the board */
    int board[ROWS][COLS];
    
    /* Generate the numbers */
    generate_numbers(board);
    
    /* Print the board */
    printf("BINGO SIMULATOR\n");
    printf("----------------\n");
    print_board(board);
    
    /* Check for bingo */
    int bingo = check_bingo(board);
    if (bingo == 1) {
        printf("BINGO!");
    }
    
    return 0;
}

/* Function to print the board */
void print_board(int board[ROWS][COLS])
{
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

/* Function to generate the numbers */
void generate_numbers(int board[ROWS][COLS])
{
    int nums[ROWS*COLS];
    
    /* Fill nums with random numbers */
    for (int i=0; i<ROWS*COLS; i++) {
        nums[i] = i+1;
    }
    
    /* Shuffle the array of numbers */
    for (int i=0; i<ROWS*COLS; i++) {
        int temp = nums[i];
        int rand_index = rand() % (ROWS*COLS);
        nums[i] = nums[rand_index];
        nums[rand_index] = temp;
    }
    
    /* Copy the shuffled numbers to the board */
    int index = 0;
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            board[i][j] = nums[index];
            index++;
        }
    }
}

/* Function to check for bingo */
int check_bingo(int board[ROWS][COLS])
{
    /* Check rows */
    for (int i=0; i<ROWS; i++) {
        int sum = 0;
        for (int j=0; j<COLS; j++) {
            sum += board[i][j];
        }
        if (sum == 0) {
            return 1;
        }
    }
    
    /* Check columns */
    for (int i=0; i<COLS; i++) {
        int sum = 0;
        for (int j=0; j<ROWS; j++) {
            sum += board[j][i];
        }
        if (sum == 0) {
            return 1;
        }
    }
    
    /* Check diagonals */
    int sum = 0;
    for (int i=0; i<ROWS; i++) {
        sum += board[i][i];
    }
    if (sum == 0) {
        return 1;
    }
    
    sum = 0;
    for (int i=0; i<ROWS; i++) {
        sum += board[i][ROWS-1-i];
    }
    if (sum == 0) {
        return 1;
    }
    
    /* No bingo */
    return 0;
}