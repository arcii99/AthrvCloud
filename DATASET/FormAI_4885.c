//FormAI DATASET v1.0 Category: Chess engine ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 4
#define PAWN_VALUE 100
#define KNIGHT_VALUE 300
#define BISHOP_VALUE 300
#define ROOK_VALUE 500
#define QUEEN_VALUE 900
#define KING_VALUE 2000

typedef struct {
    int row;
    int col;
} Position;

typedef enum {
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
} Piece;

typedef enum {
    WHITE,
    BLACK
} Color;

typedef struct {
    Piece piece;
    Color color;
} Square;

typedef struct {
    Square board[BOARD_SIZE][BOARD_SIZE];
    Color turn;
    bool castle_white_king_side;
    bool castle_white_queen_side;
    bool castle_black_king_side;
    bool castle_black_queen_side;
    Position en_passant_square;
    int half_moves_since_pawn_moved;
    int move_number;
} Board;

int evaluate_board(Board *board) {
    int white_points = 0;
    int black_points = 0;
    
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            Square square = board->board[row][col];
            if (square.piece == EMPTY) {
                continue;
            }
            int piece_value;
            switch (square.piece) {
                case PAWN:
                    piece_value = PAWN_VALUE;
                    break;
                case KNIGHT:
                    piece_value = KNIGHT_VALUE;
                    break;
                case BISHOP:
                    piece_value = BISHOP_VALUE;
                    break;
                case ROOK:
                    piece_value = ROOK_VALUE;
                    break;
                case QUEEN:
                    piece_value = QUEEN_VALUE;
                    break;
                case KING:
                    piece_value = KING_VALUE;
                    break;
            }
            if (square.color == WHITE) {
                white_points += piece_value;
            } else {
                black_points += piece_value;
            }
        }
    }
    return white_points - black_points;
}

int negamax(Board *board, int alpha, int beta, int depth) {
    if (depth == 0) {
        return evaluate_board(board);
    }
    int best_score = -999999;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            Square square = board->board[row][col];
            if (square.piece == EMPTY || square.color != board->turn) {
                continue;
            }
            // TODO: Calculate legal moves for the piece
            // for each legal move
            // make the move on a copy of the board and evaluate the position
            // score = -negamax(copy_of_board, -beta, -alpha, depth - 1)
            // if (score >= beta)
            //     return beta
            // if (score > best_score)
            //     best_score = score
            //     if (alpha < score)
            //         alpha = score
        }
    }
    return best_score;
}

int main(void) {
    // Initialize the board
    Board board;
    board.turn = WHITE;
    board.castle_white_king_side = true;
    board.castle_white_queen_side = true;
    board.castle_black_king_side = true;
    board.castle_black_queen_side = true;
    board.en_passant_square.row = -1;
    board.en_passant_square.col = -1;
    board.half_moves_since_pawn_moved = 0;
    board.move_number = 1;
    // Set up the starting position
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (row == 0 || row == 7) {
                if (col == 0 || col == 7) {
                    board.board[row][col].piece = ROOK;
                } else if (col == 1 || col == 6) {
                    board.board[row][col].piece = KNIGHT;
                } else if (col == 2 || col == 5) {
                    board.board[row][col].piece = BISHOP;
                } else if (col == 3) {
                    board.board[row][col].piece = QUEEN;
                } else if (col == 4) {
                    board.board[row][col].piece = KING;
                }
                if (row == 0) {
                    board.board[row][col].color = BLACK;
                } else {
                    board.board[row][col].color = WHITE;
                }
            } else if (row == 1 || row == 6) {
                board.board[row][col].piece = PAWN;
                if (row == 1) {
                    board.board[row][col].color = BLACK;
                } else {
                    board.board[row][col].color = WHITE;
                }
            } else {
                board.board[row][col].piece = EMPTY;
            }
        }
    }
    // Evaluate the position
    int score = negamax(&board, -999999, 999999, MAX_DEPTH);
    printf("The score is %d\n", score);
    return 0;
}