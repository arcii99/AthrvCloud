//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 30
#define MAP_HEIGHT 20
#define MAX_ROOMS 5
#define ROOM_MIN_SIZE 4
#define ROOM_MAX_SIZE 8

char map[MAP_HEIGHT][MAP_WIDTH];
int player_x, player_y;

int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_room(int x, int y, int width, int height) {
    for (int i = y; i < y + height; i++) {
        for (int j = x; j < x + width; j++) {
            map[i][j] = '.';
        }
    }
}

void connect_rooms(int x1, int y1, int x2, int y2) {
    if (rand_range(0, 1) == 0) {
        for (int i = x1; i <= x2; i++) {
            map[y1][i] = '.';
        }
        if (y1 < y2) {
            for (int i = y1; i <= y2; i++) {
                map[i][x2] = '.';
            }
        } else {
            for (int i = y2; i <= y1; i++) {
                map[i][x2] = '.';
            }
        }
    } else {
        for (int i = y1; i <= y2; i++) {
            map[i][x1] = '.';
        }
        if (x1 < x2) {
            for (int i = x1; i <= x2; i++) {
                map[y2][i] = '.';
            }
        } else {
            for (int i = x2; i <= x1; i++) {
                map[y2][i] = '.';
            }
        }
    }
}

void generate_map() {
    // Initialize map with walls
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }

    srand(time(NULL));

    // Generate rooms
    int num_rooms = 0;
    while (num_rooms < MAX_ROOMS) {
        int x = rand_range(1, MAP_WIDTH - ROOM_MAX_SIZE - 1);
        int y = rand_range(1, MAP_HEIGHT - ROOM_MAX_SIZE - 1);
        int width = rand_range(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        int height = rand_range(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        if (map[y][x] == '.') {
            continue;
        }
        generate_room(x, y, width, height);
        if (num_rooms == 0) {
            player_x = x + width / 2;
            player_y = y + height / 2;
        } else {
            int prev_x = rand_range(x, x + width - 1);
            int prev_y = rand_range(y, y + height - 1);
            connect_rooms(prev_x, prev_y, x + width / 2, y + height / 2);
        }
        num_rooms++;
    }
}

void print_map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();
    printf("Player position: (%d, %d)\n", player_x, player_y);
    return 0;
}