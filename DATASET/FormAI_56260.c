//FormAI DATASET v1.0 Category: Game of Life ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLUMNS 30

int board[ROWS][COLUMNS];
int temp_board[ROWS][COLUMNS];

//Function to initialize the board with random values
void init_board() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = rand() % 2;
            temp_board[i][j] = 0;
        }
    }
}

//Function to print the board
void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == 1) {
                printf("* ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

//Function to check if a cell is a valid neighbor and alive
int is_valid_and_alive(int i, int j) {
    if (i >= 0 && i < ROWS && j >= 0 && j < COLUMNS && board[i][j] == 1) {
        return 1;
    } else {
        return 0;
    }
}

//Function to get the number of alive neighbors for a given cell
int get_alive_neighbors(int row, int col) {
    int alive_neighbors = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i != row || j != col) {
                alive_neighbors += is_valid_and_alive(i, j);
            }
        }
    }
    return alive_neighbors;
}

//Function to simulate one generation of the game
void simulate_generation() {
    int alive_neighbors;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            alive_neighbors = get_alive_neighbors(i, j);
            if (board[i][j] == 1 && (alive_neighbors == 2 || alive_neighbors == 3)) {
                //Cell stays alive
                temp_board[i][j] = 1;
            } else if (board[i][j] == 0 && alive_neighbors == 3) {
                //Cell becomes alive
                temp_board[i][j] = 1;
            } else {
                //Cell is dead
                temp_board[i][j] = 0;
            }
        }
    }
    //Copy temp_board to board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = temp_board[i][j];
        }
    }
}

int main() {
    init_board();
    for (int i = 0; i < 10; i++) {
        printf("Generation %d\n", i);
        print_board();
        simulate_generation();
    }
    return 0;
}