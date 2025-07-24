//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: complex
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.6743e-11 // gravitational constant
#define MAX_STEPS 100000 // maximum simulation steps
#define DT 3600 // time step

// structure to store the properties of a celestial object
typedef struct {
    char name[20];
    double mass;
    double radius;
    double position[3];
    double velocity[3];
    double acceleration[3];
} celestial_object;

int main() {
    // initialize the random seed
    srand(time(NULL));
    
    // create the Sun, Earth and Moon objects
    celestial_object sun, earth, moon;
    
    // set the properties of the Sun
    sprintf(sun.name, "Sun");
    sun.mass = 1.989e+30;
    sun.radius = 696340e+3;
    sun.position[0] = 0;
    sun.position[1] = 0;
    sun.position[2] = 0;
    sun.velocity[0] = 0;
    sun.velocity[1] = 0;
    sun.velocity[2] = 0;
    
    // set the properties of the Earth
    sprintf(earth.name, "Earth");
    earth.mass = 5.972e+24;
    earth.radius = 6371e+3;
    earth.position[0] = 147e+9;
    earth.position[1] = 0;
    earth.position[2] = 0;
    earth.velocity[0] = 0;
    earth.velocity[1] = 30300;
    earth.velocity[2] = 0;
    
    // set the properties of the Moon
    sprintf(moon.name, "Moon");
    moon.mass = 7.342e+22;
    moon.radius = 1737e+3;
    moon.position[0] = earth.position[0] + 3.844e+8;
    moon.position[1] = 0;
    moon.position[2] = 0;
    moon.velocity[0] = 0;
    moon.velocity[1] = earth.velocity[1] + 1022;
    moon.velocity[2] = 0;
    
    // print the initial state of the system
    printf("Initial state:\n");
    printf("%s - x = %.2e, y = %.2e, z = %.2e\n", sun.name, sun.position[0], sun.position[1], sun.position[2]);
    printf("%s - x = %.2e, y = %.2e, z = %.2e\n", earth.name, earth.position[0], earth.position[1], earth.position[2]);
    printf("%s - x = %.2e, y = %.2e, z = %.2e\n", moon.name, moon.position[0], moon.position[1], moon.position[2]);
    
    // simulate the system
    for(int i=0; i<MAX_STEPS; i++) {
        // calculate the acceleration of the Earth due to the Sun's gravity
        double r = sqrt(pow(earth.position[0]-sun.position[0], 2)
                      + pow(earth.position[1]-sun.position[1], 2)
                      + pow(earth.position[2]-sun.position[2], 2));
        double f = G * earth.mass * sun.mass / pow(r, 2);
        earth.acceleration[0] = -f * (earth.position[0]-sun.position[0]) / r / earth.mass;
        earth.acceleration[1] = -f * (earth.position[1]-sun.position[1]) / r / earth.mass;
        earth.acceleration[2] = -f * (earth.position[2]-sun.position[2]) / r / earth.mass;
        
        // calculate the acceleration of the Moon due to the Earth's gravity
        r = sqrt(pow(moon.position[0]-earth.position[0], 2)
               + pow(moon.position[1]-earth.position[1], 2)
               + pow(moon.position[2]-earth.position[2], 2));
        f = G * moon.mass * earth.mass / pow(r, 2);
        moon.acceleration[0] = -f * (moon.position[0]-earth.position[0]) / r / moon.mass + earth.acceleration[0];
        moon.acceleration[1] = -f * (moon.position[1]-earth.position[1]) / r / moon.mass + earth.acceleration[1];
        moon.acceleration[2] = -f * (moon.position[2]-earth.position[2]) / r / moon.mass + earth.acceleration[2];
    
        // update the position and velocity of the Earth and the Moon
        earth.position[0] = earth.position[0] + earth.velocity[0] * DT;
        earth.position[1] = earth.position[1] + earth.velocity[1] * DT;
        earth.position[2] = earth.position[2] + earth.velocity[2] * DT;
        moon.position[0] = moon.position[0] + moon.velocity[0] * DT;
        moon.position[1] = moon.position[1] + moon.velocity[1] * DT;
        moon.position[2] = moon.position[2] + moon.velocity[2] * DT;
        earth.velocity[0] = earth.velocity[0] + earth.acceleration[0] * DT;
        earth.velocity[1] = earth.velocity[1] + earth.acceleration[1] * DT;
        earth.velocity[2] = earth.velocity[2] + earth.acceleration[2] * DT;
        moon.velocity[0] = moon.velocity[0] + moon.acceleration[0] * DT;
        moon.velocity[1] = moon.velocity[1] + moon.acceleration[1] * DT;
        moon.velocity[2] = moon.velocity[2] + moon.acceleration[2] * DT;
        
        // print the state of the system every 365 days
        if(i % (365*24) == 0) {
            printf("Day %d:\n", i/24);
            printf("%s - x = %.2e, y = %.2e, z = %.2e\n", sun.name, sun.position[0], sun.position[1], sun.position[2]);
            printf("%s - x = %.2e, y = %.2e, z = %.2e\n", earth.name, earth.position[0], earth.position[1], earth.position[2]);
            printf("%s - x = %.2e, y = %.2e, z = %.2e\n", moon.name, moon.position[0], moon.position[1], moon.position[2]);
        }
    }
    
    return 0;
}