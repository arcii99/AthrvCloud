//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.6743e-11 // gravitational constant
#define YEAR 31536000.0 // 1 earth year in seconds

// structure to hold planet data
typedef struct Planet{
    char name[25];
    double mass; // in kg
    double radius; // in m
    double position[3]; // in m
    double velocity[3]; // in m/s
    double acceleration[3]; // in m/s^2
}Planet;

// function to initialize planets
void init_planets(Planet* planets){
    // sun
    sprintf(planets[0].name, "Sun");
    planets[0].mass = 1.989e30;
    planets[0].radius = 696340000.0;
    planets[0].position[0] = 0.0;
    planets[0].position[1] = 0.0;
    planets[0].position[2] = 0.0;
    planets[0].velocity[0] = 0.0;
    planets[0].velocity[1] = 0.0;
    planets[0].velocity[2] = 0.0;
    planets[0].acceleration[0] = 0.0;
    planets[0].acceleration[1] = 0.0;
    planets[0].acceleration[2] = 0.0;

    // mercury
    sprintf(planets[1].name, "Mercury");
    planets[1].mass = 3.285e23;
    planets[1].radius = 2439700.0;
    planets[1].position[0] = -57909227000.0;
    planets[1].position[1] = 0.0;
    planets[1].position[2] = 0.0;
    planets[1].velocity[0] = 0.0;
    planets[1].velocity[1] = -47362.0;
    planets[1].velocity[2] = 0.0;

    // venus
    sprintf(planets[2].name, "Venus");
    planets[2].mass = 4.867e24;
    planets[2].radius = 6051800.0;
    planets[2].position[0] = -108208930000.0;
    planets[2].position[1] = 0.0;
    planets[2].position[2] = 0.0;
    planets[2].velocity[0] = 0.0;
    planets[2].velocity[1] = -35020.0;
    planets[2].velocity[2] = 0.0;

    // earth
    sprintf(planets[3].name, "Earth");
    planets[3].mass = 5.972e24;
    planets[3].radius = 6371000.0;
    planets[3].position[0] = -147098074000.0;
    planets[3].position[1] = 0.0;
    planets[3].position[2] = 0.0;
    planets[3].velocity[0] = 0.0;
    planets[3].velocity[1] = -29785.0;
    planets[3].velocity[2] = 0.0;

    // mars
    sprintf(planets[4].name, "Mars");
    planets[4].mass = 6.39e23;
    planets[4].radius = 3389500.0;
    planets[4].position[0] = -206655215000.0;
    planets[4].position[1] = 0.0;
    planets[4].position[2] = 0.0;
    planets[4].velocity[0] = 0.0;
    planets[4].velocity[1] = -24100.0;
    planets[4].velocity[2] = 0.0;

    // jupiter
    sprintf(planets[5].name, "Jupiter");
    planets[5].mass = 1.898e27;
    planets[5].radius = 69911000.0;
    planets[5].position[0] = -740679835000.0;
    planets[5].position[1] = 0.0;
    planets[5].position[2] = 0.0;
    planets[5].velocity[0] = 0.0;
    planets[5].velocity[1] = -13070.0;
    planets[5].velocity[2] = 0.0;

    // saturn
    sprintf(planets[6].name, "Saturn");
    planets[6].mass = 5.683e26;
    planets[6].radius = 58232000.0;
    planets[6].position[0] = -1353572956000.0;
    planets[6].position[1] = 0.0;
    planets[6].position[2] = 0.0;
    planets[6].velocity[0] = 0.0;
    planets[6].velocity[1] = -9690.0;
    planets[6].velocity[2] = 0.0;

    // uranus
    sprintf(planets[7].name, "Uranus");
    planets[7].mass = 8.681e25;
    planets[7].radius = 25362000.0;
    planets[7].position[0] = -2748938461000.0;
    planets[7].position[1] = 0.0;
    planets[7].position[2] = 0.0;
    planets[7].velocity[0] = 0.0;
    planets[7].velocity[1] = -6810.0;
    planets[7].velocity[2] = 0.0;

    // neptune
    sprintf(planets[8].name, "Neptune");
    planets[8].mass = 1.024e26;
    planets[8].radius = 24622000.0;
    planets[8].position[0] = -4452940833000.0;
    planets[8].position[1] = 0.0;
    planets[8].position[2] = 0.0;
    planets[8].velocity[0] = 0.0;
    planets[8].velocity[1] = -5430.0;
    planets[8].velocity[2] = 0.0;
}

