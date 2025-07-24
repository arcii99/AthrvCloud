//FormAI DATASET v1.0 Category: Game of Life ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

/* Function to print the game board */
void print_board(int board[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == 1) {
                printf(" # ");
            }
            else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

/* Function to initialize the game board */
void initialize_board(int board[][COLS], double density) {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            double r = (double)rand() / RAND_MAX;
            if(r < density) {
                board[i][j] = 1;
            }
            else {
                board[i][j] = 0;
            }
        }
    }
}

/* Function to calculate the next generation of cells */
void next_generation(int board[][COLS]) {
    int new_board[ROWS][COLS] = {0};
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbors = 0;
            for(int x=-1; x<=1; x++) {
                for(int y=-1; y<=1; y++) {
                    if(!(x == 0 && y == 0) && i+x >= 0 && i+x < ROWS && j+y >= 0 && j+y < COLS) {
                        if(board[i+x][j+y] == 1) {
                            neighbors++;
                        }
                    }
                }
            }
            if(board[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3) {
                    new_board[i][j] = 0;
                }
                else {
                    new_board[i][j] = 1;
                }
            }
            else {
                if(neighbors == 3) {
                    new_board[i][j] = 1;
                }
            }
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS] = {0};
    double density = 0.5;
    initialize_board(board, density);
    printf("Initial state:\n");
    print_board(board);
    printf("Press enter to see the next generation or enter q to quit.\n");
    char c = getchar();
    while(c != 'q') {
        next_generation(board);
        printf("Next generation:\n");
        print_board(board);
        printf("Press enter to see the next generation or enter q to quit.\n");
        c = getchar();
    }
    return 0;
}