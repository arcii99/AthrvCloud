//FormAI DATASET v1.0 Category: Chess engine ; Style: mathematical
#include <stdio.h>

struct board {
    int pieces[8][8];
};

int evaluate_board(struct board game_board, int player);

int minimax(struct board game_board, int depth, int alpha, int beta, int player, int is_maximizing);

void make_move(struct board* game_board, int from_row, int from_col, int to_row, int to_col);

int is_legal_move(struct board game_board, int from_row, int from_col, int to_row, int to_col);

int get_piece_value(int piece, int is_white);

int main(void) {

    //initialize chess board
    struct board game_board;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            game_board.pieces[row][col] = 0;
        }
    }

    //pawn setup
    for (int col = 0; col < 8; col++) {
        game_board.pieces[1][col] = 1;
        game_board.pieces[6][col] = -1;
    }

    //rook setup
    game_board.pieces[0][0] = 2;
    game_board.pieces[0][7] = 2;
    game_board.pieces[7][0] = -2;
    game_board.pieces[7][7] = -2;

    //knight setup
    game_board.pieces[0][1] = 3;
    game_board.pieces[0][6] = 3;
    game_board.pieces[7][1] = -3;
    game_board.pieces[7][6] = -3;

    //bishop setup
    game_board.pieces[0][2] = 4;
    game_board.pieces[0][5] = 4;
    game_board.pieces[7][2] = -4;
    game_board.pieces[7][5] = -4;

    //queen setup
    game_board.pieces[0][3] = 5;
    game_board.pieces[7][3] = -5;

    //king setup
    game_board.pieces[0][4] = 6;
    game_board.pieces[7][4] = -6;

    int player_turn = 1;
    int depth = 4;

    int score = evaluate_board(game_board, player_turn);
    printf("Initial Score: %d", score);

    int best_move_val = -9999;
    int best_move_from_row = -1;
    int best_move_from_col = -1;
    int best_move_to_row = -1;
    int best_move_to_col = -1;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (game_board.pieces[i][j] == 0) continue;
            if (game_board.pieces[i][j] > 0 && player_turn == 1) {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (is_legal_move(game_board, i, j, k, l)) {
                            struct board new_board = game_board;
                            make_move(&new_board, i, j, k, l);
                            int move_value = minimax(new_board, depth, -10000, 10000, -1, 0);
                            if (move_value > best_move_val) {
                                best_move_val = move_value;
                                best_move_from_row = i;
                                best_move_from_col = j;
                                best_move_to_row = k;
                                best_move_to_col = l;
                            }
                        }
                    }
                }
            }
            else if (game_board.pieces[i][j] < 0 && player_turn == -1) {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (is_legal_move(game_board, i, j, k, l)) {
                            struct board new_board = game_board;
                            make_move(&new_board, i, j, k, l);
                            int move_value = minimax(new_board, depth, -10000, 10000, 1, 0);
                            if (move_value > best_move_val) {
                                best_move_val = move_value;
                                best_move_from_row = i;
                                best_move_from_col = j;
                                best_move_to_row = k;
                                best_move_to_col = l;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Best Move: %c%d to %c%d", best_move_from_col + 'a', 8 - best_move_from_row, best_move_to_col + 'a', 8 - best_move_to_row);

    return 0;
}

//evaluate board function
int evaluate_board(struct board game_board, int player) {
    int score = 0;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            int piece_value = get_piece_value(game_board.pieces[row][col], player == 1);
            score += piece_value;
        }
    }
    return score;
}

//minimax function
int minimax(struct board game_board, int depth, int alpha, int beta, int player, int is_maximizing) {
    if (depth == 0) {
        return -1 * evaluate_board(game_board, player);
    }

    if (is_maximizing) {
        int best_move_value = -9999;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (game_board.pieces[i][j] == 0) continue;
                if (game_board.pieces[i][j] > 0) {
                    for (int k = 0; k < 8; k++) {
                        for (int l = 0; l < 8; l++) {
                            if (is_legal_move(game_board, i, j, k, l)) {
                                struct board new_board = game_board;
                                make_move(&new_board, i, j, k, l);
                                int move_value = minimax(new_board, depth - 1, alpha, beta, player, 0);
                                if (move_value > best_move_value) {
                                    best_move_value = move_value;
                                }
                                alpha = alpha > best_move_value ? alpha : best_move_value;
                                if (beta <= alpha) break;
                            }
                        }
                    }
                }
            }
        }
        return best_move_value;
    }
    else {
        int best_move_value = 9999;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (game_board.pieces[i][j] == 0) continue;
                if (game_board.pieces[i][j] < 0) {
                    for (int k = 0; k < 8; k++) {
                        for (int l = 0; l < 8; l++) {
                            if (is_legal_move(game_board, i, j, k, l)) {
                                struct board new_board = game_board;
                                make_move(&new_board, i, j, k, l);
                                int move_value = minimax(new_board, depth - 1, alpha, beta, player, 1);
                                if (move_value < best_move_value) {
                                    best_move_value = move_value;
                                }
                                beta = beta < best_move_value ? beta : best_move_value;
                                if (beta <= alpha) break;
                            }
                        }
                    }
                }
            }
        }
        return best_move_value;
    }

}

//make move function
void make_move(struct board* game_board, int from_row, int from_col, int to_row, int to_col) {
    int piece = game_board->pieces[from_row][from_col];
    game_board->pieces[from_row][from_col] = -1;
    game_board->pieces[to_row][to_col] = piece;
}

