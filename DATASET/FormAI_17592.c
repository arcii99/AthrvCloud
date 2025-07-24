//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: artistic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define SUN_RADIUS 20.0
#define EARTH_RADIUS 10.0
#define MOON_RADIUS 3.5

#define SUN_MASS 1989000.0
#define EARTH_MASS 5.97
#define MOON_MASS 0.0735

#define EARTH_ORBIT 100.0
#define MOON_ORBIT 20.0

#define G 6.67430e-11

typedef struct {
    double x;
    double y;
} vec2d;

typedef struct {
    vec2d position;
    vec2d velocity;
    double mass;
    double radius;
} celestial_body;

int main() {
    celestial_body sun = {{0, 0}, {0, 0}, SUN_MASS, SUN_RADIUS};
    celestial_body earth = {{-EARTH_ORBIT, 0}, {0, sqrt((G * SUN_MASS) / (EARTH_ORBIT))}, EARTH_MASS, EARTH_RADIUS};
    celestial_body moon = {{-EARTH_ORBIT - MOON_ORBIT, 0}, {0, sqrt((G * EARTH_MASS) / (MOON_ORBIT))}, MOON_MASS, MOON_RADIUS};

    double time_step = 3600.0;
    double duration = 24.0 * 60.0 * 60.0 * 365.0;
    double current_time = 0.0;

    while (current_time < duration) {
        vec2d moon_to_earth = {earth.position.x - moon.position.x, earth.position.y - moon.position.y};
        double moon_to_earth_distance = sqrt(pow(moon_to_earth.x, 2) + pow(moon_to_earth.y, 2));
        vec2d moon_gravity_pull = {moon_to_earth.x / moon_to_earth_distance, moon_to_earth.y / moon_to_earth_distance};
        moon_gravity_pull.x *= G * earth.mass * moon.mass / pow(moon_to_earth_distance, 2);
        moon_gravity_pull.y *= G * earth.mass * moon.mass / pow(moon_to_earth_distance, 2);

        vec2d earth_to_sun = {sun.position.x - earth.position.x, sun.position.y - earth.position.y};
        double earth_to_sun_distance = sqrt(pow(earth_to_sun.x, 2) + pow(earth_to_sun.y, 2));
        vec2d earth_gravity_pull = {earth_to_sun.x / earth_to_sun_distance, earth_to_sun.y / earth_to_sun_distance};
        earth_gravity_pull.x *= G * sun.mass * earth.mass / pow(earth_to_sun_distance, 2);
        earth_gravity_pull.y *= G * sun.mass * earth.mass / pow(earth_to_sun_distance, 2);

        moon.velocity.x += moon_gravity_pull.x * time_step / moon.mass;
        moon.velocity.y += moon_gravity_pull.y * time_step / moon.mass;

        earth.velocity.x += earth_gravity_pull.x * time_step / earth.mass;
        earth.velocity.y += earth_gravity_pull.y * time_step / earth.mass;

        sun.velocity.x = 0;
        sun.velocity.y = 0;

        moon.position.x += moon.velocity.x * time_step;
        moon.position.y += moon.velocity.y * time_step;

        earth.position.x += earth.velocity.x * time_step;
        earth.position.y += earth.velocity.y * time_step;

        printf("\033[H\033[J");
        for (int i = (int)(SUN_RADIUS + 10); i >= 0; --i) {
            for (int j = 0; j < (int)(SUN_RADIUS + EARTH_ORBIT + MOON_ORBIT + 50); ++j) {
                vec2d position = {j - SUN_RADIUS - EARTH_ORBIT - MOON_ORBIT, i};
                double earth_distance_to_position = sqrt(pow(position.x - earth.position.x, 2) + pow(position.y - earth.position.y, 2));
                double moon_distance_to_position = sqrt(pow(position.x - moon.position.x, 2) + pow(position.y - moon.position.y, 2));
                double sun_distance_to_position = sqrt(pow(position.x, 2) + pow(position.y, 2));
                if (sun_distance_to_position < SUN_RADIUS) {
                    printf("*");
                } else if (earth_distance_to_position < EARTH_RADIUS) {
                    printf("o");
                } else if (moon_distance_to_position < MOON_RADIUS) {
                    printf("x");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("EARTH POSITION: x=%lf y=%lf\n", earth.position.x, earth.position.y);
        printf("MOON POSITION: x=%lf y=%lf\n", moon.position.x, moon.position.y);
        usleep(10000);
        current_time += time_step;
    }

    return 0;
}