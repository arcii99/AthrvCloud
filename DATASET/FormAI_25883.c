//FormAI DATASET v1.0 Category: Physics simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.67408e-11   // gravitational constant

typedef struct {
    double x;
    double y;
    double z;
} vector;

typedef struct {
    vector position;
    vector velocity;
    double mass;
} body;

vector calculate_trajectory(body b, double dt, body* all_bodies, int num_bodies) {
    vector acceleration = {0, 0, 0};
    for (int i = 0; i < num_bodies; i++) {
        if (b.position.x == all_bodies[i].position.x
            && b.position.y == all_bodies[i].position.y
            && b.position.z == all_bodies[i].position.z) {
            continue;   // do not calculate acceleration on itself
        }
        double distance = sqrt(pow(b.position.x - all_bodies[i].position.x, 2)
                               + pow(b.position.y - all_bodies[i].position.y, 2)
                               + pow(b.position.z - all_bodies[i].position.z, 2));
        double force = G * b.mass * all_bodies[i].mass / pow(distance, 2);
        acceleration.x += force * (all_bodies[i].position.x - b.position.x) / distance / b.mass;
        acceleration.y += force * (all_bodies[i].position.y - b.position.y) / distance / b.mass;
        acceleration.z += force * (all_bodies[i].position.z - b.position.z) / distance / b.mass;
    }
    vector new_velocity = {b.velocity.x + acceleration.x * dt, b.velocity.y + acceleration.y * dt, b.velocity.z + acceleration.z * dt};
    vector new_position = {b.position.x + new_velocity.x * dt, b.position.y + new_velocity.y * dt, b.position.z + new_velocity.z * dt};
    return new_position;
}

int main(int argc, char** argv) {
    double dt = 0.01;
    int num_bodies = 3;
    body* all_bodies = (body*) malloc(num_bodies * sizeof(body));
    all_bodies[0] = (body) {{0, 0, 0}, {0, 0, 0}, 5.972e24};    // earth
    all_bodies[1] = (body) {{0, 0, 1.496e11}, {29.29e3, 0, 0}, 1.989e30};    // sun
    all_bodies[2] = (body) {{0, 384.4e6, 0}, {1e3, 0, 0}, 7.342e22};    // moon
    for (int i = 0; i < 1000000; i++) {
        for (int j = 0; j < num_bodies; j++) {
            all_bodies[j].position = calculate_trajectory(all_bodies[j], dt, all_bodies, num_bodies);
        }
    }
    printf("final position of earth: (%f, %f, %f)\n", all_bodies[0].position.x, all_bodies[0].position.y, all_bodies[0].position.z);
    printf("final position of sun: (%f, %f, %f)\n", all_bodies[1].position.x, all_bodies[1].position.y, all_bodies[1].position.z);
    printf("final position of moon: (%f, %f, %f)\n", all_bodies[2].position.x, all_bodies[2].position.y, all_bodies[2].position.z);
    free(all_bodies);
    return 0;
}