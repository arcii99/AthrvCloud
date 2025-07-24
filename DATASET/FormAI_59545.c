//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define BOMB_COUNT 10
#define UNCOVERED 1
#define COVERED 0
#define FLAGGED 2

int board[GRID_SIZE][GRID_SIZE] = {0};
int revealed[GRID_SIZE][GRID_SIZE] = {0};
int flags[GRID_SIZE][GRID_SIZE] = {0};
int remaining_covered = GRID_SIZE * GRID_SIZE - BOMB_COUNT;

void generate_board() {
    int bomb_count = BOMB_COUNT;
    while (bomb_count > 0) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (board[x][y] == 0) {
            board[x][y] = -1;
            bomb_count--;
        }
    }
}

void print_board() {
    printf("Board:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i][j] == UNCOVERED) {
                printf("%d\t", board[i][j]);
            } else if (flags[i][j] == FLAGGED) {
                printf("F\t");
            } else {
                printf(".\t");
            }
        }
        printf("\n");
    }
}

int is_valid(int x, int y) {
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
        return 0;
    }
    return 1;
}

void flood_fill(int x, int y) {
    if (!is_valid(x, y)) {
        return;
    }
    if (revealed[x][y] == UNCOVERED) {
        return;
    }
    remaining_covered--;
    revealed[x][y] = UNCOVERED;
    if (board[x][y] == 0) {
        flood_fill(x - 1, y - 1);
        flood_fill(x - 1, y);
        flood_fill(x - 1, y + 1);
        flood_fill(x, y - 1);
        flood_fill(x, y + 1);
        flood_fill(x + 1, y - 1);
        flood_fill(x + 1, y);
        flood_fill(x + 1, y + 1);
    }
}

void reveal(int x, int y) {
    if (!is_valid(x, y)) {
        return;
    }
    if (revealed[x][y] == UNCOVERED) {
        return;
    }
    if (flags[x][y] == FLAGGED) {
        return;
    }
    if (board[x][y] == -1) {
        printf("Game over!\n");
        exit(0);
    } else if (board[x][y] == 0) {
        flood_fill(x, y);
    } else {
        revealed[x][y] = UNCOVERED;
        remaining_covered--;
    }
}

void flag(int x, int y) {
    if (!is_valid(x, y)) {
        return;
    }
    if (revealed[x][y] == UNCOVERED) {
        return;
    }
    if (flags[x][y] == COVERED) {
        flags[x][y] = FLAGGED;
    } else if (flags[x][y] == FLAGGED) {
        flags[x][y] = COVERED;
    }
}

int is_win() {
    if (remaining_covered == BOMB_COUNT) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    generate_board();

    while (1) {
        print_board();

        int x, y;
        printf("Enter coordinates (x y): ");
        scanf("%d %d", &x, &y);

        char action;
        printf("Enter action (r for reveal, f for flag): ");
        scanf(" %c", &action);

        if (action == 'r') {
            reveal(x, y);
        } else if (action == 'f') {
            flag(x, y);
        }

        if (is_win()) {
            printf("You win!\n");
            exit(0);
        }
    }

    return 0;
}