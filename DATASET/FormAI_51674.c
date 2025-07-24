//FormAI DATASET v1.0 Category: Physics simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11    //Gravitational Constant 
#define MASS 1000     //Mass of the object
#define TIME_INTERVAL 0.1   //time interval for simulation
#define TERMINATION_TIME 10    //time duration for simulation

typedef struct {
    double x, y;     //position coordinates
    double vx, vy;   //velocity components
    double ax, ay;   //acceleration components
} Object;

Object createObject(double x, double y, double vx, double vy) {
    Object object;
    object.x = x;
    object.y = y;
    object.vx = vx;
    object.vy = vy;
    return object;
}

double distance(Object object1, Object object2) {
    double dx = object1.x - object2.x;
    double dy = object1.y - object2.y;
    return sqrt(dx*dx + dy*dy);
}

void calculateAcceleration(Object *object, Object *objects, int n) {
    object->ax = 0;
    object->ay = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (object == &objects[i]) { //skip object if it is itself
            continue;
        }
        double d = distance(*object, objects[i]);
        //calculate acceleration using Newton's law of gravitation
        double a = G * MASS / (d*d);
        object->ax += a * (objects[i].x - object->x) / d;
        object->ay += a * (objects[i].y - object->y) / d;
    }
}

void updateObject(Object *object) {
    //update velocity and position using Euler's method
    object->vx += object->ax * TIME_INTERVAL;
    object->vy += object->ay * TIME_INTERVAL;
    object->x += object->vx * TIME_INTERVAL;
    object->y += object->vy * TIME_INTERVAL;
}

void simulate(Object *objects, int n, double duration) {
    int time_steps = duration / TIME_INTERVAL;
    int i, j, k;
    for (i = 0; i < time_steps; i++) {
        //calculate acceleration for each object
        for (j = 0; j < n; j++) {
            calculateAcceleration(&objects[j], objects, n);
        }
        //update each object's velocity and position
        for (k = 0; k < n; k++) {
            updateObject(&objects[k]);
        }
        //output each object's position for the current time step
        printf("Time: %.1f\n", i*TIME_INTERVAL);
        for (j = 0; j < n; j++) {
            printf("Object %d: x=%.2f, y=%.2f\n", j, objects[j].x, objects[j].y);
        }
        printf("\n");
    }
}

int main() {
    Object objects[3] = {
        createObject(0, 0, 0, 0),
        createObject(1e7, 0, 0, 1e4),
        createObject(0, 1e7, 1e4, 0)
    };

    simulate(objects, 3, TERMINATION_TIME);

    return 0;
}