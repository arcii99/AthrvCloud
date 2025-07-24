//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 //Gravitational constant 

typedef struct Vector{ //2D vector structure
    double x;
    double y;
}Vector;

typedef struct Planet{ //Planet structure
    char* name;
    double mass;
    Vector position;
    Vector velocity;
    Vector acceleration;
}Planet;

int main(){
    //create planets
    Planet earth = {"Earth", 5.972e24, {0, 0}, {0, 0}, {0, 0}};
    Planet mars = {"Mars", 6.39e23, {0, 22792}, {24000, 0}, {0, 0}};
    
    //set simulation parameters
    double timestep = 1; //seconds
    double total_time = 100000; //seconds
    int num_steps = total_time/timestep;
    
    //perform simulation
    for(int i=0; i<num_steps; i++){
        //calculate distance between planets
        Vector diff = {mars.position.x - earth.position.x, mars.position.y - earth.position.y};
        double distance = sqrt(diff.x*diff.x + diff.y*diff.y);
        
        //calculate gravitational force
        double force_magnitude = G*earth.mass*mars.mass/(distance*distance);
        Vector force_direction = {diff.x/distance, diff.y/distance};
        Vector force = {force_magnitude*force_direction.x, force_magnitude*force_direction.y};
        
        //update acceleration
        earth.acceleration.x = force.x/earth.mass;
        earth.acceleration.y = force.y/earth.mass;
        mars.acceleration.x = -force.x/mars.mass;
        mars.acceleration.y = -force.y/mars.mass;
        
        //update velocity
        earth.velocity.x += earth.acceleration.x*timestep;
        earth.velocity.y += earth.acceleration.y*timestep;
        mars.velocity.x += mars.acceleration.x*timestep;
        mars.velocity.y += mars.acceleration.y*timestep;
        
        //update position
        earth.position.x += earth.velocity.x*timestep;
        earth.position.y += earth.velocity.y*timestep;
        mars.position.x += mars.velocity.x*timestep;
        mars.position.y += mars.velocity.y*timestep;
        
        //print positions
        printf("%s position: (%f, %f)\n", earth.name, earth.position.x, earth.position.y);
        printf("%s position: (%f, %f)\n", mars.name, mars.position.x, mars.position.y);
    }

    return 0;
}