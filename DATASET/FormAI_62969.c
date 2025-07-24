//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: all-encompassing
#include <stdio.h>
#include <math.h>
#define G 6.6743E-11 // gravitational constant
#define timestep 60*60*24 // 1 day
#define num_bodies 8 // number of bodies in the simulation

// define the structure for each celestial body
struct Body{
    char name[10];
    double mass;
    double radius;
    double position[3];
    double velocity[3];
    double acceleration[3];
};

int main(){
    struct Body planets[num_bodies]; // array of planets
    double time = 0; // initialize time to 0
    
    // set up solar system
    strcpy(planets[0].name, "Sun");
    planets[0].mass = 1.989E30; // kg
    planets[0].radius = 696340; // km
    planets[0].position[0] = 0;
    planets[0].position[1] = 0;
    planets[0].position[2] = 0;
    planets[0].velocity[0] = 0;
    planets[0].velocity[1] = 0;
    planets[0].velocity[2] = 0;
    
    strcpy(planets[1].name, "Mercury");
    planets[1].mass = 3.285E23; // kg
    planets[1].radius = 2439.7; // km
    planets[1].position[0] = 57910000; // km
    planets[1].position[1] = 0;
    planets[1].position[2] = 0;
    planets[1].velocity[0] = 0;
    planets[1].velocity[1] = 47362; // m/s
    planets[1].velocity[2] = 0;
    
    strcpy(planets[2].name, "Venus");
    planets[2].mass = 4.867E24; // kg
    planets[2].radius = 6051.8; // km
    planets[2].position[0] = 108200000; // km
    planets[2].position[1] = 0;
    planets[2].position[2] = 0;
    planets[2].velocity[0] = 0;
    planets[2].velocity[1] = 35020; // m/s
    planets[2].velocity[2] = 0;
    
    strcpy(planets[3].name, "Earth");
    planets[3].mass = 5.972E24; // kg
    planets[3].radius = 6378.1; // km
    planets[3].position[0] = 147100000; // km
    planets[3].position[1] = 0;
    planets[3].position[2] = 0;
    planets[3].velocity[0] = 0;
    planets[3].velocity[1] = 29783; // m/s
    planets[3].velocity[2] = 0;
    
    strcpy(planets[4].name, "Mars");
    planets[4].mass = 6.39E23; // kg
    planets[4].radius = 3396.2; // km
    planets[4].position[0] = 227900000; // km
    planets[4].position[1] = 0;
    planets[4].position[2] = 0;
    planets[4].velocity[0] = 0;
    planets[4].velocity[1] = 24130; // m/s
    planets[4].velocity[2] = 0;
    
    strcpy(planets[5].name, "Jupiter");
    planets[5].mass = 1.898E27; // kg
    planets[5].radius = 69911; // km
    planets[5].position[0] = 778500000; // km
    planets[5].position[1] = 0;
    planets[5].position[2] = 0;
    planets[5].velocity[0] = 0;
    planets[5].velocity[1] = 13070; // m/s
    planets[5].velocity[2] = 0;
    
    strcpy(planets[6].name, "Saturn");
    planets[6].mass = 5.683E26; // kg
    planets[6].radius = 58232; // km
    planets[6].position[0] = 1433000000; // km
    planets[6].position[1] = 0;
    planets[6].position[2] = 0;
    planets[6].velocity[0] = 0;
    planets[6].velocity[1] = 9670; // m/s
    planets[6].velocity[2] = 0;
    
    strcpy(planets[7].name, "Uranus");
    planets[7].mass = 8.681E25; // kg
    planets[7].radius = 25362; // km
    planets[7].position[0] = 2877000000; // km
    planets[7].position[1] = 0;
    planets[7].position[2] = 0;
    planets[7].velocity[0] = 0;
    planets[7].velocity[1] = 6810; // m/s
    planets[7].velocity[2] = 0;
    
    // simulate motion of planets
    while (time < 365*24*60*60){ // 1 year
        
        // calculate gravitational force between each pair of planets
        for (int i = 0; i < num_bodies; i++){
            for (int j = i+1; j < num_bodies; j++){
                double distance = sqrt(pow(planets[j].position[0] - planets[i].position[0], 2) +
                                       pow(planets[j].position[1] - planets[i].position[1], 2) +
                                       pow(planets[j].position[2] - planets[i].position[2], 2));
                double force = (G * planets[i].mass * planets[j].mass) / pow(distance, 2);
                double direction[3] = {planets[j].position[0] - planets[i].position[0],
                                       planets[j].position[1] - planets[i].position[1],
                                       planets[j].position[2] - planets[i].position[2]};
                double magnitude = sqrt(pow(direction[0], 2) + pow(direction[1], 2) + pow(direction[2], 2));
                direction[0] /= magnitude;
                direction[1] /= magnitude;
                direction[2] /= magnitude;
                planets[i].acceleration[0] += force * direction[0] / planets[i].mass;
                planets[i].acceleration[1] += force * direction[1] / planets[i].mass;
                planets[i].acceleration[2] += force * direction[2] / planets[i].mass;
                planets[j].acceleration[0] -= force * direction[0] / planets[j].mass;
                planets[j].acceleration[1] -= force * direction[1] / planets[j].mass;
                planets[j].acceleration[2] -= force * direction[2] / planets[j].mass;
            }
        }
        
        // update velocity and position of each planet
        for (int i = 0; i < num_bodies; i++){
            for (int j = 0; j < 3; j++){
                planets[i].velocity[j] += planets[i].acceleration[j] * timestep;
                planets[i].position[j] += planets[i].velocity[j] * timestep;
                planets[i].acceleration[j] = 0; // reset acceleration
            }
        }
        
        time += timestep;
    }
    
    // print final positions of planets
    printf("Final positions of planets after 1 year:\n");
    for (int i = 0; i < num_bodies; i++){
        printf("%s: (%.3f, %.3f, %.3f)\n", planets[i].name, planets[i].position[0], planets[i].position[1], planets[i].position[2]);
    }
    
    return 0;
}