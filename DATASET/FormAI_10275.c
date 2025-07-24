//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30 // number of cars
#define MAX_SPEED 10 // maximum car speed
#define ROAD_LENGTH 50 // length of road
#define CELL_EMPTY -1 // no car
#define CELL_INTERVAL 100 // interval between each display

// function to initialize the road
void initialize(int* road) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        *(road + i) = CELL_EMPTY;
    }
}

// function to print the road
void print_road(int* road) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (*(road + i) == CELL_EMPTY) {
            printf("-");
        } else {
            printf("%d", *(road + i));
        }
    }
    printf("\n");
}

// function to move the cars
void move_cars(int* road, int* speeds) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (*(road + i) != CELL_EMPTY) { // if there's a car at this cell
            int speed = *(speeds + i);
            int distance_to_next_car = ROAD_LENGTH; // distance to next car
            for (int j = i + 1; j < ROAD_LENGTH; j++) {
                if (*(road + j) != CELL_EMPTY) { // if there's a car at this cell
                    distance_to_next_car = j - i;
                    break;
                }
            }
            int new_position = i + speed;
            if (new_position >= ROAD_LENGTH) { // if the car reaches the end of the road
                *(road + i) = CELL_EMPTY; // remove the car from the road
            } else {
                if (distance_to_next_car <= speed) { // if the car is too close to the next car
                    speed = distance_to_next_car - 1; // slow down
                }
                *(road + i) = CELL_EMPTY; // remove the car from the current position
                *(road + new_position) = i; // put the car in the new position
                *(speeds + new_position) = speed; // update the speed at the new position
            }
        }  
    }
}

// function to update the speed of the cars
void update_speeds(int* road, int* speeds) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (*(road + i) != CELL_EMPTY) { // if there's a car at this cell
            int speed = *(speeds + i);
            int distance_to_next_car = ROAD_LENGTH; // distance to next car
            for (int j = i + 1; j < ROAD_LENGTH; j++) {
                if (*(road + j) != CELL_EMPTY) { // if there's a car at this cell
                    distance_to_next_car = j - i;
                    break;
                }
            }
            int new_speed = speed;
            if (distance_to_next_car <= new_speed) { // if the car is too close to the next car
                new_speed = distance_to_next_car - 1; // slow down
            } else if (new_speed < MAX_SPEED) { // if the car is below the maximum speed
                new_speed += 1; // speed up
            }
            *(speeds + i) = new_speed; // update the speed
        }  
    }
}

int main() {
    int road[ROAD_LENGTH];
    int speeds[ROAD_LENGTH];
    int count = N;
    srand(time(NULL));
    initialize(road);
    // randomly place cars on the road
    while (count > 0) {
        int pos = rand() % ROAD_LENGTH;
        if (*(road + pos) == CELL_EMPTY) {
            *(road + pos) = count;
            *(speeds + pos) = rand() % MAX_SPEED + 1;
            count--;
        }
    }
    // simulate the traffic flow
    int interval = 0;
    while (1) {
        system("clear"); // clear the console
        print_road(road);
        move_cars(road, speeds);
        update_speeds(road, speeds);
        interval++;
        if (interval == CELL_INTERVAL) {
            getchar(); // wait for the user to press a button
            interval = 0;
        }
    }
    return 0;
}