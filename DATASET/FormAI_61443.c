//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define Constants
#define ROWS 10
#define COLS 10
#define MINES 20
#define FLAG 'F'
#define MINE 'X'
#define HIDDEN ' '
#define GAMEOVER 1
#define GAMENOTOVER 0

// Function Declarations
void initialize_board(char board[][COLS]);
void print_board(char board[][COLS], int reveal);
void populate_mines(char board[][COLS]);
void populate_numbers(char board[][COLS]);
void reveal_cells(char board[][COLS], int row, int col);
int check_game_status(char board[][COLS]);

int main() {
    int i, j, row, col, choice, reveal = 0, game_status = GAMENOTOVER;
    char board[ROWS][COLS];
    
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize board
    initialize_board(board);
    
    // Populate board with mines and numbers
    populate_mines(board);
    populate_numbers(board);
    
    // Welcome Message
    printf("Welcome to Minesweeper!\n\n");
    
    do {
        // Print board
        print_board(board, reveal);
        
        // User input
        printf("Enter row and column number (separated by space): ");
        scanf("%d%d", &row, &col);
        
        printf("1. Reveal cell\n");
        printf("2. Flag cell\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Reveal cell
                if (board[row][col] == MINE) {
                    // Game Over
                    reveal = 1;
                    board[row][col] = GAMEOVER;
                    game_status = GAMEOVER;
                    printf("Oops, you hit a mine!\n");
                }
                else {
                    reveal_cells(board, row, col);
                }
                break;
            case 2:
                // Flag cell
                if (board[row][col] == FLAG) {
                    board[row][col] = HIDDEN;
                }
                else {
                    board[row][col] = FLAG;
                }
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        
        // Check game status
        game_status = check_game_status(board);
        
    } while (game_status == GAMENOTOVER);
    
    // Game Over Message
    printf("\n***** GAME OVER *****\n");
    print_board(board, 1);
    
    return 0;
}

// Initialize board with hidden cells
void initialize_board(char board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = HIDDEN;
        }
    }
}

// Print the board
void print_board(char board[][COLS], int reveal) {
    int i, j;
    printf("\n   ");
    for (i = 0; i < COLS; i++) {
        printf("%2d", i);
    }
    printf("\n");
    printf("  +");
    for (i = 0; i < COLS; i++) {
        printf("--");
    }
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("%2d|", i);
        for (j = 0; j < COLS; j++) {
            if (reveal || board[i][j] == MINE) {
                printf("%2c", board[i][j]);
            }
            else {
                printf("%2c", HIDDEN);
            }
        }
        printf("\n");
    }
}

// Populate board with mines
void populate_mines(char board[][COLS]) {
    int i, row, col;
    for (i = 0; i < MINES; i++) {
        row = rand() % ROWS;
        col = rand() % COLS;
        if (board[row][col] == MINE) {
            i--;
        }
        else {
            board[row][col] = MINE;
        }
    }
}

// Populate board with numbers
void populate_numbers(char board[][COLS]) {
    int i, j, count;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] != MINE) {
                count = 0;
                // Count adjacent mines
                if (i > 0 && board[i-1][j] == MINE) {
                    count++;
                }
                if (i < ROWS-1 && board[i+1][j] == MINE) {
                    count++;
                }
                if (j > 0 && board[i][j-1] == MINE) {
                    count++;
                }
                if (j < COLS-1 && board[i][j+1] == MINE) {
                    count++;
                }
                if (i > 0 && j > 0 && board[i-1][j-1] == MINE) {
                    count++;
                }
                if (i > 0 && j < COLS-1 && board[i-1][j+1] == MINE) {
                    count++;
                }
                if (i < ROWS-1 && j > 0 && board[i+1][j-1] == MINE) {
                    count++;
                }
                if (i < ROWS-1 && j < COLS-1 && board[i+1][j+1] == MINE) {
                    count++;
                }
                // Convert count to character
                board[i][j] = count + '0';
            }
        }
    }
}

// Reveal all empty cells adjacent to chosen cell
void reveal_cells(char board[][COLS], int row, int col) {
    if (board[row][col] != HIDDEN) {
        return;
    }
    board[row][col] = board[row][col] >= '1' && board[row][col] <= '8' ? board[row][col] : ' ';
    if (row > 0) {
        reveal_cells(board, row-1, col);
    }
    if (row < ROWS-1) {
        reveal_cells(board, row+1, col);
    }
    if (col > 0) {
        reveal_cells(board, row, col-1);
    }
    if (col < COLS-1) {
        reveal_cells(board, row, col+1);
    }
}

// Check game status (Game Over or Game Not Over)
int check_game_status(char board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == HIDDEN) {
                return GAMENOTOVER;
            }
        }
    }
    return GAMEOVER;
}