//check if move is legal
int is_legal_move(struct board game_board, int from_row, int from_col, int to_row, int to_col) {
    if (game_board.pieces[to_row][to_col] * game_board.pieces[from_row][from_col] > 0) return 0; //same color pieces
    if (game_board.pieces[from_row][from_col] == 0) return 0; //no piece to move
    if (to_row < 0 || to_row > 7 || to_col < 0 || to_col > 7) return 0; //invalid square
    int piece = game_board.pieces[from_row][from_col];
    switch (abs(piece)) {
        case 1: //pawn
            if (piece > 0) { //white pawn
                if (from_col == to_col && game_board.pieces[to_row][to_col] == 0 && to_row == from_row - 1) return 1; //move forward 1
                if (from_col == to_col && game_board.pieces[to_row - 1][to_col] == 0 && game_board.pieces[to_row][to_col] == 0 && from_row == 6 && to_row == 4) return 1; //move forward 2
                if (abs(from_col - to_col) == 1 && to_row == from_row - 1 && game_board.pieces[to_row][to_col] < 0) return 1; //capture
            }
            else { //black pawn
                if (from_col == to_col && game_board.pieces[to_row][to_col] == 0 && to_row == from_row + 1) return 1; //move forward 1
                if (from_col == to_col && game_board.pieces[to_row + 1][to_col] == 0 && game_board.pieces[to_row][to_col] == 0 && from_row == 1 && to_row == 3) return 1; //move forward 2
                if (abs(from_col - to_col) == 1 && to_row == from_row + 1 && game_board.pieces[to_row][to_col] > 0) return 1; //capture
            }
            break;
        case 2: //rook
            if (to_row != from_row && to_col != from_col) return 0; //can only move along rank or file
            int between_squares;
            if (to_row == from_row) { //moving along rank
                between_squares = abs(to_col - from_col) - 1;
                int col_direction = to_col < from_col ? -1 : 1;
                for (int i = 0; i < between_squares; i++) {
                    if (game_board.pieces[from_row][from_col + col_direction * (i + 1)] != 0) return 0; //piece blocking path
                }
            }
            else { //moving along file
                between_squares = abs(to_row - from_row) - 1;
                int row_direction = to_row < from_row ? -1 : 1;
                for (int i = 0; i < between_squares; i++) {
                    if (game_board.pieces[from_row + row_direction * (i + 1)][from_col] != 0) return 0; //piece blocking path
                }
            }
            return 1;
            break;
        case 3: //knight
            if (abs(from_row - to_row) == 1 && abs(from_col - to_col) == 2) return 1;
            if (abs(from_row - to_row) == 2 && abs(from_col - to_col) == 1) return 1;
            return 0;
            break;
        case 4: //bishop
            if (abs(to_row - from_row) != abs(to_col - from_col)) return 0; //can only move along diagonal
            between_squares = abs(to_row - from_row) - 1;
            int row_direction = to_row < from_row ? -1 : 1;
            int col_direction = to_col < from_col ? -1 : 1;
            for (int i = 0; i < between_squares; i++) {
                if (game_board.pieces[from_row + row_direction * (i + 1)][from_col + col_direction * (i + 1)] != 0) return 0; //piece blocking path
            }
            return 1;
            break;
        case 5: //queen
            if (to_row != from_row && to_col != from_col) { //moving along diagonal
                if (abs(to_row - from_row) != abs(to_col - from_col)) return 0; //can only move along diagonal
                between_squares = abs(to_row - from_row) - 1;
                int row_direction = to_row < from_row ? -1 : 1;
                int col_direction = to_col < from_col ? -1 : 1;
                for (int i = 0; i < between_squares; i++) {
                    if (game_board.pieces[from_row + row_direction * (i + 1)][from_col + col_direction * (i + 1)] != 0) return 0; //piece blocking path
                }
                return 1;
            }
            else { //moving along rank or file
                if (to_row != from_row && to_col != from_col) return 0; //can only move along rank or file
                if (to_row == from_row) { //moving along rank
                    between_squares = abs(to_col - from_col) - 1;
                    int col_direction = to_col < from_col ? -1 : 1;
                    for (int i = 0; i < between_squares; i++) {
                        if (game_board.pieces[from_row][from_col + col_direction * (i + 1)] != 0) return 0; //piece blocking path
                    }
                }
                else { //moving along file
                    between_squares = abs(to_row - from_row) - 1;
                    int row_direction = to_row < from_row ? -1 : 1;
                    for (int i = 0; i < between_squares; i++) {
                        if (game_board.pieces[from_row + row_direction * (i + 1)][from_col] != 0) return 0; //piece blocking path
                    }
                }
                return 1;
            }
            break;
        case 6: //king
            if (abs(to_row - from_row) > 1 || abs(to_col - from_col) > 1) return 0; //moving more than 1 square away
            return 1;
            break;
    }
    return 0;
}

//get the value of a piece
int get_piece_value(int piece, int is_white) {
    if (piece == 1) return 10;
    if (piece == -1) return -10;
    if (piece == 2) return 50;
    if (piece == -2) return -50;
    if (piece == 3 || piece == -3) return 30;
    if (piece == 4 || piece == -4) return 30;
    if (piece == 5) return 90;
    if (piece == -5) return -90;
    if (piece == 6) return 900;
    if (piece == -6) return -900;
    return 0;
}