//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: medieval
#include <stdio.h>
#include <math.h>

#define G 9.81 // gravitational constant

int main() {
  
  // initialization
  double m1, m2, r, F, a1, a2, d, x, y; // m1 and m2 are masses, r is distance, F is force, a1 and a2 are accelerations
  int runs = 100; // number of simulation runs
  int timestep = 1; // time step for simulation
  int i, j;
  
  // user inputs mass and distance values
  printf("Enter mass of planet A: ");
  scanf("%lf", &m1);
  printf("Enter mass of planet B: ");
  scanf("%lf", &m2);
  printf("Enter distance between the planets: ");
  scanf("%lf", &r);
  
  // calculate force of gravitation and accelerations
  F = (G * m1 * m2) / pow(r, 2);
  a1 = F / m1;
  a2 = F / m2;
  
  // simulation loop
  for (i = 0; i < runs; i++) {
    
    // update velocity and position of planets
    x = i * timestep;
    y = a1 * pow(x, 2) / 2;
    d = r - x;
    y += a2 * pow(d, 2) / 2;
    
    // display updated positions
    printf("Planet A position: %lf\n", x);
    printf("Planet B position: %lf\n\n", d);
  }
  
  return 0;
}