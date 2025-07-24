//FormAI DATASET v1.0 Category: Chess AI ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Types of pieces
typedef enum PieceType {
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN,
    EMPTY
} PieceType;

// Colors of pieces
typedef enum PieceColor {
    BLACK,
    WHITE,
    NONE
} PieceColor;

// Structure representing a chess piece
typedef struct Piece {
    PieceType type;
    PieceColor color;
} Piece;

// Structure representing a chess board
typedef struct Board {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    PieceColor turn;
} Board;

// Function to initialize the chess board
void init_board(Board* board) {
    // Rooks
    board->board[0][0] = (Piece) {ROOK, BLACK};
    board->board[0][7] = (Piece) {ROOK, BLACK};
    board->board[7][0] = (Piece) {ROOK, WHITE};
    board->board[7][7] = (Piece) {ROOK, WHITE};

    // Knights
    board->board[0][1] = (Piece) {KNIGHT, BLACK};
    board->board[0][6] = (Piece) {KNIGHT, BLACK};
    board->board[7][1] = (Piece) {KNIGHT, WHITE};
    board->board[7][6] = (Piece) {KNIGHT, WHITE};

    // Bishops
    board->board[0][2] = (Piece) {BISHOP, BLACK};
    board->board[0][5] = (Piece) {BISHOP, BLACK};
    board->board[7][2] = (Piece) {BISHOP, WHITE};
    board->board[7][5] = (Piece) {BISHOP, WHITE};

    // Queens
    board->board[0][3] = (Piece) {QUEEN, BLACK};
    board->board[7][3] = (Piece) {QUEEN, WHITE};

    // Kings
    board->board[0][4] = (Piece) {KING, BLACK};
    board->board[7][4] = (Piece) {KING, WHITE};

    // Pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[1][i] = (Piece) {PAWN, BLACK};
        board->board[6][i] = (Piece) {PAWN, WHITE};
    }

    board->turn = WHITE;
}

