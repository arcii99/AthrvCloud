//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CARS 20
#define MAX_SPEED 5

int main() {
    int car_speeds[MAX_CARS];
    int distances[MAX_CARS][MAX_CARS];
    int num_cars = rand() % MAX_CARS + 1;
    srand(time(NULL));
    
    printf("Generating %d cars with random speeds...\n", num_cars);
    for (int i = 0; i < num_cars; i++) {
        car_speeds[i] = rand() % MAX_SPEED + 1;
        printf("Car %d speed: %d\n", i, car_speeds[i]);
    }
    
    printf("Generating distances between cars...\n");
    for (int i = 0; i < num_cars; i++) {
        for (int j = i + 1; j < num_cars; j++) {
            if (i == j) {
                distances[i][j] = 0;
            } else {
                distances[i][j] = rand() % 100 + 1;
                distances[j][i] = distances[i][j];
            }
        }
    }
    
    printf("Simulating traffic flow for 30 seconds...\n");
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < num_cars; j++) {
            int sum_speeds = 0;
            int num_cars_ahead = 0;
            for (int k = 0; k < num_cars; k++) {
                if (distances[j][k] > 0 && distances[j][k] < 100) {
                    num_cars_ahead++;
                    sum_speeds += car_speeds[k];
                }
            }
            if (num_cars_ahead > 0) {
                int avg_speed_ahead = sum_speeds / num_cars_ahead;
                if (avg_speed_ahead < car_speeds[j]) {
                    car_speeds[j] = avg_speed_ahead;
                } else if (car_speeds[j] < MAX_SPEED) {
                    car_speeds[j]++;
                }
            } else if (car_speeds[j] < MAX_SPEED) {
                car_speeds[j]++;
            }
            printf("Car %d speed: %d\n", j, car_speeds[j]);
        }
    }
    
    return 0;
}