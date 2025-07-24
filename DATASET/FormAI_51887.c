//FormAI DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void initialize_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void get_user_input(int *row, int *col) {
    printf("Enter row and col (0-indexed): ");
    scanf("%d %d", row, col);
}

int is_valid_move(char board[ROWS][COLS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
        return 0;
    if (board[row][col] != '-')
        return 0;
    return 1;
}

int is_game_over(char board[ROWS][COLS]) {
    int i, j;
    // check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }
    // check cols
    for (j = 0; j < COLS; j++) {
        if (board[0][j] != '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return 1;
    }
    // check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

void make_move(char board[ROWS][COLS], int player, int row, int col) {
    board[row][col] = (player == 1) ? 'X' : 'O';
}

int main() {
    char board[ROWS][COLS];
    int turn = 1; // player 1 starts
    int row, col;
    int moves = 0;
    int game_over = 0;
    initialize_board(board);
    srand(time(0)); // seeding the random number generator
    int ai_level;
    printf("Select AI Level:\n");
    printf("1. Random\n");
    printf("2. Smart\n");
    printf("Enter choice: ");
    scanf("%d", &ai_level);
    while (!game_over) {
        if (turn == 1)
            printf("Player 1's turn:\n");
        else
            printf("Player 2's turn:\n");
        if (turn == 1 || ai_level == 1) {
            get_user_input(&row, &col);
            while (!is_valid_move(board, row, col)) {
                printf("Invalid move. Try again.\n");
                get_user_input(&row, &col);
            }
        }
        else {
            // AI's turn
            if (ai_level == 2) {
                // smart AI
                int i, j;
                // check rows
                for (i = 0; i < ROWS; i++) {
                    int count = 0;
                    for (j = 0; j < COLS; j++) {
                        if (board[i][j] == 'O')
                            count++;
                        if (board[i][j] == '-')
                            row = i, col = j;
                    }
                    if (count == 2 && row != -1 && col != -1)
                        break;
                }
                // check cols
                if (i == ROWS) {
                    for (j = 0; j < COLS; j++) {
                        int count = 0;
                        for (i = 0; i < ROWS; i++) {
                            if (board[i][j] == 'O')
                                count++;
                            if (board[i][j] == '-')
                                row = i, col = j;
                        }
                        if (count == 2 && row != -1 && col != -1)
                            break;
                    }
                }
                // check diagonals
                if (i == ROWS && j == COLS) {
                    int count = 0;
                    for (i = 0; i < ROWS; i++) {
                        if (board[i][i] == 'O')
                            count++;
                        if (board[i][i] == '-')
                            row = i, col = i;
                    }
                    if (count != 2 || row == -1 || col == -1) {
                        count = 0;
                        for (i = 0; i < ROWS; i++) {
                            if (board[i][2 - i] == 'O')
                                count++;
                            if (board[i][2 - i] == '-')
                                row = i, col = 2 - i;
                        }
                    }
                }
                if (i == ROWS && j == COLS) {
                    // no winning move, make a random move
                    row = rand() % ROWS;
                    col = rand() % COLS;
                    while (!is_valid_move(board, row, col)) {
                        row = rand() % ROWS;
                        col = rand() % COLS;
                    }
                }
            }
            else {
                // random AI
                row = rand() % ROWS;
                col = rand() % COLS;
                while (!is_valid_move(board, row, col)) {
                    row = rand() % ROWS;
                    col = rand() % COLS;
                }
            }
            printf("AI chose row=%d col=%d\n", row, col);
        }
        make_move(board, turn, row, col);
        print_board(board);
        moves++;
        if (is_game_over(board)) {
            if (turn == 1)
                printf("Player 1 wins!\n");
            else if (ai_level == 1)
                printf("Player 2 wins!\n");
            else
                printf("AI wins!\n");
            game_over = 1;
        }
        else if (moves == ROWS * COLS) {
            printf("It's a tie!\n");
            game_over = 1;
        }
        else {
            turn = (turn == 1) ? 2 : 1;
        }
    }
    return 0;
}