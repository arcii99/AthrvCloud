//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CARS 1000
#define MAX_SPEED 60
#define MIN_DISTANCE 10
#define MAX_DISTANCE 100

typedef struct car Car;
struct car {
    int id;
    int speed;
    int distance_to_next_car;
    int position;
    bool can_move; 
};

void print_grid(char grid[MAX_CARS+1][MAX_DISTANCE+1], int num_cars, int max_distance) {
    printf("\n");
    for(int i=0;i<num_cars+1;i++) {
        for(int j=0;j<=max_distance;j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Car cars[MAX_CARS];
    Car *next_car;
    int num_cars = rand()%MAX_CARS+1;
    char grid[MAX_CARS+1][MAX_DISTANCE+1];
    printf("Number of cars: %d\n\n", num_cars);

    //initialize cars
    for(int i=0;i<num_cars;i++) {
        cars[i].id = i+1;
        cars[i].speed = rand()%MAX_SPEED+1;
        cars[i].distance_to_next_car = rand()%(MAX_DISTANCE-MIN_DISTANCE)+MIN_DISTANCE;
        cars[i].position = i==0 ? cars[i].distance_to_next_car : cars[i-1].position+cars[i-1].distance_to_next_car+cars[i].distance_to_next_car;
        cars[i].can_move = true;
    }

    //initialize grid
    for(int i=0;i<=num_cars;i++) {
        for(int j=0;j<=MAX_DISTANCE;j++) {
            grid[i][j] = '-';
        }
    }

    //print initial positions of cars
    for(int i=0;i<num_cars;i++) {
        grid[0][cars[i].position] = cars[i].id+'0';
    }
    print_grid(grid, num_cars, MAX_DISTANCE);

    //simulate traffic
    int time_tick = 0;
    while(true) {
        //update cars positions
        for(int i=0;i<num_cars;i++) {
            if(cars[i].can_move) {
                cars[i].position += cars[i].speed;
                if(cars[i].position > MAX_DISTANCE) {
                    printf("\nSimulation finished in %d seconds.", time_tick);
                    exit(0);
                }
            }
        }

        //check collisions
        for(int i=0;i<num_cars-1;i++) {
            next_car = &cars[i+1];
            if(next_car->position - cars[i].position <= next_car->distance_to_next_car) {
                next_car->can_move = false;
            }
        }

        //update grid
        for(int i=0;i<=num_cars;i++) {
            for(int j=0;j<=MAX_DISTANCE;j++) {
                grid[i][j] = '-';
            }
        }
        for(int i=0;i<num_cars;i++) {
            if(cars[i].can_move) {
                grid[0][cars[i].position] = cars[i].id+'0';
            }
        }
        print_grid(grid, num_cars, MAX_DISTANCE);

        //reset can_move flag
        for(int i=0;i<num_cars;i++) {
            cars[i].can_move = true;
        }

        time_tick++;
    }

    return 0;
}