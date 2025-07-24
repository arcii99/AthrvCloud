//FormAI DATASET v1.0 Category: Chess engine ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } piece;
typedef enum { WHITE, BLACK } color;

typedef struct {
    piece pc;
    color cl;
} square;

typedef struct {
    square s[BOARD_SIZE][BOARD_SIZE];
    color turn;
    int w_king_pos[2];
    int b_king_pos[2];
    bool w_king_moved, b_king_moved;
    bool w_rook1_moved, w_rook2_moved;
    bool b_rook1_moved, b_rook2_moved;
} board;

void init_board(board *b) {
    b->w_king_pos[0] = 7;
    b->w_king_pos[1] = 4;
    b->b_king_pos[0] = 0;
    b->b_king_pos[1] = 4;
    b->w_king_moved = false;
    b->b_king_moved = false;
    b->w_rook1_moved = false;
    b->w_rook2_moved = false;
    b->b_rook1_moved = false;
    b->b_rook2_moved = false;
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == 7) {
                if (j == 0 || j == 7) {
                    b->s[i][j].pc = ROOK;
                } else if (j == 1 || j == 6) {
                    b->s[i][j].pc = KNIGHT;
                } else if (j == 2 || j == 5) {
                    b->s[i][j].pc = BISHOP;
                } else if (j == 3) {
                    b->s[i][j].pc = QUEEN;
                } else if (j == 4) {
                    b->s[i][j].pc = KING;
                }
                if (i == 0) {
                    b->s[i][j].cl = BLACK;
                } else {
                    b->s[i][j].cl = WHITE;
                }
            } else if (i == 1 || i == 6) {
                b->s[i][j].pc = PAWN;
                if (i == 1) {
                    b->s[i][j].cl = BLACK;
                } else {
                    b->s[i][j].cl = WHITE;
                }
            } else {
                b->s[i][j].pc = EMPTY;
            }
        }
    }
}


void print_board(board b) {
    printf("\n\n\t    A  B  C  D  E  F  G  H  \n"
           "\t  +------------------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\t%d |", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (b.s[i][j].pc) {
                case EMPTY:
                    printf(" _ ");
                    break;
                case PAWN:
                    printf(b.s[i][j].cl == WHITE ? " P " : " p ");
                    break;
                case KNIGHT:
                    printf(b.s[i][j].cl == WHITE ? " N " : " n ");
                    break;
                case BISHOP:
                    printf(b.s[i][j].cl == WHITE ? " B " : " b ");
                    break;
                case ROOK:
                    printf(b.s[i][j].cl == WHITE ? " R " : " r ");
                    break;
                case QUEEN:
                    printf(b.s[i][j].cl == WHITE ? " Q " : " q ");
                    break;
                case KING:
                    printf(b.s[i][j].cl == WHITE ? " K " : " k ");
                    break;
            }
        }
        printf("| %d\n", i + 1);
    }
    printf("\t  +------------------------+\n"
           "\t    A  B  C  D  E  F  G  H  \n\n");
}

int letter_to_num(char c) {
    switch (c) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        default:
            return -1;
    }
}

bool valid_input(char *input) {
    if (strlen(input) != 4) {
        return false;
    }
    int from_x = letter_to_num(input[0]), from_y = input[1] - '1';
    int to_x = letter_to_num(input[2]), to_y = input[3] - '1';
    if (from_x < 0 || from_x >= BOARD_SIZE || from_y < 0 || from_y >= BOARD_SIZE) {
        return false;
    }
    if (to_x < 0 || to_x >= BOARD_SIZE || to_y < 0 || to_y >= BOARD_SIZE) {
        return false;
    }
    return true;
}

