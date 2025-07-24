//FormAI DATASET v1.0 Category: Chess AI ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];
char current_player;
int score_white = 0;
int score_black = 0;

int score_pieces(char c) {
    int score = 0;
    int i, j;

    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == c) {
                if (c == 'P' || c == 'p') {
                    score += 1;
                } else if (c == 'B' || c == 'b') {
                    score += 3;
                } else if (c == 'N' || c == 'n') {
                    score += 3;
                } else if (c == 'R' || c == 'r') {
                    score += 5;
                } else if (c == 'Q' || c == 'q') {
                    score += 9;
                }
            }
        }
    }

    return score;
}

void reset_board() {
    int i, j;

    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            if (i == 1) {
                board[i][j] = 'P';
            } else if (i == 6) {
                board[i][j] = 'p';
            } else {
                board[i][j] = ' ';
            }
        }
    }

    board[0][0] = 'R';
    board[0][1] = 'N';
    board[0][2] = 'B';
    board[0][3] = 'Q';
    board[0][4] = 'K';
    board[0][5] = 'B';
    board[0][6] = 'N';
    board[0][7] = 'R';

    board[7][0] = 'r';
    board[7][1] = 'n';
    board[7][2] = 'b';
    board[7][3] = 'q';
    board[7][4] = 'k';
    board[7][5] = 'b';
    board[7][6] = 'n';
    board[7][7] = 'r';

    current_player = 'w';
}

void print_board() {
    int i, j;

    for (i = 0; i < BOARD_SIZE; ++i) {
        printf("\n+---+---+---+---+---+---+---+---+\n");

        for (j = 0; j < BOARD_SIZE; ++j) {
            printf("| %c ", board[i][j]);
        }

        printf("| %d", BOARD_SIZE - i);
    }

    printf("\n+---+---+---+---+---+---+---+---+\n");
    printf("  A   B   C   D   E   F   G   H\n");
}

