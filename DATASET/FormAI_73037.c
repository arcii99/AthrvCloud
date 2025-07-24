//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

typedef struct {
    int x;
    int y;
} Coord;

typedef enum {
    CELL_WALL,
    CELL_FLOOR,
} Cell;

Cell map[WIDTH][HEIGHT];

void init_map() {
    int i, j;
    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            map[i][j] = CELL_WALL;
        }
    }
}

void print_map() {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            putchar(map[j][i] == CELL_WALL ? '#' : '.');
        }
        putchar('\n');
    }
}

void set_cell(Coord c, Cell cell) {
    map[c.x][c.y] = cell;
}

Cell get_cell(Coord c) {
    if(c.x < 0 || c.x >= WIDTH || c.y < 0 || c.y >= HEIGHT)
        return CELL_WALL;
    return map[c.x][c.y];
}

int count_adjacent(Coord c, Cell cell) {
    int i, j;
    int count = 0;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if(i == 0 && j == 0) continue;
            if(get_cell((Coord) {c.x + i, c.y + j}) == cell) count++;
        }
    }
    return count;
}

void carve_room(Coord c1, Coord c2) {
    int i, j;
    for(i = c1.x; i <= c2.x; i++) {
        for(j = c1.y; j <= c2.y; j++) {
            set_cell((Coord) {i, j}, CELL_FLOOR);
        }
    }
}

int generate_dungeon(int n_rooms) {
    int i, j;
    int generated_rooms = 0;
    while(generated_rooms < n_rooms) {
        Coord room_tl = (Coord) {
            rand() % (WIDTH - 6) + 2,
            rand() % (HEIGHT - 6) + 2
        };
        Coord room_br = (Coord) {
            room_tl.x + rand() % 5 + 2,
            room_tl.y + rand() % 5 + 2
        };
        if(get_cell(room_tl) == CELL_WALL && get_cell(room_br) == CELL_WALL) {
            int adj_count = count_adjacent(room_tl, CELL_FLOOR) +
                            count_adjacent(room_br, CELL_FLOOR);
            if(adj_count == 0) {
                carve_room(room_tl, room_br);
                generated_rooms++;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    init_map();
    generate_dungeon(8);
    print_map();
    return 0;
}