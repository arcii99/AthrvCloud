//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.674 * pow(10, -11) // gravitational constant
#define DT 1000 // time step - 1 second in milliseconds
#define N 4 // number of planets

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double m; // mass
} planet;

// calculate distance between two planets
double distance(planet p1, planet p2) {
    return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

// calculate gravitational force between two planets
double force(planet p1, planet p2) {
    return G * p1.m * p2.m / pow(distance(p1, p2), 2);
}

// calculate acceleration on a planet due to all other planets
void update_acceleration(int index, planet *planets) {
    double ax = 0, ay = 0;
    for (int i = 0; i < N; i++) {
        if (i != index) {
            double f = force(planets[index], planets[i]);
            ax += f * (planets[i].x - planets[index].x) / distance(planets[index], planets[i]);
            ay += f * (planets[i].y - planets[index].y) / distance(planets[index], planets[i]);
        }
    }
    double acceleration_x = ax / planets[index].m;
    double acceleration_y = ay / planets[index].m;
    planets[index].vx += acceleration_x * DT / 1000;
    planets[index].vy += acceleration_y * DT / 1000;
}

// update position of a planet after time step
void update_position(int index, planet *planets) {
    planets[index].x += planets[index].vx * DT / 1000;
    planets[index].y += planets[index].vy * DT / 1000;
}

// print current positions of all planets
void print_planets(planet *planets) {
    for (int i = 0; i < N; i++) {
        printf("Planet %d:\n x = %f\n y = %f\n\n", i+1, planets[i].x, planets[i].y);
    }
}

int main() {
    planet planets[N];

    // initialise planets
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].m = 5.97 * pow(10, 24); // earth

    planets[1].x = 2 * pow(10, 11);
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = 3 * pow(10, 4);
    planets[1].m = 1.9 * pow(10, 30); // sun

    planets[2].x = 2.5 * pow(10, 11);
    planets[2].y = 0;
    planets[2].vx = 0;
    planets[2].vy = 2 * pow(10, 4);
    planets[2].m = 3.3 * pow(10, 23); // mercury

    planets[3].x = 4 * pow(10, 11);
    planets[3].y = 0;
    planets[3].vx = 0;
    planets[3].vy = 2.5 * pow(10, 4);
    planets[3].m = 6.39 * pow(10, 23); // mars

    // initialise random seed
    srand(time(NULL));

    // simulation loop
    for (int t = 0; t < 100000; t++) {
        for (int i = 0; i < N; i++) {
            update_acceleration(i, planets);
        }
        for (int i = 0; i < N; i++) {
            update_position(i, planets);
        }
        // randomly change mass of earth
        if (t % 10000 == 0) {
            planets[0].m = (double)rand() / RAND_MAX * pow(10, 25);
        }
        // print current position of planets every 10000 time steps
        if (t % 10000 == 0) {
            printf("\nTime: %d seconds\n\n", t+1);
            print_planets(planets);
        }
    }

    return 0;
}