//FormAI DATASET v1.0 Category: Chess engine ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int white_king_pos[2];
    int black_king_pos[2];
    bool white_castle_k;
    bool white_castle_q;
    bool black_castle_k;
    bool black_castle_q;
    bool white_to_move;
} Game;

void init_game(Game* game) {
    // Initialize board with pieces in starting position
    char starting_board[BOARD_SIZE][BOARD_SIZE] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                                                   {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                                                   {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                                                   {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                                                   {' ', '.', ' ', '.', ' ', '.', ' ', ' '},
                                                   {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                                                   {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                                                   {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};
    memcpy(game->board, starting_board, sizeof(starting_board));
    // Set king positions
    game->white_king_pos[0] = 7;
    game->white_king_pos[1] = 4;
    game->black_king_pos[0] = 0;
    game->black_king_pos[1] = 4;
    // Set castling flags
    game->white_castle_k = true;
    game->white_castle_q = true;
    game->black_castle_k = true;
    game->black_castle_q = true;
    // White to move first
    game->white_to_move = true;
}

void print_board(char board[][BOARD_SIZE]) {
    printf("  +-----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d | ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  +-----------------+\n");
    printf("    a b c d e f g h  \n");
}

void move_piece(Game* game, int from_row, int from_col, int to_row, int to_col) {
    // Move piece from "from" square to "to" square
    game->board[to_row][to_col] = game->board[from_row][from_col];
    game->board[from_row][from_col] = ' ';
    // Keep track of king position if a king is moving
    if (game->board[to_row][to_col] == 'K') {
        game->white_king_pos[0] = to_row;
        game->white_king_pos[1] = to_col;
        // Update castling flags if king moves
        game->white_castle_k = false;
        game->white_castle_q = false;
    } else if (game->board[to_row][to_col] == 'k') {
        game->black_king_pos[0] = to_row;
        game->black_king_pos[1] = to_col;
        // Update castling flags if king moves
        game->black_castle_k = false;
        game->black_castle_q = false;
    }
}

bool is_valid_move(Game* game, int from_row, int from_col, int to_row, int to_col) {
    // Check boundaries
    if (from_row < 0 || from_row >= BOARD_SIZE || from_col < 0 || from_col >= BOARD_SIZE ||
        to_row < 0 || to_row >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE) {
        return false;
    }
    // Check player turn
    if ((game->white_to_move && islower(game->board[from_row][from_col])) ||
        (!game->white_to_move && isupper(game->board[from_row][from_col]))) {
        return false;
    }
    // Check if move puts own king in check
    Game temp_game = *game;  // Create copy of game to make hypothetical move
    move_piece(&temp_game, from_row, from_col, to_row, to_col);
    // TODO: Implement check and checkmate detection
    // TODO: Implement legal move generation
    return true;
}

void play_turn(Game* game) {
    printf("Enter move: ");
    char move[5];
    scanf("%s", move);
    int from_col = move[0] - 'a';
    int from_row = BOARD_SIZE - (move[1] - '0');
    int to_col = move[2] - 'a';
    int to_row = BOARD_SIZE - (move[3] - '0');
    if (is_valid_move(game, from_row, from_col, to_row, to_col)) {
        move_piece(game, from_row, from_col, to_row, to_col);
        // TODO: Implement promotion if pawn reaches last row
        // TODO: Implement en passant capture
        game->white_to_move = !game->white_to_move;
    } else {
        printf("Invalid move.\n");
    }
}

int main() {
    Game game;
    init_game(&game);
    while (true) {
        print_board(game.board);
        if (game.white_to_move) {
            printf("White's turn.\n");
        } else {
            printf("Black's turn.\n");
        }
        play_turn(&game);
    }
    return 0;
}