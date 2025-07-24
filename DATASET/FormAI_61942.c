//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 1000
#define MAX_TIME 100

typedef struct Car {
    int id;
    int entry_time;
    int exit_time;
} Car;

int num_cars = 0;
Car cars[MAX_CARS];

void addCar(int time) {
    if(num_cars < MAX_CARS) {
        Car new_car;
        new_car.id = num_cars + 1;
        new_car.entry_time = time;
        new_car.exit_time = -1;
        cars[num_cars++] = new_car;
        printf("Car %d added at time %d\n", new_car.id, time);
    }
}

void removeCar(int car_index, int time) {
    Car removed_car = cars[car_index];
    for(int i = car_index; i < num_cars-1; i++) {
        cars[i] = cars[i+1];
    }
    num_cars--;
    removed_car.exit_time = time;
    printf("Car %d removed at time %d, total time spent: %d\n", removed_car.id, time, removed_car.exit_time - removed_car.entry_time);
}

void simulateTraffic() {
    int curr_time = 0;
    while(curr_time < MAX_TIME) {
        int decision = rand() % 2;
        if(decision == 0) {
            addCar(curr_time);
        }
        else {
            if(num_cars > 0) {
                removeCar(rand() % num_cars, curr_time);
            }
        }
        curr_time++;
    }
}

int main() {
    srand(time(NULL));
    simulateTraffic();
    return 0;
}