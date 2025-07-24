//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define ROOM_MIN_SIZE 4
#define ROOM_MAX_SIZE 8
#define MAX_ROOMS 5

char map[ROWS][COLS];

typedef struct room {
    int x;
    int y;
    int width;
    int height;
} Room;

Room rooms[MAX_ROOMS];

void generate_map() {
    int i, j, r, x, y, w, h, room_count = 0;
    
    // Initialize map with walls
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            map[i][j] = '#';
        }
    }
    
    // Generate rooms
    while(room_count < MAX_ROOMS) {
        w = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        h = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        x = rand() % (COLS - w - 1) + 1;
        y = rand() % (ROWS - h - 1) + 1;
        
        // Check if the room overlaps with another room
        int overlaps = 0;
        for(r = 0; r < room_count; r++) {
            if(x < rooms[r].x + rooms[r].width + 1 &&
               x + w + 1 > rooms[r].x &&
               y < rooms[r].y + rooms[r].height + 1 &&
               y + h + 1 > rooms[r].y) {
                overlaps = 1;
                break;
            }
        }
        
        if(!overlaps) {
            Room new_room = {x, y, w, h};
            rooms[room_count] = new_room;
            room_count++;
        }
    }
    
    // Draw rooms
    for(i = 0; i < MAX_ROOMS; i++) {
        for(j = rooms[i].y; j < rooms[i].y + rooms[i].height; j++) {
            for(r = rooms[i].x; r < rooms[i].x + rooms[i].width; r++) {
                map[j][r] = '.';
            }
        }
    }
}

void print_map() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generate_map();
    print_map();
    return 0;
}