//FormAI DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 50

void initialize_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);
int count_neighbor_cells(int board[ROWS][COLS], int row, int col);
void update_board(int board[ROWS][COLS]);

int main()
{
    int board[ROWS][COLS];
    initialize_board(board);
    print_board(board);

    while(1) {
        update_board(board);
        print_board(board);
        usleep(250000); // Sleep for 250ms
    }

    return 0;
}

void initialize_board(int board[ROWS][COLS])
{
    srand(time(0));

    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            // Randomly initialize cells
            board[row][col] = rand() % 2;
        }
    }
}

void print_board(int board[ROWS][COLS])
{
    // Clear screen
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);

    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            // Print cell state
            printf("%c", board[row][col] ? '#' : '-');
        }
        printf("\n");
    }
}

int count_neighbor_cells(int board[ROWS][COLS], int row, int col)
{
    int count = 0;

    for(int r = row-1; r <= row+1; r++) {
        for(int c = col-1; c <= col+1; c++) {
            // Handle boundary cases
            int check_row = (r + ROWS) % ROWS;
            int check_col = (c + COLS) % COLS;

            // Don't count the cell at (row, col)
            if(r == row && c == col) {
                continue;
            }

            // Increment count if cell is alive
            if(board[check_row][check_col]) {
                count++;
            }
        }
    }

    return count;
}

void update_board(int board[ROWS][COLS])
{
    int new_board[ROWS][COLS];

    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            int neighbor_count = count_neighbor_cells(board, row, col);

            // Apply Game of Life rules
            if(board[row][col]) {
                if(neighbor_count < 2 || neighbor_count > 3) {
                    new_board[row][col] = 0;
                } else {
                    new_board[row][col] = 1;
                }
            } else {
                if(neighbor_count == 3) {
                    new_board[row][col] = 1;
                } else {
                    new_board[row][col] = 0;
                }
            }
        }
    }

    // Copy new board to old board
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            board[row][col] = new_board[row][col];
        }
    }
}