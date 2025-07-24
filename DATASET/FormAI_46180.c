//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: rigorous
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11
#define DELTA_T 1

typedef struct {
  double x, y;
  double vx, vy;
  double ax, ay;
  double mass;
} body;

void update_position(body *b) {
  b->x += b->vx * DELTA_T + 0.5 * b->ax * DELTA_T * DELTA_T;
  b->y += b->vy * DELTA_T + 0.5 * b->ay * DELTA_T * DELTA_T;
}

void update_velocity(body *b) {
  b->vx += b->ax * DELTA_T;
  b->vy += b->ay * DELTA_T;
}

void update_acceleration(body *b, const body *objects, int num_objects) {
  b->ax = 0;
  b->ay = 0;
  for (int i = 0; i < num_objects; i++) {
    const body *other = &objects[i];
    if (b == other) {
      continue;
    }
    double dx = other->x - b->x;
    double dy = other->y - b->y;
    double r = sqrt(dx * dx + dy * dy);
    double f = G * b->mass * other->mass / (r * r);
    b->ax += f * dx / r / b->mass;
    b->ay += f * dy / r / b->mass;
  }
}

int main(void) {

  body objects[] = {
    { 0, 0, 0, 0, 0, 0, 5.97e24 },
    { 0, 1000, 43000, 0, 0, 0, 1000 },
    { 0, -1000, -43000, 0, 0, 0, 1000 },
    { 1000, 0, 0, -43000, 0, 0, 1000 },
    { -1000, 0, 0, 43000, 0, 0, 1000 }
  };

  const int NUM_OBJECTS = sizeof(objects) / sizeof(*objects);

  for (int i = 0; i < NUM_OBJECTS; i++) {
    body *b = &objects[i];
    update_acceleration(b, objects, NUM_OBJECTS);
  }

  while (1) {
    for (int i = 0; i < NUM_OBJECTS; i++) {
      body *b = &objects[i];
      update_position(b);
      update_acceleration(b, objects, NUM_OBJECTS);
    }
    for (int i = 0; i < NUM_OBJECTS; i++) {
      body *b = &objects[i];
      update_velocity(b);
    }
    printf("Earth: (%f, %f)\n", objects[0].x, objects[0].y);
    printf("Satellite 1: (%f, %f)\n", objects[1].x, objects[1].y);
    printf("Satellite 2: (%f, %f)\n", objects[2].x, objects[2].y);
    printf("Satellite 3: (%f, %f)\n", objects[3].x, objects[3].y);
    printf("Satellite 4: (%f, %f)\n", objects[4].x, objects[4].y);
  }

  return 0;
}