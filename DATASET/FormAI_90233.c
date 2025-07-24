//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLANETS 5

struct planet {
    double x;
    double y;
    double mass;
    double vx;
    double vy;
};

void generate_planets(struct planet *planets) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].x = rand() % 100 + 1;
        planets[i].y = rand() % 100 + 1;
        planets[i].mass = rand() % 100000 + 1;
        planets[i].vx = rand() % 10 + 1;
        planets[i].vy = rand() % 10 + 1;
    }
}

void update_velocity(struct planet *planets) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        double ax = 0.0;
        double ay = 0.0;

        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i != j) {
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double distance = sqrt(dx*dx + dy*dy);
                double force = (planets[i].mass * planets[j].mass) / (distance * distance);

                ax += force * dx / distance;
                ay += force * dy / distance;
            }
        }

        planets[i].vx += ax;
        planets[i].vy += ay;
    }
}

void update_position(struct planet *planets) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].x += planets[i].vx;
        planets[i].y += planets[i].vy;
    }
}

void draw_planets(struct planet *planets) {
    printf("           o\n");
    printf("          ooo\n");
    printf("        oooooo\n");
    printf("       oooooooo\n");
    printf("      ooooooooo\n");

    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: (x=%f, y=%f, m=%f, vx=%f, vy=%f)\n", i+1, planets[i].x, planets[i].y, planets[i].mass, planets[i].vx, planets[i].vy);
    }
}

int main() {
    struct planet planets[NUM_PLANETS];
    srand(time(NULL));
    generate_planets(planets);
    double t = 0.0;

    printf("Welcome to the surreal Planet Gravity Simulation!\n");

    while (t < 100.0) {
        printf("Timestep: %f\n", t);
        draw_planets(planets);
        update_velocity(planets);
        update_position(planets);
        t += 1.0;
    }

    printf("Simulation complete!\n");

    return 0;
}