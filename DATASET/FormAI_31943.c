//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 19
#define PELLET_NUM 114

char gameBoard[ROWS][COLS] = {
    "+-------------------+",
    "|                   |",
    "| +---+ +---+ +---+ |",
    "| |   | |   | |   | |",
    "| +   + +   + +   + |",
    "| |   | |   | |   | |",
    "| +---+ +---+ +---+ |",
    "|                   |",
    "| +---+ +---+ +---+ |",
    "| |   | |   | |   | |",
    "| +   + +   + +   + |",
    "| |   | |   | |   | |",
    "| +---+ +---+ +---+ |",
    "|                   |",
    "| +---+ +---+ +---+ |",
    "| |   | |   | |   | |",
    "| +   + +   + +   + |",
    "| |   | |   | |   | |",
    "| +---+ +---+ +---+ |",
    "|                   |",
    "+-------------------+"
};

int pelletCount = PELLET_NUM;

int playerRow = 10;
int playerCol = 9;

int ghosts[4][2] = {
    {9, 9},
    {9, 10},
    {10, 9},
    {10, 10}
};

int getRandomNumber(int min, int max) {
    int num;
    srand(time(NULL));
    num = (rand() % (max - min + 1)) + min;
    return num;
}

void moveGhosts() {
    int dir, row, col;
    for (int i = 0; i < 4; i++) {
        dir = getRandomNumber(1, 4);
        row = ghosts[i][0];
        col = ghosts[i][1];
        if (dir == 1 && gameBoard[row - 1][col] != '+') {
            ghosts[i][0]--;
        } else if (dir == 2 && gameBoard[row + 1][col] != '+') {
            ghosts[i][0]++;
        } else if (dir == 3 && gameBoard[row][col - 1] != '+') {
            ghosts[i][1]--;
        } else if (dir == 4 && gameBoard[row][col + 1] != '+') {
            ghosts[i][1]++;
        }
    }
}

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", gameBoard[i]);
    }
    printf("Pellets remaining: %d\n", pelletCount);
}

void movePlayer(char dir) {
    if (dir == 'w' && gameBoard[playerRow - 1][playerCol] != '+') {
        playerRow--;
    } else if (dir == 's' && gameBoard[playerRow + 1][playerCol] != '+') {
        playerRow++;
    } else if (dir == 'a' && gameBoard[playerRow][playerCol - 1] != '+') {
        playerCol--;
    } else if (dir == 'd' && gameBoard[playerRow][playerCol + 1] != '+') {
        playerCol++;
    }
}

int main() {
    char input;
    while (pelletCount > 0) {
        printBoard();
        printf("Enter direction (w,a,s,d): ");
        scanf("%c", &input);
        fflush(stdin); //clear input buffer
        movePlayer(input);
        moveGhosts();
        if (playerRow == ghosts[0][0] && playerCol == ghosts[0][1]) {
            printf("Game over! You were caught by a ghost.\n");
            return 0;
        }
        if (playerRow == ghosts[1][0] && playerCol == ghosts[1][1]) {
            printf("Game over! You were caught by a ghost.\n");
            return 0;
        }
        if (playerRow == ghosts[2][0] && playerCol == ghosts[2][1]) {
            printf("Game over! You were caught by a ghost.\n");
            return 0;
        }
        if (playerRow == ghosts[3][0] && playerCol == ghosts[3][1]) {
            printf("Game over! You were caught by a ghost.\n");
            return 0;
        }
        if (gameBoard[playerRow][playerCol] == '*') {
            pelletCount--;
            gameBoard[playerRow][playerCol] = ' ';
        }
    }
    printf("Congratulations! You won!\n");
    return 0;
}