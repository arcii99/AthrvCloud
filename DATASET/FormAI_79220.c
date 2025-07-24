//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 5
#define MAX_LANE 2

typedef struct {
    int position; // position of the car on the road, i.e., index of the current segment
    int speed; // the current speed of the car
    int lane; // the lane on which the car is currently running
    int destination; // index of the last segment
} Car;

int num_cars = 0;

void print_state(int road[][MAX_LANE]) {
    printf("\n");
    for(int i = 0; i < MAX_LANE; i++) {
        for(int j = 0; j < MAX_CARS; j++) {
            if(road[j][i] != -1) printf("[%d|%2d]", road[j][i], j);
            else printf("[*|  ]");
        }
        printf("\n");
    }
}

void move_cars(int road[][MAX_LANE]) {
    int max_index = num_cars - 1;
    for(int i = max_index; i >= 0; i--) {
        Car car = {i, road[i][0], 0, MAX_CARS-1};
        if(road[i][1] != -1 && road[i+1][0] != -1 && i < max_index) {
            Car next_car = {i+1, road[i+1][0], 0, MAX_CARS-1};
            if(next_car.position - car.position < car.speed) {
                car.speed = next_car.position - car.position - 1;
            }
        }
        if((rand()%2 == 0 && car.speed > 0) || (car.speed < MAX_SPEED)) car.speed++;
        car.position += car.speed;
        if(car.position > MAX_CARS-1) {
            car.position = MAX_CARS-1;
            car.destination = -1;
        }
        if(road[car.position][0] != -1) {
            int next_index = num_cars;
            road[next_index][0] = car.speed;
            num_cars++;
        }
        road[car.position][0] = car.speed;
        road[i][0] = -1;
    }
}

int main() {
    srand(time(NULL));
    int road[MAX_CARS][MAX_LANE] = {0};
    int num_iterations = 20;
    int i = 0;
    road[0][0] = 1;
    num_cars = 1;
    while(i < num_iterations) {
        print_state(road);
        move_cars(road);
        i++;
    }
    return 0;
}