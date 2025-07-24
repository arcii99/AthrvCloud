//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Donald Knuth
#include<stdio.h>
#include<math.h>

//Structure for planets
struct planet{
    char name[10];
    float mass;
    float radius;
    float posx;
    float posy;
    float velx;
    float vely;
};

int main(){
    //Initializing planets
    struct planet earth = {"Earth", 5.9*pow(10,24), 6.4*pow(10,6), 0, 149.6*pow(10,9), 0, 29.5*pow(10,3)};
    struct planet sun = {"Sun", 1.9*pow(10,30), 6.95*pow(10,8), 0, 0, 0, 0};
    struct planet mars = {"Mars", 6.4*pow(10,23), 3.4*pow(10,6), 0, 227.9*pow(10,9), 0, 24.1*pow(10,3)};
    
    //Declaring variables
    float G = 6.67*pow(10,-11);
    float t = 0.01;
    float compx, compy, dist, force;
    int i;
    
    //Calculating and updating positions and velocities
    for(i=1; i<=10000; i++){
        //Calculating Earth's position and velocity
        compx = sun.posx - earth.posx;
        compy = sun.posy - earth.posy;
        dist = sqrt(pow(compx,2) + pow(compy,2));
        force = (G*earth.mass*sun.mass)/pow(dist,2);
        earth.velx += (force/earth.mass)*(compx/dist)*t;
        earth.vely += (force/earth.mass)*(compy/dist)*t;
        earth.posx += earth.velx*t;
        earth.posy += earth.vely*t;
        
        //Calculating Mars' position and velocity
        compx = sun.posx - mars.posx;
        compy = sun.posy - mars.posy;
        dist = sqrt(pow(compx,2) + pow(compy,2));
        force = (G*mars.mass*sun.mass)/pow(dist,2);
        mars.velx += (force/mars.mass)*(compx/dist)*t;
        mars.vely += (force/mars.mass)*(compy/dist)*t;
        mars.posx += mars.velx*t;
        mars.posy += mars.vely*t;
        
        //Updating Sun's position (stationary)
        sun.posx = 0;
        sun.posy = 0;
    }
    
    //Printing final positions of planets
    printf("%s's final position: (%f, %f)\n", earth.name, earth.posx, earth.posy);
    printf("%s's final position: (%f, %f)\n", mars.name, mars.posx, mars.posy);
    printf("%s's final position: (%f, %f)\n", sun.name, sun.posx, sun.posy);
    
    return 0;
}