//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: innovative
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define WIDTH 100
#define HEIGHT 50

#define G 6.67430e-11
#define SCALE_FACTOR 1e6 

#define H 86400 // step size of one day 

// Helper function to scale down to fit in terminal 
int scale(double n) { 
    return (int)(n / SCALE_FACTOR * WIDTH / 2) + WIDTH / 2; 
} 

typedef struct { 
    double x, y; // position 
    double vx, vy; // velocity 
    double ax, ay; // acceleration 
    double mass;
    char symbol; // symbol to represent planet 
    int color; // color code 
} body; 

int main() { 
    body sun = {0, 0, 0, 0, 0, 1.9885e30, '*', 3}; 
    body earth = {-147000000000.0, 0, 0, 30300, 0, 5.9722e24, 'o', 6}; 
    body mars = {0, 227000000000.0, -24077.0, 0, 0, 6.4185e23, 'o', 1}; 
    body venus = {108000000000.0, 0, 0, -35000.0, 0, 4.8675e24, 'o', 4}; 
    
    body* planets[] = {&earth, &mars, &venus}; 
    int num_planets = sizeof(planets) / sizeof(body*); 
    
    // set up initial values 
    for(int i = 0; i < num_planets; i++) {
        planets[i]->ax = 0;
        planets[i]->ay = 0;
    }
    
    // simulation loop 
    for(int t = 0; ; t += H) { 
        // calculate accelerations 
        for(int i = 0; i < num_planets; i++) { 
            for(int j = i+1; j < num_planets; j++) { 
                double dx = planets[j]->x - planets[i]->x;
                double dy = planets[j]->y - planets[i]->y;
                double d = sqrt(dx*dx + dy*dy); 
            
                double f = G * planets[i]->mass * planets[j]->mass / (d*d); 
            
                double fx = f * dx / d; 
                double fy = f * dy / d; 
            
                planets[i]->ax += fx / planets[i]->mass; 
                planets[i]->ay += fy / planets[i]->mass; 
            
                planets[j]->ax -= fx / planets[j]->mass; 
                planets[j]->ay -= fy / planets[j]->mass; 
            } 
        } 
        
        // update velocities and positions 
        for(int i = 0; i < num_planets; i++) { 
            planets[i]->vx += planets[i]->ax * H; 
            planets[i]->vy += planets[i]->ay * H; 
            planets[i]->x += planets[i]->vx * H; 
            planets[i]->y += planets[i]->vy * H; 
            planets[i]->ax = 0;
            planets[i]->ay = 0;
        } 
        
        // print out current state of solar system 
        char screen[HEIGHT][WIDTH]; 
        for(int i = 0; i < HEIGHT; i++) { 
            printf("\033[%d;1H", i+1); 
            for(int j = 0; j < WIDTH; j++) {
                screen[i][j] = ' ';
                for(int k = 0; k < num_planets; k++) { 
                    int x = scale(planets[k]->x); 
                    int y = scale(planets[k]->y); 
                    if(x == j && y == i) {
                        screen[i][j] = planets[k]->symbol; 
                        printf("\033[3%dm%c\033[0m", planets[k]->color, planets[k]->symbol);
                    }
                }
                putchar(screen[i][j]); 
            }
        }  
        printf("\033[%d;1HTime: %d s", HEIGHT+1, t+H); 
        fflush(stdout); 
    } 
    return 0; 
}