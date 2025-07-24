//FormAI DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define GENERATIONS 10

// Function to initialize the board randomly
void initialize_board(int board[][SIZE]) {
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to print the board
void print_board(int board[][SIZE]) {
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            printf("%c", board[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}

// Function to count the number of live neighbors for a cell
int count_live_neighbors(int board[][SIZE], int i, int j) {
    int count = 0;
    int x, y;
    for (x=i-1; x<=i+1; x++) {
        for (y=j-1; y<=j+1; y++) {
            if (x>=0 && x<SIZE && y>=0 && y<SIZE && board[x][y]) {
                count++;
            }
        }
    }
    if (board[i][j]) {
        count--;
    }
    return count;
}

// Function to apply the rules of the game for a cell
void apply_game_rules(int board[][SIZE], int i, int j) {
    int live_neighbors = count_live_neighbors(board, i, j);
    if (board[i][j]) {
        if (live_neighbors < 2 || live_neighbors > 3) {
            board[i][j] = 0;
        }
    } else {
        if (live_neighbors == 3) {
            board[i][j] = 1;
        }
    }
}

// Function to execute a generation of the game
void execute_generation(int board[][SIZE]) {
    int i, j;
    int new_board[SIZE][SIZE];

    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            new_board[i][j] = board[i][j];
        }
    }

    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            apply_game_rules(new_board, i, j);
        }
    }

    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

// Main function
int main() {
    srand(time(NULL));

    int board[SIZE][SIZE];

    initialize_board(board);

    printf("Initial board:\n");
    print_board(board);

    int generation;
    for (generation=0; generation<GENERATIONS; generation++) {
        printf("\nGeneration %d:\n", generation+1);
        execute_generation(board);
        print_board(board);
    }

    return 0;
}