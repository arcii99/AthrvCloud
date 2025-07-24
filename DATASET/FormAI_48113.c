//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: minimalist
#include <stdio.h>
#include <math.h>

#define G 6.6743*pow(10,-11) /* gravitational constant */

struct Object {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
};

void update_velocity(struct Object *obj1, struct Object *obj2) {
    double dx = obj2->x - obj1->x;
    double dy = obj2->y - obj1->y;
    double dist = sqrt(dx*dx + dy*dy); /* distance between objects */

    double F = G*obj1->mass*obj2->mass/pow(dist,2); /* force of attraction between objects */
    double angle = atan2(dy,dx); /* angle of the force with respect to x-axis */

    double ax = F/obj1->mass*cos(angle); /* acceleration of object 1 in x direction */
    double ay = F/obj1->mass*sin(angle); /* acceleration of object 1 in y direction */

    obj1->vx += ax*1; /* updating velocity of object 1 in x direction */
    obj1->vy += ay*1; /* updating velocity of object 1 in y direction */
}

void update_position(struct Object *obj) {
    obj->x += obj->vx*1; /* updating position of object in x direction */
    obj->y += obj->vy*1; /* updating position of object in y direction */
}

int main(void) {
    struct Object earth = {5.972*pow(10,24), 0, 0, 0, 0}; /* mass of earth and initial position and velocity */
    struct Object moon = {7.342*pow(10,22), 384400000, 0, 0, 1022}; /* mass of moon and initial position and velocity */
    int i;

    for(i=0; i<86400; i++) { /* simulation for 1 day (86400 seconds) */
        update_velocity(&earth, &moon); /* updating velocity of earth due to attraction from moon */
        update_velocity(&moon, &earth); /* updating velocity of moon due to attraction from earth */
        update_position(&earth); /* updating position of earth due to its velocity */
        update_position(&moon); /* updating position of moon due to its velocity */
    }

    printf("Final position of earth: (%.2f, %.2f)\n", earth.x, earth.y);
    printf("Final position of moon: (%.2f, %.2f)\n", moon.x, moon.y);

    return 0;
}