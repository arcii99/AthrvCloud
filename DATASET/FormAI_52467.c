//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10

void draw_map(int map[MAP_SIZE][MAP_SIZE], int pos_x, int pos_y) {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            if (pos_x == x && pos_y == y) {
                printf("X ");
            } else if (map[y][x] == 0) {
                printf(". ");
            } else if (map[y][x] == 1) {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int map[MAP_SIZE][MAP_SIZE];
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            if (rand() % 4 == 0) {
                map[y][x] = 1;
            } else {
                map[y][x] = 0;
            }
        }
    }

    int pos_x = rand() % MAP_SIZE;
    int pos_y = rand() % MAP_SIZE;

    draw_map(map, pos_x, pos_y);

    while (1) {
        char input[10];
        fgets(input, 10, stdin);

        int new_pos_x = pos_x;
        int new_pos_y = pos_y;

        if (strcmp(input, "up\n") == 0) {
            new_pos_y--;
        } else if (strcmp(input, "down\n") == 0) {
            new_pos_y++;
        } else if (strcmp(input, "left\n") == 0) {
            new_pos_x--;
        } else if (strcmp(input, "right\n") == 0) {
            new_pos_x++;
        }

        if (new_pos_x >= 0 && new_pos_x < MAP_SIZE && new_pos_y >= 0 && new_pos_y < MAP_SIZE && map[new_pos_y][new_pos_x] == 0) {
            pos_x = new_pos_x;
            pos_y = new_pos_y;
        }

        draw_map(map, pos_x, pos_y);
    }

    return 0;
}