//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 1000.0 // Gravitational constant
#define M_SUN 1000000.0 // Mass of the sun
#define FPS 60 // Frames per second
#define DT 0.1 // Time step
#define N_PLANETS 4 // Number of planets

typedef struct {
    double x; // x coordinate
    double y; // y coordinate
    double vx; // x velocity
    double vy; // y velocity
    double m; // mass
} planet;

void calculate_acceleration(planet* p, planet* planets, int n) {
    double ax = 0.0; // Acceleration in x axis
    double ay = 0.0; // Acceleration in y axis
    
    for (int i = 0; i < n; i++) {
        if (p != &planets[i]) {
            double dx = planets[i].x - p->x; // Distance in x axis
            double dy = planets[i].y - p->y; // Distance in y axis
            double distance_squared = dx * dx + dy * dy; // Squared distance
            double distance = sqrt(distance_squared); // Distance
            
            ax += G * planets[i].m / distance_squared * dx / distance; // Add acceleration in x axis
            ay += G * planets[i].m / distance_squared * dy / distance; // Add acceleration in y axis
        }
    }
    
    p->vx += ax * DT; // Update velocity in x axis
    p->vy += ay * DT; // Update velocity in y axis
}

void update_position(planet* p) {
    p->x += p->vx * DT; // Update x coordinate
    p->y += p->vy * DT; // Update y coordinate
}

int main() {
    planet planets[N_PLANETS]; // Array of planets
    
    // Initialize the sun
    planets[0].x = 0.0;
    planets[0].y = 0.0;
    planets[0].vx = 0.0;
    planets[0].vy = 0.0;
    planets[0].m = M_SUN;
    
    // Initialize the planets
    planets[1].x = -500.0;
    planets[1].y = 0.0;
    planets[1].vx = 0.0;
    planets[1].vy = -10.0;
    planets[1].m = 1.0;
    
    planets[2].x = 0.0;
    planets[2].y = 500.0;
    planets[2].vx = 5.0;
    planets[2].vy = 0.0;
    planets[2].m = 2.0;
    
    planets[3].x = 500.0;
    planets[3].y = 0.0;
    planets[3].vx = 0.0;
    planets[3].vy = 7.0;
    planets[3].m = 1.5;
    
    // Simulation loop
    for (int i = 0; i < FPS * 10; i++) {
        // Print the positions of the planets
        printf("\nIteration %d:\n", i);
        for (int j = 0; j < N_PLANETS; j++) {
            printf("Planet %d: (%.2f, %.2f)\n", j, planets[j].x, planets[j].y);
        }
        
        // Update the velocities and positions of the planets
        for (int j = 0; j < N_PLANETS; j++) {
            calculate_acceleration(&planets[j], planets, N_PLANETS);
            update_position(&planets[j]);
        }
    }
    
    return 0;
}