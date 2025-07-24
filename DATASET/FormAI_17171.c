//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: recursive
#include <stdio.h>
#include <math.h>

struct planet {
    char* name;
    double mass; // kg
    double radius; // km
    double x; // position x-axis (AU)
    double y; // position y-axis (AU)
    double vx; // velocity x-axis (km/s)
    double vy; // velocity y-axis (km/s)
};

void print_planet(struct planet* p, int index) {
    printf("Planet %d:\n", index);
    printf("Name: %s\n", p->name);
    printf("Mass: %lf kg\n", p->mass);
    printf("Radius: %lf km\n", p->radius);
    printf("Position: (%lf AU, %lf AU)\n", p->x, p->y);
    printf("Velocity: (%lf km/s, %lf km/s)\n", p->vx, p->vy);
    printf("\n");
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void update_planet_position(struct planet* p, double dt) {
    double x_new = p->x + p->vx * dt;
    double y_new = p->y + p->vy * dt;
    p->x = x_new;
    p->y = y_new;
}

void update_planet_velocity(struct planet p[], int num_planets, int index, double G, double dt) {
    double sum_fx = 0;
    double sum_fy = 0;
    for (int i = 0; i < num_planets; i++) {
        if (i != index) {
            double d = distance(p[index].x, p[index].y, p[i].x, p[i].y);
            double f = G * p[index].mass * p[i].mass / pow(d, 2);
            double fx = f * (p[i].x - p[index].x) / d;
            double fy = f * (p[i].y - p[index].y) / d;
            sum_fx += fx;
            sum_fy += fy;
        }
    }
    p[index].vx += sum_fx / p[index].mass * dt;
    p[index].vy += sum_fy / p[index].mass * dt;
}

void simulate(struct planet p[], int num_planets, double G, double dt, int num_steps) {
    for (int i = 0; i < num_steps; i++) {
        printf("Step %d:\n", i+1);
        for (int j = 0; j < num_planets; j++) {
            update_planet_velocity(p, num_planets, j, G, dt);
            update_planet_position(&p[j], dt);
            print_planet(&p[j], j+1);
        }
        printf("\n");
    }
}

int main() {
    // Simulation parameters
    double G = 6.67430e-11; // N m^2/kg^2
    double dt = 86400; // seconds
    int num_steps = 365; // days
    int num_planets = 3;

    // Initialize planets
    struct planet earth = {"Earth", 5.97237e24, 6371, 1, 0, 0, 29.78};
    struct planet sun = {"Sun", 1.989e30, 696340, 0, 0, 0, 0};
    struct planet mars = {"Mars", 6.4171e23, 3389.5, 1.524, 0, 0, 24.077};

    // Add planets to array
    struct planet planets[] = {earth, sun, mars};

    // Simulate solar system
    simulate(planets, num_planets, G, dt, num_steps);

    return 0;
}