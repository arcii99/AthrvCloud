//FormAI DATASET v1.0 Category: Chess engine ; Style: real-life
#include <stdio.h>

// define board and pieces as constants
#define SIZE 8
#define EMPTY '-'
#define WHITE 'W'
#define BLACK 'B'
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'
#define QUEEN 'Q'
#define KING 'K'

// define struct for each square
typedef struct {
    char piece;
    char color;
} Square;

// define struct for each move
typedef struct {
    int from_row;
    int from_col;
    int to_row;
    int to_col;
} Move;

// create the board
Square board[SIZE][SIZE] = {
    { {ROOK,   BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {QUEEN,  BLACK},
      {KING,   BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK,   BLACK} },
    { {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK},
      {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK} },
    { {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY},
      {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY} },
    { {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY},
      {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY} },
    { {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY},
      {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY} },
    { {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY},
      {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY}, {EMPTY,  EMPTY} },
    { {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE},
      {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE} },
    { {ROOK,   WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {QUEEN,  WHITE},
      {KING,   WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK,   WHITE} }
};

// function to print the board
void print_board() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j].piece);
        }
        printf("\n");
    }
}

// function to check if a move is legal
int is_move_legal(Move move) {
    char piece = board[move.from_row][move.from_col].piece;
    char color = board[move.from_row][move.from_col].color;
    // check if piece and color match
    if (color == WHITE && (piece != PAWN && piece != KNIGHT && piece != BISHOP && piece != ROOK && piece != QUEEN && piece != KING)) {
        printf("Error: Invalid Piece.\n");
        return 0;
    } else if (color == BLACK && (piece != PAWN && piece != KNIGHT && piece != BISHOP && piece != ROOK && piece != QUEEN && piece != KING)) {
        printf("Error: Invalid Piece.\n");
        return 0;
    }
    // check if move is within the board
    if (move.from_row < 0 || move.from_row >= SIZE || move.from_col < 0 || move.from_col >= SIZE ||
        move.to_row < 0 || move.to_row >= SIZE || move.to_col < 0 || move.to_col >= SIZE) {
        printf("Error: Move is out of range.\n");
        return 0;
    }
    // check if piece can move to the new position
    if (piece == PAWN) {
        if (color == WHITE && move.from_col == move.to_col && move.to_row == move.from_row - 1 && board[move.to_row][move.to_col].piece == EMPTY) {
            return 1;
        } else if (color == BLACK && move.from_col == move.to_col && move.to_row == move.from_row + 1 && board[move.to_row][move.to_col].piece == EMPTY) {
            return 1;
        } else {
            printf("Error: Invalid Move.\n");
            return 0;
        }
    } else if (piece == KNIGHT) {
        if ((move.to_row == move.from_row + 2 && move.to_col == move.from_col + 1) ||
            (move.to_row == move.from_row + 1 && move.to_col == move.from_col + 2) ||
            (move.to_row == move.from_row - 1 && move.to_col == move.from_col + 2) ||
            (move.to_row == move.from_row - 2 && move.to_col == move.from_col + 1) ||
            (move.to_row == move.from_row - 2 && move.to_col == move.from_col - 1) ||
            (move.to_row == move.from_row - 1 && move.to_col == move.from_col - 2) ||
            (move.to_row == move.from_row + 1 && move.to_col == move.from_col - 2) ||
            (move.to_row == move.from_row + 2 && move.to_col == move.from_col - 1)) {
            return 1;
        }
    } else if (piece == BISHOP) {
        if (move.from_row != move.to_row && move.from_col != move.to_col &&
            move.to_row - move.from_row == move.to_col - move.from_col) {
            int i, j;
            if (move.to_row > move.from_row && move.to_col > move.from_col) {
                for (i = move.from_row + 1, j = move.from_col + 1; i < move.to_row; i++, j++) {
                    if (board[i][j].piece != EMPTY) {
                        printf("Error: Invalid Move.\n");
                        return 0;
                    }
                }
            } else if (move.to_row < move.from_row && move.to_col > move.from_col) {
                for (i = move.from_row - 1, j = move.from_col + 1; i > move.to_row; i--, j++) {
                    if (board[i][j].piece != EMPTY) {
                        printf("Error: Invalid Move.\n");
                        return 0;
                    }
                }
            } else if (move.to_row < move.from_row && move.to_col < move.from_col) {
                for (i = move.from_row - 1, j = move.from_col - 1; i > move.to_row; i--, j--) {
                    if (board[i][j].piece != EMPTY) {
                        printf("Error: Invalid Move.\n");
                        return 0;
                    }
                }
            } else if (move.to_row > move.from_row && move.to_col < move.from_col) {
                for (i = move.from_row + 1, j = move.from_col - 1; i < move.to_row; i++, j--) {
                    if (board[i][j].piece != EMPTY) {
                        printf("Error: Invalid Move.\n");
                        return 0;
                    }
                }
            }
            return 1;
        }
    } else if (piece == ROOK) {
        if ((move.from_col == move.to_col && move.from_row != move.to_row) ||
            (move.from_row == move.to_row && move.from_col != move.to_col)) {
            int i;
            if (move.to_row > move.from_row) {
                for (i = move.from_row + 1; i < move.to_row; i++) {
                    if (board[i][move.from_col].piece != EMPTY) {
                        printf("Error: Invalid Move.\n");
                        return 0;
                    }
                }
            } else if (move.to_row < move.from_row) {
                for (i = move.from_row - 1; i > move.to_row; i--) {
                    if (board[i][move.from_col].piece != EMPTY) {
                        printf("Error: Invalid Move.\n");
                        return 0;
                    }
                }
            } else if (move.to_col > move.from_col) {
                for (i = move.from_col + 1; i < move.to_col; i++) {
                    if (board[move.from_row][i].piece != EMPTY) {
                        printf("Error: Invalid Move.\n");
                        return 0;
                    }
                }
            } else if (move.to_col < move.from_col) {
                for (i = move.from_col - 1; i > move.to_col; i--) {
                    if (board[move.from_row][i].piece != EMPTY) {
                        printf("Error: Invalid Move.\n");
                        return 0;
                    }
                }
            }
            return 1;
        }
    } else if (piece == QUEEN) {
        if ((move.from_col == move.to_col && move.from_row != move.to_row) ||
            (move.from_row == move.to_row && move.from_col != move.to_col) ||
            (move.from_row != move.to_row && move.from_col != move.to_col &&
             move.to_row - move.from_row == move.to_col - move.from_col)) {
            int i, j;
            if (move.to_row > move.from_row && move.to_col > move.from_col) {
                for (i = move.from_row + 1, j = move.from_col + 1; i < move.to_row; i++, j++) {
                    if (board[i][j].piece != EMPTY) {
                        printf("Error: Invalid Move.\n");
                        return 0;
                    }
                }
            } else if (move.to_row < move.from_row && move.to_col > move.from_col) {
                for (i = move.from_row - 1, j = move.from_col + 1; i > move.to_row; i--, j++) {
                    if (board[i][j].piece != EMPTY) {
                        printf("Error: Invalid Move.\n");
                        return 0;
                    }
                }
            } else if (move.to_row < move.from_row && move.to_col < move.from_col) {
                for (i = move.from_row - 1, j = move.from_col - 1; i > move.to_row; i--, j--) {
                    if (board[i][j].piece != EMPTY) {
                        printf("Error: Invalid Move.\n");
                        return 0;
                    }
                }
            } else if (move.to_row > move.from_row && move.to_col < move.from_col) {
                for (i = move.from_row + 1, j = move.from_col - 1; i < move.to_row; i++, j--) {
                    if (board[i][j].piece != EMPTY) {
                        printf("Error: Invalid Move.\n");
                        return 0;
                    }
                }
            } else if (move.from_col == move.to_col && move.from_row != move.to_row) {
                int i;
                if (move.to_row > move.from_row) {
                    for (i = move.from_row + 1; i < move.to_row; i++) {
                        if (board[i][move.from_col].piece != EMPTY) {
                            printf("Error: Invalid Move.\n");
                            return 0;
                        }
                    }
                } else if (move.to_row < move.from_row) {
                    for (i = move.from_row - 1; i > move.to_row; i--) {
                        if (board[i][move.from_col].piece != EMPTY) {
                            printf("Error: Invalid Move.\n");
                            return 0;
                        }
                    }
                }
            } else if (move.from_row == move.to_row && move.from_col != move.to_col) {
                int i;
                if (move.to_col > move.from_col) {
                    for (i = move.from_col + 1; i < move.to_col; i++) {
                        if (board[move.from_row][i].piece != EMPTY) {
                            printf("Error: Invalid Move.\n");
                            return 0;
                        }
                    }
                } else if (move.to_col < move.from_col) {
                    for (i = move.from_col - 1; i > move.to_col; i--) {
                        if (board[move.from_row][i].piece != EMPTY) {
                            printf("Error: Invalid Move.\n");
                            return 0;
                        }
                    }
                }
            }
            return 1;
        }
    } else if (piece == KING) {
        if ((move.to_row == move.from_row + 1 && move.to_col == move.from_col) ||
            (move.to_row == move.from_row + 1 && move.to_col == move.from_col + 1) ||
            (move.to_row == move.from_row && move.to_col == move.from_col + 1) ||
            (move.to_row == move.from_row - 1 && move.to_col == move.from_col + 1) ||
            (move.to_row == move.from_row - 1 && move.to_col == move.from_col) ||
            (move.to_row == move.from_row - 1 && move.to_col == move.from_col - 1) ||
            (move.to_row == move.from_row && move.to_col == move.from_col - 1) ||
            (move.to_row == move.from_row + 1 && move.to_col == move.from_col - 1)) {
            return 1;
        }
    }
    printf("Error: Invalid Move.\n");
    return 0;
}

