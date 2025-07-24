//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: recursive
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#define PI 3.14159265
#define GRAV 6.6743*pow(10,-11) // Gravitational constant
#define YRS 100000000 // Number of years to simulate
#define DT 86400 // Time step in seconds

struct body{ // Defining a structure to hold the properties of each celestial body
    double x, y;
    double vx, vy;
    double fx, fy;
    double m;
};

typedef struct body BODY; // Typedefining the structure to make it easier to use

void update_acceleration(BODY *bodies, int num_bodies, int i){ // Updating the acceleration of a single body
    double ax = 0, ay = 0; // Initializing the acceleration to 0
    for(int j=0;j<num_bodies;j++){ // Looping through all bodies
        if(i!=j){ // Keeping track of all bodies except itself
            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double r = sqrt(dx*dx + dy*dy);
            ax += GRAV * bodies[j].m * dx / pow(r,3); // Updating acceleration in x direction
            ay += GRAV * bodies[j].m * dy / pow(r,3); // Updating acceleration in y direction
        }
    }
    bodies[i].fx = ax; // Updating the force in x direction
    bodies[i].fy = ay; // Updating the force in y direction
}

void update_velocity(BODY *body, double dt){ // Updating the velocity of a single body
    body->vx += (body->fx / body->m) * dt; // Updating velocity in x direction
    body->vy += (body->fy / body->m) * dt; // Updating velocity in y direction
    return;
}

void update_position(BODY *body, double dt){ // Updating the position of a single body
    body->x += body->vx * dt; // Updating position in x direction
    body->y += body->vy * dt; // Updating position in y direction
    return;
}

void simulate(BODY *bodies, int num_bodies, double dt){ // Main simulation function
    for(int i=0;i<num_bodies;i++){ // Looping through all bodies
        update_acceleration(bodies, num_bodies, i); // Updating acceleration of the current body
        update_velocity(&(bodies[i]), dt); // Updating velocity of the current body
    }
    for(int i=0;i<num_bodies;i++){ // Looping through all bodies again
        update_position(&(bodies[i]), dt); // Updating position of the current body
    }
}

void print_bodies(BODY *bodies, int num_bodies){ // Function to print the properties of all bodies
    for(int i=0;i<num_bodies;i++){ // Looping through all bodies
        printf("Body %d\nPosition: (%lf, %lf)\nVelocity: (%lf, %lf)\nMass: %lf\n\n", i+1, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy, bodies[i].m);
    }
}

int main(){
    srand(time(0)); // To generate different random values each time the program runs
    int num_bodies = 5; // Number of celestial bodies to simulate
    BODY bodies[num_bodies]; // Array of celestial bodies

    // Initializing the properties of each celestial body
    bodies[0].x = 0;
    bodies[0].y = 0;
    bodies[0].vx = 0;
    bodies[0].vy = 0;
    bodies[0].m = pow(10,25);

    bodies[1].x = 1.496*pow(10,11);
    bodies[1].y = 0;
    bodies[1].vx = 0;
    bodies[1].vy = 2.9783*pow(10,4);
    bodies[1].m = pow(10,23);

    bodies[2].x = 2.279*pow(10,11);
    bodies[2].y = 0;
    bodies[2].vx = 0;
    bodies[2].vy = 2.4077*pow(10,4);
    bodies[2].m = pow(10,23);

    bodies[3].x = 0;
    bodies[3].y = 0;
    bodies[3].vx = 30*pow(10,3);
    bodies[3].vy = 0;
    bodies[3].m = pow(10,23);

    bodies[4].x = 0;
    bodies[4].y = 6.371*pow(10,6);
    bodies[4].vx = -2.98*pow(10,4);
    bodies[4].vy = 0;
    bodies[4].m = pow(10,24);

    double year = 0; // Initializing the number of simulated years to 0
    while(year < YRS){ // Looping until the specified number of years have been simulated
        simulate(bodies, num_bodies, DT); // Simulating for one time step
        year += DT/(365*24*3600.0); // Updating the number of simulated years
    }
    print_bodies(bodies, num_bodies); // Printing the properties of all bodies
    return 0;
}