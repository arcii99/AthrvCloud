//FormAI DATASET v1.0 Category: Checkers Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum {EMPTY, BLACK, WHITE} piece;
typedef enum {NO_WINNER, BLACK_WIN, WHITE_WIN} winner;

piece board[BOARD_SIZE][BOARD_SIZE];
piece cur_player = BLACK;

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = BLACK;
                } else if (i > 4) {
                    board[i][j] = WHITE;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void print_board() {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j] == EMPTY ? '-' : board[i][j] == BLACK ? 'B' : 'W');
        }
        printf("%d\n", i + 1);
    }
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
}

// Returns true if the coordinate is valid and the cell is empty
int is_valid_move(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == EMPTY;
}

// Returns true if the player can jump the opponent's piece
int can_jump(int x, int y, int dx, int dy) {
    int opponent_player = cur_player == BLACK ? WHITE : BLACK;
    return x + 2 * dx >= 0 && x + 2 * dx < BOARD_SIZE && y + 2 * dy >= 0 && y + 2 * dy < BOARD_SIZE && board[x + dx][y + dy] == opponent_player && board[x + 2 * dx][y + 2 * dy] == EMPTY;
}

// Returns true if the player can do a legal move
int can_move(int x, int y) {
    int can_move_forward = cur_player == BLACK ? x < BOARD_SIZE - 1 : x > 0;
    int can_move_backward = cur_player == BLACK ? x > 0 : x < BOARD_SIZE - 1;
    int can_jump_left = can_jump(x, y, 1, -1) || can_jump(x, y, -1, -1);
    int can_jump_right = can_jump(x, y, 1, 1) || can_jump(x, y, -1, 1);
    int can_move_left = can_move_forward && (y > 0 && board[x + (cur_player == BLACK ? 1 : -1)][y - 1] == EMPTY) && (!can_jump_left);
    int can_move_right = can_move_forward && (y < BOARD_SIZE - 1 && board[x + (cur_player == BLACK ? 1 : -1)][y + 1] == EMPTY) && (!can_jump_right);
    return can_move_left || can_move_right || can_jump_left || can_jump_right;
}

// Returns true if the player can jump any opponent's piece
int can_jump_anywhere() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == cur_player) {
                if (can_jump(i, j, 1, -1) || can_jump(i, j, 1, 1) || can_jump(i, j, -1, -1) || can_jump(i, j, -1, 1)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Switches to the other player
void switch_player() {
    cur_player = cur_player == BLACK ? WHITE : BLACK;
}

// Returns true if the player wins the game
int is_winner() {
    // Check if all opponent's pieces are captured
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == cur_player || board[i][j] == EMPTY) {
                continue;
            }
            if (can_move(i, j)) {
                return 0;
            }
        }
    }
    // If the opponent cannot move, the player wins
    return 1;
}

// Returns the winner of the game
winner get_winner() {
    if (is_winner()) {
        return cur_player == BLACK ? BLACK_WIN : WHITE_WIN;
    }
    return NO_WINNER;
}

// Makes a move
void make_move(int x, int y, int dx, int dy) {
    piece p = board[x][y];
    board[x][y] = EMPTY;
    if (x + 2 * dx >= 0 && x + 2 * dx < BOARD_SIZE && y + 2 * dy >= 0 && y + 2 * dy < BOARD_SIZE && board[x + dx][y + dy] == (cur_player == BLACK ? WHITE : BLACK)) {
        board[x + dx][y + dy] = EMPTY;
    }
    board[x + 2 * dx][y + 2 * dy] = p;
    if (cur_player == BLACK ? x + 2 * dx == BOARD_SIZE - 1 : x + 2 * dx == 0) {
        board[x + 2 * dx][y + 2 * dy] = cur_player == BLACK ? 'K' : 'W';
    }
}

void play_game() {
    while (get_winner() == NO_WINNER) {
        print_board();
        if (!can_jump_anywhere()) {
            printf("Player %c, please enter the coordinates of the piece you want to move (in the format A1): ", cur_player == BLACK ? 'B' : 'W');
            int x, y;
            char col;
            scanf("%c%d", &col, &x);
            getchar();
            y = col - 'A';
            x--;
            if (!is_valid_move(x, y)) {
                printf("Invalid move! Please try again.\n");
                continue;
            }
            printf("Please enter the direction in which you want to move your piece (1 for forward-left, 2 for forward-right): ");
            int dir;
            scanf("%d", &dir);
            getchar();
            if ((cur_player == BLACK && dir == 2) || (cur_player == WHITE && dir == 1)) {
                printf("Invalid direction! Please try again.\n");
                continue;
            }
            int dx = cur_player == BLACK ? 1 : -1;
            int dy = dir == 1 ? -1 : 1;
            if (can_jump(x, y, dx, dy)) {
                printf("You can't move forward. You must capture the opponent's piece! Please try again.\n");
                continue;
            }
            make_move(x, y, dx, dy);
        } else {
            printf("Player %c, please enter the coordinates of the piece you want to move (in the format A1): ", cur_player == BLACK ? 'B' : 'W');
            int x, y;
            char col;
            scanf("%c%d", &col, &x);
            getchar();
            y = col - 'A';
            x--;
            if (!is_valid_move(x, y)) {
                printf("Invalid move! Please try again.\n");
                continue;
            }
            printf("Please enter the direction in which you want to move your piece (1 for forward-left, 2 for forward-right): ");
            int dir;
            scanf("%d", &dir);
            getchar();
            if ((cur_player == BLACK && dir == 2) || (cur_player == WHITE && dir == 1)) {
                printf("Invalid direction! Please try again.\n");
                continue;
            }
            int dx = cur_player == BLACK ? 1 : -1;
            int dy = dir == 1 ? -1 : 1;
            if (!can_jump(x, y, dx, dy)) {
                printf("You can't capture any opponent's piece! Please try again.\n");
                continue;
            }
            make_move(x, y, dx, dy);
        }
        switch_player();
    }
    printf("Player %c wins!", cur_player == BLACK ? 'B' : 'W');
}

int main() {
    initialize_board();
    play_game();
    return 0;
}