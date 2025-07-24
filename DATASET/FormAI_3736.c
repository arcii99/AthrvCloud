//FormAI DATASET v1.0 Category: Chess engine ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define BLACK 'B'
#define WHITE 'W'
#define MAX_DEPTH 3

typedef struct Piece {
    char color;
    char type;
} Piece;

typedef struct Square {
    int row;
    int col;
} Square;

typedef struct Move {
    Square from;
    Square to;
} Move;

Piece board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    int r, c;
    // set up black pieces
    board[0][0].type = 'R'; board[0][0].color = BLACK;
    board[0][1].type = 'N'; board[0][1].color = BLACK;
    board[0][2].type = 'B'; board[0][2].color = BLACK;
    board[0][3].type = 'Q'; board[0][3].color = BLACK;
    board[0][4].type = 'K'; board[0][4].color = BLACK;
    board[0][5].type = 'B'; board[0][5].color = BLACK;
    board[0][6].type = 'N'; board[0][6].color = BLACK;
    board[0][7].type = 'R'; board[0][7].color = BLACK;
    for (c = 0; c < BOARD_SIZE; c++) {
        board[1][c].type = 'P'; board[1][c].color = BLACK;
    }
    // set up white pieces
    board[7][0].type = 'R'; board[7][0].color = WHITE;
    board[7][1].type = 'N'; board[7][1].color = WHITE;
    board[7][2].type = 'B'; board[7][2].color = WHITE;
    board[7][3].type = 'Q'; board[7][3].color = WHITE;
    board[7][4].type = 'K'; board[7][4].color = WHITE;
    board[7][5].type = 'B'; board[7][5].color = WHITE;
    board[7][6].type = 'N'; board[7][6].color = WHITE;
    board[7][7].type = 'R'; board[7][7].color = WHITE;
    for (c = 0; c < BOARD_SIZE; c++) {
        board[6][c].type = 'P'; board[6][c].color = WHITE;
    }
    // set up empty squares
    for (r = 2; r < 6; r++) {
        for (c = 0; c < BOARD_SIZE; c++) {
            board[r][c].type = '.';
        }
    }
}

void print_board() {
    int r, c;
    for (r = 0; r < BOARD_SIZE; r++) {
        for (c = 0; c < BOARD_SIZE; c++) {
            printf("%c ", board[r][c].type);
        }
        printf("\n");
    }
}

int is_move_valid(char player_color, Move move) {
    if (move.from.row < 0 || move.from.row >= BOARD_SIZE || move.from.col < 0 || move.from.col >= BOARD_SIZE) {
        return 0;
    }
    if (board[move.from.row][move.from.col].type == '.' || board[move.from.row][move.from.col].color != player_color) {
        return 0;
    }
    if (move.to.row < 0 || move.to.row >= BOARD_SIZE || move.to.col < 0 || move.to.col >= BOARD_SIZE) {
        return 0;
    }
    Piece from_piece = board[move.from.row][move.from.col];
    Piece to_piece = board[move.to.row][move.to.col];
    if (to_piece.type != '.' && to_piece.color == player_color) {
        return 0;
    }
    // TODO: more validation based on piece type
    return 1;
}

void make_move(Move move) {
    board[move.to.row][move.to.col] = board[move.from.row][move.from.col];
    board[move.from.row][move.from.col].type = '.';
}

void unmake_move(Move move, Piece captured) {
    board[move.to.row][move.to.col] = captured;
    board[move.from.row][move.from.col] = board[move.to.row][move.to.col];
    board[move.to.row][move.to.col].type = '.';
}

int score_board(char player_color) {
    // Simple evaluation function which just counts number of pieces for player
    int r, c, score = 0;
    for (r = 0; r < BOARD_SIZE; r++) {
        for (c = 0; c < BOARD_SIZE; c++) {
            Piece p = board[r][c];
            if (p.type != '.') {
                if (p.color == player_color) {
                    score += 1;
                } else {
                    score -= 1;
                }
            }
        }
    }
    return score;
}

