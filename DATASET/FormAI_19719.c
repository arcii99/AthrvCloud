//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minimax(int board[3][3], int depth, int is_max);
void print_board(int board[3][3]);
int get_best_move(int board[3][3]);
int check_winner(int board[3][3]);

int main() {
    // Initialize empty board
    int board[3][3] = {0};
    int round = 0;

    while (round < 9) {
        printf("==========\n");
        print_board(board);
        printf("==========\n");

        if (round % 2 == 0) {
            printf("Player's turn (O)\n");
            int row, col;
            do {
                printf("Enter row and column (1-3): ");
                scanf("%d %d", &row, &col);
                row--;
                col--;
            } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != 0);

            board[row][col] = -1;
        } else {
            printf("AI's turn (X)\n");
            int best_move = get_best_move(board);
            printf("AI chooses row %d, column %d\n", best_move/3+1, best_move%3+1);
            board[best_move/3][best_move%3] = 1;
        }

        int winner = check_winner(board);
        if (winner != 0) {
            printf("==========\n");
            print_board(board);
            printf("==========\n");

            if (winner == -1) {
                printf("Player wins!\n");
            } else if (winner == 1) {
                printf("AI wins!\n");
            } else {
                printf("It's a tie!\n");
            }

            return 0;
        }

        round++;
    }

    printf("==========\n");
    print_board(board);
    printf("==========\n");

    printf("It's a tie!\n");
    return 0;
}

int minimax(int board[3][3], int depth, int is_max) {
    // Base case
    int winner = check_winner(board);
    if (winner == 1) {
        return 10 - depth;
    } else if (winner == -1) {
        return depth - 10;
    } else if (winner == 0 && depth == 9) {
        return 0;
    }

    // Recursive case
    int best_value;
    if (is_max) {
        best_value = -100;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = 1;
                    int value = minimax(board, depth+1, 0);
                    board[i][j] = 0;
                    if (value > best_value) {
                        best_value = value;
                    }
                }
            }
        }
    } else {
        best_value = 100;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = -1;
                    int value = minimax(board, depth+1, 1);
                    board[i][j] = 0;
                    if (value < best_value) {
                        best_value = value;
                    }
                }
            }
        }
    }

    return best_value;
}

void print_board(int board[3][3]) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            switch (board[i][j]) {
                case 1:
                    printf("X ");
                    break;
                case -1:
                    printf("O ");
                    break;
                default:
                    printf(". ");
                    break;
            }
        }
        printf("\n");
    }
}

int get_best_move(int board[3][3]) {
    int best_score = -100;
    int best_move = -1;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 1;
                int score = minimax(board, 0, 0);
                board[i][j] = 0;

                if (score > best_score) {
                    best_score = score;
                    best_move = i*3 + j;
                }
            }
        }
    }

    return best_move;
}

int check_winner(int board[3][3]) {
    // Check rows
    for (int i=0; i<3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int i=0; i<3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // Check for tie
    int count = 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] == 0) {
                count++;
            }
        }
    }
    if (count == 0) {
        return 2;
    }

    return 0;
}