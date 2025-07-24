//FormAI DATASET v1.0 Category: Chess AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// defining the chess board structure
struct ChessBoard {
    int board[BOARD_SIZE][BOARD_SIZE];
};

// initialize the chess board with starting positions
void init_board(struct ChessBoard* chess_board) {
    int rows[] = {2, 7};
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i == 0 || i == 7) {
            int pieces[] = {1, 2, 3, 4, 5, 3, 2, 1};
            for (int j = 0; j < BOARD_SIZE; j++) {
                chess_board->board[i][j] = pieces[j];
            }
        }
        else if (i == rows[0] || i == rows[1]) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                chess_board->board[i][j] = 6;
            }
        }
        else {
            for (int j = 0; j < BOARD_SIZE; j++) {
                chess_board->board[i][j] = 0;
            }
        }
    }
}

// prints the chess board to console
void print_board(struct ChessBoard* chess_board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", chess_board->board[i][j]);
        }
        printf("\n");
    }
}

// check if a given square is within the board boundaries
bool is_within_boundaries(int x, int y) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

// check if a given move is valid for a given chess piece
bool is_valid_move(int piece, int x, int y, int dest_x, int dest_y, struct ChessBoard* chess_board) {
    if (piece == 1 || piece == 7) { // pawn
        if (chess_board->board[dest_x][dest_y] == 0) {
            // move forward
            if (y == dest_y) {
                if (piece == 1) {
                    if (x + 1 == dest_x) return true;
                    if (x == 1 && x + 2 == dest_x && chess_board->board[x+1][y] == 0) return true;
                }
                else {
                    if (x - 1 == dest_x) return true;
                    if (x == 6 && x - 2 == dest_x && chess_board->board[x-1][y] == 0) return true;
                }
            }
            // capture diagonally
            if (x + 1 == dest_x || x - 1 == dest_x) {
                if (y + 1 == dest_y || y - 1 == dest_y) {
                    if (chess_board->board[dest_x][dest_y] != 0) {
                        return true;
                    }
                }
            }
        }
    }
    else if (piece == 2 || piece == 8) { // knight
        int dx = abs(dest_x - x);
        int dy = abs(dest_y - y);
        if (dx + dy == 3 && dx != 0 && dy != 0 && is_within_boundaries(dest_x, dest_y)) {
            if (chess_board->board[dest_x][dest_y] == 0 || (chess_board->board[dest_x][dest_y] / 10) != (piece / 10)) {
                return true;
            }
        }
    }
    else if (piece == 3 || piece == 9) { // bishop
        int dx = abs(dest_x - x);
        int dy = abs(dest_y - y);
        if (dx == dy) {
            int inc_x = (dest_x - x > 0) ? 1 : -1;
            int inc_y = (dest_y - y > 0) ? 1 : -1;
            int i = x + inc_x;
            int j = y + inc_y;
            while (i != dest_x && j != dest_y) {
                if (chess_board->board[i][j] != 0) {
                    return false;
                }
                i += inc_x;
                j += inc_y;
            }
            if (chess_board->board[dest_x][dest_y] == 0 || (chess_board->board[dest_x][dest_y] / 10) != (piece / 10)) {
                return true;
            }
        }
    }
    else if (piece == 4 || piece == 10) { // rook
        int dx = abs(dest_x - x);
        int dy = abs(dest_y - y);
        if (dx == 0 || dy == 0) {
            int inc_x = (dest_x - x > 0) ? 1 : -1;
            int inc_y = (dest_y - y > 0) ? 1 : -1;
            if (dx == 0) {
                inc_x = 0;
            }
            if (dy == 0) {
                inc_y = 0;
            }
            int i = x + inc_x;
            int j = y + inc_y;
            while (i != dest_x || j != dest_y) {
                if (chess_board->board[i][j] != 0) {
                    return false;
                }
                i += inc_x;
                j += inc_y;
            }
            if (chess_board->board[dest_x][dest_y] == 0 || (chess_board->board[dest_x][dest_y] / 10) != (piece / 10)) {
                return true;
            }
        }
    }
    else if (piece == 5 || piece == 11) { // queen
        if (is_valid_move(piece = 4, x, y, dest_x, dest_y, chess_board) || is_valid_move(piece = 3, x, y, dest_x, dest_y, chess_board)) {
            return true;
        }
    }
    else if (piece == 6 || piece == 12) { // king
        int dx = abs(dest_x - x);
        int dy = abs(dest_y - y);
        if ((dx == 0 && dy == 1) || (dx == 1 && dy == 0) || (dx == 1 && dy == 1)) {
            if (chess_board->board[dest_x][dest_y] == 0 || (chess_board->board[dest_x][dest_y] / 10) != (piece / 10)) {
                return true;
            }
        }
    }
    return false;
}

