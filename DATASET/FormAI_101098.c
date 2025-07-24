//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 10
#define BOMB_COUNT 10

// Global variables
int board[BOARD_SIZE][BOARD_SIZE] = {0};
bool revealed[BOARD_SIZE][BOARD_SIZE] = {false};
bool game_over = false;

// Function prototypes
void setup_board();
void print_board(bool reveal_bombs);
void clear_screen();
void reveal_cell(int row, int col);
void reveal_area(int row, int col);
void handle_input();

int main() {
    setup_board();
    clear_screen();
    print_board(false);
    while(!game_over) {
        handle_input();
        clear_screen();
        print_board(false);
    }
    printf("Game Over!\n");
    return 0;
}

// Set up the game board with bombs and numbers
void setup_board() {
    srand(time(NULL));
    int bombs_placed = 0;
    while(bombs_placed < BOMB_COUNT) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        if(board[row][col] == -1) {
            continue;
        } else {
            board[row][col] = -1;
            bombs_placed++;
            // Update surrounding cells with count of bombs
            for(int dr=-1; dr<=1; dr++) {
                for(int dc=-1; dc<=1; dc++) {
                    int r = row + dr;
                    int c = col + dc;
                    if(r < 0 || r >= BOARD_SIZE || c < 0 || c >= BOARD_SIZE
                        || (dr == 0 && dc == 0)) {
                        continue;
                    } else {
                        if(board[r][c] != -1) {
                            board[r][c]++;
                        }
                    }
                }
            }
        }
    }
}

// Print out the game board, optionally revealing bomb locations
void print_board(bool reveal_bombs) {
    printf("   ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    for(int row=0; row<BOARD_SIZE; row++) {
        printf("%2d|", row);
        for(int col=0; col<BOARD_SIZE; col++) {
            if(game_over && board[row][col] == -1 && reveal_bombs) {
                printf("*  ");
            } else if(revealed[row][col]) {
                if(board[row][col] == -1) {
                    printf("X  ");
                } else {
                    printf("%d  ", board[row][col]);
                }
            } else {
                printf(".  ");
            }
        }
        printf("\n");
    }
}

// Clear the terminal screen
void clear_screen() {
    printf("\033[2J\033[1;1H");
}

// Handle user input for selecting a cell to reveal or flag
void handle_input() {
    printf("Enter row col action (r=reveal, f=flag): ");
    int row, col;
    char action;
    scanf("%d %d %c", &row, &col, &action);
    if(row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        printf("Invalid cell, try again.\n");
    } else {
        switch(action) {
            case 'r':
                if(board[row][col] == -1) {
                    // Bomb hit - reveal all cells and end game
                    game_over = true;
                    printf("You hit a bomb!\n");
                    print_board(true);
                } else {
                    if(board[row][col] == 0) {
                        reveal_area(row, col);
                    } else {
                        reveal_cell(row, col);
                    }
                }
                break;
            case 'f':
                printf("Flag at (%d, %d)\n", row, col);
                break;
            default:
                printf("Invalid action, try again.\n");
                break;
        }
    }
}

// Reveal a single cell on the game board
void reveal_cell(int row, int col) {
    if(revealed[row][col]) {
        return;
    } else {
        revealed[row][col] = true;
        if(board[row][col] == 0) {
            return;
        } else {
            return;
        }
    }
}

// Reveal the entire connected area of cells with no bombs
void reveal_area(int row, int col) {
    if(revealed[row][col]) {
        return;
    } else {
        revealed[row][col] = true;
        if(board[row][col] == 0) {
            for(int dr=-1; dr<=1; dr++) {
                for(int dc=-1; dc<=1; dc++) {
                    int r = row + dr;
                    int c = col + dc;
                    if(r < 0 || r >= BOARD_SIZE || c < 0 || c >= BOARD_SIZE
                        || (dr == 0 && dc == 0)) {
                        continue;
                    } else {
                        reveal_area(r, c);
                    }
                }
            }
        } else {
            return;
        }
    }
}