// Function to print the chess board
void print_board(Board* board) {
    printf("   A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j].type == EMPTY) {
                printf(". ");
            }
            else if (board->board[i][j].color == BLACK) {
                switch (board->board[i][j].type) {
                    case KING:
                        printf("k ");
                        break;
                    case QUEEN:
                        printf("q ");
                        break;
                    case ROOK:
                        printf("r ");
                        break;
                    case BISHOP:
                        printf("b ");
                        break;
                    case KNIGHT:
                        printf("n ");
                        break;
                    case PAWN:
                        printf("p ");
                        break;
                    default:
                        break;
                }
            }
            else if (board->board[i][j].color == WHITE) {
                switch (board->board[i][j].type) {
                    case KING:
                        printf("K ");
                        break;
                    case QUEEN:
                        printf("Q ");
                        break;
                    case ROOK:
                        printf("R ");
                        break;
                    case BISHOP:
                        printf("B ");
                        break;
                    case KNIGHT:
                        printf("N ");
                        break;
                    case PAWN:
                        printf("P ");
                        break;
                    default:
                        break;
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the move is a legal move
bool is_legal_move(Board* board, int from_x, int from_y, int to_x, int to_y) {
    PieceType from_type = board->board[from_x][from_y].type;
    PieceColor from_color = board->board[from_x][from_y].color;
    PieceType to_type = board->board[to_x][to_y].type;
    PieceColor to_color = board->board[to_x][to_y].color;

    // Check if there is a piece at the starting position
    if (from_type == EMPTY) {
        return false;
    }

    // Check if the piece is moving to a valid position
    if (to_x < 0 || to_x > BOARD_SIZE || to_y < 0 || to_y > BOARD_SIZE) {
        return false;
    }

    // Check if the piece is not moving to its original position
    if (from_x == to_x && from_y == to_y) {
        return false;
    }

    // Check if the piece is of the correct color
    if (from_color != board->turn) {
        return false;
    }

    // Check if the piece is obstructed by another piece (not valid for knights)
    if (from_type != KNIGHT) {
        int dx = to_x - from_x;
        int dy = to_y - from_y;
        int abs_dx = abs(dx);
        int abs_dy = abs(dy);
        int x_step = dx / abs_dx;
        int y_step = dy / abs_dy;
        int curr_x = from_x + x_step;
        int curr_y = from_y + y_step;
        while (curr_x != to_x || curr_y != to_y) {
            if (board->board[curr_x][curr_y].color != NONE) {
                return false;
            }
            curr_x += x_step;
            curr_y += y_step;
        }
    }

    // Check if the piece is moving to a location with a piece of the opposite color
    if (to_color == from_color) {
        return false;
    }

    // Check for specific legal moves for each piece type
    switch (from_type) {
        case KING:
            if (abs(to_x - from_x) > 1 || abs(to_y - from_y) > 1) {
                // Check for castle
                if (to_x == from_x && abs(to_y - from_y) == 2 && to_color == NONE) {
                    Piece rook = board->board[to_x][to_y > from_y ? 7 : 0];
                    if (rook.type == ROOK && rook.color == from_color && board->board[from_x][from_y + (to_y-from_y)/2].type == EMPTY) {
                        // Check that the king is not in check and that it doesn't move through check
                        if (is_legal_move(board, from_x, from_y, from_x, from_y + (to_y-from_y)/2) && is_legal_move(board, from_x, from_y + (to_y-from_y)/2, to_x, to_y)) {
                            return true;
                        }
                    }
                }
                return false;
            }
            break;
        case QUEEN:
            if (to_x - from_x != 0 && to_y - from_y != 0 && abs(to_x - from_x) != abs(to_y - from_y)) {
                return false;
            }
            break;
        case ROOK:
            if (to_x - from_x != 0 && to_y - from_y != 0) {
                return false;
            }
            break;
        case BISHOP:
            if (to_x - from_x == 0 || to_y - from_y == 0 || abs(to_x - from_x) != abs(to_y - from_y)) {
                return false;
            }
            break;
        case KNIGHT:
            if (abs(to_x - from_x) * abs(to_y - from_y) != 2) {
                return false;
            }
            break;
        case PAWN:
            if (from_color == WHITE) {
                if (to_x == from_x - 1 && to_y == from_y && to_color == NONE) {
                    return true;
                }
                if (from_x == 6 && to_x == 4 && to_y == from_y && board->board[4][from_y].type == EMPTY && to_color == NONE) {
                    return true;
                }
                if (to_x == from_x - 1 && abs(to_y - from_y) == 1 && to_color == BLACK) {
                    return true;
                }
            }
            else {
                if (to_x == from_x + 1 && to_y == from_y && to_color == NONE) {
                    return true;
                }
                if (from_x == 1 && to_x == 3 && to_y == from_y && board->board[3][from_y].type == EMPTY && to_color == NONE) {
                    return true;
                }
                if (to_x == from_x + 1 && abs(to_y - from_y) == 1 && to_color == WHITE) {
                    return true;
                }
            }
            return false;
        default:
            break;
    }

    return true;
}

// Function to make a move on the chess board
bool make_move(Board* board, int from_x, int from_y, int to_x, int to_y) {
    if (!is_legal_move(board, from_x, from_y, to_x, to_y)) {
        return false;
    }

    PieceType from_type = board->board[from_x][from_y].type;
    PieceColor from_color = board->board[from_x][from_y].color;
    PieceType to_type = board->board[to_x][to_y].type;
    PieceColor to_color = board->board[to_x][to_y].color;

    // Check for en passant capture
    if (from_type == PAWN && to_x == from_x && abs(to_y - from_y) == 1 && to_color == NONE && board->board[from_x][to_y].type == PAWN && board->board[from_x][to_y].color != board->turn) {
        board->board[from_x][to_y].type = EMPTY;
        board->board[from_x][to_y].color = NONE;
    }

    // Check for pawn promotion
    if (from_type == PAWN && ((from_color == WHITE && to_x == 0) || (from_color == BLACK && to_x == 7))) {
        char piece_lookup[6] = {'q', 'r', 'b', 'n', '\0'};
        char promotion_type;
        do {
            printf("Enter promotion type (q, r, b, n): ");
            scanf(" %c", &promotion_type);
        } while (strchr(piece_lookup, promotion_type) == NULL);
        switch (promotion_type) {
            case 'q':
                board->board[to_x][to_y] = (Piece) {QUEEN, from_color};
                break;
            case 'r':
                board->board[to_x][to_y] = (Piece) {ROOK, from_color};
                break;
            case 'b':
                board->board[to_x][to_y] = (Piece) {BISHOP, from_color};
                break;
            case 'n':
                board->board[to_x][to_y] = (Piece) {KNIGHT, from_color};
                break;
            default:
                break;
        }
    }
    else {
        board->board[to_x][to_y] = (Piece) {from_type, from_color};
    }

    board->board[from_x][from_y] = (Piece) {EMPTY, NONE};

    // Switch turns
    board->turn = (board->turn == WHITE) ? BLACK : WHITE;

    return true;
}

int main() {
    Board board;
    init_board(&board);

    int from_x, from_y, to_x, to_y;
    while (true) {
        print_board(&board);
        printf("%s's turn\n", (board.turn == BLACK) ? "Black" : "White");
        printf("Enter move (ex: a2 a4): ");
        scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);
        from_x--;
        from_y--;
        to_x--;
        to_y--;

        if (!make_move(&board, from_x, from_y, to_x, to_y)) {
            printf("Invalid move!\n");
        }

        // Check for checkmate and stalemate
        bool white_king_checked = false;
        bool black_king_checked = false;
        bool valid_move_exists = false;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board.board[i][j].color == board.turn) {
                    for (int k = 0; k < BOARD_SIZE; k++) {
                        for (int l = 0; l < BOARD_SIZE; l++) {
                            if (is_legal_move(&board, i, j, k, l)) {
                                Board temp_board = board;
                                make_move(&temp_board, i, j, k, l);
                                if (temp_board.turn == WHITE && temp_board.board[temp_board.board[0][4].type == KING ? 0 : 7][4].type != KING) {
                                    white_king_checked = true;
                                }
                                else if (temp_board.turn == BLACK && temp_board.board[temp_board.board[0][4].type == KING ? 0 : 7][4].type != KING) {
                                    black_king_checked = true;
                                }
                                valid_move_exists = true;
                            }
                        }
                    }
                }
            }
        }

        if (board.turn == WHITE && white_king_checked && !valid_move_exists) {
            printf("Checkmate! Black wins!\n");
            break;
        }
        else if (board.turn == BLACK && black_king_checked && !valid_move_exists) {
            printf("Checkmate! White wins!\n");
            break;
        }
        else if (!valid_move_exists) {
            printf("Stalemate!\n");
            break;
        }
    }

    return 0;
}