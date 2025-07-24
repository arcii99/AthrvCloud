//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_ROWS 10
#define MAP_COLS 20
#define MAX_ROOMS 5
#define MAX_ROOM_SIZE 6
#define MIN_ROOM_SIZE 2
#define PLAYER '@'
#define FLOOR '.'
#define WALL '#'

char map[MAP_ROWS][MAP_COLS];
int player_pos_x, player_pos_y;

void init_map() {
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            map[i][j] = WALL;
        }
    }
}

void print_map() {
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void put_tile(int x, int y, char tile) {
    if (x >= 0 && x < MAP_COLS && y >= 0 && y < MAP_ROWS) {
        map[y][x] = tile;
    }
}

int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_room(int top_x, int top_y, int width, int height) {
    for (int i = top_y; i < top_y + height; i++) {
        for (int j = top_x; j < top_x + width; j++) {
            if (i == top_y || i == top_y + height - 1 || j == top_x || j == top_x + width - 1) {
                put_tile(j, i, WALL);
            } else {
                put_tile(j, i, FLOOR);
            }
        }
    }
}

void generate_map() {
    srand(time(NULL));
    int num_rooms = random_int(1, MAX_ROOMS);
    int room_width, room_height, top_x, top_y, overlaps_room;
    for (int i = 0; i < num_rooms; i++) {
        do {
            overlaps_room = 0;
            top_x = random_int(0, MAP_COLS - MAX_ROOM_SIZE - 1);
            top_y = random_int(0, MAP_ROWS - MAX_ROOM_SIZE - 1);
            room_width = random_int(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
            room_height = random_int(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
            for (int j = top_y - 1; j < top_y + room_height + 1; j++) {
                for (int k = top_x - 1; k < top_x + room_width + 1; k++) {
                    if (j >= 0 && j < MAP_ROWS && k >= 0 && k < MAP_COLS && map[j][k] != WALL) {
                        overlaps_room = 1;
                        break;
                    }
                }
                if (overlaps_room) {
                    break;
                }
            }
        } while (overlaps_room);
        generate_room(top_x, top_y, room_width, room_height);
    }
}

void find_player_start() {
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            if (map[i][j] == FLOOR) {
                player_pos_x = j;
                player_pos_y = i;
                return;
            }
        }
    }
}

void move_player(int dx, int dy) {
    int new_pos_x = player_pos_x + dx;
    int new_pos_y = player_pos_y + dy;
    char tile = map[new_pos_y][new_pos_x];
    if (tile == FLOOR) {
        put_tile(player_pos_x, player_pos_y, FLOOR);
        put_tile(new_pos_x, new_pos_y, PLAYER);
        player_pos_x = new_pos_x;
        player_pos_y = new_pos_y;
    }
}

int main() {
    init_map();
    generate_map();
    find_player_start();
    put_tile(player_pos_x, player_pos_y, PLAYER);
    print_map();
    char movement;
    while (scanf(" %c", &movement) == 1) {
        switch(movement) {
            case 'w':
                move_player(0, -1);
                break;
            case 'a':
                move_player(-1, 0);
                break;
            case 's':
                move_player(0, 1);
                break;
            case 'd':
                move_player(1, 0);
                break;
            default:
                break;
        }
        print_map();
    }
    return 0;
}