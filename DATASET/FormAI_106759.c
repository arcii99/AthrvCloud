//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11

typedef struct planet {
  char name[50];
  double mass;
  double position[3];
  double velocity[3];
} Planet;

void simulate(Planet *planets, int n, double dt, double t);
double distance(double *pos1, double *pos2);
void update_velocity(Planet *p1, Planet *p2, double dt);
void update_position(Planet *p, double dt);

int main() {
  int n = 3;
  double t = 0, dt = 3600;
  Planet planets[n];

  // initializing the planets
  strcpy(planets[0].name, "Earth");
  planets[0].mass = 5.97e24;
  planets[0].position[0] = 147e9;
  planets[0].position[1] = 0;
  planets[0].position[2] = 0;
  planets[0].velocity[0] = 0;
  planets[0].velocity[1] = 29.8e3;
  planets[0].velocity[2] = 0;

  strcpy(planets[1].name, "Mars");
  planets[1].mass = 6.39e23;
  planets[1].position[0] = 0;
  planets[1].position[1] = 228e9;
  planets[1].position[2] = 0;
  planets[1].velocity[0] = 24.1e3;
  planets[1].velocity[1] = 0;
  planets[1].velocity[2] = 0;

  strcpy(planets[2].name, "Venus");
  planets[2].mass = 4.87e24;
  planets[2].position[0] = 108e9;
  planets[2].position[1] = 0;
  planets[2].position[2] = 0;
  planets[2].velocity[0] = 0;
  planets[2].velocity[1] = 35e3;
  planets[2].velocity[2] = 0;

  simulate(planets, n, dt, t);

  return 0;
}

void simulate(Planet *planets, int n, double dt, double t) {
  int i, j, k;
  double x, y, z, r, force;

  while (t < 10 * 365 * 24 * 3600) {
    for (i=0; i<n; i++) {
      for (j=i+1; j<n; j++) {
        r = distance(planets[i].position, planets[j].position);
        force = G * planets[i].mass * planets[j].mass / (r * r);

        x = planets[j].position[0] - planets[i].position[0];
        y = planets[j].position[1] - planets[i].position[1];
        z = planets[j].position[2] - planets[i].position[2];

        planets[i].velocity[0] += force * x / (r * planets[i].mass) * dt;
        planets[i].velocity[1] += force * y / (r * planets[i].mass) * dt;
        planets[i].velocity[2] += force * z / (r * planets[i].mass) * dt;

        planets[j].velocity[0] -= force * x / (r * planets[j].mass) * dt;
        planets[j].velocity[1] -= force * y / (r * planets[j].mass) * dt;
        planets[j].velocity[2] -= force * z / (r * planets[j].mass) * dt;
      }
    }

    for (k=0; k<n; k++) {
      update_position(&planets[k], dt);
    }

    t += dt;
  }
}

void update_position(Planet *p, double dt) {
  p->position[0] += p->velocity[0] * dt;
  p->position[1] += p->velocity[1] * dt;
  p->position[2] += p->velocity[2] * dt;
}

void update_velocity(Planet *p1, Planet *p2, double dt) {
  int i;
  double f, distance, direction[3];

  distance = sqrt(pow(p1->position[0]-p2->position[0], 2) +
                  pow(p1->position[1]-p2->position[1], 2) +
                  pow(p1->position[2]-p2->position[2], 2));
  f = G * p1->mass * p2->mass / pow(distance, 2);

  for (i=0; i<3; i++) {
    direction[i] = p2->position[i] - p1->position[i];
    p1->velocity[i] += f * direction[i] / distance / p1->mass * dt;
    p2->velocity[i] -= f * direction[i] / distance / p2->mass * dt;
  }
}

double distance(double *pos1, double *pos2) {
  return sqrt(pow(pos1[0]-pos2[0], 2) + pow(pos1[1]-pos2[1], 2) + pow(pos1[2]-pos2[2], 2));
}