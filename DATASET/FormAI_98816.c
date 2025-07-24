//FormAI DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// function to print the board
void printboard(int board[BOARD_SIZE][BOARD_SIZE], int guess[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n--------------\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(guess[i][j]==1) { // if player already guessed the cell
                printf("%d ", board[i][j]);
            } else { // if player has not guessed the cell yet
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("--------------\n");
}

// function to check if the game is over
int is_gameover(int guess[BOARD_SIZE][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(guess[i][j]==0) { // if player has not guessed the cell yet
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE]; // the board containing the numbers
    int guess[BOARD_SIZE][BOARD_SIZE]; // the grid containing the guesses of the player

    // initialize both the board and guess table with 0
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = 0;
            guess[i][j] = 0;
        }
    }

    // randomly generate the numbers for the board
    srand(time(NULL));
    for(int num=1; num<=(BOARD_SIZE*BOARD_SIZE)/2; num++) {
        int count = 0;
        while(count<2) {
            int i = rand()%BOARD_SIZE;
            int j = rand()%BOARD_SIZE;
            if(board[i][j]==0) {
                board[i][j] = num;
                count++;
            }
        }
    }

    // print the empty board to the player
    printboard(board, guess);

    int moves = 0; // number of moves taken by the player
    while(!is_gameover(guess)) { // keep playing until game is over
        printf("Enter coordinates (row, column) to guess: ");
        int row, col;
        scanf("%d %d", &row, &col);

        // validate user input
        if(row<0 || row>=BOARD_SIZE || col<0 || col>=BOARD_SIZE) {
            printf("Invalid input, please try again\n");
            continue;
        } else if(guess[row][col]==1) {
            printf("Cell already guessed, please try again\n");
            continue;
        }

        // update the guess table with the player's guess
        guess[row][col] = 1;

        // check if the guess is correct or not
        if(board[row][col]==0) {
            printf("Incorrect guess\n");
        } else {
            printf("Correct guess\n");
        }

        // print the updated board to the player
        printboard(board, guess);
        moves++;
    }

    printf("Congratulations! You completed the game in %d moves.\n", moves);
    return 0;
}