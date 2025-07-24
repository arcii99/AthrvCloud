//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: complex
#include <stdio.h>
#include <math.h>

#define MAX_PLANETS 10 // maximum number of planets
#define G 6.67430e-11   // gravitational constant

struct planet {
   char name[30];
   double mass;
   double x, y; // position
   double vx, vy; // velocity
   double ax, ay; // acceleration
};

int main() {
   struct planet planets[MAX_PLANETS];
   int num_planets = 0, i, j;
   //TODO: prompt user for number and properties of planets
   //TODO: initialize planets array

   double timestep = 0.1, t;
   double radius2, radius, force;
   double ax, ay, fx, fy;

   // main loop
   for (t = 0; t < 10000; t += timestep) {
      // reset accelerations to zero
      for (i = 0; i < num_planets; i++) {
         planets[i].ax = 0;
         planets[i].ay = 0;
      }

      // calculate forces on each planet due to all others
      for (i = 0; i < num_planets; i++) {
         for (j = 0; j < num_planets; j++) {
            if (i == j) continue;
            radius2 = pow(planets[j].x - planets[i].x, 2) + pow(planets[j].y - planets[i].y, 2);
            radius = sqrt(radius2);
            force = G * planets[i].mass * planets[j].mass / radius2;
            fx = force * (planets[j].x - planets[i].x) / radius;
            fy = force * (planets[j].y - planets[i].y) / radius;
            planets[i].ax += fx / planets[i].mass;
            planets[i].ay += fy / planets[i].mass;
         }
      }

      // update velocities and positions
      for (i = 0; i < num_planets; i++) {
         planets[i].vx += planets[i].ax * timestep;
         planets[i].vy += planets[i].ay * timestep;
         planets[i].x += planets[i].vx * timestep;
         planets[i].y += planets[i].vy * timestep;
      }

      //TODO: output current state of all planets
   }
   return 0;
}