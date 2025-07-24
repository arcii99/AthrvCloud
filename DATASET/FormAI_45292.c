//FormAI DATASET v1.0 Category: Physics simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define HEIGHT 25
#define WIDTH 60
#define MAX_PARTICLES 200
#define GRAVITY 9.8

// Define particle struct
typedef struct particle {
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
  double time_left;
} Particle;

// Function to generate random double within range
double random_double(double min, double max) {
  return (double)(rand() / (double)RAND_MAX * (max - min) + min);
}

int main() {
  // Create particle array
  Particle particles[MAX_PARTICLES];

  // Seed rand() function
  srand(time(NULL));
  
  // Create initial particles
  int i;
  for (i = 0; i < MAX_PARTICLES; i++) {
    // Set initial position to random point in space
    particles[i].x = random_double(-100, 100);
    particles[i].y = random_double(-100, 100);
    particles[i].z = random_double(-100, 100);
    
    // Set initial velocity to random direction
    double theta = random_double(0, M_PI);
    double phi = random_double(0, 2 * M_PI);
    particles[i].vx = sin(theta) * cos(phi) * random_double(0, 50);
    particles[i].vy = sin(theta) * sin(phi) * random_double(0, 50);
    particles[i].vz = cos(theta) * random_double(0, 50);
    
    // Set initial time left to simulate
    particles[i].time_left = random_double(2, 5);
  }

  // Run simulation
  int j;
  for (j = 0; j < 1000; j++) {
    // Update particle positions and velocities
    for (i = 0; i < MAX_PARTICLES; i++) {
      particles[i].x += particles[i].vx;
      particles[i].y += particles[i].vy;
      particles[i].z += particles[i].vz;
      particles[i].vy -= GRAVITY / 100;
      particles[i].time_left -= 0.01;
    }

    // Draw particles in matrix
    char matrix[HEIGHT][WIDTH];
    int k, l;
    for (k = 0; k < HEIGHT; k++) {
      for (l = 0; l < WIDTH; l++) {
        matrix[k][l] = ' ';
      }
    }
    for (i = 0; i < MAX_PARTICLES; i++) {
      if (particles[i].time_left > 0) {
        int x = (int)(particles[i].x / particles[i].z * 7) + WIDTH / 2;
        int y = (int)(particles[i].y / particles[i].z * 7) + HEIGHT / 2;
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
          matrix[y][x] = '*';
        }
      }
    }

    // Print matrix
    printf("\033[2J\033[%d;%dH", 0, 0);
    for (k = 0; k < HEIGHT; k++) {
      for (l = 0; l < WIDTH; l++) {
        printf("%c", matrix[k][l]);
      }
      printf("\n");
    }

    // Sleep for 10 milliseconds
    usleep(10000);
  }

  return 0;
}