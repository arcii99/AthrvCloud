//FormAI DATASET v1.0 Category: Physics simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define G 6.67e-11 // gravitational constant

typedef struct Body {
    double mass;
    double x_pos;
    double y_pos;
    double x_vel;
    double y_vel;
    double x_acc;
    double y_acc;
} Body;

// calculate the distance between two bodies
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// calculate the gravitational force acting between two bodies
double gravitational_force(double m1, double m2, double d) {
    return G * m1 * m2 / pow(d, 2);
}

// update the velocity and position of a body
void update_body(Body *body, double time_step) {
    body->x_vel += body->x_acc * time_step;
    body->y_vel += body->y_acc * time_step;
    body->x_pos += body->x_vel * time_step;
    body->y_pos += body->y_vel * time_step;
}

// update the acceleration of a body based on the gravitational forces from other bodies
void update_acceleration(Body *body, Body *bodies, int num_bodies) {
    double net_x_force = 0;
    double net_y_force = 0;

    for (int i = 0; i < num_bodies; i++) {
        if (&bodies[i] != body) { // exclude self-interactions
            double d = distance(body->x_pos, body->y_pos, bodies[i].x_pos, bodies[i].y_pos);
            double f = gravitational_force(body->mass, bodies[i].mass, d);
            double theta = atan2((bodies[i].y_pos - body->y_pos), (bodies[i].x_pos - body->x_pos));
            net_x_force += f * cos(theta);
            net_y_force += f * sin(theta);
        }
    }

    body->x_acc = net_x_force / body->mass;
    body->y_acc = net_y_force / body->mass;
}

int main() {
    int num_bodies = 3;
    Body bodies[num_bodies];

    // set up initial conditions
    bodies[0].mass = 100;
    bodies[0].x_pos = 0;
    bodies[0].y_pos = 0;
    bodies[0].x_vel = 0;
    bodies[0].y_vel = 0;
    bodies[1].mass = 50;
    bodies[1].x_pos = 100;
    bodies[1].y_pos = 0;
    bodies[1].x_vel = 0;
    bodies[1].y_vel = 50;
    bodies[2].mass = 25;
    bodies[2].x_pos = 0;
    bodies[2].y_pos = 100;
    bodies[2].x_vel = 50;
    bodies[2].y_vel = 0;

    double time_step = 0.01;

    for (double t = 0; t < 10; t += time_step) {
        for (int i = 0; i < num_bodies; i++) {
            update_acceleration(&bodies[i], bodies, num_bodies);
        }

        for (int i = 0; i < num_bodies; i++) {
            update_body(&bodies[i], time_step);
        }

        printf("Time: %.2lf\n", t);
        for (int i = 0; i < num_bodies; i++) {
            printf("Body %d: (%.2lf, %.2lf) v = (%.2lf, %.2lf) a = (%.2lf, %.2lf)\n",
                    i, bodies[i].x_pos, bodies[i].y_pos, bodies[i].x_vel, bodies[i].y_vel, bodies[i].x_acc, bodies[i].y_acc);
        }
        printf("\n");
    }

    return 0;
}