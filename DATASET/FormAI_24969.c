//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20
#define MAX_ROOMS 6

typedef struct {
    int x;
    int y;
    int w;
    int h;
} Room;

void draw_map(char map[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

int intersect(Room a, Room b) {
    return (a.x <= (b.x + b.w)) && ((a.x + a.w) >= b.x) && (a.y <= (b.y + b.h)) && ((a.y + a.h) >= b.y);

}

int generate_map(char map[HEIGHT][WIDTH]) {
    int num_rooms = 0;
    Room rooms[MAX_ROOMS];
    srand(time(NULL));
    // Fill the map with walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[y][x] = '#';
        }
    }
    // Generate a bunch of random rooms and try to place them
    for (int i = 0; i < MAX_ROOMS; i++) {
        int w, h;
        do {
            // Random width and height between 4 and 10
            w = rand() % 7 + 4;
            h = rand() % 7 + 4;
            // Random position within the bounds of the map
            rooms[i].x = rand() % (WIDTH - w - 2) + 1;
            rooms[i].y = rand() % (HEIGHT - h - 2) + 1;
            rooms[i].w = w;
            rooms[i].h = h;
        } while (intersect(rooms[i], rooms[i]));
        // If the room doesn't overlap, draw it on the map
        for (int y = rooms[i].y; y < rooms[i].y + rooms[i].h; y++) {
            for (int x = rooms[i].x; x < rooms[i].x + rooms[i].w; x++) {
                map[y][x] = '.';
            }
        }
        num_rooms++;
    }
    // Connect the rooms with corridors
    for (int i = 0; i < num_rooms - 1; i++) {
        // Calculate the center of the two rooms
        int x1 = rooms[i].x + rooms[i].w / 2;
        int y1 = rooms[i].y + rooms[i].h / 2;
        int x2 = rooms[i + 1].x + rooms[i + 1].w / 2;
        int y2 = rooms[i + 1].y + rooms[i + 1].h / 2;
        // Connect them with a straight line
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
    return num_rooms;
}

int main() {
    char map[HEIGHT][WIDTH];
    int num_rooms = generate_map(map);
    printf("Generated map with %d rooms:\n", num_rooms);
    draw_map(map);
    return 0;
}