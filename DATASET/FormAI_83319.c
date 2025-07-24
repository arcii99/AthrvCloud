//FormAI DATASET v1.0 Category: Checkers Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, RED, BLACK } Piece;
typedef enum { OK, ILLEGAL_MOVE, ILLEGAL_INPUT } MoveStatus;

void init_board(Piece board[][BOARD_SIZE]);
void print_board(Piece board[][BOARD_SIZE]);
MoveStatus move(Piece board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y);
int can_capture(Piece board[][BOARD_SIZE], int x, int y);
int is_valid_move(Piece board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y);

int main()
{
    Piece board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    print_board(board);
    
    int player = RED;
    while (1) {
        printf("%s turn\n", player == RED ? "Red" : "Black");

        int from_x, from_y, to_x, to_y;
        printf("Enter from position (x, y): ");
        if (scanf("%d %d", &from_x, &from_y) != 2) {
            printf("Invalid input, please try again\n");
            continue;
        }

        printf("Enter to position (x, y): ");
        if (scanf("%d %d", &to_x, &to_y) != 2) {
            printf("Invalid input, please try again\n");
            continue;
        }

        MoveStatus status = move(board, from_x, from_y, to_x, to_y);
        if (status == ILLEGAL_MOVE) {
            printf("Illegal move, please try again\n");
        } else if (status == ILLEGAL_INPUT) {
            printf("Invalid input, please try again\n");
        } else {
            print_board(board);
            if (player == RED) {
                if (can_capture(board, to_x, to_y)) {
                    printf("Red has another move, enter next move\n");
                } else {
                    player = BLACK;
                }
            } else {
                if (can_capture(board, to_x, to_y)) {
                    printf("Black has another move, enter next move\n");
                } else {
                    player = RED;
                }
            }
        }
    }

    return 0;
}

void init_board(Piece board[][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0 && i < 3) {
                board[i][j] = BLACK;
            } else if ((i + j) % 2 == 0 && i > 4) {
                board[i][j] = RED;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void print_board(Piece board[][BOARD_SIZE])
{
    printf("  ");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j] == EMPTY ? '.' : board[i][j] == RED ? 'r' : 'b');
        }
        printf("%d\n", i);
    }

    printf("  ");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("%d ", j);
    }
    printf("\n");
}

MoveStatus move(Piece board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y)
{
    if (from_x < 0 || from_x >= BOARD_SIZE || from_y < 0 || from_y >= BOARD_SIZE
        || to_x < 0 || to_x >= BOARD_SIZE || to_y < 0 || to_y >= BOARD_SIZE) {
        return ILLEGAL_INPUT;
    }

    if (board[from_x][from_y] == EMPTY || board[to_x][to_y] != EMPTY) {
        return ILLEGAL_MOVE;
    }

    if (!is_valid_move(board, from_x, from_y, to_x, to_y)) {
        return ILLEGAL_MOVE;
    }

    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = EMPTY;

    if (abs(from_x - to_x) == 2) {
        int captured_x = (from_x + to_x) / 2;
        int captured_y = (from_y + to_y) / 2;
        board[captured_x][captured_y] = EMPTY;
    }

    return OK;
}

int can_capture(Piece board[][BOARD_SIZE], int x, int y)
{
    if (board[x][y] == RED) {
        if (x < BOARD_SIZE - 2 && y > 1 && board[x+1][y-1] == BLACK && board[x+2][y-2] == EMPTY) {
            return 1;
        } else if (x < BOARD_SIZE - 2 && y < BOARD_SIZE - 2 && board[x+1][y+1] == BLACK && board[x+2][y+2] == EMPTY) {
            return 1;
        } else if (x > 1 && y > 1 && board[x-1][y-1] == BLACK && board[x-2][y-2] == EMPTY) {
            return 1;
        } else if (x > 1 && y < BOARD_SIZE - 2 && board[x-1][y+1] == BLACK && board[x-2][y+2] == EMPTY) {
            return 1;
        }
    } else if (board[x][y] == BLACK) {
        if (x > 1 && y > 1 && board[x-1][y-1] == RED && board[x-2][y-2] == EMPTY) {
            return 1;
        } else if (x > 1 && y < BOARD_SIZE - 2 && board[x-1][y+1] == RED && board[x-2][y+2] == EMPTY) {
            return 1;
        } else if (x < BOARD_SIZE - 2 && y > 1 && board[x+1][y-1] == RED && board[x+2][y-2] == EMPTY) {
            return 1;
        } else if (x < BOARD_SIZE - 2 && y < BOARD_SIZE - 2 && board[x+1][y+1] == RED && board[x+2][y+2] == EMPTY) {
            return 1;
        }
    }

    return 0;
}

int is_valid_move(Piece board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y)
{
    if (abs(from_x - to_x) != abs(from_y - to_y)) {
        return 0;
    }

    if (board[from_x][from_y] == RED) {
        if (to_x > from_x) {
            return 0;
        }

        if ((from_x - to_x == 1 && abs(from_y - to_y) == 1 && board[to_x][to_y] == EMPTY)
            || (from_x - to_x == 2 && abs(from_y - to_y) == 2 && board[to_x][to_y] == EMPTY
                && board[(from_x + to_x) / 2][(from_y + to_y) / 2] == BLACK)) {
            return 1;
        }
    } else if (board[from_x][from_y] == BLACK) {
        if (to_x < from_x) {
            return 0;
        }

        if ((to_x - from_x == 1 && abs(from_y - to_y) == 1 && board[to_x][to_y] == EMPTY)
            || (to_x - from_x == 2 && abs(from_y - to_y) == 2 && board[to_x][to_y] == EMPTY
                && board[(from_x + to_x) / 2][(from_y + to_y) / 2] == RED)) {
            return 1;
        }
    }

    return 0;
}