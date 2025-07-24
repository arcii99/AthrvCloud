//FormAI DATASET v1.0 Category: Robot movement control ; Style: accurate
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Function to print board
void print_board(char board[][COLS]) {
    printf("\n\t");
    for (int j = 0; j < COLS; j++) {
        printf("%d ", j);
    }
    printf("\n\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d\t", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to move robot
void move_robot(char board[][COLS], int row, int col) {
    srand(time(NULL));
    int r_num = rand() % 4;
    switch (r_num) {
        case 0:
            if (row > 0) {
                board[row][col] = '-';
                row--;
                board[row][col] = 'R';
            }
            break;
        case 1:
            if (row < ROWS - 1) {
                board[row][col] = '-';
                row++;
                board[row][col] = 'R';
            }
            break;
        case 2:
            if (col > 0) {
                board[row][col] = '-';
                col--;
                board[row][col] = 'R';
            }
            break;
        case 3:
            if (col < COLS - 1) {
                board[row][col] = '-';
                col++;
                board[row][col] = 'R';
            }
            break;
        default:
            break;
    }
}

int main() {
    char board[ROWS][COLS];
    int row = ROWS / 2;
    int col = COLS / 2;

    // Initializing the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
    board[row][col] = 'R'; // Initial position of robot
    print_board(board);

    int moves = 0;
    while (moves < 20) { // 20 moves for robot
        move_robot(board, row, col);
        row = (int) (rand() % ROWS);
        col = (int) (rand() % COLS);
        print_board(board);
        printf("Move: %d\n", ++moves);
    }
    return 0;
}