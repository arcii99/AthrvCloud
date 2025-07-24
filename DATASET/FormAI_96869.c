//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: innovative
#include <stdio.h>
#include <math.h>

#define G 6.674e-11
#define M1 5.972e24
#define M2 7.342e22
#define R 3.844e8

struct Vector {
    double x, y;
};

struct Object {
    struct Vector pos, vel, acc;
    double mass;
};

void update_velocity(struct Object *obj, double dt) {
    obj->vel.x += obj->acc.x * dt;
    obj->vel.y += obj->acc.y * dt;
}

void update_position(struct Object *obj, double dt) {
    obj->pos.x += obj->vel.x * dt;
    obj->pos.y += obj->vel.y * dt;
}

void calculate_acceleration(struct Object *obj1, struct Object *obj2) {
    double dx = obj1->pos.x - obj2->pos.x;
    double dy = obj1->pos.y - obj2->pos.y;
    double distance = sqrt(dx * dx + dy * dy);
    double force = G * obj1->mass * obj2->mass / (distance * distance);
    double acceleration = force / obj1->mass;
    obj1->acc.x += acceleration * dx / distance;
    obj1->acc.y += acceleration * dy / distance;
}

void simulate(struct Object *obj1, struct Object *obj2, double dt, double tmax) {
    for (double t = 0; t <= tmax; t += dt) {
        calculate_acceleration(obj1, obj2);
        calculate_acceleration(obj2, obj1);
        update_velocity(obj1, dt);
        update_velocity(obj2, dt);
        update_position(obj1, dt);
        update_position(obj2, dt);
        printf("Time: %lf s | Object 1 Position: %lf m, %lf m | Object 2 Position: %lf m, %lf m\n", t, obj1->pos.x, obj1->pos.y, obj2->pos.x, obj2->pos.y);
    }
}

int main() {
    struct Object obj1 = {{0, R}, {-1022, 0}, {0, 0}, M1};
    struct Object obj2 = {{R, R}, {0, 1022}, {0, 0}, M2};
    double dt = 1;
    double tmax = 86400;
    simulate(&obj1, &obj2, dt, tmax);
    return 0;
}