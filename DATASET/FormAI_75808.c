//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Dennis Ritchie
#include<stdio.h>
#include<math.h>

#define G 0.00000000006674

struct planet{
    double mass;
    double radius;
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;
};

double calculate_distance(struct planet p1, struct planet p2){
    double distance;
    distance = sqrt(pow((p1.pos_x - p2.pos_x), 2) + pow((p1.pos_y - p2.pos_y), 2));
    return distance;
}

void calculate_force(struct planet *p1, struct planet *p2){
    double distance;
    double force;

    distance = calculate_distance(*p1, *p2);
    force = (G * p1->mass * p2->mass) / pow(distance, 2);

    // Finding direction of force
    double angle = atan2(p1->pos_y-p2->pos_y, p1->pos_x-p2->pos_x);
    double f_x = force * cos(angle);
    double f_y = force * sin(angle);

    // Updating Velocity
    p1->vel_x -= f_x / p1->mass;
    p1->vel_y -= f_y / p1->mass;
    p2->vel_x += f_x / p2->mass;
    p2->vel_y += f_y / p2->mass;
}

void update_position(struct planet *p, int t){
    p->pos_x += p->vel_x * t;
    p->pos_y += p->vel_y * t;
}

int main(){
    struct planet p[3];

    // Setting the mass, radius, position and velocity of first planet
    p[0].mass = 5.972 * pow(10, 24);
    p[0].radius = 6400000;
    p[0].pos_x = 0;
    p[0].pos_y = 0;
    p[0].vel_x = 0;
    p[0].vel_y = 0;

    // Setting the mass, radius, position and velocity of second planet
    p[1].mass = 7.342 * pow(10, 22);
    p[1].radius = 1737000;
    p[1].pos_x = 384400000;
    p[1].pos_y = 0;
    p[1].vel_x = 0;
    p[1].vel_y = 1022;

    // Setting the mass, radius, position and velocity of third planet
    p[2].mass = 1.989 * pow(10, 30);
    p[2].radius = 695500000;
    p[2].pos_x = 0;
    p[2].pos_y = 149600000000;
    p[2].vel_x = 29783;
    p[2].vel_y = 0;

    double time = 0.0;
    double dt = 3600; // dt is the time step in seconds

    while(time < 86400){
        for(int i = 0; i < 3; i++){
            for(int j = i+1; j < 3; j++){
                calculate_force(&p[i], &p[j]);
            }
        }

        for(int i = 0; i < 3; i++){
            update_position(&p[i], dt);
        }

        time += dt;
    }

    return 0;
}