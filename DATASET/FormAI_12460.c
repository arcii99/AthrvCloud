//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_ROWS 10
#define MAP_COLS 20
#define MAX_ROOMS 10
#define MAX_ROOM_WIDTH 5
#define MAX_ROOM_HEIGHT 5

void generate_map(int map[][MAP_COLS], int rooms[][4]);
void generate_rooms(int rooms[][4]);
void place_rooms(int map[][MAP_COLS], int rooms[][4]);
void place_corridors(int map[][MAP_COLS], int rooms[][4]);
void print_map(int map[][MAP_COLS]);

int main() {
    int map[MAP_ROWS][MAP_COLS];
    int rooms[MAX_ROOMS][4];

    generate_map(map, rooms);
    print_map(map);

    return 0;
}

void generate_map(int map[][MAP_COLS], int rooms[][4]) {
    srand(time(NULL));

    // Fill the map with walls
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            map[i][j] = 1;
        }
    }

    generate_rooms(rooms);
    place_rooms(map, rooms);
    place_corridors(map, rooms);
}

void generate_rooms(int rooms[][4]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        // Generate a random room size
        int width = rand() % MAX_ROOM_WIDTH + 1;
        int height = rand() % MAX_ROOM_HEIGHT + 1;

        // Randomly place the room in the map
        int row = rand() % (MAP_ROWS - height - 1) + 1;
        int col = rand() % (MAP_COLS - width - 1) + 1;

        rooms[i][0] = row;
        rooms[i][1] = col;
        rooms[i][2] = row + height;
        rooms[i][3] = col + width;
    }
}

void place_rooms(int map[][MAP_COLS], int rooms[][4]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        for (int row = rooms[i][0]; row < rooms[i][2]; row++) {
            for (int col = rooms[i][1]; col < rooms[i][3]; col++) {
                map[row][col] = 0;
            }
        }
    }
}

void place_corridors(int map[][MAP_COLS], int rooms[][4]) {
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        int current_row = rooms[i][2] - 1;
        int current_col = rooms[i][3] - 1;
        int next_row = rooms[i + 1][0];
        int next_col = rooms[i + 1][1];

        while (current_row != next_row) {
            if (map[current_row][current_col] == 1) {
                map[current_row][current_col] = 0;
            }
            if (current_row < next_row) {
                current_row++;
            } else {
                current_row--;
            }
        }

        while (current_col != next_col) {
            if (map[current_row][current_col] == 1) {
                map[current_row][current_col] = 0;
            }
            if (current_col < next_col) {
                current_col++;
            } else {
                current_col--;
            }
        }
    }
}

void print_map(int map[][MAP_COLS]) {
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            if (map[i][j] == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}