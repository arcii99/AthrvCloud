//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_DIM 3

bool check_winner(int board[MAX_DIM][MAX_DIM], int player) {
    int i, j;
    bool win;

    // Check rows
    for (i = 0; i < MAX_DIM; i++) {
        win = true;
        for (j = 0; j < MAX_DIM; j++) {
            if (board[i][j] != player) {
                win = false;
                break;
            }
        }
        if (win) {
            return true;
        }
    }
    
    // Check columns
    for (j = 0; j < MAX_DIM; j++) {
        win = true;
        for (i = 0; i < MAX_DIM; i++) {
            if (board[i][j] != player) {
                win = false;
                break;
            }
        }
        if (win) {
            return true;
        }
    }

    // Check diagonals
    win = true;
    for (i = 0; i < MAX_DIM; i++) {
        if (board[i][i] != player) {
            win = false;
            break;
        }
    }
    if (win) {
        return true;
    }

    win = true;
    for (i = 0; i < MAX_DIM; i++) {
        if (board[i][MAX_DIM - i - 1] != player) {
            win = false;
            break;
        }
    }
    if (win) {
        return true;
    }

    return false;
}

int minimax(int board[MAX_DIM][MAX_DIM], int depth, bool is_max, int alpha, int beta) {
    int i, j, score;
    int best_move = -1;
    int best_score = is_max ? -1000 : 1000;

    // Check if terminal node
    if (depth == 0 || check_winner(board, 1) || check_winner(board, 2)) {
        return (check_winner(board, 1) ? -10 : (check_winner(board, 2) ? 10 : 0));
    }

    // Evaluate all possible moves
    for (i = 0; i < MAX_DIM; i++) {
        for (j = 0; j < MAX_DIM; j++) {
            if (board[i][j] == 0) {
                board[i][j] = is_max ? 2 : 1;
                score = minimax(board, depth - 1, !is_max, alpha, beta);
                board[i][j] = 0;
                
                // Update best score
                if (is_max && score > best_score) {
                    best_score = score;
                    best_move = i * MAX_DIM + j;
                    alpha = score;
                }
                else if (!is_max && score < best_score) {
                    best_score = score;
                    best_move = i * MAX_DIM + j;
                    beta = score;
                }

                if (beta <= alpha) {
                    break; // Alpha Beta pruning
                }
            }
        }
    }

    if (depth == MAX_DIM * MAX_DIM) {
        return best_move;
    }

    return best_score;
}

void print_board(int board[MAX_DIM][MAX_DIM]) {
    int i, j;
    for (i = 0; i < MAX_DIM; i++) {
        for (j = 0; j < MAX_DIM; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void clear_board(int board[MAX_DIM][MAX_DIM]) {
    int i, j;
    for (i = 0; i < MAX_DIM; i++) {
        for (j = 0; j < MAX_DIM; j++) {
            board[i][j] = 0;
        }
    }
}

int main() {
    int board[MAX_DIM][MAX_DIM] = {0};
    int i, j, move;
    bool valid_move;
    char player_choice;

    srand(time(0));

    printf("Welcome to Tic Tac Toe AI\n\n");

    while (true) {
        printf("Please choose your player, X or O: ");
        scanf(" %c", &player_choice);

        if (player_choice == 'X' || player_choice == 'O') {
            break;
        }

        printf("Invalid choice, please try again\n");
    }

    for (i = 0; i < MAX_DIM * MAX_DIM; i++) {
        if (player_choice == 'X') {
            // Player's turn
            do {
                printf("\nYour turn\n");
                print_board(board);
                printf("Select your move (1-%d): ", MAX_DIM * MAX_DIM);
                scanf("%d", &move);
                move--;
                i = move;

                if (board[move / MAX_DIM][move % MAX_DIM] != 0) {
                    printf("Invalid move, please try again\n");
                    valid_move = false;
                }
                else {
                    valid_move = true;
                }
            } while (!valid_move);
            
            board[move / MAX_DIM][move % MAX_DIM] = 1;
            printf("\nYour move:\n");
            print_board(board);
        }
        else {
            // AI's turn
            printf("AI's turn\n");
            move = minimax(board, MAX_DIM * MAX_DIM - i, true, -1000, 1000);
            board[move / MAX_DIM][move % MAX_DIM] = 2;
            printf("\nAI's move:\n");
            print_board(board);
        }

        if (check_winner(board, 1)) {
            printf("\nYou win!\n");
            break;
        }
        else if (check_winner(board, 2)) {
            printf("\nAI wins!\n");
            break;
        }

        if (i == MAX_DIM * MAX_DIM - 1) {
            printf("\nIt's a draw!\n");
            break;
        }

        if (player_choice == 'O') {
            // Player's turn
            do {
                printf("\nYour turn\n");
                print_board(board);
                printf("Select your move (1-%d): ", MAX_DIM * MAX_DIM);
                scanf("%d", &move);
                move--;
                i = move;

                if (board[move / MAX_DIM][move % MAX_DIM] != 0) {
                    printf("Invalid move, please try again\n");
                    valid_move = false;
                }
                else {
                    valid_move = true;
                }
            } while (!valid_move);
            
            board[move / MAX_DIM][move % MAX_DIM] = 1;
            printf("\nYour move:\n");
            print_board(board);
        }
        else {
            // AI's turn
            printf("AI's turn\n");
            move = minimax(board, MAX_DIM * MAX_DIM - i, true, -1000, 1000);
            board[move / MAX_DIM][move % MAX_DIM] = 2;
            printf("\nAI's move:\n");
            print_board(board);
        }

        if (check_winner(board, 1)) {
            printf("\nYou win!\n");
            break;
        }
        else if (check_winner(board, 2)) {
            printf("\nAI wins!\n");
            break;
        }
    }

    return 0;
}