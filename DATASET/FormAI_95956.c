//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define NUM_PLAYERS 2

int player_turn = 0; // Player 0 goes first

struct Point {
    int x;
    int y;
};

struct Line {
    struct Point a;
    struct Point b;
};

void print_grid(int grid[][GRID_SIZE]) {
    printf("\n");
    printf("  ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(struct Line move, int grid[][GRID_SIZE]) {
    if (move.a.x < 0 || move.a.x >= GRID_SIZE ||
        move.a.y < 0 || move.a.y >= GRID_SIZE ||
        move.b.x < 0 || move.b.x >= GRID_SIZE ||
        move.b.y < 0 || move.b.y >= GRID_SIZE ||
        move.a.x != move.b.x && move.a.y != move.b.y ||
        move.a.x == move.b.x && abs(move.a.y - move.b.y) != 1 ||
        move.a.y == move.b.y && abs(move.a.x - move.b.x) != 1 ||
        grid[move.a.x][move.a.y] != -1 ||
        grid[move.b.x][move.b.y] != -1 ||
        move.a.x == move.b.x && move.a.y > move.b.y ||
        move.a.y == move.b.y && move.a.x > move.b.x) {
        return 0;
    }
    return 1;
}

int is_winner(int grid[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == -1) {
                return 0;
            }
        }
    }
    return 1;
}

void next_turn() {
    player_turn = (player_turn + 1) % NUM_PLAYERS;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = -1;
        }
    }
    
    srand(time(NULL));
    int start_player = rand() % 2;
    player_turn = start_player;
    printf("Player %d goes first.\n", player_turn);

    int num_moves = 0;
    while (!is_winner(grid)) {
        printf("Player %d's Turn\n", player_turn);
        struct Line move;
        printf("Enter Move:\n");
        scanf("%d %d %d %d", &move.a.x, &move.a.y, &move.b.x, &move.b.y);
        if (is_valid_move(move, grid)) {
            grid[move.a.x][move.a.y] = player_turn;
            grid[move.b.x][move.b.y] = player_turn;
            num_moves++;
            print_grid(grid);
            next_turn();
        } else {
            printf("Invalid Move. Try Again.\n");
        }
    }
    printf("Player %d wins in %d moves!\n", (player_turn + NUM_PLAYERS - 1) % NUM_PLAYERS, num_moves);

    return 0;
}