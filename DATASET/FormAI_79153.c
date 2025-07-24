//FormAI DATASET v1.0 Category: Chess engine ; Style: Linus Torvalds
/*
 * C Chess engine example program
 * Based on Linus Torvalds' coding style
 * Written by [Your Name]
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct {
    uint8_t row;
    uint8_t col;
} Position;

typedef struct {
    char piece;
    Position pos;
} Square;

typedef enum {
    WHITE,
    BLACK
} Player;

typedef struct {
    Square board[BOARD_SIZE][BOARD_SIZE];
    Player current_player;
} Game;

void init_board(Game *game)
{
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            game->board[row][col].piece = ' ';
            game->board[row][col].pos.row = row;
            game->board[row][col].pos.col = col;
        }
    }

    // White pieces
    game->board[0][0].piece = 'R';
    game->board[0][1].piece = 'N';
    game->board[0][2].piece = 'B';
    game->board[0][3].piece = 'Q';
    game->board[0][4].piece = 'K';
    game->board[0][5].piece = 'B';
    game->board[0][6].piece = 'N';
    game->board[0][7].piece = 'R';
    for (int col = 0; col < BOARD_SIZE; ++col)
        game->board[1][col].piece = 'P';

    // Black pieces
    game->board[7][0].piece = 'r';
    game->board[7][1].piece = 'n';
    game->board[7][2].piece = 'b';
    game->board[7][3].piece = 'q';
    game->board[7][4].piece = 'k';
    game->board[7][5].piece = 'b';
    game->board[7][6].piece = 'n';
    game->board[7][7].piece = 'r';
    for (int col = 0; col < BOARD_SIZE; ++col)
        game->board[6][col].piece = 'p';

    game->current_player = WHITE;
}

void print_board(const Game *game)
{
    printf("\n   A B C D E F G H\n");
    for (int row = 0; row < BOARD_SIZE; ++row) {
        printf("%d  ", row + 1);
        for (int col = 0; col < BOARD_SIZE; ++col) {
            printf("%c ", game->board[row][col].piece);
        }
        printf("%d", row + 1);
        printf("\n");
    }
    printf("   A B C D E F G H\n");
}

bool is_valid_move(const Game *game, const Position from, const Position to)
{
    const Square square_from = game->board[from.row][from.col];
    const Square square_to = game->board[to.row][to.col];

    if (square_from.piece == ' ')
        return false;

    if (square_from.pos.row == square_to.pos.row && square_from.pos.col == square_to.pos.col)
        return false;

    if (square_from.piece == 'P' || square_from.piece == 'p') {
        if (square_to.piece == ' ') {
            if (from.col == to.col && ((from.row == 1 && to.row == 3 && game->board[from.row + 1][from.col].piece == ' ') ||
                                       (from.row == 6 && to.row == 4 && game->board[from.row - 1][from.col].piece == ' ')))
                return true;
            else if (from.row + 1 == to.row && from.col == to.col && square_from.piece == 'P')
                return true;
            else if (from.row - 1 == to.row && from.col == to.col && square_from.piece == 'p')
                return true;
        } else {
            if (from.row + 1 == to.row && (from.col + 1 == to.col || from.col - 1 == to.col) && square_from.piece == 'P')
                return true;
            else if (from.row - 1 == to.row && (from.col + 1 == to.col || from.col - 1 == to.col) && square_from.piece == 'p')
                return true;
        }
    }

    // Add more rules for other pieces here....

    return false;
}

void make_move(Game *game, const Position from, const Position to)
{
    Square square_from = game->board[from.row][from.col];
    Square square_to = game->board[to.row][to.col];

    square_to.piece = square_from.piece;
    square_from.piece = ' ';

    game->current_player = game->current_player == WHITE ? BLACK : WHITE;

    // Add more stuff here...
}

int main(void)
{
    Game game;
    init_board(&game);
    print_board(&game);

    while (true) {
        printf("Enter move (e.g. e2e4): ");
        char move[5];
        scanf("%s", move);

        const Position from = { move[1] - '1', move[0] - 'a' };
        const Position to = { move[3] - '1', move[2] - 'a' };

        if (is_valid_move(&game, from, to)) {
            make_move(&game, from, to);
            print_board(&game);
        } else {
            printf("Invalid move!\n");
        }
    }

    return 0;
}