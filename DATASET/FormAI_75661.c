//FormAI DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_MOVES 15

/* Function to initialize the game board */
void initialize_board(int board[][COLS]) {
    int i, j, num = 1;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = num;
            num++;
        }
    }
    board[ROWS - 1][COLS - 1] = 0; // set the blank space
}

/* Function to print the current game board */
void print_board(int board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf("|   ");
            } else {
                printf("| %d ", board[i][j]);
            }
        }
        printf("|\n");
    }
}

/* Function to swap two adjacent cells */
void swap_cells(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to check if the puzzle is solved */
int check_win(int board[][COLS]) {
    int i, j, num = 1;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] != num) {
                return 0;
            }
            num++;
        }
    }
    return 1;
}

int main() {
    int board[ROWS][COLS];
    int i, j, num_moves = 0;
    char move;
    srand(time(NULL)); // seed the random number generator

    initialize_board(board);
    printf("Starting Game:\n");
    print_board(board);

    while (num_moves < MAX_MOVES) {
        /* Generate a random move */
        int valid_move = 0;
        while (!valid_move) {
            int row = rand() % ROWS;
            int col = rand() % COLS;
            if (board[row][col] == 0) {
                continue; // can't move the blank space
            }
            valid_move = 1;
            printf("Enter move (l=left, r=right, u=up, d=down): ");
            scanf("%c", &move);
            getchar(); // clear input buffer
            switch(move) {
                case 'l':
                    if (col == 0) {
                        valid_move = 0;
                    } else {
                        swap_cells(&board[row][col], &board[row][col-1]);
                    }
                    break;
                case 'r':
                    if (col == COLS-1) {
                        valid_move = 0;
                    } else {
                        swap_cells(&board[row][col], &board[row][col+1]);
                    }
                    break;
                case 'u':
                    if (row == 0) {
                        valid_move = 0;
                    } else {
                        swap_cells(&board[row][col], &board[row-1][col]);
                    }
                    break;
                case 'd':
                    if (row == ROWS-1) {
                        valid_move = 0;
                    } else {
                        swap_cells(&board[row][col], &board[row+1][col]);
                    }
                    break;
                default:
                    printf("Invalid move! Try again.\n");
                    valid_move = 0;
                    break;
            }
        }
        num_moves++;
        printf("Move #%d:\n", num_moves);
        print_board(board);
        if (check_win(board)) {
            printf("Congratulations, you solved the puzzle in %d moves!\n", num_moves);
            return 0;
        }
    }

    printf("Game over. Try again!\n");
    return 0;
}