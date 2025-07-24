//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: accurate
#include <stdio.h>

#define G 6.67408e-11   // gravitational constant
#define TIMESTEP 3600   // timestep for simulation

struct planet {
    char name[20];
    double mass;
    double position[3];
    double velocity[3];
    double acceleration[3];
};

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    double dz = z1 - z2;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void calculate_acceleration(struct planet planets[], int num_planets) {
    int i,j;
    double dx,dy,dz,dist,grav_force;
    for (i = 0; i < num_planets; i++) {
        for (j = 0; j < num_planets; j++) {
            if (i == j) {
                continue;
            }
            dx = planets[i].position[0] - planets[j].position[0];
            dy = planets[i].position[1] - planets[j].position[1];
            dz = planets[i].position[2] - planets[j].position[2];
            dist = distance(planets[i].position[0], planets[i].position[1], planets[i].position[2],
                            planets[j].position[0], planets[j].position[1], planets[j].position[2]);
            grav_force = G * planets[i].mass * planets[j].mass / (dist*dist);
            planets[i].acceleration[0] += -grav_force * dx / dist / planets[i].mass;
            planets[i].acceleration[1] += -grav_force * dy / dist / planets[i].mass;
            planets[i].acceleration[2] += -grav_force * dz / dist / planets[i].mass;
        }
    }
}

void update_velocity(struct planet planets[], int num_planets) {
    int i;
    for (i = 0; i < num_planets; i++) {
        planets[i].velocity[0] += planets[i].acceleration[0] * TIMESTEP;
        planets[i].velocity[1] += planets[i].acceleration[1] * TIMESTEP;
        planets[i].velocity[2] += planets[i].acceleration[2] * TIMESTEP;
    }
}

void update_position(struct planet planets[], int num_planets) {
    int i;
    for (i = 0; i < num_planets; i++) {
        planets[i].position[0] += planets[i].velocity[0] * TIMESTEP;
        planets[i].position[1] += planets[i].velocity[1] * TIMESTEP;
        planets[i].position[2] += planets[i].velocity[2] * TIMESTEP;
    }
}

int main() {
    struct planet planets[] = {
        {"Earth", 5.97e24, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        {"Moon", 7.342e22, {384400000, 0, 0}, {0, 1022, 0}, {0, 0, 0}}
    };
    int num_planets = sizeof(planets) / sizeof(struct planet);
    int i,j;
    for (i = 0; i < num_planets; i++) {
        printf("Planet %s\n", planets[i].name);
        printf("Mass: %g kg\n", planets[i].mass);
        printf("Initial position: (%g, %g, %g) m\n", planets[i].position[0], planets[i].position[1], planets[i].position[2]);
        printf("Initial velocity: (%g, %g, %g) m/s\n", planets[i].velocity[0], planets[i].velocity[1], planets[i].velocity[2]);
    }
    for (j = 0; j < 60*60*24*365; j += TIMESTEP) {
        calculate_acceleration(planets, num_planets);
        update_velocity(planets, num_planets);
        update_position(planets, num_planets);
    }
    for (i = 0; i < num_planets; i++) {
        printf("Planet %s\n", planets[i].name);
        printf("Final position: (%g, %g, %g) m\n", planets[i].position[0], planets[i].position[1], planets[i].position[2]);
        printf("Final velocity: (%g, %g, %g) m/s\n", planets[i].velocity[0], planets[i].velocity[1], planets[i].velocity[2]);
    }
    return 0;
}