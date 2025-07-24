//FormAI DATASET v1.0 Category: Chess AI ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define BOARD_SIZE 8

// struct for a chess piece
typedef struct {
    char piece_type; // 'K': King, 'Q': Queen, 'R': Rook, 'B': Bishop, 'N': Knight, 'P': Pawn
    int x; // x-coordinate on the board
    int y; // y-coordinate on the board
} piece_t;

// enum for the color of a chess piece
typedef enum { WHITE, BLACK } color_t;

// struct for the chess game
typedef struct {
    piece_t board[BOARD_SIZE][BOARD_SIZE];
    color_t current_turn; // current turn, either WHITE or BLACK
    bool white_can_castle_kingside; // true if white can still castle kingside, false otherwise
    bool white_can_castle_queenside; // true if white can still castle queenside, false otherwise
    bool black_can_castle_kingside; // true if black can still castle kingside, false otherwise
    bool black_can_castle_queenside; // true if black can still castle queenside, false otherwise
} chess_game_t;

// function to initialize the board with pieces
void initialize_board(chess_game_t* game) {
    // initialize pieces for white
    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[1][i] = (piece_t){'P', i, 1};
    }
    game->board[0][0] = (piece_t){'R', 0, 0};
    game->board[0][1] = (piece_t){'N', 1, 0};
    game->board[0][2] = (piece_t){'B', 2, 0};
    game->board[0][3] = (piece_t){'Q', 3, 0};
    game->board[0][4] = (piece_t){'K', 4, 0};
    game->board[0][5] = (piece_t){'B', 5, 0};
    game->board[0][6] = (piece_t){'N', 6, 0};
    game->board[0][7] = (piece_t){'R', 7, 0};

    // initialize pieces for black
    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[6][i] = (piece_t){'P', i, 6};
    }
    game->board[7][0] = (piece_t){'R', 0, 7};
    game->board[7][1] = (piece_t){'N', 1, 7};
    game->board[7][2] = (piece_t){'B', 2, 7};
    game->board[7][3] = (piece_t){'Q', 3, 7};
    game->board[7][4] = (piece_t){'K', 4, 7};
    game->board[7][5] = (piece_t){'B', 5, 7};
    game->board[7][6] = (piece_t){'N', 6, 7};
    game->board[7][7] = (piece_t){'R', 7, 7};

    // set other initial values
    game->current_turn = WHITE;
    game->white_can_castle_kingside = true;
    game->white_can_castle_queenside = true;
    game->black_can_castle_kingside = true;
    game->black_can_castle_queenside = true;
}

// function to print the board to the console
void print_board(chess_game_t* game) {
    printf("+--A---B---C---D---E---F---G---H--+\n");
    for (int y = 0; y < BOARD_SIZE; y++) {
        printf("|");
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (game->board[y][x].piece_type == '\0') {
                printf("    ");
            } else {
                printf(" %c%c ", toupper(game->board[y][x].piece_type), (game->board[y][x].piece_type == 'P' ? ' ' : game->current_turn == WHITE ? 'w' : 'b'));
            }
            printf("|");
        }
        printf(" %d\n", BOARD_SIZE - y);
    }
    printf("+--A---B---C---D---E---F---G---H--+\n");
}

