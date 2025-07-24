//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: post-apocalyptic
#include <stdio.h>
#include <math.h>

#define G 6.6743E-11 // Gravitational constant
#define SUN_MASS 1.989E30 // Solar mass

typedef struct {
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
    double mass; // Mass of planet
} Body;

// Function to calculate acceleration between two bodies
void acceleration(Body p1, Body p2, double *ax, double *ay, double *az){
  double rx, ry, rz, r, f;

  // Distance between two bodies
  rx = p2.x - p1.x;
  ry = p2.y - p1.y;
  rz = p2.z - p1.z;
  r = sqrt(rx*rx + ry*ry + rz*rz);

  // Force between two bodies
  f = G*p1.mass*p2.mass/(r*r);

  // Acceleration felt by p1 due to p2
  *ax = f*rx/r/p1.mass;
  *ay = f*ry/r/p1.mass;
  *az = f*rz/r/p1.mass;
}

int main() {
    // Initial Positions and Velocities of Planets (AU and AU/day)
    Body sun    = { 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, SUN_MASS};
    Body mercury= { 0.39, 0.00, 0.00, 0.00, 47.87, 0.00, 0.330E24};
    Body venus  = { 0.72, 0.00, 0.00, 0.00, 35.02, 0.00, 4.87E24};
    Body earth  = { 1.00, 0.00, 0.00, 0.00, 29.78, 0.00, 5.97E24};
    Body mars   = { 1.52, 0.00, 0.00, 0.00, 24.07, 0.00, 0.642E24};
    Body jupiter= { 5.20, 0.00, 0.00, 0.00, 13.07, 0.00, 1898.0E24};
    Body saturn = { 9.58, 0.00, 0.00, 0.00, 9.69, 0.00, 568.0E24};
    Body uranus = {19.18, 0.00, 0.00, 0.00, 6.81, 0.00, 86.8E24};
    Body neptune= {30.07, 0.00, 0.00, 0.00, 5.43, 0.00, 102.0E24};

    // Simulation variables
    double t = 0.0; // Time
    double dt = 3600*24*0.01; // Time Step (1% of a day)
    Body planets[] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};
    const int num_planets = sizeof(planets)/sizeof(Body);
    double ax, ay, az; // Acceleration felt by planet

    // Run Simulation
    while (1) {
        // Print positions of all planets
        printf("%.2f", t);
        for(int i=0; i<num_planets; i++){
          printf(",%.8f,%.8f,%.8f", planets[i].x, planets[i].y, planets[i].z);
        }
        printf("\n");

        // Reset acceleration for each planet
        for(int i=0; i<num_planets; i++){
          planets[i].vx += ax*dt;
          planets[i].vy += ay*dt;
          planets[i].vz += az*dt;
          ax = ay = az = 0.0;
        }

        // Calculate acceleration due to gravity
        for(int i=0; i<num_planets; i++){
          for(int j=i+1; j<num_planets; j++){
            acceleration(planets[i], planets[j], &ax, &ay, &az);
            planets[i].vx += ax*dt;
            planets[i].vy += ay*dt;
            planets[i].vz += az*dt;
            planets[j].vx -= ax*dt;
            planets[j].vy -= ay*dt;
            planets[j].vz -= az*dt;
          }
        }

        // Apply Velocity Changes
        for(int i=0; i<num_planets; i++){
          planets[i].x += planets[i].vx*dt;
          planets[i].y += planets[i].vy*dt;
          planets[i].z += planets[i].vz*dt;
        }

        // Increment time
        t += dt;
    }
    return 0;
}