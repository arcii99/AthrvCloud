//FormAI DATASET v1.0 Category: Game of Life ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

void display_board(char board[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(int x, int y, char board[][WIDTH]) {
    int count = 0;
    if (x > 0 && y > 0 && board[x-1][y-1] == 'X') count++;
    if (y > 0 && board[x][y-1] == 'X') count++;
    if (x < HEIGHT-1 && y > 0 && board[x+1][y-1] == 'X') count++;
    if (x > 0 && board[x-1][y] == 'X') count++;
    if (x < HEIGHT-1 && board[x+1][y] == 'X') count++;
    if (x > 0 && y < WIDTH-1 && board[x-1][y+1] == 'X') count++;
    if (y < WIDTH-1 && board[x][y+1] == 'X') count++;
    if (x < HEIGHT-1 && y < WIDTH-1 && board[x+1][y+1] == 'X') count++;
    return count;
}

int main() {
    char board[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = '-';
        }
    }
    board[1][2] = 'X';
    board[2][3] = 'X';
    board[3][1] = 'X';
    board[3][2] = 'X';
    board[3][3] = 'X';

    printf("Welcome to the Game of Life! Press enter to start.\n");
    getchar();
    int generation = 1;

    while (1) {
        printf("Generation %d\n", generation);
        display_board(board);
        getchar();

        char new_board[HEIGHT][WIDTH];
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                int num_neighbors = count_neighbors(i, j, board);
                if (board[i][j] == 'X') {
                    if (num_neighbors < 2 || num_neighbors > 3) {
                        new_board[i][j] = '-';
                    } else {
                        new_board[i][j] = 'X';
                    }
                } else {
                    if (num_neighbors == 3) {
                        new_board[i][j] = 'X';
                    } else {
                        new_board[i][j] = '-';
                    }
                }
            }
        }

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                board[i][j] = new_board[i][j];
            }
        }

        generation++;
    }
    return 0;
}