// function to check if a move is valid
bool is_valid_move(chess_game_t* game, piece_t piece, int new_x, int new_y) {
    // check if new coordinates are within bounds
    if (new_x < 0 || new_x >= BOARD_SIZE || new_y < 0 || new_y >= BOARD_SIZE) {
        return false;
    }

    // check if piece is actually on the board
    if (game->board[piece.y][piece.x].piece_type != piece.piece_type) {
        return false;
    }

    // check if there is a piece of the same color in the new location
    if (game->board[new_y][new_x].piece_type != '\0' && (game->board[new_y][new_x].piece_type != 'K' && piece.piece_type != 'K') && (game->board[new_y][new_x].piece_type != 'p' && game->board[new_y][new_x].piece_type != 'P') && ((game->board[new_y][new_x].piece_type >= 'a' && piece.piece_type >= 'a') || (game->board[new_y][new_x].piece_type < 'a' && piece.piece_type < 'a'))) {
        return false;
    }

    // check if the piece type can move to the new location
    switch (piece.piece_type) {
        case 'K': // King
            // check if move is only 1 square in any direction
            if (abs(new_x - piece.x) > 1 || abs(new_y - piece.y) > 1) {
                return false;
            }
            break;
        case 'Q': // Queen
            // check if move is horizontal, vertical or diagonal
            if (new_x != piece.x && new_y != piece.y && abs(new_x - piece.x) != abs(new_y - piece.y)) {
                return false;
            }
            break;
        case 'R': // Rook
            // check if move is either horizontal or vertical
            if (new_x != piece.x && new_y != piece.y) {
                return false;
            }
            break;
        case 'B': // Bishop
            // check if move is diagonal
            if (abs(new_x - piece.x) != abs(new_y - piece.y)) {
                return false;
            }
            break;
        case 'N': // Knight
            // check if move is L-shaped
            if (abs(new_x - piece.x) != 1 || abs(new_y - piece.y) != 2) {
                if (abs(new_x - piece.x) != 2 || abs(new_y - piece.y) != 1) {
                    return false;
                }
            }
            break;
        case 'P': // Pawn
            // check if move is valid for the pawn
            if (piece.x == new_x) { // moving forward
                if (game->board[new_y][new_x].piece_type != '\0') { // can't move into a non-empty square
                    return false;
                } else if (piece.piece_type == 'P' && new_y <= piece.y) { // white pawn can't move backwards
                    return false;
                } else if (piece.piece_type == 'p' && new_y >= piece.y) { // black pawn can't move backwards
                    return false;
                } else if (abs(new_y - piece.y) > 2) { // can't move more than 2 squares forward
                    return false;
                } else if (abs(new_y - piece.y) == 2 && (piece.y != 1 && piece.y != 6)) { // can only move 2 squares on first move
                    return false;
                } else if (abs(new_y - piece.y) == 2 && game->board[(new_y + piece.y) / 2][new_x].piece_type != '\0') { // can only move 2 squares if no pieces are blocking the path
                    return false;
                }
            } else { // capturing
                if (game->board[new_y][new_x].piece_type == '\0') { // can't capture an empty square
                    return false;
                } else if (piece.piece_type == 'P' && (new_y <= piece.y || abs(new_x - piece.x) != 1 || new_y - piece.y != 1)) { // white pawn can only capture diagonally and only one square forward
                    return false;
                } else if (piece.piece_type == 'p' && (new_y >= piece.y || abs(new_x - piece.x) != 1 || piece.y - new_y != 1)) { // black pawn can only capture diagonally and only one square forward
                    return false;
                }
            }
            break;
    }

    return true;
}

// function to move a piece on the board
void move_piece(chess_game_t* game, piece_t piece, int new_x, int new_y) {
    // update castling flags if necessary
    if (piece.piece_type == 'K') {
        if (game->current_turn == WHITE) {
            game->white_can_castle_kingside = false;
            game->white_can_castle_queenside = false;
        } else {
            game->black_can_castle_kingside = false;
            game->black_can_castle_queenside = false;
        }
    } else if (piece.piece_type == 'R') {
        if (piece.x == 0 && piece.y == 0) {
            game->white_can_castle_queenside = false;
        } else if (piece.x == 7 && piece.y == 0) {
            game->white_can_castle_kingside = false;
        } else if (piece.x == 0 && piece.y == 7) {
            game->black_can_castle_queenside = false;
        } else if (piece.x == 7 && piece.y == 7) {
            game->black_can_castle_kingside = false;
        }
    }

    // move the piece
    game->board[piece.y][piece.x] = (piece_t){'\0', piece.x, piece.y};
    game->board[new_y][new_x] = (piece_t){piece.piece_type, new_x, new_y};

    // update current turn
    game->current_turn = (game->current_turn == WHITE ? BLACK : WHITE);
}

// function to get a piece from its algebraic notation position, e.g. "e2"
piece_t get_piece_from_position(chess_game_t* game, char* position) {
    return game->board[BOARD_SIZE - (position[1] - '0')][position[0] - 'a'];
}

int main() {
    chess_game_t game;
    initialize_board(&game);

    // example game
    move_piece(&game, get_piece_from_position(&game, "e2"), 4, 4);
    print_board(&game);
    move_piece(&game, get_piece_from_position(&game, "e8"), 5, 5);
    print_board(&game);
    move_piece(&game, get_piece_from_position(&game, "d1"), 3, 3);
    print_board(&game);
    move_piece(&game, get_piece_from_position(&game, "f7"), 5, 4);
    print_board(&game);

    return 0;
}