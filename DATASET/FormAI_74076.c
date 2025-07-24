//FormAI DATASET v1.0 Category: Physics simulation ; Style: single-threaded
#include<stdio.h>
#include<math.h>

#define G 6.67430e-11 // Gravitational constant
#define M1 5.972e24  // Mass of Earth
#define M2 1000     // Mass of a projectile
#define R 6371000   // Radius of Earth

void single_threaded_simulation(){
    double x1 = 0, y1 = 0;           // Position of Earth
    double x2 = R + 10000, y2 = 0;  // Initial position of projectile
    double vx = 0, vy = 8000;       // Initial velocity of projectile
    
    double dt = 1;       // Time step
    double t = 0;        // Initial time
    
    double d, fx, fy, ax, ay;
    
    FILE *f = fopen("output.txt", "w");
    
    while(y2 >= 0){
        // Calculate the distance between Earth and projectile
        d = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
        
        // Calculate the force on projectile due to Earth
        fx = (G * M1 * M2 * (x1-x2)) / pow(d, 3);
        fy = (G * M1 * M2 * (y1-y2)) / pow(d, 3);
        
        // Calculate the acceleration of projectile
        ax = fx / M2;
        ay = fy / M2;
        
        // Update the velocity of projectile
        vx += ax * dt;
        vy += ay * dt;
        
        // Update the position of projectile
        x2 += vx * dt;
        y2 += vy * dt;
        
        // Update the time
        t += dt;
        
        // Print current position and time to output file
        fprintf(f, "%f, %f, %f\n", x2, y2, t);
    }
    
    fclose(f);
}

int main(){
    single_threaded_simulation();
    return 0;
}