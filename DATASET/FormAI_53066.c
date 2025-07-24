//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: protected
#include <stdio.h>

//created a structure for planet data
typedef struct {
    double x, y; //position
    double vx, vy; //velocity
    double mass; //mass
} Planet;

//function to calculate distance between two planets
double distance(Planet p1, Planet p2){
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

//function to calculate force between two planets
//using Newton's Law of Universal Gravitation
double force(Planet p1, Planet p2){
    double G = 6.674e-11; //gravitational constant
    double r = distance(p1, p2);
    return G * p1.mass * p2.mass / (r * r);
}

//function to calculate acceleration on a planet
double acceleration(Planet p, double fx, double fy){
    return fx / p.mass, fy / p.mass;
}

int main(){

    //create an array of 3 planets
    Planet planets[3] = {
        {0, 0, 0, 0, 5.97e24}, //earth
        {384400000, 0, 0, 1022, 7.35e22}, //moon
        {6.37e6, 0, 0, 0, 1000} //ball
    };

    //define time step and duration
    double dt = 0.1;
    double t = 0;
    double duration = 1000;

    //simulate the motion of the planets
    while(t < duration){
        //for each planet
        for(int i = 0; i < 3; i++){
            //calculate the total force acting on the planet
            double fx = 0;
            double fy = 0;
            for(int j = 0; j < 3; j++){
                if(i == j) continue; //skip itself
                double f = force(planets[i], planets[j]);
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                fx += f * dx / distance(planets[i], planets[j]);
                fy += f * dy / distance(planets[i], planets[j]);
            }
            //calculate the acceleration of the planet
            double ax = acceleration(planets[i], fx, fy);
            double ay = acceleration(planets[i], fy, fx);
            //update the velocity of the planet
            planets[i].vx += ax * dt;
            planets[i].vy += ay * dt;
            //update the position of the planet
            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
        }
        //increment time step
        t += dt;
    }

    //print the final position of each planet
    for(int i = 0; i < 3; i++){
        printf("Planet %d: (%.2f, %.2f)\n", i, planets[i].x, planets[i].y);
    }

    return 0;
}