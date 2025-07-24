//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_ROOMS 6
#define MIN_SIZE 3
#define MAX_SIZE 6

typedef struct {
    int x;
    int y;
    int w;
    int h;
} Room;

typedef struct {
    int x;
    int y;
    char c;
} Tile;

void print_tiles(Tile map[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[x][y].c);
        }
        printf("\n");
    }
}

void generate_map(Tile map[WIDTH][HEIGHT]) {
    // Fill map with wall tiles
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[x][y].x = x;
            map[x][y].y = y;
            map[x][y].c = '#';
        }
    }

    // Generate rooms
    srand(time(NULL));
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;
    while (num_rooms < MAX_ROOMS) {
        int x = rand() % (WIDTH - MAX_SIZE - 1) + 1;
        int y = rand() % (HEIGHT - MAX_SIZE - 1) + 1;
        int w = rand() % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE;
        int h = rand() % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE;

        // Check for overlap with existing room
        int overlap = 0;
        for (int i = 0; i < num_rooms; i++) {
            if (x < rooms[i].x + rooms[i].w &&
                x + w > rooms[i].x &&
                y < rooms[i].y + rooms[i].h &&
                y + h > rooms[i].y) {
                overlap = 1;
                break;
            }
        }

        // If no overlap, add room to map
        if (!overlap) {
            Room room = {x, y, w, h};
            rooms[num_rooms] = room;
            num_rooms++;

            for (int dy = 0; dy < h; dy++) {
                for (int dx = 0; dx < w; dx++) {
                    int x2 = x + dx;
                    int y2 = y + dy;
                    map[x2][y2].c = '.';
                }
            }
        }
    }

    // Connect rooms with corridors
    for (int i = 0; i < num_rooms - 1; i++) {
        int x1 = rooms[i].x + rooms[i].w / 2;
        int y1 = rooms[i].y + rooms[i].h / 2;
        int x2 = rooms[i + 1].x + rooms[i + 1].w / 2;
        int y2 = rooms[i + 1].y + rooms[i + 1].h / 2;

        int dx = (x1 < x2 ? 1 : -1);
        int dy = (y1 < y2 ? 1 : -1);

        while (x1 != x2 || y1 != y2) {
            if (x1 != x2 && y1 != y2) {
                if (rand() % 2 == 0) {
                    x1 += dx;
                } else {
                    y1 += dy;
                }
            } else if (x1 != x2) {
                x1 += dx;
            } else {
                y1 += dy;
            }

            map[x1][y1].c = '.';
        }
    }

    // Add player and exit
    int player_x = rooms[0].x + 1;
    int player_y = rooms[0].y + 1;
    map[player_x][player_y].c = '@';

    int exit_x = rooms[num_rooms - 1].x + rooms[num_rooms - 1].w - 2;
    int exit_y = rooms[num_rooms - 1].y + rooms[num_rooms - 1].h - 2;
    map[exit_x][exit_y].c = 'X';
}

int main() {
    Tile map[WIDTH][HEIGHT];
    generate_map(map);
    print_tiles(map);
    return 0;
}