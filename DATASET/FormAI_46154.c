//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

char board[3][3];    // Tic Tac Toe board
const char human = 'X';   // Player
const char ai = 'O';  // AI
const char empty = '-';    // Empty cell

// Function to print the board
void print_board() {
    printf("\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf(" %c ", board[i][j]);
            if (j != 2)
                printf("|");
        }
        printf("\n");
        if (i != 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if the game is over
int game_over() {
    // Check for a win in each row
    for (int i=0; i<3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return 1;
    }
    // Check for a win in each column
    for (int i=0; i<3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return 1;
    }
    // Check for a win in diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return 1;
    
    // Check for a tie
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] == empty)
                return 0;
        }
    }
    return 2;
}

// Function for the AI to make a move
int ai_move() {
    int move_score = -1000;
    int move_i, move_j;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] == empty) {
                board[i][j] = ai;
                int score = minimax(0, 0);
                board[i][j] = empty;
                if (score > move_score) {
                    move_score = score;
                    move_i = i;
                    move_j = j;
                }
            }
        }
    }
    board[move_i][move_j] = ai;
    return 0;
}

// Minimax function
int minimax(int depth, int isMax) {
    int result = game_over();
    if (result) {
        if (result == 2)
            return 0;
        if (isMax)
            return -10 + depth;
        else
            return 10 - depth;
    }
    if (isMax) {
        int best_score = -1000;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (board[i][j] == empty) {
                    board[i][j] = ai;
                    int score = minimax(depth+1, 0);
                    board[i][j] = empty;
                    if (score > best_score)
                        best_score = score;
                }
            }
        }
        return best_score;
    }
    else {
        int best_score = 1000;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (board[i][j] == empty) {
                    board[i][j] = human;
                    int score = minimax(depth+1, 1);
                    board[i][j] = empty;
                    if (score < best_score)
                        best_score = score;
                }
            }
        }
        return best_score;
    }
}

// Main function to play Tic Tac Toe
int main() {
    int game_status = 0;
    // Initialize the board
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            board[i][j] = empty;
        }
    }
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are playing as 'X'.\n");
    while (!game_status) {
        int row, col;
        // Player's turn
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);
        if (row > 3 || col > 3 || row < 1 || col < 1 || board[row-1][col-1] != empty) {
            printf("Invalid move, try again.\n");
            continue;
        }
        board[row-1][col-1] = human;
        print_board();
        // Check for game over
        game_status = game_over();
        if (game_status) break;
        // AI's turn
        printf("AI's turn.\n");
        ai_move();
        print_board();
        // Check for game over
        game_status = game_over();
    }
    // Print game outcome
    if (game_status == 2)
        printf("The game is a tie.\n");
    else if (game_status == 1)
        printf("You lost. Better luck next time!\n");
    else
        printf("Congratulations! You won!\n");
    return 0;
}