//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_ROOMS 6

typedef struct room {
    int x;
    int y;
    int w;
    int h;
} room_t;

void generate_map(char map[][WIDTH]);
void print_map(char map[][WIDTH]);
void draw_room(room_t room, char map[][WIDTH]);
void draw_h_tunnel(int x1, int x2, int y, char map[][WIDTH]);
void draw_v_tunnel(int y1, int y2, int x, char map[][WIDTH]);

int main(void) {
    srand(time(NULL));  // Seed random number generator
    
    char map[HEIGHT][WIDTH];
    generate_map(map);
    print_map(map);
    
    return 0;
}

void generate_map(char map[][WIDTH]) {
    // Fill map with walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = '#';
        }
    }
    
    // Generate rooms
    int num_rooms = 0;
    room_t rooms[MAX_ROOMS];
    
    while (num_rooms < MAX_ROOMS) {
        int w = rand() % 6 + 4;
        int h = rand() % 4 + 3;
        int x = rand() % (WIDTH - w - 1) + 1;
        int y = rand() % (HEIGHT - h - 1) + 1;
        
        room_t new_room = {x, y, w, h};
        
        // Check if new room intersects with existing rooms
        int intersects = 0;
        for (int i = 0; i < num_rooms; i++) {
            room_t existing_room = rooms[i];
            if (new_room.x <= existing_room.x + existing_room.w && new_room.x + new_room.w >= existing_room.x &&
                new_room.y <= existing_room.y + existing_room.h && new_room.y + new_room.h >= existing_room.y) {
                intersects = 1;
                break;
            }
        }
        
        // If new room does not intersect with existing rooms, add it to the map
        if (!intersects) {
            rooms[num_rooms] = new_room;
            draw_room(new_room, map);
            num_rooms++;
        }
    }
    
    // Create corridors
    for (int i = 0; i < num_rooms - 1; i++) {
        int x1 = rooms[i].x + rooms[i].w / 2;
        int y1 = rooms[i].y + rooms[i].h / 2;
        int x2 = rooms[i+1].x + rooms[i+1].w / 2;
        int y2 = rooms[i+1].y + rooms[i+1].h / 2;
        
        if (rand() % 2 == 0) {
            draw_h_tunnel(x1, x2, y1, map);
            draw_v_tunnel(y1, y2, x2, map);
        } else {
            draw_v_tunnel(y1, y2, x1, map);
            draw_h_tunnel(x1, x2, y2, map);
        }
    }
}

void draw_room(room_t room, char map[][WIDTH]) {
    for (int i = room.y + 1; i < room.y + room.h - 1; i++) {
        for (int j = room.x + 1; j < room.x + room.w - 1; j++) {
            map[i][j] = '.';
        }
    }
}

void draw_h_tunnel(int x1, int x2, int y, char map[][WIDTH]) {
    for (int i = x1; i <= x2; i++) {
        map[y][i] = '.';
    }
}

void draw_v_tunnel(int y1, int y2, int x, char map[][WIDTH]) {
    for (int i = y1; i <= y2; i++) {
        map[i][x] = '.';
    }
}

void print_map(char map[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}