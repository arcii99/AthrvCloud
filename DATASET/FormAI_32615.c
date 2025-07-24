//FormAI DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

void initBoard(int board[][WIDTH]);
void drawBoard(int board[][WIDTH]);
void updateBoard(int board[][WIDTH]);
int countNeighbours(int board[][WIDTH], int x, int y);

int main() {
    srand(time(NULL)); // set the seed for random generation

    int board[HEIGHT][WIDTH];
    initBoard(board);
    drawBoard(board);

    while (1) {
        updateBoard(board);
        drawBoard(board);
        usleep(100000); // sleep for 100ms
    }

    return 0;
}

void initBoard(int board[][WIDTH]) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            board[y][x] = rand() % 2; // randomly assign 0 or 1
        }
    }
}

void drawBoard(int board[][WIDTH]) {
    system("clear"); // clear the console
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", board[y][x] == 1 ? '#' : ' '); // print the board
        }
        printf("\n");
    }
}

void updateBoard(int board[][WIDTH]) {
    int newBoard[HEIGHT][WIDTH];
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int neighbours = countNeighbours(board, x, y);
            if (board[y][x] == 1) { // if alive
                if (neighbours < 2) { // underpopulation
                    newBoard[y][x] = 0;
                } else if (neighbours > 3) { // overpopulation
                    newBoard[y][x] = 0;
                } else { // survive
                    newBoard[y][x] = 1;
                }
            } else { // if dead
                if (neighbours == 3) { // reproduction
                    newBoard[y][x] = 1;
                } else { // stay dead
                    newBoard[y][x] = 0;
                }
            }
        }
    }
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            board[y][x] = newBoard[y][x]; // update the board
        }
    }
}

int countNeighbours(int board[][WIDTH], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nx = (x + i + WIDTH) % WIDTH; // handle edge wrapping
            int ny = (y + j + HEIGHT) % HEIGHT;
            count += board[ny][nx]; // accumulate neighbours
        }
    }
    count -= board[y][x]; // subtract itself
    return count;
}