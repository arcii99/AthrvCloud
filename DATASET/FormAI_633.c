//FormAI DATASET v1.0 Category: Checkers Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define PIECE_COUNT 12

char board[BOARD_SIZE][BOARD_SIZE];

typedef struct {
    int x;
    int y;
    bool is_crowned;
} piece_t;

piece_t pieces[PIECE_COUNT];

// Initialize the board and the pieces
void init_board() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if ((i + j) % 2 == 0 && (i < 3 || i > 4)) {
                board[i][j] = 'O';
                if (i < 3) {
                    pieces[(i * BOARD_SIZE + j) / 2].x = i;
                    pieces[(i * BOARD_SIZE + j) / 2].y = j;
                    pieces[(i * BOARD_SIZE + j) / 2].is_crowned = false;
                } else if (i > 4) {
                    pieces[((BOARD_SIZE - i) * BOARD_SIZE + j) / 2 + (BOARD_SIZE - PIECE_COUNT / 2)].x = i;
                    pieces[((BOARD_SIZE - i) * BOARD_SIZE + j) / 2 + (BOARD_SIZE - PIECE_COUNT / 2)].y = j;
                    pieces[((BOARD_SIZE - i) * BOARD_SIZE + j) / 2 + (BOARD_SIZE - PIECE_COUNT / 2)].is_crowned = false;
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Print the board and the pieces
void print_board() {
    printf("  ");
    for (int j = 0; j < BOARD_SIZE; ++j) {
        printf("%c ", 'A' + j);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("%d", i + 1);
        printf("\n");
    }
    printf("  ");
    for (int j = 0; j < BOARD_SIZE; ++j) {
        printf("%c ", 'A' + j);
    }
    printf("\n");
}

// Check if the move is valid
bool is_valid_move(int from_x, int from_y, int to_x, int to_y, bool is_crowning) {
    if (from_x < 0 || from_x >= BOARD_SIZE || from_y < 0 || from_y >= BOARD_SIZE ||
        to_x < 0 || to_x >= BOARD_SIZE || to_y < 0 || to_y >= BOARD_SIZE) {
        return false;
    }
    if (board[to_x][to_y] != ' ') {
        return false;
    }
    if (pieces[from_x * BOARD_SIZE + from_y].is_crowned || is_crowning) {
        // Crowned piece can move in any direction
        if (abs(to_x - from_x) == 1 && abs(to_y - from_y) == 1) {
            return true;
        }
        // Check for jump over another piece
        int dir_x = to_x > from_x ? 1 : -1;
        int dir_y = to_y > from_y ? 1 : -1;
        int x = from_x + dir_x;
        int y = from_y + dir_y;
        while (x != to_x && y != to_y) {
            if (board[x][y] != ' ' ||
                (!pieces[x * BOARD_SIZE + y].is_crowned && pieces[x * BOARD_SIZE + y].x != from_x)) {
                return false;
            }
            x += dir_x;
            y += dir_y;
        }
        if (board[x][y] == ' ') {
            return false;
        }
        return true;
    } else {
        // Regular piece can only move forward
        if ((to_x - from_x) == -1 && abs(to_y - from_y) == 1) {
            return true;
        }
        // Check for jump over another piece
        int dir_y = to_y > from_y ? 1 : -1;
        int x = from_x - 1;
        int y = from_y + dir_y;
        while (x != to_x && y != to_y) {
            if (board[x][y] != ' ' || (!pieces[x * BOARD_SIZE + y].is_crowned && pieces[x * BOARD_SIZE + y].x != from_x - 1)) {
                return false;
            }
            x -= 1;
            y += dir_y;
        }
        if (board[x][y] == ' ') {
            return false;
        }
        return true;
    }
}

// Move a piece from (from_x, from_y) to (to_x, to_y)
bool move_piece(int from_x, int from_y, int to_x, int to_y) {
    bool is_crowning = false;
    if (to_x == 0 && !pieces[from_x * BOARD_SIZE + from_y].is_crowned) {
        pieces[from_x * BOARD_SIZE + from_y].is_crowned = true;
        board[from_x][from_y] = 'X';
        is_crowning = true;
    }
    if (is_valid_move(from_x, from_y, to_x, to_y, is_crowning)) {
        if (to_x == 0 && !pieces[from_x * BOARD_SIZE + from_y].is_crowned) {
            pieces[from_x * BOARD_SIZE + from_y].is_crowned = true;
            board[from_x][from_y] = 'X';
            is_crowning = true;
        }
        board[from_x][from_y] = ' ';
        board[to_x][to_y] = pieces[from_x * BOARD_SIZE + from_y].is_crowned ? 'X' : 'O';
        pieces[from_x * BOARD_SIZE + from_y].x = to_x;
        pieces[from_x * BOARD_SIZE + from_y].y = to_y;
        return true;
    }
    return false;
}

// Check if any jumps are available for the current player
bool is_jump_available(int player) {
    for (int i = 0; i < PIECE_COUNT; ++i) {
        if ((pieces[i].x + pieces[i].y) % 2 == player) {
            if (pieces[i].is_crowned) {
                // Crowned piece can jump in any direction
                for (int j = -1; j <= 1; j += 2) {
                    for (int k = -1; k <= 1; k += 2) {
                        if (pieces[i].x + 2 * j >= 0 && pieces[i].x + 2 * j < BOARD_SIZE &&
                            pieces[i].y + 2 * k >= 0 && pieces[i].y + 2 * k < BOARD_SIZE &&
                            board[pieces[i].x + j][pieces[i].y + k] != ' ' &&
                            board[pieces[i].x + 2 * j][pieces[i].y + 2 * k] == ' ' &&
                            pieces[(pieces[i].x + j) * BOARD_SIZE + pieces[i].y + k].is_crowned != pieces[i].is_crowned) {
                            return true;
                        }
                    }
                }
            } else if (pieces[i].x == player) {
                // Regular piece can only jump forward
                for (int j = -1; j <= 1; j += 2) {
                    if (pieces[i].y + 2 * j >= 0 && pieces[i].y + 2 * j < BOARD_SIZE &&
                        board[pieces[i].x - 1][pieces[i].y + j] != ' ' &&
                        board[pieces[i].x - 2][pieces[i].y + 2 * j] == ' ' &&
                        pieces[(pieces[i].x - 1) * BOARD_SIZE + pieces[i].y + j].is_crowned != pieces[i].is_crowned) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int player = 0; // player 0 is O and player 1 is X
    init_board();
    print_board();
    while (true) {
        printf("Player %d turn!\n", player);
        int from_x, from_y, to_x, to_y;
        bool jump_available = is_jump_available(player);
        if (jump_available) {
            printf("Enter the coordinates of the piece you want to move (i.e. \"2A\"): ");
            scanf("%d%c", &from_x, &from_y);
            from_x--;
            from_y -= 'A';
            printf("Enter the coordinates of the cell you want to move to (i.e. \"3B\"): ");
            scanf("%d%c", &to_x, &to_y);
            to_x--;
            to_y -= 'A';
            if (move_piece(from_x, from_y, to_x, to_y)) {
                printf("%s jumps to %s.\n", "2A", "3B");
                if (is_jump_available(to_x)) {
                    printf("You can jump again!\n");
                } else {
                    player = (player + 1) % 2;
                }
            } else {
                printf("Invalid move!\n");
            }
        } else {
            printf("Enter the coordinates of the piece you want to move (i.e. \"2A\"): ");
            scanf("%d%c", &from_x, &from_y);
            from_x--;
            from_y -= 'A';
            printf("Enter the coordinates of the cell you want to move to (i.e. \"3B\"): ");
            scanf("%d%c", &to_x, &to_y);
            to_x--;
            to_y -= 'A';
            if (move_piece(from_x, from_y, to_x, to_y)) {
                if (to_x == 0 && pieces[from_x * BOARD_SIZE + from_y].is_crowned) {
                    printf("%s crowns to %s.\n", "2A", "3B");
                } else {
                    printf("%s moves to %s.\n", "2A", "3B");
                }
                player = (player + 1) % 2;
            } else {
                printf("Invalid move!\n");
            }
        }
        print_board();
    }
    return 0;
}