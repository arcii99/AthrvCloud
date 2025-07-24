//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// planet struct
typedef struct Planet{
  char* name;
  float mass;
  float x_position;
  float y_position;
  float x_velocity;
  float y_velocity;
  float force_x;
  float force_y;
} Planet;

// simulation function
void simulate_gravity(Planet* p1, Planet* p2) {
  float distance_squared = pow(p1->x_position - p2->x_position, 2) + pow(p1->y_position - p2->y_position, 2);
  float force = (p1->mass * p2->mass * 6.67430e-11) / distance_squared;
  float angle = atan2(p2->y_position - p1->y_position, p2->x_position - p1->x_position);
  p1->force_x += force * cos(angle);
  p2->force_x -= force * cos(angle);
  p1->force_y += force * sin(angle);
  p2->force_y -= force * sin(angle);
}

int main(void) {
  // initial setup of planets
  srand(time(NULL));
  Planet* earth = calloc(1, sizeof(Planet));
  earth->name = "Earth";
  earth->mass = 5.97e24;
  earth->x_position = 0;
  earth->y_position = 0;
  earth->x_velocity = 0;
  earth->y_velocity = 0;
  earth->force_x = 0;
  earth->force_y = 0;

  Planet* moon = calloc(1, sizeof(Planet));
  moon->name = "Moon";
  moon->mass = 7.34e22;
  moon->x_position = 384400000;
  moon->y_position = 0;
  moon->x_velocity = 0;
  moon->y_velocity = 1022;
  moon->force_x = 0;
  moon->force_y = 0;

  int tick = 0;
  printf("Let's watch Earth and Moon dance in the sky!\n");
  printf("Tick %d: Earth's position (%f, %f), Moon's position (%f, %f)\n", tick, earth->x_position, earth->y_position, moon->x_position, moon->y_position);

  // simulate gravity for 1000 ticks
  for (tick = 1; tick <= 1000; tick++) {
    simulate_gravity(earth, moon);

    earth->x_velocity += earth->force_x / earth->mass;
    earth->y_velocity += earth->force_y / earth->mass;
    moon->x_velocity += moon->force_x / moon->mass;
    moon->y_velocity += moon->force_y / moon->mass;

    earth->x_position += earth->x_velocity;
    earth->y_position += earth->y_velocity;
    moon->x_position += moon->x_velocity;
    moon->y_position += moon->y_velocity;

    earth->force_x = 0;
    earth->force_y = 0;
    moon->force_x = 0;
    moon->force_y = 0;

    if (tick % 100 == 0) {
      printf("Tick %d: Earth's position (%f, %f), Moon's position (%f, %f)\n", tick, earth->x_position, earth->y_position, moon->x_position, moon->y_position);
    }
  }

  printf("And that's how Earth and Moon did the gravity dance!\n");

  free(earth);
  free(moon);

  return 0;
}