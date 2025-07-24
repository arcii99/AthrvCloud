//FormAI DATASET v1.0 Category: Physics simulation ; Style: real-life
#include<stdio.h>
#include<math.h>

#define G 6.67*pow(10,-11) // Gravititational constant
#define TIME_STEP 0.1       // Time step size

typedef struct {
    double x,y;             // coordinates
    double vx,vy;           // velocity
    double ax,ay;           // acceleration
    double mass;            // mass
} Body;

Body createBody(double x, double y, double vx, double vy, double mass) {
    Body body;
    body.x = x;
    body.y = y;
    body.vx = vx;
    body.vy = vy;
    body.mass = mass;
    return body;
}

double distance (Body b1, Body b2) {
    return sqrt(pow(b1.x-b2.x,2)+pow(b1.y-b2.y,2));
}

double force (Body b1, Body b2) {
    double dist = distance(b1,b2);
    return G * b1.mass * b2.mass / pow(dist,2);
}

int main() {
    Body sun = createBody(0,0,0,0,1.989*pow(10,30));    // position sun at origin
    Body earth = createBody(1.496*pow(10,11),0,0,29783,5.973*pow(10,24)); // position earth at its mean orbital distance from the sun
    double r, f, fx, fy;
    double time = 0;
    while (1) {
        // calculate force and acceleration
        r = distance(sun, earth);
        f = force(sun, earth);
        fx = f * (sun.x - earth.x) / r;
        fy = f * (sun.y - earth.y) / r;
        earth.ax = fx / earth.mass;
        earth.ay = fy / earth.mass;

        // update position and velocity
        earth.vx += earth.ax * TIME_STEP;
        earth.vy += earth.ay * TIME_STEP;
        earth.x += earth.vx * TIME_STEP;
        earth.y += earth.vy * TIME_STEP;

        printf("time: %.2f sec, position: (%e, %e) m\n", time, earth.x, earth.y);
        time += TIME_STEP;
    }
    return 0;
}