//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct {
    int row;
    int column;
} Move;

void initialize_board(char board[][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool is_move_valid(char board[][BOARD_SIZE], Move move) {
    int row = move.row;
    int column = move.column;
    if(row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE) {
        printf("Move out of bounds\n");
        return false;
    }
    if(board[row][column] != '-') {
        printf("Spot already taken\n");
        return false;
    }
    return true;
}

bool is_move_winning(char board[][BOARD_SIZE], Move move, char symbol) {
    int count = 0;
    int row = move.row;
    int column = move.column;
    for(int i=0; i<BOARD_SIZE; i++) {
        if(board[row][i] == symbol) {
            count++;
        } else {
            count = 0;
            break;
        }
    }
    if(count == BOARD_SIZE) {
        return true;
    }
    count = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        if(board[i][column] == symbol) {
            count++;
        } else {
            count = 0;
            break;
        }
    }
    if(count == BOARD_SIZE) {
        return true;
    }
    count = 0;
    if(row == column) {
        for(int i=0; i<BOARD_SIZE; i++) {
            if(board[i][i] == symbol) {
                count++;
            } else {
                count = 0;
                break;
            }
        }
        if(count == BOARD_SIZE) {
            return true;
        }
    }
    count = 0;
    if(row == BOARD_SIZE - 1 - column) {
        for(int i=0; i<BOARD_SIZE; i++) {
            if(board[i][BOARD_SIZE - 1 - i] == symbol) {
                count++;
            } else {
                count = 0;
                break;
            }
        }
        if(count == BOARD_SIZE) {
            return true;
        }
    }
    return false;
}

int evaluate_board(char board[][BOARD_SIZE], char symbol) {
    if(is_move_winning(board, (Move){0,0}, symbol)) {
        return 10;
    }
    if(is_move_winning(board, (Move){0,1}, symbol)) {
        return 10;
    }
    if(is_move_winning(board, (Move){0,2}, symbol)) {
        return 10;
    }
    if(is_move_winning(board, (Move){1,0}, symbol)) {
        return 10;
    }
    if(is_move_winning(board, (Move){1,1}, symbol)) {
        return 10;
    }
    if(is_move_winning(board, (Move){1,2}, symbol)) {
        return 10;
    }
    if(is_move_winning(board, (Move){2,0}, symbol)) {
        return 10;
    }
    if(is_move_winning(board, (Move){2,1}, symbol)) {
        return 10;
    }
    if(is_move_winning(board, (Move){2,2}, symbol)) {
        return 10;
    }
    return 0;
}

int minimax(char board[][BOARD_SIZE], char symbol, int depth, bool is_maximizer) {
    if(evaluate_board(board, symbol) == 10) {
        return 10;
    } else if(evaluate_board(board, symbol == 'X' ? 'O' : 'X') == 10) {
        return -10;
    } else if(depth == 0) {
        return 0;
    }
    if(is_maximizer) {
        int best_value = -1000;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = symbol;
                    best_value = (best_value, minimax(board, symbol, depth-1, !is_maximizer));
                    board[i][j] = '-';
                }
            }
        }
        return best_value;
    } else {
        int best_value = 1000;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = symbol == 'X' ? 'O' : 'X';
                    best_value = (best_value, minimax(board, symbol, depth-1, !is_maximizer));
                    board[i][j] = '-';
                }
            }
        }
        return best_value;
    }
}

Move find_best_move(char board[][BOARD_SIZE], char symbol) {
    int best_value = -1000;
    Move best_move;
    best_move.row = -1;
    best_move.column = -1;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == '-') {
                board[i][j] = symbol;
                int current_value = minimax(board, symbol, 2, false);
                board[i][j] = '-';
                if(current_value > best_value) {
                    best_value = current_value;
                    best_move.row = i;
                    best_move.column = j;
                }
            }
        }
    }
    return best_move;
}

int main() {
    printf("Welcome to Tic Tac Toe!\n\n");
    printf("To make a move, enter the row number and column number separated by a space (e.g. 1 2).\n");
    printf("You will be X and the computer will be O.\n\n");
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    char winner = '-';
    while(winner == '-') {
        print_board(board);
        int row, column;
        printf("\nMake your move: ");
        scanf("%d %d", &row, &column);
        if(is_move_valid(board, (Move){row, column})) {
            board[row][column] = 'X';
        } else {
            continue;
        }
        if(is_move_winning(board, (Move){row, column}, 'X')) {
            winner = 'X';
            break;
        }
        Move ai_move = find_best_move(board, 'O');
        board[ai_move.row][ai_move.column] = 'O';
        printf("The computer made a move at (%d, %d).\n", ai_move.row, ai_move.column);
        if(is_move_winning(board, ai_move, 'O')) {
            winner = 'O';
        }
    }
    print_board(board);
    printf("\n%s wins!\n", winner == 'X' ? "You" : "The computer");
    return 0;
}