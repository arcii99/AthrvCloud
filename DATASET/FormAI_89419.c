//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Alan Touring
#include <stdio.h>
#include <math.h>

#define MAX_OBJECTS 10
#define G 6.67e-11

struct Object {
    double mass;
    double pos[3];
    double vel[3];
    double acc[3];
};

struct Object objects[MAX_OBJECTS];
int num_objects;

void update_acceleration()
{
    for (int i = 0; i < num_objects; i++) {
        objects[i].acc[0] = 0;
        objects[i].acc[1] = 0;
        objects[i].acc[2] = 0;

        for (int j = 0; j < num_objects; j++) {
            if (i == j)
                continue;

            double dr[3];
            double distance;

            for (int k = 0; k < 3; k++) {
                dr[k] = objects[j].pos[k] - objects[i].pos[k];
            }

            distance = sqrt(dr[0] * dr[0] + dr[1] * dr[1] + dr[2] * dr[2]);

            double force;
            force = G * objects[i].mass * objects[j].mass / (distance * distance);

            for (int k = 0; k < 3; k++) {
                objects[i].acc[k] += force * dr[k] / distance / objects[i].mass;
            }
        }
    }
}

void update_position(double dt)
{
    for (int i = 0; i < num_objects; i++) {
        for (int k = 0; k < 3; k++) {
            objects[i].vel[k] += objects[i].acc[k] * dt;
            objects[i].pos[k] += objects[i].vel[k] * dt;
        }
    }
}

int main()
{
    num_objects = 2;

    objects[0].mass = 5.97e24;  // mass of earth
    objects[0].pos[0] = 0;
    objects[0].pos[1] = 0;
    objects[0].pos[2] = 0;
    objects[0].vel[0] = 0;
    objects[0].vel[1] = 0;
    objects[0].vel[2] = 0;

    objects[1].mass = 7.35e22;  // mass of moon
    objects[1].pos[0] = 3.85e8;
    objects[1].pos[1] = 0;
    objects[1].pos[2] = 0;
    objects[1].vel[0] = 0;
    objects[1].vel[1] = 1e3;
    objects[1].vel[2] = 0;

    double dt = 1e3;
    for (int i = 0; i < 1000; i++) {
        update_acceleration();
        update_position(dt);
        printf("%lf %lf %lf\n", objects[0].pos[0], objects[0].pos[1], objects[0].pos[2]);
        printf("%lf %lf %lf\n", objects[1].pos[0], objects[1].pos[1], objects[1].pos[2]);
    }

    return 0;
}