//FormAI DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void initialize(int board[ROWS][COLS]) {
    int i, j; 
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }   
    }
}

void print_board(int board[ROWS][COLS]) {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[ROWS][COLS], int row, int col) {
    int i, j, count = 0;
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) {
                continue;
            } 
            if (i < 0 || i >= ROWS || j < 0 || j >= COLS) {
                continue;
            } 
            if (board[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS]) {
    int i, j, neighbors;
    int new_board[ROWS][COLS];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            neighbors = count_neighbors(board, i, j);
            if (board[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_board[i][j] = 1;
            } else if (board[i][j] == 0 && neighbors == 3) {
                new_board[i][j] = 1;
            } else {
                new_board[i][j] = 0;
            }
        }
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    int generation = 0;
    char user_choice;
    
    initialize(board);
    while (1) {
        printf("Generation: %d\n", generation);
        print_board(board);
        printf("Press 'q' to quit or any other key to continue: ");
        scanf(" %c", &user_choice);
        if (user_choice == 'q') {
            break;
        }
        update_board(board);
        generation++;
    }
    return 0;
}