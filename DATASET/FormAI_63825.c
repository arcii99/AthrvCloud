//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initiate an empty Bingo board
    int board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    // Shuffle and place the numbers on the board
    int numList[MAX_NUM];
    for (int i = 0; i < MAX_NUM; i++) {
        numList[i] = i + 1;
    }
    for (int i = 0; i < MAX_NUM; i++) {
        int randIndex = rand() % MAX_NUM;
        int temp = numList[i];
        numList[i] = numList[randIndex];
        numList[randIndex] = temp;
    }
    int index = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = numList[index++];
        }
    }

    // Print the empty board
    printf("Welcome to the Bingo Simulator!\n\n");
    printf("Here is your Bingo board:\n\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }

    // Play Bingo until a winner is declared
    int gameOver = 0;
    while (!gameOver) {
        int pickedNum = rand() % MAX_NUM + 1;
        printf("The caller has drawn the number: %d\n", pickedNum);

        // Check for matching numbers on the board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == pickedNum) {
                    board[i][j] = 0;
                }
            }
        }

        // Check for Bingo
        int bingo = 0;
        for (int i = 0; i < ROWS; i++) {
            // Check for a horizontal Bingo
            if (board[i][0] == 0 && board[i][1] == 0 && board[i][2] == 0 && board[i][3] == 0 && board[i][4] == 0) {
                bingo = 1;
                printf("\nBingo! You have won with a horizontal line.\n");
                gameOver = 1;
                break;
            }
            // Check for a vertical Bingo
            else if (board[0][i] == 0 && board[1][i] == 0 && board[2][i] == 0 && board[3][i] == 0 && board[4][i] == 0) {
                bingo = 1;
                printf("\nBingo! You have won with a vertical line.\n");
                gameOver = 1;
                break;
            }
            // Check for a diagonal Bingo
            else if (board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 && board[3][3] == 0 && board[4][4] == 0) {
                bingo = 1;
                printf("\nBingo! You have won with a diagonal line.\n");
                gameOver = 1;
                break;
            }
            else if (board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 && board[3][1] == 0 && board[4][0] == 0) {
                bingo = 1;
                printf("\nBingo! You have won with a diagonal line.\n");
                gameOver = 1;
                break;
            }
        }
        if (bingo) {
            printf("\nCongratulations! You have won the game of Bingo!\n");
        }
    }

    return 0;
}