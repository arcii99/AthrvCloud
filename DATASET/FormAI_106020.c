//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: portable
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

#define N_PLANETS 3
#define G 6.674e-11
#define TIMESTEP 86400

typedef struct {
  double x, y;
}vector2D;

typedef struct {
  char name[20];
  double mass;
  double radius;
  vector2D position;
  vector2D velocity;
  vector2D acceleration;
} planet;

void updateAcceleration(planet *p1, planet *p2) {
  vector2D direction;
  double distance, magnitude;
  direction.x = p2->position.x - p1->position.x;
  direction.y = p2->position.y - p1->position.y;
  distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
  magnitude = G * p2->mass / pow(distance, 2);
  p1->acceleration.x += magnitude * direction.x / distance;
  p1->acceleration.y += magnitude * direction.y /distance;
}

void updatePosition(planet *p) {
  p->position.x += p->velocity.x * TIMESTEP;
  p->position.y += p->velocity.y * TIMESTEP;
}

void updateVelocity(planet *p) {
  p->velocity.x += p->acceleration.x * TIMESTEP;
  p->velocity.y += p->acceleration.y * TIMESTEP;
}

void zeroAcceleration(planet *p) {
  p->acceleration.x = 0;
  p->acceleration.y = 0;
}

int main() {
  int i, j, step;
  double t, dt;
  planet planets[N_PLANETS] = {
    {"Sun", 1.989e30, 6.96e8, {0,0}, {0,0}, {0,0}},
    {"Earth", 5.97e24, 6.37e6, {1.496e11,0}, {0,2.9783e4}, {0,0}},
    {"Mars", 6.39e23, 3.39e6, {0,2.279e11}, {-2.4077e4,0}, {0,0}}
  };

  t = 0;
  dt = TIMESTEP;
  for(step=0; step<365*5; step++) {
    for(i=0; i<N_PLANETS; i++) {
      zeroAcceleration(&planets[i]);
      for(j=0; j<N_PLANETS; j++) {
        if(i!=j) {
          updateAcceleration(&planets[i], &planets[j]);
        }
      }
    }
    for(i=0; i<N_PLANETS; i++) {
      updateVelocity(&planets[i]);
      updatePosition(&planets[i]);
    }
    t += dt;
  }

  printf("Position of each planet after 5 years:\n\n");
  for(i=0; i<N_PLANETS; i++) {
    printf("%s: (%.2e, %.2e)\n", planets[i].name, planets[i].position.x, planets[i].position.y);
  }
  return 0;
}