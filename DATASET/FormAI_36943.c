//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20
#define MAX_ROOMS 6     // maximum number of rooms
#define ROOM_MIN_SIZE 4 // minimum size of each room
#define ROOM_MAX_SIZE 10// maximum size of each room

typedef struct {
    int x, y, w, h;
} Room;

typedef struct {
    int x, y;
} Point;

char dungeon[ROWS][COLS];    // 2D array to represent the dungeon
Room rooms[MAX_ROOMS];      // array to hold rooms
int num_rooms = 0;          // number of rooms created

/* Function prototypes */
void init_dungeon();
void print_dungeon();
void create_rooms();
int is_room_overlap(int r1, int r2);
void connect_rooms();

int main(void)
{
    srand(time(NULL));      // seed the random number generator
    init_dungeon();
    create_rooms();
    connect_rooms();
    print_dungeon();
    return 0;
}

/* Initialize the dungeon with walls */
void init_dungeon()
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            dungeon[i][j] = '#';
        }
    }
}

/* Print the dungeon */
void print_dungeon()
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }
}

/* Create rooms randomly */
void create_rooms()
{
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        int w = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int h = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int x = rand() % (COLS - w - 1) + 1;
        int y = rand() % (ROWS - h - 1) + 1;

        // check if room overlaps with any other rooms
        int j;
        for (j = 0; j < i; j++) {
            if (is_room_overlap(j, i)) {
                break;
            }
        }

        // if room does not overlap, add it to the array
        if (j == i) {
            rooms[i].x = x;
            rooms[i].y = y;
            rooms[i].w = w;
            rooms[i].h = h;
            num_rooms++;
        }
    }

    // add rooms to the dungeon
    int r, c;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            for (i = 0; i < num_rooms; i++) {
                if (r >= rooms[i].y && r <= rooms[i].y + rooms[i].h
                    && c >= rooms[i].x && c <= rooms[i].x + rooms[i].w) {
                    dungeon[r][c] = '.';
                }
            }
        }
    }
}

/* Check if two rooms overlap */
int is_room_overlap(int r1, int r2)
{
    Room room1 = rooms[r1];
    Room room2 = rooms[r2];
    return !(room1.x + room1.w < room2.x || room1.x > room2.x + room2.w
        || room1.y + room1.h < room2.y || room1.y > room2.y + room2.h);
}

/* Connect the rooms with corridors */
void connect_rooms()
{
    int i, r, c;
    for (i = 0; i < num_rooms - 1; i++) {
        Point p1 = { rooms[i].x + rooms[i].w / 2, rooms[i].y + rooms[i].h / 2 };
        Point p2 = { rooms[i + 1].x + rooms[i + 1].w / 2, rooms[i + 1].y + rooms[i + 1].h / 2 };

        // add vertical corridor
        for (r = p1.y; r != p2.y; r += (p2.y - p1.y) / abs(p2.y - p1.y)) {
            dungeon[r][p1.x] = '.';
        }

        // add horizontal corridor
        for (c = p1.x; c != p2.x; c += (p2.x - p1.x) / abs(p2.x - p1.x)) {
            dungeon[p2.y][c] = '.';
        }
    }
}