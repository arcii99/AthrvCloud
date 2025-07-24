//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define MAX_TIME 86400 // 24 hours in seconds

typedef struct Car {
    int id;
    int arrival_time;
    int departure_time;
} Car;

int main() {
    srand(time(NULL)); // initialize random seed

    Car northbound_cars[MAX_CARS];
    Car southbound_cars[MAX_CARS];

    int num_northbound_cars = 0;
    int num_southbound_cars = 0;

    int current_time = 0;

    while (current_time < MAX_TIME) {
        // Generate a random number to determine if a car arrives
        int r = rand() % 100;

        if (r < 50) { // 50% chance a car arrives at northbound lane
            if (num_northbound_cars < MAX_CARS) {
                Car car;
                car.id = num_northbound_cars + 1;
                car.arrival_time = current_time;
                northbound_cars[num_northbound_cars] = car;
                num_northbound_cars++;
            }
        } else if (r < 100){
            if (num_southbound_cars < MAX_CARS) {
                Car car;
                car.id = num_southbound_cars + 1;
                car.arrival_time = current_time;
                southbound_cars[num_southbound_cars] = car;
                num_southbound_cars++;
            }
        }

        // Check if any cars are ready to depart from northbound lane
        for (int i = 0; i < num_northbound_cars; i++) {
            if (northbound_cars[i].departure_time == 0 && current_time - northbound_cars[i].arrival_time >= 60) {
                northbound_cars[i].departure_time = current_time;
            }
        }

        // Check if any cars are ready to depart from southbound lane
        for (int i = 0; i < num_southbound_cars; i++) {
            if (southbound_cars[i].departure_time == 0 && current_time - southbound_cars[i].arrival_time >= 60) {
                southbound_cars[i].departure_time = current_time;
            }
        }

        // Print current status of traffic flow
        printf("Current Time: %d\n", current_time);

        printf("Northbound Lane:\n");
        for (int i = 0; i < num_northbound_cars; i++) {
            printf("Car #%d:\tArrival Time: %d\tDeparture Time: ", northbound_cars[i].id, northbound_cars[i].arrival_time);
            if (northbound_cars[i].departure_time == 0) {
                printf("N/A\n");
            } else {
                printf("%d\n", northbound_cars[i].departure_time);
            }
        }

        printf("Southbound Lane:\n");
        for (int i = 0; i < num_southbound_cars; i++) {
            printf("Car #%d:\tArrival Time: %d\tDeparture Time: ", southbound_cars[i].id, southbound_cars[i].arrival_time);
            if (southbound_cars[i].departure_time == 0) {
                printf("N/A\n");
            } else {
                printf("%d\n", southbound_cars[i].departure_time);
            }
        }

        printf("=============================\n");
        printf("\n");

        current_time++;
    }

    return 0;
}