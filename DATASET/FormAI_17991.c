//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 3
#define HUMAN_PLAYER 'X'
#define COMPUTER_PLAYER 'O'
#define EMPTY_CELL '-'

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = EMPTY_CELL;
        }
    }
}

void print_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

bool is_move_valid(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false;
    }
    if (board[row][col] != EMPTY_CELL) {
        return false;
    }
    return true;
}

bool is_game_over() {
    // Check rows
    for (int row = 0; row < BOARD_SIZE; row++) {
        if (board[row][0] == board[row][1] && board[row][0] == board[row][2] && board[row][0] != EMPTY_CELL) {
            return true;
        }
    }
    // Check columns
    for (int col = 0; col < BOARD_SIZE; col++) {
        if (board[0][col] == board[1][col] && board[0][col] == board[2][col] && board[0][col] != EMPTY_CELL) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != EMPTY_CELL) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != EMPTY_CELL) {
        return true;
    }
    // Check if there are empty cells left
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY_CELL) {
                return false;
            }
        }
    }
    // No winner and no empty cells left, it's a draw
    return true;
}

int evaluate_board() {
    // Check rows
    for (int row = 0; row < BOARD_SIZE; row++) {
        if (board[row][0] == board[row][1] && board[row][0] == board[row][2]) {
            if (board[row][0] == HUMAN_PLAYER) {
                return -10;
            }
            else if (board[row][0] == COMPUTER_PLAYER) {
                return 10;
            }
        }
    }
    // Check columns
    for (int col = 0; col < BOARD_SIZE; col++) {
        if (board[0][col] == board[1][col] && board[0][col] == board[2][col]) {
            if (board[0][col] == HUMAN_PLAYER) {
                return -10;
            }
            else if (board[0][col] == COMPUTER_PLAYER) {
                return 10;
            }
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        if (board[0][0] == HUMAN_PLAYER) {
            return -10;
        }
        else if (board[0][0] == COMPUTER_PLAYER) {
            return 10;
        }
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        if (board[0][2] == HUMAN_PLAYER) {
            return -10;
        }
        else if (board[0][2] == COMPUTER_PLAYER) {
            return 10;
        }
    }
    // If no winner, return 0
    return 0;
}

int minimax(bool is_maximizing_player) {
    int score = evaluate_board();
    if (score == 10 || score == -10 || is_game_over()) {
        return score;
    }
    if (is_maximizing_player) {
        int best_score = -1000;
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                if (board[row][col] == EMPTY_CELL) {
                    board[row][col] = COMPUTER_PLAYER;
                    int current_score = minimax(false);
                    board[row][col] = EMPTY_CELL;
                    if (current_score > best_score) {
                        best_score = current_score;
                    }
                }
            }
        }
        return best_score;
    }
    else {
        int best_score = 1000;
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                if (board[row][col] == EMPTY_CELL) {
                    board[row][col] = HUMAN_PLAYER;
                    int current_score = minimax(true);
                    board[row][col] = EMPTY_CELL;
                    if (current_score < best_score) {
                        best_score = current_score;
                    }
                }
            }
        }
        return best_score;
    }
}

void make_computer_move() {
    int best_score = -1000;
    int best_row = -1;
    int best_col = -1;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY_CELL) {
                board[row][col] = COMPUTER_PLAYER;
                int current_score = minimax(false);
                board[row][col] = EMPTY_CELL;
                if (current_score > best_score) {
                    best_score = current_score;
                    best_row = row;
                    best_col = col;
                }
            }
        }
    }
    board[best_row][best_col] = COMPUTER_PLAYER;
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are playing as %c. The computer is playing as %c.\n", HUMAN_PLAYER, COMPUTER_PLAYER);
    printf("To make a move, enter the row (1-3) followed by the column (1-3).\n");
    initialize_board();
    print_board();
    while (!is_game_over()) {
        // Human player move
        int human_row, human_col;
        do {
            printf("Enter your move (row column): ");
            scanf("%d %d", &human_row, &human_col);
            human_row -= 1;
            human_col -= 1;
        } while (!is_move_valid(human_row, human_col));
        board[human_row][human_col] = HUMAN_PLAYER;
        print_board();
        if (is_game_over()) {
            break;
        }
        // Computer player move
        printf("The computer is making its move...\n");
        make_computer_move();
        print_board();
    }
    int score = evaluate_board();
    if (score == 0) {
        printf("It's a draw!\n");
    }
    else if (score > 0) {
        printf("The computer wins!\n");
    }
    else {
        printf("You win!\n");
    }
    return 0;
}