// check if a given move puts the current player in check
bool is_in_check(struct ChessBoard* chess_board, int player_color) {
    // get king position
    int king_x = -1, king_y = -1;
    int king_piece = (player_color == 0) ? 6 : 12;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (chess_board->board[i][j] == king_piece) {
                king_x = i;
                king_y = j;
                break;
            }
        }
    }

    // check if any of the opponent's pieces can attack the king
    int opponent_color = (player_color == 0) ? 1 : 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int piece = chess_board->board[i][j];
            if (piece == 0) continue;
            if ((piece / 10) == opponent_color) {
                if (is_valid_move(piece, i, j, king_x, king_y, chess_board)) {
                    return true;
                }
            }
        }
    }

    return false;
}

// check if a given player has any legal moves left
bool has_legal_moves(struct ChessBoard* chess_board, int player_color) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int piece = chess_board->board[i][j];
            if (piece == 0) continue;
            if ((piece / 10) == player_color) {
                for (int k = 0; k < BOARD_SIZE; k++) {
                    for (int l = 0; l < BOARD_SIZE; l++) {
                        if (is_valid_move(piece, i, j, k, l, chess_board)) {
                            struct ChessBoard new_board = *chess_board;
                            new_board.board[k][l] = piece;
                            new_board.board[i][j] = 0;
                            if (!is_in_check(&new_board, player_color)) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

// make a move on the chess board
void make_move(int x, int y, int dest_x, int dest_y, struct ChessBoard* chess_board) {
    int piece = chess_board->board[x][y];
    if (is_valid_move(piece, x, y, dest_x, dest_y, chess_board)) {
        chess_board->board[dest_x][dest_y] = piece;
        chess_board->board[x][y] = 0;
    }
}

// main program loop
int main() {
    struct ChessBoard chess_board;
    init_board(&chess_board);
    print_board(&chess_board);
    int player_color = 0;
    while (true) {
        int x, y, dest_x, dest_y;
        printf("Player %d's turn. Enter move (x, y, dest_x, dest_y): ", player_color + 1);
        scanf("%d %d %d %d", &x, &y, &dest_x, &dest_y);
        if (is_within_boundaries(x, y) && is_within_boundaries(dest_x, dest_y)) {
            int piece = chess_board.board[x][y];
            if ((piece / 10) == player_color) {
                if (is_valid_move(piece, x, y, dest_x, dest_y, &chess_board)) {
                    struct ChessBoard new_board = chess_board;
                    make_move(x, y, dest_x, dest_y, &new_board);
                    if (!is_in_check(&new_board, player_color)) {
                        chess_board = new_board;
                        player_color = (player_color == 0) ? 1 : 0;
                        printf("Updated board:\n");
                        print_board(&chess_board);
                        if (!has_legal_moves(&chess_board, player_color)) {
                            printf("Player %d is in checkmate! Game over.", player_color + 1);
                            break;
                        }
                    }
                    else {
                        printf("Move puts player in check. Try again.\n");
                    }
                }
                else {
                    printf("Invalid move. Try again.\n");
                }
            }
            else {
                printf("Not player's piece. Try again.\n");
            }
        }
        else {
            printf("Invalid input. Try again.\n");
        }
    }
    return 0;
}