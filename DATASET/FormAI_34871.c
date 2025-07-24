//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 0.00000000006673 // gravitational constant
#define DT 86400 // time step (1 day in seconds)
#define NUM_PLANETS 4 // number of planets to simulate
#define MAX_RADIUS 1000000000000 // maximum distance from center of system
#define TWO_PI 6.28318530718 // 2 * pi

typedef struct {
    char name[10];
    double mass; // in kg
    double x; // position in meters
    double y;
    double z;
    double vx; // velocity in meters per second
    double vy;
    double vz;
    double ax; // acceleration in meters per second squared
    double ay;
    double az;
} planet;

double random_double(double min, double max) {
    double range = max - min;
    double scaled = rand() / (double)RAND_MAX;
    return (scaled * range) + min;
}

void calculate_acceleration(planet *p1, planet *p2, double *ax, double *ay, double *az) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);
    double force = (G * p1->mass * p2->mass) / (distance * distance);
    *ax += force * dx / distance / p1->mass;
    *ay += force * dy / distance / p1->mass;
    *az += force * dz / distance / p1->mass;
}

void simulate(planet *planets) {
    int i, j;
    double ax, ay, az;

    for(i=0; i<NUM_PLANETS; i++) {
        ax = 0; ay = 0; az = 0;
        for(j=0; j<NUM_PLANETS; j++) {
            if(i != j) {
                calculate_acceleration(&planets[i], &planets[j], &ax, &ay, &az);
            }
        }
        planets[i].ax = ax;
        planets[i].ay = ay;
        planets[i].az = az;
    }

    for(i=0; i<NUM_PLANETS; i++) {
        planets[i].vx += planets[i].ax * DT;
        planets[i].vy += planets[i].ay * DT;
        planets[i].vz += planets[i].az * DT;
        planets[i].x += planets[i].vx * DT;
        planets[i].y += planets[i].vy * DT;
        planets[i].z += planets[i].vz * DT;
    }
}

void initialize_planet(planet *p) {
    p->mass = random_double(1.0, 100.0) * pow(10, random_double(22, 26));
    p->x = random_double(-MAX_RADIUS, MAX_RADIUS);
    p->y = random_double(-MAX_RADIUS, MAX_RADIUS);
    p->z = random_double(-MAX_RADIUS, MAX_RADIUS);
    double speed = sqrt((G * 2 * pow(10, 30)) / MAX_RADIUS);
    double angle_xy = random_double(0, TWO_PI);
    double angle_z = random_double(-TWO_PI/4, TWO_PI/4);
    p->vx = speed * cos(angle_xy) * cos(angle_z);
    p->vy = speed * sin(angle_xy) * cos(angle_z);
    p->vz = speed * sin(angle_z);
}

void print_planet(planet *p) {
    printf("%-10s %11.4e %14.8e %14.8e %14.8e %14.8e %14.8e %14.8e %14.8e %14.8e\n",
           p->name, p->mass, p->x, p->y, p->z, p->vx, p->vy, p->vz, p->ax, p->ay, p->az);
}

int main() {
    planet planets[NUM_PLANETS];
    int i, j;

    srand(time(NULL));

    for(i=0; i<NUM_PLANETS; i++) {
        sprintf(planets[i].name, "Planet %d", i+1);
        initialize_planet(&planets[i]);
    }

    printf("Starting positions and velocities:\n");
    for(i=0; i<NUM_PLANETS; i++) {
        print_planet(&planets[i]);
    }

    printf("\n");
    printf("Times:\n");
    for(i=0; i<365; i++) {
        simulate(planets);
        printf("%d\n", i+1);
    }

    printf("\n");
    printf("Ending positions and velocities:\n");
    for(i=0; i<NUM_PLANETS; i++) {
        print_planet(&planets[i]);
    }

    return 0;
}