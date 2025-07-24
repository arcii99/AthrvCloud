//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

char board[SIZE][SIZE]; // Tic Tac Toe board

// Initializes the board to contain empty spaces
void init_board() {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Prints the current board state
void print_board() {
    printf("\n   |   |   \n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("   |   |   \n");
}

// Checks if the board is full with no remaining moves
int board_full() {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Checks if a player has won the game
int check_win(char player) {
    for (int i=0; i<SIZE; i++) {
        // Check horizontal rows
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        // Check vertical columns
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// Evaluates the current board state for the AI
int evaluate() {
    if (check_win('X')) {
        return 10;
    } else if (check_win('O')) {
        return -10;
    } else {
        return 0;
    }
}

// Recursive function that implements the minimax algorithm to determine the best move
int minimax(int depth, int is_max) {
    int score = evaluate();
    if (score == 10) {
        return score - depth;
    }
    if (score == -10) {
        return score + depth;
    }
    if (board_full()) {
        return 0;
    }
    int best_score;
    if (is_max) {
        best_score = -1000;
        for (int i=0; i<SIZE; i++) {
            for (int j=0; j<SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int current_score = minimax(depth+1, !is_max);
                    board[i][j] = ' ';
                    if (current_score > best_score) {
                        best_score = current_score;
                    }
                }
            }
        }
    } else {
        best_score = 1000;
        for (int i=0; i<SIZE; i++) {
            for (int j=0; j<SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int current_score = minimax(depth+1, !is_max);
                    board[i][j] = ' ';
                    if (current_score < best_score) {
                        best_score = current_score;
                    }
                }
            }
        }
    }
    return best_score;
}

// Generates the AI's move using the minimax algorithm
void ai_move() {
    int best_score = -1000;
    int best_move_i = -1;
    int best_move_j = -1;
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                int current_score = minimax(0, 0);
                board[i][j] = ' ';
                if (current_score > best_score) {
                    best_score = current_score;
                    best_move_i = i;
                    best_move_j = j;
                }
            }
        }
    }
    board[best_move_i][best_move_j] = 'X';
}

// Main game loop
int main() {
    init_board();
    print_board();
    while (!check_win('X') && !check_win('O') && !board_full()) {
        // Player move
        int player_i, player_j;
        printf("\nEnter row and column numbers to make your move (0-2)\n");
        scanf("%d %d", &player_i, &player_j);
        while (board[player_i][player_j] != ' ') {
            printf("Invalid move, try again\n");
            scanf("%d %d", &player_i, &player_j);
        }
        board[player_i][player_j] = 'O';
        print_board();
        if (check_win('O') || board_full()) {
            break;
        }
        // AI move
        printf("\nAI is making a move...\n");
        ai_move();
        print_board();
    }
    if (check_win('O')) {
        printf("\nCongratulations! You win.\n");
    } else if (check_win('X')) {
        printf("\nYou lost. Better luck next time!\n");
    } else {
        printf("\nIt's a tie.\n");
    }
    return 0;
}