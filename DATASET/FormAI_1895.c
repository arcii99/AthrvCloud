//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

#define G 6.6743E-11 // The gravitational constant

typedef struct { 
      double x, y, z; 
      double vx, vy, vz; // Velocity component for x, y, and z
      double mass;
} planet; // The planet structure

double distance(planet p1, planet p2) {
     // A function to calculate the distance between two planets
     return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2) + pow((p2.z - p1.z), 2));
}

planet updatePosition(planet p, double t) {
    // A function to update position of a planet after a time interval t sec
    p.x += p.vx * t;
    p.y += p.vy * t;
    p.z += p.vz * t;
    return p;
}

planet updateVelocity(planet p, planet other, double t) {
    // A function to update velocity of p after a time interval t sec due to force on it from other planet
    double dist = distance(p, other);
    double force = G * p.mass * other.mass / pow(dist, 2);
    double acceleration = force / p.mass;
    
    double x_dir = other.x - p.x;
    double y_dir = other.y - p.y;
    double z_dir = other.z - p.z;
    double total_dir = sqrt(pow(x_dir, 2) + pow(y_dir, 2) + pow(z_dir, 2));
    
    double x_n = x_dir / total_dir;
    double y_n = y_dir / total_dir;
    double z_n = z_dir / total_dir;
    
    p.vx += x_n * acceleration * t;
    p.vy += y_n * acceleration * t;
    p.vz += z_n * acceleration * t;
    
    return p;
}

void simulate(planet planets[], int num_planets, double t, int iterations) {
    for (int i = 0; i < iterations; i++){
        for (int p = 0; p < num_planets; p++) {
            planet temp = planets[p];
            for (int j = 0; j < num_planets; j++) {
                if (p != j) {
                    // Calculate velocity changes due to all planets, excluding itself
                    temp = updateVelocity(temp, planets[j], t);
                }
            }
            // Update planet positions and velocities for the time interval
            planets[p] = updatePosition(temp, t);
        }
    }
}

int main() {
    planet earth = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.972E24}; // Earth's mass is 5.972E24 kg
    planet mars = {2.279E11, 0.0, 0.0, 0.0, 24130.0, 0.0, 6.39E23}; // Mars's mass is 6.39E23 kg
    planet planets[] = {earth, mars};
    int num_planets = sizeof(planets) / sizeof(planet);
    double t = 86400; // One Earth day in seconds is 86400
    int iterations = 365; // Simulate for 365 days
    
    simulate(planets, num_planets, t, iterations);
    
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d:\nPosition (x, y, z): (%.2f, %.2f, %.2f)\nVelocity (vx, vy, vz): (%.2f, %.2f, %.2f)\n", i+1, planets[i].x, planets[i].y, planets[i].z, planets[i].vx, planets[i].vy, planets[i].vz);
    }
    return 0;
}