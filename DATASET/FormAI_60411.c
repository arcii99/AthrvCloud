//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Constants */
#define NUM_PLANETS 8
#define G_CONST 6.6743e-11

/* Struct for planets */
typedef struct {
  char name[20];
  double mass;
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
} planet_t;

/* Function to calculate distance between two planets */
double distance(planet_t planet1, planet_t planet2) {
  double dx = planet2.x - planet1.x;
  double dy = planet2.y - planet1.y;
  double dz = planet2.z - planet1.z;
  return sqrt(dx*dx + dy*dy + dz*dz);
}

/* Function to calculate force between two planets */
double force(planet_t planet1, planet_t planet2) {
  double r = distance(planet1, planet2);
  return G_CONST * planet1.mass * planet2.mass / (r*r);
}

/* Function to update velocity of a planet */
void update_velocity(planet_t *planet, planet_t *planets) {
  int i;
  double f_total_x = 0;
  double f_total_y = 0;
  double f_total_z = 0;
  
  for (i = 0; i < NUM_PLANETS; i++) {
    if (&planets[i] != planet) {
      double f = force(*planet, planets[i]);
      double dx = planets[i].x - planet->x;
      double dy = planets[i].y - planet->y;
      double dz = planets[i].z - planet->z;
      f_total_x += f * dx / distance(*planet, planets[i]);
      f_total_y += f * dy / distance(*planet, planets[i]);
      f_total_z += f * dz / distance(*planet, planets[i]);
    }
  }
  
  planet->vx += f_total_x / planet->mass;
  planet->vy += f_total_y / planet->mass;
  planet->vz += f_total_z / planet->mass;
}

/* Function to update position of a planet */
void update_position(planet_t *planet) {
  planet->x += planet->vx;
  planet->y += planet->vy;
  planet->z += planet->vz;
}

int main() {
  planet_t planets[NUM_PLANETS];
  int i, j;
  
  /* Initialize random seed */
  srand(time(NULL));
  
  /* Initialize planets */
  strcpy(planets[0].name, "Sun");
  planets[0].mass = 1.989e30;
  planets[0].x = 0;
  planets[0].y = 0;
  planets[0].z = 0;
  planets[0].vx = 0;
  planets[0].vy = 0;
  planets[0].vz = 0;
  
  strcpy(planets[1].name, "Mercury");
  planets[1].mass = 3.3011e23;
  planets[1].x = 57.91e9;
  planets[1].y = 0;
  planets[1].z = 0;
  planets[1].vx = 0;
  planets[1].vy = 47.87e3;
  planets[1].vz = 0;
  
  strcpy(planets[2].name, "Venus");
  planets[2].mass = 4.8675e24;
  planets[2].x = 108.2e9;
  planets[2].y = 0;
  planets[2].z = 0;
  planets[2].vx = 0;
  planets[2].vy = 35.02e3;
  planets[2].vz = 0;
  
  strcpy(planets[3].name, "Earth");
  planets[3].mass = 5.9742e24;
  planets[3].x = 149.6e9;
  planets[3].y = 0;
  planets[3].z = 0;
  planets[3].vx = 0;
  planets[3].vy = 29.78e3;
  planets[3].vz = 0;
  
  strcpy(planets[4].name, "Mars");
  planets[4].mass = 6.4171e23;
  planets[4].x = 227.9e9;
  planets[4].y = 0;
  planets[4].z = 0;
  planets[4].vx = 0;
  planets[4].vy = 24.07e3;
  planets[4].vz = 0;
  
  strcpy(planets[5].name, "Jupiter");
  planets[5].mass = 1.8982e27;
  planets[5].x = 778.5e9;
  planets[5].y = 0;
  planets[5].z = 0;
  planets[5].vx = 0;
  planets[5].vy = 13.07e3;
  planets[5].vz = 0;
  
  strcpy(planets[6].name, "Saturn");
  planets[6].mass = 5.6834e26;
  planets[6].x = 1.433e12;
  planets[6].y = 0;
  planets[6].z = 0;
  planets[6].vx = 0;
  planets[6].vy = 9.69e3;
  planets[6].vz = 0;
  
  strcpy(planets[7].name, "Uranus");
  planets[7].mass = 8.6810e25;
  planets[7].x = 2.872e12;
  planets[7].y = 0;
  planets[7].z = 0;
  planets[7].vx = 0;
  planets[7].vy = 6.81e3;
  planets[7].vz = 0;
  
  /* Run simulation */
  for (i = 0; i < 100000; i++) {
    for (j = 0; j < NUM_PLANETS; j++) {
      update_velocity(&planets[j], planets);
      update_position(&planets[j]);
    }
  }
  
  /* Print final positions */
  for (i = 0; i < NUM_PLANETS; i++) {
    printf("%s:\n", planets[i].name);
    printf("x = %lf m\n", planets[i].x);
    printf("y = %lf m\n", planets[i].y);
    printf("z = %lf m\n", planets[i].z);
  }
  
  return 0;
}