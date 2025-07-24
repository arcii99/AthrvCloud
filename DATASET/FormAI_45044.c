//FormAI DATASET v1.0 Category: Checkers Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY '-'
#define PLAYER1 'R'
#define PLAYER2 'B'

void print_board(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int move_available(char board[][BOARD_SIZE], int player) {
    char player_char = (player == 1) ? PLAYER1 : PLAYER2;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player_char) {
                // Regular move
                if ((player_char == PLAYER1 || board[i][j] == toupper(board[i][j])) && i > 0 && j > 0 && board[i-1][j-1] == EMPTY) {
                    return 1;
                }
                if ((player_char == PLAYER1 || board[i][j] == toupper(board[i][j])) && i > 0 && j < BOARD_SIZE - 1 && board[i-1][j+1] == EMPTY) {
                    return 1;
                }
                if ((player_char == PLAYER2 || board[i][j] == toupper(board[i][j])) && i < BOARD_SIZE - 1 && j > 0 && board[i+1][j-1] == EMPTY) {
                    return 1;
                }
                if ((player_char == PLAYER2 || board[i][j] == toupper(board[i][j])) && i < BOARD_SIZE - 1 && j < BOARD_SIZE - 1 && board[i+1][j+1] == EMPTY) {
                    return 1;
                }
                // Jump move
                if ((player_char == PLAYER1 || board[i][j] == toupper(board[i][j])) && i > 1 && j > 1 && board[i-1][j-1] == (player_char == PLAYER1 ? PLAYER2 : tolower(PLAYER2)) && board[i-2][j-2] == EMPTY) {
                    return 1;
                }
                if ((player_char == PLAYER1 || board[i][j] == toupper(board[i][j])) && i > 1 && j < BOARD_SIZE - 2 && board[i-1][j+1] == (player_char == PLAYER1 ? PLAYER2 : tolower(PLAYER2)) && board[i-2][j+2] == EMPTY) {
                    return 1;
                }
                if ((player_char == PLAYER2 || board[i][j] == toupper(board[i][j])) && i < BOARD_SIZE - 2 && j > 1 && board[i+1][j-1] == (player_char == PLAYER2 ? PLAYER1 : toupper(PLAYER1)) && board[i+2][j-2] == EMPTY) {
                    return 1;
                }
                if ((player_char == PLAYER2 || board[i][j] == toupper(board[i][j])) && i < BOARD_SIZE - 2 && j < BOARD_SIZE - 2 && board[i+1][j+1] == (player_char == PLAYER2 ? PLAYER1 : toupper(PLAYER1)) && board[i+2][j+2] == EMPTY) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int make_move(char board[][BOARD_SIZE], int player, int i, int j, int choice_i, int choice_j) {
    char player_char = (player == 1) ? PLAYER1 : PLAYER2;
    char opponent_char = (player == 1) ? PLAYER2 : PLAYER1;

    // Regular move
    if ((player_char == PLAYER1 || board[i][j] == toupper(board[i][j])) && i - 1 == choice_i && j - 1 == choice_j && board[choice_i][choice_j] == EMPTY) {
        board[choice_i][choice_j] = player_char;
        board[i][j] = EMPTY;
    }
    if ((player_char == PLAYER1 || board[i][j] == toupper(board[i][j])) && i - 1 == choice_i && j + 1 == choice_j && board[choice_i][choice_j] == EMPTY) {
        board[choice_i][choice_j] = player_char;
        board[i][j] = EMPTY;
    }
    if ((player_char == PLAYER2 || board[i][j] == toupper(board[i][j])) && i + 1 == choice_i && j - 1 == choice_j && board[choice_i][choice_j] == EMPTY) {
        board[choice_i][choice_j] = player_char;
        board[i][j] = EMPTY;
    }
    if ((player_char == PLAYER2 || board[i][j] == toupper(board[i][j])) && i + 1 == choice_i && j + 1 == choice_j && board[choice_i][choice_j] == EMPTY) {
        board[choice_i][choice_j] = player_char;
        board[i][j] = EMPTY;
    }

    // Jump move
    if ((player_char == PLAYER1 || board[i][j] == toupper(board[i][j])) && i - 2 == choice_i && j - 2 == choice_j && board[choice_i][choice_j] == EMPTY && board[i-1][j-1] == opponent_char) {
        board[choice_i][choice_j] = player_char;
        board[i][j] = EMPTY;
        board[i-1][j-1] = EMPTY;
    }
    if ((player_char == PLAYER1 || board[i][j] == toupper(board[i][j])) && i - 2 == choice_i && j + 2 == choice_j && board[choice_i][choice_j] == EMPTY && board[i-1][j+1] == opponent_char) {
        board[choice_i][choice_j] = player_char;
        board[i][j] = EMPTY;
        board[i-1][j+1] = EMPTY;
    }
    if ((player_char == PLAYER2 || board[i][j] == toupper(board[i][j])) && i + 2 == choice_i && j - 2 == choice_j && board[choice_i][choice_j] == EMPTY && board[i+1][j-1] == opponent_char) {
        board[choice_i][choice_j] = player_char;
        board[i][j] = EMPTY;
        board[i+1][j-1] = EMPTY;
    }
    if ((player_char == PLAYER2 || board[i][j] == toupper(board[i][j])) && i + 2 == choice_i && j + 2 == choice_j && board[choice_i][choice_j] == EMPTY && board[i+1][j+1] == opponent_char) {
        board[choice_i][choice_j] = player_char;
        board[i][j] = EMPTY;
        board[i+1][j+1] = EMPTY;
    }

    // Promote to king
    if (board[choice_i][choice_j] == PLAYER1 && choice_i == 0) {
        board[choice_i][choice_j] = toupper(PLAYER1);
    }
    if (board[choice_i][choice_j] == PLAYER2 && choice_i == BOARD_SIZE - 1) {
        board[choice_i][choice_j] = toupper(PLAYER2);
    }

    return 0;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {EMPTY, PLAYER1, EMPTY, PLAYER1, EMPTY, PLAYER1, EMPTY, PLAYER1},
        {PLAYER1, EMPTY, PLAYER1, EMPTY, PLAYER1, EMPTY, PLAYER1, EMPTY},
        {EMPTY, PLAYER1, EMPTY, PLAYER1, EMPTY, PLAYER1, EMPTY, PLAYER1},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {PLAYER2, EMPTY, PLAYER2, EMPTY, PLAYER2, EMPTY, PLAYER2, EMPTY},
        {EMPTY, PLAYER2, EMPTY, PLAYER2, EMPTY, PLAYER2, EMPTY, PLAYER2},
        {PLAYER2, EMPTY, PLAYER2, EMPTY, PLAYER2, EMPTY, PLAYER2, EMPTY}
    };
    int player = 1;

    while (move_available(board, player)) {
        print_board(board);

        printf("Player %d's turn.\n", player);

        int i, j, choice_i, choice_j;

        do {
            printf("Enter the coordinate of the piece you wish to move: ");
            scanf("%d %d", &i, &j);
        } while (board[i][j] != (player == 1 ? PLAYER1 : PLAYER2));

        do {
            printf("Enter the coordinate of the space you wish to move to: ");
            scanf("%d %d", &choice_i, &choice_j);
        } while (!make_move(board, player, i, j, choice_i, choice_j));

        player = (player == 1) ? 2 : 1;
    }

    printf("No moves available. Player %d wins!\n", (player == 1) ? 2 : 1);

    return 0;
}