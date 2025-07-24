//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // Tic Tac Toe board
int player = 1; // Player turn
char player1 = 'X'; // Player 1 symbol
char player2 = 'O'; // AI symbol

// Initialize the board
void initialize_board() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the board
void print_board() {
    printf("\n-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

// Make a move
void make_move(int row, int col, char symbol) {
    board[row][col] = symbol;
}

// Check the status of the board
int check_board() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            if (board[i][0] == player1) {
                return 10;
            } else if (board[i][0] == player2) {
                return -10;
            }
        }
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            if (board[0][i] == player1) {
                return 10;
            } else if (board[0][i] == player2) {
                return -10;
            }
        }
    }

    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        if (board[0][0] == player1) {
            return 10;
        } else if (board[0][0] == player2) {
            return -10;
        }
    }

    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
        if (board[0][2] == player1) {
            return 10;
        } else if (board[0][2] == player2) {
            return -10;
        }
    }

    return 0;
}

// Minimax AI algorithm
int minimax(int depth, int is_max) {
    int score = check_board();

    if (score == 10 || score == -10) {
        return score;
    }

    if (depth == 0) {
        return 0;
    }

    if (is_max) {
        int best_score = -1000;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = player1;

                    int current_score = minimax(depth - 1, !is_max);

                    board[i][j] = ' ';
                    best_score = (current_score > best_score) ? current_score : best_score;
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = player2;

                    int current_score = minimax(depth - 1, !is_max);

                    board[i][j] = ' ';
                    best_score = (current_score < best_score) ? current_score : best_score;
                }
            }
        }
        return best_score;
    }
}

// AI makes a move
void ai_move() {
    int best_score = -1000;
    int row, col;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player1;

                int current_score = minimax(2, 0);

                board[i][j] = ' ';

                if (current_score > best_score) {
                    best_score = current_score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    make_move(row, col, player1);
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 uses 'X' and goes first.\n");

    // Initialize the board
    initialize_board();

    // Game loop
    while (1) {
        // Print the board
        print_board();

        // Player turn
        if (player == 1) {
            int row, col;

            printf("\nPlayer 1, enter a row and column (1-3): ");
            scanf("%d %d", &row, &col);
            row--;
            col--;

            // Check if move is valid
            if (board[row][col] == ' ') {
                make_move(row, col, player1);
                player = 2;
            } else {
                printf("\nInvalid move. Try again.\n\n");
                continue;
            }
        }
        // AI turn
        else {
            printf("\nAI is thinking...\n");
            ai_move();
            player = 1;
        }

        // Check if game is over
        if (check_board() == 10) {
            // Print the board
            print_board();

            printf("\nPlayer 1 wins!\n\n");
            break;
        } else if (check_board() == -10) {
            // Print the board
            print_board();

            printf("\nAI wins!\n\n");
            break;
        } else if (check_board() == 0 && player == 1) {
            // Print the board
            print_board();

            printf("\nThe game is a tie!\n\n");
            break;
        }
    }

    return 0;
}