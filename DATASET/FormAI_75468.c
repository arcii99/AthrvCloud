//FormAI DATASET v1.0 Category: Checkers Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define BLACK 'b'
#define WHITE 'w'
#define EMPTY ' '

#define SIZE 8

char board[SIZE][SIZE]; // define the board of the game
char current_player; // define the current player

// function that initializes the board with the initial positions of the pieces
void initialize_board() {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i < 3) {
                if ((i + j) % 2 == 0) {
                    board[i][j] = BLACK;
                } else {
                    board[i][j] = EMPTY;
                }
            } else if (i > 4) {
                if ((i + j) % 2 == 0) {
                    board[i][j] = WHITE;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

// function that displays the board
void display_board() {
    int i, j;

    printf("\n   ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d  ", i);
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// function that checks if the move is valid
int is_valid_move(int row1, int col1, int row2, int col2) {
    if (row1 < 0 || col1 < 0 || row2 < 0 || col2 < 0) {
        return 0;
    }

    if (row1 >= SIZE || col1 >= SIZE || row2 >= SIZE || col2 >= SIZE) {
        return 0;
    }

    if (board[row2][col2] != EMPTY) {
        return 0;
    }

    if (current_player == WHITE) {
        if (row2 > row1) {
            return 0;
        }

        if (row1 - row2 > 2 || abs(col2 - col1) > 2) {
            return 0;
        }

        if (row1 - row2 == 2) {
            if (col2 == col1 - 2 && board[row1-1][col1-1] == BLACK) {
                return 1;
            }
            
            if (col2 == col1 + 2 && board[row1-1][col1+1] == BLACK) {
                return 1;
            }

            return 0;
        }
    } else {
        if (row2 < row1) {
            return 0;
        }

        if (row2 - row1 > 2 || abs(col2 - col1) > 2) {
            return 0;
        }

        if (row2 - row1 == 2) {
            if (col2 == col1 - 2 && board[row1+1][col1-1] == WHITE) {
                return 1;
            }

            if (col2 == col1 + 2 && board[row1+1][col1+1] == WHITE) {
                return 1;
            }

            return 0;
        }
    }

    return 1;
}

// function that makes the move
void make_move(int row1, int col1, int row2, int col2) {
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = EMPTY;

    if (current_player == WHITE && row2 == 0) {
        board[row2][col2] = 'W';
    } else if (current_player == BLACK && row2 == SIZE - 1) {
        board[row2][col2] = 'B';
    }
}

// function that checks if there are any captures available
int captures_available() {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == current_player || board[i][j] == toupper(current_player)) {
                if (current_player == WHITE || toupper(board[i][j]) == 'W') {
                    if (j >= 2 && i >= 2 && board[i-1][j-1] == BLACK && board[i-2][j-2] == EMPTY) {
                        return 1;
                    }

                    if (j <= 5 && i >= 2 && board[i-1][j+1] == BLACK && board[i-2][j+2] == EMPTY) {
                        return 1;
                    }

                    if (toupper(board[i][j]) == 'W') {
                        if (j >= 2 && i <= 5 && board[i+1][j-1] == BLACK && board[i+2][j-2] == EMPTY) {
                            return 1;
                        }

                        if (j <= 5 && i <= 5 && board[i+1][j+1] == BLACK && board[i+2][j+2] == EMPTY) {
                            return 1;
                        }
                    }
                } else {
                    if (j >= 2 && i <= 5 && board[i+1][j-1] == WHITE && board[i+2][j-2] == EMPTY) {
                        return 1;
                    }

                    if (j <= 5 && i <= 5 && board[i+1][j+1] == WHITE && board[i+2][j+2] == EMPTY) {
                        return 1;
                    }

                    if (toupper(board[i][j]) == 'B') {
                        if (j >= 2 && i >= 2 && board[i-1][j-1] == WHITE && board[i-2][j-2] == EMPTY) {
                            return 1;
                        }

                        if (j <= 5 && i >= 2 && board[i-1][j+1] == WHITE && board[i-2][j+2] == EMPTY) {
                            return 1;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

// function that makes the capture
void make_capture(int row1, int col1, int row2, int col2) {
    int i, j;

    board[row2][col2] = board[row1][col1];
    board[row1][col1] = EMPTY;

    i = (row1 + row2) / 2;
    j = (col1 + col2) / 2;

    board[i][j] = EMPTY;
}

// function that plays the game
void play_game() {
    initialize_board();
    current_player = BLACK;

    while (1) {
        display_board();

        if (captures_available()) {
            printf("%c player, please make a capture: ", current_player);
            int row1, col1, row2, col2;

            do {
                printf("From (row column): ");
                scanf("%d %d", &row1, &col1);

                printf("To (row column): ");
                scanf("%d %d", &row2, &col2);
            } while (!is_valid_move(row1, col1, row2, col2) || abs(row2 - row1) != 2 || abs(col2 - col1) != 2);

            make_capture(row1, col1, row2, col2);
        } else {
            printf("%c player, please make a move: ", current_player);
            int row1, col1, row2, col2;

            do {
                printf("From (row column): ");
                scanf("%d %d", &row1, &col1);

                printf("To (row column): ");
                scanf("%d %d", &row2, &col2);
            } while (!is_valid_move(row1, col1, row2, col2));

            make_move(row1, col1, row2, col2);
        }

        if (current_player == BLACK) {
            current_player = WHITE;
        } else {
            current_player = BLACK;
        }
    }
}

// main function that runs the game
int main() {
    printf("Welcome to Checkers!\n");
    play_game();
    return 0;
}