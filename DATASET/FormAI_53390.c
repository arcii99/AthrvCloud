//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11     // Gravitational constant

typedef struct planet {
  char name[20];
  double mass;
  double radius;
  double position[3];
  double velocity[3];
  double acceleration[3];
} Planet;

double calculate_distance(double p1[], double p2[]) {
  double distance = 0.0;
  for (int i = 0; i < 3; i++) {
    distance += pow((p1[i] - p2[i]), 2.0);
  }
  return sqrt(distance);
}

void calculate_acceleration(Planet *p1, Planet *p2) {
  double r = calculate_distance(p1->position, p2->position);
  double f = (G * p1->mass * p2->mass) / pow(r, 2.0);
  double a = f / p1->mass;
  for (int i = 0; i < 3; i++) {
    p1->acceleration[i] += a * (p2->position[i] - p1->position[i]) / r;
  }
}

void update_position_velocity(Planet *p, double delta_t) {
  for (int i = 0; i < 3; i++) {
    p->position[i] += p->velocity[i] * delta_t + 0.5 * p->acceleration[i] * pow(delta_t, 2.0);
    p->velocity[i] += p->acceleration[i] * delta_t;
    p->acceleration[i] = 0.0;
  }
}

void print_planet(Planet *p) {
  printf("Planet %s: mass = %.2lf, radius = %.2lf, position = (%.2lf, %.2lf, %.2lf), velocity = (%.2lf, %.2lf, %.2lf)\n",
         p->name, p->mass, p->radius, p->position[0], p->position[1], p->position[2], p->velocity[0], p->velocity[1], p->velocity[2]);
}

int main() {

  // Initialize planets
  Planet earth = {"Earth", 5.97e24, 6.37e6, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
  Planet moon = {"Moon", 7.34e22, 1.74e6, {0.0, 3.84e8, 0.0}, {-1023.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};

  // Simulation parameters
  double delta_t = 60.0;   // time step in seconds
  double end_time = 31536000.0;  // simulation duration in seconds
  int num_steps = end_time / delta_t;

  // Simulation loop
  for (int i = 0; i < num_steps; i++) {
    calculate_acceleration(&earth, &moon);
    calculate_acceleration(&moon, &earth);
    update_position_velocity(&earth, delta_t);
    update_position_velocity(&moon, delta_t);
    if ((i+1) % 1000 == 0) {   // print every 1000 steps
      print_planet(&earth);
      print_planet(&moon);
    }
  }

  return 0;
}