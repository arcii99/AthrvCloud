//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NUM_PLANETS 8
#define GRAVITATIONAL_CONSTANT 6.67428e-11

struct vector {
    double x;
    double y;
};

typedef struct planet {
    char name[20];
    double mass;
    double diameter;
    struct vector position;
    struct vector velocity;
} planet;

void initialize_planets(planet planets[]) {
    // Create an array of planet structures with fixed properties
    planet sun = {"Sun", 1989000e24, 1392000, {0, 0}, {0, 0}};
    planet mercury = {"Mercury", 0.33e24, 4878, {57.9e9, 0}, {0, 47.4e3}};
    planet venus = {"Venus", 4.87e24, 12104, {108.2e9, 0}, {0, 35e3}};
    planet earth = {"Earth", 5.97e24, 12756, {147.1e9, 0}, {0, 29.8e3}};
    planet mars = {"Mars", 0.642e24, 6792, {227.9e9, 0}, {0, 24.1e3}};
    planet jupiter = {"Jupiter", 1898e24, 142984, {778.6e9, 0}, {0, 13.1e3}};
    planet saturn = {"Saturn", 568e24, 120536, {1433.5e9, 0}, {0, 9.7e3}};
    planet uranus = {"Uranus", 86.8e24, 51118, {2872.5e9, 0}, {0, 6.8e3}};
    planet neptune = {"Neptune", 102e24, 49528, {4495.1e9, 0}, {0, 5.4e3}};
    
    planets[0] = sun;
    planets[1] = mercury;
    planets[2] = venus;
    planets[3] = earth;
    planets[4] = mars;
    planets[5] = jupiter;
    planets[6] = saturn;
    planets[7] = uranus;
    planets[8] = neptune;    
}

void calculate_net_force(planet planets[], struct vector net_forces[]) {
    // Calculate the net force on each planet
    double distance, magnitude, force_x, force_y;
    for(int i = 1; i < NUM_PLANETS; i++) {
        net_forces[i].x = 0;
        net_forces[i].y = 0;
        for(int j = 0; j < NUM_PLANETS; j++) {
            if(i == j) continue;
            distance = sqrt(pow(planets[i].position.x - planets[j].position.x, 2) + pow(planets[i].position.y - planets[j].position.y, 2));
            magnitude = GRAVITATIONAL_CONSTANT * planets[i].mass * planets[j].mass / pow(distance, 2);
            force_x = magnitude * (planets[j].position.x - planets[i].position.x) / distance;
            force_y = magnitude * (planets[j].position.y - planets[i].position.y) / distance;
            net_forces[i].x += force_x;
            net_forces[i].y += force_y;
        }
    }
}

void update_acceleration_velocity_position(planet planets[], struct vector net_forces[], double time_step) {
    // Update the acceleration, velocity and position of each planet
    struct vector acceleration;
    double velocity_x, velocity_y;
    for(int i = 1; i < NUM_PLANETS; i++) {
        acceleration.x = net_forces[i].x / planets[i].mass;
        acceleration.y = net_forces[i].y / planets[i].mass;
        velocity_x = planets[i].velocity.x + acceleration.x * time_step;
        velocity_y = planets[i].velocity.y + acceleration.y * time_step;
        planets[i].position.x += planets[i].velocity.x * time_step + 0.5 * acceleration.x * pow(time_step, 2);
        planets[i].position.y += planets[i].velocity.y * time_step + 0.5 * acceleration.y * pow(time_step, 2);
        planets[i].velocity.x = velocity_x;
        planets[i].velocity.y = velocity_y;
    }
}

void print_planets(planet planets[]) {
    // Print the name, position and velocity of each planet
    printf("Name\t\tPosition (x, y)\t\tVelocity (x, y)\n");
    for(int i = 0; i < NUM_PLANETS; i++) {
        printf("%s\t\t(%.2f, %.2f)\t\t(%.2f, %.2f)\n", planets[i].name, planets[i].position.x, planets[i].position.y, planets[i].velocity.x, planets[i].velocity.y);
    }
}

int main() {
    planet planets[NUM_PLANETS];
    initialize_planets(planets); 

    double time = 0, time_step = 60 * 60 * 24; // simulate 1 day at a time

    struct vector net_forces[NUM_PLANETS];

    while(time < 10 * 365.25 * 24 * 60 * 60) { // simulate 10 years
        calculate_net_force(planets, net_forces);
        update_acceleration_velocity_position(planets, net_forces, time_step);
        print_planets(planets);
        time += time_step;
    }

    return 0;
}