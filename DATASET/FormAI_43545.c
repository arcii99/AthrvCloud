//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int cars_count = 10;
    int cars_speed_limit = 55; // km/h
    int road_length = 1500; // meters
    int max_acceleration_rate = 2; // m/s^2
    int max_deceleration_rate = 5; // m/s^2
    int time_step = 1; // second

    float cars_position[cars_count]; // in meters
    float cars_velocity[cars_count]; // in m/s
    float cars_acceleration[cars_count]; // in m/s^2

    // initialize cars positions and velocities
    for (int i = 0; i < cars_count; i++) {
        cars_position[i] = (float)rand()/(float)(RAND_MAX/road_length);
        cars_velocity[i] = (float)rand()/(float)(RAND_MAX/cars_speed_limit);
        cars_acceleration[i] = 0;
    }

    // simulation loop
    for (int t = 0; t <= 3600; t += time_step) { // run for one hour

        // print current state of the road
        printf("Time %d:\n", t);
        for (int i = 0; i < road_length; i += 10) {
            int cars_on_this_segment = 0;
            for (int j = 0; j < cars_count; j++) {
                if (cars_position[j] > i && cars_position[j] <= i+10)
                    cars_on_this_segment++;
            }
            if (cars_on_this_segment > 0)
                printf("%d cars on segment [%d, %d]\n", cars_on_this_segment, i, i+10);
        }

        // update cars positions and velocities based on their acceleration
        for (int i = 0; i < cars_count; i++) {
            cars_position[i] += cars_velocity[i]*time_step + 0.5*cars_acceleration[i]*time_step*time_step;
            cars_velocity[i] += cars_acceleration[i]*time_step;
            if (cars_velocity[i] > cars_speed_limit/3.6) // convert from km/h to m/s
                cars_velocity[i] = cars_speed_limit/3.6;
            if (cars_velocity[i] < 0)
                cars_velocity[i] = 0;
        }

        // assign new accelerations to cars based on traffic rules and behavior
        for (int i = 0; i < cars_count; i++) {
            float gap_in_front = road_length; // in meters
            float speed_in_front = cars_speed_limit; // in m/s
            for (int j = 0; j < cars_count; j++) {
                if (cars_position[j] > cars_position[i] && cars_position[j] - cars_position[i] < gap_in_front) {
                    gap_in_front = cars_position[j] - cars_position[i];
                    speed_in_front = cars_velocity[j];
                }
            }
            if (gap_in_front > cars_velocity[i]*3) {
                float desired_speed = cars_speed_limit*(1 - gap_in_front/(3*cars_velocity[i]));
                if (desired_speed > speed_in_front)
                    desired_speed = speed_in_front;
                cars_acceleration[i] = (desired_speed - cars_velocity[i])/time_step;
                if (cars_acceleration[i] > max_acceleration_rate)
                    cars_acceleration[i] = max_acceleration_rate;
            } else if (gap_in_front > cars_velocity[i]*2) {
                float desired_speed = cars_speed_limit*(2 - gap_in_front/(2*cars_velocity[i]))/3;
                if (desired_speed > speed_in_front)
                    desired_speed = speed_in_front;
                cars_acceleration[i] = (desired_speed - cars_velocity[i])/time_step;
                if (cars_acceleration[i] > max_acceleration_rate)
                    cars_acceleration[i] = max_acceleration_rate;
            } else {
                cars_acceleration[i] = -max_deceleration_rate;
            }
        }
    }

    return 0;
}