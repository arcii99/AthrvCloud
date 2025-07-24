//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define G 6.674e-11       // The constant G

// Structure for holding the planet information
struct planet{
    double x, y;          // x and y coordinates
    double z;             // z coordinate
    double vx, vy;        // velocities in x and y directions
    double vz;            // velocity in z direction
    double mass;          // mass of the planet
};

// Function that calculates the distance between two planets
double calculate_distance(struct planet p1, struct planet p2){
    double distance;      // variable to store distance
    distance = sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2)+pow((p2.z-p1.z),2));
    return distance;
}

// Function that calculates the force between two planets
double calculate_force(struct planet p1, struct planet p2){
    double force;         // variable to store force
    force = G*((p1.mass*p2.mass)/pow(calculate_distance(p1,p2),2));
    return force;
}

// Function that updates the velocities of the planets based on the force acting on it
void update_velocities(struct planet *p1, struct planet *p2, double time){
    double f;             // variable to store force
    double fx, fy, fz;    // variables to store components of force
    double dx, dy, dz;    // variables to store distance components
    f = calculate_force(*p1,*p2);
    dx = p2->x - p1->x;   // difference in x coordinates
    dy = p2->y - p1->y;   // difference in y coordinates
    dz = p2->z - p1->z;   // difference in z coordinates
    fx = f*dx/calculate_distance(*p1,*p2);   // x component of force
    fy = f*dy/calculate_distance(*p1,*p2);   // y component of force
    fz = f*dz/calculate_distance(*p1,*p2);   // z component of force
    p1->vx += (fx/p1->mass)*time;             // updating velocity in x direction
    p1->vy += (fy/p1->mass)*time;             // updating velocity in y direction
    p1->vz += (fz/p1->mass)*time;             // updating velocity in z direction
}

// Function that updates the positions of the planets based on the updated velocities
void update_positions(struct planet *p, double time){
    p->x += p->vx*time;             // updating position in x direction
    p->y += p->vy*time;             // updating position in y direction
    p->z += p->vz*time;             // updating position in z direction
}

void print_planet_info(struct planet p){
    printf("Position: (%lf, %lf, %lf) \n", p.x, p.y, p.z);
    printf("Velocity: (%lf, %lf, %lf) \n", p.vx, p.vy, p.vz);
    printf("Mass: %lf\n", p.mass);
}

int main(){
    double time = 86400;           // Time step (1 day)
    double total_time = 31536000;  // Total simulation time (1 year)
    int num_planets = 3;           // Number of planets in the simulation

    struct planet planets[num_planets];  // Array for holding planet information
    
    // Setting up planet information    
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;
    planets[0].mass = 5.9722e24;      // Mass of earth

    planets[1].x = 149.6e9;           // Distance of planet from sun (in meters)
    planets[1].y = 0;
    planets[1].z = 0;
    planets[1].vx = 0;
    planets[1].vy = 29783.0;          // Velocity of earth in orbit (in meters per second)
    planets[1].vz = 0;
    planets[1].mass = 5.9722e24;      // Mass of earth

    planets[2].x = 0;
    planets[2].y = 0;
    planets[2].z =  7000e3;           // Height of satellite above earth (in meters)
    planets[2].vx = 7672.0;           // Velocity of satellite (in meters per second)
    planets[2].vy = 0;
    planets[2].vz = 0;
    planets[2].mass = 500;            // Mass of satellite

    // Simulating the planets
    int i, j;
    double t;
    for(t=0; t<total_time; t+=time){
        // Updating velocities of all the planets based on the force acting on them
        for(i=0; i<num_planets-1; i++){
            for(j=i+1; j<num_planets; j++){
                update_velocities(&planets[i], &planets[j], time);
                update_velocities(&planets[j], &planets[i], time);
            }
        }
        // Updating positions of all the planets based on the updated velocities
        for(i=0; i<num_planets; i++){
            update_positions(&planets[i], time);
        }
    }

    // Printing final planet information
    for(i=0; i<num_planets; i++){
        printf("Planet %d: \n", i+1);
        print_planet_info(planets[i]);
    }

    return 0;
}