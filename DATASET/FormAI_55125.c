//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 10
#define COLS 10
#define TRAP_COUNT 10
#define PLAYER_ICON "O"
#define TRAP_ICON "X"
#define TREASURE_ICON "$"
#define EMPTY_ICON "."

int player_row, player_col;
int treasure_row, treasure_col;
int trap_row[TRAP_COUNT], trap_col[TRAP_COUNT];
char game_board[ROWS][COLS];

void initialize_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            game_board[i][j] = *EMPTY_ICON;
        }
    }
}

void print_instructions() {
    printf("Welcome to the treasure hunt game!\n");
    printf("Rules:\n");
    printf("1. You are the player: represented by %s.\n", PLAYER_ICON);
    printf("2. You need to collect the treasure: represented by %s.\n", TREASURE_ICON);
    printf("3. Avoid the traps: represented by %s.\n", TRAP_ICON);
    printf("4. The game board is a 10x10 grid.\n");
    printf("5. The player can move up, down, left, or right using the arrow keys.\n");
    printf("6. If the player lands on a trap, the game is over. If the player lands on the treasure, the player wins.\n\n");
}

void print_board() {
    printf("   ");
    for (int i = 0; i < COLS; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%2c ", game_board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void place_objects() {
    // place player randomly
    srand(time(NULL));
    player_row = rand() % ROWS;
    player_col = rand() % COLS;
    game_board[player_row][player_col] = *PLAYER_ICON;

    // place treasure randomly
    treasure_row = rand() % ROWS;
    treasure_col = rand() % COLS;
    game_board[treasure_row][treasure_col] = *TREASURE_ICON;

    // place traps randomly
    for (int i = 0; i < TRAP_COUNT; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (row == player_row && col == player_col) {
            i--;
        } else if (row == treasure_row && col == treasure_col) {
            i--;
        } else {
            trap_row[i] = row;
            trap_col[i] = col;
            game_board[row][col] = *TRAP_ICON;
        }
    }
}

int is_within_bounds(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

int move_player(int row, int col) {
    if (!is_within_bounds(row, col)) {
        return 0;
    }

    game_board[player_row][player_col] = *EMPTY_ICON;
    player_row = row;
    player_col = col;
    game_board[player_row][player_col] = *PLAYER_ICON;

    if (player_row == treasure_row && player_col == treasure_col) {
        return 1;
    }

    for (int i = 0; i < TRAP_COUNT; i++) {
        if (player_row == trap_row[i] && player_col == trap_col[i]) {
            return -1;
        }
    }

    return 0;
}

int main() {
    initialize_board();
    print_instructions();
    place_objects();
    int game_state = 0;

    while (game_state == 0) {
        print_board();
        printf("Enter a move (w = up, s = down, a = left, d = right):\n");
        char move = getchar();
        getchar();
        int new_row = player_row;
        int new_col = player_col;

        if (move == 'w') {
            new_row--;
        } else if (move == 's') {
            new_row++;
        } else if (move == 'a') {
            new_col--;
        } else if (move == 'd') {
            new_col++;
        } else {
            continue;
        }

        game_state = move_player(new_row, new_col);
    }

    if (game_state == 1) {
        printf("Congratulations! You found the treasure!\n");
    } else {
        printf("Game over! You stepped on a trap.\n");
    }

    return 0;
}