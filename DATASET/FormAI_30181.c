//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAV_CONST 6.67430E-11 // gravitational constant in m^3 kg^-1 s^-2
#define SECOND_IN_DAY 86400 // seconds in one day
#define AU 1.495978707E11 // astronomical unit in meters

struct celestial_body {
    char name[20]; // name of the celestial body
    long double mass; // mass of the celestial body in kg
    long double radius; // radius of the celestial body in meters
    long double x_pos; // x-coordinate position of the celestial body in meters
    long double y_pos; // y-coordinate position of the celestial body in meters
    long double z_pos; // z-coordinate position of the celestial body in meters
    long double x_vel; // x-coordinate velocity of the celestial body in m/s
    long double y_vel; // y-coordinate velocity of the celestial body in m/s
    long double z_vel; // z-coordinate velocity of the celestial body in m/s
};

void calculate_velocities(struct celestial_body* cb1, struct celestial_body* cb2, double time_diff) {
    long double distance = sqrt(pow((cb2->x_pos - cb1->x_pos), 2) + pow((cb2->y_pos - cb1->y_pos), 2) + pow((cb2->z_pos - cb1->z_pos), 2)); // distance between the two celestial bodies
    long double force = GRAV_CONST * cb1->mass * cb2->mass / pow(distance, 2); // gravitational force between the two celestial bodies
    long double acceleration = force / cb1->mass; // acceleration on cb1 due to cb2
    long double time_diff_seconds = time_diff * SECOND_IN_DAY; // convert time difference to seconds
    long double x_vel_diff = acceleration * time_diff_seconds * (cb2->x_pos - cb1->x_pos) / distance; // change in x-velocity of cb1
    long double y_vel_diff = acceleration * time_diff_seconds * (cb2->y_pos - cb1->y_pos) / distance; // change in y-velocity of cb1
    long double z_vel_diff = acceleration * time_diff_seconds * (cb2->z_pos - cb1->z_pos) / distance; // change in z-velocity of cb1
    
    cb1->x_vel += x_vel_diff; // update x-velocity of cb1
    cb1->y_vel += y_vel_diff; // update y-velocity of cb1
    cb1->z_vel += z_vel_diff; // update z-velocity of cb1
}

void update_positions(struct celestial_body* cb, double time_diff) {
    long double time_diff_seconds = time_diff * SECOND_IN_DAY; // convert time difference to seconds
    cb->x_pos += time_diff_seconds * cb->x_vel; // update x-position of the celestial body
    cb->y_pos += time_diff_seconds * cb->y_vel; // update y-position of the celestial body
    cb->z_pos += time_diff_seconds * cb->z_vel; // update z-position of the celestial body
}

int main() {
    srand(time(0)); // seed the random number generator
    
    struct celestial_body sun = {"Sun", 1.989E30, 696340000, 0, 0, 0, 0, 0, 0}; // create the sun
    struct celestial_body earth = {"Earth", 5.9736E24, 6371000, AU, 0, 0, 0, 29783, 0}; // create the earth
    struct celestial_body moon = {"Moon", 7.342E22, 1737100, AU + 384400000, 0, 0, 0, 3075 + 29783, 0}; // create the moon
    
    double time_diff = 0.1; // time difference in days
    
    for (int i = 0; i < 36500; i++) { // simulate the solar system for 3650 earth days (10 earth years)
        // update velocities and positions of the moon due to the earth
        calculate_velocities(&earth, &moon, time_diff);
        update_positions(&moon, time_diff);
        
        // update velocities and positions of the earth due to the sun
        calculate_velocities(&sun, &earth, time_diff);
        update_positions(&earth, time_diff);
        
        // update velocities and positions of the moon due to the earth's gravity and the sun's gravity
        calculate_velocities(&moon, &earth, time_diff);
        calculate_velocities(&moon, &sun, time_diff);
        update_positions(&moon, time_diff);
        
        printf("Day %d\n", i+1);
        printf("Earth x-position: %Lf m\n", earth.x_pos);
        printf("Earth y-position: %Lf m\n", earth.y_pos);
        printf("Earth z-position: %Lf m\n", earth.z_pos);
        printf("Earth x-velocity: %Lf m/s\n", earth.x_vel);
        printf("Earth y-velocity: %Lf m/s\n", earth.y_vel);
        printf("Earth z-velocity: %Lf m/s\n", earth.z_vel);
        printf("Moon x-position: %Lf m\n", moon.x_pos);
        printf("Moon y-position: %Lf m\n", moon.y_pos);
        printf("Moon z-position: %Lf m\n", moon.z_pos);
        printf("Moon x-velocity: %Lf m/s\n", moon.x_vel);
        printf("Moon y-velocity: %Lf m/s\n", moon.y_vel);
        printf("Moon z-velocity: %Lf m/s\n\n", moon.z_vel);
    }
    
    return 0;
}