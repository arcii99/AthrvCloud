//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define ENEMY_ROWS 4
#define ENEMY_COLS 10
#define MAX_BULLETS 10

int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

struct bullet {
    int x, y;
    int alive;
};

struct enemy {
    int x, y;
    int alive;
};

struct player {
    int x, y;
    int score;
};

struct screen {
    char data[SCREEN_HEIGHT][SCREEN_WIDTH];
    struct player player;
    struct enemy enemies[ENEMY_ROWS][ENEMY_COLS];
    struct bullet bullets[MAX_BULLETS];
};

void clear_screen(struct screen* s) {
    for(int y=0; y<SCREEN_HEIGHT; y++) {
        for(int x=0; x<SCREEN_WIDTH; x++) {
            s->data[y][x] = ' ';
        }
    }
}

void draw_screen(struct screen* s) {
    printf("\033[2J\033[1;1H");
    for(int y=0; y<SCREEN_HEIGHT; y++) {
        for(int x=0; x<SCREEN_WIDTH; x++) {
            putchar(s->data[y][x]);
        }
        putchar('\n');
    }
    printf("SCORE: %d\n", s->player.score);
}

void update_screen(struct screen* s) {
    clear_screen(s);
    for(int y=0; y<ENEMY_ROWS; y++) {
        for(int x=0; x<ENEMY_COLS; x++) {
            if(s->enemies[y][x].alive) {
                s->data[s->enemies[y][x].y][s->enemies[y][x].x] = 'x';
            }
        }
    }
    for(int i=0; i<MAX_BULLETS; i++) {
        if(s->bullets[i].alive) {
            s->data[s->bullets[i].y][s->bullets[i].x] = '|';
        }
    }
    s->data[s->player.y][s->player.x] = 'P';
}

void create_enemies(struct screen* s) {
    for(int y=0; y<ENEMY_ROWS; y++) {
        for(int x=0; x<ENEMY_COLS; x++) {
            s->enemies[y][x].x = x*3 + 10;
            s->enemies[y][x].y = y+2;
            s->enemies[y][x].alive = 1;
        }
    }
}

void move_player(struct screen* s, int dir) {
    s->player.x += dir;
    if(s->player.x < 0) s->player.x = 0;
    if(s->player.x >= SCREEN_WIDTH) s->player.x = SCREEN_WIDTH-1;
}

void move_enemies(struct screen* s) {
    static int tick = 0;
    tick++;
    if(tick > 5) {
        tick = 0;
        int dx = -1;
        int dy = 0;
        for(int y=0; y<ENEMY_ROWS; y++) {
            for(int x=0; x<ENEMY_COLS; x++) {
                if(s->enemies[y][x].alive) {
                    s->enemies[y][x].x += dx;
                    s->enemies[y][x].y += dy;
                    if(s->enemies[y][x].x < 1) dx = 1;
                    if(s->enemies[y][x].x > SCREEN_WIDTH-3) dx = -1;
                }
            }
            if(s->enemies[y][0].alive) {
                if(s->enemies[y][0].y >= SCREEN_HEIGHT-1) {
                    printf("GAME OVER\n");
                    exit(0);
                }
            }
        }
    }
}

void shoot_bullet(struct screen* s) {
    int i;
    for(i=0; i<MAX_BULLETS; i++) {
        if(!s->bullets[i].alive) {
            s->bullets[i].alive = 1;
            s->bullets[i].x = s->player.x;
            s->bullets[i].y = s->player.y-1;
            break;
        }
    }
}

void move_bullets(struct screen* s) {
    for(int i=0; i<MAX_BULLETS; i++) {
        if(s->bullets[i].alive) {
            s->bullets[i].y--;
            if(s->bullets[i].y < 0) {
                s->bullets[i].alive = 0;
            }
            else {
                for(int y=0; y<ENEMY_ROWS; y++) {
                    for(int x=0; x<ENEMY_COLS; x++) {
                        if(s->enemies[y][x].alive) {
                            if(s->enemies[y][x].x == s->bullets[i].x &&
                               s->enemies[y][x].y == s->bullets[i].y) {
                                s->bullets[i].alive = 0;
                                s->enemies[y][x].alive = 0;
                                s->player.score++;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(void) {
    srand(time(NULL));
    struct screen s;
    clear_screen(&s);
    create_enemies(&s);
    s.player.x = SCREEN_WIDTH/2;
    s.player.y = SCREEN_HEIGHT-3;
    s.player.score = 0;
    while(1) {
        update_screen(&s);
        draw_screen(&s);
        if(kbhit()) {
            int c = getchar();
            if(c == 'a') move_player(&s, -1);
            if(c == 'd') move_player(&s, 1);
            if(c == ' ') shoot_bullet(&s);
        }
        move_enemies(&s);
        move_bullets(&s);
        usleep(10000);
    }
    return 0;
}