//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define PLAYER 1
#define COMPUTER 2

void init_board(char board[SIZE][SIZE]) {
    // Initialize game board
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[SIZE][SIZE]) {
    // Print the game board
    int i, j;
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[SIZE][SIZE], char symbol) {
    // Check for a winner
    if ((board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) ||
        (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol) ||
        (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol) ||
        (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) ||
        (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol) ||
        (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol) ||
        (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
        return 1;
    else
        return 0;
}

int minimax(char board[SIZE][SIZE], int depth, int is_max, int alpha, int beta) {
    // Minimax algorithm with alpha-beta pruning
    if (check_win(board, PLAYER))
        return -10;
    if (check_win(board, COMPUTER))
        return 10;
    if (depth == 9)
        return 0;

    int i, j, score;
    if (is_max) {
        score = -1000;
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = COMPUTER;
                    score = (score > minimax(board, depth+1, !is_max, alpha, beta)) ? score : minimax(board, depth+1, !is_max, alpha, beta);
                    board[i][j] = '-';
                    alpha = (alpha > score) ? alpha : score;
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return score;

    } else {
        score = 1000;
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = PLAYER;
                    score = (score < minimax(board, depth+1, !is_max, alpha, beta)) ? score : minimax(board, depth+1, !is_max, alpha, beta);
                    board[i][j] = '-';
                    beta = (beta < score) ? beta : score;
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return score;
    }
}

void make_move(char board[SIZE][SIZE], int player) {
    // Make a move based on player input
    int row, col;
    do {
        printf("\nEnter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        row--;
        col--;
    } while (board[row][col] != '-');

    if (player == 1)
        board[row][col] = 'X';
    if (player == 2)
        board[row][col] = 'O';
}

void make_computer_move(char board[SIZE][SIZE]) {
    // Make a move for the computer using minimax algorithm
    int i, j, alpha = -1000, beta = 1000, score = -1000, high_row = -1, high_col = -1;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') {
                board[i][j] = COMPUTER;
                int temp_score = minimax(board, 0, 0, alpha, beta);
                board[i][j] = '-';
                if (temp_score > score) {
                    score = temp_score;
                    high_row = i;
                    high_col = j;
                }
            }
        }
    }
    board[high_row][high_col] = 'O';
    printf("\nComputer's move: row %d, column %d\n", high_row+1, high_col+1);
}

int main() {
    char board[SIZE][SIZE];
    int player, first_to_move, i;

    srand(time(NULL));
    first_to_move = rand() % 2 + 1;

    if (first_to_move == 1) {
        printf("You go first!\n");
        player = PLAYER;
    }
    else {
        printf("The computer goes first!\n");
        player = COMPUTER;
    }

    printf("Player 1 = X, Player 2 = O\n");
    init_board(board);
    print_board(board);

    for (i = 0; i < 9; i++) {
        if (player == PLAYER) {
            make_move(board, player);
            if (check_win(board, 'X')) {
                printf("\nCongratulations! You win!\n");
                print_board(board);
                return 0;
            }
            player = COMPUTER;
        } else {
            make_computer_move(board);
            if (check_win(board, 'O')) {
                printf("\nSorry, the computer wins.\n");
                print_board(board);
                return 0;
            }
            player = PLAYER;
        }
        print_board(board);
    }

    printf("\nIt's a tie!\n");
    return 0;
}