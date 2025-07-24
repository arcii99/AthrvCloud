//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 40

char map[HEIGHT][WIDTH];
int player_x, player_y;

void generate_map() {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = rand() % 2 == 0 ? '.' : '#';
        }
    }
}

void print_map() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void place_player() {
    player_x = rand() % WIDTH;
    player_y = rand() % HEIGHT;
    map[player_y][player_x] = '@';
}

int move_player(int x, int y) {
    if (player_x + x < 0 || player_x + x >= WIDTH ||
        player_y + y < 0 || player_y + y >= HEIGHT) {
        return 0;
    }
    if (map[player_y + y][player_x + x] == '#') {
        return 0;
    }
    map[player_y][player_x] = '.';
    player_x += x;
    player_y += y;
    map[player_y][player_x] = '@';
    return 1;
}

int main() {
    generate_map();
    place_player();
    while (1) {
        system("clear");
        print_map();
        printf("Use WASD to move\n");
        char input = getchar();
        switch (input) {
            case 'w': 
                move_player(0, -1); 
                break;
            case 'a': 
                move_player(-1, 0); 
                break;
            case 's': 
                move_player(0, 1); 
                break;
            case 'd': 
                move_player(1, 0); 
                break;
        }
    }
    return 0;
}