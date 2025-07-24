//FormAI DATASET v1.0 Category: Physics simulation ; Style: synchronous
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.673 * pow(10, -11)    // gravitational constant G

typedef struct {
  double mass;
  double x, y;     // Position
  double vx, vy;   // Velocity
  double ax, ay;   // Acceleration
  double fx, fy;   // Force
} Particle;

Particle particles[2];

double calc_distance(double x1, double y1, double x2, double y2) {
  double dx = x1 - x2;
  double dy = y1 - y2;
  return sqrt(pow(dx, 2) + pow(dy, 2));
}

void calc_force(Particle* p1, Particle* p2) {
  double distance = calc_distance(p1->x, p1->y, p2->x, p2->y);
  double force = GRAV_CONST * p1->mass * p2->mass / pow(distance, 2);
  double ang = atan2(p2->y-p1->y, p2->x-p1->x);
  p1->fx += force * cos(ang);
  p1->fy += force * sin(ang);
}

void update_particle(Particle* p, double delta_t) {
  p->ax = p->fx / p->mass;
  p->ay = p->fy / p->mass;
  p->vx += p->ax * delta_t;
  p->vy += p->ay * delta_t;
  p->x += p->vx * delta_t;
  p->y += p->vy * delta_t;
}

int main() {
  particles[0].mass = 5.974E24;  // mass of Earth
  particles[0].x = 0;
  particles[0].y = 0;
  particles[0].vx = 0;
  particles[0].vy = 0;

  particles[1].mass = 7.342E22;  // mass of Moon
  particles[1].x = 3.844E8;      // distance from Earth
  particles[1].y = 0;
  particles[1].vx = 0;
  particles[1].vy = 1022;        // initial velocity of Moon

  double delta_t = 1; // time step in seconds
  int n_step = 10;    // number of time steps

  for (int i = 0; i < n_step; i++) {
    // Reset force of first particle to zero
    particles[0].fx = 0;
    particles[0].fy = 0;
    
    // Calculate force with second particle
    calc_force(&particles[0], &particles[1]);
    calc_force(&particles[1], &particles[0]);
    
    // Update first particle's position and velocity
    update_particle(&particles[0], delta_t);
    
    // Print out position of second particle
    printf("moon position at time %d: (%.2E, %.2E)\n", i, particles[1].x, particles[1].y);
  }
  
  return 0;
}