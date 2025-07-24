//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: cheerful
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 //Value of Gravitational Constant (m^3 kg^-1 s^-2)

/*Structure to hold planet information*/
typedef struct {
    double mass;
    double x, y;
    double vx, vy;
} Planet;

/*Function to calculate the distance between two planets*/
double calc_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

/*Function to calculate gravitational force between two planets*/
double calc_gravity(double m1, double m2, double d) {
    return G * m1 * m2 / (d*d);
}

/*Function to calculate the acceleration of a planet*/
double calc_acceleration(double f, double m) {
    return f / m;
}

/*Function to update planet's velocity and position based on acceleration*/
void update_planet(Planet *p, double ax, double ay, double t) {
    p->vx += ax * t;
    p->vy += ay * t;
    p->x += p->vx * t + 0.5 * ax * t * t;
    p->y += p->vy * t + 0.5 * ay * t * t;
}

int main() {
    /*Initial conditions for two planets*/
    Planet earth = {5.97e24, 0, 0, 0, 0};
    Planet moon = {7.34e22, 3.84e8, 0, 0, 1022};

    double t = 0.1; //Time step size (s)
    double r, f, ax, ay;
    int steps = 1000; //Number of simulation steps
    
    for (int i = 0; i < steps; i++) {
        /*Calculate distance between two planets*/
        r = calc_distance(earth.x, earth.y, moon.x, moon.y);

        /*Calculate force of gravity between planets*/
        f = calc_gravity(earth.mass, moon.mass, r);

        /*Calculate acceleration of each planet*/
        ax = calc_acceleration(f, earth.mass);
        ay = calc_acceleration(f, moon.mass);

        /*Update each planet's velocity and position*/
        update_planet(&earth, -ax, -ay, t); //Earth is at origin, so negate acceleration
        update_planet(&moon, ax, ay, t);

        printf("Step %d - Earth: (%.2e, %.2e), Moon: (%.2e, %.2e)\n", i+1, earth.x, earth.y, moon.x, moon.y);
    }

    return 0;
}