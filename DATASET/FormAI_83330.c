//FormAI DATASET v1.0 Category: Chess AI ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 4
#define INFINITY 1000000
#define MATE_SCORE 999999

typedef struct {
    int row, col;
} Location;

typedef struct {
    int type;
    int color;
    int has_moved;
} Piece;

typedef struct {
    int board[8][8];
    int castling_rights[2][2];
    int en_passant[2];
    int active_color;
    int halfmove_clock;
    int fullmove_number;
} Board;

typedef struct {
    Location from, to;
} Move;

int evaluate(Board *board) {
    // TODO: Implement evaluation function
}

int negamax(Board *board, int depth, int alpha, int beta, Move *best_move) {
    if (depth == 0) {
        return evaluate(board);
    }
    int best_score = -INFINITY;
    Move legal_moves[256];
    int num_legal_moves = 0;
    // TODO: Generate all legal moves and populate legal_moves and num_legal_moves
    
    for (int i = 0; i < num_legal_moves; i++) {
        Board child_board = *board;
        Move move = legal_moves[i];
        // TODO: Perform the move on the child_board
        
        Move child_best_move;
        int score = -negamax(&child_board, depth-1, -beta, -alpha, &child_best_move);
        score = -score;
        
        if (score > best_score) {
            best_score = score;
            *best_move = move;
        }
        if (score >= beta) {
            return best_score;
        }
        if (score > alpha) {
            alpha = score;
        }
    }
    return best_score;
}

void make_move(Board *board, Move *move) {
    // TODO: Perform the move on the board
}

void unmake_move(Board *board, Move *move) {
    // TODO: Undo the move on the board
}

void print_board(Board *board) {
    // TODO: Print the board
}

void play_game() {
    Board board;
    // TODO: Initialize the board
    
    int game_over = 0;
    int current_depth = MAX_DEPTH;
    while (!game_over) {
        Move best_move;
        int score = negamax(&board, current_depth, -INFINITY, INFINITY, &best_move);
        printf("Score: %d\n", score);
        make_move(&board, &best_move);
        print_board(&board);
        if (score >= MATE_SCORE) {
            printf("%s wins!\n", board.active_color == 0 ? "White" : "Black");
            game_over = 1;
        }
        if (current_depth == 0) {
            printf("Out of time!\n");
            game_over = 1;
        }
        if (board.halfmove_clock >= 100 || score == 0) {
            printf("Draw!\n");
            game_over = 1;
        }
        current_depth--;
    }
}

int main() {
    play_game();
    return 0;
}