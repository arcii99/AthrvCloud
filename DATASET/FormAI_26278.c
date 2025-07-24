//FormAI DATASET v1.0 Category: Game of Life ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define ALIVE 1
#define DEAD 0

int grid[HEIGHT][WIDTH];
int neighbors[HEIGHT][WIDTH];

void clear_screen() {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
}

void print_grid() {
    clear_screen();
    for (int y=0; y < HEIGHT; y++) {
        for (int x=0; x < WIDTH; x++) {
            if (grid[y][x] == ALIVE) {
                printf("%c", 219);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_initial_state() {
    srand(time(NULL));
    for (int y=0; y < HEIGHT; y++) {
        for (int x=0; x < WIDTH; x++) {
            grid[y][x] = rand() % 2;
        }
    }
}

void count_neighbors() {
    for (int y=0; y < HEIGHT; y++) {
        for (int x=0; x < WIDTH; x++) {
            int count = 0;
            for (int i=-1; i < 2; i++) {
                for (int j=-1; j < 2; j++) {
                    int neighbor_y = y+i;
                    int neighbor_x = x+j;

                    if (i == 0 && j == 0) {
                        continue;
                    }

                    if (neighbor_x < 0) {
                        neighbor_x = WIDTH - 1;
                    } else if (neighbor_x > WIDTH - 1) {
                        neighbor_x = 0;
                    }

                    if (neighbor_y < 0) {
                        neighbor_y = HEIGHT - 1;
                    } else if (neighbor_y > HEIGHT - 1) {
                        neighbor_y = 0;
                    }

                    if (grid[neighbor_y][neighbor_x] == ALIVE) {
                        count++;
                    }
                }
            }
            neighbors[y][x] = count;
        }
    }
}

void update_grid() {
    for (int y=0; y < HEIGHT; y++) {
        for (int x=0; x < WIDTH; x++) {
            int state = grid[y][x];
            int count = neighbors[y][x];

            if (state == ALIVE && (count < 2 || count > 3)) {
                state = DEAD;
            } else if (state == DEAD && count == 3) {
                state = ALIVE;
            }

            grid[y][x] = state;
        }
    }
}

int main(void) {
    generate_initial_state();
    while (1) {
        print_grid();
        count_neighbors();
        update_grid();
    }

    return 0;
}