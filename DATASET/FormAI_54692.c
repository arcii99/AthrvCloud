//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

void clear_screen() {
    system("clear");
}

void draw_line(int x1, int y1, int x2, int y2, char map[][WIDTH]) {
    float slope = (float)(y2 - y1) / (x2 - x1);
    int y = y1;
    for (int x = x1; x <= x2; x++) {
        map[HEIGHT-y-1][x] = '#';
        y += slope;
    }
}

void generate_map(char map[][WIDTH], int num_lines) {
    srand(time(NULL));
    for (int i = 0; i < num_lines; i++) {
        int x1 = rand() % WIDTH;
        int y1 = rand() % HEIGHT;
        int x2 = rand() % WIDTH;
        int y2 = rand() % HEIGHT;
        draw_line(x1, y1, x2, y2, map);
    }
}

void print_map(char map[][WIDTH]) {
    for (int y = HEIGHT-1; y >= 0; y--) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

int main() {
    char map[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[y][x] = '.';
        }
    }
    int num_lines;
    printf("Enter the number of lines to draw: ");
    scanf("%d", &num_lines);
    generate_map(map, num_lines);
    clear_screen();
    print_map(map);
    return 0;
}