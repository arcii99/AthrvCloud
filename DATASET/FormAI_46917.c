//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define HEIGHT 10
#define WIDTH 20
#define MAX_ROOMS 5

int map[HEIGHT][WIDTH];

typedef struct Room {
    int x1;
    int y1;
    int x2;
    int y2;
} Room;

void place_rooms(Room* rooms) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        int w = rand() % 4 + 4;
        int h = rand() % 4 + 4;
        int x = rand() % (WIDTH - w - 1) + 1;
        int y = rand() % (HEIGHT - h - 1) + 1;
        
        Room r;
        r.x1 = x;
        r.y1 = y;
        r.x2 = x + w;
        r.y2 = y + h;
        
        bool overlaps = false;
        for (int j = 0; j < i; j++) {
            if (r.x1 <= rooms[j].x2 && r.x2 >= rooms[j].x1 && r.y1 <= rooms[j].y2 && r.y2 >= rooms[j].y1) {
                overlaps = true;
                break;
            }
        }
        
        if (!overlaps) {
            rooms[i] = r;
        }
    }
}

void connect_rooms(Room* rooms) {
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        int x1 = rooms[i].x1 + (rooms[i].x2 - rooms[i].x1) / 2;
        int y1 = rooms[i].y1 + (rooms[i].y2 - rooms[i].y1) / 2;
        int x2 = rooms[i + 1].x1 + (rooms[i + 1].x2 - rooms[i + 1].x1) / 2;
        int y2 = rooms[i + 1].y1 + (rooms[i + 1].y2 - rooms[i + 1].y1) / 2;
        
        while (x1 != x2 || y1 != y2) {
            if (x1 < x2) {
                x1++;
            } else if (x1 > x2) {
                x1--;
            }
            
            if (y1 < y2) {
                y1++;
            } else if (y1 > y2) {
                y1--;
            }
            
            map[y1][x1] = 0;
        }
    }
}

void fill_map() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = 1;
        }
    }
    
    Room rooms[MAX_ROOMS];
    place_rooms(rooms);
    
    for (int i = 0; i < MAX_ROOMS; i++) {
        for (int y = rooms[i].y1 + 1; y < rooms[i].y2; y++) {
            for (int x = rooms[i].x1 + 1; x < rooms[i].x2; x++) {
                map[y][x] = 0;
            }
        }
    }
    
    connect_rooms(rooms);
}

void print_map() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (map[i][j]) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    fill_map();
    print_map();
    return 0;
}