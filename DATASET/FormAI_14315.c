//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

char map[HEIGHT][WIDTH];

typedef struct {
    int x, y;
} point_t;

typedef struct {
    point_t pos;
    int health, attack;
} player_t;

int randint(int min, int max) {
    static int initialized = 0;
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }
    return min + rand() % (max - min + 1);
}

point_t randpoint(void) {
    return (point_t){randint(1, WIDTH - 2), randint(1, HEIGHT - 2)};
}

void generate_map(void) {
    for (int x = 0; x < WIDTH; ++x) {
        map[0][x] = '#';
        map[HEIGHT - 1][x] = '#';
    }
    for (int y = 1; y < HEIGHT - 1; ++y) {
        map[y][0] = '#';
        map[y][WIDTH - 1] = '#';
        for (int x = 1; x < WIDTH - 1; ++x) {
            map[y][x] = '.';
        }
    }
    for (int i = 0; i < 20; ++i) {
        int x = randint(1, WIDTH - 2);
        int y = randint(1, HEIGHT - 2);
        map[y][x] = '#';
    }
}

void print_map(player_t player) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (x == player.pos.x && y == player.pos.y) {
                putchar('@');
            } else {
                putchar(map[y][x]);
            }
        }
        putchar('\n');
    }
}

player_t initialize_player(void) {
    player_t player = {
        .pos = randpoint(),
        .health = 20,
        .attack = 5,
    };
    return player;
}

int main(void) {
    generate_map();
    player_t player = initialize_player();
    while (player.health > 0) {
        print_map(player);
        int dx = 0, dy = 0;
        switch(getchar()) {
            case 'h': dx -= 1; break;
            case 'j': dy += 1; break;
            case 'k': dy -= 1; break;
            case 'l': dx += 1; break;
        }
        int x = player.pos.x + dx;
        int y = player.pos.y + dy;
        if (map[y][x] == '#') {
            continue;  // can't move there
        }
        player.pos.x = x;
        player.pos.y = y;
    }
    printf("You died!\n");
    return 0;
}