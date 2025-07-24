//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 5

typedef struct {
    int x, y, width, height;
} Room;

typedef struct {
    int x, y;
} Point;

char map[HEIGHT][WIDTH];
Room rooms[MAX_ROOMS];

void init_map() {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            map[i][j] = '#';
        }
    }
}

void print_map() {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int room_overlap(Room r1, Room r2) {
    return !(r1.x + r1.width <= r2.x || r1.x >= r2.x + r2.width || r1.y + r1.height <= r2.y || r1.y >= r2.y + r2.height);
}

void create_room(int i) {
    int x = rand() % (WIDTH - 10) + 1;
    int y = rand() % (HEIGHT - 10) + 1;
    int width = rand() % 6 + 5;
    int height = rand() % 6 + 5;

    rooms[i].x = x;
    rooms[i].y = y;
    rooms[i].width = width;
    rooms[i].height = height;
    
    int j;
    for(j = 0; j < i; j++) {
        if(room_overlap(rooms[i], rooms[j])) {
            create_room(i);
            return;
        }
    }
    
    int k, l;
    for(k = x; k < x + width; k++) {
        for(l = y; l < y + height; l++) {
            map[l][k] = '.';
        }
    }
}

void connect_rooms() {
    int i, j;
    for(i = 0; i < MAX_ROOMS; i++) {
        if(i == MAX_ROOMS - 1) {
            break;
        }
        
        Point p1, p2;
        
        p1.x = rand() % rooms[i].width + rooms[i].x;
        p1.y = rand() % rooms[i].height + rooms[i].y;
        p2.x = rand() % rooms[i+1].width + rooms[i+1].x;
        p2.y = rand() % rooms[i+1].height + rooms[i+1].y;
        
        while(p1.x != p2.x || p1.y != p2.y) {
            if(p1.x != p2.x) {
                if(p1.x < p2.x) {
                    p1.x++;
                } else {
                    p1.x--;
                }
            } else {
                if(p1.y < p2.y) {
                    p1.y++;
                } else {
                    p1.y--;
                }
            }
            
            map[p1.y][p1.x] = '#';
        }
    }
}

int main() {
    srand(time(NULL));
    
    init_map();
    
    int i;
    for(i = 0; i < MAX_ROOMS; i++) {
        create_room(i);
    }
    
    connect_rooms();
    
    print_map();
    
    return 0;
}