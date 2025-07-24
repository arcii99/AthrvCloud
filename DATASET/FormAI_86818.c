//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: rigorous
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11  // Universal Gravitational Constant
#define TIME_STEP 3600.0  // Time Step of 1 hour

typedef struct Vector {  // Vector struct for holding x,y,z coordinates
    double x,y,z;
} Vector;

typedef struct Object {  // Object struct for holding mass, position, and velocity information
    double mass;
    Vector pos,vel;
} Object;

void update_position(Object *obj, double time) {  // Update position of object based on current velocity
    obj->pos.x += obj->vel.x * time;
    obj->pos.y += obj->vel.y * time;
    obj->pos.z += obj->vel.z * time;
}

void update_velocity(Object *obj1, Object *obj2, double time) {  // Update velocity of object based on gravitational force from other object
    double distance = sqrt(pow(obj1->pos.x - obj2->pos.x, 2) + pow(obj1->pos.y - obj2->pos.y, 2) + pow(obj1->pos.z - obj2->pos.z, 2));
    double force = G * obj1->mass * obj2->mass / pow(distance, 2);
    Vector direction = {
        (obj2->pos.x - obj1->pos.x) / distance,
        (obj2->pos.y - obj1->pos.y) / distance,
        (obj2->pos.z - obj1->pos.z) / distance
    };
    obj1->vel.x += direction.x * force / obj1->mass * time;
    obj1->vel.y += direction.y * force / obj1->mass * time;
    obj1->vel.z += direction.z * force / obj1->mass * time;
}

int main() {
    Object sun = {1.989e30, {0,0,0}, {0,0,0}};  // Initialize sun object
    Object earth = {5.972e24, {1.496e11,0,0}, {0,2.9783e4,0}};  // Initialize earth object
    Object moon = {7.342e22, {1.496e11+3.844e8,0,0}, {0,2987,0}};  // Initialize moon object
    
    for (double time = 0.0; time < 31557600.0; time += TIME_STEP) {  // Loop through one year of simulation with 1 hour time steps
        update_velocity(&earth, &sun, TIME_STEP);  // Update velocity of earth based on sun's gravitational force
        update_position(&earth, TIME_STEP);  // Update position of earth based on current velocity
        update_velocity(&moon, &earth, TIME_STEP);  // Update velocity of moon based on earth's gravitational force
        update_velocity(&moon, &sun, TIME_STEP);  // Update velocity of moon based on sun's gravitational force
        update_position(&moon, TIME_STEP);  // Update position of moon based on current velocity
    }
    
    printf("Final position of Earth: (%f, %f, %f)\n", earth.pos.x, earth.pos.y, earth.pos.z);
    printf("Final velocity of Earth: (%f, %f, %f)\n", earth.vel.x, earth.vel.y, earth.vel.z);
    printf("Final position of Moon: (%f, %f, %f)\n", moon.pos.x, moon.pos.y, moon.pos.z);
    printf("Final velocity of Moon: (%f, %f, %f)\n", moon.vel.x, moon.vel.y, moon.vel.z);
    
    return 0;
}