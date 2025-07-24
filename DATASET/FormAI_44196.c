//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

#define PLAYER_WIDTH 3
#define PLAYER_HEIGHT 1
#define PLAYER_SPEED 1

#define ENEMY_WIDTH 1
#define ENEMY_HEIGHT 1
#define ENEMY_SPEED 1
#define ENEMY_COUNT 20

#define BULLET_WIDTH 1
#define BULLET_HEIGHT 1
#define BULLET_SPEED 2

#define ESC 27
#define SPACE 32

struct point {
    int x;
    int y;
};

struct player {
    struct point pos;
    int lives;
};

struct enemy {
    struct point pos;
    int active;
};

struct bullet {
    struct point pos;
    int active;
};

struct termios orig_termios;

void disable_raw_mode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enable_raw_mode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disable_raw_mode);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void clear_screen() {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void set_cursor_visibility(int visible) {
    if (visible) {
        printf("\033[?25h");
    } else {
        printf("\033[?25l");
    }
}

void draw_char(char c, int x, int y) {
    printf("\033[%d;%dH%c", y, x, c);
}

void draw_string(char *s, int x, int y) {
    printf("\033[%d;%dH%s", y, x, s);
}

void move_player(struct player *p, int dir) {
    p->pos.x += dir * PLAYER_SPEED;

    if (p->pos.x < 0) {
        p->pos.x = 0;
    }

    if (p->pos.x + PLAYER_WIDTH > SCREEN_WIDTH) {
        p->pos.x = SCREEN_WIDTH - PLAYER_WIDTH;
    }
}

void fire_bullet(struct bullet *b, struct player *p) {
    if (b->active) {
        return;
    }

    b->pos.x = p->pos.x + PLAYER_WIDTH / 2 - BULLET_WIDTH / 2;
    b->pos.y = p->pos.y - BULLET_HEIGHT;
    b->active = 1;
}

void move_bullet(struct bullet *b) {
    if (!b->active) {
        return;
    }

    b->pos.y -= BULLET_SPEED;

    if (b->pos.y < 0) {
        b->active = 0;
    }
}

void draw_player(struct player *p) {
    draw_char('>', p->pos.x, p->pos.y);
    draw_char('-', p->pos.x + 1, p->pos.y);
    draw_char('<', p->pos.x + 2, p->pos.y);
}

void draw_enemy(struct enemy *e) {
    draw_char(e->active ? 'X' : ' ', e->pos.x, e->pos.y);
}

void draw_bullet(struct bullet *b) {
    draw_char('*', b->pos.x, b->pos.y);
}

int detect_collision(struct point *p1, int w1, int h1, struct point *p2, int w2, int h2) {
    if (p1->x + w1 <= p2->x || p1->x >= p2->x + w2) {
        return 0;
    }

    if (p1->y + h1 <= p2->y || p1->y >= p2->y + h2) {
        return 0;
    }

    return 1;
}

int main() {
    struct player player = { { SCREEN_WIDTH / 2 - PLAYER_WIDTH / 2, SCREEN_HEIGHT - PLAYER_HEIGHT - 1 }, 3 };
    struct enemy enemies[ENEMY_COUNT];
    struct bullet bullet = {};
    int game_over = 0;
    int score = 0;

    enable_raw_mode();
    set_cursor_visibility(0);

    for (int i = 0; i < ENEMY_COUNT; i++) {
        enemies[i].pos.x = i * ENEMY_WIDTH + SCREEN_WIDTH / 2 - ENEMY_WIDTH * ENEMY_COUNT / 2;
        enemies[i].pos.y = 1;
        enemies[i].active = 1;
    }

    while (!game_over) {
        clear_screen();

        if (player.lives == 0) {
            game_over = 1;
            draw_string("Game Over!", SCREEN_WIDTH / 2 - 5, SCREEN_HEIGHT / 2);
            draw_string("Press 'q' to quit.", SCREEN_WIDTH / 2 - 7, SCREEN_HEIGHT / 2 + 2);
        } else if (score == ENEMY_COUNT) {
            game_over = 1;
            draw_string("You Win!", SCREEN_WIDTH / 2 - 4, SCREEN_HEIGHT / 2);
            draw_string("Press 'q' to quit.", SCREEN_WIDTH / 2 - 7, SCREEN_HEIGHT / 2 + 2);
        } else {
            draw_string("Score:", 0, 0);
            printf("%d", score);
            draw_string("Lives:", SCREEN_WIDTH - 7, 0);
            printf("%d", player.lives);

            move_bullet(&bullet);
            move_player(&player, 0);

            char c = '\0';

            if (read(STDIN_FILENO, &c, 1) == 1) {
                if (c == ESC || c == 'q') {
                    game_over = 1;
                } else if (c == 'a') {
                    move_player(&player, -1);
                } else if (c == 'd') {
                    move_player(&player, 1);
                } else if (c == SPACE) {
                    fire_bullet(&bullet, &player);
                }
            }

            for (int i = 0; i < ENEMY_COUNT; i++) {
                if (!enemies[i].active) {
                    continue;
                }

                draw_enemy(&enemies[i]);

                if (detect_collision(&bullet.pos, BULLET_WIDTH, BULLET_HEIGHT, &enemies[i].pos, ENEMY_WIDTH, ENEMY_HEIGHT)) {
                    bullet.active = 0;
                    enemies[i].active = 0;
                    score++;
                } else if (detect_collision(&player.pos, PLAYER_WIDTH, PLAYER_HEIGHT, &enemies[i].pos, ENEMY_WIDTH, ENEMY_HEIGHT)) {
                    enemies[i].active = 0;
                    player.lives--;
                }

                enemies[i].pos.y += ENEMY_SPEED;

                if (enemies[i].pos.y >= SCREEN_HEIGHT) {
                    enemies[i].active = 0;
                    player.lives--;
                }
            }

            if (bullet.active) {
                draw_bullet(&bullet);
            }

            draw_player(&player);
        }

        fflush(stdout);
        usleep(1000000 / 60);
    }

    set_cursor_visibility(1);

    return 0;
}