//FormAI DATASET v1.0 Category: Physics simulation ; Style: relaxed
#include <stdio.h>
#include <math.h>

//Constants
#define G 6.67408e-11 //gravitational constant
#define T 1 //simulation time step
#define N 100 //number of particles
#define WIDTH 1000 //width of the simulation area
#define HEIGHT 1000 //height of the simulation area

//Structures
typedef struct {
    double x, y; //position
    double vx, vy; //velocity
    double mass; //mass
} Particle;

//Function prototypes
void updatePosition(Particle *p);
void updateVelocity(Particle *p1, Particle *p2);
double distance(Particle p1, Particle p2);

int main() {
    Particle particles[N];
    int i, j, t;

    //Initialize particles
    for (i = 0; i < N; i++) {
        particles[i].x = rand() % WIDTH;
        particles[i].y = rand() % HEIGHT;
        particles[i].vx = rand() % 10;
        particles[i].vy = rand() % 10;
        particles[i].mass = rand() % 10;
    }

    //Simulation loop
    for (t = 0; t < 1000; t++) {
        //Update positions
        for (i = 0; i < N; i++) {
            updatePosition(&particles[i]);
        }

        //Update velocities
        for (i = 0; i < N; i++) {
            for (j = i+1; j < N; j++) {
                updateVelocity(&particles[i], &particles[j]);
            }
        }
    }

    return 0;
}

//Function implementations
void updatePosition(Particle *p) {
    p->x += p->vx * T;
    p->y += p->vy * T;
}

void updateVelocity(Particle *p1, Particle *p2) {
    double d = distance(*p1, *p2);
    double f = G * p1->mass * p2->mass / (d * d);
    double fx = f * (p2->x - p1->x) / d;
    double fy = f * (p2->y - p1->y) / d;
    p1->vx += fx / p1->mass * T;
    p1->vy += fy / p1->mass * T;
    p2->vx -= fx / p2->mass * T;
    p2->vy -= fy / p2->mass * T;
}

double distance(Particle p1, Particle p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}