int alpha_beta_search(char player_color, int depth, int alpha, int beta) {
    if (depth == 0) {
        return score_board(player_color);
    }
    int r, c, new_score;
    Piece captured;
    char opponent_color = (player_color == WHITE) ? BLACK : WHITE;
    int best_score = (player_color == WHITE) ? -99999 : 99999;
    for (r = 0; r < BOARD_SIZE; r++) {
        for (c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c].color == player_color) {
                // Try all possible moves for this piece
                int dr, dc;
                int move_count = 0;
                Square moves[28];
                switch (board[r][c].type) {
                    case 'P':
                        dr = (player_color == WHITE) ? -1 : 1;
                        if (board[r+dr][c].type == '.') {
                            moves[move_count].row = r+dr; moves[move_count].col = c; move_count++;
                            if ((player_color == WHITE && r == 6) || (player_color == BLACK && r == 1)) {
                                if (board[r+2*dr][c].type == '.') {
                                    moves[move_count].row = r+2*dr; moves[move_count].col = c; move_count++;
                                }
                            }
                        }
                        if (c > 0 && board[r+dr][c-1].color == opponent_color) {
                            moves[move_count].row = r+dr; moves[move_count].col = c-1; move_count++;
                        }
                        if (c < BOARD_SIZE - 1 && board[r+dr][c+1].color == opponent_color) {
                            moves[move_count].row = r+dr; moves[move_count].col = c+1; move_count++;
                        }
                        break;
                    default: break;
                }
                int i;
                for (i = 0; i < move_count; i++) {
                    Move move = { {r, c}, {moves[i].row, moves[i].col} };
                    if (is_move_valid(player_color, move)) {
                        captured = board[moves[i].row][moves[i].col];
                        make_move(move);
                        new_score = alpha_beta_search(opponent_color, depth-1, alpha, beta);
                        unmake_move(move, captured);
                        if (player_color == WHITE) {
                            if (new_score > best_score) {
                                best_score = new_score;
                            }
                            if (new_score > alpha) {
                                alpha = new_score;
                            }
                        } else {
                            if (new_score < best_score) {
                                best_score = new_score;
                            }
                            if (new_score < beta) {
                                beta = new_score;
                            }
                        }
                        if (alpha >= beta) {
                            break;
                        }
                    }
                }
            }
        }
    }
    return best_score;
}

Move get_next_move(char player_color) {
    char opponent_color = (player_color == WHITE) ? BLACK : WHITE;
    int r, c, score, new_score;
    int best_score = (player_color == WHITE) ? -99999 : 99999;
    Move best_move = { {0,0}, {0,0} };
    for (r = 0; r < BOARD_SIZE; r++) {
        for (c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c].color == player_color) {
                // Try all possible moves for this piece
                int dr, dc;
                int move_count = 0;
                Square moves[28];
                switch (board[r][c].type) {
                    case 'P':
                        dr = (player_color == WHITE) ? -1 : 1;
                        if (board[r+dr][c].type == '.') {
                            moves[move_count].row = r+dr; moves[move_count].col = c; move_count++;
                            if ((player_color == WHITE && r == 6) || (player_color == BLACK && r == 1)) {
                                if (board[r+2*dr][c].type == '.') {
                                    moves[move_count].row = r+2*dr; moves[move_count].col = c; move_count++;
                                }
                            }
                        }
                        if (c > 0 && board[r+dr][c-1].color == opponent_color) {
                            moves[move_count].row = r+dr; moves[move_count].col = c-1; move_count++;
                        }
                        if (c < BOARD_SIZE - 1 && board[r+dr][c+1].color == opponent_color) {
                            moves[move_count].row = r+dr; moves[move_count].col = c+1; move_count++;
                        }
                        break;
                    default: break;
                }
                int i;
                for (i = 0; i < move_count; i++) {
                    Move move = { {r, c}, {moves[i].row, moves[i].col} };
                    if (is_move_valid(player_color, move)) {
                        Piece captured = board[moves[i].row][moves[i].col];
                        make_move(move);
                        new_score = alpha_beta_search(opponent_color, MAX_DEPTH, -99999, 99999);
                        unmake_move(move, captured);
                        if (player_color == WHITE) {
                            if (new_score > best_score) {
                                best_score = new_score;
                                best_move = move;
                            }
                        } else {
                            if (new_score < best_score) {
                                best_score = new_score;
                                best_move = move;
                            }
                        }
                    }
                }
            }
        }
    }
    return best_move;
}

int main() {
    initialize_board();
    print_board();
    char player_color = WHITE;
    while (1) {
        printf("Player %c's turn\n", player_color);
        Move move;
        if (player_color == WHITE) {
            printf("Enter move in row1,col1,row2,col2 format: ");
            scanf("%d,%d,%d,%d", &move.from.row, &move.from.col, &move.to.row, &move.to.col);
            while (!is_move_valid(player_color, move)) {
                printf("Invalid move, enter again: ");
                scanf("%d,%d,%d,%d", &move.from.row, &move.from.col, &move.to.row, &move.to.col);
            }
        } else {
            move = get_next_move(player_color);
            printf("Computer's move: %d,%d,%d,%d\n", move.from.row, move.from.col, move.to.row, move.to.col);
        }
        make_move(move);
        print_board();
        if (score_board(player_color) == 0) {
            printf("Game over, it's a draw!\n");
            return 0;
        }
        if (player_color == WHITE) {
            player_color = BLACK;
        } else {
            player_color = WHITE;
        }
    }
    return 0;
}