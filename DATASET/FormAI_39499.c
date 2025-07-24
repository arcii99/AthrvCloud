//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50
#define MAX_ROOMS 10

char dungeon[ROWS][COLS];

typedef struct {
    int x, y, w, h;
} room;

room room_list[MAX_ROOMS];

void generate_rooms();
void place_rooms();
void connect_rooms();
void print_dungeon();

int main() {
    srand(time(NULL));
    generate_rooms();
    place_rooms();
    connect_rooms();
    print_dungeon();

    return 0;
}

void generate_rooms() {
    int i;
    for(i = 0; i < MAX_ROOMS; i++) {
        room new_room;
        new_room.w = rand()%6 + 5;
        new_room.h = rand()%5 + 4;
        new_room.x = rand()%(COLS - new_room.w - 2) + 1;
        new_room.y = rand()%(ROWS - new_room.h - 2) + 1;
        room_list[i] = new_room;
    }
}

void place_rooms() {
    int i, j;
    for(i = 0; i < MAX_ROOMS; i++) {
        for(j = room_list[i].x; j < room_list[i].x + room_list[i].w; j++) {
            dungeon[room_list[i].y][j] = '.';
            dungeon[room_list[i].y + room_list[i].h - 1][j] = '.';
        }
        for(j = room_list[i].y; j < room_list[i].y + room_list[i].h; j++) {
            dungeon[j][room_list[i].x] = '.';
            dungeon[j][room_list[i].x + room_list[i].w - 1] = '.';
        }
    }
}

void connect_rooms() {
    int i, x1, x2, y1, y2;
    for(i = 0; i < MAX_ROOMS - 1; i++) {
        x1 = room_list[i].x + rand()%room_list[i].w;
        y1 = room_list[i].y + rand()%room_list[i].h;
        x2 = room_list[i+1].x + rand()%room_list[i+1].w;
        y2 = room_list[i+1].y + rand()%room_list[i+1].h;

        while(x1 != x2) {
            if(x1 < x2) {
                x1++;
                dungeon[y1][x1] = '#';
            } else {
                x1--;
                dungeon[y1][x1] = '#';
            }
        }
        while(y1 != y2) {
            if(y1 < y2) {
                y1++;
                dungeon[y1][x1] = '#';
            } else {
                y1--;
                dungeon[y1][x1] = '#';
            }
        }
    }
}

void print_dungeon() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(dungeon[i][j] == '\0')
                printf("%c", '#');
            else
                printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }
}