//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: irregular
#include <stdio.h>
#include <math.h>

#define NUM_PLANETS 8

struct planet {
  char name[20];
  double distance;
  double velocity;
  double angle;
};

struct planet planets[NUM_PLANETS] = {
  {"Mercury", 0.387, 47.87, 0},
  {"Venus", 0.722, 35.02, 0},
  {"Earth", 1.0, 29.78, 0},
  {"Mars", 1.524, 24.07, 0},
  {"Jupiter", 5.203, 13.07, 0},
  {"Saturn", 9.539, 9.69, 0},
  {"Uranus", 19.18, 6.81, 0},
  {"Neptune", 30.07, 5.43, 0}
};

double calc_angle(double distance, double velocity) {
  double period = (2 * M_PI * distance) / velocity;
  return (2 * M_PI) / period;
}

void draw_planet(struct planet p) {
  int r = (int)p.distance;
  int x = r * sin(p.angle);
  int y = r * cos(p.angle);
  printf("%s is at (%d, %d)\n", p.name, x, y);
}

int main() {
  double time = 0.0;
  while (1) {
    time += 0.1;
    for (int i = 0; i < NUM_PLANETS; i++) {
      struct planet p = planets[i];
      p.angle += calc_angle(p.distance, p.velocity) * time;
      draw_planet(p);
    }
    printf("\n");
  }
  return 0;
}