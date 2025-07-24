//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 5
#define COLS 10
#define MAX_ENEMIES 50
#define MAX_MISSILES 100

struct Enemy {
    int xpos;
    int ypos;
    int alive;
};

struct Missile {
    int xpos;
    int ypos;
    int active;
};

struct Player {
    int xpos;
    int ypos;
};

struct Game {
    struct Enemy enemies[MAX_ENEMIES];
    int num_enemies;
    struct Missile missiles[MAX_MISSILES];
    int num_missiles;
    struct Player player;
    int score;
    int game_over;
};

void init_game(struct Game *game) {
    int x, y;
    game->num_enemies = MAX_ENEMIES;
    game->num_missiles = 0;
    game->score = 0;
    game->game_over = 0;
    game->player.xpos = COLS/2;
    game->player.ypos = ROWS-1;
    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLS; x++) {
            game->enemies[y*COLS+x].xpos = x;
            game->enemies[y*COLS+x].ypos = y;
            game->enemies[y*COLS+x].alive = 1;
        }
    }
}

void print_game(struct Game *game) {
    int x, y, found_enemy;
    found_enemy = 0;
    printf("Score: %d\n\n", game->score);
    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLS+1; x++) {
            if (x == game->player.xpos && y == game->player.ypos) {
                printf("X");
            } else {
                found_enemy = 0;
                for (int i = 0; i < MAX_ENEMIES; i++) {
                    if (game->enemies[i].xpos == x && game->enemies[i].ypos == y && game->enemies[i].alive == 1) {
                        printf("O");
                        found_enemy = 1;
                        break;
                    }
                }
                if (!found_enemy && x < COLS) {
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}

void move_enemies(struct Game *game) {
    int dir, newx, i, all_dead;
    all_dead = 1;
    for (i = 0; i < MAX_ENEMIES; i++) {
        if (game->enemies[i].alive == 1) {
            all_dead = 0;
            dir = rand() % 2 ? 1 : -1;
            newx = game->enemies[i].xpos + dir;
            if (newx < 0 || newx >= COLS) {
                continue;
            }
            game->enemies[i].xpos = newx;
            if (game->enemies[i].ypos == ROWS-1) {
                game->game_over = 1;
            }
        }
    }
    if (all_dead) {
        game->game_over = 1;
    }
}

void move_missiles(struct Game *game) {
    int i;
    for (i = 0; i < MAX_MISSILES; i++) {
        if (game->missiles[i].active == 1) {
            game->missiles[i].ypos--;
            if (game->missiles[i].ypos <= 0) {
                game->missiles[i].active = 0;
            }
            for (int j = 0; j < MAX_ENEMIES; j++) {
                if (game->missiles[i].xpos == game->enemies[j].xpos && game->missiles[i].ypos == game->enemies[j].ypos && game->enemies[j].alive == 1) {
                    game->missiles[i].active = 0;
                    game->enemies[j].alive = 0;
                    game->score++;
                }
            }
        }
    }
}

void move_player(struct Game *game, int dir) {
    int newx;
    newx = game->player.xpos + dir;
    if (newx < 0 || newx >= COLS) {
        return;
    }
    game->player.xpos = newx;
}

void fire_missile(struct Game *game) {
    if (game->num_missiles < MAX_MISSILES) {
        game->missiles[game->num_missiles].xpos = game->player.xpos;
        game->missiles[game->num_missiles].ypos = game->player.ypos-1;
        game->missiles[game->num_missiles].active = 1;
        game->num_missiles++;
    }
}

int main(void) {
    struct Game game;
    char c;
    srand(time(NULL));
    init_game(&game);
    while (!game.game_over) {
        print_game(&game);
        c = getchar();
        if (c == 'a') {
            move_player(&game, -1);
        } else if (c == 'd') {
            move_player(&game, 1);
        } else if (c == ' ') {
            fire_missile(&game);
        }
        move_enemies(&game);
        move_missiles(&game);
        system("clear");
    }
    printf("Game over. Final score: %d\n", game.score);
    return 0;
}