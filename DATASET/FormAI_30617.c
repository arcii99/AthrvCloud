//FormAI DATASET v1.0 Category: Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum tile_type {
    EMPTY,
    WALL,
    PLAYER,
    EXIT
};

struct game_state {
    enum tile_type tiles[10][10];
    int player_x;
    int player_y;
    int exit_x;
    int exit_y;
};

void print_game_state(struct game_state* game) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            switch (game->tiles[i][j]) {
                case EMPTY:
                    printf(" ");
                    break;
                case WALL:
                    printf("#");
                    break;
                case PLAYER:
                    printf("P");
                    break;
                case EXIT:
                    printf("E");
                    break;
            }
        }
        printf("\n");
    }
}

bool is_move_valid(struct game_state* game, int dx, int dy) {
    int new_x = game->player_x + dx;
    int new_y = game->player_y + dy;
    if (new_x < 0 || new_x > 9 || new_y < 0 || new_y > 9) {
        // Out of bounds
        return false;
    }
    if (game->tiles[new_y][new_x] == WALL) {
        // Wall in the way
        return false;
    }
    return true;
}

void move_player(struct game_state* game, int dx, int dy) {
    if (!is_move_valid(game, dx, dy)) {
        return;
    }

    game->tiles[game->player_y][game->player_x] = EMPTY;
    game->player_x += dx;
    game->player_y += dy;
    if (game->tiles[game->player_y][game->player_x] == EXIT) {
        printf("You win!\n");
        exit(0);
    }
    game->tiles[game->player_y][game->player_x] = PLAYER;
}

int main() {
    struct game_state game = {
        .tiles = {
            {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
            {WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
            {WALL, EMPTY, WALL, EMPTY, WALL, EMPTY, WALL, WALL, EMPTY, WALL},
            {WALL, EMPTY, WALL, EMPTY, WALL, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
            {WALL, EMPTY, WALL, EMPTY, WALL, WALL, WALL, EMPTY, WALL, WALL},
            {WALL, EMPTY, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
            {WALL, EMPTY, WALL, WALL, WALL, WALL, EMPTY, WALL, EMPTY, WALL},
            {WALL, EMPTY, EMPTY, EMPTY, EMPTY, WALL, EMPTY, WALL, EMPTY, WALL},
            {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, EMPTY, WALL},
            {WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
        },
        .player_x = 1,
        .player_y = 1,
        .exit_x = 8,
        .exit_y = 8
    };

    game.tiles[game.player_y][game.player_x] = PLAYER;
    game.tiles[game.exit_y][game.exit_x] = EXIT;

    while (true) {
        system("clear");
        printf("Use arrow keys to move player. Reach the exit (E) to win.\n");
        printf("#######################################################\n");
        print_game_state(&game);
        printf("#######################################################\n");

        char c = getchar();
        if (c == 27) { // escape character
            getchar(); // skip "["
            switch (getchar()) {
                case 'A': // up arrow
                    move_player(&game, 0, -1);
                    break;
                case 'B': // down arrow
                    move_player(&game, 0, 1);
                    break;
                case 'C': // right arrow
                    move_player(&game, 1, 0);
                    break;
                case 'D': // left arrow
                    move_player(&game, -1, 0);
                    break;
            }
        }
    }

    return 0;
}