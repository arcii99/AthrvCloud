//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // Gravitational constant in m^3 kg^-1 s^-2
#define AU 149.6e9 // 1 astronomical unit in meters
#define DAY 86400 // Number of seconds in a day
#define YEAR 365.25 // Number of days in a year
#define PI 3.141592653589793 // The magical number pi

typedef struct {
  double x;
  double y;
  double z;
} Vector3d;

typedef struct {
  Vector3d position;
  Vector3d velocity;
  double mass;
} Body;

void update_velocity(Body* body, double dt, Vector3d acceleration) {
  body->velocity.x += dt * acceleration.x;
  body->velocity.y += dt * acceleration.y;
  body->velocity.z += dt * acceleration.z;
}

void update_position(Body* body, double dt) {
  body->position.x += dt * body->velocity.x;
  body->position.y += dt * body->velocity.y;
  body->position.z += dt * body->velocity.z;
}

double calculate_distance(Body* body1, Body* body2) {
  double dx = body1->position.x - body2->position.x;
  double dy = body1->position.y - body2->position.y;
  double dz = body1->position.z - body2->position.z;
  return sqrt(dx*dx + dy*dy + dz*dz);
}

double calculate_force(double mass1, double mass2, double distance) {
  return G * mass1 * mass2 / (distance * distance);
}

Vector3d calculate_acceleration(Body* body1, Body* body2) {
  Vector3d acceleration;
  double distance = calculate_distance(body1, body2);
  double force = calculate_force(body1->mass, body2->mass, distance);
  acceleration.x = force * (body2->position.x - body1->position.x) / (body1->mass * distance);
  acceleration.y = force * (body2->position.y - body1->position.y) / (body1->mass * distance);
  acceleration.z = force * (body2->position.z - body1->position.z) / (body1->mass * distance);
  return acceleration;
}

void simulate(Body* bodies, int num_bodies, double dt, double end_time) {
  int i, j, k;
  double t;
  Vector3d acceleration[num_bodies], total_acceleration;

  for (t = 0.0; t < end_time; t += dt) {
    for (i = 0; i < num_bodies; i++) {
      total_acceleration.x = 0.0;
      total_acceleration.y = 0.0;
      total_acceleration.z = 0.0;
      for (j = 0; j < num_bodies; j++) {
        if (i != j) {
          acceleration[j] = calculate_acceleration(&bodies[i], &bodies[j]);
          total_acceleration.x += acceleration[j].x;
          total_acceleration.y += acceleration[j].y;
          total_acceleration.z += acceleration[j].z;
        }
      }
      update_velocity(&bodies[i], dt, total_acceleration);
    }

    for (k = 0; k < num_bodies; k++) {
      update_position(&bodies[k], dt);
      printf("%e %e %e\n", bodies[k].position.x / AU, bodies[k].position.y / AU, bodies[k].position.z / AU);
    }
  }
}

int main() {
  // The Sun, Earth, and Jupiter
  Body bodies[3];
  bodies[0].position.x = 0.0;
  bodies[0].position.y = 0.0;
  bodies[0].position.z = 0.0;
  bodies[0].velocity.x = 0.0;
  bodies[0].velocity.y = 0.0;
  bodies[0].velocity.z = 0.0;
  bodies[0].mass = 1.9891e30; // mass of the Sun

  bodies[1].position.x = -1.4710e11;
  bodies[1].position.y = 0.0;
  bodies[1].position.z = 0.0;
  bodies[1].velocity.x = 0.0;
  bodies[1].velocity.y = 3.0287e4;
  bodies[1].velocity.z = 0.0;
  bodies[1].mass = 5.9722e24; // mass of the Earth

  bodies[2].position.x = 7.7856e11;
  bodies[2].position.y = 0.0;
  bodies[2].position.z = 0.0;
  bodies[2].velocity.x = 0.0;
  bodies[2].velocity.y = -1.3075e4;
  bodies[2].velocity.z = 0.0;
  bodies[2].mass = 1.8987e27; // mass of Jupiter

  simulate(bodies, 3, DAY, YEAR);

  return 0;
}