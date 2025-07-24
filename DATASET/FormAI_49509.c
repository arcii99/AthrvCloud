//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define MAX_ENEMIES 5

struct entity {
    char symbol;
    int x, y;
    int health, damage;
};

int player_x, player_y;
struct entity enemies[MAX_ENEMIES];
int num_enemies = 0;

char map[HEIGHT][WIDTH];

void generate_map() {
    // Fill the entire map with .
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = '.';
        }
    }
    // Place walls around the edge of the map
    for (int i = 0; i < WIDTH; i++) {
        map[0][i] = '#';
        map[HEIGHT-1][i] = '#';
    }
    for (int i = 0; i < HEIGHT; i++) {
        map[i][0] = '#';
        map[i][WIDTH-1] = '#';
    }
    // Place the player at (1, 1)
    player_x = 1;
    player_y = 1;
    map[player_y][player_x] = '@';
    // Generate random rooms and connect them with corridors
    srand(time(NULL));
    int num_rooms = 5 + rand() % 5;
    for (int i = 0; i < num_rooms; i++) {
        int x = rand() % (WIDTH-6) + 2;
        int y = rand() % (HEIGHT-6) + 2;
        int w = rand() % 6 + 4;
        int h = rand() % 6 + 4;
        for (int j = y; j < y+h; j++) {
            for (int k = x; k < x+w; k++) {
                map[j][k] = '.';
            }
        }
    }
    for (int i = 0; i < num_rooms-1; i++) {
        int x1 = rand() % WIDTH;
        int y1 = rand() % HEIGHT;
        int x2 = rand() % WIDTH;
        int y2 = rand() % HEIGHT;
        while (x1 == x2) {
            x2 = rand() % WIDTH;
        }
        while (y1 == y2) {
            y2 = rand() % HEIGHT;
        }
        int step_x = x1 < x2 ? 1 : -1;
        int step_y = y1 < y2 ? 1 : -1;
        for (int x = x1; x != x2; x += step_x) {
            map[y1][x] = '.';
        }
        for (int y = y1; y != y2; y += step_y) {
            map[y][x2] = '.';
        }
    }
}

void place_enemies() {
    // Place enemies randomly on the map
    for (int i = 0; i < MAX_ENEMIES; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        while (map[y][x] != '.') {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        }
        enemies[i].symbol = 'e';
        enemies[i].x = x;
        enemies[i].y = y;
        enemies[i].health = 10;
        enemies[i].damage = 3;
        map[y][x] = enemies[i].symbol;
    }
    num_enemies = MAX_ENEMIES;
}

void move_enemies() {
    // Move enemies randomly towards the player
    for (int i = 0; i < num_enemies; i++) {
        if (enemies[i].health <= 0) {
            map[enemies[i].y][enemies[i].x] = '.';
            enemies[i] = enemies[num_enemies-1];
            num_enemies--;
            i--;
            continue;
        }
        int dx = player_x - enemies[i].x;
        int dy = player_y - enemies[i].y;
        if (dx == 0 && dy == 0) {
            printf("You died!\n");
            exit(0);
        }
        if (dx == 0 && abs(dy) <= 1) {
            printf("The %c hits you for %d damage!\n", enemies[i].symbol, enemies[i].damage);
            enemies[i].health -= 5;
        }
        else if (dy == 0 && abs(dx) <= 1) {
            printf("The %c hits you for %d damage!\n", enemies[i].symbol, enemies[i].damage);
            enemies[i].health -= 5;
        }
        else if (abs(dx) <= 1 && abs(dy) <= 1 && map[enemies[i].y+dy][enemies[i].x+dx]=='.') {
            map[enemies[i].y][enemies[i].x] = '.';
            enemies[i].x += dx;
            enemies[i].y += dy;
            map[enemies[i].y][enemies[i].x] = enemies[i].symbol;
        }
        else {
            int dir = rand() % 4;
            int newx = enemies[i].x;
            int newy = enemies[i].y;
            if (dir == 0 && map[newy-1][newx]=='.') {
                newy--;
            }
            if (dir == 1 && map[newy+1][newx]=='.') {
                newy++;
            }
            if (dir == 2 && map[newy][newx-1]=='.') {
                newx--;
            }
            if (dir == 3 && map[newy][newx+1]=='.') {
                newx++;
            }
            if (newx != enemies[i].x || newy != enemies[i].y) {
                map[enemies[i].y][enemies[i].x] = '.';
                enemies[i].x = newx;
                enemies[i].y = newy;
                map[enemies[i].y][enemies[i].x] = enemies[i].symbol;
            }
        }
    }
}

int main() {
    generate_map();
    place_enemies();
    while (1) {
        // Print the current map
        system("clear");
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
        // Handle player input
        char c = getchar();
        int dx = 0, dy = 0;
        switch (c) {
            case 'w': dy = -1; break;
            case 's': dy = 1; break;
            case 'a': dx = -1; break;
            case 'd': dx = 1; break;
            default: break;
        }
        if (map[player_y+dy][player_x+dx] == '.') {
            player_x += dx;
            player_y += dy;
            map[player_y][player_x] = '@';
        }
        else if (map[player_y+dy][player_x+dx] == '#') {
            continue;
        }
        else {
            for (int i = 0; i < num_enemies; i++) {
                if (enemies[i].x == player_x+dx && enemies[i].y == player_y+dy) {
                    printf("You hit the %c for 5 damage!\n" ,enemies[i].symbol);
                    enemies[i].health -= 5;
                }
            }
        }
        move_enemies();
    }
    return 0;
}