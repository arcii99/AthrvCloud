//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

struct Ship {
    int length;
    int row;
    int col;
    int direction; // 0 is horizontal, 1 is vertical
};

char board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    // Sets up the board with empty spaces and draws border
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if ((r == 0 || r == BOARD_SIZE - 1) || (c == 0 || c == BOARD_SIZE - 1)) {
                board[r][c] = '#';
            } else {
                board[r][c] = ' ';
            }
        }
    }
}

void print_board() {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int place_ship(struct Ship *s) {
    // Returns 1 if successful, 0 otherwise
    int l = s->length;
    int r = s->row;
    int c = s->col;
    int d = s->direction;

    if (d == 0) {
        if (c + l >= BOARD_SIZE) return 0; // Ship goes out of bounds

        for (int i = c; i < c + l; i++) {
            if (board[r][i] != ' ') return 0; // Space is already occupied
        }

        // Place the ship
        for (int i = c; i < c + l; i++) {
            board[r][i] = '#';
        }

    } else {
        if (r + l >= BOARD_SIZE) return 0; // Ship goes out of bounds

        for (int i = r; i < r + l; i++) {
            if (board[i][c] != ' ') return 0; // Space is already occupied
        }

        // Place the ship
        for (int i = r; i < r + l; i++) {
            board[i][c] = '#';
        }
    }

    return 1;
}

void place_all_ships() {
    struct Ship ships[5];
    ships[0].length = 5;
    ships[1].length = 4;
    ships[2].length = 3;
    ships[3].length = 3;
    ships[4].length = 2;

    // Initialize random seed
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        int dir = rand() % 2; // 0 is horizontal, 1 is vertical

        ships[i].row = row;
        ships[i].col = col;
        ships[i].direction = dir;

        if (place_ship(&ships[i]) == 0) {
            i--;
        }
    }
}

int main() {
    init_board();
    place_all_ships();
    print_board();

    return 0;
}