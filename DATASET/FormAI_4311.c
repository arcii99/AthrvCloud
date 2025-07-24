//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define AI_MOVE 'X'
#define PLAYER_MOVE 'O'
#define SIZE 3

char board[SIZE][SIZE];

void initialize_board() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board[i][j] = '_';
        }
    }
}

void display_board() {
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%c | %c | %c", board[i][0], board[i][1], board[i][2]);
        printf("\n");
    }
    printf("\n");
}

void update_board(int row, int col, char move) {
    board[row][col] = move;
}

int is_valid_move(int row, int col) {
    if(row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0;
    }
    if(board[row][col] != '_') {
        return 0;
    }
    return 1;
}

int evaluate_board(char move) {
    int i, j;

    // Check rows for win
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(board[i][j] != move) {
                break;
            }
        }
        if(j == SIZE) {
            return 1;
        }
    }

    // Check columns for win
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(board[j][i] != move) {
                break;
            }
        }
        if(j == SIZE) {
            return 1;
        }
    }

    // Check diagonals for win
    for(i = 0; i < SIZE; i++) {
        if(board[i][i] != move) {
            break;
        }
    }
    if(i == SIZE) {
        return 1;
    }
    for(i = 0; i < SIZE; i++) {
        if(board[i][SIZE-i-1] != move) {
            break;
        }
    }
    if(i == SIZE) {
        return 1;
    }

    return 0;
}

int is_game_over() {
    int i, j; 
    
    // Check if game has been won
    if(evaluate_board(AI_MOVE)) {
        printf("\nThe computer has won!\n");
        return 1;
    }
    if(evaluate_board(PLAYER_MOVE)) {
        printf("\nCongratulations! You have won!\n");
        return 1;
    }

    // Check if game has tied
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(board[i][j] == '_') {
                return 0;
            }
        }
    }
    printf("\nThe game has tied!\n");
    return 1;
}

int minimax(int depth, int is_maximizing) {
    int i, j, best_score;
    char move;

    if(evaluate_board(AI_MOVE)) {
        return 1;
    } else if(evaluate_board(PLAYER_MOVE)) {
        return -1;
    } else if(is_game_over()) {
        return 0;
    }

    if(is_maximizing) {
        best_score = -100;
        move = AI_MOVE;
    } else {
        best_score = 100;
        move = PLAYER_MOVE;
    }

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(is_valid_move(i, j)) {
                board[i][j] = move;
                if(is_maximizing) {
                    best_score = best_score > minimax(depth+1, 0) ? best_score : minimax(depth+1, 0);
                } else {
                    best_score = best_score < minimax(depth+1, 1) ? best_score : minimax(depth+1, 1);
                }
                board[i][j] = '_';
            }
        }
    }
    return best_score;
}

void ai_move() {
    int i, j, best_score = -100, move_score;

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(is_valid_move(i, j)) {
                board[i][j] = AI_MOVE;
                move_score = minimax(0, 0);
                board[i][j] = '_';
                if(move_score > best_score) {
                    best_score = move_score;
                }
            }
        }
    }

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(is_valid_move(i, j)) {
                board[i][j] = AI_MOVE;
                move_score = minimax(0, 0);
                board[i][j] = '_';
                if(move_score == best_score) {
                    update_board(i, j, AI_MOVE);
                    return;
                }
            }
        }
    }
}

int main() {
    int row, col;

    initialize_board();
    display_board();

    while(1) {
        printf("Enter row and column (e.g. 1 2) for your move: ");
        scanf("%d %d", &row, &col);

        if(is_valid_move(row, col)) {
            update_board(row, col, PLAYER_MOVE);
            display_board();
            if(is_game_over()) {
                break;
            }
            ai_move();
            display_board();
            if(is_game_over()) {
                break;
            }
        } else {
            printf("\nInvalid move, please try again.\n");
        }
    }

    return 0;
}