//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50
#define MAX_ROOMS 10
#define MIN_SIZE 5
#define MAX_SIZE 10

typedef struct {
    int x;
    int y;
} Pair;

typedef struct {
    Pair pos;
    int width;
    int height;
} Room;

char map[ROWS][COLS];

Pair player;

void generate_map(void);
void create_rooms(Room rooms[]);
void print_map(void);
void place_player(void);

int main(void) {
    srand(time(NULL));
    generate_map();
    place_player();
    print_map();
    printf("Player is at (%d, %d)\n", player.x, player.y);
    return 0;
}

void generate_map(void) {
    // fill map with walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            map[i][j] = '#';
        }
    }

    // create rooms
    Room rooms[MAX_ROOMS];
    create_rooms(rooms);

    // connect rooms with corridors
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        int x1 = rooms[i].pos.x + rooms[i].width / 2;
        int y1 = rooms[i].pos.y + rooms[i].height / 2;
        int x2 = rooms[i+1].pos.x + rooms[i+1].width / 2;
        int y2 = rooms[i+1].pos.y + rooms[i+1].height / 2;
        while (x1 != x2) {
            if (x1 < x2) {
                x1++;
            } else {
                x1--;
            }
            map[y1][x1] = '.';
        }
        while (y1 != y2) {
            if (y1 < y2) {
                y1++;
            } else {
                y1--;
            }
            map[y1][x1] = '.';
        }
    }
}

void create_rooms(Room rooms[]) {
    int num_rooms = 0;

    while (num_rooms < MAX_ROOMS) {
        int x = rand() % (COLS - MAX_SIZE - 1) + 1;
        int y = rand() % (ROWS - MAX_SIZE - 1) + 1;
        int w = rand() % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE;
        int h = rand() % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE;

        Room new_room = {{x, y}, w, h};
        int overlaps = 0;
        for (int i = 0; i < num_rooms; i++) {
            if (x < rooms[i].pos.x + rooms[i].width && x + w > rooms[i].pos.x &&
                y < rooms[i].pos.y + rooms[i].height && y + h > rooms[i].pos.y) {
                overlaps = 1;
                break;
            }
        }

        if (!overlaps) {
            for (int i = y; i < y + h; i++) {
                for (int j = x; j < x + w; j++) {
                    map[i][j] = '.';
                }
            }
            rooms[num_rooms] = new_room;
            num_rooms++;
        }
    }
}

void print_map(void) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void place_player(void) {
    while (1) {
        int x = rand() % COLS;
        int y = rand() % ROWS;
        if (map[y][x] == '.') {
            player.x = x;
            player.y = y;
            break;
        }
    }
}