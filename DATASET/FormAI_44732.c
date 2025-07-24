//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: modular
#include <stdio.h>
#include <math.h>
#include <time.h>

#define GRAV_CONST 6.674e-11 // gravitational constant
#define YEAR 31557600.0 // Number of seconds in a year

/* Define structs */

typedef struct {
    double x;
    double y;
    double z;
} vector_t;

typedef struct {
    vector_t position;
    vector_t velocity;
    double mass;
} body_t;

/* Define functions */

vector_t calculateForce(body_t a, body_t b) {
    vector_t distance;
    distance.x = b.position.x - a.position.x;
    distance.y = b.position.y - a.position.y;
    distance.z = b.position.z - a.position.z;
    
    double distanceMag = sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
    
    double forceMag = GRAV_CONST * a.mass * b.mass / pow(distanceMag, 2);
    
    vector_t force;
    force.x = forceMag * distance.x / distanceMag;
    force.y = forceMag * distance.y / distanceMag;
    force.z = forceMag * distance.z / distanceMag;
    
    return force;
}

void updateVelocity(body_t *body, vector_t force, double timeStep) {
    body->velocity.x += force.x / body->mass * timeStep;
    body->velocity.y += force.y / body->mass * timeStep;
    body->velocity.z += force.z / body->mass * timeStep;
}

void updatePosition(body_t *body, double timeStep) {
    body->position.x += body->velocity.x * timeStep;
    body->position.y += body->velocity.y * timeStep;
    body->position.z += body->velocity.z * timeStep;
}

int main() {
    srand(time(NULL)); // seed random number generator
    
    /* Define bodies */
    
    int numBodies = 5;
    
    body_t sun;
    sun.position.x = 0;
    sun.position.y = 0;
    sun.position.z = 0;
    sun.mass = 1.989e30;
    sun.velocity.x = 0;
    sun.velocity.y = 0;
    sun.velocity.z = 0;
    
    body_t earth;
    earth.position.x = 1.4710e11;
    earth.position.y = 0;
    earth.position.z = 0;
    earth.mass = 5.972e24;
    earth.velocity.x = 0;
    earth.velocity.y = 2.978e4;
    earth.velocity.z = 0;
    
    body_t moon;
    moon.position.x = 1.4710e11 + 3.843e8;
    moon.position.y = 0;
    moon.position.z = 0;
    moon.mass = 7.342e22;
    moon.velocity.x = 0;
    moon.velocity.y = 2.978e4 + 1.022e3;
    moon.velocity.z = 0;
    
    body_t jupiter;
    jupiter.position.x = 7.407e11;
    jupiter.position.y = 0;
    jupiter.position.z = 0;
    jupiter.mass = 1.898e27;
    jupiter.velocity.x = 0;
    jupiter.velocity.y = 1.306e4;
    jupiter.velocity.z = 0;
    
    body_t saturn;
    saturn.position.x = 1.353e12;
    saturn.position.y = 0;
    saturn.position.z = 0;
    saturn.mass = 5.683e26;
    saturn.velocity.x = 0;
    saturn.velocity.y = 9.692e3;
    saturn.velocity.z = 0;
    
    body_t bodies[numBodies];
    bodies[0] = sun;
    bodies[1] = earth;
    bodies[2] = moon;
    bodies[3] = jupiter;
    bodies[4] = saturn;
    
    /* Run simulation */
    
    double timeStep = 3600 * 24 * 365.25 / 1000; // 1/1000 of a year
    int numSteps = 1000;
    for (int i=0; i<numSteps; i++) {
        
        /* Calculate forces */
        
        vector_t allForces[numBodies];
        for (int a=0; a<numBodies; a++) {
            vector_t totalForce = {0, 0, 0};
            for (int b=0; b<numBodies; b++) {
                if (a != b) {
                    vector_t force = calculateForce(bodies[a], bodies[b]);
                    totalForce.x += force.x;
                    totalForce.y += force.y;
                    totalForce.z += force.z;
                }
            }
            allForces[a] = totalForce;
        }
        
        /* Update velocities and positions */
        
        for (int a=0; a<numBodies; a++) {
            updateVelocity(&bodies[a], allForces[a], timeStep);
            updatePosition(&bodies[a], timeStep);
        }
        
        /* Print positions */
        
        printf("%d: ", i);
        for (int a=0; a<numBodies; a++) {
            printf("(%e, %e, %e) ", bodies[a].position.x, bodies[a].position.y, bodies[a].position.z);
        }
        printf("\n");
    }
    
    return 0;
}