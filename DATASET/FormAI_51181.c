//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAP_SIZE 21
#define MAX_DOTS 200

struct Position {
    int x;
    int y;
};

struct Player {
    struct Position pos;
    int points;
    bool dead;
};

struct Ghost {
    struct Position pos;
    bool edible;
    char symbol;
};

int dots_remaining = MAX_DOTS;
char map[MAP_SIZE][MAP_SIZE + 1] = {
    "#####################",
    "#.........#.........#",
    "#.###.###.#.###.###.#",
    "#*###.###.#.###.###*#",
    "#.#.........#.........#",
    "#.#.###.#.#####.#.###.#",
    "#.#...#.#...#.#.#...#.#",
    "###!#.#.###.#.#.###.#.###",
    "#...#.#...#...#.#...#...#",
    "#.###.#.#.#.#.#.#.#.#.###.#",
    "#.#...#.#...#.#.#...#...#",
    "#.#.#.#######.#.#.#######.#",
    "#.#.#.#.......#.#.......#.#",
    "#.#.#.#.#####.#.#.#####.#.#",
    "#.#.#.#.....#.#.#.....#.#.#",
    "#.#.#.#####.#.#.#.#####.#.#",
    "#.#.#.#.....#.#.#.....#.#.#",
    "#.#.#.#.#####.#.#.#####.#.#",
    "#.........#.........#",
    "#####################"
};

void print_map() {
    printf("%s\n", map[0]);
    for (int i = 1; i < MAP_SIZE - 1; i++) {
        printf("%s\n", map[i]);
    }
    printf("%s\n", map[MAP_SIZE - 1]);
}

void clear_screen() {
    system("clear");
}

void move_player(struct Player* p, int dx, int dy) {
    int x = p->pos.x + dx;
    int y = p->pos.y + dy;
    if (x < 0) {
        x = MAP_SIZE - 2;
    } else if (x >= MAP_SIZE - 1) {
        x = 0;
    }
    if (map[y][x] == '.') {
        p->points++;
        dots_remaining--;
    } else if (map[y][x] == '*') {
        p->points += 10;
        dots_remaining--;
    } else if (map[y][x] == '#') {
        return;
    } else if (map[y][x] == 'G') {
        p->dead = true;
    } else if (map[y][x] == '1' || map[y][x] == '2' || map[y][x] == '3' || map[y][x] == '4') {
        p->dead = true;
    }
    p->pos.x = x;
    p->pos.y = y;
}

void move_ghost(struct Ghost* g, int dx, int dy, struct Player p) {
    int x = g->pos.x + dx;
    int y = g->pos.y + dy;
    if (map[y][x] == '.' || map[y][x] == '*' || map[y][x] == ' ' || x < 0 || x >= MAP_SIZE - 1 || y < 0 || y >= MAP_SIZE - 1) {
        g->pos.x = x;
        g->pos.y = y;
    } else if (g->edible && (map[y][x] == '1' || map[y][x] == '2' || map[y][x] == '3' || map[y][x] == '4')) {
        g->pos.x = x;
        g->pos.y = y;
    } else if (map[y][x] == '#') {
        return;
    } else {
        int ghost_dx = g->pos.x - p.pos.x;
        int ghost_dy = g->pos.y - p.pos.y;
        if (abs(ghost_dx) > abs(ghost_dy)) {
            if (ghost_dx > 0) {
                g->pos.x--;
            } else {
                g->pos.x++;
            }
        } else {
            if (ghost_dy > 0) {
                g->pos.y--;
            } else {
                g->pos.y++;
            }
        }
        if (g->pos.x == p.pos.x && g->pos.y == p.pos.y) {
           p.dead = true;
        }
    }
}

void update_ghosts(struct Ghost* ghosts, int num_ghosts, struct Player p) {
    for (int i = 0; i < num_ghosts; i++) {
        if (ghosts[i].edible) {
            move_ghost(&ghosts[i], 0, 0, p);
        } else {
            int dx = rand() % 3 - 1;
            int dy = rand() % 3 - 1;
            move_ghost(&ghosts[i], dx, dy, p);
        }
    }
}

bool check_game_over(struct Player p, struct Ghost* ghosts, int num_ghosts) {
    if (dots_remaining == 0) {
        printf("YOU WON!\n");
        return true;
    }
    if (p.dead) {
        printf("YOU LOST!\n");
        return true;
    }
    for (int i = 0; i < num_ghosts; i++) {
        if (p.pos.x == ghosts[i].pos.x && p.pos.y == ghosts[i].pos.y && !ghosts[i].edible) {
            printf("YOU LOST!\n");
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(NULL));
    struct Player player = { .pos = {1, 1}, .points = 0, .dead = false };
    struct Ghost ghosts[] = {
        { .pos = {10, 10}, .edible = false, .symbol = '1' },
        { .pos = {11, 10}, .edible = false, .symbol = '2' },
        { .pos = {10, 11}, .edible = false, .symbol = '3' },
        { .pos = {11, 11}, .edible = false, .symbol = '4' },
    };
    int num_ghosts = sizeof(ghosts) / sizeof(struct Ghost);

    while (!check_game_over(player, ghosts, num_ghosts)) {
        char input;
        clear_screen();
        print_map();
        printf("\nPoints: %d\n", player.points);
        printf("Move: ");
        scanf("%c", &input);
        getchar();

        switch (input) {
            case 'w':
                move_player(&player, 0, -1);
                break;
            case 'a':
                move_player(&player, -1, 0);
                break;
            case 's':
                move_player(&player, 0, 1);
                break;
            case 'd':
                move_player(&player, 1, 0);
                break;
        }

        update_ghosts(ghosts, num_ghosts, player);

        // 50ms sleep to slow down game loop
        struct timespec tim, tim2;
        tim.tv_sec = 0;
        tim.tv_nsec = 50000000L;
        nanosleep(&tim, &tim2);
    }

    return 0;
}