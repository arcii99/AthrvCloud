//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char PLAYER = 'X';
char COMPUTER = 'O';


int check_win(char *board);
int minimax(char *board, bool maximizing_player);
int get_best_move(char *board);
void print_board(char *board);
void player_move(char *board);
void computer_move(char *board);


int main() {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int winner = 0;
    int turn = 1;

    while (winner == 0 && turn < 10) {

        print_board(board);

        if (turn % 2 != 0) {
            player_move(board);
        } else {
            computer_move(board);
        }

        winner = check_win(board);

        turn++;
    }

    if (winner == 1) {
        printf("Player wins!\n");
    } else if (winner == -1) {
        printf("Computer wins!\n");
    } else {
        printf("Tie game!\n");
    }

    return 0;
}


/*
 * Checks if there is a winner
 *
 * Returns:
 * 1 if player wins
 * -1 if computer wins
 * 0 if tie game or no winner
 */
int check_win(char *board) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == board[i + 1] && board[i] == board[i + 2]) {
            if (board[i] == PLAYER) {
                return 1;
            } else if (board[i] == COMPUTER) {
                return -1;
            }
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == board[i + 3] && board[i] == board[i + 6]) {
            if (board[i] == PLAYER) {
                return 1;
            } else if (board[i] == COMPUTER) {
                return -1;
            }
        }
    }

    // Check diagonals
    if (board[0] == board[4] && board[0] == board[8]) {
        if (board[0] == PLAYER) {
            return 1;
        } else if (board[0] == COMPUTER) {
            return -1;
        }
    }

    if (board[2] == board[4] && board[2] == board[6]) {
        if (board[2] == PLAYER) {
            return 1;
        } else if (board[2] == COMPUTER) {
            return -1;
        }
    }

    // No winner
    return 0;
}


/*
 * Minimax algorithm for determining best move for computer
 *
 * Returns:
 * score if game is over
 * 0 if game is not over
 */
int minimax(char *board, bool maximizing_player) {
    int score = check_win(board);

    if (score != 0) {
        return score;
    }

    if (maximizing_player) {
        int best_score = -1000;

        for (int i = 0; i < 9; i++) {
            if (board[i] != PLAYER && board[i] != COMPUTER) {
                board[i] = COMPUTER;
                int this_score = minimax(board, false);
                board[i] = i + '1';
                if (this_score > best_score) {
                    best_score = this_score;
                }
            }
        }

        return best_score;

    } else {
        int best_score = 1000;

        for (int i = 0; i < 9; i++) {
            if (board[i] != PLAYER && board[i] != COMPUTER) {
                board[i] = PLAYER;
                int this_score = minimax(board, true);
                board[i] = i + '1';
                if (this_score < best_score) {
                    best_score = this_score;
                }
            }
        }

        return best_score;
    }
}


/*
 * Gets the best move for the computer
 *
 * Returns:
 * index of best move
 */
int get_best_move(char *board) {
    int best_score = -1000;
    int best_move = -1;

    for (int i = 0; i < 9; i++) {
        if (board[i] != PLAYER && board[i] != COMPUTER) {
            board[i] = COMPUTER;
            int this_score = minimax(board, false);
            board[i] = i + '1';
            if (this_score > best_score) {
                best_score = this_score;
                best_move = i;
            }
        }
    }

    return best_move;
}


/*
 * Prints the current board
 */
void print_board(char *board) {
    printf("\n");

    for (int i = 0; i < 9; i += 3) {
        printf(" %c | %c | %c \n", board[i], board[i + 1], board[i + 2]);
        if (i < 6) printf("-----------\n");
    }

    printf("\n");
}


/*
 * Gets the player's move
 */
void player_move(char *board) {
    int move;

    printf("Enter move (1-9): ");
    scanf("%d", &move);

    while (move < 1 || move > 9 || board[move - 1] == PLAYER || board[move - 1] == COMPUTER) {
        printf("Invalid move. Enter move (1-9): ");
        scanf("%d", &move);
    }

    board[move - 1] = PLAYER;
}


/*
 * Gets the computer's move
 */
void computer_move(char *board) {
    int move = get_best_move(board);

    board[move] = COMPUTER;

    printf("Computer moves at %d\n", move + 1);
}