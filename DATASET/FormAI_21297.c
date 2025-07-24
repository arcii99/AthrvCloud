//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 1.0

#define NUM_PLANETS 3

typedef struct{
    double x, y;
}Vec2;

typedef struct{
    Vec2 pos, vel;
    double mass, radius;
}Planet;

typedef struct{
    Vec2 force;
}Body;

int main(){
    Planet planets[NUM_PLANETS] = {
        { {2, 3}, {0.6, 0.5}, 50, 1},
        { {5, 6}, {0.2, -0.3}, 100, 2},
        { {10, 4}, {-0.4, 0.2}, 150, 1.5}
    };
    
    Body bodies[NUM_PLANETS];
    for(int i=0; i<NUM_PLANETS; i++){
        bodies[i].force.x = 0;
        bodies[i].force.y = 0;
    }
    
    double time_step = 0.01;
    double curr_time = 0;
    double end_time = 10;
    
    int num_steps = ceil((end_time - curr_time) / time_step);
    for(int n=0; n<num_steps; n++){
        // Calculate forces
        for(int i=0; i<NUM_PLANETS; i++){
            bodies[i].force.x = 0;
            bodies[i].force.y = 0;
            
            for(int j=0; j<NUM_PLANETS; j++){
                if(i == j) continue;
                
                Vec2 r;
                r.x = planets[j].pos.x - planets[i].pos.x;
                r.y = planets[j].pos.y - planets[i].pos.y;
                
                double dist = sqrt(r.x * r.x + r.y * r.y);
                
                double F = G * planets[i].mass * planets[j].mass / (dist * dist);
                
                bodies[i].force.x += F * r.x / dist;
                bodies[i].force.y += F * r.y / dist;
            }
        }
        
        // Update positions and velocities
        for(int i=0; i<NUM_PLANETS; i++){
            planets[i].pos.x += planets[i].vel.x * time_step;
            planets[i].pos.y += planets[i].vel.y * time_step;
            
            Vec2 accel;
            accel.x = bodies[i].force.x / planets[i].mass;
            accel.y = bodies[i].force.y / planets[i].mass;
            
            planets[i].vel.x += accel.x * time_step;
            planets[i].vel.y += accel.y * time_step;
        }
        
        // Print current positions
        printf("t = %f\n", curr_time);
        for(int i=0; i<NUM_PLANETS; i++){
            printf("Planet %d: (%f, %f)\n", i+1, planets[i].pos.x, planets[i].pos.y);
        }
        
        // Increment time
        curr_time += time_step;
    }
    
    return 0;
}