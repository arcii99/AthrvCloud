//FormAI DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <math.h>

#define G 6.67e-11  // Gravitational constant

struct object {
    double mass;
    double pos[3];  // x, y, z positions
    double vel[3];  // x, y, z velocities
};

void update(struct object *obj, double dt, double force[3]) {
    double accel[3] = {force[0] / obj->mass,
                       force[1] / obj->mass,
                       force[2] / obj->mass};
    obj->vel[0] += accel[0] * dt;
    obj->vel[1] += accel[1] * dt;
    obj->vel[2] += accel[2] * dt;
    obj->pos[0] += obj->vel[0] * dt;
    obj->pos[1] += obj->vel[1] * dt;
    obj->pos[2] += obj->vel[2] * dt;
}

double distance(double pos1[3], double pos2[3]) {
    double dx = pos2[0] - pos1[0];
    double dy = pos2[1] - pos1[1];
    double dz = pos2[2] - pos1[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void gravity(struct object *obj1, struct object *obj2, double dt) {
    double dist = distance(obj1->pos, obj2->pos);
    double force = G * obj1->mass * obj2->mass / (dist * dist);
    double unit[3] = {(obj2->pos[0] - obj1->pos[0]) / dist,
                      (obj2->pos[1] - obj1->pos[1]) / dist,
                      (obj2->pos[2] - obj1->pos[2]) / dist};
    double force_vec[3] = {unit[0] * force, unit[1] * force, unit[2] * force};
    double neg_force[3] = {-force_vec[0], -force_vec[1], -force_vec[2]};
    update(obj1, dt, force_vec);
    update(obj2, dt, neg_force);
}

int main() {
    struct object star1 = {5.97e24, {0, 0, 0}, {0, 0, 0}};  // Earth
    struct object star2 = {1.99e30, {1.496e11, 0, 0}, {0, 29783, 0}};  // Sun
    double dt = 60 * 60;  // 1 hour in seconds
    int steps = 365 * 24;  // 1 year in steps
    for (int i = 0; i < steps; i++) {
        gravity(&star1, &star2, dt);
        printf("Step: %d\n", i+1);
        printf("  Earth position: (%.3e, %.3e, %.3e)\n", star1.pos[0], star1.pos[1], star1.pos[2]);
        printf("  Earth velocity: (%.3e, %.3e, %.3e)\n", star1.vel[0], star1.vel[1], star1.vel[2]);
        printf("  Sun position: (%.3e, %.3e, %.3e)\n", star2.pos[0], star2.pos[1], star2.pos[2]);
        printf("  Sun velocity: (%.3e, %.3e, %.3e)\n", star2.vel[0], star2.vel[1], star2.vel[2]);
    }
    return 0;
}