void handle_move(char from[2], char to[2]) {
    int from_i = from[0] - 'a';
    int from_j = BOARD_SIZE - (from[1] - '0');

    int to_i = to[0] - 'a';
    int to_j = BOARD_SIZE - (to[1] - '0');

    if (board[from_j][from_i] == ' ' || (board[from_j][from_i] == 'p' && from_i == to_i && to_j - from_j != 1 && board[to_j][to_i] == ' ')) {
        printf("Invalid move.\n");
        return;
    }

    if (board[from_j][from_i] == 'P' && from_i == to_i && to_j - from_j != -1 && board[to_j][to_i] == ' ') {
        printf("Invalid move.\n");
        return;
    }

    if (board[from_j][from_i] == 'P' && abs(from_i - to_i) == 1 && to_j - from_j != -1 && board[to_j][to_i] == ' ') {
        printf("Invalid move.\n");
        return;
    }

    if (board[from_j][from_i] == 'p' && abs(from_i - to_i) == 1 && to_j - from_j != 1 && board[to_j][to_i] == ' ') {
        printf("Invalid move.\n");
        return;
    }

    if (board[from_j][from_i] == 'p' && from_i == to_i && to_j - from_j != 1 && board[to_j][to_i] == ' ') {
        printf("Invalid move.\n");
        return;
    }

    if (board[to_j][to_i] != ' ') {
        if ((isupper(board[to_j][to_i]) && current_player == 'w') || (islower(board[to_j][to_i]) && current_player == 'b')) {
            if (board[to_j][to_i] == 'K' || board[to_j][to_i] == 'k') {
                printf("Checkmate. %c wins!\n", current_player);
                exit(0);
            }

            if (current_player == 'w') {
                score_white += score_pieces(board[to_j][to_i]);
            } else {
                score_black += score_pieces(board[to_j][to_i]);
            }
        } else {
            printf("Invalid move.\n");
            return;
        }
    }

    if (board[from_j][from_i] == 'P' && from_i == to_i && to_j - from_j == -2) {
        if (board[from_j - 1][from_i] != ' ' || board[to_j][to_i] != ' ') {
            printf("Invalid move.\n");
            return;
        }

        if (from_j != 6) {
            printf("Invalid move.\n");
            return;
        }
    }

    if (board[from_j][from_i] == 'p' && from_i == to_i && to_j - from_j == 2) {
        if (board[from_j + 1][from_i] != ' ' || board[to_j][to_i] != ' ') {
            printf("Invalid move.\n");
            return;
        }

        if (from_j != 1) {
            printf("Invalid move.\n");
            return;
        }
    }

    if (board[from_j][from_i] == 'P' && (from_i - to_i == 1 || from_i - to_i == -1) && to_j - from_j == -1 && board[to_j][to_i] == ' ') {
        printf("Invalid move.\n");
        return;
    }

    if (board[from_j][from_i] == 'p' && (from_i - to_i == 1 || from_i - to_i == -1) && to_j - from_j == 1 && board[to_j][to_i] == ' ') {
        printf("Invalid move.\n");
        return;
    }

    if (board[from_j][from_i] == 'K' || board[from_j][from_i] == 'k') {
        if (abs(from_i - to_i) > 1 || abs(from_j - to_j) > 1) {
            printf("Invalid move.\n");
            return;
        }
    }

    if (board[from_j][from_i] == 'R' || board[from_j][from_i] == 'r') {
        if (from_i != to_i && from_j != to_j) {
            printf("Invalid move.\n");
            return;
        }

        if (from_i == to_i) {
            int k;

            if (from_j < to_j) {
                for (k = from_j + 1; k < to_j; ++k) {
                    if (board[k][from_i] != ' ') {
                        printf("Invalid move.\n");
                        return;
                    }
                }
            } else {
                for (k = from_j - 1; k > to_j; --k) {
                    if (board[k][from_i] != ' ') {
                        printf("Invalid move.\n");
                        return;
                    }
                }
            }
        } else {
            int k;

            if (from_i < to_i) {
                for (k = from_i + 1; k < to_i; ++k) {
                    if (board[from_j][k] != ' ') {
                        printf("Invalid move.\n");
                        return;
                    }
                }
            } else {
                for (k = from_i - 1; k > to_i; --k) {
                    if (board[from_j][k] != ' ') {
                        printf("Invalid move.\n");
                        return;
                    }
                }
            }
        }
    }

    if (board[from_j][from_i] == 'B' || board[from_j][from_i] == 'b') {
        if (abs(from_i - to_i) != abs(from_j - to_j)) {
            printf("Invalid move.\n");
            return;
        }

        int k, l;

        if (from_i < to_i && from_j > to_j) {
            for (k = from_i + 1, l = from_j - 1; k < to_i && l > to_j; ++k, --l) {
                if (board[l][k] != ' ') {
                    printf("Invalid move.\n");
                    return;
                }
            }
        } else if (from_i > to_i && from_j > to_j) {
            for (k = from_i - 1, l = from_j - 1; k > to_i && l > to_j; --k, --l) {
                if (board[l][k] != ' ') {
                    printf("Invalid move.\n");
                    return;
                }
            }
        } else if (from_i < to_i && from_j < to_j) {
            for (k = from_i + 1, l = from_j + 1; k < to_i && l < to_j; ++k, ++l) {
                if (board[l][k] != ' ') {
                    printf("Invalid move.\n");
                    return;
                }
            }
        } else {
            for (k = from_i - 1, l = from_j + 1; k > to_i && l < to_j; --k, ++l) {
                if (board[l][k] != ' ') {
                    printf("Invalid move.\n");
                    return;
                }
            }
        }
    }

    if (board[from_j][from_i] == 'N' || board[from_j][from_i] == 'n') {
        int dx = abs(from_i - to_i);
        int dy = abs(from_j - to_j);

        if ((dx != 1 || dy != 2) && (dx != 2 || dy != 1)) {
            printf("Invalid move.\n");
            return;
        }
    }

    board[to_j][to_i] = board[from_j][from_i];
    board[from_j][from_i] = ' ';

    if (current_player == 'w') {
        current_player = 'b';
    } else {
        current_player = 'w';
    }
}

int main() {
    srand(time(NULL));
    reset_board();
    print_board();

    while (1) {
        char input[10];
        printf("Enter move (e.g. e2e4): ");

        fgets(input, 10, stdin);

        if (input[0] == 'q') {
            return 0;
        }

        if (strlen(input) == 5) {
            handle_move(&input[0], &input[3]);
            print_board();
            printf("\nScore: White %d - %d Black\n", score_white, score_black);
        } else {
            printf("Invalid move.\n");
        }
    }

    return 0;
}