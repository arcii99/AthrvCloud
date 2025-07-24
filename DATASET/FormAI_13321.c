//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: creative
#include <stdio.h>
#include <math.h>

#define G 6.673e-11
#define SCALE_FACTOR 2

struct Planet {
    double mass;
    double x, y;
    double vx, vy;
};

void update_velocity(struct Planet *planet, double fx, double fy, double timestep)
{
    double ax = fx / planet->mass;
    double ay = fy / planet->mass;
    planet->vx += ax * timestep;
    planet->vy += ay * timestep;
}

void update_position(struct Planet *planet, double timestep)
{
    planet->x += planet->vx * timestep;
    planet->y += planet->vy * timestep;
}

double distance(struct Planet *planet1, struct Planet *planet2)
{
    double dx = planet2->x - planet1->x;
    double dy = planet2->y - planet1->y;
    return sqrt(dx*dx + dy*dy);
}

double force(struct Planet *planet1, struct Planet *planet2)
{
    double r = distance(planet1, planet2);
    return G * planet1->mass * planet2->mass / (r*r);
}

void simulate(struct Planet *planets, int num_planets, double timestep, int num_steps)
{
    for (int step = 0; step < num_steps; step++) {
        for (int i = 0; i < num_planets; i++) {
            double total_fx = 0.0;
            double total_fy = 0.0;
            for (int j = 0; j < num_planets; j++) {
                if (i == j) continue;
                double f = force(&planets[i], &planets[j]);
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double angle = atan2(dy, dx);
                double fx = f * cos(angle);
                double fy = f * sin(angle);
                total_fx += fx;
                total_fy += fy;
            }
            update_velocity(&planets[i], total_fx, total_fy, timestep);
        }
        for (int i = 0; i < num_planets; i++) {
            update_position(&planets[i], timestep);
        }
    }
}

int main()
{
    struct Planet planets[] = {
        // Set up your planets here, e.g.
        { 5.97e24, 0, 0, 0, 0 }, // Earth
        { 3.285e23, 3.844e8 * SCALE_FACTOR, 0, 0, 1022.0 }, // Moon
        { 1.989e30, 1.496e11 * SCALE_FACTOR, 0, 0, -29600.0 } // Sun
    };
    int num_planets = sizeof(planets) / sizeof(struct Planet);

    double timestep = 1.0;
    int num_steps = 365;

    simulate(planets, num_planets, timestep, num_steps);

    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: x=%f y=%f vx=%f vy=%f\n", i, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
    }

    return 0;
}