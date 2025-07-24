//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

typedef struct position {
    int x;
    int y;
} position;

char map[WIDTH][HEIGHT];

position player_pos;
position exit_pos;

void generate_map() {
    int i, j;
    int max_rooms = 5 + rand() % 5;
    position room_pos[max_rooms];
    position room_size[max_rooms];

    // Generate empty map
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            map[i][j] = '#';
        }
    }

    srand(time(NULL));

    // Generate rooms
    for (i = 0; i < max_rooms; i++) {
        int room_width = 4 + rand() % 10;
        int room_height = 4 + rand() % 10;
        int room_x = rand() % (WIDTH - room_width - 1) + 1;
        int room_y = rand() % (HEIGHT - room_height - 1) + 1;

        room_pos[i].x = room_x;
        room_pos[i].y = room_y;
        room_size[i].x = room_width;
        room_size[i].y = room_height;

        for (j = room_x; j < room_x + room_width; j++) {
            for (int k = room_y; k < room_y + room_height; k++) {
                if (j == room_x || j == room_x + room_width - 1 || k == room_y || k == room_y + room_height - 1) {
                    map[j][k] = '*';
                }
                else {
                    map[j][k] = '.';
                }
            }
        }
    }

    // Generate corridors
    for (i = 0; i < max_rooms - 1; i++) {
        position from = room_pos[i];
        position to = room_pos[i + 1];

        while (from.x != to.x) {
            if (from.x < to.x) {
                from.x++;
            }
            else {
                from.x--;
            }

            if (map[from.x][from.y] == '#') {
                map[from.x][from.y] = '.';
            }
        }

        while (from.y != to.y) {
            if (from.y < to.y) {
                from.y++;
            }
            else {
                from.y--;
            }

            if (map[from.x][from.y] == '#') {
                map[from.x][from.y] = '.';
            }
        }
    }

    // Place player
    do {
        int pos_x = rand() % WIDTH;
        int pos_y = rand() % HEIGHT;
        if (map[pos_x][pos_y] == '.') {
            map[pos_x][pos_y] = '@';
            player_pos.x = pos_x;
            player_pos.y = pos_y;
            break;
        }
    } while (1);

    // Place exit
    do {
        int pos_x = rand() % WIDTH;
        int pos_y = rand() % HEIGHT;
        if (map[pos_x][pos_y] == '.') {
            map[pos_x][pos_y] = 'X';
            exit_pos.x = pos_x;
            exit_pos.y = pos_y;
            break;
        }
    } while (1);
}

void print_map() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();

    return 0;
}