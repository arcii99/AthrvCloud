//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_MINES 10

typedef enum {
    COVERED,
    UNCOVERED
} CellState;

typedef enum {
    MINE,
    EMPTY
} CellContent;

typedef struct {
    CellState state;
    CellContent content;
} Cell;

void print_board(Cell board[BOARD_SIZE][BOARD_SIZE], int reveal_mines, int game_won) {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            Cell cell = board[i][j];
            char output;
            if (cell.state == COVERED) {
                if (reveal_mines && cell.content == MINE) {
                    output = '*';
                } else {
                    output = '#';
                }
            } else {
                if (cell.content == MINE) {
                    output = game_won ? '*' : 'X';
                } else {
                    int num_adjacent_mines = 0;
                    for (int k = -1; k <= 1; k++) {
                        for (int l = -1; l <= 1; l++) {
                            int row = i + k;
                            int col = j + l;
                            if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
                                if (board[row][col].content == MINE) {
                                    num_adjacent_mines++;
                                }
                            }
                        }
                    }
                    output = num_adjacent_mines + '0';
                }
            }
            printf("%2c ", output);
        }
        printf("\n");
    }
}

int count_adjacent_mines(Cell board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int r = row + i;
            int c = col + j;
            if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
                if (board[r][c].content == MINE) {
                    count++;
                }
            }
        }
    }
    return count;
}

void place_mines(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    int num_mines_placed = 0;
    while (num_mines_placed < NUM_MINES) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        if (board[row][col].content != MINE) {
            board[row][col].content = MINE;
            num_mines_placed++;
        }
    }
}

void initialize_board(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].state = COVERED;
            board[i][j].content = EMPTY;
        }
    }
    place_mines(board);
}

void reveal_cells(Cell board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    if (board[row][col].state == UNCOVERED) {
        return;
    }
    board[row][col].state = UNCOVERED;
    if (board[row][col].content == MINE) {
        return;
    }
    int num_adjacent_mines = count_adjacent_mines(board, row, col);
    if (num_adjacent_mines == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int r = row + i;
                int c = col + j;
                if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
                    reveal_cells(board, r, c);
                }
            }
        }
    }
}

int check_win(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    int num_uncovered_cells = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].state == UNCOVERED) {
                num_uncovered_cells++;
            }
        }
    }
    return num_uncovered_cells == BOARD_SIZE * BOARD_SIZE - NUM_MINES;
}

int main() {
    printf("Welcome to MineSweeper!\n");
    Cell board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    int game_over = 0;
    int game_won = 0;
    while (!game_over) {
        print_board(board, 0, 0);
        int row, col;
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);
        if (board[row][col].content == MINE) {
            printf("BOOM! Game over.\n");
            game_over = 1;
        } else {
            reveal_cells(board, row, col);
            game_won = check_win(board);
            if (game_won) {
                printf("Congratulations, you won!!!\n");
                game_over = 1;
            }
        }
    }
    print_board(board, 1, game_won);
    return 0;
}