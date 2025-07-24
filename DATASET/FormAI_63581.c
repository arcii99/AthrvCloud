//FormAI DATASET v1.0 Category: Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 5

// Global variables
int board[BOARD_SIZE][BOARD_SIZE];
int score = 0;

// Generates a random tile (2 or 4) in a random empty cell of the board
void spawn_tile() {
    int empty_cells = 0;
    int cells[BOARD_SIZE*BOARD_SIZE][2];
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == 0) {
                cells[empty_cells][0] = i;
                cells[empty_cells][1] = j;
                empty_cells++;
            }
        }
    }
    if(empty_cells == 0) return;
    int rnd = rand() % empty_cells;
    int i = cells[rnd][0];
    int j = cells[rnd][1];
    int val = (rand() % 2 + 1) * 2; // Either 2 or 4
    board[i][j] = val;
}

// Returns the highest tile on the board
int highest_tile() {
    int highest = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] > highest) {
                highest = board[i][j];
            }
        }
    }
    return highest;
}

// Draws the board
void draw_board() {
    printf("\033c"); // Clears the terminal screen
    printf("SCORE: %d\tHIGHEST TILE: %d\n\n", score, highest_tile());
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n\n");
    }
}

// Moves all tiles on a given row (towards the left)
void move_row(int row) {
    int prev = -1;
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[row][i] == 0) continue;
        int curr = board[row][i];
        board[row][i] = 0;
        if(prev == -1 || prev != curr) {
            int j = i;
            while(j > 0 && board[row][j-1] == 0) {
                j--;
            }
            board[row][j] = curr;
            prev = curr;
        } else {
            board[row][i-1] = prev*2;
            prev = -1;
            score += prev*2;
        }
    }
}

// Transposes the board (i.e., swaps rows with columns)
void transpose_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < i; j++) {
            int tmp = board[i][j];
            board[i][j] = board[j][i];
            board[j][i] = tmp;
        }
    }
}

// Moves all tiles (either left, right, up, or down)
void move_board(char dir) {
    bool moved = false;
    switch(dir) {
        case 'a': // Left
            for(int i = 0; i < BOARD_SIZE; i++) {
                move_row(i);
                if(!moved && highest_tile() == 2048) {
                    printf("CONGRATULATIONS! YOU WON!\n");
                    exit(0);
                }
            }
            moved = true;
            break;
        case 'd': // Right
            transpose_board();
            transpose_board();
            for(int i = 0; i < BOARD_SIZE; i++) {
                move_row(i);
                if(!moved && highest_tile() == 2048) {
                    printf("CONGRATULATIONS! YOU WON!\n");
                    exit(0);
                }
            }
            transpose_board();
            transpose_board();
            moved = true;
            break;
        case 'w': // Up
            transpose_board();
            for(int i = 0; i < BOARD_SIZE; i++) {
                move_row(i);
                if(!moved && highest_tile() == 2048) {
                    printf("CONGRATULATIONS! YOU WON!\n");
                    exit(0);
                }
            }
            transpose_board();
            transpose_board();
            transpose_board();
            moved = true;
            break;
        case 's': // Down
            transpose_board();
            transpose_board();
            transpose_board();
            for(int i = 0; i < BOARD_SIZE; i++) {
                move_row(i);
                if(!moved && highest_tile() == 2048) {
                    printf("CONGRATULATIONS! YOU WON!\n");
                    exit(0);
                }
            }
            transpose_board();
            moved = true;
            break;
    }
    if(moved) spawn_tile();
}

// Initializes the board by placing two tiles
void init_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    spawn_tile();
    spawn_tile();
}

int main() {
    srand(time(NULL)); // Initializes the random number generator
    init_board();
    char c;
    while(true) {
        draw_board();
        c = getchar();
        if(c == 'q') break;
        move_board(c);
    }
    return 0;
}