//FormAI DATASET v1.0 Category: Game of Life ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 20 // number of rows
#define COLUMNS 40 // number of columns
#define ALIVE '*' // character representing an alive cell
#define DEAD ' ' // character representing a dead cell

int board[ROWS][COLUMNS]; // the game board
int new_board[ROWS][COLUMNS]; // temporary board to calculate the next generation

// initializes the board randomly
void init_board() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// prints the board to the console
void print_board() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            if(board[i][j] == 0) {
                printf("%c ", DEAD);
            } else {
                printf("%c ", ALIVE);
            }
        }
        printf("\n");
    }
}

// counts the number of alive neighbors of a given cell
int count_neighbors(int row, int col) {
    int count = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=col-1; j<=col+1; j++) {
            if(i<0 || i>=ROWS || j<0 || j>=COLUMNS || (i==row && j==col)) continue; // skip cells outside the board or the current cell
            count += board[i][j];
        }
    }
    return count;
}

// updates the board to the next generation
void next_generation() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            int neighbors = count_neighbors(i, j);
            if(board[i][j] == 0 && neighbors == 3) {
                new_board[i][j] = 1;
            } else if(board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_board[i][j] = 0;
            } else {
                new_board[i][j] = board[i][j];
            }
        }
    }
    // copy the new board to the current board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    init_board();
    while(1) {
        printf("Press Enter to display the next generation, or type 'q' to quit\n");
        char c = getchar();
        if(c == 'q') {
            break;
        }
        next_generation();
        print_board();
    }
    return 0;
}