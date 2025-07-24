//FormAI DATASET v1.0 Category: Checkers Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 8
#define COLS 8

// The game board and its current state
char game_board[ROWS][COLS] = {
    {'-', 'B', '-', 'B', '-', 'B', '-', 'B'},
    {'B', '-', 'B', '-', 'B', '-', 'B', '-'},
    {'-', 'B', '-', 'B', '-', 'B', '-', 'B'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'W', '-', 'W', '-', 'W', '-', 'W', '-'},
    {'-', 'W', '-', 'W', '-', 'W', '-', 'W'},
    {'W', '-', 'W', '-', 'W', '-', 'W', '-'}
};

// The checker piece and its current position
typedef struct Checker {
    char symbol;
    int x;
    int y;
} Checker;

Checker player1 = {'B', 0, 0};
Checker player2 = {'W', 0, 0};

// Function to print the game board
void print_board() {
    printf("\n  A B C D E F G H\n");
    printf("  ----------------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", game_board[i][j]);
        }
        printf(" %d\n", i+1);
    }
    printf("  ----------------\n");
    printf("  A B C D E F G H\n\n");
}

// Function to check if a move is legal
bool is_move_legal(Checker player, int x, int y, bool is_jump) {
    // Check if move is out of bounds
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return false;
    }
    // Check if moving to a non-empty space
    if (game_board[x][y] != '-') {
        return false;
    }
    // Check if attempting a non-jump move when a jump move is available
    if (!is_jump && (game_board[player.x-1][player.y+1] == player2.symbol || game_board[player.x-1][player.y-1] == player2.symbol || game_board[player.x+1][player.y+1] == player2.symbol || game_board[player.x+1][player.y-1] == player2.symbol)) {
        return false;
    }
    // Check if non-king piece is moving backwards
    if (!is_jump && player.symbol == 'B' && x > player.x) {
        return false;
    }
    if (!is_jump && player.symbol == 'W' && x < player.x) {
        return false;
    }
    // Check if attempting a non-jump move when surrounded by enemies
    if (!is_jump && game_board[player.x-1][player.y+1] == player2.symbol && game_board[player.x-1][player.y-1] == player2.symbol && game_board[player.x+1][player.y+1] == player2.symbol && game_board[player.x+1][player.y-1] == player2.symbol) {
        return false;
    }
    // Check if attempting a jump move
    if (is_jump) {
        // Check if jump distance is valid
        int dx = x - player.x;
        int dy = y - player.y;
        int jumped_x = player.x + dx/2;
        int jumped_y = player.y + dy/2;
        if (dx*dx > 4 || dy*dy > 4 || (dx*dx == 4 && dy*dy == 4) || (dx*dx == 1 && dy*dy == 1)) {
            return false;
        }
        // Check if jumping over own piece
        if (player.symbol == 'B' && game_board[jumped_x][jumped_y] == 'B') {
            return false;
        }
        if (player.symbol == 'W' && game_board[jumped_x][jumped_y] == 'W') {
            return false;
        }
        // Check if there is an enemy to jump over
        if (game_board[jumped_x][jumped_y] != player2.symbol) {
            return false;
        }
    }
    return true;
}

// Function to check if a player has won
bool has_won(Checker player) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (game_board[i][j] == player.symbol || game_board[i][j] == toupper(player.symbol)) {
                if (is_move_legal(player, i+2, j+2, true) || is_move_legal(player, i-2, j+2, true) || is_move_legal(player, i+2, j-2, true) || is_move_legal(player, i-2, j-2, true)) {
                    return false;
                }
            }
        }
    }
    return true;
}

// Function to make a move
void make_move(Checker* player, int x, int y) {
    // Check if move is jump move
    bool is_jump = abs(x - player->x) == 2;
    // Move the piece
    game_board[x][y] = player->symbol;
    game_board[player->x][player->y] = '-';
    // Check if piece has become king
    if (player->symbol == 'B' && x == 7) {
        game_board[x][y] = 'b';
    }
    if (player->symbol == 'W' && x == 0) {
        game_board[x][y] = 'w';
    }
    // Check if piece has made a jump and can jump again
    if (is_jump && (is_move_legal(*player, x+2, y+2, true) || is_move_legal(*player, x-2, y+2, true) || is_move_legal(*player, x+2, y-2, true) || is_move_legal(*player, x-2, y-2, true))) {
        player->x = x;
        player->y = y;
        print_board();
        printf("You made a jump! You can jump again.\n");
        return;
    }
    // Check if player has won
    if (has_won(*player)) {
        print_board();
        printf("Congratulations! You have won the game.\n");
        exit(0);
    }
    // Switch players
    if (player->symbol == 'B') {
        player->symbol = 'W';
        player->x = player2.x;
        player->y = player2.y;
    }
    else {
        player->symbol = 'B';
        player->x = player1.x;
        player->y = player1.y;
    }
}

int main() {
    printf("Welcome to Checkers!\n");
    player1.x = 0;
    player1.y = 1;
    player2.symbol = 'W';
    player2.x = 7;
    player2.y = 0;
    print_board();
    while (true) {
        // Get player move
        Checker* player = (player1.symbol == 'B') ? &player1 : &player2;
        printf("%c Player, enter your move (from square to square): ", player->symbol);
        char move[5];
        scanf("%s", move);
        // Get move coordinates
        int from_x = move[1] - '1';
        int from_y = move[0] - 'A';
        int to_x = move[3] - '1';
        int to_y = move[2] - 'A';
        // Check if move is legal
        if (!is_move_legal(*player, to_x, to_y, abs(to_x - from_x) == 2)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        // Make the move
        make_move(player, to_x, to_y);
        // Print the board
        print_board();
    }
    return 0;
}