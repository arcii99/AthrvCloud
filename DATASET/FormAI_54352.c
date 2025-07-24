//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE]; // The Tic Tac Toe board

// Initialize the board with empty spaces
void init_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the board
void display_board() {
    printf("\n");
    printf("   1   2   3\n");
    printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---+---+---\n");
    printf("3  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Check if a move is valid
bool is_valid_move(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return false;
    }
    if (board[row][col] != ' ') {
        return false;
    }
    return true;
}

// Check if the game is over
bool is_game_over() {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }
    // Check diagonal
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    // Check if the board is full
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Check if the game is won by the given player
bool is_game_won(char player) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }
    // Check diagonal
    if (board[0][0] == player && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == player && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

// Minimax algorithm with alpha-beta pruning
int minimax(char player, int depth, int alpha, int beta) {
    if (is_game_over()) {
        // Game over, return the score
        if (is_game_won('O')) {
            // Computer won
            return 10 - depth;
        } else if (is_game_won('X')) {
            // Player won
            return depth - 10;
        } else {
            // Tie
            return 0;
        }
    }
    if (player == 'O') {
        // Maximizer's turn
        int best_score = -1000000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax('X', depth+1, alpha, beta);
                    board[i][j] = ' ';
                    if (score > best_score) {
                        best_score = score;
                    }
                    if (best_score > alpha) {
                        alpha = best_score;
                    }
                    if (beta <= alpha) {
                        // Prune the branch
                        break;
                    }
                }
            }
        }
        return best_score;
    } else {
        // Minimizer's turn
        int best_score = 1000000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = minimax('O', depth+1, alpha, beta);
                    board[i][j] = ' ';
                    if (score < best_score) {
                        best_score = score;
                    }
                    if (beta < best_score) {
                        beta = best_score;
                    }
                    if (beta <= alpha) {
                        // Prune the branch
                        break;
                    }
                }
            }
        }
        return best_score;
    }
}

// Make the computer move
void make_computer_move() {
    int best_score = -1000000;
    int best_row, best_col;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int score = minimax('X', 0, -1000000, 1000000);
                board[i][j] = ' ';
                if (score > best_score) {
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }
    board[best_row][best_col] = 'O';
}

// Play the game
void play_game() {
    init_board();
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are playing as X, and the computer is playing as O.\n");
    display_board();
    while (!is_game_over()) {
        int row, col;
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        row--;
        col--;
        if (is_valid_move(row, col)) {
            board[row][col] = 'X';
            display_board();
            if (is_game_over()) {
                break;
            }
            make_computer_move();
            display_board();
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
    if (is_game_won('O')) {
        printf("The computer won.\n");
    } else if (is_game_won('X')) {
        printf("You won!\n");
    } else {
        printf("It's a tie.\n");
    }
}

int main() {
    play_game();
    return 0;
}