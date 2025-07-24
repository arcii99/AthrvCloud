//FormAI DATASET v1.0 Category: Memory Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int main() {
    int game_board[MAX_SIZE][MAX_SIZE];
    int row, col, row2, col2, val, val2;
    int i, j, count=MAX_SIZE*MAX_SIZE/2, matches=0;

    // initialize game board with random numbers
    srand(time(0));
    for(i=0; i<MAX_SIZE; i++) {
        for(j=0; j<MAX_SIZE; j++) {
            game_board[i][j] = rand() % count + 1;
            count--;
        }
    }

    // start game
    printf("Welcome to the Memory Game!\n");
    while(matches < MAX_SIZE*MAX_SIZE/2) {
        printf("\n");
        // display game board
        for(i=0; i<MAX_SIZE; i++) {
            for(j=0; j<MAX_SIZE; j++) {
                if(game_board[i][j] < 0) { // already matched
                    printf("[ ]");
                } else { // hidden value
                    printf("[%d]", game_board[i][j]);
                }
            }
            printf("\n");
        }

        // get user input for first card
        printf("Enter row and column of first card:\n");
        scanf("%d %d", &row, &col);
        val = game_board[row][col];
        while(val < 0) { // already matched
            printf("This card has already been matched. Please choose another card.\n");
            scanf("%d %d", &row, &col);
            val = game_board[row][col];
        }

        // flip first card over
        game_board[row][col] = -1;

        // get user input for second card
        printf("Enter row and column of second card:\n");
        scanf("%d %d", &row2, &col2);
        val2 = game_board[row2][col2];
        while(val2 < 0 || (row2==row && col2==col)) { // already matched or same card
            printf("This card has already been matched or is the same as the first card. Please choose another card.\n");
            scanf("%d %d", &row2, &col2);
            val2 = game_board[row2][col2];
        }

        // flip second card over
        game_board[row2][col2] = -1;

        // check if match
        if(val == val2) {
            printf("You found a match!\n");
            matches++;
        } else {
            printf("Sorry, no match. Try again.\n");
            // flip cards back over
            game_board[row][col] = val;
            game_board[row2][col2] = val2;
        }
    }

    // game over
    printf("\nCongratulations, you matched all the cards!\n");
    return 0;
}