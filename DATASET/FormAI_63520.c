//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: dynamic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.141592653589793238

// Structure to hold information about the planets
struct planet {
    char name[20];
    double mass;
    double radius;
    double posX;
    double posY;
    double velX;
    double velY;
};

// Global variables
struct planet planets[9];
double G = 6.67430e-11; // universal gravitational constant
double timeStep = 3600.0; // time step in seconds (1 hour)
double totalTime = 31536000.0; // total simulation time in seconds (1 year)
double scale = 1e-11; // scaling factor for the distances

// Function to calculate the distance between two planets
double distance(struct planet p1, struct planet p2) {
    double dx = p1.posX - p2.posX;
    double dy = p1.posY - p2.posY;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate the gravitational force between two planets
double gravitationalForce(struct planet p1, struct planet p2) {
    double r = distance(p1, p2);
    return G*p1.mass*p2.mass/(r*r);
}

// Function to update the velocity and position of a planet based on the gravitational force acting on it
void updatePlanet(int planetIndex) {
    double forceX = 0.0;
    double forceY = 0.0;
    for (int i = 0; i < 9; i++) {
        if (i != planetIndex) {
            double force = gravitationalForce(planets[planetIndex], planets[i]);
            double dx = planets[i].posX - planets[planetIndex].posX;
            double dy = planets[i].posY - planets[planetIndex].posY;
            double angle = atan2(dy, dx);
            forceX += force*cos(angle);
            forceY += force*sin(angle);
        }
    }
    double accelX = forceX/planets[planetIndex].mass;
    double accelY = forceY/planets[planetIndex].mass;
    planets[planetIndex].velX += accelX*timeStep;
    planets[planetIndex].velY += accelY*timeStep;
    planets[planetIndex].posX += planets[planetIndex].velX*timeStep*scale;
    planets[planetIndex].posY += planets[planetIndex].velY*timeStep*scale;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the planets
    struct planet sun = {"Sun", 1.989e30, 696340e3, 0, 0, 0, 0};
    struct planet mercury = {"Mercury", 3.285e23, 2439.7e3, 57.9e9, 0, 0, 47890};
    struct planet venus = {"Venus", 4.867e24, 6051.8e3, 108.2e9, 0, 0, 35020};
    struct planet earth = {"Earth", 5.972e24, 6371.0e3, 149.6e9, 0, 0, 29780};
    struct planet mars = {"Mars", 6.39e23, 3389.5e3, 227.9e9, 0, 0, 24130};
    struct planet jupiter = {"Jupiter", 1.898e27, 69911e3, 778.6e9, 0, 0, 13070};
    struct planet saturn = {"Saturn", 5.683e26, 58232e3, 1433.5e9, 0, 0, 9690};
    struct planet uranus = {"Uranus", 8.681e25, 25362e3, 2872.5e9, 0, 0, 6810};
    struct planet neptune = {"Neptune", 1.024e26, 24622e3, 4495.1e9, 0, 0, 5430};
    planets[0] = sun;
    planets[1] = mercury;
    planets[2] = venus;
    planets[3] = earth;
    planets[4] = mars;
    planets[5] = jupiter;
    planets[6] = saturn;
    planets[7] = uranus;
    planets[8] = neptune;

    // Main simulation loop
    for (double t = 0; t < totalTime; t += timeStep) {
        for (int i = 0; i < 9; i++) {
            updatePlanet(i);
        }
    }

    // Output the final positions of the planets
    printf("Final positions:\n");
    for (int i = 0; i < 9; i++) {
        printf("%s: (%.2f, %.2f) m\n", planets[i].name, planets[i].posX, planets[i].posY);
    }

    return 0;
}