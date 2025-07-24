//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 10
#define SHIP_ROW 4
#define SHIP_COLUMN 9

void drawBoard(char board[ROWS][COLUMNS])
{
    printf("   ");
    for (int i = 0; i < COLUMNS; i++) {
        printf(" %d ", i+1);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%c ", 'a' + i);
        for (int j = 0; j < COLUMNS; j++) {
            printf("[");
            if (board[i][j] == 'X') {
                printf("X");
            } else {
                printf(" ");
            }
            printf("]");
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    char board[ROWS][COLUMNS] = {{' '}};
    srand(time(NULL));

    int shipLocation = rand() % COLUMNS;
    board[SHIP_ROW][shipLocation] = 'S';

    int moveCount = 0;
    bool shipHit = false;
    bool shipSunk = false;

    printf("WELCOME TO SPACE INVADERS\n");
    drawBoard(board);

    while (!shipSunk) {
        char move[3] = {' ', ' ', '\0'};
        printf("Enter your move (ex. b5): ");
        fgets(move, 3, stdin);
        
        int row = move[0] - 'a';
        int column = move[1] - '1';

        if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
            printf("Invalid move, please try again.\n");
            continue;
        }

        if (board[row][column] == 'X') {
            printf("You already hit that spot, please try again.\n");
            continue;
        }

        moveCount++;

        if (row == SHIP_ROW && column == shipLocation) {
            printf("HIT!\n");
            board[row][column] = 'X';
            shipHit = true;
        } else {
            printf("MISS!\n");
        }

        if (shipHit) {
            bool allHits = true;
            for (int i = 0; i < COLUMNS; i++) {
                if (board[SHIP_ROW][i] != 'X') {
                    allHits = false;
                    break;
                }
            }

            if (allHits) {
                printf("YOU SUNK THE SHIP!\n");
                shipSunk = true;
            }
        }

        drawBoard(board);
    }

    printf("You took %d moves to sink the ship!\n", moveCount);

    return 0;
}