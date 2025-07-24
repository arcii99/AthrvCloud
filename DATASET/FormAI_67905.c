//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to check if a number is already present in the board
int check_board(int board[][COLS], int number) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == number) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to print the board
void print_board(int board[][COLS]) {
    printf("\n***********************\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == -1) {
                printf("|  ");
            }
            else {
                printf("| %d", board[i][j]);
            }
        }
        printf("|\n***********************\n");
    }
}

int main() {
    int board[ROWS][COLS];
    int numbers[ROWS*COLS];
    int count = 0;

    // Initializing the board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = -1;
        }
    }

    // Generating random numbers between 1 to 25 and storing in an array
    srand(time(NULL));
    for(int i=0; i<ROWS*COLS; i++) {
        int number = rand() % 25 + 1;
        if(!check_board(board, number)) {
            numbers[i] = number;
            count++;
        }
        else {
            i--;
        }
    }

    // Printing the random numbers generated
    printf("\nThe list of random numbers generated are:\n");
    for(int i=0; i<count; i++) {
        printf("%d ", numbers[i]);
        if((i+1) % 5 == 0) {
            printf("\n");
        }
    }

    // Main game loop
    int turn = 1;
    while(1) {
        printf("\n\n********** Turn %d **********\n\n", turn);
        printf("Current Board:\n\n");
        print_board(board);

        // Generating a random number and checking if it's already present in the board
        int number = rand() % 25 + 1;
        if(check_board(board, number)) {
            continue;
        }

        // Asking the user if they have the number on their card
        char response;
        printf("\nDo you have the number %d on your Bingo card? (y/n) ", number);
        scanf(" %c", &response);

        // Updating the board and checking for a Bingo
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(board[i][j] == number) {
                    board[i][j] = -1;
                    printf("\n\nOh no! The number %d was on your card, but it got marked off.\n\n", number);
                }
            }
        }
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(board[i][j] != -1) {
                    goto endloop;
                }
            }
        }
        printf("\n\n***********************\n");
        printf("Congratulations! You got a BINGO!\n");
        printf("***********************\n");
        break;
        endloop:

        // Updating the board
        if(response == 'y') {
            for(int i=0; i<ROWS; i++) {
                for(int j=0; j<COLS; j++) {
                    if(board[i][j] == number) {
                        board[i][j] = -1;
                    }
                }
            }
        }

        // Checking for a Bingo
        int row_sum = 0, col_sum = 0, diag_sum1 = 0, diag_sum2 = 0;
        for(int i=0; i<ROWS; i++) {
            row_sum = 0, col_sum = 0;
            for(int j=0; j<COLS; j++) {
                row_sum += board[i][j];
                col_sum += board[j][i];
                if(i == j) {
                    diag_sum1 += board[i][j];
                }
                if(i+j == ROWS-1) {
                    diag_sum2 += board[i][j];
                }
            }
            if(row_sum == -COLS || col_sum == -ROWS) {
                printf("\n\n***********************\n");
                printf("Congratulations! You got a BINGO!\n");
                printf("***********************\n");
                goto endgame;
            }
        }
        if(diag_sum1 == -ROWS || diag_sum2 == -ROWS) {
            printf("\n\n***********************\n");
            printf("Congratulations! You got a BINGO!\n");
            printf("***********************\n");
            goto endgame;
        }

        turn++;
    }
    endgame:
    return 0;
}