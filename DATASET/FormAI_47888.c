//FormAI DATASET v1.0 Category: Checkers Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define NO_PIECE ' '
#define WHITE_PAWN 'W'
#define BLACK_PAWN 'B'
#define WHITE_KING 'K'
#define BLACK_KING 'Q'

typedef struct position {
    int x;
    int y;
} Position;

typedef struct piece {
    char type;
    Position position;
} Piece;

void display_board(Piece board[][BOARD_SIZE]);
void init_board(Piece board[][BOARD_SIZE]);
int check_move(Piece board[][BOARD_SIZE], Position from, Position to);
void move_piece(Piece board[][BOARD_SIZE], Position from, Position to);
void convert_to_king(Piece board[][BOARD_SIZE], Position position);
int check_win(Piece board[][BOARD_SIZE], char player);

int main() {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    Position from, to;
    int valid_move;
    char player = WHITE_PAWN;

    init_board(board);

    while (!check_win(board, player)) {
        printf("\n\n**** %c's Turn ****\n", player);
        display_board(board);

        do {
            printf("Enter the row and column of the piece you want to move: ");
            scanf("%d %d", &from.x, &from.y);
        } while (board[from.x][from.y].type != player && board[from.x][from.y].type != toupper(player));

        do {
            printf("Enter the row and column of the position you want to move to: ");
            scanf("%d %d", &to.x, &to.y);
            valid_move = check_move(board, from, to);
            switch (valid_move) {
                case 0:
                    printf("That is not a valid move!\n");
                    break;
                case 1:
                    printf("You cannot move there, a piece is blocking your way.\n");
                    break;
                case 2:
                    printf("You cannot move backwards with a pawn!\n");
                    break;
                default:
                    move_piece(board, from, to);
                    if (valid_move == 3) {
                        convert_to_king(board, to);
                    }
                    break;
            }
        } while (!valid_move);

        if (player == WHITE_PAWN) {
            player = BLACK_PAWN;
        } else {
            player = WHITE_PAWN;
        }
    }

    printf("\n\n**** %c Wins! ****\n", player);

    return 0;
}

void init_board(Piece board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0 && i < 3) {
                board[i][j].type = BLACK_PAWN;
                board[i][j].position.x = i;
                board[i][j].position.y = j;
            } else if ((i + j) % 2 == 0 && i > 4) {
                board[i][j].type = WHITE_PAWN;
                board[i][j].position.x = i;
                board[i][j].position.y = j;
            } else {
                board[i][j].type = NO_PIECE;
                board[i][j].position.x = i;
                board[i][j].position.y = j;
            }
        }
    }
}

void display_board(Piece board[][BOARD_SIZE]) {
    int i, j;
    printf("\n   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n  -");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("--");
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d| ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j].type);
        }
        printf(" %d\n", i);
    }
    printf("  -");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("--");
    }
    printf("\n   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int check_move(Piece board[][BOARD_SIZE], Position from, Position to) {
    if (board[to.x][to.y].type != NO_PIECE) {
        return 1;
    }
    if (board[from.x][from.y].type == WHITE_PAWN && to.x >= from.x) {
        return 2;
    }
    if (board[from.x][from.y].type == BLACK_PAWN && to.x <= from.x) {
        return 2;
    }
    int x_diff = abs(from.x - to.x);
    int y_diff = abs(from.y - to.y);
    if (x_diff == y_diff ||
        (board[from.x][from.y].type == WHITE_KING || board[from.x][from.y].type == BLACK_KING)) {
        int i, j;
        if (to.x < from.x) {
            i = -1;
        } else {
            i = 1;
        }
        if (to.y < from.y) {
            j = -1;
        } else {
            j = 1;
        }
        for (i += from.x, j += from.y; i != to.x; i += (to.x - from.x) / abs(to.x - from.x), j += (to.y - from.y) / abs(to.y - from.y)) {
            if (board[i][j].type != NO_PIECE) {
                return 1;
            }
        }
        if (board[from.x][from.y].type == WHITE_KING && to.x == BOARD_SIZE - 1) {
            return 3;
        }
        if (board[from.x][from.y].type == BLACK_KING && to.x == 0) {
            return 3;
        }
        return 4;
    }
    return 0;
}

void move_piece(Piece board[][BOARD_SIZE], Position from, Position to) {
    board[to.x][to.y].type = board[from.x][from.y].type;
    board[from.x][from.y].type = NO_PIECE;
    board[to.x][to.y].position.x = to.x;
    board[to.x][to.y].position.y = to.y;
    board[from.x][from.y].position.x = -1;
    board[from.x][from.y].position.y = -1;
}

void convert_to_king(Piece board[][BOARD_SIZE], Position position) {
    if (board[position.x][position.y].type == WHITE_PAWN) {
        board[position.x][position.y].type = WHITE_KING;
    } else {
        board[position.x][position.y].type = BLACK_KING;
    }
}

int check_win(Piece board[][BOARD_SIZE], char player) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == player || board[i][j].type == toupper(player)) {
                Position from = {i, j};
                if (board[i][j].type == WHITE_PAWN || board[i][j].type == WHITE_KING) {
                    if (check_move(board, from, (Position) {i + 1, j + 1}) ||
                        check_move(board, from, (Position) {i + 1, j - 1}) ||
                        check_move(board, from, (Position) {i + 2, j + 2}) ||
                        check_move(board, from, (Position) {i + 2, j - 2})) {
                        return 0;
                    }
                } else {
                    if (check_move(board, from, (Position) {i - 1, j + 1}) ||
                        check_move(board, from, (Position) {i - 1, j - 1}) ||
                        check_move(board, from, (Position) {i - 2, j + 2}) ||
                        check_move(board, from, (Position) {i - 2, j - 2})) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}