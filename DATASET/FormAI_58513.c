//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: curious
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#define GRAV_CONST 0.000000000067     //Gravitational constant
#define TIME_SCALE 86400             //Simulation time scale (1 day in seconds)

typedef struct {
    double xpos;
    double ypos;
    double xvel;
    double yvel;
    double mass;
} Body;

//Function Declarations
void update_velocity(Body* body_arr, int num_bodies, double time);
void update_position(Body* body_arr, int num_bodies, double time);
double calc_distance(Body body1, Body body2);
void simulate(Body* body_arr, int num_bodies, int num_steps);

int main() {
    srand(time(NULL));             //Initialize random number generator
    int num_bodies = 9;
    Body body_arr[] = {           //Initial conditions of each planet
        {0, 0, 0, 0, 1.98 * pow(10,30)},          //Sun
        {57.9 * pow(10,9), 0, 0, 47.4 * pow(10,3), 3.3 * pow(10,23)},     //Mercury
        {108.2 * pow(10,9), 0, 0, 35.0 * pow(10,3), 4.87 * pow(10,24)},    //Venus
        {149.6 * pow(10,9), 0, 0, 29.8 * pow(10,3), 5.97 * pow(10,24)},    //Earth
        {227.9 * pow(10,9), 0, 0, 24.1 * pow(10,3), 6.42 * pow(10,23)},    //Mars
        {778.6 * pow(10,9), 0, 0, 13.1 * pow(10,3), 1.90 * pow(10,27)},    //Jupiter
        {1433.5 * pow(10,9), 0, 0, 9.7 * pow(10,3), 5.69 * pow(10,26)},    //Saturn
        {2872.5 * pow(10,9), 0, 0, 6.8 * pow(10,3), 8.68 * pow(10,25)},    //Uranus
        {4495.1 * pow(10,9), 0, 0, 5.4 * pow(10,3), 1.02 * pow(10,26)}     //Neptune
    };
    simulate(body_arr, num_bodies, 20000);           //Simulation runs for 20000 time steps
    return 0;
}

//This function updates the velocity of each body
void update_velocity(Body* body_arr, int num_bodies, double time) {
    int i, j;
    double x_diff, y_diff, distance, force;
    for (i = 0; i < num_bodies; i++) {
        for (j = 0; j < num_bodies; j++) {
            if (i != j) {         //Checking if the body is interacting with itself
                x_diff = body_arr[j].xpos - body_arr[i].xpos;
                y_diff = body_arr[j].ypos - body_arr[i].ypos;
                distance = sqrt(pow(x_diff, 2) + pow(y_diff, 2));     //Distance formula
                force = GRAV_CONST * body_arr[i].mass * body_arr[j].mass / pow(distance, 2);   //Gravitational force formula
                body_arr[i].xvel += force * time * x_diff / (distance * body_arr[i].mass);     //Velocity update formula
                body_arr[i].yvel += force * time * y_diff / (distance * body_arr[i].mass);
            }
        }
    }
}

//This function updates the position of each body
void update_position(Body* body_arr, int num_bodies, double time) {
    int i;
    for (i = 0; i < num_bodies; i++) {
        body_arr[i].xpos += body_arr[i].xvel * time;   //Position update formula
        body_arr[i].ypos += body_arr[i].yvel * time;
    }
}

double calc_distance(Body body1, Body body2) {
    double x_diff = body1.xpos - body2.xpos;
    double y_diff = body1.ypos - body2.ypos;
    return sqrt(pow(x_diff, 2) + pow(y_diff, 2));
}

//This function simulates the solar system
void simulate(Body* body_arr, int num_bodies, int num_steps) {
    int i, j;
    for (i = 0; i < num_steps; i++) {
        printf("Day %d:\n", i+1);    //Simulation happens one day at a time
        for (j = 0; j < num_bodies; j++) {
            printf("Body %d: X Position: %lf Y Position: %lf\n", j+1, body_arr[j].xpos, body_arr[j].ypos);
        }
        update_velocity(body_arr, num_bodies, TIME_SCALE);
        update_position(body_arr, num_bodies, TIME_SCALE);
    }
}