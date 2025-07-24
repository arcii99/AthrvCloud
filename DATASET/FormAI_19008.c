//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY_CONSTANT 6.6743e-11
#define TIME_STEP 60

struct planet {
    char* name;
    double mass;
    double x_pos;
    double y_pos;
    double x_vel;
    double y_vel;
};

void update_position(struct planet* p) {
    p->x_pos += p->x_vel * TIME_STEP;
    p->y_pos += p->y_vel * TIME_STEP;
}

void update_velocity(struct planet* p, double x_acc, double y_acc) {
    p->x_vel += x_acc * TIME_STEP;
    p->y_vel += y_acc * TIME_STEP;
}

double distance(struct planet* p1, struct planet* p2) {
    double x_dist = p2->x_pos - p1->x_pos;
    double y_dist = p2->y_pos - p1->y_pos;
    return sqrt(x_dist * x_dist + y_dist * y_dist);
}

void gravity_simulation(struct planet* planets, int num_planets) {
    double x_acc[num_planets];
    double y_acc[num_planets];

    for (int i = 0; i < num_planets; i++) {
        x_acc[i] = 0;
        y_acc[i] = 0;
        for (int j = 0; j < num_planets; j++) {
            if (i != j) {
                double dist = distance(&planets[i], &planets[j]);
                double force = GRAVITY_CONSTANT * planets[i].mass * planets[j].mass / (dist * dist);
                double x_force = force * (planets[j].x_pos - planets[i].x_pos) / dist;
                double y_force = force * (planets[j].y_pos - planets[i].y_pos) / dist;

                x_acc[i] += x_force / planets[i].mass;
                y_acc[i] += y_force / planets[i].mass;
            }
        }
        update_velocity(&planets[i], x_acc[i], y_acc[i]);
        update_position(&planets[i]);
    }
}

int main() {
    struct planet planets[3] = {
        {"Earth", 5.97e24, 0, 0, 0, 29783},
        {"Mars", 6.39e23, 2279e6, 0, 0, 24139},
        {"Venus", 4.87e24, 108e6, 0, 0, 35260}
    };

    for (int i = 0; i < 10000; i++) {
        gravity_simulation(planets, 3);
        printf("Time: %d\n", i);
        for (int j = 0; j < 3; j++) {
            printf("%s -- X: %lf Y: %lf\n", planets[j].name, planets[j].x_pos, planets[j].y_pos);
        }
        printf("\n");
    }

    return 0;
}