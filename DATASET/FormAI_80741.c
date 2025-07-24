//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// define constants
#define G 6.674e-11 // gravitational constant
#define WIDTH 120 // simulation window width
#define HEIGHT 30 // simulation window height
#define PARTICLES 10 // number of particles to simulate
#define MAX_MASS 100 // maximum particle mass
#define MAX_RADIUS 3 // maximum particle radius
#define MAX_VELOCITY 100 // maximum particle velocity
#define MAX_DISTANCE 50 // maximum distance between particles
#define FRAME_RATE 60 // simulation frame rate

// define a particle structure
struct particle
{
    double x;
    double y;
    double mass;
    double radius;
    double vx;
    double vy;
};

// function to calculate the distance between two particles
double distance(struct particle *p1, struct particle *p2)
{
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

// function to simulate the gravitational force between two particles
void gravitate(struct particle *p1, struct particle *p2)
{
    double d = distance(p1, p2);
    double f = G * p1->mass * p2->mass / (d * d);
    double theta = atan2(p1->y - p2->y, p1->x - p2->x);
    double fx = f * cos(theta);
    double fy = f * sin(theta);
    p1->vx -= fx / p1->mass;
    p1->vy -= fy / p1->mass;
    p2->vx += fx / p2->mass;
    p2->vy += fy / p2->mass;
}

// function to update the simulation state
void update(struct particle *particles, int count)
{
    // apply gravitational forces to all particles
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            gravitate(&particles[i], &particles[j]);
        }
    }

    // update particle positions based on current velocities
    for (int i = 0; i < count; i++)
    {
        particles[i].x += particles[i].vx / FRAME_RATE;
        particles[i].y += particles[i].vy / FRAME_RATE;
    }

    // handle collisions between particles
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (distance(&particles[i], &particles[j]) < particles[i].radius + particles[j].radius)
            {
                double m1 = particles[i].mass;
                double m2 = particles[j].mass;
                double x1 = particles[i].vx;
                double y1 = particles[i].vy;
                double x2 = particles[j].vx;
                double y2 = particles[j].vy;

                // calculate new velocities using conservation of momentum and energy
                particles[i].vx = (m1 * x1 + m2 * x2 - m2 * (x1 - x2)) / (m1 + m2);
                particles[i].vy = (m1 * y1 + m2 * y2 - m2 * (y1 - y2)) / (m1 + m2);
                particles[j].vx = (m1 * x1 + m2 * x2 - m1 * (x2 - x1)) / (m1 + m2);
                particles[j].vy = (m1 * y1 + m2 * y2 - m1 * (y2 - y1)) / (m1 + m2);

                // move particles slightly apart to avoid overlapping
                double overlap = particles[i].radius + particles[j].radius - distance(&particles[i], &particles[j]);
                particles[i].x += overlap / 2 * (particles[i].x - particles[j].x) / distance(&particles[i], &particles[j]);
                particles[i].y += overlap / 2 * (particles[i].y - particles[j].y) / distance(&particles[i], &particles[j]);
                particles[j].x -= overlap / 2 * (particles[i].x - particles[j].x) / distance(&particles[i], &particles[j]);
                particles[j].y -= overlap / 2 * (particles[i].y - particles[j].y) / distance(&particles[i], &particles[j]);
            }
        }
    }
}

// function to draw the current state of the simulation
void draw(struct particle *particles, int count)
{
    char screen[HEIGHT][WIDTH + 1];
    memset(screen, ' ', HEIGHT * (WIDTH + 1));

    // draw particles
    for (int i = 0; i < count; i++)
    {
        int x = particles[i].x * WIDTH / MAX_DISTANCE + WIDTH / 2;
        int y = particles[i].y * HEIGHT / MAX_DISTANCE + HEIGHT / 2;
        int r = particles[i].radius * WIDTH / MAX_DISTANCE;
        if (r < 1) r = 1;
        for (int dx = -r; dx <= r; dx++)
        {
            for (int dy = -r; dy <= r; dy++)
            {
                if (x + dx >= 0 && x + dx < WIDTH && y + dy >= 0 && y + dy < HEIGHT)
                {
                    if (dx * dx + dy * dy <= r * r)
                    {
                        screen[y + dy][x + dx] = '*';
                    }
                }
            }
        }
    }

    // print screen
    for (int y = 0; y < HEIGHT; y++)
    {
        screen[y][WIDTH] = '\0';
        printf("%s\n", screen[y]);
    }
}

int main()
{
    // seed random number generator
    srand(time(NULL));

    // initialize particles with random positions, masses, radii, and velocities
    struct particle particles[PARTICLES];
    for (int i = 0; i < PARTICLES; i++)
    {
        particles[i].x = rand() % (2 * MAX_DISTANCE) - MAX_DISTANCE;
        particles[i].y = rand() % (2 * MAX_DISTANCE) - MAX_DISTANCE;
        particles[i].mass = (double) (rand() % MAX_MASS + 1);
        particles[i].radius = (double) (rand() % MAX_RADIUS + 1);
        particles[i].vx = (double) (rand() % (2 * MAX_VELOCITY) - MAX_VELOCITY);
        particles[i].vy = (double) (rand() % (2 * MAX_VELOCITY) - MAX_VELOCITY);
    }

    // run simulation
    while (true)
    {
        update(particles, PARTICLES);
        draw(particles, PARTICLES);
        usleep(1000000 / FRAME_RATE);
    }

    return 0;
}