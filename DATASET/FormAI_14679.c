//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: detailed
#include <stdio.h>
#include <math.h>
#define G 6.67e-11  // Gravitational constant

// Define struct for a planet
typedef struct Planet {
    char name[20];
    double mass; // kg
    double radius; // meters
    double x; // position x
    double y; // position y
    double z; // position z
    double vx; // velocity x
    double vy; // velocity y
    double vz; // velocity z
}Planet;

// Function to calculate distance between two planets
double distance(Planet p1, Planet p2){
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    double d = sqrt(dx*dx + dy*dy + dz*dz);
    return d;
}

// Function to calculate gravitational force between two planets
double force(Planet p1, Planet p2){
    double d = distance(p1, p2);
    double f = G * p1.mass * p2.mass / (d*d);
    return f;
}

// Function to update positions and velocities of planets
void update(Planet *p, int num_planets, double time_step){
    double fx[num_planets];
    double fy[num_planets];
    double fz[num_planets];
    
    // Calculate gravitational force on each planet
    for(int i = 0; i < num_planets; i++){
        double ax = 0;
        double ay = 0;
        double az = 0;
        for(int j = 0; j < num_planets; j++){
            if(i == j) continue;
            double f = force(p[i], p[j]);
            double d = distance(p[i], p[j]);
            double fxij = f * (p[j].x - p[i].x) / d;
            double fyij = f * (p[j].y - p[i].y) / d;
            double fzij = f * (p[j].z - p[i].z) / d;
            fx[i] += fxij;
            fy[i] += fyij;
            fz[i] += fzij;
        }
        ax = fx[i] / p[i].mass;
        ay = fy[i] / p[i].mass;
        az = fz[i] / p[i].mass;
        p[i].vx += ax * time_step;
        p[i].vy += ay * time_step;
        p[i].vz += az * time_step;
        p[i].x += p[i].vx * time_step;
        p[i].y += p[i].vy * time_step;
        p[i].z += p[i].vz * time_step;
    }
}

int main(){
    // Define 4 planets
    Planet earth = {"Earth", 5.97e24, 6.371e6, 0, 0, 0, 0, 0, 0};
    Planet moon = {"Moon", 7.34e22, 1.737e6, 3.84e8, 0, 0, 0, 1.022e3, 0};
    Planet mars = {"Mars", 6.39e23, 3.389e6, 2.27e11, 0, 0, 0, 0, 0};
    Planet jupiter = {"Jupiter", 1.898e27, 6.9911e7, 7.785e11, 0, 0, 0, 0, 0};
    
    Planet planets[4] = {earth, moon, mars, jupiter};
    int num_planets = sizeof(planets)/sizeof(planets[0]);
    double time_step = 86400; // 1 day in seconds
    double simulation_time = 365 * 10; // 10 years in days
    
    for(int i = 0; i < simulation_time; i++){
        update(planets, num_planets, time_step);
    }
    
    // Print final positions of planets
    for(int i = 0; i < num_planets; i++){
        printf("%s: x = %.2f, y = %.2f, z = %.2f\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }
    
    return 0;
}