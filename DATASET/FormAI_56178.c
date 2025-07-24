//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define G 6.6743E-11 // Gravitational constant
#define M_sun 1.9891E30 // Mass of the sun
#define M_mercury 3.3011E23 // Mass of mercury
#define M_venus 4.8675E24 // Mass of Venus
#define M_earth 5.9722E24 // Mass of Earth
#define M_mars 6.4171E23 // Mass of Mars
#define M_jupiter 1.8982E27 // Mass of Jupiter
#define M_saturn 5.6834E26 // Mass of Saturn
#define M_uranus 8.6810E25 // Mass of Uranus
#define M_neptune 1.0241E26 // Mass of Neptune
#define T 31536000 // Time in seconds for one Earth year

// Defining structure celestial_body
typedef struct celestial_body
{
    char name[20]; // Name of the planet
    double mass; // Mass of planet in kg
    double radius; // Radius of planet in km
    double x, y, z; // Position of planet in 3D space
    double vx, vy, vz; // Velocity of planet in 3D space
    double ax, ay, az; // Acceleration of planet in 3D space
}celestial_body;

// Defining function to calculate distance between two celestial bodies
double distance(celestial_body body1, celestial_body body2)
{
    return sqrt(pow((body1.x - body2.x), 2) + pow((body1.y - body2.y), 2) + pow((body1.z - body2.z), 2));
}

