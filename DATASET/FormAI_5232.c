//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define MAX_DEPTH 9

char board[BOARD_SIZE][BOARD_SIZE];

// Function to print the Tic Tac Toe board
void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j != BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i != BOARD_SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check if the game is over
int check_game_over(char symbol) {
    // Check if symbol has won by getting three in a row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }
    // Check if symbol has won by getting three in a column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }
    // Check if symbol has won by getting three on a diagonal
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
            (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return 1;
    }
    // Check if all spaces on the board are filled, meaning the game is a draw
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Min-Max algorithm to determine best move for AI
int min_max(char symbol, int depth) {
    if (depth == MAX_DEPTH || check_game_over(symbol)) {
        if (check_game_over('O')) {
            return 10 - depth;
        } else if (check_game_over('X')) {
            return depth - 10;
        }
        return 0;
    }
    int best_move = -1, current_move_score;
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        int x = i / BOARD_SIZE, y = i % BOARD_SIZE;
        if (board[x][y] == ' ') {
            board[x][y] = symbol;
            if (symbol == 'O') {
                current_move_score = min_max('X', depth + 1);
            } else {
                current_move_score = min_max('O', depth + 1);
            }
            if ((symbol == 'O' && current_move_score > best_move) ||
                    (symbol == 'X' && current_move_score < best_move) || best_move == -1) {
                best_move = current_move_score;
            }
            board[x][y] = ' ';
        }
    }
    return best_move;
}

// Function for AI to make its move
void ai_move() {
    int best_move_score = -1, current_move_score;
    srand(time(NULL));
    int i = rand() % (BOARD_SIZE * BOARD_SIZE);
    int x = i / BOARD_SIZE, y = i % BOARD_SIZE;
    if (board[x][y] == ' ') {
        board[x][y] = 'O';
        if (check_game_over('O')) {
            return;
        } else {
            current_move_score = min_max('X', 0);
            best_move_score = current_move_score;
        }
        board[x][y] = ' ';
    }
    for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        x = i / BOARD_SIZE, y = i % BOARD_SIZE;
        if (board[x][y] == ' ') {
            board[x][y] = 'O';
            if (check_game_over('O')) {
                return;
            } else {
                current_move_score = min_max('X', 0);
                if (current_move_score > best_move_score) {
                    best_move_score = current_move_score;
                    return;
                }
            }
            board[x][y] = ' ';
        }
    }
}

int main() {
    // Initialize the board with empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are X and the computer is O.\n");
    while (!check_game_over('X') && !check_game_over('O')) {
        print_board();
        // Player's move
        int x, y;
        printf("Please enter the coordinates of your move (in the form x,y): ");
        scanf("%d,%d", &x, &y);
        if (board[x-1][y-1] == ' ') {
            board[x-1][y-1] = 'X';
        } else {
            printf("That space is already occupied. Please choose another.\n");
        }
        // AI's move
        ai_move();
    }
    print_board();
    if (check_game_over('X')) {
        printf("Congratulations! You won!\n");
    } else if (check_game_over('O')) {
        printf("Sorry, the computer won. Better luck next time!\n");
    } else {
        printf("The game is a draw!\n");
    }
    return 0;
}