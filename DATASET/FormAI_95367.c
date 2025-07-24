//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// define max number of planets
#define MAX 5

// define struct for planet
typedef struct{
    double x,y; // position
    double vx,vy; // velocity
    double ax,ay; // acceleration
    double mass; // mass
} Planet;

// function to calculate distance between two planets
double distance(Planet p1, Planet p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// function to calculate gravitational force between two planets
double force(Planet p1, Planet p2){
    double G = 6.6743 * pow(10,-11);
    double r = distance(p1,p2);
    return G * p1.mass * p2.mass / pow(r,2);
}

// function to update acceleration of given planet
void update_acceleration(Planet* planets, int num_planets, int current_planet){
    double fx = 0, fy = 0;
    for(int i=0; i<num_planets; i++){
        if(i==current_planet) continue;
        double f = force(planets[current_planet], planets[i]);
        double r = distance(planets[current_planet], planets[i]);
        fx += f * (planets[i].x - planets[current_planet].x)/r;
        fy += f * (planets[i].y - planets[current_planet].y)/r;
    }
    planets[current_planet].ax = fx / planets[current_planet].mass;
    planets[current_planet].ay = fy / planets[current_planet].mass;
}

// function to update velocity of given planet
void update_velocity(Planet* planet, double dt){
    planet->vx += planet->ax * dt;
    planet->vy += planet->ay * dt;
}

// function to update position of given planet
void update_position(Planet* planet, double dt){
    planet->x += planet->vx * dt;
    planet->y += planet->vy * dt;
}

// main function
int main(){
    srand(time(NULL));
    Planet planets[MAX];
    int num_planets = rand() % MAX + 1; // choose random number of planets between 1 and MAX
    printf("Number of planets: %d\n", num_planets);
    // initialize planets
    for(int i=0; i<num_planets; i++){
        planets[i].mass = rand() % 10 + 1; // choose random mass between 1 and 10
        planets[i].x = rand() % 100; // choose random position between 0 and 100
        planets[i].y = rand() % 100;
        planets[i].vx = rand() % 10 - 5; // choose random velocity between -5 and 5
        planets[i].vy = rand() % 10 - 5;
        update_acceleration(planets, num_planets, i); // update initial acceleration
    }
    // run simulation for 1000 time steps
    double dt = 0.1;
    for(int t=0; t<1000; t++){
        // update acceleration, velocity, and position of each planet
        for(int i=0; i<num_planets; i++){
            update_acceleration(planets, num_planets, i);
            update_velocity(&planets[i], dt);
            update_position(&planets[i], dt);
        }
        // print positions of planets every 10 time steps
        if(t % 10 == 0){
            printf("Time step %d:\n", t);
            for(int i=0; i<num_planets; i++){
                printf("Planet %d: x = %.2f, y = %.2f\n", i, planets[i].x, planets[i].y);
            }
            printf("\n");
        }
    }
    return 0;
}