int main()
{
    // Initializing structure for each planet
    celestial_body sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune;
    
    // Initializing initial values for each planet
    sun.mass = M_sun;
    sun.radius = 695508; // Radius of the sun in km
    sun.x = sun.y = sun.z = sun.vx = sun.vy = sun.vz = sun.ax = sun.ay = sun.az = 0; // Sun is at the center of the solar system
    
    strcpy(mercury.name, "Mercury");
    mercury.mass = M_mercury;
    mercury.radius = 2439.7;
    mercury.x = 57910000;
    mercury.y = 0;
    mercury.z = 0;
    mercury.vx = 0;
    mercury.vy = 47360; // Velocity of Mercury in km/s
    mercury.vz = 0;
    
    strcpy(venus.name, "Venus");
    venus.mass = M_venus;
    venus.radius = 6051.8;
    venus.x = 108200000;
    venus.y = 0;
    venus.z = 0;
    venus.vx = 0;
    venus.vy = 35020; // Velocity of Venus in km/s
    venus.vz = 0;
    
    strcpy(earth.name, "Earth");
    earth.mass = M_earth;
    earth.radius = 6371;
    earth.x = 147095000;
    earth.y = 0;
    earth.z = 0;
    earth.vx = 0;
    earth.vy = 29780; // Velocity of Earth in km/s
    earth.vz = 0;
    
    strcpy(mars.name, "Mars");
    mars.mass = M_mars;
    mars.radius = 3389.5;
    mars.x = 206620000;
    mars.y = 0;
    mars.z = 0;
    mars.vx = 0;
    mars.vy = 24077; // Velocity of Mars in km/s
    mars.vz = 0;
    
    strcpy(jupiter.name, "Jupiter");
    jupiter.mass = M_jupiter;
    jupiter.radius = 69911;
    jupiter.x = 740520000;
    jupiter.y = 0;
    jupiter.z = 0;
    jupiter.vx = 0;
    jupiter.vy = 130700; // Velocity of Jupiter in km/s
    jupiter.vz = 0;
    
    strcpy(saturn.name, "Saturn");
    saturn.mass = M_saturn;
    saturn.radius = 58232;
    saturn.x = 1349820000;
    saturn.y = 0;
    saturn.z = 0;
    saturn.vx = 0;
    saturn.vy = 9640; // Velocity of Saturn in km/s
    saturn.vz = 0;
    
    strcpy(uranus.name, "Uranus");
    uranus.mass = M_uranus;
    uranus.radius = 25362;
    uranus.x = 2735590000;
    uranus.y = 0;
    uranus.z = 0;
    uranus.vx = 0;
    uranus.vy = 6800; // Velocity of Uranus in km/s
    uranus.vz = 0;
    
    strcpy(neptune.name, "Neptune");
    neptune.mass = M_neptune;
    neptune.radius = 24622;
    neptune.x = 4452940000;
    neptune.y = 0;
    neptune.z = 0;
    neptune.vx = 0;
    neptune.vy = 5430; // Velocity of Neptune in km/s
    neptune.vz = 0;
    
    int i, j;
    double r, f;
    double dt = 60; // Time step in seconds
    double time = 0; // Current time in seconds
    
    // Simulation loop
    while(time < (100 * T))
    {
        // Calculating acceleration for each planet
        for(i = 0; i < 9; i++)
        {
            celestial_body *body1, *body2;
            double ax = 0, ay = 0, az = 0;
            body1 = &sun;
            switch(i)
            {
                case 0:
                    body2 = &mercury;
                    break;
                case 1:
                    body2 = &venus;
                    break;
                case 2:
                    body2 = &earth;
                    break;
                case 3:
                    body2 = &mars;
                    break;
                case 4:
                    body2 = &jupiter;
                    break;
                case 5:
                    body2 = &saturn;
                    break;
                case 6:
                    body2 = &uranus;
                    break;
                case 7:
                    body2 = &neptune;
                    break;
            }
            r = distance(*body1, *body2);
            f = G * body1->mass * body2->mass / pow(r, 2);
            ax += f * (body2->x - body1->x) / r / body2->mass;
            ay += f * (body2->y - body1->y) / r / body2->mass;
            az += f * (body2->z - body1->z) / r / body2->mass;
            
            // Updating acceleration for each planet
            switch(i)
            {
                case 0:
                    mercury.ax = ax;
                    mercury.ay = ay;
                    mercury.az = az;
                    break;
                case 1:
                    venus.ax = ax;
                    venus.ay = ay;
                    venus.az = az;
                    break;
                case 2:
                    earth.ax = ax;
                    earth.ay = ay;
                    earth.az = az;
                    break;
                case 3:
                    mars.ax = ax;
                    mars.ay = ay;
                    mars.az = az;
                    break;
                case 4:
                    jupiter.ax = ax;
                    jupiter.ay = ay;
                    jupiter.az = az;
                    break;
                case 5:
                    saturn.ax = ax;
                    saturn.ay = ay;
                    saturn.az = az;
                    break;
                case 6:
                    uranus.ax = ax;
                    uranus.ay = ay;
                    uranus.az = az;
                    break;
                case 7:
                    neptune.ax = ax;
                    neptune.ay = ay;
                    neptune.az = az;
                    break;
            }
        }

        // Updating velocity and position for each planet using acceleration
        mercury.vx += mercury.ax * dt;
        mercury.vy += mercury.ay * dt;
        mercury.vz += mercury.az * dt;
        mercury.x += mercury.vx * dt;
        mercury.y += mercury.vy * dt;
        mercury.z += mercury.vz * dt;
        
        venus.vx += venus.ax * dt;
        venus.vy += venus.ay * dt;
        venus.vz += venus.az * dt;
        venus.x += venus.vx * dt;
        venus.y += venus.vy * dt;
        venus.z += venus.vz * dt;
        
        earth.vx += earth.ax * dt;
        earth.vy += earth.ay * dt;
        earth.vz += earth.az * dt;
        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;
        earth.z += earth.vz * dt;
        
        mars.vx += mars.ax * dt;
        mars.vy += mars.ay * dt;
        mars.vz += mars.az * dt;
        mars.x += mars.vx * dt;
        mars.y += mars.vy * dt;
        mars.z += mars.vz * dt;
        
        jupiter.vx += jupiter.ax * dt;
        jupiter.vy += jupiter.ay * dt;
        jupiter.vz += jupiter.az * dt;
        jupiter.x += jupiter.vx * dt;
        jupiter.y += jupiter.vy * dt;
        jupiter.z += jupiter.vz * dt;
        
        saturn.vx += saturn.ax * dt;
        saturn.vy += saturn.ay * dt;
        saturn.vz += saturn.az * dt;
        saturn.x += saturn.vx * dt;
        saturn.y += saturn.vy * dt;
        saturn.z += saturn.vz * dt;
        
        uranus.vx += uranus.ax * dt;
        uranus.vy += uranus.ay * dt;
        uranus.vz += uranus.az * dt;
        uranus.x += uranus.vx * dt;
        uranus.y += uranus.vy * dt;
        uranus.z += uranus.vz * dt;
        
        neptune.vx += neptune.ax * dt;
        neptune.vy += neptune.ay * dt;
        neptune.vz += neptune.az * dt;
        neptune.x += neptune.vx * dt;
        neptune.y += neptune.vy * dt;
        neptune.z += neptune.vz * dt;
        
        time += dt;
        
        // Printing position of each planet after each day
        if(fmod(time, T) == 0)
        {
            printf("Day %d\n", (int)(time/T));
            printf("Sun: (%.2f, %.2f, %.2f)\n", sun.x, sun.y, sun.z);
            printf("Mercury: (%.2f, %.2f, %.2f)\n", mercury.x, mercury.y, mercury.z);
            printf("Venus: (%.2f, %.2f, %.2f)\n", venus.x, venus.y, venus.z);
            printf("Earth: (%.2f, %.2f, %.2f)\n", earth.x, earth.y, earth.z);
            printf("Mars: (%.2f, %.2f, %.2f)\n", mars.x, mars.y, mars.z);
            printf("Jupiter: (%.2f, %.2f, %.2f)\n", jupiter.x, jupiter.y, jupiter.z);
            printf("Saturn: (%.2f, %.2f, %.2f)\n", saturn.x, saturn.y, saturn.z);
            printf("Uranus: (%.2f, %.2f, %.2f)\n", uranus.x, uranus.y, uranus.z);
            printf("Neptune: (%.2f, %.2f, %.2f)\n", neptune.x, neptune.y, neptune.z);
        }
    }
    
    return 0;
}