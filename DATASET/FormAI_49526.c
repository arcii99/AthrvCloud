//FormAI DATASET v1.0 Category: Chess AI ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

void print_board(char board[][BOARD_SIZE]) {
    printf("   A B C D E F G H\n");
    printf("  +---------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf(" %d\n", i + 1);
    }
    printf("  +---------------+\n");
    printf("   A B C D E F G H\n");
}

int is_valid_move(char board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y) {
    if (from_x < 0 || from_x >= BOARD_SIZE || to_x < 0 || to_x >= BOARD_SIZE ||
            from_y < 0 || from_y >= BOARD_SIZE || to_y < 0 || to_y >= BOARD_SIZE ||
            board[from_x][from_y] == ' ' || board[to_x][to_y] == ' ') {
        return 0;
    }
    char piece = board[from_x][from_y];
    int dx = to_x - from_x;
    int dy = to_y - from_y;
    if (piece == 'P') {
        if (dx == 1 && dy == 0 && board[to_x][to_y] == ' ') {
            return 1;
        } else if (dx == 2 && dy == 0 && from_x == 1 && board[to_x][to_y] == ' ' && board[to_x-1][to_y] == ' ') {
            return 1;
        } else if (dx == 1 && (dy == -1 || dy == 1) && board[to_x][to_y] != ' ') {
            return 1;
        }
    } else if (piece == 'R') {
        if (dx == 0 && dy != 0) {
            int direction = dy > 0 ? 1 : -1;
            for (int i = from_y + direction; i != to_y; i += direction) {
                if (board[from_x][i] != ' ') {
                    return 0;
                }
            }
            return 1;
        } else if (dy == 0 && dx != 0) {
            int direction = dx > 0 ? 1 : -1;
            for (int i = from_x + direction; i != to_x; i += direction) {
                if (board[i][from_y] != ' ') {
                    return 0;
                }
            }
            return 1;
        }
    } else if (piece == 'N') {
        if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1) || (dx == 2 && dy == -1) || (dx == 1 && dy == -2) ||
                (dx == -1 && dy == -2) || (dx == -2 && dy == -1) || (dx == -2 && dy == 1) || (dx == -1 && dy == 2)) {
            return 1;
        }
    } else if (piece == 'B') {
        if (dx != dy && dx != -dy) {
            return 0;
        }
        int x_direction = dx > 0 ? 1 : dx < 0 ? -1 : 0;
        int y_direction = dy > 0 ? 1 : dy < 0 ? -1 : 0;
        for (int i = 1; i < abs(dx); i++) {
            if (board[from_x + i*x_direction][from_y + i*y_direction] != ' ') {
                return 0;
            }
        }
        return 1;
    } else if (piece == 'Q') {
        if (dx == 0 && dy != 0) {
            int direction = dy > 0 ? 1 : -1;
            for (int i = from_y + direction; i != to_y; i += direction) {
                if (board[from_x][i] != ' ') {
                    return 0;
                }
            }
            return 1;
        } else if (dy == 0 && dx != 0) {
            int direction = dx > 0 ? 1 : -1;
            for (int i = from_x + direction; i != to_x; i += direction) {
                if (board[i][from_y] != ' ') {
                    return 0;
                }
            }
            return 1;
        } else if (dx != dy && dx != -dy) {
            return 0;
        }
        int x_direction = dx > 0 ? 1 : dx < 0 ? -1 : 0;
        int y_direction = dy > 0 ? 1 : dy < 0 ? -1 : 0;
        for (int i = 1; i < abs(dx); i++) {
            if (board[from_x + i*x_direction][from_y + i*y_direction] != ' ') {
                return 0;
            }
        }
        return 1;
    } else if (piece == 'K') {
        if ((abs(dx) == 1 && abs(dy) == 0) || (abs(dx) == 0 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 1)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };
    int turn = 0;
    int move_number = 1;
    srand(time(NULL));
    while (1) {
        print_board(board);
        if (turn == 0) {
            printf("It's white's move.\n");
        } else {
            printf("It's black's move.\n");
        }
        int from_x, from_y, to_x, to_y;
        while (1) {
            if (turn == 0) {
                printf("Enter white's move (e.g. e2e4): ");
            } else {
                printf("Enter black's move (e.g. e7e5): ");
            }
            char input[5];
            scanf("%4s", input);
            from_x = input[1] - '1';
            from_y = input[0] - 'A';
            to_x = input[3] - '1';
            to_y = input[2] - 'A';
            if (is_valid_move(board, from_x, from_y, to_x, to_y)) {
                break;
            } else {
                printf("Invalid move! Please try again.\n");
            }
        }
        char piece = board[from_x][from_y];
        board[to_x][to_y] = piece;
        board[from_x][from_y] = ' ';
        turn = 1 - turn;
        move_number++;
        if (move_number > 100) {
            printf("The game ended in a draw (maximum number of moves reached).\n");
            break;
        }
        int king_x, king_y;
        char king = turn == 0 ? 'K' : 'k';
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == king) {
                    king_x = i;
                    king_y = j;
                    break;
                }
            }
        }
        int is_checkmate = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] != ' ' && (board[i][j] == king || board[i][j] % 32 != king % 32)) {
                    for (int k = 0; k < BOARD_SIZE; k++) {
                        for (int l = 0; l < BOARD_SIZE; l++) {
                            if (is_valid_move(board, i, j, k, l)) {
                                char temp = board[k][l];
                                board[k][l] = board[i][j];
                                board[i][j] = ' ';
                                int temp_x = king_x, temp_y = king_y;
                                if (board[k][l] == king) {
                                    temp_x = k;
                                    temp_y = l;
                                }
                                for (int m = -1; m <= 1; m++) {
                                    for (int n = -1; n <= 1; n++) {
                                        if (temp_x + m >= 0 && temp_x + m < BOARD_SIZE && temp_y + n >= 0 && temp_y + n < BOARD_SIZE) {
                                            if (board[temp_x + m][temp_y + n] == ' ' || (board[temp_x + m][temp_y + n] % 32 == king % 32 && board[temp_x + m][temp_y + n] != king)) {
                                                is_checkmate = 0;
                                            }
                                        }
                                    }
                                }
                                board[i][j] = board[k][l];
                                board[k][l] = temp;
                                if (!is_checkmate) {
                                    break;
                                }
                            }
                        }
                        if (!is_checkmate) {
                            break;
                        }
                    }
                }
                if (!is_checkmate) {
                    break;
                }
            }
            if (!is_checkmate) {
                break;
            }
        }
        if (is_checkmate) {
            printf("Checkmate! ");
            if (turn == 0) {
                printf("Black wins!\n");
            } else {
                printf("White wins!\n");
            }
            break;
        }
    }
    return 0;
}