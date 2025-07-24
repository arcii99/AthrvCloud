//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print the game board
void print_board(int board[][4]) {
    printf("\n");
    for (int i = 0; i < 4; i++) {
        printf("\t\t");
        for (int j = 0; j < 4; j++) 
            printf("%d\t", board[i][j]);
        printf("\n\n");
    }
}

// function to move the tiles
void move_tiles(int board[][4], char direction) {
    int i, j, temp;
    switch (direction) {
        case 'w':   // move tiles upwards
            for (j = 0; j < 4; j++) {
                for (i = 1; i < 4; i++) {
                    if (board[i][j] != 0) {
                        temp = board[i][j];
                        board[i][j] = 0;
                        for (int k = i-1; k >= 0; k--) {
                            if (board[k][j] == 0) {
                                board[k][j] = temp;
                                break;
                            }
                            if (board[k][j] == temp) {
                                board[k][j] *= 2;
                                break;
                            }
                            if (k == 0) {
                                board[k][j] = temp;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 'a':   // move tiles to the left
            for (i = 0; i < 4; i++) {
                for (j = 1; j < 4; j++) {
                    if (board[i][j] != 0) {
                        temp = board[i][j];
                        board[i][j] = 0;
                        for (int k = j-1; k >= 0; k--) {
                            if (board[i][k] == 0) {
                                board[i][k] = temp;
                                break;
                            }
                            if (board[i][k] == temp) {
                                board[i][k] *= 2;
                                break;
                            }
                            if (k == 0) {
                                board[i][k] = temp;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 's':   // move tiles downwards
            for (j = 0; j < 4; j++) {
                for (i = 2; i >= 0; i--) {
                    if (board[i][j] != 0) {
                        temp = board[i][j];
                        board[i][j] = 0;
                        for (int k = i+1; k < 4; k++) {
                            if (board[k][j] == 0) {
                                board[k][j] = temp;
                                break;
                            }
                            if (board[k][j] == temp) {
                                board[k][j] *= 2;
                                break;
                            }
                            if (k == 3) {
                                board[k][j] = temp;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 'd':   // move tiles to the right
            for (i = 0; i < 4; i++) {
                for (j = 2; j >= 0; j--) {
                    if (board[i][j] != 0) {
                        temp = board[i][j];
                        board[i][j] = 0;
                        for (int k = j+1; k < 4; k++) {
                            if (board[i][k] == 0) {
                                board[i][k] = temp;
                                break;
                            }
                            if (board[i][k] == temp) {
                                board[i][k] *= 2;
                                break;
                            }
                            if (k == 3) {
                                board[i][k] = temp;
                                break;
                            }
                        }
                    }
                }
            }
            break;
    }
}

// function to check if the game board is full
int is_board_full(int board[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

// main function
int main() {
    int board[4][4] = {0};   // initialize the game board to zeros
    char direction;
    int game_over = 0;
    int score = 0;

    // randomly place two tiles on the board
    srand(time(0));
    int i1 = rand() % 4;
    int j1 = rand() % 4;
    int i2, j2;
    do {
        i2 = rand() % 4;
        j2 = rand() % 4;
    } while (i1 == i2 && j1 == j2);

    board[i1][j1] = 2;
    board[i2][j2] = 2;

    printf("\n\n\t\tWelcome to the 2048 game!\n\n");
    printf("\t\tUse 'w', 'a', 's', 'd' keys to move the tiles.\n\n");
    printf("\t\t'w' for Up, 'a' for Left, 's' for Down, 'd' for Right.\n\n");
    print_board(board);

    while (!game_over) {
        printf("\t\tEnter the direction to move the tiles: ");
        scanf("%c", &direction);

        while (getchar() != '\n');   // clear the input buffer

        // move the tiles in the given direction
        move_tiles(board, direction);

        // randomly place a new tile on the board if it is not full
        if (!is_board_full(board)) {
            int i, j;
            do {
                i = rand() % 4;
                j = rand() % 4;
            } while (board[i][j] != 0);
            board[i][j] = 2;
        }

        // check if the game is over
        int game_over_1 = 1;
        int game_over_2 = 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == 2048) {
                    game_over = 1;
                    break;
                }
                if (board[i][j] == 0 || (j < 3 && board[i][j] == board[i][j+1])
                    || (i < 3 && board[i][j] == board[i+1][j])) {
                    game_over_1 = 0;
                }
                if (board[i][j] == 0 || (j > 0 && board[i][j] == board[i][j-1]) 
                    || (i > 0 && board[i][j] == board[i-1][j])) {
                    game_over_2 = 0;
                }
            }
            if (game_over)
                break;
        }

        // update the score
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                score += board[i][j];
            }
        }

        if (game_over_1 || game_over_2) {
            game_over = 1;
            printf("\n\n\t\tGame over!\n\n");
            printf("\t\tYour final score is %d.\n\n", score);
        } else {
            printf("\n\n");
            print_board(board);
        }
    }

    return 0;
}