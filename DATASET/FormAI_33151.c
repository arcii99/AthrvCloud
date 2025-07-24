//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.674E-11 // Newton's gravitational constant
#define AU 1.496E11 // Astronomical Unit, the average distance between Earth and the Sun
#define DAY 86400 // Number of seconds in a day

typedef struct {
    char* name; // Name of the planet
    double mass; // Mass of the planet (in kg)
    double radius; // Radius of the planet (in m)
    double distance; // Distance from the Sun (in m)
    double x, y; // Position (in m)
    double vx, vy; // Velocity (in m/s)
} Planet;

void simulateYear(Planet* planets, int numPlanets) {
    for(int i = 0; i < numPlanets; i++) {
        for(int j = i + 1; j < numPlanets; j++) {
            double dx = planets[j].x - planets[i].x;
            double dy = planets[j].y - planets[i].y;
            double d = sqrt(dx*dx + dy*dy);
            double F = G*planets[i].mass*planets[j].mass/(d*d);
            double ax = F/planets[i].mass*dx/d;
            double ay = F/planets[i].mass*dy/d;
            planets[i].vx += ax*DAY;
            planets[i].vy += ay*DAY;
            planets[j].vx -= ax*DAY;
            planets[j].vy -= ay*DAY;
        }
    }
    for(int i = 0; i < numPlanets; i++) {
        planets[i].x += planets[i].vx*DAY;
        planets[i].y += planets[i].vy*DAY;
    }
}

void printPositions(Planet* planets, int numPlanets) {
    for(int i = 0; i < numPlanets; i++) {
        printf("%s: (%.2f, %.2f)\n", planets[i].name, planets[i].x/AU, planets[i].y/AU);
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));
    
    // Create the planets
    Planet sun = {"Sun", 1.989E30, 696340000, 0, 0, 0, 0, 0};
    Planet mercury = {"Mercury", 3.285E23, 2440000, 57909175000, 0, 0, 0, 47000};
    Planet venus = {"Venus", 4.867E24, 6051800, 108208930000, 0, 0, 0, 35000};
    Planet earth = {"Earth", 5.972E24, 6378100, 149597870700, 0, 0, 0, 30000};
    Planet mars = {"Mars", 6.390E23, 3397000, 227936640000, 0, 0, 0, 24000};
    Planet jupiter = {"Jupiter", 1.898E27, 71492000, 778547200000, 0, 0, 0, 13000};
    Planet saturn = {"Saturn", 5.683E26, 60268000, 1429394069000, 0, 0, 0, 9000};
    Planet uranus = {"Uranus", 8.681E25, 25559000, 2870658180000, 0, 0, 0, 6835};
    Planet neptune = {"Neptune", 1.024E26, 24764000, 4498396441000, 0, 0, 0, 5477};
    
    // Put all the planets in an array
    Planet planets[] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};
    int numPlanets = sizeof(planets)/sizeof(Planet);
    
    // Set random initial positions
    for(int i = 1; i < numPlanets; i++) {
        double angle = (double)rand()/RAND_MAX*2*M_PI;
        planets[i].x = planets[i].distance*cos(angle);
        planets[i].y = planets[i].distance*sin(angle);
    }
    
    // Simulate one year
    simulateYear(planets, numPlanets);
    printPositions(planets, numPlanets);
    
    return 0;
}