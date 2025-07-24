//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// board size definition
#define ROWS 3
#define COLS 3

// function prototypes
void initialize_board(int board[][COLS]);
void print_board(int board[][COLS]);
bool is_valid_move(int board[][COLS], int row, int col);
bool is_winner(int board[][COLS], int player);
bool is_board_full(int board[][COLS]);
int evaluate_board(int board[][COLS], int player);
int minimax(int board[][COLS], int depth, int player);
void make_move(int board[][COLS], int player);
void get_human_move(int board[][COLS]);
void get_computer_move(int board[][COLS]);

// main function
int main() {
    // initialize the board and print it
    int board[ROWS][COLS];
    initialize_board(board);
    print_board(board);

    // game loop
    while (true) {
        // human turn
        get_human_move(board);
        print_board(board);
        if (is_winner(board, 1)) {
            printf("You win!\n");
            break;
        } else if (is_board_full(board)) {
            printf("It's a tie!\n");
            break;
        }

        // computer turn
        get_computer_move(board);
        printf("Computer's move:\n");
        print_board(board);
        if (is_winner(board, 2)) {
            printf("Computer wins!\n");
            break;
        } else if (is_board_full(board)) {
            printf("It's a tie!\n");
            break;
        }
    }

    return 0;
}

// initialize the board to empty cells (0)
void initialize_board(int board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

// print the board
void print_board(int board[][COLS]) {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("X\t");
            } else if (board[i][j] == 2) {
                printf("O\t");
            } else {
                printf("-\t");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// check if a move is valid
bool is_valid_move(int board[][COLS], int row, int col) {
    return (board[row][col] == 0);
}

// check if a player has won
bool is_winner(int board[][COLS], int player) {
    int i, j;

    // check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // check columns
    for (j = 0; j < COLS; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// check if the board is full
bool is_board_full(int board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

// evaluate the board for a player
int evaluate_board(int board[][COLS], int player) {
    if (is_winner(board, player)) {
        return 10;
    } else if (is_winner(board, 3 - player)) {
        return -10;
    } else {
        return 0;
    }
}

// use minimax algorithm to find best move for the computer player
int minimax(int board[][COLS], int depth, int player) {
    int i, j;
    int score;
    int best_score;
    int best_row = -1;
    int best_col = -1;

    // evaluate the board if depth limit is reached or game is won/tied
    if (depth == 0 || is_winner(board, 1) || is_winner(board, 2) || is_board_full(board)) {
        return evaluate_board(board, player);
    }

    // find the best move using minimax algorithm
    if (player == 2) { // computer's turn
        best_score = -100;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == 0) { // empty cell
                    board[i][j] = player; // make the move
                    score = minimax(board, depth - 1, 3 - player); // evaluate the board
                    if (score > best_score) { // update best move
                        best_score = score;
                        best_row = i;
                        best_col = j;
                    }
                    board[i][j] = 0; // undo the move
                }
            }
        }
    } else { // human's turn
        best_score = 100;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == 0) { // empty cell
                    board[i][j] = player; // make the move
                    score = minimax(board, depth - 1, 3 - player); // evaluate the board
                    if (score < best_score) { // update best move
                        best_score = score;
                        best_row = i;
                        best_col = j;
                    }
                    board[i][j] = 0; // undo the move
                }
            }
        }
    }

    if (depth == 6) {
        return best_row * 3 + best_col;
    } else {
        return best_score;
    }
}

// make a move for the player
void make_move(int board[][COLS], int player) {
    if (player == 1) {
        get_human_move(board);
    } else {
        get_computer_move(board);
    }
}

// get a move from the human player
void get_human_move(int board[][COLS]) {
    int row, col;
    do {
        printf("Enter row and column (0-2): ");
        scanf("%d %d", &row, &col);
    } while (!is_valid_move(board, row, col));
    board[row][col] = 1;
}

// get a move from the computer player
void get_computer_move(int board[][COLS]) {
    int move = minimax(board, 6, 2);
    int row = move / 3;
    int col = move % 3;
    board[row][col] = 2;
}