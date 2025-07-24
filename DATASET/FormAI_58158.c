//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: calm
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 120
#define HEIGHT 50

// Constants for the simulation
#define GRAVITATIONAL_CONSTANT 6.67E-11
#define TIME_STEP 0.0001
#define NUM_PLANETS 8

typedef struct {
  double mass;
  double x;
  double y;
  double vx;
  double vy;
} Planet;

void update_position(Planet *p, double time_step) {
  p->x += p->vx * time_step;
  p->y += p->vy * time_step;
}

void apply_force(Planet *p1, Planet *p2, double time_step) {
  double dx = p2->x - p1->x;
  double dy = p2->y - p1->y;
  double distance = sqrt(dx*dx + dy*dy);
  double force = GRAVITATIONAL_CONSTANT * p1->mass * p2->mass / (distance*distance);

  p1->vx += force * dx / (p1->mass * distance) * time_step;
  p1->vy += force * dy / (p1->mass * distance) * time_step;
}

void simulate(Planet planets[], double time_step, int num_steps) {
  int i, j, k;

  for (k = 0; k < num_steps; k++) {
    // Apply forces
    for (i = 0; i < NUM_PLANETS; i++) {
      for (j = i+1; j < NUM_PLANETS; j++) {
        apply_force(&planets[i], &planets[j], time_step);
        apply_force(&planets[j], &planets[i], time_step);
      }
    }

    // Update positions
    for (i = 0; i < NUM_PLANETS; i++) {
      update_position(&planets[i], time_step);
    }
  }
}

void draw(Planet planets[]) {
  int x, y;

  char buffer[WIDTH * HEIGHT];
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      buffer[y * WIDTH + x] = ' ';
    }
  }

  // Draw planets
  for (int i = 0; i < NUM_PLANETS; i++) {
    int screen_x = (int)(planets[i].x / 5E9 * WIDTH/2 + WIDTH/2);
    int screen_y = (int)(planets[i].y / 5E9 * HEIGHT/2 + HEIGHT/2);

    if (screen_x >= 0 && screen_x < WIDTH && screen_y >= 0 && screen_y < HEIGHT) {
      buffer[screen_y * WIDTH + screen_x] = 'O';
    }
  }

  // Display buffer
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      putchar(buffer[y * WIDTH + x]);
    }
    putchar('\n');
  }
}

int main() {
  Planet planets[NUM_PLANETS];

  // Set up initial conditions
  planets[0].mass = 1.989E30;
  planets[0].x = 0;
  planets[0].y = 0;
  planets[0].vx = 0;
  planets[0].vy = 0;

  planets[1].mass = 3.3E23;
  planets[1].x = 57.9E9;
  planets[1].y = 0;
  planets[1].vx = 0;
  planets[1].vy = 47.4E3;

  planets[2].mass = 4.87E24;
  planets[2].x = 108.2E9;
  planets[2].y = 0;
  planets[2].vx = 0;
  planets[2].vy = 35E3;

  planets[3].mass = 5.97E24;
  planets[3].x = 149.6E9;
  planets[3].y = 0;
  planets[3].vx = 0;
  planets[3].vy = 29.8E3;

  planets[4].mass = 6.42E23;
  planets[4].x = 227.9E9;
  planets[4].y = 0;
  planets[4].vx = 0;
  planets[4].vy = 24.1E3;

  planets[5].mass = 1.898E27;
  planets[5].x = 778.6E9;
  planets[5].y = 0;
  planets[5].vx = 0;
  planets[5].vy = 13.1E3;

  planets[6].mass = 5.68E26;
  planets[6].x = 1.434E12;
  planets[6].y = 0;
  planets[6].vx = 0;
  planets[6].vy = 9.7E3;

  planets[7].mass = 8.68E25;
  planets[7].x = 2.871E12;
  planets[7].y = 0;
  planets[7].vx = 0;
  planets[7].vy = 6.8E3;

  simulate(planets, TIME_STEP, 1000000);
  draw(planets);

  return 0;
}