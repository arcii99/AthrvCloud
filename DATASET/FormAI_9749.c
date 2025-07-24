//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdio.h>

// Function to print the Tic Tac Toe game board
void print_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check for a win in the game board
int check_win(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
        return 1;
    return 0;
}

// Function to determine the best move for the AI player
void ai_move(char board[3][3]) {
    int best_score = -1000;
    int best_i = -1, best_j = -1;
    // Check each possible move on the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '_') {
                board[i][j] = 'O';
                int score = minimax(board, 0, 0);
                board[i][j] = '_';
                // Choose the move with the highest score
                if (score > best_score) {
                    best_score = score;
                    best_i = i;
                    best_j = j;
                }
            }
        }
    }
    // Make the best move for the AI player
    board[best_i][best_j] = 'O';
    printf("AI makes move: (%d, %d)\n", best_i+1, best_j+1);
}

// Function to perform the minimax algorithm on the game board
int minimax(char board[3][3], int depth, int is_max) {
    // Check if a player has won
    if (check_win(board, 'O')) {
        return 10 - depth;
    } else if (check_win(board, 'X')) {
        return depth - 10;
    } else if (is_full(board)) {
        return 0;
    }
    // Check each possible move on the board
    if (is_max) {
        int best_score = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = 'O';
                    int score = minimax(board, depth+1, 0);
                    board[i][j] = '_';
                    // Choose the move with the highest score
                    if (score > best_score)
                        best_score = score;
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = 'X';
                    int score = minimax(board, depth+1, 1);
                    board[i][j] = '_';
                    // Choose the move with the lowest score
                    if (score < best_score)
                        best_score = score;
                }
            }
        }
        return best_score;
    }
}

// Function to check if the game board is full
int is_full(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '_')
                return 0;
        }
    }
    return 1;
}

int main() {
    char board[3][3] = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are X, and the AI is O.\n");
    while (1) {
        print_board(board);
        // Player's turn
        int row, col;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &row, &col);
        if (board[row-1][col-1] == '_') {
            board[row-1][col-1] = 'X';
            if (check_win(board, 'X')) {
                printf("You win!\n");
                print_board(board);
                break;
            }
            if (is_full(board)) {
                printf("Draw.\n");
                print_board(board);
                break;
            }
            // AI's turn
            ai_move(board);
            if (check_win(board, 'O')) {
                printf("AI wins!\n");
                print_board(board);
                break;
            }
            if (is_full(board)) {
                printf("Draw.\n");
                print_board(board);
                break;
            }
        } else {
            printf("Invalid move.\n");
        }
    }
    return 0;
}