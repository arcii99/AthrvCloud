//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Donald Knuth
#include <math.h>
#include <stdio.h>

#define DT 0.001 // simulation time step
#define G 6.67430e-11 // gravitational constant
#define NUM_PLANETS 2 // number of planets

typedef struct {
    double x, y, z; // planet position
    double vx, vy, vz; // planet velocity
    double mass; // planet mass
} Planet;

void update_position(Planet* p, double timestep) {
    p->x += p->vx * timestep;
    p->y += p->vy * timestep;
    p->z += p->vz * timestep;
}

void update_velocity(Planet* p, double timestep, double ax, double ay, double az) {
    p->vx += ax * timestep;
    p->vy += ay * timestep;
    p->vz += az * timestep;
}

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    double dz = z1 - z2;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void simulate(double time) {
    Planet planets[NUM_PLANETS];
    planets[0].mass = 5.9742e24; // mass of Earth
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;
    planets[1].mass = 7.342e22; // mass of Moon
    planets[1].x = 3.844e8; // distance from Earth
    planets[1].y = 0;
    planets[1].z = 0;
    planets[1].vx = 0;
    planets[1].vy = 1022; // velocity of Moon
    planets[1].vz = 0;
    
    double ax[NUM_PLANETS] = {0}; // acceleration arrays
    double ay[NUM_PLANETS] = {0};
    double az[NUM_PLANETS] = {0};
    
    for (double t=0; t<time; t+=DT) {
        // calculate acceleration
        for (int i=0; i<NUM_PLANETS; i++) {
            ax[i] = 0;
            ay[i] = 0;
            az[i] = 0;
            for (int j=0; j<NUM_PLANETS; j++) {
                if (i == j) {
                    continue;
                }
                double dist = distance(planets[i].x, planets[i].y, planets[i].z, planets[j].x, planets[j].y, planets[j].z);
                double force = G * planets[i].mass * planets[j].mass / (dist*dist);
                ax[i] += force * (planets[j].x - planets[i].x) / dist / planets[i].mass;
                ay[i] += force * (planets[j].y - planets[i].y) / dist / planets[i].mass;
                az[i] += force * (planets[j].z - planets[i].z) / dist / planets[i].mass;
            }
        }
        // update velocity and position
        for (int i=0; i<NUM_PLANETS; i++) {
            update_velocity(&planets[i], DT, ax[i], ay[i], az[i]);
            update_position(&planets[i], DT);
        }
        printf("Time: %lf, Distance between Earth and Moon: %lf meters\n", t+DT, distance(planets[0].x, planets[0].y, planets[0].z, planets[1].x, planets[1].y, planets[1].z));
    }
}

int main() {
    simulate(86400); // simulate for one Earth day
    return 0;
}