int main() {
    // initialize variables
    int turn = 1;
    int row, col;
    char player[10];
    Move move;

    // print the initial board
    printf("Welcome to C Chess!\n");
    print_board();

    // loop until a king is captured
    while (1) {
        // get player input
        if (turn % 2 == 1) {
            printf("White's move.\n");
            strcpy(player, "White");
        } else {
            printf("Black's move.\n");
            strcpy(player, "Black");
        }
        printf("Enter move (from_row from_col to_row to_col): ");
        scanf("%d %d %d %d", &move.from_row, &move.from_col, &move.to_row, &move.to_col);

        // check if move is legal
        if (!is_move_legal(move)) {
            continue;
        }

        // move the piece
        board[move.to_row][move.to_col].piece = board[move.from_row][move.from_col].piece;
        board[move.to_row][move.to_col].color = board[move.from_row][move.from_col].color;
        board[move.from_row][move.from_col].piece = EMPTY;
        board[move.from_row][move.from_col].color = EMPTY;

        // print the updated board
        print_board();

        // check if a king is captured
        for (row = 0; row < SIZE; row++) {
            for (col = 0; col < SIZE; col++) {
                if (board[row][col].piece == KING && board[row][col].color == player[0] && turn % 2 == 1) {
                    printf("Black Wins!\n");
                    return 0;
                } else if (board[row][col].piece == KING && board[row][col].color == player[0] && turn % 2 == 0) {
                    printf("White Wins!\n");
                    return 0;
                }
            }
        }

        // increment turn counter
        turn++;
    }
    return 0;
}