//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define ROWS 10
#define COLS 20
#define SPEED 100000

char grid[ROWS][COLS];

void prepareGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == ROWS - 1) grid[i][j] = '_';
            else if (j == COLS - 1) grid[i][j] = '|';
            else grid[i][j] = ' ';
        }
    }
}

void drawGrid() {
    system("clear");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }

        printf("\n");
    }
}

void insertSnake(int row, int col) {
    grid[row][col] = '*';
}

int main() {
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int headRow = ROWS / 2;
    int headCol = COLS / 2;
    int tailRow = headRow;
    int tailCol = headCol - 2;
    int input, len = 0;

    prepareGrid();
    insertSnake(headRow, headCol);
    insertSnake(tailRow, tailCol);

    while (1) {
        drawGrid();
        usleep(SPEED);

        input = getchar();

        if (input == 'q') break;

        switch (input) {
            case 'w':
                headRow--;
                break;
            case 'a':
                headCol--;
                break;
            case 's':
                headRow++;
                break;
            case 'd':
                headCol++;
                break;
        }

        len++;

        if (headRow < 0 || headRow >= ROWS - 1 || headCol < 0 || headCol >= COLS - 1) break;

        insertSnake(headRow, headCol);

        if (len == 10) {
            len = 0;
            grid[tailRow][tailCol] = ' ';
            switch (input) {
                case 'w':
                    tailRow--;
                    break;
                case 'a':
                    tailCol--;
                    break;
                case 's':
                    tailRow++;
                    break;
                case 'd':
                    tailCol++;
                    break;
            }
        } else {
            insertSnake(tailRow, tailCol);
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return 0;
}