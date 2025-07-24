//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define G 6.67e-11   // gravitational constant

// a struct to represent a planet
typedef struct {
    double mass;    // mass of planet
    double x_pos;   // x position of planet in space
    double y_pos;   // y position of planet in space
    double x_vel;   // x velocity of planet
    double y_vel;   // y velocity of planet
} Planet;

// a struct to pass information to a planet update thread
typedef struct {
    Planet *planet;     // pointer to the planet to be updated
    Planet *planets;    // pointer to array of all planets in simulation
    int num_planets;    // number of planets in simulation
    double time_delta;  // time interval between updates
} PlanetUpdateArgs;

// a function to calculate the gravitational force between two planets
double gravitational_force(Planet *p1, Planet *p2) {
    double distance = sqrt(pow(p1->x_pos - p2->x_pos, 2) + pow(p1->y_pos - p2->y_pos, 2));
    double force = (G * p1->mass * p2->mass) / pow(distance, 2);
    return force;
}

// a function to update the position and velocity of a single planet
void *update_planet(void *args) {
    PlanetUpdateArgs *update_args = (PlanetUpdateArgs *)args;
    Planet *planet = update_args->planet;
    Planet *planets = update_args->planets;
    int num_planets = update_args->num_planets;
    double time_delta = update_args->time_delta;
    
    double total_force_x = 0.0;
    double total_force_y = 0.0;
    
    for (int i = 0; i < num_planets; i++) {
        if (planets[i].mass == planet->mass) continue;
        double force = gravitational_force(planet, &planets[i]);
        double angle = atan2(planets[i].y_pos - planet->y_pos, planets[i].x_pos - planet->x_pos);
        total_force_x += force * cos(angle);
        total_force_y += force * sin(angle);
    }
    
    double accel_x = total_force_x / planet->mass;
    double accel_y = total_force_y / planet->mass;
    
    planet->x_vel += accel_x * time_delta;
    planet->y_vel += accel_y * time_delta;
    
    planet->x_pos += planet->x_vel * time_delta;
    planet->y_pos += planet->y_vel * time_delta;
    
    pthread_exit(0);
}

int main() {
    Planet planets[] = {
        {5.97e24, 0.0, 0.0, 0.0, 0.0},  // Earth
        {1.99e30, 1.496e11, 0.0, 0.0, 30.29e3}  // Sun
    };
    int num_planets = sizeof(planets) / sizeof(*planets);
    
    pthread_t threads[num_planets];
    PlanetUpdateArgs update_args[num_planets];
    
    for (int i = 0; i < num_planets; i++) {
        update_args[i].planet = &planets[i];
        update_args[i].planets = planets;
        update_args[i].num_planets = num_planets;
        update_args[i].time_delta = 60.0;  // update every 60 seconds
        
        pthread_create(&threads[i], NULL, update_planet, (void *)&update_args[i]);
    }
    
    for (int i = 0; i < num_planets; i++) {
        pthread_join(threads[i], NULL);
    }
    
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: (%f, %f)\n", i+1, planets[i].x_pos, planets[i].y_pos);
    }
    
    return 0;
}