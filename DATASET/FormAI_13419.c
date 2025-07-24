//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: inquisitive
#include <stdio.h>
#include <math.h>

#define GRAVITY_CONSTANT 6.67e-11

typedef struct {
    double x;
    double y;
} Position;

typedef struct {
    double mass;
    Position position;
    Position velocity;
} CelestialBody;

void simulate(double deltaT, CelestialBody* bodies, int numBodies) {
    for(int i=0; i<numBodies; i++) {
        for(int j=0; j<numBodies; j++) {
            if(i == j)
                continue;
            
            double distance = sqrt(pow(bodies[j].position.x - bodies[i].position.x, 2) + pow(bodies[j].position.y - bodies[i].position.y, 2));
            double force = (GRAVITY_CONSTANT * bodies[i].mass * bodies[j].mass) / pow(distance, 2);
            double angle = atan2(bodies[j].position.y - bodies[i].position.y, bodies[j].position.x - bodies[i].position.x);
            double forceX = force * cos(angle);
            double forceY = force * sin(angle);

            bodies[i].velocity.x += (forceX / bodies[i].mass) * deltaT;
            bodies[i].velocity.y += (forceY / bodies[i].mass) * deltaT;
        }
    }

    for(int i=0; i<numBodies; i++) {
        bodies[i].position.x += bodies[i].velocity.x * deltaT;
        bodies[i].position.y += bodies[i].velocity.y * deltaT;
    }
}

int main() {
    CelestialBody sun = {.mass=1.989e30, .position={.x=0, .y=0}, .velocity={.x=0, .y=0}};
    CelestialBody earth = {.mass=5.972e24, .position={.x=1.496e11, .y=0}, .velocity={.x=0, .y=2.978e4}};

    CelestialBody bodies[2] = {sun, earth};

    for(int i=0; i<365; i++) {
        printf("Day %d: Earth x=%f y=%f\n", i, earth.position.x, earth.position.y);
        simulate(86400, bodies, 2);
    }

    return 0;
}