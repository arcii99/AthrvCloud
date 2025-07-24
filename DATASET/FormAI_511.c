//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // Tic tac toe board
const char player = 'X'; // Player marker
const char ai = 'O'; // AI marker

// Display the current board state
void display_board() {
    printf("------------\nTic Tac Toe\n------------\n\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if(j != 2) {
                printf("|");
            }
        }
        printf("\n");
        if(i != 2) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

// Check if the game has ended in a win
int check_for_win(char marker) {
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == marker && board[i][1] == marker && board[i][2] == marker) {
            return 1;
        }
    }
    // Check columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == marker && board[1][i] == marker && board[2][i] == marker) {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == marker && board[1][1] == marker && board[2][2] == marker) {
        return 1;
    }
    if(board[0][2] == marker && board[1][1] == marker && board[2][0] == marker) {
        return 1;
    }
    return 0;
}

// Check if a move is valid
int is_valid_move(int row, int col) {
    return (board[row][col] == ' ');
}

// Make a random move for the AI
void ai_make_random_move() {
    srand(time(0)); // Seed the random number generator
    int row, col;
    do {
        row = rand() % 3; // Generate random row and column
        col = rand() % 3;
    } while(!is_valid_move(row, col));
    board[row][col] = ai; // Make the move
}

// Minimax algorithm for AI move selection
int minimax(char board[3][3], int depth, int is_max) {
    if(check_for_win(player)) {
        return -10 + depth;
    }
    if(check_for_win(ai)) {
        return 10 - depth;
    }
    if(depth == 0) {
        return 0;
    }
    if(is_max) { // Maximizing player (AI)
        int best_score = -1000; // Keep track of best move
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(is_valid_move(i, j)) {
                    board[i][j] = ai; // Make the move
                    int score = minimax(board, depth - 1, 0);
                    board[i][j] = ' '; // Undo the move
                    if(score > best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score; // Return the best move
    } else { // Minimizing player (Human)
        int best_score = 1000; // Keep track of best move
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(is_valid_move(i, j)) {
                    board[i][j] = player; // Make the move
                    int score = minimax(board, depth - 1, 1);
                    board[i][j] = ' '; // Undo the move
                    if(score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score; // Return the best move
    }
}

// Make a move for the AI using the minimax algorithm
void ai_make_move() {
    int best_score = -1000; // Keep track of best move
    int best_row = -1;
    int best_col = -1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(is_valid_move(i, j)) {
                board[i][j] = ai; // Make the move
                int score = minimax(board, 5, 0);
                board[i][j] = ' '; // Undo the move
                if(score > best_score) {
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }
    board[best_row][best_col] = ai; // Make the best move
}

// Main program
int main() {
    // Initialize the board
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    int turn = 0; // 0 for player, 1 for AI
    while(!check_for_win(player) && !check_for_win(ai) && turn < 9) {
        display_board(); // Display the board
        if(turn % 2 == 0) { // Player turn
            int row, col;
            printf("Make your move (row column): ");
            scanf("%d %d", &row, &col);
            if(is_valid_move(row, col)) {
                board[row][col] = player; // Make the move
                turn++;
            } else {
                printf("Invalid move, try again.\n");
            }
        } else { // AI turn
            printf("The AI is thinking...\n");
            ai_make_move(); // Make the move
            turn++;
        }
    }
    display_board(); // Display the game result
    if(check_for_win(player)) {
        printf("Congratulations, you win!\n");
    } else if(check_for_win(ai)) {
        printf("Sorry, you lose.\n");
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}