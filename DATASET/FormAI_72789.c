//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: thoughtful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67e-11             // Universal Gravitational Constant
#define tmax 31536000.0        // Number of seconds in a year
#define step 86400.0           // Time step in seconds
#define numBodies 5            // Number of celestial bodies in the simulation

typedef struct {                // Defining struct for celestial bodies
    char name[20];              // Name of the body
    double mass;                // Mass of the body
    double radius;              // Radius of the body
    double pos[3];              // Position of the body in 3D space
    double vel[3];              // Velocity of the body in 3D space
    double acc[3];              // Acceleration of the body in 3D space
}Body;

void updatePosition(Body* bod, double t){          // Function for updating position
    int i;
    for(i=0; i<3; i++){
        bod->pos[i] += bod->vel[i] * t + 0.5 * bod->acc[i] * t * t;
    }
}

void updateVelocity(Body* bod, double t){          // Function for updating velocity
    int i;
    for(i=0; i<3; i++){
        bod->vel[i] += bod->acc[i] * t;
    }
}

double distance(Body* bod1, Body* bod2){           // Function for calculating distance between two bodies
    double x = bod1->pos[0] - bod2->pos[0];
    double y = bod1->pos[1] - bod2->pos[1];
    double z = bod1->pos[2] - bod2->pos[2];
    return sqrt(x * x + y * y + z * z);
}

double force(Body* bod1, Body* bod2){              // Function for calculating gravitational force between two bodies
    double dist = distance(bod1, bod2);
    double f = (G * bod1->mass * bod2->mass) / (dist * dist);  // Newton's Law of Gravitation
    return f;
}

void updateAcceleration(Body bodies[]){            // Function for updating acceleration of all bodies
    int i, j;
    double f;
    for(i=0; i<numBodies; i++){
        for(j=0; j<numBodies; j++){
            if(i != j){                             // Body should not calculate force on itself
                f = force(&bodies[i], &bodies[j]);
                double x = bodies[j].pos[0] - bodies[i].pos[0];
                double y = bodies[j].pos[1] - bodies[i].pos[1];
                double z = bodies[j].pos[2] - bodies[i].pos[2];
                double dist = distance(&bodies[i], &bodies[j]);
                bodies[i].acc[0] += f * x / (dist * bodies[i].mass);
                bodies[i].acc[1] += f * y / (dist * bodies[i].mass);
                bodies[i].acc[2] += f * z / (dist * bodies[i].mass);
            }
        }
    }
}

void print(Body bodies[]){                          // Function for printing position of all bodies
    int i;
    for(i=0; i<numBodies; i++){
        printf("%s Position: x=%lf y=%lf z=%lf\n", bodies[i].name, bodies[i].pos[0], bodies[i].pos[1], bodies[i].pos[2]);
    }
}

int main(){
    Body bodies[numBodies];                         // Defining celestial bodies
    strcpy(bodies[0].name, "Sun");
    bodies[0].mass = 1.989e30;
    bodies[0].radius = 0;
    bodies[0].pos[0] = 0;
    bodies[0].pos[1] = 0;
    bodies[0].pos[2] = 0;
    bodies[0].vel[0] = 0;
    bodies[0].vel[1] = 0;
    bodies[0].vel[2] = 0;
    bodies[0].acc[0] = 0;
    bodies[0].acc[1] = 0;
    bodies[0].acc[2] = 0;

    strcpy(bodies[1].name, "Mercury");
    bodies[1].mass = 3.285e23;
    bodies[1].radius = 2440e3;
    bodies[1].pos[0] = 0;
    bodies[1].pos[1] = 57909176e3;
    bodies[1].pos[2] = 0;
    bodies[1].vel[0] = 47360;
    bodies[1].vel[1] = 0;
    bodies[1].vel[2] = 0;
    bodies[1].acc[0] = 0;
    bodies[1].acc[1] = 0;
    bodies[1].acc[2] = 0;

    strcpy(bodies[2].name, "Venus");
    bodies[2].mass = 4.867e24;
    bodies[2].radius = 6052e3;
    bodies[2].pos[0] = 0;
    bodies[2].pos[1] = 108208930e3;
    bodies[2].pos[2] = 0;
    bodies[2].vel[0] = 35020;
    bodies[2].vel[1] = 0;
    bodies[2].vel[2] = 0;
    bodies[2].acc[0] = 0;
    bodies[2].acc[1] = 0;
    bodies[2].acc[2] = 0;

    strcpy(bodies[3].name, "Earth");
    bodies[3].mass = 5.972e24;
    bodies[3].radius = 6378e3;
    bodies[3].pos[0] = 149597870e3;
    bodies[3].pos[1] = 0;
    bodies[3].pos[2] = 0;
    bodies[3].vel[0] = 0;
    bodies[3].vel[1] = 29790;
    bodies[3].vel[2] = 0;
    bodies[3].acc[0] = 0;
    bodies[3].acc[1] = 0;
    bodies[3].acc[2] = 0;

    strcpy(bodies[4].name, "Mars");
    bodies[4].mass = 6.39e23;
    bodies[4].radius = 3396e3;
    bodies[4].pos[0] = 0;
    bodies[4].pos[1] = 227936637e3;
    bodies[4].pos[2] = 0;
    bodies[4].vel[0] = 24130;
    bodies[4].vel[1] = 0;
    bodies[4].vel[2] = 0;
    bodies[4].acc[0] = 0;
    bodies[4].acc[1] = 0;
    bodies[4].acc[2] = 0;

    srand(time(0));                // Generate a random initial velocity for the first celestial body
    bodies[0].vel[0] = (double)(rand()) / (RAND_MAX / 10000000) - 5000000;
    bodies[0].vel[1] = (double)(rand()) / (RAND_MAX / 10000000) - 5000000;
    bodies[0].vel[2] = (double)(rand()) / (RAND_MAX / 10000000) - 5000000;

    int t;
    for(t = 0; t <= tmax; t+=step){                // Loop for simulating the solar system for one year
        updateAcceleration(bodies);
        int i;
        for(i=0; i<numBodies; i++){
            updatePosition(&bodies[i], step);
            updateVelocity(&bodies[i], step);
        }
    }

    print(bodies);                  // Print final positions of all celestial bodies

    return 0;
}