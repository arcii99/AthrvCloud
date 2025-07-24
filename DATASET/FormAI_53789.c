//FormAI DATASET v1.0 Category: Physics simulation ; Style: synchronous
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11 // Gravitational constant
#define TIME_STEP 0.1 // Time step for simulation
#define MASS_EARTH 5.972e24 // Mass of the Earth
#define MASS_MOON 7.342e22 // Mass of the Moon

struct Vector {
  double x;
  double y;
  double z;
};

struct Body {
  double mass;
  struct Vector position;
  struct Vector velocity;
  struct Vector acceleration;
};

struct Body create_body(double mass, double x, double y, double z, double vx, double vy, double vz) {
  struct Body body;

  body.mass = mass;
  body.position.x = x;
  body.position.y = y;
  body.position.z = z;
  body.velocity.x = vx;
  body.velocity.y = vy;
  body.velocity.z = vz;

  return body;
}

struct Vector calculate_gravity(struct Body body1, struct Body body2) {
  struct Vector gravity;

  double distance = sqrt(pow(body2.position.x - body1.position.x, 2) + pow(body2.position.y - body1.position.y, 2) + pow(body2.position.z - body1.position.z, 2));
  double force = G * body1.mass * body2.mass / pow(distance, 2);

  gravity.x = force / body1.mass * (body2.position.x - body1.position.x) / distance;
  gravity.y = force / body1.mass * (body2.position.y - body1.position.y) / distance;
  gravity.z = force / body1.mass * (body2.position.z - body1.position.z) / distance;

  return gravity;
}

void update_body(struct Body *body) {
  body->velocity.x += body->acceleration.x * TIME_STEP;
  body->velocity.y += body->acceleration.y * TIME_STEP;
  body->velocity.z += body->acceleration.z * TIME_STEP;

  body->position.x += body->velocity.x * TIME_STEP;
  body->position.y += body->velocity.y * TIME_STEP;
  body->position.z += body->velocity.z * TIME_STEP;
}

int main() {
  struct Body earth = create_body(MASS_EARTH, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  struct Body moon = create_body(MASS_MOON, 0.0, 384400000.0, 0.0, 1022.0, 0.0, 0.0);

  for (int i = 0; i < 10000; i++) {
    struct Vector gravity_earth = calculate_gravity(earth, moon);
    struct Vector gravity_moon = calculate_gravity(moon, earth);

    earth.acceleration.x = gravity_moon.x;
    earth.acceleration.y = gravity_moon.y;
    earth.acceleration.z = gravity_moon.z;

    moon.acceleration.x = gravity_earth.x;
    moon.acceleration.y = gravity_earth.y;
    moon.acceleration.z = gravity_earth.z;

    update_body(&earth);
    update_body(&moon);

    printf("Time: %d s\n", i);
    printf("Earth Position: (%f, %f, %f)\n", earth.position.x, earth.position.y, earth.position.z);
    printf("Moon Position: (%f, %f, %f)\n\n", moon.position.x, moon.position.y, moon.position.z);
  }

  return 0;
}