//FormAI DATASET v1.0 Category: Physics simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // seed rand() with the current time
   
   int num_particles = 100; // number of particles in our simulation
   double positions[num_particles][3]; // 3D array to store particle positions
   double velocities[num_particles][3]; // 3D array to store particle velocities
   
   // initialize particle positions randomly
   for (int i = 0; i < num_particles; i++) {
      positions[i][0] = (double) rand() / RAND_MAX; // x position
      positions[i][1] = (double) rand() / RAND_MAX; // y position
      positions[i][2] = (double) rand() / RAND_MAX; // z position
   }
   
   // initialize particle velocities randomly
   for (int i = 0; i < num_particles; i++) {
      velocities[i][0] = (double) (rand() % 10) - 5; // x velocity
      velocities[i][1] = (double) (rand() % 10) - 5; // y velocity
      velocities[i][2] = (double) (rand() % 10) - 5; // z velocity
   }
   
   double time_step = 0.1; // time step for our simulation
   
   // simulate the motion of particles for 100 time steps
   for (int t = 0; t < 100; t++) {
      
      // update particle positions based on their velocities
      for (int i = 0; i < num_particles; i++) {
         positions[i][0] += velocities[i][0] * time_step; // update x position
         positions[i][1] += velocities[i][1] * time_step; // update y position
         positions[i][2] += velocities[i][2] * time_step; // update z position
      }
      
      // update particle velocities based on their positions
      for (int i = 0; i < num_particles; i++) {
         // calculate the net force on particle i from all other particles
         double net_force_x = 0;
         double net_force_y = 0;
         double net_force_z = 0;
         for (int j = 0; j < num_particles; j++) {
            if (i != j) {
               // calculate the force between particles i and j using Coulomb's law
               double dx = positions[j][0] - positions[i][0];
               double dy = positions[j][1] - positions[i][1];
               double dz = positions[j][2] - positions[i][2];
               double distance = sqrt(dx*dx + dy*dy + dz*dz);
               double force = 1 / (distance*distance);
               net_force_x += force*dx/distance;
               net_force_y += force*dy/distance;
               net_force_z += force*dz/distance;
            }
         }
         
         // update the velocity of particle i using the net force on it and the time step
         velocities[i][0] += net_force_x * time_step;
         velocities[i][1] += net_force_y * time_step;
         velocities[i][2] += net_force_z * time_step;
      }
   }
   
   // output the final positions and velocities of the particles
   for (int i = 0; i < num_particles; i++) {
      printf("Particle %d: position = (%g, %g, %g), velocity = (%g, %g, %g)\n",
          i+1, positions[i][0], positions[i][1], positions[i][2],
          velocities[i][0], velocities[i][1], velocities[i][2]);
   }
   
   return 0;
}