//FormAI DATASET v1.0 Category: Physics simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant

struct Object {
    char name[20];
    double mass;
    double pos[3];
    double vel[3];
    double acc[3];
};

int main() {
    struct Object objects[3] = {
        {"Object 1", 5000.0, {0.0, 0.0, 0.0}, {50.0, 0.0, 0.0}, {0.0, 0.0, 0.0}},
        {"Object 2", 3000.0, {100.0, 0.0, 0.0}, {0.0, 70.0, 0.0}, {0.0, 0.0, 0.0}},
        {"Object 3", 2000.0, {0.0, 50.0, 0.0}, {20.0, 0.0, 80.0}, {0.0, 0.0, 0.0} }
    };

    int num_objects = sizeof(objects) / sizeof(objects[0]);

    double timestep = 0.1;
    double time = 0.0;

    printf("Time\tObject 1 Position (m)\tObject 2 Position (m)\tObject 3 Position (m)\n");

    while (1) {
        // compute acceleration for each object
        for (int i = 0; i < num_objects; i++) {
            struct Object object1 = objects[i];
            double acc[3] = {0.0, 0.0, 0.0};

            for (int j = 0; j < num_objects; j++) {
                if (i != j) {
                    struct Object object2 = objects[j];

                    double distance = sqrt((object1.pos[0] - object2.pos[0]) * (object1.pos[0] - object2.pos[0]) +
                                           (object1.pos[1] - object2.pos[1]) * (object1.pos[1] - object2.pos[1]) +
                                           (object1.pos[2] - object2.pos[2]) * (object1.pos[2] - object2.pos[2]));

                    double force_magnitude = G * object1.mass * object2.mass / (distance * distance);
                    double force[3] = {force_magnitude * (object2.pos[0] - object1.pos[0]) / distance,
                                       force_magnitude * (object2.pos[1] - object1.pos[1]) / distance,
                                       force_magnitude * (object2.pos[2] - object1.pos[2]) / distance};

                    acc[0] += force[0] / object1.mass;
                    acc[1] += force[1] / object1.mass;
                    acc[2] += force[2] / object1.mass;
                }
            }

            objects[i].acc[0] = acc[0];
            objects[i].acc[1] = acc[1];
            objects[i].acc[2] = acc[2];
        }

        // update position and velocity for each object
        for (int i = 0; i < num_objects; i++) {
            objects[i].vel[0] += objects[i].acc[0] * timestep;
            objects[i].vel[1] += objects[i].acc[1] * timestep;
            objects[i].vel[2] += objects[i].acc[2] * timestep;

            objects[i].pos[0] += objects[i].vel[0] * timestep;
            objects[i].pos[1] += objects[i].vel[1] * timestep;
            objects[i].pos[2] += objects[i].vel[2] * timestep;
        }

        // output position for each object
        printf("%lf\t(%lf, %lf, %lf)\t(%lf, %lf, %lf)\t(%lf, %lf, %lf)\n",
               time, objects[0].pos[0], objects[0].pos[1], objects[0].pos[2],
               objects[1].pos[0], objects[1].pos[1], objects[1].pos[2],
               objects[2].pos[0], objects[2].pos[1], objects[2].pos[2]);

        // sleep for 100 milliseconds
        #ifdef _WIN32
            Sleep(100);
        #else
            usleep(100000);
        #endif

        time += timestep;
    }

    return 0;
}