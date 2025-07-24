//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Function prototypes
void draw_board(char board[ROWS][COLS]);
int check_winner(char board[ROWS][COLS], char symbol);
int minimax(char board[ROWS][COLS], int depth, int is_maximizing, char maximizing_symbol, char minimizing_symbol);
int get_best_move(char board[ROWS][COLS], char symbol);
void get_computer_move(char board[ROWS][COLS], char symbol);
void get_user_move(char board[ROWS][COLS], char symbol);

// Function to draw the Tic Tac Toe board
void draw_board(char board[ROWS][COLS]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if a player has won
int check_winner(char board[ROWS][COLS], char symbol) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }
    // Check columns
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    return 0;
}

// Minimax function to get best move
int minimax(char board[ROWS][COLS], int depth, int is_maximizing, char maximizing_symbol, char minimizing_symbol) {
    // Check if game is over or maximum depth has been reached
    int winner = check_winner(board, maximizing_symbol) || check_winner(board, minimizing_symbol);
    if (winner || depth == 0) {
        if (winner) {
            if (check_winner(board, maximizing_symbol)) {
                return 1;
            } else {
                return -1;
            }
        } else {
            return 0;
        }
    }
    // Maximizing player's turn
    if (is_maximizing) {
        int best_score = -1000;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = maximizing_symbol;
                    int score = minimax(board, depth - 1, 0, maximizing_symbol, minimizing_symbol);
                    board[i][j] = ' ';
                    if (score > best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
    // Minimizing player's turn
    else {
        int best_score = 1000;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = minimizing_symbol;
                    int score = minimax(board, depth - 1, 1, maximizing_symbol, minimizing_symbol);
                    board[i][j] = ' ';
                    if (score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
}

// Function to get best move
int get_best_move(char board[ROWS][COLS], char symbol) {
    int best_score = -1000;
    int best_row, best_col;
    // Call minimax function for all vacant spots on board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = symbol;
                int score = minimax(board, 3, 0, 'X', 'O');
                board[i][j] = ' ';
                if (score > best_score) {
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }
    return best_row * 3 + best_col;
}

// Function to get computer's move
void get_computer_move(char board[ROWS][COLS], char symbol) {
    printf("Computer's turn (%c):\n", symbol);
    // Wait for a moment to make it look like computer is thinking
    srand(time(NULL));
    int wait_time = rand() % 3 + 1;
    printf("Thinking...");
    fflush(stdout);
    sleep(wait_time);
    // Get best move and make the move
    int best_move = get_best_move(board, symbol);
    int row = best_move / 3;
    int col = best_move % 3;
    board[row][col] = symbol;
    printf("Computer made move at row %d, column %d\n", row + 1, col + 1);
    draw_board(board);
}

// Function to get user's move
void get_user_move(char board[ROWS][COLS], char symbol) {
    printf("Your turn (%c):\n", symbol);
    int row, col;
    // Get user input for row and column
    do {
        printf("Enter row number (1-3): ");
        scanf("%d", &row);
        row--;
        printf("Enter column number (1-3): ");
        scanf("%d", &col);
        col--;
        if (board[row][col] != ' ') {
            printf("That spot is already taken. Please choose another.\n");
        }
    } while (board[row][col] != ' ');
    // Make the move
    board[row][col] = symbol;
    draw_board(board);
}

int main() {
    char board[ROWS][COLS];
    // Initialize the board with empty spaces
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
    // Draw initial board
    draw_board(board);
    // Randomly assign who goes first
    srand(time(NULL));
    int first_turn = rand() % 2;
    char user_symbol, computer_symbol;
    if (first_turn) {
        printf("You go first!\n");
        user_symbol = 'X';
        computer_symbol = 'O';
    } else {
        printf("Computer goes first!\n");
        user_symbol = 'O';
        computer_symbol = 'X';
    }
    // Game loop
    int turn_count = 0;
    while (1) {
        if (first_turn) {
            if (turn_count % 2 == 0) {
                get_user_move(board, user_symbol);
                if (check_winner(board, user_symbol)) {
                    printf("You win!!!\n");
                    break;
                }
            } else {
                get_computer_move(board, computer_symbol);
                if (check_winner(board, computer_symbol)) {
                    printf("Computer wins!!!\n");
                    break;
                }
            }
        } else {
            if (turn_count % 2 == 0) {
                get_computer_move(board, computer_symbol);
                if (check_winner(board, computer_symbol)) {
                    printf("Computer wins!!!\n");
                    break;
                }
            } else {
                get_user_move(board, user_symbol);
                if (check_winner(board, user_symbol)) {
                    printf("You win!!!\n");
                    break;
                }
            }
        }
        turn_count++;
        // Check if game ends in a draw
        if (turn_count == ROWS * COLS) {
            printf("Game ends in a draw!!!\n");
            break;
        }
    }
    return 0;
}