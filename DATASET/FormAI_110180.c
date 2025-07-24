//FormAI DATASET v1.0 Category: Physics simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define HEIGHT 20
#define WIDTH 20
#define SIZE 10
#define MASS 1000
#define TEMPERATURE 300
#define COOLING_RATE 0.01
#define BOLTZMANN_CONSTANT 1.38e-23

struct Particle {
    double x, y;
    double vx, vy;
    double ax, ay;
    double force_x, force_y;
};

struct Particle particles[SIZE];
double total_energy, kin_energy, pot_energy;

void update_forces() {
    for (int i = 0; i < SIZE; i++) {
        particles[i].force_x = 0;
        particles[i].force_y = 0;

        for (int j = i+1; j < SIZE; j++) {
            double distance = sqrt(pow(particles[j].x - particles[i].x, 2) + pow(particles[j].y - particles[i].y, 2));
            double force = MASS * MASS / pow(distance, 2);
            particles[i].force_x += force * (particles[j].x - particles[i].x) / distance;
            particles[i].force_y += force * (particles[j].y - particles[i].y) / distance;
            particles[j].force_x -= force * (particles[j].x - particles[i].x) / distance;
            particles[j].force_y -= force * (particles[j].y - particles[i].y) / distance;
        }

        double friction_x = -1 * COOLING_RATE * particles[i].vx;
        double friction_y = -1 * COOLING_RATE * particles[i].vy;

        double thermal_noise_x = sqrt(2 * BOLTZMANN_CONSTANT * TEMPERATURE / MASS) * ((double)rand() / (double)RAND_MAX - 0.5);
        double thermal_noise_y = sqrt(2 * BOLTZMANN_CONSTANT * TEMPERATURE / MASS) * ((double)rand() / (double)RAND_MAX - 0.5);

        particles[i].force_x += friction_x + thermal_noise_x;
        particles[i].force_y += friction_y + thermal_noise_y;
    }
}

void update_positions(double time_step) {
    for (int i = 0; i < SIZE; i++) {
        particles[i].x += particles[i].vx * time_step + 0.5 * particles[i].ax * pow(time_step, 2);
        particles[i].y += particles[i].vy * time_step + 0.5 * particles[i].ay * pow(time_step, 2);
    }
}

void update_velocities(double time_step) {
    for (int i = 0; i < SIZE; i++) {
        particles[i].vx += 0.5 * (particles[i].ax + particles[i].force_x / MASS) * time_step;
        particles[i].vy += 0.5 * (particles[i].ay + particles[i].force_y / MASS) * time_step;
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        particles[i].x = (double)rand() / (double)RAND_MAX * WIDTH;
        particles[i].y = (double)rand() / (double)RAND_MAX * HEIGHT;
        particles[i].vx = 0;
        particles[i].vy = 0;
        particles[i].ax = 0;
        particles[i].ay = 0;
    }

    double time_step = 0.01;
    double simulation_time = 10;
    double time = 0;

    while (time < simulation_time) {
        update_forces();
        update_positions(time_step);
        update_forces();
        update_velocities(time_step);

        kin_energy = 0;
        for (int i = 0; i < SIZE; i++) {
            kin_energy += 0.5 * MASS * (pow(particles[i].vx, 2) + pow(particles[i].vy, 2));
        }

        pot_energy = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = i+1; j < SIZE; j++) {
                double distance = sqrt(pow(particles[j].x - particles[i].x, 2) + pow(particles[j].y - particles[i].y, 2));
                pot_energy -= MASS * MASS / distance;
            }
        }

        total_energy = kin_energy + pot_energy;

        printf("time=%f, total_energy=%f\n", time, total_energy);

        time += time_step;
    }

    return 0;
}