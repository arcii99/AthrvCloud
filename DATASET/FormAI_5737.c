//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 60
#define MAP_HEIGHT 30

char map[MAP_HEIGHT][MAP_WIDTH] = {
    "+-------------------------------------------------------------+",
    "|                        GPS Navigation                        |",
    "|                                                             |",
    "|               +------+                                      |",
    "|               |      |                                      |",
    "|               |      |     +-----------+                     |",
    "|               |      +-----+           |                     |",
    "|       +-------+            |           |           +---------+",
    "|       |                    +-----------+           |         |",
    "|       |                                              |         |",
    "|       +------+              +-----------+           +---------+",
    "|              |              |           |                     |",
    "|              +--------------+           |           +---------+",
    "|                                   +-----+           |         |",
    "|                                                     +---------+",
    "|                                                             |",
    "|                                                             |",
    "+-------------------------------------------------------------+"
};

int x = 2;  // horizontal position
int y = 2;  // vertical position

void draw_map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        printf("%s\n", map[i]);
    }
}

int main() {
    int ch;
    draw_map();
    printf("Press 'q' to quit.\n");
    while ((ch = getchar()) != 'q') {
        switch (ch) {
            case 'w':
                if (y > 1) {
                    map[y][x] = ' ';
                    y--;
                    map[y][x] = '+';
                }
                break;
            case 's':
                if (y < MAP_HEIGHT - 2) {
                    map[y][x] = ' ';
                    y++;
                    map[y][x] = '+';
                }
                break;
            case 'a':
                if (x > 1) {
                    map[y][x] = ' ';
                    x--;
                    map[y][x] = '+';
                }
                break;
            case 'd':
                if (x < MAP_WIDTH - 2) {
                    map[y][x] = ' ';
                    x++;
                    map[y][x] = '+';
                }
                break;
        }
        system("clear");  // clear console (UNIX only)
        draw_map();
        printf("Press 'q' to quit.\n");
    }
    return 0;
}