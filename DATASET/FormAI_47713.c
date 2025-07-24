//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_ROWS 20
#define MAP_COLS 60

#define MAX_ROOMS 10
#define MIN_ROOM_SIZE 3
#define MAX_ROOM_SIZE 7

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

char map[MAP_ROWS][MAP_COLS];

int x_player, y_player;

typedef struct Room {
    int x, y, width, height;
} Room;

Room *rooms[MAX_ROOMS];

int num_rooms = 0;

int rng(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void make_room(Room *r) {
    int i, j;
    for (i = r->x; i < r->x + r->width; i++) {
        for (j = r->y; j < r->y + r->height; j++) {
            map[i][j] = '.';
        }
    }
}

void make_corridor(int x1, int y1, int x2, int y2) {
    int x = x1, y = y1;
    while (x != x2) {
        if (map[x][y] != '.') {
            map[x][y] = '#';
        }
        if (x < x2) {
            x++;
        } else {
            x--;
        }
    }
    while (y != y2) {
        if (map[x][y] != '.') {
            map[x][y] = '#';
        }
        if (y < y2) {
            y++;
        } else {
            y--;
        }
    }
}

void connect_rooms(Room *r1, Room *r2) {
    int x1 = rng(r1->x, r1->x + r1->width - 1);
    int y1 = rng(r1->y, r1->y + r1->height - 1);
    int x2 = rng(r2->x, r2->x + r2->width - 1);
    int y2 = rng(r2->y, r2->y + r2->height - 1);
    make_corridor(x1, y1, x2, y2);
}

void create_map() {
    int i, j;

    for (i = 0; i < MAP_ROWS; i++) {
        for (j = 0; j < MAP_COLS; j++) {
            map[i][j] = '#';
        }
    }

    for (i = 0; i < MAX_ROOMS; i++) {
        Room *r = (Room*) malloc(sizeof(Room));
        r->x = rng(1, MAP_COLS - MAX_ROOM_SIZE);
        r->y = rng(1, MAP_ROWS - MAX_ROOM_SIZE);
        r->width = rng(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        r->height = rng(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        make_room(r);
        rooms[i] = r;
        num_rooms++;
    }

    for (i = 0; i < num_rooms - 1; i++) {
        connect_rooms(rooms[i], rooms[i + 1]);
    }
}

void print_map() {
    int i, j;

    for (i = 0; i < MAP_ROWS; i++) {
        for (j = 0; j < MAP_COLS; j++) {
            if (i == x_player && j == y_player) {
                printf("@");
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

void move_player(int dir) {
    switch (dir) {
        case UP:
            if (x_player > 0 && map[x_player - 1][y_player] == '.') {
                map[x_player][y_player] = '.';
                x_player--;
            }
            break;
        case DOWN:
            if (x_player < MAP_ROWS - 1 && map[x_player + 1][y_player] == '.') {
                map[x_player][y_player] = '.';
                x_player++;
            }
            break;
        case LEFT:
            if (y_player > 0 && map[x_player][y_player - 1] == '.') {
                map[x_player][y_player] = '.';
                y_player--;
            }
            break;
        case RIGHT:
            if (y_player < MAP_COLS - 1 && map[x_player][y_player + 1] == '.') {
                map[x_player][y_player] = '.';
                y_player++;
            }
            break;
    }
}

int main() {
    srand(time(NULL));
    create_map();
    x_player = rooms[0]->x + rooms[0]->width / 2;
    y_player = rooms[0]->y + rooms[0]->height / 2;
    print_map();
    char input;
    while (1) {
        input = getchar();
        switch (input) {
            case 'w':
                move_player(UP);
                break;
            case 's':
                move_player(DOWN);
                break;
            case 'a':
                move_player(LEFT);
                break;
            case 'd':
                move_player(RIGHT);
                break;
        }
        print_map();
    }
    return 0;
}