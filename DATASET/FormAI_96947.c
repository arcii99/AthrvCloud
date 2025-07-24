//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: excited
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define GRAV_CONST 0.000000000066742

typedef struct {
  double x;
  double y;
  double z;
} Vector;

typedef struct {
  Vector position;
  Vector velocity;
  double mass;
} Body;

int main() {
  Body sun = {
    .mass = 1989000e24,
    .position = {0, 0, 0},
    .velocity = {0, 0, 0},
  };
  
  Body earth = {
    .mass = 5.972e24,
    .position = {1.496e11, 0, 0},
    .velocity = {0, 29780, 0},
  };
  
  Body moon = {
    .mass = 73.47e21,
    .position = {1.496e11 + 384400000, 0, 0},
    .velocity = {0, 3078, 0},
  };
  
  Body mars = {
    .mass = 641.71e21,
    .position = {0, -2.279e11, 0},
    .velocity = {-24130, 0, 0},
  };
  
  Body venus = {
    .mass = 48.685e23,
    .position = {0, -108.94e9, 0},
    .velocity = {35020, 0, 0},
  };
  
  Body mercury = {
    .mass = 3.301e23,
    .position = {0, -57.91e9, 0},
    .velocity = {47360, 0, 0},
  };
  
  Body jupiter = {
    .mass = 1898.19e24,
    .position = {0, 0, -7.785e11},
    .velocity = {13070, 0, 0},
  };
  
  Body saturn = {
    .mass = 568.34e24,
    .position = {0, 0, 1.433e12},
    .velocity = {-9650, 0, 0},
  };
  
  Body uranus = {
    .mass = 86.813e24,
    .position = {0, 0, -2.871e12},
    .velocity = {6810, 0, 0},
  };
  
  Body neptune = {
    .mass = 102.413e24,
    .position = {0, 0, 4.495e12},
    .velocity = {-5440, 0, 0},
  };
  
  Body pluto = {
    .mass = 1.27e22,
    .position = {0, 0, -5.906e12},
    .velocity = {4740, 0, 0},
  };
  
  Body bodies[] = {sun, earth, moon, mars, venus, mercury, jupiter, saturn, uranus, neptune, pluto};
  
  double t = 0;
  double dt = 3600; // 1 hour
  
  while (1) {
    t += dt;
    
    for (int i = 0; i < sizeof(bodies) / sizeof(Body); i++) {
      for (int j = i + 1; j < sizeof(bodies) / sizeof(Body); j++) {
        Vector r = {bodies[j].position.x - bodies[i].position.x, bodies[j].position.y - bodies[i].position.y, bodies[j].position.z - bodies[i].position.z};
        double dist = sqrt(r.x * r.x + r.y * r.y + r.z * r.z);
        Vector force = {.x = GRAV_CONST * bodies[i].mass * bodies[j].mass / (dist * dist * dist) * r.x,
                        .y = GRAV_CONST * bodies[i].mass * bodies[j].mass / (dist * dist * dist) * r.y,
                        .z = GRAV_CONST * bodies[i].mass * bodies[j].mass / (dist * dist * dist) * r.z};
        bodies[i].velocity.x += force.x / bodies[i].mass * dt;
        bodies[i].velocity.y += force.y / bodies[i].mass * dt;
        bodies[i].velocity.z += force.z / bodies[i].mass * dt;
        bodies[j].velocity.x -= force.x / bodies[j].mass * dt;
        bodies[j].velocity.y -= force.y / bodies[j].mass * dt;
        bodies[j].velocity.z -= force.z / bodies[j].mass * dt;
      }
    }
    
    for (int i = 0; i < sizeof(bodies) / sizeof(Body); i++) {
      bodies[i].position.x += bodies[i].velocity.x * dt;
      bodies[i].position.y += bodies[i].velocity.y * dt;
      bodies[i].position.z += bodies[i].velocity.z * dt;
    }
    
    // Output earth's position every 100 days
    if ((int)(t / 3600 / 24) % 100 == 0) {
      printf("Day %d: The Earth is at (%f, %f, %f)\n", (int)(t / 3600 / 24), earth.position.x, earth.position.y, earth.position.z);
    }
  }
  
  return 0;
}