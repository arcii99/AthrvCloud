//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 6
#define COL 10

void draw_map(int map[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (map[i][j] == 0) {
                printf(" x ");
            } else {
                printf(" o ");
            }
        }
        printf("\n");
    }
}

void fill_map(int map[ROW][COL]) {
    srand(time(NULL));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (rand() % 3 == 0) {
                map[i][j] = 0;
            } else {
                map[i][j] = 1;
            }
        }
    }
}

void find_route(int map[ROW][COL], int r, int c) {
    if (r >= ROW || c >= COL || map[r][c] == 0) {
        return;
    }

    map[r][c] = 0;

    if (r == ROW - 1 && c == COL - 1) {
        printf("\nCongratulations! You have found the exit!\n");
        return;
    }

    printf("Moving to row %d, column %d\n", r, c);

    find_route(map, r + 1, c);
    find_route(map, r, c + 1);
}

int main() {
    int map[ROW][COL];

    fill_map(map);

    printf("Maze Map:\n");
    draw_map(map);

    printf("\n");
    find_route(map, 0, 0);

    return 0;
}