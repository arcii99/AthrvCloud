//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 30
#define HEIGHT 20

void init_map(char map[HEIGHT][WIDTH]);
void print_map(char map[HEIGHT][WIDTH]);
bool is_wall(char map[HEIGHT][WIDTH], int x, int y);
int count_adj_walls(char map[HEIGHT][WIDTH], int x, int y);

int main(void) {
    srand(time(NULL));
    char map[HEIGHT][WIDTH];

    init_map(map);
    print_map(map);

    return 0;
}

void init_map(char map[HEIGHT][WIDTH]) {
    // Fill map with walls
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            map[y][x] = '#';
        }
    }

    // Dig out random starting room
    int start_x = rand() % (WIDTH - 6) + 3;
    int start_y = rand() % (HEIGHT - 6) + 3;

    for (int y = start_y - 2; y <= start_y + 2; ++y) {
        for (int x = start_x - 2; x <= start_x + 2; ++x) {
            map[y][x] = '.';
        }
    }

    // Dig out additional rooms
    int num_rooms = 5 + rand() % 5;

    for (int i = 0; i < num_rooms; ++i) {
        int x = rand() % (WIDTH - 6) + 3;
        int y = rand() % (HEIGHT - 6) + 3;

        if (is_wall(map, x, y)) {
            for (int h = -1; h <= 1; ++h) {
                for (int w = -1; w <= 1; ++w) {
                    map[y+h][x+w] = '.';
                }
            }
        }
    }

    // Connect rooms with corridors
    for (int y = 1; y < HEIGHT-1; ++y) {
        for (int x = 1; x < WIDTH-1; ++x) {
            if (map[y][x] == '.' && count_adj_walls(map, x, y) == 1) {
                if (map[y-1][x] == '#') {
                    map[y-1][x] = '.';
                } else if (map[y+1][x] == '#') {
                    map[y+1][x] = '.';
                } else if (map[y][x-1] == '#') {
                    map[y][x-1] = '.';
                } else if (map[y][x+1] == '#') {
                    map[y][x+1] = '.';
                }
            }
        }
    }
}

void print_map(char map[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            putchar(map[y][x]);
        }
        putchar('\n');
    }
}

bool is_wall(char map[HEIGHT][WIDTH], int x, int y) {
    for (int h = -1; h <= 1; ++h) {
        for (int w = -1; w <= 1; ++w) {
            if (map[y+h][x+w] == '.') {
                return false;
            }
        }
    }
    return true;
}

int count_adj_walls(char map[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for (int h = -1; h <= 1; ++h) {
        for (int w = -1; w <= 1; ++w) {
            if (map[y+h][x+w] == '#') {
                ++count;
            }
        }
    }
    return count;
}