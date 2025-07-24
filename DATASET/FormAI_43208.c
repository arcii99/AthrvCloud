//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: secure
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

struct planet {
    char name[20];
    double mass; // in kg
    double radius; // in km
    double distance; // in km
    double speed; // in km/s
    double angle; // in radians
};

int main() {
    // create an array of planet objects
    struct planet planets[] = {
        {"Mercury", 3.3011e23, 2439.7, 5.79e7, 47.87, 0},
        {"Venus", 4.8675e24, 6051.8, 1.08e8, 35.02, 0},
        {"Earth", 5.9724e24, 6371.0, 1.496e8, 29.78, 0},
        {"Mars", 6.4171e23, 3389.5, 2.28e8, 24.08, 0},
        {"Jupiter", 1.8982e27, 69911, 7.78e8, 13.07, 0},
        {"Saturn", 5.6834e26, 58232, 1.43e9, 9.69, 0},
        {"Uranus", 8.6810e25, 25362, 2.87e9, 6.81, 0},
        {"Neptune", 1.0243e26, 24622, 4.50e9, 5.43, 0},
        {"Pluto", 1.303e22, 1187, 5.91e9, 4.67, 0}
    };
    int num_planets = sizeof(planets)/sizeof(struct planet);
    
    // set up initial angle for each planet
    for (int i=0; i<num_planets; i++) {
        planets[i].angle = (double)i/num_planets * 2*PI;
    }
    
    // simulation loop
    double time_step = 86400; // in seconds (1 day)
    double time_elapsed = 0;
    while (1) {
        // update angle and position for each planet
        for (int i=0; i<num_planets; i++) {
            double angular_speed = planets[i].speed / planets[i].distance;
            planets[i].angle += angular_speed * time_step;
            double x = planets[i].distance * cos(planets[i].angle);
            double y = planets[i].distance * sin(planets[i].angle);
            printf("%s: (%.2f, %.2f)\n", planets[i].name, x, y);
        }
        
        // update time elapsed
        time_elapsed += time_step;
        printf("Time elapsed: %.2f days\n", time_elapsed/86400);
        
        // wait for user input to continue simulation
        printf("Press enter to continue simulation, or q to quit: ");
        char ch = getchar();
        if (ch == 'q') {
            break;
        }
    }
    
    return 0;
}