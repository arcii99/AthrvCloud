//FormAI DATASET v1.0 Category: Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_GUESSES 10

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int i, j, guess_row, guess_col, num_guesses = 0;
    srand(time(NULL));

    //populate board with random characters
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 26 + 'A';
        }
    }

    while(num_guesses < MAX_GUESSES) {
        //print board with '*' for unguessed squares
        printf("\n");
        for(i = 0; i < BOARD_SIZE; i++) {
            for(j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == '*') {
                    printf("* ");
                }
                else {
                    printf("%c ", board[i][j]);
                }
            }
            printf("\n");
        }

        //get user guess
        printf("\nEnter row number (0-9): ");
        scanf("%d", &guess_row);
        printf("Enter column number (0-9): ");
        scanf("%d", &guess_col);

        if(board[guess_row][guess_col] == '*') {
            printf("\nCorrect!");
            board[guess_row][guess_col] = ' ';
        }
        else {
            printf("\nIncorrect, try again.");
        }

        num_guesses++;
    }

    //print final board
    printf("\nFinal Board:\n");
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}