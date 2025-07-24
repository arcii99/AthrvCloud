//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G_CONST 6.674e-11
#define NUM_OBJECTS 3
#define MAX_ITER 10000
#define TIME_STEP 0.1

struct Vector {        // Structure for 3D Vectors
    double x, y, z;
};

struct Object {        // Structure for Objects with properties
    double mass;
    struct Vector position;
    struct Vector velocity;
};

struct Vector gravitational_force(struct Object obj1, struct Object obj2) {   // Calculates gravitational force between two objects
    double dist, magnitude;
    struct Vector direction;

    dist = sqrt(pow((obj1.position.x - obj2.position.x), 2) + pow((obj1.position.y - obj2.position.y), 2) + pow((obj1.position.z - obj2.position.z), 2));
    magnitude = (G_CONST * obj1.mass * obj2.mass) / pow(dist, 2);
    direction.x = (obj2.position.x - obj1.position.x) / dist;
    direction.y = (obj2.position.y - obj1.position.y) / dist;
    direction.z = (obj2.position.z - obj1.position.z) / dist;

    return (struct Vector) {magnitude * direction.x, magnitude * direction.y, magnitude * direction.z};
}

void update_velocity(struct Object *obj, struct Vector force, double time_step) {  // Updates velocity of an object
    obj->velocity.x += force.x * time_step / obj->mass;
    obj->velocity.y += force.y * time_step / obj->mass;
    obj->velocity.z += force.z * time_step / obj->mass;
}

void update_position(struct Object *obj, double time_step) {  // Updates position of an object
    obj->position.x += obj->velocity.x * time_step;
    obj->position.y += obj->velocity.y * time_step;
    obj->position.z += obj->velocity.z * time_step;
}

void simulate(struct Object *obj_arr, int num_objects, double max_iter, double time_step) {  // Main simulation function
    int iter, i, j;
    struct Vector force;

    for (iter = 0; iter < max_iter; iter++) {
        for (i = 0; i < num_objects; i++) {
            force = (struct Vector) {0, 0, 0};
            for (j = 0; j < num_objects; j++) {
                if (i != j) {
                    force.x += gravitational_force(obj_arr[i], obj_arr[j]).x;
                    force.y += gravitational_force(obj_arr[i], obj_arr[j]).y;
                    force.z += gravitational_force(obj_arr[i], obj_arr[j]).z;
                }
            }
            update_velocity(&obj_arr[i], force, time_step);
        }
        for (i = 0; i < num_objects; i++) {
            update_position(&obj_arr[i], time_step);
        }
    }
}

int main() {   // Example program
    struct Object obj1 = {100, {-100, 0, 0}, {0, 0, 0}};
    struct Object obj2 = {500, {0, 0, 0}, {0, 0, 0}};
    struct Object obj3 = {200, {100, 0, 0}, {0, 0, 0}};
    struct Object obj_arr[NUM_OBJECTS] = {obj1, obj2, obj3};
    int i;

    simulate(obj_arr, NUM_OBJECTS, MAX_ITER, TIME_STEP);

    for (i = 0; i < NUM_OBJECTS; i++) {
        printf("Object %d: position(%.2f, %.2f, %.2f) velocity(%.2f, %.2f, %.2f)\n", i+1, obj_arr[i].position.x, obj_arr[i].position.y, obj_arr[i].position.z, obj_arr[i].velocity.x, obj_arr[i].velocity.y, obj_arr[i].velocity.z);
    }

    return 0;
}