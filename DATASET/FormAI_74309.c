//FormAI DATASET v1.0 Category: Physics simulation ; Style: random
#include <stdio.h>
#include <math.h>

// Define constants
#define G 6.67408 * pow(10, -11)    // Universal gravitational constant
#define DT 0.1                       // Time delta
#define N 2                         // Number of objects in simulation

// Define structures
typedef struct {
    double x;
    double y;
    double z;
} Vec3;

typedef struct {
    Vec3 position;
    Vec3 velocity;
    double mass;
} Object;

// Define function prototypes
Vec3 calcGravity(Object obj1, Object obj2);
void updatePosition(Object *obj, Vec3 acceleration);
void updateVelocity(Object *obj, Vec3 acceleration);

int main() {
    // Define objects
    Object objects[N];

    // Initialize objects
    objects[0].position.x = 0;
    objects[0].position.y = 0;
    objects[0].position.z = 0;
    objects[0].velocity.x = 0;
    objects[0].velocity.y = 0;
    objects[0].velocity.z = 0;
    objects[0].mass = 100;

    objects[1].position.x = 10;
    objects[1].position.y = 0;
    objects[1].position.z = 0;
    objects[1].velocity.x = 0;
    objects[1].velocity.y = sqrt(G * objects[0].mass / objects[1].position.x);
    objects[1].velocity.z = 0;
    objects[1].mass = 50;

    // Run simulation
    int i, j;
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < N; j++) {
            // Calculate gravity on object j
            Vec3 gravity = {0, 0, 0};
            int k;
            for (k = 0; k < N; k++) {
                if (j != k) {
                    Vec3 temp = calcGravity(objects[j], objects[k]);
                    gravity.x += temp.x;
                    gravity.y += temp.y;
                    gravity.z += temp.z;
                }
            }

            // Update position and velocity of object j
            updatePosition(&objects[j], gravity);
            updateVelocity(&objects[j], gravity);
        }
    }

    // Print final object states
    for (i = 0; i < N; i++) {
        printf("Object %d:\n", i);
        printf("Position: (%f, %f, %f)\n", objects[i].position.x, objects[i].position.y, objects[i].position.z);
        printf("Velocity: (%f, %f, %f)\n", objects[i].velocity.x, objects[i].velocity.y, objects[i].velocity.z);
        printf("Mass: %f\n", objects[i].mass);
    }

    return 0;
}

// Calculates the gravitational force on obj1 due to obj2
Vec3 calcGravity(Object obj1, Object obj2) {
    Vec3 r = {obj2.position.x - obj1.position.x, obj2.position.y - obj1.position.y, obj2.position.z - obj1.position.z};
    double distance = sqrt(pow(r.x, 2) + pow(r.y, 2) + pow(r.z, 2));
    double force = G * obj1.mass * obj2.mass / pow(distance, 2);
    Vec3 gravity = {force * r.x / distance, force * r.y / distance, force * r.z / distance};
    return gravity;
}

// Updates the position of obj based on the acceleration due to gravity
void updatePosition(Object *obj, Vec3 acceleration) {
    obj->position.x += obj->velocity.x * DT + 0.5 * acceleration.x * pow(DT, 2);
    obj->position.y += obj->velocity.y * DT + 0.5 * acceleration.y * pow(DT, 2);
    obj->position.z += obj->velocity.z * DT + 0.5 * acceleration.z * pow(DT, 2);
}

// Updates the velocity of obj based on the acceleration due to gravity
void updateVelocity(Object *obj, Vec3 acceleration) {
    obj->velocity.x += acceleration.x * DT;
    obj->velocity.y += acceleration.y * DT;
    obj->velocity.z += acceleration.z * DT;
}