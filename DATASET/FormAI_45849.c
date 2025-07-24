//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_CELL '-'

char board[BOARD_SIZE][BOARD_SIZE];

int is_move_valid(int row, int col) {
    if(row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
        return 0;
    if(board[row][col] != EMPTY_CELL)
        return 0;
    return 1;
}

int is_game_won(char player) {
    int i, j, row_count = 0, col_count = 0, diag1_count = 0, diag2_count = 0;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == player) {
                row_count++;
            }
            if(board[j][i] == player) {
                col_count++;
            }
            if(i == j && board[i][j] == player) {
                diag1_count++;
            }
            if(i+j == BOARD_SIZE-1 && board[i][j] == player) {
                diag2_count++;
            }
        }
        if(row_count == BOARD_SIZE || col_count == BOARD_SIZE || diag1_count == BOARD_SIZE || diag2_count == BOARD_SIZE) {
            return 1;
        }
        row_count = 0;
        col_count = 0;
        diag1_count = 0;
        diag2_count = 0;
    }
    return 0;
}

int evaluate_board() {
    if(is_game_won(PLAYER_X)) {
        return 10;
    }
    if(is_game_won(PLAYER_O)) {
        return -10;
    }
    return 0;
}

int minimax(int depth, int is_maximizer) {
    int i, j, score, best_score;
    best_score = -1000;
    if(evaluate_board() == 10) {
        return 10 - depth;
    }
    if(evaluate_board() == -10) {
        return -10 + depth;
    }
    if(depth == BOARD_SIZE * BOARD_SIZE) {
        return 0;
    }
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(is_move_valid(i, j)) {
                if(is_maximizer) {
                    board[i][j] = PLAYER_X;
                    score = minimax(depth+1, 0);
                    board[i][j] = EMPTY_CELL;
                    if(score > best_score) {
                        best_score = score;
                    }
                } else {
                    board[i][j] = PLAYER_O;
                    score = minimax(depth+1, 1);
                    board[i][j] = EMPTY_CELL;
                    if(score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
    }
    return best_score;
}

void make_computer_move() {
    int i, j, best_score = -1000, score;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(is_move_valid(i, j)) {
                board[i][j] = PLAYER_X;
                score = minimax(0, 0);
                board[i][j] = EMPTY_CELL;
                if(score > best_score) {
                    best_score = score;
                }
            }
        }
    }
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(is_move_valid(i, j)) {
                board[i][j] = PLAYER_X;
                score = minimax(0, 0);
                board[i][j] = EMPTY_CELL;
                if(score == best_score) {
                    board[i][j] = PLAYER_X;
                    return;
                }
            }
        }
    }
}

void print_board() {
    int i, j;
    printf("\n");
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int i, j, row, col;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_CELL;
        }
    }
    while(1) {
        printf("Enter row and col (0 to %d) to make a move as O or enter -1 to exit.\n", BOARD_SIZE-1);
        scanf("%d %d", &row, &col);
        if(row == -1) {
            break;
        }
        if(is_move_valid(row, col)) {
            board[row][col] = PLAYER_O;
            make_computer_move();
            print_board();
        } else {
            printf("Invalid move! Try again.\n");
        }
        if(is_game_won(PLAYER_X)) {
            printf("You lost!\n");
            break;
        }
        if(is_game_won(PLAYER_O)) {
            printf("You won!\n");
            break;
        }
    }
    return 0;
}