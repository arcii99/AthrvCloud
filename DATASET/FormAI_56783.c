//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PLANETS 9
#define G_CONST 6.674e-11

struct planet {
  char name[20];
  double mass;
  double radius;
  double x, y; // coordinates
  double vx, vy; // velocities
  double fx, fy; // forces acting on planet
};

struct planet planets[NUM_PLANETS]; // array of all planets

double rand_between(double min, double max) {
  return min + ((double)rand() / RAND_MAX) * (max - min);
}

void initialize_planets() {
  // initialize sun
  strcpy(planets[0].name, "Sun");
  planets[0].mass = 1.989e30;
  planets[0].radius = 695700e3;
  planets[0].x = 0;
  planets[0].y = 0;
  planets[0].vx = 0;
  planets[0].vy = 0;

  // initialize other planets
  strcpy(planets[1].name, "Mercury");
  planets[1].mass = 3.3e23;
  planets[1].radius = 2.439e6;
  planets[1].x = rand_between(0.3075e11, 0.468e11);
  planets[1].y = rand_between(-0.296e11, 0.296e11);
  planets[1].vx = rand_between(-47.87e3, 47.87e3);
  planets[1].vy = rand_between(-58.98e3, 58.98e3);

  // rest of the planets
  // ...

}

void calculate_forces() {
  // initialize all forces to zero
  for(int i=0; i<NUM_PLANETS; i++) {
    planets[i].fx = 0;
    planets[i].fy = 0;
  }

  // calculate force between each planet and every other planet
  for(int i=0; i<NUM_PLANETS; i++) {
    for(int j=i+1; j<NUM_PLANETS; j++) {
      double dx = planets[j].x - planets[i].x;
      double dy = planets[j].y - planets[i].y;
      double distance = sqrt(dx*dx + dy*dy);

      double force = G_CONST * planets[i].mass * planets[j].mass / (distance * distance);
      double fx = force * dx / distance;
      double fy = force * dy / distance;

      // apply forces to planets
      planets[i].fx += fx;
      planets[i].fy += fy;
      planets[j].fx -= fx;
      planets[j].fy -= fy;
    }
  }
}

void update_positions(double dt) {
  for(int i=0; i<NUM_PLANETS; i++) {
    planets[i].x += planets[i].vx * dt;
    planets[i].y += planets[i].vy * dt;
  }
}

void update_velocities(double dt) {
  for(int i=0; i<NUM_PLANETS; i++) {
    double ax = planets[i].fx / planets[i].mass;
    double ay = planets[i].fy / planets[i].mass;
    planets[i].vx += ax * dt;
    planets[i].vy += ay * dt;
  }
}

void simulate(double dt, int num_steps) {

  // initialize random number generator
  srand(time(NULL));

  // initialize planets
  initialize_planets();

  for(int i=0; i<num_steps; i++) {

    calculate_forces();

    update_positions(dt);

    calculate_forces(); // recalculate forces after new positions are calculated

    update_velocities(dt);

  }
}

int main() {
  double dt = 60*60; // 1 hour in seconds
  int num_steps = 24*365*10; // 10 years, with 1 day resolution
  simulate(dt, num_steps);
  return 0;
}