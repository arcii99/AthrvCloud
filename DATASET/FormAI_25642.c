//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: genious
#include <stdio.h>

#define G 6.67e-11 // Gravitational constant
#define TIMESTEP 100 // Time step for each iteration
#define MAX_STEPS 1000000 // Maximum number of simulation steps
#define NUM_PLANETS 3 // Number of planets in the simulation

struct Vec {
  double x, y;
};

struct Planet {
  char name[20];
  double mass;
  struct Vec pos, vel, acc;
};

void update_planets(struct Planet planets[]) {
  int i, j;
  struct Vec r, F;
  double dist, mag;

  for (i = 0; i < NUM_PLANETS; i++) {
    for (j = 0; j < NUM_PLANETS; j++) {
      if (i == j) continue;

      r.x = planets[j].pos.x - planets[i].pos.x;
      r.y = planets[j].pos.y - planets[i].pos.y;
      dist = sqrt(r.x * r.x + r.y * r.y);

      mag = G * planets[i].mass * planets[j].mass / (dist * dist);
      F.x = mag * r.x / dist;
      F.y = mag * r.y / dist;

      planets[i].acc.x += F.x / planets[i].mass;
      planets[i].acc.y += F.y / planets[i].mass;
    }
  }

  for (i = 0; i < NUM_PLANETS; i++) {
    planets[i].vel.x += planets[i].acc.x * TIMESTEP;
    planets[i].vel.y += planets[i].acc.y * TIMESTEP;
    planets[i].pos.x += planets[i].vel.x * TIMESTEP;
    planets[i].pos.y += planets[i].vel.y * TIMESTEP;

    planets[i].acc.x = 0;
    planets[i].acc.y = 0;
  }
}

void print_planets(struct Planet planets[]) {
  int i;
  for (i = 0; i < NUM_PLANETS; i++) {
    printf("%s\t(%f, %f)\t(%f, %f)\t%f\n",
      planets[i].name,
      planets[i].pos.x, planets[i].pos.y,
      planets[i].vel.x, planets[i].vel.y,
      planets[i].mass
    );
  }
}

int main() {
  struct Planet planets[NUM_PLANETS] = {
    {"Earth", 5.97e24, {0, 0}, {0, 0}, {0, 0}},
    {"Mars", 6.39e23, {227.9e9, 0}, {0, 24.077e3}, {0, 0}},
    {"Venus", 4.87e24, {-108.2e9, 0}, {0, -35.02e3}, {0, 0}}
  };

  int i, j;
  for (i = 0; i < MAX_STEPS; i++) {
    update_planets(planets);
    if (i % 10000 == 0) {
      printf("Step %d\n", i);
      print_planets(planets);
    }
  }
}