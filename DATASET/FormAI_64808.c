//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: complete
#include <stdio.h>
#include <math.h>

#define G 6.67428e-11 // gravitational constant

typedef struct planet {
    char* name;
    double mass;
    double radius;
    double pos[3];
    double vel[3];
    double acc[3];
} planet;

void initialize_planets(planet* planets, int n) {
    for(int i=0; i<n; i++) {
        printf("Enter the name of planet %d: ", i+1);
        scanf("%s", planets[i].name);
        printf("Enter the mass of planet %d (in kg): ", i+1);
        scanf("%lf", &planets[i].mass);
        printf("Enter the radius of planet %d (in meters): ", i+1);
        scanf("%lf", &planets[i].radius);
        printf("Enter the position of planet %d (in meters separated by space): ", i+1);
        scanf("%lf %lf %lf", &planets[i].pos[0], &planets[i].pos[1], &planets[i].pos[2]);
        printf("Enter the velocity of planet %d (in meters/second separated by space): ", i+1);
        scanf("%lf %lf %lf", &planets[i].vel[0], &planets[i].vel[1], &planets[i].vel[2]);
    }
}

void calculate_gravity(planet* p1, planet* p2, double* force) {
    double distance = sqrt(pow(p1->pos[0]-p2->pos[0], 2) + pow(p1->pos[1]-p2->pos[1], 2) + pow(p1->pos[2]-p2->pos[2], 2));
    double magnitude = G * p1->mass * p2->mass / pow(distance, 2);
    force[0] = magnitude * (p2->pos[0]-p1->pos[0]) / distance;
    force[1] = magnitude * (p2->pos[1]-p1->pos[1]) / distance;
    force[2] = magnitude * (p2->pos[2]-p1->pos[2]) / distance;
}

void update_acceleration(planet* planets, int n) {
    for(int i=0; i<n; i++) {
        double force[3] = {0};
        for(int j=0; j<n; j++) {
            if(i!=j) {
                double f[3] = {0};
                calculate_gravity(&planets[i], &planets[j], f);
                force[0] += f[0];
                force[1] += f[1];
                force[2] += f[2];
            }
        }
        planets[i].acc[0] = force[0] / planets[i].mass;
        planets[i].acc[1] = force[1] / planets[i].mass;
        planets[i].acc[2] = force[2] / planets[i].mass;
    }
}

void update_velocity(planet* planets, double dt, int n) {
    for(int i=0; i<n; i++) {
        planets[i].vel[0] += planets[i].acc[0] * dt;
        planets[i].vel[1] += planets[i].acc[1] * dt;
        planets[i].vel[2] += planets[i].acc[2] * dt;
    }
}

void update_position(planet* planets, double dt, int n) {
    for(int i=0; i<n; i++) {
        planets[i].pos[0] += planets[i].vel[0] * dt + 0.5 * planets[i].acc[0] * pow(dt, 2);
        planets[i].pos[1] += planets[i].vel[1] * dt + 0.5 * planets[i].acc[1] * pow(dt, 2);
        planets[i].pos[2] += planets[i].vel[2] * dt + 0.5 * planets[i].acc[2] * pow(dt, 2);
    }
}

void print_planet_info(planet* planets, int n) {
    for(int i=0; i<n; i++) {
        printf("%s:\nMass: %lf kg\nRadius: %lf m\nPosition: (%lf, %lf, %lf) m\nVelocity: (%lf, %lf, %lf) m/s\nAcceleration: (%lf, %lf, %lf) m/s^2\n", planets[i].name, planets[i].mass, planets[i].radius, planets[i].pos[0], planets[i].pos[1], planets[i].pos[2], planets[i].vel[0], planets[i].vel[1], planets[i].vel[2], planets[i].acc[0], planets[i].acc[1], planets[i].acc[2]);
    }
}

int main() {
    int n;
    printf("Enter the number of planets: ");
    scanf("%d", &n);
    planet planets[n];
    initialize_planets(planets, n);
    double dt;
    printf("Enter the time step (in seconds): ");
    scanf("%lf", &dt);
    double t;
    printf("Enter the total time (in seconds): ");
    scanf("%lf", &t);
    int steps = t/dt;
    for(int i=0; i<steps; i++) {
        printf("Step %d:\n", i+1);
        update_acceleration(planets, n);
        update_velocity(planets, dt, n);
        update_position(planets, dt, n);
        print_planet_info(planets, n);
        printf("\n");
    }
    return 0;
}