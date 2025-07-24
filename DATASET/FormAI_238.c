//FormAI DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[10][10];
    int playerOneScore, playerTwoScore;
    int playerOneRow, playerOneCol, playerTwoRow, playerTwoCol;
    char playerOneName[20], playerTwoName[20];
    int turn = 1;

    // initialize board
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = 0;
        }
    }

    // get player names
    printf("Welcome to the C Table Game!\n\n");
    printf("Player 1, please enter your name: ");
    scanf("%s", playerOneName);
    printf("Player 2, please enter your name: ");
    scanf("%s", playerTwoName);

    // randomly place players on board
    srand(time(NULL));
    playerOneRow = rand() % 10;
    playerOneCol = rand() % 10;
    board[playerOneRow][playerOneCol] = 1;

    do {
        playerTwoRow = rand() % 10;
        playerTwoCol = rand() % 10;
    } while (playerOneRow == playerTwoRow && playerOneCol == playerTwoCol);
    board[playerTwoRow][playerTwoCol] = 2;

    // game loop
    while (1) {
        if (turn % 2 == 1) {
            // player one's turn
            printf("%s, it's your turn!\n", playerOneName);
            printf("Enter the row and column numbers you want to place your piece: ");
            scanf("%d %d", &playerOneRow, &playerOneCol);
            board[playerOneRow][playerOneCol] = 1;

            // calculate score
            playerOneScore = 0;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (board[i][j] == 2) {
                        if ((i == playerOneRow - 1 && j == playerOneCol) ||
                            (i == playerOneRow + 1 && j == playerOneCol) ||
                            (i == playerOneRow && j == playerOneCol - 1) ||
                            (i == playerOneRow && j == playerOneCol + 1)) {
                            playerOneScore++;
                            board[i][j] = 0;
                        }
                    }
                }
            }

            printf("Score: %d\n", playerOneScore);
            turn++;
        } else {
            // player two's turn
            printf("%s, it's your turn!\n", playerTwoName);
            printf("Enter the row and column numbers you want to place your piece: ");
            scanf("%d %d", &playerTwoRow, &playerTwoCol);
            board[playerTwoRow][playerTwoCol] = 2;

            // calculate score
            playerTwoScore = 0;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (board[i][j] == 1) {
                        if ((i == playerTwoRow - 1 && j == playerTwoCol) ||
                            (i == playerTwoRow + 1 && j == playerTwoCol) ||
                            (i == playerTwoRow && j == playerTwoCol - 1) ||
                            (i == playerTwoRow && j == playerTwoCol + 1)) {
                            playerTwoScore++;
                            board[i][j] = 0;
                        }
                    }
                }
            }

            printf("Score: %d\n", playerTwoScore);
            turn++;
        }
    }

    return 0;
}