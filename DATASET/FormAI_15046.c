//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: light-weight
#include <stdio.h>
#include <math.h>

#define G 6.674e-11  // universal gravitational constant
#define TIMESTEP 86400  // simulation timestep in seconds

struct Vec3
{
    double x, y, z;
};

struct CelestialBody
{
    char name[50];
    double mass;  // in kg
    struct Vec3 pos;  // in m
    struct Vec3 vel;  // in m/s
};

// calculates gravitational force between two celestial bodies
struct Vec3 calcForce(struct CelestialBody* body1, struct CelestialBody* body2)
{
    double dist = sqrt(pow(body1->pos.x - body2->pos.x, 2) + pow(body1->pos.y - body2->pos.y, 2) + pow(body1->pos.z - body2->pos.z, 2));
    double forceMag = G * body1->mass * body2->mass / pow(dist, 2);
    struct Vec3 force;
    force.x = forceMag * (body2->pos.x - body1->pos.x) / dist;
    force.y = forceMag * (body2->pos.y - body1->pos.y) / dist;
    force.z = forceMag * (body2->pos.z - body1->pos.z) / dist;
    return force;
}

int main()
{
    // create celestial bodies
    struct CelestialBody sun = {"Sun", 1.989e30, {0, 0, 0}, {0, 0, 0}};
    struct CelestialBody earth = {"Earth", 5.9742e24, {149.6e9, 0, 0}, {0, 29.78e3, 0}};
    struct CelestialBody moon = {"Moon", 7.342e22, {149.6e9, 384.4e6, 0}, {-1.02e3, 29.78e3, 0}};

    // simulation loop
    for (int i = 0; i < 365; i++)
    {
        // calculate forces on bodies
        struct Vec3 forceSunEarth = calcForce(&sun, &earth);
        struct Vec3 forceEarthSun = {-forceSunEarth.x, -forceSunEarth.y, -forceSunEarth.z};
        struct Vec3 forceEarthMoon = calcForce(&earth, &moon);
        struct Vec3 forceMoonEarth = {-forceEarthMoon.x, -forceEarthMoon.y, -forceEarthMoon.z};
        struct Vec3 forceMoonSun = calcForce(&moon, &sun);
        struct Vec3 forceSunMoon = {-forceMoonSun.x, -forceMoonSun.y, -forceMoonSun.z};

        // update velocities and positions based on forces
        earth.vel.x += (forceSunEarth.x + forceEarthMoon.x) / earth.mass * TIMESTEP;
        earth.vel.y += (forceSunEarth.y + forceEarthMoon.y) / earth.mass * TIMESTEP;
        earth.vel.z += (forceSunEarth.z + forceEarthMoon.z) / earth.mass * TIMESTEP;
        earth.pos.x += earth.vel.x * TIMESTEP;
        earth.pos.y += earth.vel.y * TIMESTEP;
        earth.pos.z += earth.vel.z * TIMESTEP;

        moon.vel.x += (forceEarthMoon.x + forceMoonSun.x) / moon.mass * TIMESTEP;
        moon.vel.y += (forceEarthMoon.y + forceMoonSun.y) / moon.mass * TIMESTEP;
        moon.vel.z += (forceEarthMoon.z + forceMoonSun.z) / moon.mass * TIMESTEP;
        moon.pos.x += moon.vel.x * TIMESTEP;
        moon.pos.y += moon.vel.y * TIMESTEP;
        moon.pos.z += moon.vel.z * TIMESTEP;

        // print positions of earth and moon
        printf("Day %d:\n", i + 1);
        printf("\t%s: (%e, %e, %e)\n", earth.name, earth.pos.x, earth.pos.y, earth.pos.z);
        printf("\t%s: (%e, %e, %e)\n", moon.name, moon.pos.x, moon.pos.y, moon.pos.z);
    }

    return 0;
}