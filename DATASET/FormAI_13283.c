//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    // initialize array of bingo card
    int card[ROWS][COLS] = {0};
    
    // set seed for random number generator
    srand(time(NULL));
    
    // fill in first column with random numbers between 1 and 15
    for (int i = 0; i < ROWS; i++) {
        int num = rand() % 15 + 1;
        card[i][0] = num;
    }
    
    // fill in second column with random numbers between 16 and 30, ensuring no duplicates
    for (int i = 0; i < ROWS; i++) {
        int num = rand() % 15 + 16;
        while (num == card[i][0]) {
            num = rand() % 15 + 16;
        }
        card[i][1] = num;
    }
    
    // fill in third column with random numbers between 31 and 45, ensuring no duplicates
    for (int i = 0; i < ROWS; i++) {
        int num = rand() % 15 + 31;
        while (num == card[i][0] || num == card[i][1]) {
            num = rand() % 15 + 31;
        }
        card[i][2] = num;
    }
    
    // fill in fourth column with random numbers between 46 and 60, ensuring no duplicates
    for (int i = 0; i < ROWS; i++) {
        int num = rand() % 15 + 46;
        while (num == card[i][0] || num == card[i][1] || num == card[i][2]) {
            num = rand() % 15 + 46;
        }
        card[i][3] = num;
    }
    
    // fill in fifth column with random numbers between 61 and 75, ensuring no duplicates
    for (int i = 0; i < ROWS; i++) {
        int num = rand() % 15 + 61;
        while (num == card[i][0] || num == card[i][1] || num == card[i][2] || num == card[i][3]) {
            num = rand() % 15 + 61;
        }
        card[i][4] = num;
    }
    
    // print out bingo card
    printf("B I N G O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}