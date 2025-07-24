//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: real-life
#include <stdio.h>
#include <math.h>
#define TIME_STEP 0.01       // time step is 0.01 year
#define N 4                  // N is the number of planets
#define G 6.674 * pow(10,-11)  // gravitational constant

struct planet {
    double mass;                // mass of the planet in kg
    double radius;              // radius of the planet in km
    double x;                   // x-position of the planet in km
    double y;                   // y-position of the planet in km
    double vx;                  // x-velocity of the planet in km/year
    double vy;                  // y-velocity of the planet in km/year
};

int main() {
    struct planet planets[N];
    
    // initialize the planets
    planets[0].mass = 1.98 * pow(10,30);   // mass of sun
    planets[0].radius = 696340;            // radius of sun
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    
    planets[1].mass = 5.97 * pow(10,24);   // mass of earth
    planets[1].radius = 6371;              // radius of earth
    planets[1].x = 152.10 * pow(10,6);     // distance from sun to earth in km
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = 29.78 * pow(10,3);     // velocity of earth in km/year
    
    planets[2].mass = 3.30 * pow(10,23);   // mass of mars
    planets[2].radius = 3389;              // radius of mars
    planets[2].x = 227.94 * pow(10,6);     // distance from sun to mars in km
    planets[2].y = 0;
    planets[2].vx = 0;
    planets[2].vy = 24.07 * pow(10,3);     // velocity of mars in km/year
    
    planets[3].mass = 1.90 * pow(10,27);   // mass of jupiter
    planets[3].radius = 69911;             // radius of jupiter
    planets[3].x = 778.24 * pow(10,6);     // distance from sun to jupiter in km
    planets[3].y = 0;
    planets[3].vx = 0;
    planets[3].vy = 13.07 * pow(10,3);     // velocity of jupiter in km/year
  
    double total_time = 1;                 // total time in years
    int n_steps = (int)(total_time / TIME_STEP);  // number of time steps

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            double distance = sqrt(pow(planets[j].x - planets[i].x, 2) + pow(planets[j].y - planets[i].y, 2));
            double force = G * planets[j].mass * planets[i].mass / pow(distance, 2);
            double angle = atan2(planets[j].y - planets[i].y, planets[j].x - planets[i].x);
            
            double fx = force * cos(angle);
            double fy = force * sin(angle);
            
            planets[i].vx += fx * TIME_STEP / planets[i].mass;
            planets[i].vy += fy * TIME_STEP / planets[i].mass;
            
            planets[j].vx -= fx * TIME_STEP / planets[j].mass;
            planets[j].vy -= fy * TIME_STEP / planets[j].mass;
        }
    }

    for(int step = 0; step < n_steps; step++) {
        for(int i = 1; i < N; i++) {
            planets[i].x += planets[i].vx * TIME_STEP;
            planets[i].y += planets[i].vy * TIME_STEP;
        }
        
        for(int i = 1; i < N; i++) {
            for(int j = 0; j < i; j++) {
                double distance = sqrt(pow(planets[j].x - planets[i].x, 2) + pow(planets[j].y - planets[i].y, 2));
                double force = G * planets[j].mass * planets[i].mass / pow(distance, 2);
                double angle = atan2(planets[j].y - planets[i].y, planets[j].x - planets[i].x);
                
                double fx = force * cos(angle);
                double fy = force * sin(angle);
                
                planets[i].vx += fx * TIME_STEP / planets[i].mass;
                planets[i].vy += fy * TIME_STEP / planets[i].mass;
                
                planets[j].vx -= fx * TIME_STEP / planets[j].mass;
                planets[j].vy -= fy * TIME_STEP / planets[j].mass;
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        printf("Planet %d:\n", i);
        printf("Mass: %lf kg\n", planets[i].mass);
        printf("Radius: %lf km\n", planets[i].radius);
        printf("Position (x,y): (%lf, %lf) km\n", planets[i].x, planets[i].y);
        printf("Velocity (vx,vy): (%lf, %lf) km/year\n", planets[i].vx, planets[i].vy);
        printf("\n");
    }
    
    return 0;
}