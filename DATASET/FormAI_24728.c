//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67430e-11 // gravitational constant
#define SIZE 9 // number of celestial bodies

typedef struct{
    char name[20]; // name of the celestial body
    double mass; // mass of the celestial body in kg
    double x_pos; // x position of the celestial body in meters
    double y_pos; // y position of the celestial body in meters
    double x_vel; // x velocity of the celestial body in meters per second
    double y_vel; // y velocity of the celestial body in meters per second
} CelestialBody;

void initialize_positions(CelestialBody* celestial_bodies){
    // randomly initialize the positions of celestial bodies within a range of -1e11 to +1e11 meters
    double x_pos, y_pos;
    int i;
    srand(time(NULL));
    for(i = 0; i < SIZE; i++){
        x_pos = (double)(rand() % 200000000000 - 100000000000.0);
        y_pos = (double)(rand() % 200000000000 - 100000000000.0);
        celestial_bodies[i].x_pos = x_pos;
        celestial_bodies[i].y_pos = y_pos;
    }
}

void initialize_velocities(CelestialBody* celestial_bodies){
    // set the velocities of all celestial bodies to zero initially
    int i;
    for(i = 0; i < SIZE; i++){
        celestial_bodies[i].x_vel = 0.0;
        celestial_bodies[i].y_vel = 0.0;
    }
}

void simulate(CelestialBody* celestial_bodies, double delta_t){
    int i, j;
    double x_distance, y_distance, distance, force, acceleration, x_acceleration, y_acceleration;
    for(i = 0; i < SIZE; i++){
        x_acceleration = 0.0;
        y_acceleration = 0.0;
        for(j = 0; j < SIZE; j++){
            if(i != j){
                x_distance = celestial_bodies[j].x_pos - celestial_bodies[i].x_pos;
                y_distance = celestial_bodies[j].y_pos - celestial_bodies[i].y_pos;
                distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
                force = G * celestial_bodies[i].mass * celestial_bodies[j].mass / pow(distance, 2);
                acceleration = force / celestial_bodies[i].mass;
                x_acceleration += acceleration * x_distance / distance;
                y_acceleration += acceleration * y_distance / distance;
            }
        }
        celestial_bodies[i].x_vel += x_acceleration * delta_t;
        celestial_bodies[i].y_vel += y_acceleration * delta_t;
        celestial_bodies[i].x_pos += celestial_bodies[i].x_vel * delta_t;
        celestial_bodies[i].y_pos += celestial_bodies[i].y_vel * delta_t;
    }
}

void print_celestial_bodies(CelestialBody* celestial_bodies){
    int i;
    for(i = 0; i < SIZE; i++){
        printf("%s:\n", celestial_bodies[i].name);
        printf("x position: %f meters\n", celestial_bodies[i].x_pos);
        printf("y position: %f meters\n", celestial_bodies[i].y_pos);
        printf("x velocity: %f meters per second\n", celestial_bodies[i].x_vel);
        printf("y velocity: %f meters per second\n\n", celestial_bodies[i].y_vel);
    }
}

int main(){
    CelestialBody sun = {"Sun", 1.989e30, 0.0, 0.0, 0.0, 0.0};
    CelestialBody earth = {"Earth", 5.972e24, 147097074000.0, 0.0, 0.0, 30300.0};
    CelestialBody moon = {"Moon", 7.342e22, 147097074000.0, 384399000.0, -1022.0, 0.0};
    CelestialBody mars = {"Mars", 6.39e23, -206669691235.0, 0.0, 0.0, -24100.0};
    CelestialBody venus = {"Venus", 4.87e24, 108208930000.0, 0.0, 0.0, 35020};
    CelestialBody jupiter = {"Jupiter", 1.898e27, -740679835000.0, 0.0, 0.0, -13070};
    CelestialBody saturn = {"Saturn", 5.68e26, 1353572956000.0, 0.0, 0.0, 9690};
    CelestialBody uranus = {"Uranus", 8.68e25, 2748938461000.0, 0.0, 0.0, -6810};
    CelestialBody neptune = {"Neptune", 1.02e26, 4452940833000.0, 0.0, 0.0, 5430};
    CelestialBody celestial_bodies[SIZE] = {sun, earth, moon, mars, venus, jupiter, saturn, uranus, neptune};

    initialize_positions(celestial_bodies);
    initialize_velocities(celestial_bodies);

    int i;
    double delta_t = 10000.0; // time step in seconds
    for(i = 0; i < 100000; i++){ // run the simulation for 1 million seconds
        simulate(celestial_bodies, delta_t);
        if(i % 100 == 0){
            printf("Iteration %d:\n", i);
            print_celestial_bodies(celestial_bodies);
        }
    }

    return 0;
}