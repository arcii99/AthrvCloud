//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: accurate
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define G 6.674e-11
#define MASS_OF_SUN 1.989e30
#define AU 149.6e9

typedef struct{
    double x;
    double y;
    double z;
} vector;

typedef struct{
    vector pos; //position
    vector vel; //velocity
    double mass; // mass
} planet;

double distance(vector pos1, vector pos2){
    double dx = pos1.x - pos2.x;
    double dy = pos1.y - pos2.y;
    double dz = pos1.z - pos2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

vector calculate_force(planet p1, planet p2){
    double dist = distance(p1.pos, p2.pos);
    double force_magnitude = G*p1.mass*p2.mass/(dist*dist);
    vector force;
    force.x = force_magnitude * (p2.pos.x - p1.pos.x)/dist;
    force.y = force_magnitude * (p2.pos.y - p1.pos.y)/dist;
    force.z = force_magnitude * (p2.pos.z - p1.pos.z)/dist;
    return force;
}

void update(planet* planets, int num_planets, double dt){
    // loop through all pairs of planets and calculate the force between them
    for(int i=0; i<num_planets; i++){
        // reset the force on the planet
        vector force;
        force.x = 0.0;
        force.y = 0.0;
        force.z = 0.0;
        for(int j=0; j<num_planets; j++){
            if(i != j){
                // calculate the force between two planets
                vector f = calculate_force(planets[i], planets[j]);
                force.x += f.x;
                force.y += f.y;
                force.z += f.z;
            }
        }
        // update the velocity and position of the planet
         planets[i].vel.x += dt * force.x / planets[i].mass;
         planets[i].vel.y += dt * force.y / planets[i].mass;
         planets[i].vel.z += dt * force.z / planets[i].mass;
         planets[i].pos.x += dt * planets[i].vel.x;
         planets[i].pos.y += dt * planets[i].vel.y;
         planets[i].pos.z += dt * planets[i].vel.z;
    }
}

int main(){
    // set up the simulation parameters
    int num_planets = 4;
    double dt = 86400.0; // time step in seconds (1 day)
    planet mars = {{1.524*AU, 0, 0}, {0, 24080.0, 0}, 6.39e23};
    planet venus = {{0.723*AU, 0, 0}, {0, 35260.0, 0}, 4.87e24};
    planet earth = {{AU, 0, 0}, {0, 29783.0, 0}, 5.97e24};
    planet sun = {{0,0,0}, {0,0,0}, MASS_OF_SUN};
    
    planet planets[] = {mars, venus, earth, sun};
    
    // run the simulation for 1 year
    double totalTime = 365*86400.0;
    int numSteps = (int) (totalTime/dt);

    // time loop
    for(int i=0; i<numSteps; i++){
        update(planets, num_planets, dt);
    }

    // output the final positions of the planets
    printf("Final Positions:\n");
    for(int i=0; i<num_planets; i++){
        printf("Planet %d: x=%e y=%e z=%e\n", i, planets[i].pos.x, planets[i].pos.y, planets[i].pos.z);
    }

    return 0;
}