bool is_valid_move(board b, int from_x, int from_y, int to_x, int to_y) {
    if (from_x < 0 || from_x >= BOARD_SIZE || from_y < 0 || from_y >= BOARD_SIZE) {
        return false;
    }
    if (to_x < 0 || to_x >= BOARD_SIZE || to_y < 0 || to_y >= BOARD_SIZE) {
        return false;
    }
    if (b.s[from_x][from_y].pc == EMPTY || b.s[from_x][from_y].cl != b.turn) {
        return false;
    }
    if (b.s[from_x][from_y].pc == PAWN) {
        if (b.turn == WHITE && to_x == from_x - 1 && to_y == from_y && b.s[to_x][to_y].pc == EMPTY) {
            return true;
        }
        if (b.turn == BLACK && to_x == from_x + 1 && to_y == from_y && b.s[to_x][to_y].pc == EMPTY) {
            return true;
        }
        if (b.turn == WHITE && to_x == from_x - 2 && to_y == from_y && b.s[to_x][to_y].pc == EMPTY
            && b.s[from_x - 1][from_y].pc == EMPTY && from_x == 6) {
            return true;
        }
        if (b.turn == BLACK && to_x == from_x + 2 && to_y == from_y && b.s[to_x][to_y].pc == EMPTY
            && b.s[from_x + 1][from_y].pc == EMPTY && from_x == 1) {
            return true;
        }
        if (b.turn == WHITE && (to_x == from_x - 1 && to_y == from_y - 1 ||
                                 to_x == from_x - 1 && to_y == from_y + 1) && b.s[to_x][to_y].cl == BLACK) {
            return true;
        }
        if (b.turn == BLACK && (to_x == from_x + 1 && to_y == from_y - 1 ||
                                 to_x == from_x + 1 && to_y == from_y + 1) && b.s[to_x][to_y].cl == WHITE) {
            return true;
        }
        return false;
    }
    return true;
}

void make_move(board *b, int from_x, int from_y, int to_x, int to_y) {
    b->s[to_x][to_y] = b->s[from_x][from_y];
    b->s[from_x][from_y].pc = EMPTY;
    b->s[from_x][from_y].cl = 0;
    b->turn = b->turn == WHITE ? BLACK : WHITE;
    if (b->s[to_x][to_y].pc == KING) {
        if (b->turn == WHITE) {
            b->w_king_pos[0] = to_x;
            b->w_king_pos[1] = to_y;
            b->w_king_moved = true;
        } else {
            b->b_king_pos[0] = to_x;
            b->b_king_pos[1] = to_y;
            b->b_king_moved = true;
        }
    } else if (b->s[to_x][to_y].pc == ROOK) {
        if (b->turn == WHITE) {
            if (from_x == 7 && from_y == 0) {
                b->w_rook1_moved = true;
            } else if (from_x == 7 && from_y == 7) {
                b->w_rook2_moved = true;
            }
        } else {
            if (from_x == 0 && from_y == 0) {
                b->b_rook1_moved = true;
            } else if (from_x == 0 && from_y == 7) {
                b->b_rook2_moved = true;
            }
        }
    }
}

bool is_in_check(board b, int king_x, int king_y) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (b.s[i][j].pc != EMPTY && b.s[i][j].cl != b.turn) {
                if (is_valid_move(b, i, j, king_x, king_y)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool is_in_checkmate(board b, int king_x, int king_y) {
    for (int i = king_x - 1; i <= king_x + 1; i++) {
        for (int j = king_y - 1; j <= king_y + 1; j++) {
            if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && (i != king_x || j != king_y)) {
                if (b.s[i][j].pc == EMPTY || b.s[i][j].cl != b.turn) {
                    board temp = b;
                    make_move(&temp, king_x, king_y, i, j);
                    if (!is_in_check(temp, i, j)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    board b;
    init_board(&b);
    printf("Welcome to chess!\n\n");
    print_board(b);
    while (1) {
        printf("%s's turn (enter 'q' to quit): ", b.turn == WHITE ? "White" : "Black");
        char input[5];
        fgets(input, 5, stdin);
        if (strcmp(input, "q\n") == 0) {
            printf("Thanks for playing!\n");
            return 0;
        }
        if (valid_input(input)) {
            int from_x = letter_to_num(input[0]), from_y = input[1] - '1';
            int to_x = letter_to_num(input[2]), to_y = input[3] - '1';
            if (is_valid_move(b, from_x, from_y, to_x, to_y)) {
                make_move(&b, from_x, from_y, to_x, to_y);
                print_board(b);
                if (is_in_checkmate(b, b.turn == WHITE ? b.w_king_pos[0] : b.b_king_pos[0],
                                    b.turn == WHITE ? b.w_king_pos[1] : b.b_king_pos[1])) {
                    printf("%s is in checkmate! %s wins!\n", b.turn == WHITE ? "Black" : "White",
                           b.turn == WHITE ? "Black" : "White");
                    return 0;
                } else if (is_in_check(b, b.turn == WHITE ? b.w_king_pos[0] : b.b_king_pos[0], 
                                        b.turn == WHITE ? b.w_king_pos[1] : b.b_king_pos[1])) {
                    printf("%s is in check!\n", b.turn == WHITE ? "White" : "Black");
                }
            } else {
                printf("Invalid move, try again.\n");
            }
        } else {
            printf("Invalid input, try again.\n");
        }
    }
}