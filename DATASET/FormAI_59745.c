//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random number between min and max */
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to calculate probability to determine which road user gets priority */
int probability(int cars, int bikes, int pedestrians) {
    int total = cars + bikes + pedestrians;
    int car_prob = (cars / total) * 100;
    int bike_prob = (bikes / total) * 100;
    int ped_prob = (pedestrians / total) * 100;
    int rand_num = random_number(1, 100);
    if (rand_num <= car_prob) {
        return 1;
    } else if (rand_num <= (car_prob + bike_prob)) {
        return 2;
    } else {
        return 3;
    }
}

/* Function to simulate traffic flow */
void simulate_traffic() {
    int north_cars = 0, north_bikes = 0, north_pedestrians = 0;
    int south_cars = 0, south_bikes = 0, south_pedestrians = 0;
    int east_cars = 0, east_bikes = 0, east_pedestrians = 0;
    int west_cars = 0, west_bikes = 0, west_pedestrians = 0;
    int current_road = 1; // 1 for north-south road, 2 for east-west road
    int i;
    printf("Simulation start:\n\n");
    for (i = 0; i < 100; i++) {
        // Check which road is currently being used
        if (current_road == 1) {
            printf("On North - South road:\n");
        } else {
            printf("On East - West road:\n");
        }

        // Generate random numbers of cars, bikes and pedestrians on each road
        north_cars = random_number(1, 15);
        south_cars = random_number(1, 15);
        east_cars = random_number(1, 15);
        west_cars = random_number(1, 15);
        north_bikes = random_number(1, 10);
        south_bikes = random_number(1, 10);
        east_bikes = random_number(1, 10);
        west_bikes = random_number(1, 10);
        north_pedestrians = random_number(1, 5);
        south_pedestrians = random_number(1, 5);
        east_pedestrians = random_number(1, 5);
        west_pedestrians = random_number(1, 5);

        // Determine which road user gets priority based on probability
        int priority = probability(north_cars + south_cars + east_cars + west_cars,
                                    north_bikes + south_bikes + east_bikes + west_bikes,
                                    north_pedestrians + south_pedestrians + east_pedestrians + west_pedestrians);
        int waiting_time = random_number(1, 15);
        switch(priority) {
            case 1: // Cars get priority
                printf("Cars on this road get priority.\n");
                if (current_road == 1) {
                    printf("Traffic on the North-South road is flowing.\n");
                } else {
                    printf("Traffic on the East-West road is flowing.\n");
                }
                break;
            case 2: // Bikes get priority
                printf("Bikes on this road get priority.\n");
                printf("Traffic on the other road waits for %d seconds.\n", waiting_time);
                if (current_road == 1) {
                    printf("Traffic on the East-West road is waiting.\n");
                } else {
                    printf("Traffic on the North-South road is waiting.\n");
                }
                break;
            case 3: // Pedestrians get priority
                printf("Pedestrians on this road get priority.\n");
                printf("Traffic on the other road waits for %d seconds.\n", waiting_time);
                if (current_road == 1) {
                    printf("Traffic on the East-West road is waiting.\n");
                } else {
                    printf("Traffic on the North-South road is waiting.\n");
                }
                break;
        }

        // Change road after 5 iterations
        if ((i+1)%5 == 0) {
            printf("\nChanging road.\n\n");
            if (current_road == 1) {
                current_road = 2;
            } else {
                current_road = 1;
            }
        } else {
            printf("\n");
        }
    }
}

int main() {
    srand(time(NULL)); // Initialize random number generator
    simulate_traffic(); // Run traffic simulation
    return 0;
}