//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void initializeBoard(int board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard(int board[ROWS][COLS]) {
    printf("  B  I  N  G  O\n");
    for(int i = 0; i < ROWS; i++) {
        printf("%c ", 'A' + i);
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == 0) {
                printf("| | ");
            } else {
                printf("|%2d ", board[i][j]);
            }
        }
        printf("| %c\n", 'A' + i);
    }
    printf("  B  I  N  G  O\n");
}

int checkForBingo(int board[ROWS][COLS]) {
    int sum;
    
    // Check rows for bingo
    for(int i = 0; i < ROWS; i++) {
        sum = 0;
        for(int j = 0; j < COLS; j++) {
            sum += board[i][j];
        }
        if(sum == 0) {
            return 1;
        }
    }
    
    // Check columns for bingo
    for(int i = 0; i < COLS; i++) {
        sum = 0;
        for(int j = 0; j < ROWS; j++) {
            sum += board[j][i];
        }
        if(sum == 0) {
            return 1;
        }
    }
    
    // Check diagonals for bingo
    sum = 0;
    for(int i = 0; i < ROWS; i++) {
        sum += board[i][i];
    }
    if(sum == 0) {
        return 1;
    }
    
    sum = 0;
    for(int i = 0; i < ROWS; i++) {
        sum += board[i][ROWS - i - 1];
    }
    if(sum == 0) {
        return 1;
    }
    
    // No bingo found
    return 0;
}

int main() {
    srand(time(NULL));
    
    int board[ROWS][COLS];
    initializeBoard(board);
    
    // Populate board with random numbers
    int used[26] = {0};
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int num;
            do {
                num = rand() % 25 + 1;
            } while(used[num]);
            board[i][j] = num;
            used[num] = 1;
        }
    }
    
    int turns = 0;
    printf("Welcome to Bingo Simulator!\n");
    printf("Here is your board:\n");
    printBoard(board);
    
    while(1) {
        turns++;
        int nextNum;
        
        // Generate a new number
        do {
            nextNum = rand() % 25 + 1;
        } while(used[nextNum]);
        used[nextNum] = 1;
        
        // Mark number on board
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(board[i][j] == nextNum) {
                    board[i][j] = 0;
                    break;
                }
            }
        }
        
        printf("Next number: %d\n", nextNum);
        printf("Board after turn %d:\n", turns);
        printBoard(board);
        
        if(checkForBingo(board)) {
            printf("Bingo! You won in %d turns.\n", turns);
            break;
        }
    }
    
    return 0;
}