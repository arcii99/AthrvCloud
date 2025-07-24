//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define G 6.67408e-11
#define DT 86400

typedef struct {
    double x, y, z;
} Vector;

typedef struct {
    Vector position;
    Vector velocity;
    Vector force;
    double mass;
} Particle;

void calculate_force(Particle particles[]) {
    int i, j;
    double dx, dy, dz, ds;
    double f;

    for (i = 0; i < N; i++) {
        particles[i].force.x = 0.0;
        particles[i].force.y = 0.0;
        particles[i].force.z = 0.0;

        for (j = 0; j < N; j++) {
            if (i != j) {
                dx = particles[j].position.x - particles[i].position.x;
                dy = particles[j].position.y - particles[i].position.y;
                dz = particles[j].position.z - particles[i].position.z;

                ds = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));

                f = G * particles[i].mass * particles[j].mass / pow(ds, 2);

                particles[i].force.x += f * dx / ds;
                particles[i].force.y += f * dy / ds;
                particles[i].force.z += f * dz / ds;
            }
        }
    }
}

void calculate_velocity(Particle particles[]) {
    int i;

    for (i = 0; i < N; i++) {
        particles[i].velocity.x += particles[i].force.x / particles[i].mass * DT;
        particles[i].velocity.y += particles[i].force.y / particles[i].mass * DT;
        particles[i].velocity.z += particles[i].force.z / particles[i].mass * DT;
    }
}

void calculate_position(Particle particles[]) {
    int i;

    for (i = 0; i < N; i++) {
        particles[i].position.x += particles[i].velocity.x * DT;
        particles[i].position.y += particles[i].velocity.y * DT;
        particles[i].position.z += particles[i].velocity.z * DT;
    }
}

void print_particles(Particle particles[]) {
    int i;

    for (i = 0; i < N; i++) {
        printf("Particle %d:\n", i + 1);
        printf("Position: (%lf, %lf, %lf)\n", particles[i].position.x, particles[i].position.y, particles[i].position.z);
        printf("Velocity: (%lf, %lf, %lf)\n", particles[i].velocity.x, particles[i].velocity.y, particles[i].velocity.z);
        printf("Force: (%lf, %lf, %lf)\n", particles[i].force.x, particles[i].force.y, particles[i].force.z);
        printf("Mass: %lf\n", particles[i].mass);
        printf("\n");
    }
}

int main() {
    Particle particles[N] = {
        {{149.6e9, 0, 0}, {0, 0, 0}, {0, 0, 0}, 1.989e30}, // sun
        {{0, 0, 0}, {29.29e3, 0, 0}, {0, 0, 0}, 5.972e24}, // earth
        {{384.4e6, 0, 0}, {0, 1.02e3, 0}, {0, 0, 0}, 7.342e22}, // moon
        {{227.9e9, 0, 0}, {0, 24.077e3, 0}, {0, 0, 0}, 6.39e23}, // mars
        {{778.3e9, 0, 0}, {0, 13.07e3, 0}, {0, 0, 0}, 1.898e27}, // jupiter
        {{1.429e12, 0, 0}, {0, 9.69e3, 0}, {0, 0, 0}, 5.68e26}, // saturn
        {{2.878e12, 0, 0}, {0, 6.81e3, 0}, {0, 0, 0}, 8.68e25}, // uranus
        {{4.498e12, 0, 0}, {0, 5.43e3, 0}, {0, 0, 0}, 1.02e26}, // neptune
        {{5.906e12, 0, 0}, {0, 4.74e3, 0}, {0, 0, 0}, 1.27e22}, // pluto
        {{10e10, 10e10, 10e10}, {0, 0, 0}, {0, 0, 0}, 100} // test particle
    };
    int i;

    for (i = 0; i < 365; i++) {
        calculate_force(particles);
        calculate_velocity(particles);
        calculate_position(particles);
    }

    print_particles(particles);

    return 0;
}