//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 50

typedef struct Player {
    int x;
    int y;
    int health;
} Player;

typedef enum CellType {
    FLOOR,
    WALL
} CellType;

int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void print_map(CellType map[HEIGHT][WIDTH], Player player) {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == player.y && j == player.x) {
                printf("@");
            } else if (map[i][j] == FLOOR) {
                printf(".");
            } else if (map[i][j] == WALL) {
                printf("#");
            }
        }
        printf("\n");
    }
}

void generate_map(CellType map[HEIGHT][WIDTH]) {
    srand(time(NULL));
    int i, j, r;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            r = rand_range(0, 100);
            if (r < 40) {
                map[i][j] = FLOOR;
            } else {
                map[i][j] = WALL;
            }
        }
    }
}

int move_player(CellType map[HEIGHT][WIDTH], Player *player, int dx, int dy) {
    int new_x = player->x + dx;
    int new_y = player->y + dy;
    if (new_x < 0 || new_y < 0 || new_x >= WIDTH || new_y >= HEIGHT) {
        return 0;
    }
    if (map[new_y][new_x] == WALL) {
        return 0;
    }
    player->x = new_x;
    player->y = new_y;
    return 1;
}

int main() {
    CellType map[HEIGHT][WIDTH];
    generate_map(map);
    Player player = {5, 5, 100};
    while (1) {
        print_map(map, player);
        printf("Health: %d\n", player.health);
        char input = getchar();
        if (input == 'q') {
            break;
        }
        if (input == 'w') {
            move_player(map, &player, 0, -1);
        }
        if (input == 'a') {
            move_player(map, &player, -1, 0);
        }
        if (input == 's') {
            move_player(map, &player, 0, 1);
        }
        if (input == 'd') {
            move_player(map, &player, 1, 0);
        }
    }
    return 0;
}