//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_CARS 100
#define SPEED_LIMIT 50
#define SIMULATION_TIME 60 // time in seconds

enum Direction {NORTH, SOUTH, EAST, WEST}; // directions

typedef struct Car {
    int id;
    int speed;
    int position;
    enum Direction direction;
} Car;

int random_speed() {
    return rand() % (SPEED_LIMIT + 1); // generate random speed within the limit
}

void update_position(Car *car, int time_elapsed) {
    int distance_moved = car->speed * time_elapsed;
    car->position += distance_moved;
}

void simulate_traffic_flow() {
    srand(time(NULL)); // initialize random seed
    
    Car cars[TOTAL_CARS];
    for (int i = 0; i < TOTAL_CARS; i++) {
        cars[i].id = i;
        cars[i].speed = random_speed();
        cars[i].position = rand() % 1000; // generate position between 0 and 1000
        cars[i].direction = rand() % 4; // generate random direction
    }
    
    for (int t = 0; t < SIMULATION_TIME; t++) {
        printf("Time: %d\n", t);
        for (int i = 0; i < TOTAL_CARS; i++) {
            printf("Car %d (Speed: %d, Position: %d, Direction: %d) - ", cars[i].id, cars[i].speed, cars[i].position, cars[i].direction);
            update_position(&cars[i], 1); // update position of the car
            printf("New Position: %d\n", cars[i].position);
        }
        printf("\n");
    }
}

int main() {
    simulate_traffic_flow();
    return 0;
}