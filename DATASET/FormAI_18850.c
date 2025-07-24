//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Game constants
#define BOARD_SIZE 10
#define NUM_MINES 10

typedef enum { HIDDEN, REVEALED, FLAGGED } square_state_t;
typedef struct {
    square_state_t state;
    int is_mine;
    int num_adjacent_mines;
} square_t;

// Function prototypes
void init_board(square_t board[BOARD_SIZE][BOARD_SIZE]);
void place_mines(square_t board[BOARD_SIZE][BOARD_SIZE]);
void print_board(square_t board[BOARD_SIZE][BOARD_SIZE]);
void reveal(square_t board[BOARD_SIZE][BOARD_SIZE], int row, int col, int *remaining);
void flag(square_t board[BOARD_SIZE][BOARD_SIZE], int row, int col, int *num_flags);
int check_win(square_t board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    square_t board[BOARD_SIZE][BOARD_SIZE];
    int remaining = BOARD_SIZE * BOARD_SIZE - NUM_MINES;
    int num_flags = 0;
    srand(time(NULL));
    
    init_board(board);
    place_mines(board);
    printf("Welcome to MineSweeper!\n");
    printf("Use r to reveal a square, f to flag a square, and q to quit.\n");
    print_board(board);
    
    while (remaining > 0) {
        char input;
        int row, col;
        printf("Enter a command (r, f, q): ");
        scanf(" %c", &input);
        if (input == 'q') {
            printf("Goodbye!\n");
            return 0;
        }
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            printf("Invalid row or column.\n");
            continue;
        }
        if (input == 'r') {
            if (board[row][col].state == REVEALED) {
                printf("This square is already revealed.\n");
            } else if (board[row][col].is_mine) {
                printf("BOOM! You hit a mine.\n");
                return 0;
            } else {
                reveal(board, row, col, &remaining);
                if (check_win(board)) {
                    printf("Congratulations! You won!\n");
                    return 0;
                }
            }
        } else if (input == 'f') {
            flag(board, row, col, &num_flags);
        } else {
            printf("Invalid command.\n");
        }
        print_board(board);
    }
}

void init_board(square_t board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].state = HIDDEN;
            board[i][j].is_mine = 0;
            board[i][j].num_adjacent_mines = 0;
        }
    }
}

void place_mines(square_t board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < NUM_MINES; i++) {
        int row, col;
        do {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        } while (board[row][col].is_mine);
        board[row][col].is_mine = 1;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                int r = row + j;
                int c = col + k;
                if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
                    board[r][c].num_adjacent_mines++;
                }
            }
        }
    }
}

void print_board(square_t board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].state == HIDDEN) {
                printf(". ");
            } else if (board[i][j].state == FLAGGED) {
                printf("F ");
            } else if (board[i][j].is_mine) {
                printf("X ");
            } else {
                printf("%d ", board[i][j].num_adjacent_mines);
            }
        }
        printf("\n");
    }
}

void reveal(square_t board[BOARD_SIZE][BOARD_SIZE], int row, int col, int *remaining) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return;
    }
    if (board[row][col].state == REVEALED) {
        return;
    }
    if (board[row][col].is_mine) {
        return;
    }
    board[row][col].state = REVEALED;
    (*remaining)--;
    if (board[row][col].num_adjacent_mines == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int r = row + i;
                int c = col + j;
                reveal(board, r, c, remaining);
            }
        }
    }
}

void flag(square_t board[BOARD_SIZE][BOARD_SIZE], int row, int col, int *num_flags) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return;
    }
    if (board[row][col].state == REVEALED) {
        return;
    }
    if (board[row][col].state == FLAGGED) {
        board[row][col].state = HIDDEN;
        (*num_flags)--;
    } else {
        board[row][col].state = FLAGGED;
        (*num_flags)++;
    }
}

int check_win(square_t board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].state == HIDDEN && !board[i][j].is_mine) {
                return 0;
            }
        }
    }
    return 1;
}