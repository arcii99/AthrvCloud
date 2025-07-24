//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

/* Function to check if a number is already present in the array */
int checkDuplicate(int arr[], int num, int index) {
    for(int i=0; i<index; i++) {
        if(arr[i] == num) {
            return 1;
        }
    }
    return 0;
}

/* Function to generate random numbers for the bingo card */
void generateCard(int arr[][COLS]) {
    srand(time(0));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int num = (j * 15) + (rand() % 15) + 1;
            /* Check if the number is already present in the same column */
            while(checkDuplicate(arr[i], num, j)) {
                num = (j * 15) + (rand() % 15) + 1;
            }
            arr[i][j] = num;
        }
    }
}

/* Function to print the bingo card */
void printCard(int arr[][COLS]) {
    printf("B   I   N   G   O\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%2d  ", arr[i][j]);
        }
        printf("\n");
    }
}

/* Function to check if a bingo has been formed */
int checkBingo(int arr[][COLS]) {
    int bingo = 0;
    /* Check rows */
    for(int i=0; i<ROWS; i++) {
        int count = 0;
        for(int j=0; j<COLS; j++) {
            if(arr[i][j] == -1) {
                count++;
            }
        }
        if(count == COLS) {
            bingo = 1;
            break;
        }
    }
    /* Check columns */
    for(int i=0; i<COLS; i++) {
        int count = 0;
        for(int j=0; j<ROWS; j++) {
            if(arr[j][i] == -1) {
                count++;
            }
        }
        if(count == ROWS) {
            bingo = 1;
            break;
        }
    }
    /* Check diagonals */
    if(arr[0][0] == -1 && arr[1][1] == -1 && arr[2][2] == -1 && arr[3][3] == -1 && arr[4][4] == -1) {
        bingo = 1;
    }
    if(arr[0][4] == -1 && arr[1][3] == -1 && arr[2][2] == -1 && arr[3][1] == -1 && arr[4][0] == -1) {
        bingo = 1;
    }
    return bingo;
}

/* Main function */
int main() {
    int card[ROWS][COLS];
    generateCard(card);
    printCard(card);
    
    int num;
    printf("\nEnter numbers (1-75) to mark in the card (0 to exit):\n");
    while(1) {
        scanf("%d", &num);
        if(num == 0) {
            break;
        }
        /* Mark the number in the card */
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(card[i][j] == num) {
                    card[i][j] = -1;
                }
            }
        }
        /* Print the updated card */
        printCard(card);
        /* Check if bingo has been formed */
        if(checkBingo(card)) {
            printf("Bingo!\n");
            break;
        }
    }
    return 0;
}