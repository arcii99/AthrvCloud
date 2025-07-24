//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 8

typedef struct Room {
    int x;
    int y;
    int w;
    int h;
} Room;

typedef struct Player {
    int x;
    int y;
} Player;

typedef struct Monster {
    int x;
    int y;
    int hp;
} Monster;

char map[HEIGHT][WIDTH];

void generate_dungeon(Room *rooms, int *num_rooms) {
    int i, j, k, overlap;
    *num_rooms = 0;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            map[i][j] = '#';
        }
    }
    srand(time(NULL));
    for (k = 0; k < MAX_ROOMS; k++) {
        int w = rand() % 5 + 5;
        int h = rand() % 5 + 5;
        int x = rand() % (WIDTH - w - 1) + 1;
        int y = rand() % (HEIGHT - h - 1) + 1;
        Room new_room = { x, y, w, h };
        overlap = 0;
        for (i = 0; i < *num_rooms; i++) {
            if (new_room.x < rooms[i].x + rooms[i].w &&
                rooms[i].x < new_room.x + new_room.w &&
                new_room.y < rooms[i].y + rooms[i].h &&
                rooms[i].y < new_room.y + new_room.h) {
                overlap = 1;
                break;
            }
        }
        if (overlap) {
            continue;
        }
        rooms[*num_rooms] = new_room;
        *num_rooms += 1;
    }
    for (i = 0; i < *num_rooms; i++) {
        for (j = rooms[i].x + 1; j < rooms[i].x + rooms[i].w - 1; j++) {
            for (k = rooms[i].y + 1; k < rooms[i].y + rooms[i].h - 1; k++) {
                map[k][j] = '.';
            }
        }
    }
    for (i = 0; i < *num_rooms - 1; i++) {
        int cx1 = rooms[i].x + rooms[i].w / 2;
        int cy1 = rooms[i].y + rooms[i].h / 2;
        int cx2 = rooms[i+1].x + rooms[i+1].w / 2;
        int cy2 = rooms[i+1].y + rooms[i+1].h / 2;
        if (rand() % 2 == 0) {
            for (j = cx1; j != cx2; j += (cx2 - cx1) / abs(cx2 - cx1)) {
                if (map[cy1][j] == '#') {
                    map[cy1][j] = '.';
                }
            }
            for (j = cy1; j != cy2; j += (cy2 - cy1) / abs(cy2 - cy1)) {
                if (map[j][cx2] == '#') {
                    map[j][cx2] = '.';
                }
            }
        } else {
            for (j = cy1; j != cy2; j += (cy2 - cy1) / abs(cy2 - cy1)) {
                if (map[j][cx1] == '#') {
                    map[j][cx1] = '.';
                }
            }
            for (j = cx1; j != cx2; j += (cx2 - cx1) / abs(cx2 - cx1)) {
                if (map[cy2][j] == '#') {
                    map[cy2][j] = '.';
                }
            }
        }
    }
}

void print_map(Player *p, Monster *m, int num_monsters) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (p->x == j && p->y == i) {
                putchar('@');
            } else if (map[i][j] == '.') {
                int found = 0;
                for (int k = 0; k < num_monsters; k++) {
                    if (m[k].x == j && m[k].y == i) {
                        putchar('M');
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    putchar('.');
                }
            } else {
                putchar(map[i][j]);
            }
        }
        putchar('\n');
    }
}

void move_player(Player *p, int dx, int dy) {
    if (p->x + dx >= 0 && p->x + dx < WIDTH &&
        p->y + dy >= 0 && p->y + dy < HEIGHT &&
        map[p->y+dy][p->x+dx] == '.') {
        p->x += dx;
        p->y += dy;
    }
}

void move_monsters(Monster *m, int num_monsters, Player *p) {
    int i, dx, dy;
    for (i = 0; i < num_monsters; i++) {
        dx = p->x - m[i].x;
        dy = p->y - m[i].y;
        if (abs(dx) > abs(dy)) {
            dx = (dx > 0 ? 1 : -1);
            dy = 0;
        } else {
            dx = 0;
            dy = (dy > 0 ? 1 : -1);
        }
        if (m[i].x + dx >= 0 && m[i].x + dx < WIDTH &&
            m[i].y + dy >= 0 && m[i].y + dy < HEIGHT &&
            map[m[i].y+dy][m[i].x+dx] == '.') {
            m[i].x += dx;
            m[i].y += dy;
        }
        if (m[i].x == p->x && m[i].y == p->y) {
            p->x = -1;
            p->y = -1;
        }
    }
}

int main() {
    Room rooms[MAX_ROOMS];
    int num_rooms;
    Player player = { WIDTH/2, HEIGHT/2 };
    Monster monsters[5] = { {10, 10, 10}, {20, 10, 15}, {30, 10, 20}, {40, 10, 25}, {10, 15, 30} };
    int num_monsters = 5;
    generate_dungeon(rooms, &num_rooms);
    while (1) {
        system("clear");
        print_map(&player, monsters, num_monsters);
        int dx = 0, dy = 0;
        char c = getchar();
        getchar();
        switch (c) {
            case 'w': dy = -1; break;
            case 'a': dx = -1; break;
            case 's': dy = 1; break;
            case 'd': dx = 1; break;
            case 'q': exit(0);
        }
        move_player(&player, dx, dy);
        move_monsters(monsters, num_monsters, &player);
        if (player.x == -1 && player.y == -1) {
            printf("You died!\n");
            exit(0);
        }
    }
    return 0;
}