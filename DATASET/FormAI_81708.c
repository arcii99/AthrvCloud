//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 5
#define COLS 5 
#define NUM_OF_BALLS 75

#define true 1
#define false 0

/* Function Prototypes */
void initBoard(int board[ROWS][COLS]);
void printBoard(int board[ROWS][COLS]);
int generateRandomNumber(int upperLimit);
void playGame(int board[ROWS][COLS]);

int main()
{
    srand(time(NULL));
    printf("\t\tBINGO SIMULATOR\n");
    
    int board[ROWS][COLS];
    initBoard(board);
    printBoard(board);
    
    char playAgain = 'N';
    do {
        playGame(board);
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
    } while(playAgain == 'Y');
    
    printf("\n\t\tTHANKS FOR PLAYING BINGO SIMULATOR!\n");
    return 0;
}

/*
 * Initialize board to be completely empty
 * 'X' indicates that the spot on the board is marked/selected
 */
void initBoard(int board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLS; ++j) {
            board[i][j] = 0;
        }
    }
}

void printBoard(int board[ROWS][COLS]) {
    printf("\n================== BINGO BOARD ==================\n");
    printf("   B    I    N    G    O\n");
    printf("----------------------------\n");
    for(int i = 0; i < ROWS; ++i) {
        printf("| ");
        for(int j = 0; j < COLS; ++j) {
            if(board[i][j] == 0) {
                printf("%2c ", 'X');
            } else {
                printf("%2d ", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("======================\n");
}

int generateRandomNumber(int upperLimit) {
    return rand() % upperLimit + 1;
}

void playGame(int board[ROWS][COLS]) {
    printf("\n================== LET'S PLAY! ==================\n");
    int ballsSelected[NUM_OF_BALLS];
    int ballCounter = 0;
    initBoard(board);

    while(ballCounter != NUM_OF_BALLS) {
        int randomNum = generateRandomNumber(NUM_OF_BALLS);
        if(ballsSelected[randomNum]) {
            // This ball has already been selected
            continue;
        }
        ballsSelected[randomNum] = true;
        printf("\nNext ball: %d\n", randomNum+1);

        // Mark the corresponding spot on the board
        int boardPositionRow = randomNum / 15;
        int boardPositionCol = (randomNum % 15) / 3;
        board[boardPositionRow][boardPositionCol] = randomNum+1;

        printBoard(board);

        // Check if the player has won
        int won = true;
        for(int i = 0; i < ROWS; ++i) {
            // Check each row
            won = true;
            for(int j = 0; j < COLS; ++j) {
                if(board[i][j] == 0) {
                    won = false;
                    break;
                }
            }
            if(won) {
                break;
            }
        }
        if(won) {
            printf("\nCongratulations! You have won the game!\n");
            break;
        }
    }
    printf("\n(end of game)\n");
}