//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: safe
#include <stdio.h>

#define BOARD_SIZE 3

/* Structure to store coordinates of a cell */
typedef struct {
    int row, col;
} Coordinate;

/* Function to print the current state of the board */
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n\nCurrent Board:\n\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c | %c | %c", board[i][0], board[i][1], board[i][2]);
        if (i != BOARD_SIZE - 1) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n\n");
}

/* Function to check if the game has ended */
int check_game_over(char board[BOARD_SIZE][BOARD_SIZE]) {
    /* Check if any row has the same player symbol */
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                return 1;
            }
            else if (board[i][0] == 'O') {
                return -1;
            }
        }
    }

    /* Check if any column has the same player symbol */
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == 'X') {
                return 1;
            }
            else if (board[0][j] == 'O') {
                return -1;
            }
        }
    }

    /* Check if any diagonal has the same player symbol */
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            return 1;
        }
        else if (board[0][0] == 'O') {
            return -1;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            return 1;
        }
        else if (board[0][2] == 'O') {
            return -1;
        }
    }

    /* Check if the board is full (tie) */
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    /* Game is over, but no winner */
    return 2;
}

/* Function to perform minimax algorithm with alpha-beta pruning */
int minimax(char board[BOARD_SIZE][BOARD_SIZE], int depth, int alpha, int beta, int maximizing_player) {
    int score = check_game_over(board);
    if (score == 1) {
        return depth - 10;
    }
    else if (score == -1) {
        return 10 - depth;
    }
    else if (score == 2) {
        return 0;
    }

    if (maximizing_player) {
        int best_score = -100000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int current_score = minimax(board, depth + 1, alpha, beta, 0);
                    board[i][j] = ' ';
                    if (current_score > best_score) {
                        best_score = current_score;
                    }
                    if (best_score > alpha) {
                        alpha = best_score;
                    }
                    if (alpha >= beta) {
                        break;
                    }
                }
            }
        }
        return best_score;
    }
    else {
        int best_score = 100000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int current_score = minimax(board, depth + 1, alpha, beta, 1);
                    board[i][j] = ' ';
                    if (current_score < best_score) {
                        best_score = current_score;
                    }
                    if (best_score < beta) {
                        beta = best_score;
                    }
                    if (alpha >= beta) {
                        break;
                    }
                }
            }
        }
        return best_score;
    }
}

/* Function to perform computer's move */
Coordinate computer_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    int best_score = -100000;
    Coordinate best_move;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int current_score = minimax(board, 0, -100000, 100000, 0);
                board[i][j] = ' ';
                if (current_score > best_score) {
                    best_score = current_score;
                    best_move.row = i;
                    best_move.col = j;
                }
            }
        }
    }
    return best_move;
}

/* Main function */
int main() {
    /* Initialize the board */
    char board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    /* Game loop */
    int turn = 0;
    while (check_game_over(board) == 0) {
        /* Print the board */
        print_board(board);

        /* Determine the current player */
        char current_player;
        if (turn % 2 == 0) {
            current_player = 'X';
        }
        else {
            current_player = 'O';
        }

        /* Perform player's move */
        Coordinate move;
        if (current_player == 'X') {
            printf("Enter your move (row column): ");
            scanf("%d %d", &move.row, &move.col);
            while (board[move.row][move.col] != ' ') {
                printf("That cell is already taken. Enter a valid move (row column): ");
                scanf("%d %d", &move.row, &move.col);
            }
            board[move.row][move.col] = current_player;
        }
        else {
            move = computer_move(board);
            printf("Computer played move (%d %d)\n", move.row, move.col);
            board[move.row][move.col] = 'O';
        }

        /* Switch player */
        turn++;
    }

    /* Game over */
    print_board(board);
    int score = check_game_over(board);
    if (score == 1) {
        printf("X wins!\n");
    }
    else if (score == -1) {
        printf("O wins!\n");
    }
    else {
        printf("Tie game!\n");
    }

    return 0;
}