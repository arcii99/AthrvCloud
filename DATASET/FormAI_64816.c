//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define G 6.674e-11 // gravitational constant

struct planet {
    char name[20];
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
};

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2) + pow(z2-z1, 2));
}

void update_velocity(struct planet *p1, struct planet *p2, double t) {
    double force_mag;
    double force_x, force_y, force_z;

    force_mag = G * p1->mass * p2->mass / pow(distance(p1->x, p1->y, p1->z, p2->x, p2->y, p2->z), 2);
    force_x = force_mag * (p2->x - p1->x) / distance(p1->x, p1->y, p1->z, p2->x, p2->y, p2->z);
    force_y = force_mag * (p2->y - p1->y) / distance(p1->x, p1->y, p1->z, p2->x, p2->y, p2->z);
    force_z = force_mag * (p2->z - p1->z) / distance(p1->x, p1->y, p1->z, p2->x, p2->y, p2->z);

    p1->vx += force_x / p1->mass * t;
    p1->vy += force_y / p1->mass * t;
    p1->vz += force_z / p1->mass * t;
}

void update_position(struct planet *p, double t) {
    p->x += p->vx * t;
    p->y += p->vy * t;
    p->z += p->vz * t;
}

int main() {
    int num_planets;
    double sim_time, time_step;

    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);

    struct planet *planets = calloc(num_planets, sizeof(struct planet));

    for (int i=0; i<num_planets; i++) {
        printf("Enter the name of planet %d: ", i+1);
        scanf("%s", planets[i].name);

        printf("Enter the mass of planet %d: ", i+1);
        scanf("%lf", &planets[i].mass);

        printf("Enter the x, y, and z coordinates of planet %d: ", i+1);
        scanf("%lf %lf %lf", &planets[i].x, &planets[i].y, &planets[i].z);

        printf("Enter the x, y, and z components of the velocity of planet %d: ", i+1);
        scanf("%lf %lf %lf", &planets[i].vx, &planets[i].vy, &planets[i].vz);
    }

    printf("Enter the simulation time in seconds: ");
    scanf("%lf", &sim_time);

    printf("Enter the time step in seconds: ");
    scanf("%lf", &time_step);

    int num_steps = sim_time / time_step;

    for (int t=0; t<num_steps; t++) {
        printf("Time: %d seconds\n", t*time_step);

        for (int i=0; i<num_planets; i++) {
            for (int j=i+1; j<num_planets; j++) {
                update_velocity(&planets[i], &planets[j], time_step);
                update_velocity(&planets[j], &planets[i], time_step);
            }
        }

        for (int i=0; i<num_planets; i++) {
            update_position(&planets[i], time_step);

            printf("%s: (%lf, %lf, %lf)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
        }

        printf("\n");
    }

    free(planets);

    return 0;
}