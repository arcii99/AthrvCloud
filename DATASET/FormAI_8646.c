//FormAI DATASET v1.0 Category: Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_MINES 15

typedef struct {
    int x;
    int y;
} Point;

typedef enum {
    UNREVEALED,
    REVEALED,
    FLAGGED
} CellState;

typedef enum {
    MINE,
    EMPTY
} CellType;

typedef struct {
    CellType type;
    bool has_mine;
    CellState state;
} Cell;

Cell board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    srand(time(NULL));
    
    // initialize all cells as unrevealed and empty
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].type = EMPTY;
            board[i][j].has_mine = false;
            board[i][j].state = UNREVEALED;
        }
    }
    
    // generate random mine locations
    int num_mines_left = NUM_MINES;
    while (num_mines_left > 0) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if (!board[x][y].has_mine) {
            board[x][y].has_mine = true;
            num_mines_left--;
        }
    }
}

void print_board() {
    printf(" ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("  %d", i);
    }
    printf("\n");
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j].state) {
                case UNREVEALED:
                    printf("[ ]");
                    break;
                case REVEALED:
                    if (board[i][j].type == MINE) {
                        printf("[*]");
                    } else {
                        int count = 0;
                        for (int x = i-1; x <= i+1; x++) {
                            for (int y = j-1; y <= j+1; y++) {
                                if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y].has_mine) {
                                    count++;
                                }
                            }
                        }
                        printf("[%d]", count);
                    }
                    break;
                case FLAGGED:
                    printf("[F]");
                    break;
            }
        }
        printf("\n");
    }
}

void reveal_cell(int x, int y) {
    if (board[x][y].state == UNREVEALED) {
        board[x][y].state = REVEALED;
        if (board[x][y].type == EMPTY) {
            for (int i = x-1; i <= x+1; i++) {
                for (int j = y-1; j <= y+1; j++) {
                    if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE) {
                        reveal_cell(i, j);
                    }
                }
            }
        }
    }
}

bool check_win() {
    int num_unrevealed = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].state == UNREVEALED) {
                num_unrevealed++;
            }
        }
    }
    return num_unrevealed == NUM_MINES;
}

int main() {
    init_board();
    
    printf("Welcome to Minesweeper!\n");
    printf("The goal of the game is to reveal all non-mine cells.\n");
    printf("Enter coordinates in the form 'x y' to reveal a cell, or 'x y f' to flag/unflag a cell.\n");
    
    bool game_over = false;
    while (!game_over) {
        print_board();
        int x, y;
        char c;
        printf("Enter coordinates: ");
        scanf("%d %d %c", &x, &y, &c);
        if (c == 'f') {
            if (board[x][y].state == FLAGGED) {
                board[x][y].state = UNREVEALED;
            } else if (board[x][y].state == UNREVEALED) {
                board[x][y].state = FLAGGED;
            }
        } else {
            reveal_cell(x, y);
            if (board[x][y].has_mine) {
                printf("Game over!\n");
                game_over = true;
            } else if (check_win()) {
                printf("You win!\n");
                game_over = true;
            }
        }
    }
    
    return 0;
}