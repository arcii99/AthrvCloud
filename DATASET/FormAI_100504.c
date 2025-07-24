//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Function: printBoard
 * --------------------
 * This function prints out the Bingo board in a
 * post-apocalyptic style.
 *
 * board: The 5x5 Bingo board to print.
 */
void printBoard(int board[][5]){
    printf(" _____ _____ _____ _____ _____\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(board[i][j] == -1){
                printf("|%c%c%c%c%c", 'X', 'X', 'X', 'X', 'X');
            }
            else{
                printf("|%c%c%c%c%c", 'O', 'O', 'O', 'O', 'O');
            }
        }
        printf("|\n");
        printf("|_____|_____|_____|_____|_____|\n");
    }
}

/**
 * Function: checkHorizontal
 * -------------------------
 * This function checks if a horizontal line on the board is complete.
 *
 * board: The 5x5 Bingo board to check.
 *
 * returns: 1 if a horizontal line is complete, 0 otherwise.
 */
int checkHorizontal(int board[][5]){
    for(int i = 0; i < 5; i++){
        int complete = 1;
        for(int j = 0; j < 5; j++){
            if(board[i][j] != -1){
                complete = 0;
                break;
            }
        }
        if(complete) return 1;
    }
    return 0;
}

/**
 * Function: checkVertical
 * -----------------------
 * This function checks if a vertical line on the board is complete.
 *
 * board: The 5x5 Bingo board to check.
 *
 * returns: 1 if a vertical line is complete, 0 otherwise.
 */
int checkVertical(int board[][5]){
    for(int i = 0; i < 5; i++){
        int complete = 1;
        for(int j = 0; j < 5; j++){
            if(board[j][i] != -1){
                complete = 0;
                break;
            }
        }
        if(complete) return 1;
    }
    return 0;
}

/**
 * Function: checkDiagonal
 * -----------------------
 * This function checks if a diagonal line on the board is complete.
 *
 * board: The 5x5 Bingo board to check.
 *
 * returns: 1 if a diagonal line is complete, 0 otherwise.
 */
int checkDiagonal(int board[][5]){
    int complete = 1;
    for(int i = 0; i < 5; i++){
        if(board[i][i] != -1){
            complete = 0;
            break;
        }
    }
    if(complete) return 1;

    complete = 1;
    for(int i = 0; i < 5; i++){
        if(board[i][4-i] != -1){
            complete = 0;
            break;
        }
    }
    if(complete) return 1;

    return 0;
}

int main(){
    // Initialize the Bingo board with random values between 1 and 75
    srand(time(NULL));
    int board[5][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            board[i][j] = rand() % 75 + 1;
        }
    }

    // Mark the center square as already called
    board[2][2] = -1;

    // Print out the initial state of the board
    printBoard(board);
    printf("Get ready to play Bingo in the post-apocalyptic world!\n");

    // Call numbers until the game is won
    int calls = 0;
    while(1){
        calls++;
        int nextCall = rand() % 75 + 1;
        printf("The next number is %d.\n", nextCall);

        // Mark any matching numbers on the board as already called
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(board[i][j] == nextCall){
                    board[i][j] = -1;
                }
            }
        }

        // Check if the game has been won
        if(checkHorizontal(board) || checkVertical(board) || checkDiagonal(board)){
            printf("Bingo! The game has been won in %d calls.\n", calls);
            break;
        }

        // Print out the updated state of the board
        printBoard(board);
    }

    return 0;
}