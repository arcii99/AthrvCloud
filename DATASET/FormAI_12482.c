//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11
#define DELTA_T 60*60*24

struct planet {
    char name[20];
    double mass;
    double radius;
    double pos[3];
    double vel[3];
    double acc[3];
};

void print_planet(struct planet p) {
    printf("Planet %s:\n", p.name);
    printf("Mass: %lf kg\n", p.mass);
    printf("Radius: %lf m\n", p.radius);
    printf("Position: (%lf, %lf, %lf) m\n", p.pos[0], p.pos[1], p.pos[2]);
    printf("Velocity: (%lf, %lf, %lf) m/s\n", p.vel[0], p.vel[1], p.vel[2]);
    printf("Acceleration: (%lf, %lf, %lf) m/s^2\n", p.acc[0], p.acc[1], p.acc[2]);
}

void update_acceleration(struct planet *p, struct planet planet_list[], int num_planets) {
    double force[3] = {0};
    for (int i = 0; i < num_planets; i++) {
        if (p == &planet_list[i]) continue;
        double distance = sqrt(pow(planet_list[i].pos[0] - p->pos[0], 2) 
                             + pow(planet_list[i].pos[1] - p->pos[1], 2)
                             + pow(planet_list[i].pos[2] - p->pos[2], 2));
        double force_magnitude = G * p->mass * planet_list[i].mass / pow(distance, 2);
        for (int j = 0; j < 3; j++) {
            force[j] += force_magnitude * (planet_list[i].pos[j] - p->pos[j]) / distance;
        }
    }
    for (int i = 0; i < 3; i++) {
        p->acc[i] = force[i] / p->mass;
    }
}

void update_velocity_position(struct planet *p) {
    for (int i = 0; i < 3; i++) {
        p->vel[i] += p->acc[i] * DELTA_T;
        p->pos[i] += p->vel[i] * DELTA_T;
    }
}

int main() {
    int num_planets = 2;
    struct planet planet_list[num_planets];
    strcpy(planet_list[0].name, "Earth");
    planet_list[0].mass = 5.972e24;
    planet_list[0].radius = 6371e3;
    planet_list[0].pos[0] = 0;
    planet_list[0].pos[1] = 0;
    planet_list[0].pos[2] = 0;
    planet_list[0].vel[0] = 0;
    planet_list[0].vel[1] = 0;
    planet_list[0].vel[2] = 0;
    planet_list[0].acc[0] = 0;
    planet_list[0].acc[1] = 0;
    planet_list[0].acc[2] = 0;
    strcpy(planet_list[1].name, "Mars");
    planet_list[1].mass = 6.4171e23;
    planet_list[1].radius = 3389.5e3;
    planet_list[1].pos[0] = 2.067e11;
    planet_list[1].pos[1] = 0;
    planet_list[1].pos[2] = 0;
    planet_list[1].vel[0] = 0;
    planet_list[1].vel[1] = 24078;
    planet_list[1].vel[2] = 0;
    planet_list[1].acc[0] = 0;
    planet_list[1].acc[1] = 0;
    planet_list[1].acc[2] = 0;
    for (int i = 0; i < 365*10; i++) {
        for (int j = 0; j < num_planets; j++) {
            update_acceleration(&planet_list[j], planet_list, num_planets);
        }
        for (int j = 0; j < num_planets; j++) {
            update_velocity_position(&planet_list[j]);
        }
        if (i % 365 == 0) {
            printf("Year %d:\n", i/365);
            for (int j = 0; j < num_planets; j++) {
                print_planet(planet_list[j]);
            }
        }
    }
    return 0;
}