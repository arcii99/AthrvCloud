//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point tl, br;
} Rect;

typedef struct {
    Point position;
    int health, attack;
} Actor;

Actor player;

char map[MAP_HEIGHT][MAP_WIDTH];

Rect rooms[MAX_ROOMS];
int n_rooms = 0;

void init_map() {
    for(int i = 0; i < MAP_HEIGHT; i++) {
        for(int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }
}

void print_map() {
    for(int i = 0; i < MAP_HEIGHT; i++) {
        for(int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int check_overlap(Rect r1, Rect r2) {
    if(r1.br.x < r2.tl.x || r1.tl.x > r2.br.x) return 0;
    if(r1.br.y < r2.tl.y || r1.tl.y > r2.br.y) return 0;
    return 1;
}

void create_rooms() {
    Rect r;
    n_rooms = 0;
    while(n_rooms < MAX_ROOMS) {
        r.tl.x = rand() % (MAP_WIDTH-5) + 1;
        r.tl.y = rand() % (MAP_HEIGHT-5) + 1;
        r.br.x = r.tl.x + rand() % 5 + 5;
        r.br.y = r.tl.y + rand() % 5 + 5;
        int overlap = 0;
        for(int i = 0; i < n_rooms; i++) {
            if(check_overlap(r, rooms[i])) {
                overlap = 1;
                break;
            }
        }
        if(!overlap) {
            rooms[n_rooms] = r;
            n_rooms++;
            for(int i = r.tl.y+1; i < r.br.y; i++) {
                for(int j = r.tl.x+1; j < r.br.x; j++) {
                    map[i][j] = '.';
                }
            }
        }
    }
}

void place_player() {
    int i = rand() % n_rooms;
    player.position.x = rooms[i].tl.x + rand() % (rooms[i].br.x - rooms[i].tl.x - 1) + 1;
    player.position.y = rooms[i].tl.y + rand() % (rooms[i].br.y - rooms[i].tl.y - 1) + 1;
    map[player.position.y][player.position.x] = '@';
    player.health = 10;
    player.attack = 5;
}

void move_actor(Actor *a, int x, int y) {
    if(map[a->position.y + y][a->position.x + x] == '.') {
        map[a->position.y][a->position.x] = '.';
        a->position.x += x;
        a->position.y += y;
        if(a == &player) map[a->position.y][a->position.x] = '@';
        else map[a->position.y][a->position.x] = 'O';
    }
    else if(map[a->position.y + y][a->position.x + x] == 'O') {
        int damage = rand() % a->attack + 1;
        Actor *enemy = a == &player ? &player : NULL;
        if(enemy) enemy->health -= damage;
        printf("You hit the enemy for %d damage!\n", damage);
    }
}

void player_turn() {
    char c = getchar();
    if(c == 'w') move_actor(&player, 0, -1);
    if(c == 's') move_actor(&player, 0, 1);
    if(c == 'a') move_actor(&player, -1, 0);
    if(c == 'd') move_actor(&player, 1, 0);
}

void enemy_turn() {
    for(int i = 0; i < n_rooms; i++) {
        if(rooms[i].tl.x <= player.position.x && player.position.x <= rooms[i].br.x &&
           rooms[i].tl.y <= player.position.y && player.position.y <= rooms[i].br.y) {
            Actor enemy = { {rooms[i].tl.x+1, rooms[i].tl.y+1}, 10, 5 };
            while(enemy.health > 0) {
                int dx = player.position.x > enemy.position.x ? 1 : -1;
                int dy = player.position.y > enemy.position.y ? 1 : -1;
                move_actor(&enemy, dx, dy);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    init_map();
    create_rooms();
    place_player();
    while(player.health > 0) {
        print_map();
        player_turn();
        enemy_turn();
    }
    printf("You died!\n");
    return 0;
}