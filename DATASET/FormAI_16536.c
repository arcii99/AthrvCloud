//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.673E-11
#define DT 3600*24

struct planet {
    double x, y, z;  //position
    double vx, vy, vz;  //velocity
    double ax, ay, az;  //acceleration
    double m;  //mass
};

int main() {
    //initialize the planets
    struct planet sun = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1.989E30};
    struct planet mercury = {-5.7E10, 0, 0, 0, 47400, 0, 0, 0, 0, 0.33E24};
    struct planet venus = {-1.1E11, 0, 0, 0, 35000, 0, 0, 0, 0, 4.87E24};
    struct planet earth = {0, 1.5E11, 0, -29780, 0, 0, 0, 0, 0, 5.97E24};
    struct planet mars = {0, -2.2E11, 0, 24000, 0, 0, 0, 0, 0, 0.642E24};
    
    //calculate the initial gravitational forces
    double r, fx, fy, fz;
    r = sqrt(pow(mercury.x-sun.x, 2) + pow(mercury.y-sun.y, 2) + pow(mercury.z-sun.z, 2));
    fx = G * sun.m * mercury.m * (mercury.x - sun.x) / pow(r, 3);
    fy = G * sun.m * mercury.m * (mercury.y - sun.y) / pow(r, 3);
    fz = G * sun.m * mercury.m * (mercury.z - sun.z) / pow(r, 3);
    mercury.ax = fx / mercury.m;
    mercury.ay = fy / mercury.m;
    mercury.az = fz / mercury.m;
    r = sqrt(pow(venus.x-sun.x, 2) + pow(venus.y-sun.y, 2) + pow(venus.z-sun.z, 2));
    fx = G * sun.m * venus.m * (venus.x - sun.x) / pow(r, 3);
    fy = G * sun.m * venus.m * (venus.y - sun.y) / pow(r, 3);
    fz = G * sun.m * venus.m * (venus.z - sun.z) / pow(r, 3);
    venus.ax = fx / venus.m;
    venus.ay = fy / venus.m;
    venus.az = fz / venus.m;
    r = sqrt(pow(earth.x-sun.x, 2) + pow(earth.y-sun.y, 2) + pow(earth.z-sun.z, 2));
    fx = G * sun.m * earth.m * (earth.x - sun.x) / pow(r, 3);
    fy = G * sun.m * earth.m * (earth.y - sun.y) / pow(r, 3);
    fz = G * sun.m * earth.m * (earth.z - sun.z) / pow(r, 3);
    earth.ax = fx / earth.m;
    earth.ay = fy / earth.m;
    earth.az = fz / earth.m;
    r = sqrt(pow(mars.x-sun.x, 2) + pow(mars.y-sun.y, 2) + pow(mars.z-sun.z, 2));
    fx = G * sun.m * mars.m * (mars.x - sun.x) / pow(r, 3);
    fy = G * sun.m * mars.m * (mars.y - sun.y) / pow(r, 3);
    fz = G * sun.m * mars.m * (mars.z - sun.z) / pow(r, 3);
    mars.ax = fx / mars.m;
    mars.ay = fy / mars.m;
    mars.az = fz / mars.m;
    
    //simulate the solar system
    int i;
    for (i = 0; i < 365*10; i++) {
        //update the positions
        mercury.x += mercury.vx * DT;
        mercury.y += mercury.vy * DT;
        mercury.z += mercury.vz * DT;
        venus.x += venus.vx * DT;
        venus.y += venus.vy * DT;
        venus.z += venus.vz * DT;
        earth.x += earth.vx * DT;
        earth.y += earth.vy * DT;
        earth.z += earth.vz * DT;
        mars.x += mars.vx * DT;
        mars.y += mars.vy * DT;
        mars.z += mars.vz * DT;
        
        //calculate the new gravitational forces
        r = sqrt(pow(mercury.x-sun.x, 2) + pow(mercury.y-sun.y, 2) + pow(mercury.z-sun.z, 2));
        fx = G * sun.m * mercury.m * (mercury.x - sun.x) / pow(r, 3);
        fy = G * sun.m * mercury.m * (mercury.y - sun.y) / pow(r, 3);
        fz = G * sun.m * mercury.m * (mercury.z - sun.z) / pow(r, 3);
        mercury.ax = fx / mercury.m;
        mercury.ay = fy / mercury.m;
        mercury.az = fz / mercury.m;
        r = sqrt(pow(venus.x-sun.x, 2) + pow(venus.y-sun.y, 2) + pow(venus.z-sun.z, 2));
        fx = G * sun.m * venus.m * (venus.x - sun.x) / pow(r, 3);
        fy = G * sun.m * venus.m * (venus.y - sun.y) / pow(r, 3);
        fz = G * sun.m * venus.m * (venus.z - sun.z) / pow(r, 3);
        venus.ax = fx / venus.m;
        venus.ay = fy / venus.m;
        venus.az = fz / venus.m;
        r = sqrt(pow(earth.x-sun.x, 2) + pow(earth.y-sun.y, 2) + pow(earth.z-sun.z, 2));
        fx = G * sun.m * earth.m * (earth.x - sun.x) / pow(r, 3);
        fy = G * sun.m * earth.m * (earth.y - sun.y) / pow(r, 3);
        fz = G * sun.m * earth.m * (earth.z - sun.z) / pow(r, 3);
        earth.ax = fx / earth.m;
        earth.ay = fy / earth.m;
        earth.az = fz / earth.m;
        r = sqrt(pow(mars.x-sun.x, 2) + pow(mars.y-sun.y, 2) + pow(mars.z-sun.z, 2));
        fx = G * sun.m * mars.m * (mars.x - sun.x) / pow(r, 3);
        fy = G * sun.m * mars.m * (mars.y - sun.y) / pow(r, 3);
        fz = G * sun.m * mars.m * (mars.z - sun.z) / pow(r, 3);
        mars.ax = fx / mars.m;
        mars.ay = fy / mars.m;
        mars.az = fz / mars.m;
        
        //update the velocities
        mercury.vx += mercury.ax * DT;
        mercury.vy += mercury.ay * DT;
        mercury.vz += mercury.az * DT;
        venus.vx += venus.ax * DT;
        venus.vy += venus.ay * DT;
        venus.vz += venus.az * DT;
        earth.vx += earth.ax * DT;
        earth.vy += earth.ay * DT;
        earth.vz += earth.az * DT;
        mars.vx += mars.ax * DT;
        mars.vy += mars.ay * DT;
        mars.vz += mars.az * DT;
        
        //print the positions of the planets
        printf("Day %d:\n", i+1);
        printf("Mercury: (%.2f, %.2f, %.2f)\n", mercury.x, mercury.y, mercury.z);
        printf("Venus: (%.2f, %.2f, %.2f)\n", venus.x, venus.y, venus.z);
        printf("Earth: (%.2f, %.2f, %.2f)\n", earth.x, earth.y, earth.z);
        printf("Mars: (%.2f, %.2f, %.2f)\n\n", mars.x, mars.y, mars.z);
    }
    
    return 0;
}