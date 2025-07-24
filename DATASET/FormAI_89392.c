//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: complete
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define G 6.67e-11   // Gravitational constant
#define PI 3.1416    // Pi value

struct vector{
  double x, y, z;  
};

typedef struct vector vect;

struct planet{
  char name[30];
  double mass;
  vect position, velocity, acceleration;
};

typedef struct planet planet;

// Function to calculate distance between two planets
double distance(vect pos_a, vect pos_b){
    double dist;
    dist = sqrt(pow((pos_b.x - pos_a.x), 2) +
                pow((pos_b.y - pos_a.y), 2) +
                pow((pos_b.z - pos_a.z), 2));
    return dist;
}

// Function to calculate gravitational force between two planets
vect gravity(vect pos_a, vect pos_b, double mass_a, double mass_b){
    vect force;
    double dist = distance(pos_a, pos_b);
    double mag_force = G * mass_a * mass_b / pow(dist, 2);
    force.x = mag_force * (pos_b.x - pos_a.x) / dist;
    force.y = mag_force * (pos_b.y - pos_a.y) / dist;
    force.z = mag_force * (pos_b.z - pos_a.z) / dist;
    return force;
}

int main(){
    planet sun = {"Sun", 1.989e30, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};  // Initializing Sun
    planet earth = {"Earth", 5.97e24, {1.496e11, 0, 0}, {0, 29783, 0}, {0, 0, 0}};  // Initializing Earth
    planet moon = {"Moon", 7.35e22, {1.5e11, 0, 0}, {0, 3070, 0}, {0, 0, 0}};   // Initializing Moon
    
    double time_step = 3600;  // 1 hour time step
    double sim_time = 31536000;  // 1 Earth year simulation time
    
    // Running simulation loop
    for(double t=0; t<sim_time; t+=time_step){
        // Calculating gravitational forces
        vect force_sun_earth = gravity(sun.position, earth.position, sun.mass, earth.mass);
        vect force_sun_moon = gravity(sun.position, moon.position, sun.mass, moon.mass);
        vect force_earth_moon = gravity(earth.position, moon.position, earth.mass, moon.mass);
        
        // Updating acceleration
        earth.acceleration.x = force_sun_earth.x / earth.mass;
        earth.acceleration.y = force_sun_earth.y / earth.mass;
        earth.acceleration.z = force_sun_earth.z / earth.mass;
        
        moon.acceleration.x = force_sun_moon.x / moon.mass + force_earth_moon.x / moon.mass;
        moon.acceleration.y = force_sun_moon.y / moon.mass + force_earth_moon.y / moon.mass;
        moon.acceleration.z = force_sun_moon.z / moon.mass + force_earth_moon.z / moon.mass;
        
        // Updating velocity
        earth.velocity.x += earth.acceleration.x * time_step;
        earth.velocity.y += earth.acceleration.y * time_step;
        earth.velocity.z += earth.acceleration.z * time_step;
        
        moon.velocity.x += moon.acceleration.x * time_step;
        moon.velocity.y += moon.acceleration.y * time_step;
        moon.velocity.z += moon.acceleration.z * time_step;
        
        // Updating position
        earth.position.x += earth.velocity.x * time_step;
        earth.position.y += earth.velocity.y * time_step;
        earth.position.z += earth.velocity.z * time_step;
        
        moon.position.x += moon.velocity.x * time_step;
        moon.position.y += moon.velocity.y * time_step;
        moon.position.z += moon.velocity.z * time_step;
        
        // Printing current position of Earth and Moon
        printf("Time: %.2f\n", t);
        printf("Position of Earth: x=%.2f, y=%.2f, z=%.2f\n", earth.position.x, earth.position.y, earth.position.z);
        printf("Position of Moon: x=%.2f, y=%.2f, z=%.2f\n\n", moon.position.x, moon.position.y, moon.position.z);
    }
    
    return 0;
}