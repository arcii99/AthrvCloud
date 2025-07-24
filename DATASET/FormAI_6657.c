//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_ROOMS 6
#define MAX_ROOM_WIDTH 5
#define MAX_ROOM_HEIGHT 5

struct room {
    int x, y, w, h;
};

void print_map(char map[][WIDTH], struct room rooms[], int num_rooms) {
    // prints map with rooms marked as 'R'
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int room_flag = 0;
            for (int k = 0; k < num_rooms; k++) {
                if (i >= rooms[k].y && i < rooms[k].y + rooms[k].h &&
                    j >= rooms[k].x && j < rooms[k].x + rooms[k].w) {
                    printf("R");
                    room_flag = 1;
                    break;
                }
            }
            if (!room_flag) {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

void place_room(char map[][WIDTH], struct room *r) {
    // randomly places room in map
    r->x = rand() % (WIDTH - r->w);
    r->y = rand() % (HEIGHT - r->h);
    for (int i = r->y; i < r->y + r->h; i++) {
        for (int j = r->x; j < r->x + r->w; j++) {
            map[i][j] = '.';
        }
    }
}

void add_corridor(char map[][WIDTH], int x1, int y1, int x2, int y2) {
    // adds a corridor connecting two points in the map
    if (x1 == x2) {
        // vertical corridor
        int starty, endy;
        if (y1 < y2) {
            starty = y1;
            endy = y2;
        } else {
            starty = y2;
            endy = y1;
        }
        for (int i = starty; i <= endy; i++) {
            map[i][x1] = '#';
        }
    } else {
        // horizontal corridor
        int startx, endx;
        if (x1 < x2) {
            startx = x1;
            endx = x2;
        } else {
            startx = x2;
            endx = x1;
        }
        for (int i = startx; i <= endx; i++) {
            map[y1][i] = '#';
        }
    }
}

void connect_rooms(char map[][WIDTH], struct room rooms[], int num_rooms) {
    // randomly adds corridors connecting the rooms
    for (int i = 0; i < num_rooms - 1; i++) {
        int currx = rooms[i].x + rand() % rooms[i].w;
        int curry = rooms[i].y + rand() % rooms[i].h;
        int nextx = rooms[i+1].x + rand() % rooms[i+1].w;
        int nexty = rooms[i+1].y + rand() % rooms[i+1].h;
        add_corridor(map, currx, curry, nextx, nexty);
    }
}

int main(void) {
    srand(time(NULL));

    char map[HEIGHT][WIDTH];
    struct room rooms[MAX_ROOMS];
    int num_rooms = 0;

    // initialize map to all walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = '#';
        }
    }

    // create rooms
    while (num_rooms < MAX_ROOMS) {
        struct room new_room = {
            .w = rand() % MAX_ROOM_WIDTH + 1,
            .h = rand() % MAX_ROOM_HEIGHT + 1,
        };
        place_room(map, &new_room);

        // check overlap with existing rooms
        int overlap_flag = 0;
        for (int i = 0; i < num_rooms; i++) {
            if ((new_room.x + new_room.w >= rooms[i].x) &&
                (new_room.x <= rooms[i].x + rooms[i].w) &&
                (new_room.y + new_room.h >= rooms[i].y) &&
                (new_room.y <= rooms[i].y + rooms[i].h)) {
                overlap_flag = 1;
                break;
            }
        }

        if (!overlap_flag) {
            rooms[num_rooms] = new_room;
            num_rooms++;
        }
    }

    // connect rooms
    connect_rooms(map, rooms, num_rooms);

    // print map
    print_map(map, rooms, num_rooms);

    return 0;
}