//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // The Tic Tac Toe board
char player = 'X'; // The current player (initially X)
int moves = 0; // The total number of moves played

// Function to draw the Tic Tac Toe board
void draw_board() {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if the current player has won
int check_win() {
    int i;
    for (i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

// Function to check if the current game is a tie
int check_tie() {
    return moves == 9;
}

// Function to get the move from the user
void get_move() {
    int row, col;
    printf("Player %c's turn.\n", player);
    printf("Enter row (1-3): ");
    scanf("%d", &row);
    printf("Enter column (1-3): ");
    scanf("%d", &col);
    // Convert from 1-based to 0-based indexing
    row--;
    col--;
    // Check if the move is valid
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        printf("Invalid move. Try again.\n");
        get_move();
    } else {
        board[row][col] = player;
        moves++;
    }
}

// Function to get the best move for the AI (using the minimax algorithm)
int get_best_move() {
    int row, col, best_score = -100, score, i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                score = -minimax(1);
                board[i][j] = ' ';
                if (score > best_score) {
                    best_score = score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    return row * 3 + col;
}

// Function to calculate the minimax score for the given board state
int minimax(int depth) {
    int i, j, score;
    if (check_win()) {
        // AI wins -> score = 10 - depth
        // Player wins -> score = depth - 10
        return (player == 'O') ? (10 - depth) : (depth - 10);
    }
    if (check_tie())
        return 0;
    if (player == 'O') {
        // Maximizing player (AI)
        score = -100;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    score = max(score, minimax(depth + 1));
                    board[i][j] = ' ';
                }
            }
        }
        return score;
    } else {
        // Minimizing player (human)
        score = 100;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    score = min(score, minimax(depth + 1));
                    board[i][j] = ' ';
                }
            }
        }
        return score;
    }
}

// Utility function to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Utility function to find minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Main function
int main() {
    int i, j, move;
    // Initialize the board to all empty spaces
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = ' ';
    while (!check_win() && !check_tie()) {
        draw_board();
        if (player == 'X')
            get_move();
        else {
            // AI's turn
            move = get_best_move();
            board[move/3][move%3] = 'O';
            moves++;
            printf("AI played at (%d,%d).\n", move/3+1, move%3+1);
        }
        // Switch players
        player = (player == 'X') ? 'O' : 'X';
    }
    draw_board();
    if (check_win())
        printf("Player %c wins!\n", player);
    else
        printf("It's a tie!\n");
    return 0;
}