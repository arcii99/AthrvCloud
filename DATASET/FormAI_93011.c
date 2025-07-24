//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Cryptic
#include<stdio.h>
#define SECONDS_IN_DAY 86400.0
#define G 6.674e-11
#define SUN_MASS 1.98847e30
#define EARTH_MASS 5.97e24
#define AU 149.6e9
#define EARTH_ORBIT_VELOCITY 29.78e3
#define YEAR_IN_SECONDS 31556952.0

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main() {
    // setting initial conditions for the bodies
    double sun_x = 0, sun_y = 0, sun_vx = 0, sun_vy = 0, sun_ax = 0, sun_ay = 0, sun_mass = SUN_MASS;
    double earth_x = AU, earth_y = 0, earth_vx = 0, earth_vy = EARTH_ORBIT_VELOCITY, earth_ax = 0, earth_ay = 0, earth_mass = EARTH_MASS;

    double time_step = 1000;
    double current_time = 0;
    int number_of_iterations = 365;

    for(int i=0; i<number_of_iterations; i++) {
        double distance_between_bodies = distance(sun_x, sun_y, earth_x, earth_y);
        double force_between_bodies = G*sun_mass*earth_mass/(distance_between_bodies*distance_between_bodies);

        sun_ax = force_between_bodies/sun_mass;
        sun_ay = force_between_bodies/sun_mass;

        earth_ax = force_between_bodies/earth_mass;
        earth_ay = force_between_bodies/earth_mass;

        sun_vx += sun_ax*time_step;
        sun_vy += sun_ay*time_step;

        earth_vx += earth_ax*time_step;
        earth_vy += earth_ay*time_step;

        sun_x += sun_vx*time_step;
        sun_y += sun_vy*time_step;

        earth_x += earth_vx*time_step;
        earth_y += earth_vy*time_step;

        printf("Current Time: %f seconds \n", current_time);
        printf("Sun Position: x=%f y=%f\n", sun_x, sun_y);
        printf("Earth Postion: x=%f y=%f\n", earth_x, earth_y);
        printf("\n");

        current_time += time_step;
    }

    return 0;
}