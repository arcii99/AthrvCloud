//FormAI DATASET v1.0 Category: Memory Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printBoard(char board[ROWS][COLS], int hidden) {
    printf("  1 2 3 4\n");
    for(int i = 0; i < ROWS; i++) {
        printf("%d ", i+1);
        for(int j = 0; j < COLS; j++) {
            if(hidden && board[i][j] == 'X') {
                printf("X ");
            } else {
                printf("%c ", board[i][j]);
            }
            
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    char board[ROWS][COLS] = {
        {'A', 'A', 'B', 'B'},
        {'C', 'C', 'D', 'D'},
        {'E', 'E', 'F', 'F'},
        {'G', 'G', 'H', 'H'}
    };
    
    int revealed[ROWS][COLS] = {0};
    int numPairs = ROWS * COLS / 2;
    
    int guesses = 0;
    int numCorrect = 0;
    int maxGuesses = numPairs * 2;
    
    srand(time(NULL));
    for(int i = 0; i < ROWS * COLS; i++) {
        int row1 = rand() % ROWS;
        int col1 = rand() % COLS;
        int row2 = rand() % ROWS;
        int col2 = rand() % COLS;
        
        char temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;
    }
    
    printf("Welcome to Memory Game! There are %d pairs.\n", numPairs);
    
    printBoard(board, 1);
    
    while(numCorrect < numPairs) {
        int row1 = -1;
        int col1 = -1;
        int row2 = -1;
        int col2 = -1;
        
        printf("Enter your guess:");
        scanf("%d %d", &row1, &col1);
        
        while(row1 < 1 || row1 > ROWS || col1 < 1 || col1 > COLS || revealed[row1-1][col1-1] == 1) {
            printf("Invalid guess. Enter your guess:");
            scanf("%d %d", &row1, &col1);
        }
        
        revealed[row1-1][col1-1] = 1;
        guesses++;
        printBoard(board, 0);
        
        printf("Enter your guess:");
        scanf("%d %d", &row2, &col2);
        
        while(row2 < 1 || row2 > ROWS || col2 < 1 || col2 > COLS || revealed[row2-1][col2-1] == 1) {
            printf("Invalid guess. Enter your guess:");
            scanf("%d %d", &row2, &col2);
        }
        
        revealed[row2-1][col2-1] = 1;
        guesses++;
        
        if(board[row1-1][col1-1] == board[row2-1][col2-1]) {
            printf("Correct!\n");
            numCorrect++;
        } else {
            printf("Incorrect.\n");
            revealed[row1-1][col1-1] = 0;
            revealed[row2-1][col2-1] = 0;
        }
        
        if(guesses >= maxGuesses) {
            printf("Game over! You used all your guesses.\n");
            return 0;
        }
        
        printBoard(board, 0);
    }
    
    printf("Congratulations! You won in %d guesses.\n", guesses);
    
    return 0;
}