//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {

    // welcome message
    printf("Welcome to the Ephemeral Maze Game!\n");
    printf("You are the red square and you need to reach the exit (E).\n");
    printf("But be careful, there are obstacles (O) that will block your way.\n\n");

    // initialize game board
    char board[10][10] = {
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#','O','#',' ','#',' ','#','#',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#','#','#',' ','#','#','#',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ','#','#'},
        {'#','#',' ','#','#','#','#',' ',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#','E','#','#','#','#','#','#',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    };

    // initialize player position
    int playerX = 1;
    int playerY = 1;
    board[playerY][playerX] = 'R';

    // initialize exit position
    int exitX = 8;
    int exitY = 8;
    board[exitY][exitX] = 'E';

    // initialize obstacle positions
    srand(time(NULL));
    int obstacleX = rand() % 8 + 1;
    int obstacleY = rand() % 8 + 1;
    board[obstacleY][obstacleX] = 'O';

    // game loop
    int moveCount = 0;
    while (1) {

        // display game board
        printf("\n");
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                printf("%c ", board[y][x]);
            }
            printf("\n");
        }
        printf("\n");

        // check if player has reached the exit
        if (playerX == exitX && playerY == exitY) {
            printf("Congratulations, you made it to the exit!\n");
            printf("Total moves: %d\n", moveCount);
            break;
        }

        // prompt user for input
        printf("Enter move (up, down, left, right): ");
        char input[10];
        fgets(input, 10, stdin);

        // handle input
        if (strcmp(input, "up\n") == 0) {
            if (board[playerY-1][playerX] == ' ') {
                board[playerY][playerX] = ' ';
                playerY--;
                board[playerY][playerX] = 'R';
                moveCount++;
            } else {
                printf("Invalid move!\n");
            }
        } else if (strcmp(input, "down\n") == 0) {
            if (board[playerY+1][playerX] == ' ') {
                board[playerY][playerX] = ' ';
                playerY++;
                board[playerY][playerX] = 'R';
                moveCount++;
            } else {
                printf("Invalid move!\n");
            }
        } else if (strcmp(input, "left\n") == 0) {
            if (board[playerY][playerX-1] == ' ') {
                board[playerY][playerX] = ' ';
                playerX--;
                board[playerY][playerX] = 'R';
                moveCount++;
            } else {
                printf("Invalid move!\n");
            }
        } else if (strcmp(input, "right\n") == 0) {
            if (board[playerY][playerX+1] == ' ') {
                board[playerY][playerX] = ' ';
                playerX++;
                board[playerY][playerX] = 'R';
                moveCount++;
            } else {
                printf("Invalid move!\n");
            }
        } else {
            printf("Invalid input!\n");
        }

        // move obstacle randomly
        int random = rand() % 4;
        if (random == 0) {
            if (board[obstacleY-1][obstacleX] == ' ') {
                board[obstacleY][obstacleX] = ' ';
                obstacleY--;
                board[obstacleY][obstacleX] = 'O';
            }
        } else if (random == 1) {
            if (board[obstacleY+1][obstacleX] == ' ') {
                board[obstacleY][obstacleX] = ' ';
                obstacleY++;
                board[obstacleY][obstacleX] = 'O';
            }
        } else if (random == 2) {
            if (board[obstacleY][obstacleX-1] == ' ') {
                board[obstacleY][obstacleX] = ' ';
                obstacleX--;
                board[obstacleY][obstacleX] = 'O';
            }
        } else if (random == 3) {
            if (board[obstacleY][obstacleX+1] == ' ') {
                board[obstacleY][obstacleX] = ' ';
                obstacleX++;
                board[obstacleY][obstacleX] = 'O';
            }
        }

    }

    return 0;
}