//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: high level of detail
#include <stdio.h>
#define G 6.674E-11 // gravitational constant
#define dt 86400 //time-step (1 day in seconds)

// Define a struct for planet information
typedef struct {
    char *name;
    double mass; //kg
    double position[3]; //m
    double velocity[3]; //m/s
} planet;

// Function to calculate the distance between two planets
double distance(double *pos1, double *pos2) {
    double dx = pos1[0] - pos2[0];
    double dy = pos1[1] - pos2[1];
    double dz = pos1[2] - pos2[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Function to update the position and velocity of a planet
void update(planet *p, double *acceleration) {
    p->velocity[0] += acceleration[0] * dt;
    p->velocity[1] += acceleration[1] * dt;
    p->velocity[2] += acceleration[2] * dt;
    
    p->position[0] += p->velocity[0] * dt;
    p->position[1] += p->velocity[1] * dt;
    p->position[2] += p->velocity[2] * dt;
}

// Function to calculate the acceleration of a planet due to other planets
void acceleration(double *pos1, double *pos2, double mass2, double *result) {
    double d = distance(pos1, pos2);
    double f = G * mass2 / (d*d);
    result[0] = f * (pos2[0] - pos1[0]) / d;
    result[1] = f * (pos2[1] - pos1[1]) / d;
    result[2] = f * (pos2[2] - pos1[2]) / d;
}

int main() {
    //initialize planets
    planet sun      = {"Sun", 1.989E30, {0, 0, 0}, {0, 0, 0}};
    planet mercury  = {"Mercury", 3.3011E23, {-4.6E10, 0, 0}, {0, 47360, 0}};
    planet venus    = {"Venus", 4.8675E24, {-1.1E11, 0, 0}, {0, 35020, 0}};
    planet earth    = {"Earth", 5.972E24, {-1.5E11, 0, 0}, {0, 29783, 0}};
    planet mars     = {"Mars", 6.4171E23, {2.1E11, 0, 0}, {0, 24077, 0}};
    
    planet planets[] = {sun, mercury, venus, earth, mars};
    int num_planets = sizeof(planets) / sizeof(planet);
    
    //calculate acceleration and update planet positions and velocities for 1 year
    for(int i = 0; i < 365; i++) {
        for(int j = 0; j < num_planets; j++) {
            double acceleration_vec[3] = {0};
            for(int k = 0; k < num_planets; k++) {
                if(j == k) continue;
                double a[3] = {0};
                acceleration(planets[j].position, planets[k].position, planets[k].mass, a);
                acceleration_vec[0] += a[0];
                acceleration_vec[1] += a[1];
                acceleration_vec[2] += a[2];
            }
            update(&planets[j], acceleration_vec);
        }
    }
    
    //print out final positions of planets
    for(int i = 0; i < num_planets; i++) {
        printf("%s final position: %.2f m, %.2f m, %.2f m\n", planets[i].name, planets[i].position[0], planets[i].position[1], planets[i].position[2]);
    }
    
    return 0;
}