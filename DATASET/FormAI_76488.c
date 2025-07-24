//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 15
#define COLS 30

// Function prototypes
void displayGame(char board[][COLS], int playerPosX, int playerPosY);
void resetGame(char board[][COLS], int *playerPosX, int *playerPosY);
bool isWall(char board[][COLS], int x, int y);
bool isGhost(char board[][COLS], int x, int y);
bool isTreasure(char board[][COLS], int x, int y);
bool isValidMove(char board[][COLS], int x, int y);
void updateGame(char board[][COLS], int *playerPosX, int *playerPosY, int dx, int dy);

int main()
{
    char gameboard[ROWS][COLS] = {
        "##############################",
        "#.........###....##....######",
        "#.###.###.###.##.##.##......#",
        "#.#.....#...#..#..#..#####.#",
        "###.###.#.#.#.##.##......#.#",
        "#.#.#...#.#.#..#..###.###.#.",
        "#.#.#.#####.#.########...#.#",
        "#.#.#...#...#.#......#.#.#.#",
        "#.###.#.#.#.#####.###.#.#.#.",
        "#.....#.#.#.#.....#.###.#.#.",
        "####.#####.#####.#.#...#.#.",
        "#.....#...#...#.#.#.#.#.#.#.",
        "#.###.#.#.#####.#.#.#.#.#.#.",
        "#.#...#.#.#.....#.#.#.#.#.#.",
        "#.#.#####.#.#####.#.#.#.#.#.",
        "#.#.......#.......#.....#.#.",
        "#.#####.#.#.#.#.#.#.#####.#.",
        "#.#.....#.#.#.#.#.#.....#.#.",
        "#.#.###.###.#.#.#.#####.#.#.",
        "#.#.#.....#.#.#.#.....#...#.",
        "##.###.###.#.#.#.#####.#.#.#",
        "#.........#...#.......#.#.#.",
        "################################"
    };

    int row, col, playerX, playerY;
    char c;

    srand(time(NULL)); // seed random number generator

    // initialize player position randomly
    do {
        playerX = rand() % ROWS;
        playerY = rand() % COLS;
    } while(isWall(gameboard, playerX, playerY));

    resetGame(gameboard, &playerX, &playerY);

    // game loop
    do {
        displayGame(gameboard, playerX, playerY);
        printf("Enter a movement (w,a,s,d): ");
        scanf(" %c", &c);
        switch (c) {
            case 'w':
                updateGame(gameboard, &playerX, &playerY, -1, 0);
                break;
            case 'a':
                updateGame(gameboard, &playerX, &playerY, 0, -1);
                break;
            case 's':
                updateGame(gameboard, &playerX, &playerY, 1, 0);
                break;
            case 'd':
                updateGame(gameboard, &playerX, &playerY, 0, 1);
                break;
        }
    } while(c != 'q');

    printf("Thanks for playing!\n");
    return 0;
}

void displayGame(char board[][COLS], int playerPosX, int playerPosY)
{
    int row, col;
    for(row = 0; row < ROWS; row++) {
        for(col = 0; col < COLS; col++) {
            if(row == playerPosX && col == playerPosY) {
                printf("P");
            }
            else {
                printf("%c", board[row][col]);
            }
        }
        printf("\n");
    }
}

void resetGame(char board[][COLS], int *playerPosX, int *playerPosY)
{
    int row, col, treasureX, treasureY, ghost1X, ghost1Y, ghost2X, ghost2Y;

    // initialize treasure position randomly
    do {
        treasureX = rand() % ROWS;
        treasureY = rand() % COLS;
    } while(isWall(board, treasureX, treasureY) ||
            (treasureX == *playerPosX && treasureY == *playerPosY));

    // initialize ghost1 position randomly
    do {
        ghost1X = rand() % ROWS;
        ghost1Y = rand() % COLS;
    } while(isWall(board, ghost1X, ghost1Y) ||
            (ghost1X == *playerPosX && ghost1Y == *playerPosY) ||
            (ghost1X == treasureX && ghost1Y == treasureY));

    // initialize ghost2 position randomly
    do {
        ghost2X = rand() % ROWS;
        ghost2Y = rand() % COLS;
    } while(isWall(board, ghost2X, ghost2Y) ||
            (ghost2X == *playerPosX && ghost2Y == *playerPosY) ||
            (ghost2X == treasureX && ghost2Y == treasureY) ||
            (ghost2X == ghost1X && ghost2Y == ghost1Y));

    // update board array with objects
    board[*playerPosX][*playerPosY] = 'P';
    board[treasureX][treasureY] = '$';
    board[ghost1X][ghost1Y] = 'G';
    board[ghost2X][ghost2Y] = 'G';
}

bool isWall(char board[][COLS], int x, int y)
{
    return board[x][y] == '#';
}

bool isGhost(char board[][COLS], int x, int y)
{
    return board[x][y] == 'G';
}

bool isTreasure(char board[][COLS], int x, int y)
{
    return board[x][y] == '$';
}

bool isValidMove(char board[][COLS], int x, int y)
{
    return !isWall(board, x, y) &&
           x >= 0 && x < ROWS &&
           y >= 0 && y < COLS;
}

void updateGame(char board[][COLS], int *playerPosX, int *playerPosY, int dx, int dy)
{
    int newX = *playerPosX + dx;
    int newY = *playerPosY + dy;

    if(!isValidMove(board, newX, newY)) {
        printf("You hit a wall! Try again.\n");
    }
    else {
        board[*playerPosX][*playerPosY] = ' ';
        if(isGhost(board, newX, newY)) {
            printf("You were caught by a ghost! Game over.\n");
            exit(0);
        }
        else if(isTreasure(board, newX, newY)) {
            printf("Congratulations, you found the treasure! You win!\n");
            exit(0);
        }
        else {
            *playerPosX = newX;
            *playerPosY = newY;
            board[*playerPosX][*playerPosY] = 'P';
        }
    }
}