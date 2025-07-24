//FormAI DATASET v1.0 Category: Physics simulation ; Style: future-proof
#include <stdio.h>
#include <math.h>

#define dt 0.01   // time step size
#define G 6.674e-11   // gravitational constant

struct Object {
    double mass;   // mass of the object
    double x, y, z;   // position vector of the object
    double vx, vy, vz;   // velocity vector of the object
};

void update_position(struct Object *obj) {
    obj->x += obj->vx * dt;
    obj->y += obj->vy * dt;
    obj->z += obj->vz * dt;
}

void update_velocity(struct Object *obj, double ax, double ay, double az) {
    obj->vx += ax * dt;
    obj->vy += ay * dt;
    obj->vz += az * dt;
}

double compute_distance(struct Object *obj1, struct Object *obj2) {
    double dx = obj2->x - obj1->x;
    double dy = obj2->y - obj1->y;
    double dz = obj2->z - obj1->z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void simulate(struct Object *objects, int num_objects, int num_steps) {
    int i, j, k;
    double ax, ay, az, r, d, F;

    for (k = 0; k < num_steps; k++) {
        // compute acceleration for each object
        for (i = 0; i < num_objects; i++) {
            ax = 0; ay = 0; az = 0;
            for (j = 0; j < num_objects; j++) {
                if (i == j) continue;
                d = compute_distance(&objects[i], &objects[j]);
                F = G * objects[i].mass * objects[j].mass / (d*d);
                ax += F * (objects[j].x - objects[i].x) / d;
                ay += F * (objects[j].y - objects[i].y) / d;
                az += F * (objects[j].z - objects[i].z) / d;
            }
            update_velocity(&objects[i], ax, ay, az);
        }
        // update position for each object
        for (i = 0; i < num_objects; i++) {
            update_position(&objects[i]);
        }
    }
}

int main() {
    // create objects
    struct Object objects[] = {
        {5.97e24, 0, 0, 0, 0, 0, 0},  // Earth
        {7.34e22, 4e8, 0, 0, 1000, 0, 0}  // Moon
    };
    int num_objects = sizeof(objects)/sizeof(objects[0]);

    // simulate
    int num_steps = 100000;
    simulate(objects, num_objects, num_steps);

    // print final positions
    printf("Final positions:\n");
    for (int i = 0; i < num_objects; i++) {
        printf("Object %d: x=%g y=%g z=%g\n",
            i+1, objects[i].x, objects[i].y, objects[i].z);
    }
    return 0;
}