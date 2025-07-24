//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void initialize_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_row(char board[ROWS][COLS], char symbol) {
    int i, j, count;
    for (i = 0; i < ROWS; ++i) {
        count = 0;
        for (j = 0; j < COLS; ++j) {
            if (board[i][j] == symbol) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1;
        }
    }
    return 0;
}

int check_col(char board[ROWS][COLS], char symbol) {
    int i, j, count;
    for (j = 0; j < COLS; ++j) {
        count = 0;
        for (i = 0; i < ROWS; ++i) {
            if (board[i][j] == symbol) {
                count++;
            }
        }
        if (count == COLS) {
            return 1;
        }
    }
    return 0;
}

int check_diag(char board[ROWS][COLS], char symbol) {
    int i, j, count_diag1, count_diag2;
    count_diag1 = 0;
    count_diag2 = 0;
    for (i = 0, j = 0; i < ROWS && j < COLS; ++i, ++j) {
        if (board[i][j] == symbol) {
            count_diag1++;
        }
    }
    for (i = 0, j = COLS - 1; i < ROWS && j >= 0; ++i, --j) {
        if (board[i][j] == symbol) {
            count_diag2++;
        }
    }
    if (count_diag1 == ROWS || count_diag2 == ROWS) {
        return 1;
    }
    return 0;
}

int check_win(char board[ROWS][COLS], char symbol) {
    if (check_row(board, symbol) || check_col(board, symbol) || check_diag(board, symbol)) {
        return 1;
    }
    return 0;
}

void player_turn(char board[ROWS][COLS], char symbol) {
    int row, col;
    printf("\nYour turn (Player '%c'):\n", symbol);
    do {
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        row--;
        col--;
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("\nInvalid input. Please try again.\n");
        }
        else if (board[row][col] != '-') {
            printf("\nThat cell is already occupied. Please try again.\n");
        }
        else {
            board[row][col] = symbol;
        }
    } while (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != '-');
}

void computer_turn(char board[ROWS][COLS], char symbol) {
    int row, col, i, j, count_max, count_empty;
    int row_max[ROWS], col_max[COLS];
    count_max = 0;
    count_empty = 0;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            if (board[i][j] == '-') {
                count_empty++;
                board[i][j] = symbol;
                if (check_win(board, symbol)) {
                    printf("\nComputer wins!\n");
                    exit(0);
                }
                board[i][j] = '-';
            }
        }
    }
    if (count_empty == 1) {
        printf("\nDraw!\n");
        exit(0);
    }
    srand(time(NULL));
    do {
        row = rand() % ROWS;
        col = rand() % COLS;
        if (board[row][col] == '-') {
            board[row][col] = symbol;
            break;
        }
    } while (1);
}

int main() {
    char board[ROWS][COLS], symbol;
    int i, j;
    initialize_board(board);
    print_board(board);
    printf("\nEnter your symbol (X or O): ");
    scanf(" %c", &symbol);
    if (symbol == 'X') {
        for (i = 0; i < ROWS * COLS; ++i) {
            player_turn(board, symbol);
            print_board(board);
            if (check_win(board, symbol)) {
                printf("\nCongratulations! You win!\n");
                return 0;
            }
            computer_turn(board, 'O');
            print_board(board);
            if (check_win(board, 'O')) {
                printf("\nComputer wins!\n");
                return 0;
            }
        }
    }
    else if (symbol == 'O') {
        for (i = 0; i < ROWS * COLS; ++i) {
            computer_turn(board, 'X');
            print_board(board);
            if (check_win(board, 'X')) {
                printf("\nComputer wins!\n");
                return 0;
            }
            player_turn(board, symbol);
            print_board(board);
            if (check_win(board, symbol)) {
                printf("\nCongratulations! You win!\n");
                return 0;
            }
        }
    }
    else {
        printf("\nInvalid symbol. Please restart the program.\n");
    }
    printf("\nDraw!\n");
    return 0;
}