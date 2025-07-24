//FormAI DATASET v1.0 Category: Physics simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_PARTICLES 1000

typedef struct Particle {
    float x, y, vx, vy;
} Particle;

Particle particles[NUM_PARTICLES];

void simulate() {
    srand(time(NULL)); // seed the random number generator

    // initialize particles randomly
    for(int i=0; i<NUM_PARTICLES; i++) {
        particles[i].x = rand() % WIDTH;
        particles[i].y = rand() % HEIGHT;
        particles[i].vx = (rand() % 21) - 10; // random velocity between -10 and 10
        particles[i].vy = (rand() % 21) - 10;
    }

    // simulate physics
    float dt = 0.01;
    float G = 6.67e-11;
    for(int i=0; i<NUM_PARTICLES; i++) {
        Particle *pi = &particles[i];
        for(int j=i+1; j<NUM_PARTICLES; j++) {
            Particle *pj = &particles[j];
            float dx = pj->x - pi->x;
            float dy = pj->y - pi->y;
            float r = sqrt(dx*dx + dy*dy);
            float f = G / (r*r);
            pi->vx += f * dx / r * dt;
            pi->vy += f * dy / r * dt;
            pj->vx -= f * dx / r * dt;
            pj->vy -= f * dy / r * dt;
        }
        pi->x += pi->vx * dt;
        pi->y += pi->vy * dt;
        // wrap particles around the screen
        if(pi->x < 0) {
            pi->x += WIDTH;
        } else if(pi->x > WIDTH) {
            pi->x -= WIDTH;
        }
        if(pi->y < 0) {
            pi->y += HEIGHT;
        } else if(pi->y > HEIGHT) {
            pi->y -= HEIGHT;
        }
    }
}

int main() {
    // initialize particles
    for(int i=0; i<NUM_PARTICLES; i++) {
        particles[i].x = WIDTH/2;
        particles[i].y = HEIGHT/2;
        particles[i].vx = (rand() % 21) - 10; // random velocity between -10 and 10
        particles[i].vy = (rand() % 21) - 10;
    }

    // main loop
    while(1) {
        simulate();

        // clear screen
        printf("\033[2J");

        // draw particles
        for(int i=0; i<NUM_PARTICLES; i++) {
            printf("\033[%d;%dH*", (int)particles[i].y+1, (int)particles[i].x+1);
        }

        // wait
        usleep(100000);
    }

    return 0;
}