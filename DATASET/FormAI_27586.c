//FormAI DATASET v1.0 Category: Physics simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define GRAVITY 0.1f

struct Particle {
    float x, y, vx, vy;
};

void clear_screen(void) {
    for (int i = 0; i < HEIGHT; i++) {
        putchar('\n');
    }
}

void draw_particle(int x, int y) {
    putchar('O');
    for (int i = 0; i < 3; i++) {
        if (y - i > 0 && y - i < HEIGHT) {
            putchar('|');
        }
    }
    putchar('\n');
}

void update_particle(struct Particle *p) {
    p->vy += GRAVITY;
    p->x += p->vx;
    p->y += p->vy;
    if (p->x < 0 || p->x >= WIDTH) {
        p->vx = -p->vx;
    }
    if (p->y > HEIGHT) {
        p->y = HEIGHT;
        p->vy = -p->vy * 0.9f;
        if (p->vx > 0) {
            p->vx -= 0.1f;
        } else {
            p->vx += 0.1f;
        }
    } else if (p->y < 0) {
        p->y = 0;
        p->vy = -p->vy;
    }
}

int main(void) {
    srand(time(NULL));
    clear_screen();
    struct Particle particles[10];
    memset(particles, 0, sizeof(particles));
    for (int i = 0; i < 10; i++) {
        particles[i].x = (float)(rand() % WIDTH);
        particles[i].y = (float)(rand() % HEIGHT);
        particles[i].vx = (float)((rand() % 201) - 100) / 100.f;
        particles[i].vy = (float)((rand() % 201) - 100) / 100.f;
    }
    while (1) {
        clear_screen();
        for (int i = 0; i < 10; i++) {
            draw_particle((int)particles[i].x, (int)particles[i].y);
            update_particle(&particles[i]);
        }
        fflush(stdout);
        usleep(1000000 / 60);
    }
    return 0;
}