//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

typedef struct dungeon {
    char tiles[HEIGHT][WIDTH];
    int player_x, player_y;
} dungeon_t;

void init_dungeon(dungeon_t *dungeon);
void print_dungeon(dungeon_t *dungeon);
void generate_dungeon(dungeon_t *dungeon);

int main() {
    dungeon_t dungeon;
    init_dungeon(&dungeon);
    generate_dungeon(&dungeon);
    print_dungeon(&dungeon);
}

void init_dungeon(dungeon_t *dungeon) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            dungeon->tiles[i][j] = '#';
        }
    }

    dungeon->player_x = WIDTH / 2;
    dungeon->player_y = HEIGHT / 2;
}

void print_dungeon(dungeon_t *dungeon) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == dungeon->player_y && j == dungeon->player_x) {
                printf("@");
            } else {
                printf("%c", dungeon->tiles[i][j]);
            }
        }
        printf("\n");
    }
}

void generate_dungeon(dungeon_t *dungeon) {
    srand(time(NULL));

    for (int i = 2; i < HEIGHT - 2; i++) {
        for (int j = 2; j < WIDTH - 2; j++) {
            if (rand() % 100 < 50) {
                dungeon->tiles[i][j] = '.';
            }
        }
    }
}