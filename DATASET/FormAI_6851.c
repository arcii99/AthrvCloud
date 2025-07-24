//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPDATE_INTERVAL 2
#define MAX_SPEED 60
#define SPEED_UPDATE_PROBABILITY 0.2

void update_speeds(int* speeds, int num_cars);
void update_positions(int* positions, int* speeds, int num_cars, int time_interval);
void print_traffic(int* positions, int num_cars, int time);
double kmph_to_mps(double kmph);

int main(){
    srand(time(NULL));

    int num_cars = 10;
    int positions[num_cars];
    int speeds[num_cars];

    for (int i = 0; i < num_cars; i++) {
        positions[i] = i * 10;
        speeds[i] = rand() % MAX_SPEED + 1;
    }

    for (int t = 0; t < 5; t += UPDATE_INTERVAL) {
        update_speeds(speeds, num_cars);
        update_positions(positions, speeds, num_cars, UPDATE_INTERVAL);
        print_traffic(positions, num_cars, t);
    }

    return 0;
}

void update_speeds(int* speeds, int num_cars) {
    for (int i = 0; i < num_cars; i++) {
        if ((double) rand() / (double) RAND_MAX < SPEED_UPDATE_PROBABILITY) {
            int new_speed = rand() % MAX_SPEED + 1;
            if (new_speed > speeds[i]) {
                speeds[i] += 1;
            }
            else if (new_speed < speeds[i]) {
                speeds[i] -= 1;
            }
        }
    }
}

void update_positions(int* positions, int* speeds, int num_cars, int time_interval) {
    for (int i = 0; i < num_cars; i++) {
        int new_pos = positions[i] + speeds[i] * time_interval;
        if (new_pos > 1000) {
            new_pos = new_pos % 1000;
        }
        positions[i] = new_pos;
    }
}

void print_traffic(int* positions, int num_cars, int time) {
    printf("\nTime: %d seconds\n", time);
    for (int i = 0; i < num_cars; i++) {
        printf("Car %d: Position %.2lf meters\n", i, (double) positions[i]);
    }
}

double kmph_to_mps(double kmph) {
    return kmph / 3.6;
}