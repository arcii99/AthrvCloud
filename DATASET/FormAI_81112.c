//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: optimized
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.67E-11 // gravitational constant, in N m^2 / kg^2
#define EARTH_RAD 6371000  // radius of Earth, in meters
#define SUN_MASS 1.98E30  // mass of the Sun, in kg
#define EARTH_MASS 5.97E24 // mass of Earth, in kg
#define AU 1.5E11 // astronomical unit, in meters

typedef struct {
  double x, y, z; // position of the object, in meters
  double vx, vy, vz; // velocity of the object, in m/s
  double mass; // mass of the object, in kg
  double ax, ay, az; // acceleration of the object, in m/s^2
  double fx, fy, fz; // force acting on the object, in N
} Body;

// function to calculate the force acting on a body due to gravity
void calculate_force(Body *body1, Body *body2) {
  double dx = body2->x - body1->x;
  double dy = body2->y - body1->y;
  double dz = body2->z - body1->z;
  double d = sqrt(dx*dx + dy*dy + dz*dz);
  double f = (GRAV_CONST * body1->mass * body2->mass) / (d*d);
  body1->fx += f * dx / d;
  body1->fy += f * dy / d;
  body1->fz += f * dz / d;
}

int main() {
  Body sun = {
    .x = 0,
    .y = 0,
    .z = 0,
    .vx = 0,
    .vy = 0,
    .vz = 0,
    .mass = SUN_MASS,
    .ax = 0,
    .ay = 0,
    .az = 0,
    .fx = 0,
    .fy = 0,
    .fz = 0,
  };
  Body earth = {
    .x = AU,
    .y = 0,
    .z = 0,
    .vx = 0,
    .vy = 30000,
    .vz = 0,
    .mass = EARTH_MASS,
    .ax = 0,
    .ay = 0,
    .az = 0,
    .fx = 0,
    .fy = 0,
    .fz = 0,
  };
  double dt = 1; // timestep, in seconds
  int num_steps = 365 * 24 * 60 * 60 / dt; // number of steps in one year
  for (int i = 0; i < num_steps; i++) {
    // calculate forces on the bodies
    sun.fx = sun.fy = sun.fz = 0;
    earth.fx = earth.fy = earth.fz = 0;
    calculate_force(&sun, &earth);
    calculate_force(&earth, &sun);
    // update positions of the bodies
    earth.ax = earth.fx / earth.mass;
    earth.ay = earth.fy / earth.mass;
    earth.az = earth.fz / earth.mass;
    earth.vx += earth.ax * dt;
    earth.vy += earth.ay * dt;
    earth.vz += earth.az * dt;
    earth.x += earth.vx * dt;
    earth.y += earth.vy * dt;
    earth.z += earth.vz * dt;
    sun.ax = sun.fx / sun.mass;
    sun.ay = sun.fy / sun.mass;
    sun.az = sun.fz / sun.mass;
    sun.vx += sun.ax * dt;
    sun.vy += sun.ay * dt;
    sun.vz += sun.az * dt;
    sun.x += sun.vx * dt;
    sun.y += sun.vy * dt;
    sun.z += sun.vz * dt;
    printf("%d: Earth position = (%e, %e, %e)\n", i, earth.x, earth.y, earth.z);
  }
  return 0;
}