//FormAI DATASET v1.0 Category: Checkers Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define WHITE_PIECE 'W'
#define BLACK_PIECE 'B'
#define EMPTY_SPACE ' '

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char turn;
} Game;

void initialize_board(Game* game) {
    // Initialize the board with pieces in their starting positions
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (row < 3 && ((row + col) % 2 == 0)) {
                game->board[row][col] = BLACK_PIECE;
            } else if (row > 4 && ((row + col) % 2 == 0)) {
                game->board[row][col] = WHITE_PIECE;
            } else {
                game->board[row][col] = EMPTY_SPACE;
            }
        }
    }

    // Black goes first
    game->turn = BLACK_PIECE;
}

void display_board(Game* game) {
    // Display the current state of the board
    printf("  0 1 2 3 4 5 6 7\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", game->board[row][col]);
        }
        printf("\n");
    }
}

bool is_valid_move(Game* game, int start_row, int start_col, int end_row, int end_col) {
    // Check if the move is valid for the current turn
    char piece = game->board[start_row][start_col];

    // Check that the start and end positions are within the board
    if (start_row < 0 || start_row >= BOARD_SIZE ||
        start_col < 0 || start_col >= BOARD_SIZE ||
        end_row < 0 || end_row >= BOARD_SIZE ||
        end_col < 0 || end_col >= BOARD_SIZE) {
        return false;
    }
    
    // Check that the end position is empty
    if (game->board[end_row][end_col] != EMPTY_SPACE) {
        return false;
    }

    // Check if the move is a regular one or a jump
    int row_difference = end_row - start_row;
    int col_difference = end_col - start_col;
    if (piece == WHITE_PIECE) {
        if (row_difference == 1 && abs(col_difference) == 1) {
            return true;
        } else if (row_difference == 2 && abs(col_difference) == 2 &&
                   game->board[start_row+row_difference/2][start_col+col_difference/2] == BLACK_PIECE) {
            return true;
        } else {
            return false;
        }
    } else { // Black piece
        if (row_difference == -1 && abs(col_difference) == 1) {
            return true;
        } else if (row_difference == -2 && abs(col_difference) == 2 &&
                   game->board[start_row+row_difference/2][start_col+col_difference/2] == WHITE_PIECE) {
            return true;
        } else {
            return false;
        }
    }
}

bool make_move(Game* game, int start_row, int start_col, int end_row, int end_col) {
    // Make a move on the board
    if (!is_valid_move(game, start_row, start_col, end_row, end_col)) {
        return false;
    }

    // Move the piece
    game->board[end_row][end_col] = game->board[start_row][start_col];
    game->board[start_row][start_col] = EMPTY_SPACE;

    // Check if the piece should be promoted to a king
    char piece = game->board[end_row][end_col];
    if (piece == WHITE_PIECE && end_row == BOARD_SIZE-1) {
        game->board[end_row][end_col] = 'W';
    } else if (piece == BLACK_PIECE && end_row == 0) {
        game->board[end_row][end_col] = 'B';
    }

    // If the move is a jump, remove the jumped piece from the board
    int row_difference = end_row - start_row;
    int col_difference = end_col - start_col;
    if (abs(row_difference) == 2 && abs(col_difference) == 2) {
        game->board[start_row+row_difference/2][start_col+col_difference/2] = EMPTY_SPACE;
    }

    // Switch to the other player's turn
    game->turn = (game->turn == BLACK_PIECE) ? WHITE_PIECE : BLACK_PIECE;

    return true;
}

bool game_over(Game* game) {
    // Returns true if the game is over (someone has won or there are no valid moves)
    char current_player = game->turn;
    bool has_valid_move = false;

    // Check if there are any valid moves for the current player
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (game->board[row][col] == current_player) {
                if (is_valid_move(game, row, col, row+1, col+1) ||
                    is_valid_move(game, row, col, row+1, col-1) ||
                    is_valid_move(game, row, col, row-1, col+1) ||
                    is_valid_move(game, row, col, row-1, col-1) ||
                    is_valid_move(game, row, col, row+2, col+2) ||
                    is_valid_move(game, row, col, row+2, col-2) ||
                    is_valid_move(game, row, col, row-2, col+2) ||
                    is_valid_move(game, row, col, row-2, col-2)) {
                    has_valid_move = true;
                }
            }
        }
    }

    if (!has_valid_move) {
        return true;
    }

    // Check if one player has no pieces left
    bool has_white_piece = false;
    bool has_black_piece = false;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (game->board[row][col] == WHITE_PIECE || game->board[row][col] == 'W') {
                has_white_piece = true;
            } else if (game->board[row][col] == BLACK_PIECE || game->board[row][col] == 'B') {
                has_black_piece = true;
            }
        }
    }

    if (!has_white_piece || !has_black_piece) {
        return true;
    }

    return false;
}

int main() {
    Game game;
    initialize_board(&game);

    while (!game_over(&game)) {
        // Display the board and prompt the current player for a move
        display_board(&game);
        printf("Current player: %c\n", game.turn);
        printf("Enter move (in the form 'start_row,start_col end_row,end_col'): ");

        // Parse the user's move input
        int start_row, start_col, end_row, end_col;
        scanf("%d,%d %d,%d", &start_row, &start_col, &end_row, &end_col);

        // Make the move and display an error message if it is invalid
        if (!make_move(&game, start_row, start_col, end_row, end_col)) {
            printf("Invalid move!\n");
        }
    }

    // Display the final state of the board and the winner (if any)
    display_board(&game);
    if (!game_over(&game)) {
        printf("Error: game ended prematurely!\n");
    } else if (!game.turn) {
        printf("Draw!\n");
    } else {
        printf("Winner: %c\n", game.turn);
    }

    return 0;
}