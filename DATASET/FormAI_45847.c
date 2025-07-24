//FormAI DATASET v1.0 Category: Physics simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.674e-11

typedef struct {
    double mass;
    double radius;
    double x, y, z;
    double vx, vy, vz;
} Particle;

int main() {
    int num_particles = 50;
    double time_step = 1.0;
    double radius_max = 100.0;

    Particle particles[num_particles];
    srand(time(NULL));

    // Initialize particles
    for (int i = 0; i < num_particles; i++) {
        particles[i].mass = 1.0 + rand() % 10;
        particles[i].radius = particles[i].mass / 10;
        particles[i].x = rand() % (int)(2 * radius_max) - radius_max;
        particles[i].y = rand() % (int)(2 * radius_max) - radius_max;
        particles[i].z = rand() % (int)(2 * radius_max) - radius_max;
        particles[i].vx = rand() % 10;
        particles[i].vy = rand() % 10;
        particles[i].vz = rand() % 10;
    }

    // Simulation loop
    for (int t = 0; t < 1000; t++) {
        // Compute acceleration for each particle
        for (int i = 0; i < num_particles; i++) {
            double ax = 0, ay = 0, az = 0;
            for (int j = 0; j < num_particles; j++) {
                if (i == j) continue;
                double dx = particles[j].x - particles[i].x;
                double dy = particles[j].y - particles[i].y;
                double dz = particles[j].z - particles[i].z;
                double d = sqrt(dx*dx + dy*dy + dz*dz);
                double f = G * particles[i].mass * particles[j].mass / (d*d);
                ax += f * dx / d;
                ay += f * dy / d;
                az += f * dz / d;
            }
            particles[i].vx += ax * time_step;
            particles[i].vy += ay * time_step;
            particles[i].vz += az * time_step;
        }

        // Update position for each particle
        for (int i = 0; i < num_particles; i++) {
            particles[i].x += particles[i].vx * time_step;
            particles[i].y += particles[i].vy * time_step;
            particles[i].z += particles[i].vz * time_step;
        }

        // Check for collisions and merge particles
        for (int i = 0; i < num_particles; i++) {
            for (int j = i+1; j < num_particles; j++) {
                double dx = particles[i].x - particles[j].x;
                double dy = particles[i].y - particles[j].y;
                double dz = particles[i].z - particles[j].z;
                double d = sqrt(dx*dx + dy*dy + dz*dz);
                if (d < particles[i].radius + particles[j].radius) {
                    double total_mass = particles[i].mass + particles[j].mass;
                    double com_x = (particles[i].mass * particles[i].x + 
                                    particles[j].mass * particles[j].x) / total_mass;
                    double com_y = (particles[i].mass * particles[i].y + 
                                    particles[j].mass * particles[j].y) / total_mass;
                    double com_z = (particles[i].mass * particles[i].z + 
                                    particles[j].mass * particles[j].z) / total_mass;
                    particles[i].mass = total_mass;
                    particles[i].radius = pow(total_mass, 1.0/3) / 10;
                    particles[i].x = com_x;
                    particles[i].y = com_y;
                    particles[i].z = com_z;
                    particles[i].vx = (particles[i].mass * particles[i].vx + 
                                        particles[j].mass * particles[j].vx) / total_mass;
                    particles[i].vy = (particles[i].mass * particles[i].vy + 
                                        particles[j].mass * particles[j].vy) / total_mass;
                    particles[i].vz = (particles[i].mass * particles[i].vz + 
                                        particles[j].mass * particles[j].vz) / total_mass;
                    particles[j] = particles[num_particles-1];
                    num_particles--;
                }
            }
        }

        // Print state of system
        printf("Time: %d\n", t);
        for (int i = 0; i < num_particles; i++) {
            printf("Particle %d: mass=%.2f, radius=%.2f, position=(%.2f,%.2f,%.2f), velocity=(%.2f,%.2f,%.2f)\n",
                i+1, particles[i].mass, particles[i].radius, particles[i].x, particles[i].y, particles[i].z,
                particles[i].vx, particles[i].vy, particles[i].vz);
        }
        printf("\n");
    }

    return 0;
}