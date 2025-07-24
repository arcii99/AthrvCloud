//FormAI DATASET v1.0 Category: Physics simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 20
#define GRAVITY 10.0

typedef struct {
  double x, y;
  double vx, vy;
  double ax, ay;
  bool on_ground;
} particle_t;

double rand_double(double range) {
  return ((double)rand() / RAND_MAX) * range;
}

double get_time() {
  return (double)clock() / CLOCKS_PER_SEC;
}

void print_particle(particle_t *p) {
  int x = (int)(p->x + 0.5);
  int y = (int)(p->y + 0.5);
  if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
    return;
  }
  putchar('#');
  for (int i = 0; i < HEIGHT - y - 1; i++) {
    putchar('\n');
  }
  for (int i = 0; i < x; i++) {
    putchar(' ');
  }
  putchar('O');
  for (int i = x + 1; i < WIDTH; i++) {
    putchar(' ');
  }
}

void update_particle(particle_t *p, double dt) {
  p->vx += p->ax * dt;
  p->vy += p->ay * dt;
  p->x += p->vx * dt;
  p->y += p->vy * dt;
  p->ay = GRAVITY;
  if (p->y < 0) {
    p->y = 0;
    p->vy = -p->vy * 0.7;
    if (p->vy < 1) {
      p->on_ground = true;
    }
  }
}

void simulate() {
  double start_time = get_time();
  particle_t p = {
    .x = rand_double(WIDTH),
    .y = rand_double(HEIGHT),
    .vx = rand_double(10) - 5,
    .vy = rand_double(10) - 5,
    .ax = 0,
    .ay = GRAVITY,
    .on_ground = false
  };
  while (!p.on_ground) {
    double t = get_time() - start_time;
    update_particle(&p, t);
    system("clear");
    print_particle(&p);
    fflush(stdout);
  }
}

int main() {
  srand(time(NULL));
  while (true) {
    simulate();
  }
  return 0;
}