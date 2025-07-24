//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // Gravitational constant
#define DELTA_T 1 // Time step
#define NUM_STARS 3 // Number of stars

typedef struct {
   double x;
   double y;
   double z;
} vector;

typedef struct {
   vector position;
   vector velocity;
   double mass;
} body;

void calculate_forces(body *bodies, vector *forces, int num_bodies) {
   int i, j;
   double distance, magnitude, x_diff, y_diff, z_diff;
   vector direction;

   // Initialize the force vector for each body
   for (i = 0; i < num_bodies; i++) {
      forces[i].x = 0;
      forces[i].y = 0;
      forces[i].z = 0;
   }

   // Calculate the forces between each pair of bodies
   for (i = 0; i < num_bodies; i++) {
      for (j = i + 1; j < num_bodies; j++) {
         // Calculate the distance between the bodies
         x_diff = bodies[i].position.x - bodies[j].position.x;
         y_diff = bodies[i].position.y - bodies[j].position.y;
         z_diff = bodies[i].position.z - bodies[j].position.z;
         distance = sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);

         // Calculate the direction and magnitude of the force
         direction.x = -x_diff / distance;
         direction.y = -y_diff / distance;
         direction.z = -z_diff / distance;
         magnitude = G * bodies[i].mass * bodies[j].mass / (distance * distance);

         // Apply the force to both bodies
         forces[i].x += magnitude * direction.x;
         forces[i].y += magnitude * direction.y;
         forces[i].z += magnitude * direction.z;
         forces[j].x -= magnitude * direction.x;
         forces[j].y -= magnitude * direction.y;
         forces[j].z -= magnitude * direction.z;
      }
   }
}

void update_positions(body *bodies, vector *forces, int num_bodies) {
   int i;
   vector acceleration;

   // Update the velocity and position of each body
   for (i = 0; i < num_bodies; i++) {
      // Calculate the acceleration
      acceleration.x = forces[i].x / bodies[i].mass;
      acceleration.y = forces[i].y / bodies[i].mass;
      acceleration.z = forces[i].z / bodies[i].mass;

      // Update the velocity and position
      bodies[i].velocity.x += acceleration.x * DELTA_T;
      bodies[i].velocity.y += acceleration.y * DELTA_T;
      bodies[i].velocity.z += acceleration.z * DELTA_T;
      bodies[i].position.x += bodies[i].velocity.x * DELTA_T;
      bodies[i].position.y += bodies[i].velocity.y * DELTA_T;
      bodies[i].position.z += bodies[i].velocity.z * DELTA_T;
   }
}

int main() {
   int i, j;
   body bodies[NUM_STARS] = {
      {{1, 0, 0}, {0, 0, 0}, 2e30}, // Sun
      {{0, 1, 0}, {0, 0, 30290}, 6e24}, // Earth
      {{0, 0, 1}, {57830, 0, 0}, 6e24} // Mars
   };
   vector forces[NUM_STARS];

   // Simulate for 10 years
   for (i = 0; i < 365 * 10; i++) {
      calculate_forces(bodies, forces, NUM_STARS);
      update_positions(bodies, forces, NUM_STARS);

      // Print the position of each body
      for (j = 0; j < NUM_STARS; j++) {
         printf("Body %d: x=%f y=%f z=%f\n", j, bodies[j].position.x, bodies[j].position.y, bodies[j].position.z);
      }
   }

   return 0;
}