// function to calculate distance between two planets
double calc_distance(Planet planet1, Planet planet2){
    double x_diff_sq = pow((planet1.position[0] - planet2.position[0]),2);
    double y_diff_sq = pow((planet1.position[1] - planet2.position[1]),2);
    double z_diff_sq = pow((planet1.position[2] - planet2.position[2]),2);
    double distance = sqrt(x_diff_sq + y_diff_sq + z_diff_sq);
    return distance;
}

// function to calculate gravitational force between two planets
double calc_gravity(Planet planet1, Planet planet2){
    double distance = calc_distance(planet1, planet2);
    double force = G * ((planet1.mass * planet2.mass) / pow(distance,2));
    return force;
}

// function to calculate acceleration of a planet due to gravitational forces from all other planets
void calc_acceleration(Planet* planets){
    for(int i=0; i<9; i++){
        planets[i].acceleration[0] = 0.0;
        planets[i].acceleration[1] = 0.0;
        planets[i].acceleration[2] = 0.0;
        for(int j=0; j<9; j++){
            if(i==j) continue;
            double force = calc_gravity(planets[i], planets[j]);
            double distance = calc_distance(planets[i], planets[j]);
            double acceleration = force / planets[i].mass;
            double x_comp = (planets[j].position[0] - planets[i].position[0]) / distance;
            double y_comp = (planets[j].position[1] - planets[i].position[1]) / distance;
            double z_comp = (planets[j].position[2] - planets[i].position[2]) / distance;
            planets[i].acceleration[0] += acceleration * x_comp;
            planets[i].acceleration[1] += acceleration * y_comp;
            planets[i].acceleration[2] += acceleration * z_comp;
        }
    }
}

// function to update velocity and position of planets based on current acceleration
void update_planets(Planet* planets, double time_step){
    for(int i=0; i<9; i++){
        planets[i].velocity[0] += planets[i].acceleration[0] * time_step;
        planets[i].velocity[1] += planets[i].acceleration[1] * time_step;
        planets[i].velocity[2] += planets[i].acceleration[2] * time_step;
        planets[i].position[0] += planets[i].velocity[0] * time_step;
        planets[i].position[1] += planets[i].velocity[1] * time_step;
        planets[i].position[2] += planets[i].velocity[2] * time_step;
    }
}

// function to print current state of all planets
void print_planets(Planet* planets){
    printf("Name        Mass (kg)    Radius (m)    Position (m)                              Velocity (m/s)                          Acceleration (m/s^2)\n");
    for(int i=0; i<9; i++){
        printf("%-10s  %-12.4e  %-12.2f  (% 12.4e, % 12.4e, % 12.4e)  (% 12.4e, % 12.4e, % 12.4e)  (% 12.4e, % 12.4e, % 12.4e)\n", planets[i].name, planets[i].mass, planets[i].radius, planets[i].position[0], planets[i].position[1], planets[i].position[2], planets[i].velocity[0], planets[i].velocity[1], planets[i].velocity[2], planets[i].acceleration[0], planets[i].acceleration[1], planets[i].acceleration[2]);
    }
}

int main(){
    srand(time(NULL));
    double time_step = 86400.0 * 0.5; // half an earth day in seconds
    Planet planets[9];
    init_planets(planets);

    printf("Simulation starting...\n");
    print_planets(planets);

    for(int i=0; i<365*5; i++){
        calc_acceleration(planets);
        update_planets(planets, time_step);
        if(i % 30 == 0){
            printf("Day %d:\n", i/30 + 1);
            print_planets(planets);
        }
    }

    printf("Simulation complete.\n");

    return 0;
}