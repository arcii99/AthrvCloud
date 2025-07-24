//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include <stdio.h>
#include <limits.h>

#define SIZE 3 // board size

enum {X, O, EMPTY}; // player symbols
enum {MIN, MAX}; // minimax player roles

int board[SIZE][SIZE]; // the board state

int evaluate(void) {
    // evaluate the current board state
    // return 10*X + 1 if X wins, -10*O - 1 if O wins, 0 otherwise
    int row, col, diag1 = 0, diag2 = 0;
    for (row = 0; row < SIZE; ++row) {
        int sum_row = 0, sum_col = 0;
        for (col = 0; col < SIZE; ++col) {
            sum_row += board[row][col];
            sum_col += board[col][row];
            if (row == col) diag1 += board[row][col];
            if (row == SIZE - col - 1) diag2 += board[row][col];
        }
        if (sum_row == 3*X || sum_col == 3*X) return 10*X + 1;
        if (sum_row == 3*O || sum_col == 3*O) return -10*O - 1;
    }
    if (diag1 == 3*X || diag2 == 3*X) return 10*X + 1;
    if (diag1 == 3*O || diag2 == 3*O) return -10*O - 1;
    return 0;
}

int isfull(void) {
    // check if the board is full
    int row, col;
    for (row = 0; row < SIZE; ++row)
        for (col = 0; col < SIZE; ++col)
            if (board[row][col] == EMPTY) return 0;
    return 1;
}

int minimax(int depth, int alpha, int beta, int role) {
    // the minimax algorithm with alpha-beta pruning
    int row, col, best_row = -1, best_col = -1;
    int score = evaluate();
    if (score) return score; // gameover
    if (isfull()) return 0; // draw
    if (role == MAX) { // maximize
        int max_score = INT_MIN;
        for (row = 0; row < SIZE; ++row)
            for (col = 0; col < SIZE; ++col)
                if (board[row][col] == EMPTY) {
                    board[row][col] = X;
                    int curr_score = minimax(depth + 1, alpha, beta, MIN);
                    board[row][col] = EMPTY;
                    if (curr_score > max_score) {
                        max_score = curr_score;
                        best_row = row;
                        best_col = col;
                    }
                    alpha = (alpha > max_score) ? alpha : max_score;
                    if (beta <= alpha) break; // beta cutoff
                }
        if (depth == 0) board[best_row][best_col] = X; // make move
        return max_score;
    } else { // minimize
        int min_score = INT_MAX;
        for (row = 0; row < SIZE; ++row)
            for (col = 0; col < SIZE; ++col)
                if (board[row][col] == EMPTY) {
                    board[row][col] = O;
                    int curr_score = minimax(depth + 1, alpha, beta, MAX);
                    board[row][col] = EMPTY;
                    if (curr_score < min_score) {
                        min_score = curr_score;
                        best_row = row;
                        best_col = col;
                    }
                    beta = (beta < min_score) ? beta : min_score;
                    if (beta <= alpha) break; // alpha cutoff
                }
        if (depth == 0) board[best_row][best_col] = O; // make move
        return min_score;
    }
}

void display(void) {
    // print the board state
    int row, col;
    for (row = 0; row < SIZE; ++row) {
        for (col = 0; col < SIZE; ++col)
            printf("%c ", (board[row][col] == X) ? 'X' : (board[row][col] == O) ? 'O' : '-');
        printf("\n");
    }
}

void play(void) {
    // play the game
    int turn = X, row, col;
    while (!isfull()) {
        display();
        if (turn == X) {
            printf("Player X's turn: ");
            scanf("%d %d", &row, &col);
            if (board[row][col] == EMPTY) {
                board[row][col] = X;
                turn = O;
            }
        } else {
            printf("Player O's turn: ");
            minimax(0, INT_MIN, INT_MAX, MIN);
            turn = X;
        }
        int score = evaluate();
        if (score) {
            display();
            printf((score == 10*X + 1) ? "Player X wins!\n" : "Player O wins!\n");
            return;
        }
    }
    display();
    printf("It's a draw!\n");
}

int main(void) {
    int i, j;
    for (i = 0; i < SIZE; ++i)
        for (j = 0; j < SIZE; ++j) board[i][j] = EMPTY;
    play();
    return 0;
}