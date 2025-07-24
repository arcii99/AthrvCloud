//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5   // constant for size of bingo card
#define MAX_NUM 75  // constant for maximum number in bingo game

// Function to generate a random number between 1 and MAX_NUM
int generateNumber() {
    return (rand() % MAX_NUM) + 1;
}

// Function to initialize the bingo card with unique random numbers
void initCard(int card[][SIZE]) {
    int i, j;
    int nums[MAX_NUM] = {0};  // array to keep track of used numbers
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            int num;
            do {
                num = generateNumber();
            } while (nums[num-1] != 0);  // check if number has already been used
            nums[num-1] = 1;  // mark number as used
            card[i][j] = num;
        }
    }
}

// Function to print the bingo card
void printCard(int card[][SIZE]) {
    int i, j;
    printf(" B  I  N  G  O\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (card[i][j] < 10)
                printf(" %d ", card[i][j]);
            else
                printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is in a column
int checkColumn(int card[][SIZE], int col, int num) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (card[i][col] == num)
            return 1;
    }
    return 0;
}

// Function to check if a number is in a row
int checkRow(int card[][SIZE], int row, int num) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (card[row][i] == num)
            return 1;
    }
    return 0;
}

// Function to check if a number is in a diagonal
int checkDiagonal(int card[][SIZE], int num) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (card[i][i] == num)
            return 1;
        if (card[i][SIZE-i-1] == num)
            return 1;
    }
    return 0;
}

// Function to check if all numbers in a row are marked
int rowMarked(int card[][SIZE], int row) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (card[row][i] > 0)  // check if number is marked
            return 0;
    }
    return 1;
}

// Function to check if all numbers in a column are marked
int colMarked(int card[][SIZE], int col) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (card[i][col] > 0)  // check if number is marked
            return 0;
    }
    return 1;
}

// Function to check if all numbers in a diagonal are marked
int diagonalMarked(int card[][SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (card[i][i] > 0)  // check if number in first diagonal is marked
            break;
    }
    if (i == SIZE)  // all numbers in first diagonal are marked
        return 1;
    
    for (i = 0; i < SIZE; i++) {
        if (card[i][SIZE-i-1] > 0)  // check if number in second diagonal is marked
            break;
    }
    if (i == SIZE)  // all numbers in second diagonal are marked
        return 1;
    
    return 0;
}

// Main function
int main() {
    int card[SIZE][SIZE];  
    int i, j;
    int num_calls = 0;  // variable to keep track of number of bingo calls
    int nums[MAX_NUM] = {0};  // array to keep track of called numbers
    
    srand(time(NULL));  // seed the random number generator
    
    initCard(card);  // initialize the bingo card with random numbers
    
    printf("Here is your bingo card!\n\n");
    printCard(card);  // print the bingo card
    
    // Game loop
    while (1) {
        int num;
        do {
            num = generateNumber();  // generate a random number
        } while (nums[num-1] != 0);  // check if number has already been called
        nums[num-1] = 1;  // mark number as called
        num_calls++;
        printf("\nCalled number: %d\n", num);
        
        // Check if number is on the card and mark it
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (card[i][j] == num) {
                    card[i][j] = 0;  // mark number as called
                }
            }
        }
        
        // Check for bingo
        for (i = 0; i < SIZE; i++) {
            if (rowMarked(card, i)) {
                printf("\nBINGO! You got a full row!\n");
                printf("Number of calls: %d\n", num_calls);
                return 0;
            }
            if (colMarked(card, i)) {
                printf("\nBINGO! You got a full column!\n");
                printf("Number of calls: %d\n", num_calls);
                return 0;
            }
        }
        if (diagonalMarked(card)) {
            printf("\nBINGO! You got a full diagonal!\n");
            printf("Number of calls: %d\n", num_calls);
            return 0;
        }
    }
    
    return 0;
}