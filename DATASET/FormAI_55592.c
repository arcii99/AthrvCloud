//FormAI DATASET v1.0 Category: Chess AI ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

// Function prototypes
void print_board(char board[][BOARD_SIZE]);
void initialize_board(char board[][BOARD_SIZE]);
void computer_move(char board[][BOARD_SIZE], char player);
int evaluate_board(char board[][BOARD_SIZE], char player);
int minimax(char board[][BOARD_SIZE], char player, int depth, int alpha, int beta);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    char player = 'X';
    
    // Main game loop
    while (1) {
        // Player's turn
        printf("Enter row (1-8) and column (a-h) of your move (e.g. 5d): ");
        int row, col;
        char col_char;
        scanf("%d%c", &row, &col_char);
        col = col_char-'a';
        if (board[row-1][col] != '-') {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        board[row-1][col] = player;
        print_board(board);
        int board_score = evaluate_board(board, player);
        if (board_score == 100) {
            printf("%c wins!\n", player);
            break;
        } else if (board_score == 0) {
            printf("Tie game.\n");
            break;
        }
        
        // Computer's turn (using minimax algorithm)
        printf("Computer's turn...\n");
        computer_move(board, player);
        print_board(board);
        board_score = evaluate_board(board, player);
        if (board_score == -100) {
            printf("%c wins!\n", (player == 'X') ? 'O' : 'X');
            break;
        } else if (board_score == 0) {
            printf("Tie game.\n");
            break;
        }
    }
    
    return 0;
}

// Prints the current state of the board
void print_board(char board[][BOARD_SIZE]) {
    printf("\n  a b c d e f g h\n");
    for (int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for (int j=0; j<BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i+1);
    }
    printf("  a b c d e f g h\n\n");
}

// Sets the board to its initial state
void initialize_board(char board[][BOARD_SIZE]) {
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    board[3][3] = 'O';
    board[4][4] = 'O';
    board[3][4] = 'X';
    board[4][3] = 'X';
}

// Calculates the score of the board for the given player
int evaluate_board(char board[][BOARD_SIZE], char player) {
    int score = 0;
    char opponent = (player == 'X') ? 'O' : 'X';
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                score++;
            } else if (board[i][j] == opponent) {
                score--;
            }
        }
    }
    return score;
}

// Calls the minimax function and performs the computer's move
void computer_move(char board[][BOARD_SIZE], char player) {
    int best_score = -1000000;
    int best_row = -1;
    int best_col = -1;
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            if (board[i][j] == '-') {
                board[i][j] = player;
                int score = minimax(board, player, 4, -1000000, 1000000);
                board[i][j] = '-';
                if (score > best_score) {
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }
    board[best_row][best_col] = player;
}

// Minimax algorithm with alpha-beta pruning
int minimax(char board[][BOARD_SIZE], char player, int depth, int alpha, int beta) {
    if (depth == 0) {
        return evaluate_board(board, player);
    }
    char opponent = (player == 'X') ? 'O' : 'X';
    if (player == 'X') {
        int best_score = -1000000;
        for (int i=0; i<BOARD_SIZE; i++) {
            for (int j=0; j<BOARD_SIZE; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = player;
                    int score = minimax(board, opponent, depth-1, alpha, beta);
                    board[i][j] = '-';
                    if (score > best_score) {
                        best_score = score;
                    }
                    if (best_score > alpha) {
                        alpha = best_score;
                    }
                    if (alpha >= beta) {
                        return best_score;
                    }
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000000;
        for (int i=0; i<BOARD_SIZE; i++) {
            for (int j=0; j<BOARD_SIZE; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = player;
                    int score = minimax(board, opponent, depth-1, alpha, beta);
                    board[i][j] = '-';
                    if (score < best_score) {
                        best_score = score;
                    }
                    if (best_score < beta) {
                        beta = best_score;
                    }
                    if (alpha >= beta) {
                        return best_score;
                    }
                }
            }
        }
        return best_score;
    }
}