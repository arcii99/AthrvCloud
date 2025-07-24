//FormAI DATASET v1.0 Category: Physics simulation ; Style: protected
#include <stdio.h>
#include <math.h>

#define NUM_PARTICLES 10
#define TIME_STEP 0.1

typedef struct {
  double mass;
  double position[3];
  double velocity[3];
} Particle;

void calculate_acceleration(Particle particles[]) {
  for (int i = 0; i < NUM_PARTICLES; i++) {
    double acceleration[3] = {0, 0, 0};

    for (int j = 0; j < NUM_PARTICLES; j++) {
      if (i != j) {
        double distance[3];
        double dist_sq = 0;

        for (int k = 0; k < 3; k++) {
          distance[k] = particles[j].position[k] - particles[i].position[k];
          dist_sq += distance[k] * distance[k];
        }

        double force = particles[j].mass / (dist_sq * sqrt(dist_sq));
        for (int k = 0; k < 3; k++) {
          acceleration[k] += force * distance[k];
        }
      }
    }

    for (int k = 0; k < 3; k++) {
      particles[i].velocity[k] += acceleration[k] * TIME_STEP;
    }
  }
}

void update_positions(Particle particles[]) {
  for (int i = 0; i < NUM_PARTICLES; i++) {
    for (int k = 0; k < 3; k++) {
      particles[i].position[k] += particles[i].velocity[k] * TIME_STEP;
    }
  }
}

void simulate(Particle particles[]) {
  for (int i = 0; i < 1000; i++) {
    calculate_acceleration(particles);
    update_positions(particles);

    // Print the current positions of the particles
    for (int j = 0; j < NUM_PARTICLES; j++) {
      printf("Particle %d position: %lf,%lf,%lf\n", j, particles[j].position[0], particles[j].position[1], particles[j].position[2]);
    }
  }
}

int main() {
  // Initialize the particles
  Particle particles[NUM_PARTICLES];
  for (int i = 0; i < NUM_PARTICLES; i++) {
    particles[i].mass = 1;
    particles[i].position[0] = i;
    particles[i].position[1] = i * 2;
    particles[i].position[2] = 0;
    particles[i].velocity[0] = 0;
    particles[i].velocity[1] = 0;
    particles[i].velocity[2] = 0;
  }

  simulate(particles);

  return 0;
}