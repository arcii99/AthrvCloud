//FormAI DATASET v1.0 Category: Weather simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define MAX_PLAYERS 5

typedef struct Player {
    int id;
    int x_pos;
    int y_pos;
    int health;
} Player;

typedef struct Grid {
    int temperature[GRID_SIZE][GRID_SIZE];
    int humidity[GRID_SIZE][GRID_SIZE];
    int rainfall[GRID_SIZE][GRID_SIZE];
    int num_players;
    Player players[MAX_PLAYERS];
} Grid;

void init_grid(Grid* grid) {
    srand(time(NULL));
    grid->num_players = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid->temperature[i][j] = rand() % 50;  // random temperature between 0-50 degrees Celsius
            grid->humidity[i][j] = rand() % 100;  // random humidity between 0-100%
            grid->rainfall[i][j] = rand() % 50;  // random rainfall between 0-50mm
        }
    }
}

void print_grid(Grid* grid) {
    printf("\t\tTemperature\tHumidity\tRainfall\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("[%d,%d]\t\t%d°C\t\t%d%%\t\t%dmm\n", i, j, grid->temperature[i][j], grid->humidity[i][j], grid->rainfall[i][j]);
        }
    }
}

void add_player(Grid* grid, int x, int y) {
    if (grid->num_players < MAX_PLAYERS) {
        Player new_player = { .id = grid->num_players, .x_pos = x, .y_pos = y, .health = 100 };
        grid->players[grid->num_players++] = new_player;
        printf("Player %d added to grid.\n", new_player.id);
    }
}

void move_player(Grid* grid, int player_id, int x, int y) {
    if (player_id >= 0 && player_id < grid->num_players) {
        Player* player = &grid->players[player_id];
        if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
            player->x_pos = x;
            player->y_pos = y;
            printf("Player %d moved to [%d,%d].\n", player->id, player->x_pos, player->y_pos);
        } else {
            printf("Invalid position.\n");
        }
    } else {
        printf("Player not found.\n");
    }
}

int main() {
    Grid grid;
    init_grid(&grid);
    print_grid(&grid);

    add_player(&grid, 3, 4);
    add_player(&grid, 5, 6);
    add_player(&grid, 7, 8);

    move_player(&grid, 0, 5, 5);
    move_player(&grid, 2, 8, 8);
    move_player(&grid, 5, 2, 2);

    return 0;
}