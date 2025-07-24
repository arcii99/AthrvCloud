//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 21
#define MAX_ROOMS 10

char map[WIDTH][HEIGHT];
int player_x, player_y;

struct room {
    int x, y, w, h;
};

void make_map();
void draw_map();
void draw_player();
void move_player(int dx, int dy);
int check_collision(int x, int y, int w, int h);

int main() {
    make_map();
    player_x = WIDTH/2;
    player_y = HEIGHT/2;
    while (1) {
        draw_map();
        draw_player();
        char input = getchar();
        if (input == 'q') {
            break;
        } else if (input == 'w') {
            move_player(0, -1);
        } else if (input == 's') {
            move_player(0, 1);
        } else if (input == 'a') {
            move_player(-1, 0);
        } else if (input == 'd') {
            move_player(1, 0);
        }
    }
    return 0;
}

void make_map() {
    // Set all tiles to wall
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[x][y] = '#';
        }
    }

    // Randomly generate rooms
    struct room rooms[MAX_ROOMS];
    int num_rooms = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        int w = rand() % 6 + 5;
        int h = rand() % 6 + 5;
        int x = rand() % (WIDTH - w - 1) + 1;
        int y = rand() % (HEIGHT - h - 1) + 1;
        if (!check_collision(x, y, w, h)) {
            // We can add the room
            for (int j = x; j < x+w; j++) {
                for (int k = y; k < y+h; k++) {
                    map[j][k] = '.';
                }
            }
            rooms[num_rooms++] = (struct room) {x, y, w, h};
        }
    }

    // Connect rooms with corridors
    for (int i = 0; i < num_rooms-1; i++) {
        int x1 = rooms[i].x + rooms[i].w/2;
        int y1 = rooms[i].y + rooms[i].h/2;
        int x2 = rooms[i+1].x + rooms[i+1].w/2;
        int y2 = rooms[i+1].y + rooms[i+1].h/2;
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
            map[x1][y1] = '.';
        }
    }
}

void draw_map() {
    printf("\033c"); // Clear screen
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(map[x][y]);
        }
        putchar('\n');
    }
}

void draw_player() {
    putchar('@');
    printf("\033[%dA", HEIGHT - player_y); // Move cursor to player position
    printf("\033[%dD", WIDTH - player_x - 1); // Move cursor to player position
}

void move_player(int dx, int dy) {
    if (map[player_x+dx][player_y+dy] == '.') {
        player_x += dx;
        player_y += dy;
    }
}

int check_collision(int x, int y, int w, int h) {
    for (int i = x-1; i < x+w+1; i++) {
        for (int j = y-1; j < y+h+1; j++) {
            if (map[i][j] == '.') {
                return 1;
            }
        }
    }
    return 0;
}