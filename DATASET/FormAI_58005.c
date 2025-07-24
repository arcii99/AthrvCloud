//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: statistical
#include <stdio.h>
#include <math.h>

#define N_PLANETS 3 // number of planets in the solar system
#define G_CONST 6.67430e-11 // gravitational constant
#define TIME_STEP 86400 // time step in seconds (1 day)
#define MAX_TIME_STEPS 365 // maximum number of time steps to simulate

struct planet {
    char *name;
    double mass;
    double radius;
    double x_position;
    double y_position;
    double x_velocity;
    double y_velocity;
};

struct planet planets[N_PLANETS] = {
    {"Earth", 5.972e24, 6.371e6, 1.496e11, 0, 0, 29783},
    {"Mars", 6.39e23, 3.3895e6, 2.279e11, 0, 0, 24007},
    {"Jupiter", 1.898e27, 6.9911e7, 7.785e11, 0, 0, 13069}
};

// function to calculate distance between two planets
double distance(struct planet *p1, struct planet *p2) {
    double x_diff = p2->x_position - p1->x_position;
    double y_diff = p2->y_position - p1->y_position;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

// function to calculate gravitational force between two planets
double force(struct planet *p1, struct planet *p2) {
    double dist = distance(p1, p2);
    return G_CONST * p1->mass * p2->mass / (dist * dist);
}

// function to update velocity and position of a planet
void update_planet(struct planet *p, double force_x, double force_y) {
    double acceleration_x = force_x / p->mass;
    double acceleration_y = force_y / p->mass;
    p->x_velocity += acceleration_x * TIME_STEP;
    p->y_velocity += acceleration_y * TIME_STEP;
    p->x_position += p->x_velocity * TIME_STEP;
    p->y_position += p->y_velocity * TIME_STEP;
}

// function to simulate the solar system for a given number of time steps
void simulate(int n_time_steps) {
    int i, j, t;
    struct planet *p1, *p2;
    double force_x, force_y, dist, f;

    for (t = 0; t < n_time_steps; t++) {
        printf("Time step %d:\n", t);

        for (i = 0; i < N_PLANETS; i++) {
            p1 = &planets[i];
            force_x = force_y = 0;
            
            for (j = 0; j < N_PLANETS; j++) {
                p2 = &planets[j];
                
                if (p1 != p2) {
                    dist = distance(p1, p2);
                    f = force(p1, p2);
                    force_x += f * (p2->x_position - p1->x_position) / dist;
                    force_y += f * (p2->y_position - p1->y_position) / dist;
                }
            }
            
            update_planet(p1, force_x, force_y);
            printf("%s: (%.2e, %.2e)\n", p1->name, p1->x_position, p1->y_position);
        }
    }
}

int main() {
    simulate(MAX_TIME_STEPS);
    return 0;
}