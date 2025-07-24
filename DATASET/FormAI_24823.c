//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define the number of lanes and their maximum capacity
#define NUM_LANES 4
#define MAX_LANE_CAPACITY 100

//Define the number of cars in the simulation
#define NUM_CARS 1000

//Define the maximum speed limit and the minimum speed a car can travel
#define MAX_SPEED_LIMIT 120
#define MIN_SPEED_LIMIT 20

//Define the time it takes for a car to exit a lane and enter the next lane
#define EXIT_TIME 2

//Define the time it takes for a car to switch lanes
#define SWITCH_LANES_TIME 3

int main() {
    //Initialize the array to store the number of cars in each lane
    int current_lane[NUM_LANES] = {0};

    //Initialize the array to store the speed limit of each lane
    int lane_speed_limit[NUM_LANES] = {60, 80, 100, 120};

    //Initialize the array to store the position of each car in the simulation
    int car_position[NUM_CARS] = {0};

    //Initialize the array to store the speed of each car in the simulation
    int car_speed[NUM_CARS] = {0};

    //Seed the random number generator
    srand(time(NULL));

    //Generate random speeds and positions for each car in the simulation
    for (int i = 0; i < NUM_CARS; i++) {
        //Generate a random speed for the car
        car_speed[i] = rand() % (MAX_SPEED_LIMIT - MIN_SPEED_LIMIT + 1) + MIN_SPEED_LIMIT;

        //Generate a random lane for the car
        int lane = rand() % NUM_LANES;

        //Increment the number of cars in the lane
        current_lane[lane] += 1;

        //Calculate the position of the car based on the current number of cars in the lane
        car_position[i] = current_lane[lane] * MAX_LANE_CAPACITY / (current_lane[lane] + 1);
    }

    //Print the starting positions and speeds of each car in the simulation
    printf("Starting positions and speeds:\n");
    for (int i = 0; i < NUM_CARS; i++) {
        printf("Car %d: Lane %d, Position %d, Speed %d\n", i + 1, car_position[i] / MAX_LANE_CAPACITY, car_position[i] % MAX_LANE_CAPACITY, car_speed[i]);
    }

    //Update the positions of the cars in the simulation over time
    for (int time = 1; time <= 100; time++) {
        //Update the positions of the cars in each lane
        for (int lane = 0; lane < NUM_LANES; lane++) {
            int current_position = MAX_LANE_CAPACITY;

            //Loop through each car in the lane and update its position
            for (int i = 0; i < NUM_CARS; i++) {
                //If the car is in the current lane, update its position
                if (car_position[i] / MAX_LANE_CAPACITY == lane) {
                    //Calculate the distance the car can travel in the current time step
                    int distance = (car_speed[i] * 1000) / (60 * 60);

                    //Update the position of the car based on its speed and the distance it can travel
                    car_position[i] += distance;

                    //If the car has exited the lane, set its position to the end of the lane
                    if (car_position[i] >= (current_position + MAX_LANE_CAPACITY)) {
                        car_position[i] = current_position + MAX_LANE_CAPACITY - 1;
                    }

                    //Update the current position for the next car in the lane
                    current_position = car_position[i] % MAX_LANE_CAPACITY;
                }
            }
        }

        //Check for collisions between cars in adjacent lanes
        for (int lane = 0; lane < NUM_LANES - 1; lane++) {
            //Loop through each car in the current lane
            for (int i = 0; i < NUM_CARS; i++) {
                //If the car is in the current lane, check for collisions with cars in the adjacent lane
                if (car_position[i] / MAX_LANE_CAPACITY == lane) {
                    int current_speed = car_speed[i];

                    //Check for cars to the right of the current car
                    for (int j = i + 1; j < NUM_CARS; j++) {
                        //If the car is in the adjacent lane and behind the current car, check for a collision
                        if (car_position[j] / MAX_LANE_CAPACITY == lane + 1 && car_position[j] % MAX_LANE_CAPACITY < car_position[i] % MAX_LANE_CAPACITY && car_position[j] % MAX_LANE_CAPACITY + (EXIT_TIME + SWITCH_LANES_TIME) * car_speed[j] / 60 >= car_position[i] % MAX_LANE_CAPACITY) {
                            //Reduce the speed of the current car to avoid a collision
                            current_speed = (car_position[j] % MAX_LANE_CAPACITY - car_position[i] % MAX_LANE_CAPACITY) * 60 / (EXIT_TIME + SWITCH_LANES_TIME);
                            break;
                        }
                    }

                    //Check for cars to the left of the current car
                    for (int j = i - 1; j >= 0; j--) {
                        //If the car is in the adjacent lane and ahead of the current car, check for a collision
                        if (car_position[j] / MAX_LANE_CAPACITY == lane + 1 && car_position[j] % MAX_LANE_CAPACITY > car_position[i] % MAX_LANE_CAPACITY && car_position[j] % MAX_LANE_CAPACITY - (EXIT_TIME + SWITCH_LANES_TIME) * car_speed[i] / 60 <= car_position[i] % MAX_LANE_CAPACITY) {
                            //Reduce the speed of the current car to avoid a collision
                            current_speed = (car_position[j] % MAX_LANE_CAPACITY - car_position[i] % MAX_LANE_CAPACITY) * 60 / (EXIT_TIME + SWITCH_LANES_TIME);
                            break;
                        }
                    }

                    //Limit the speed of the current car to the speed limit of the lane
                    if (current_speed > lane_speed_limit[lane]) {
                        current_speed = lane_speed_limit[lane];
                    }

                    //Update the speed of the current car
                    car_speed[i] = current_speed;
                }
            }
        }

        //Switch lanes for any cars that can do so
        for (int i = 0; i < NUM_CARS; i++) {
            //If the car is not already in the outermost lane, check if it can switch lanes
            if (car_position[i] / MAX_LANE_CAPACITY < NUM_LANES - 1) {
                int current_speed = car_speed[i];
                int current_lane = car_position[i] / MAX_LANE_CAPACITY;
                int current_position = car_position[i] % MAX_LANE_CAPACITY;

                //Check for cars to the right of the current car in the adjacent lane
                for (int j = 0; j < NUM_CARS; j++) {
                    //If the car is in the adjacent lane and ahead of the current car, check if there is enough space to switch lanes
                    if (car_position[j] / MAX_LANE_CAPACITY == current_lane + 1 && car_position[j] % MAX_LANE_CAPACITY > current_position && car_position[j] % MAX_LANE_CAPACITY - current_position >= (EXIT_TIME + SWITCH_LANES_TIME) * current_speed / 60) {
                        //Switch lanes
                        current_lane += 1;
                        car_position[i] = current_lane * MAX_LANE_CAPACITY + current_position;
                        break;
                    }
                }

                //Check for cars to the left of the current car in the adjacent lane
                for (int j = 0; j < NUM_CARS; j++) {
                    //If the car is in the adjacent lane and behind the current car, check if there is enough space to switch lanes
                    if (car_position[j] / MAX_LANE_CAPACITY == current_lane + 1 && car_position[j] % MAX_LANE_CAPACITY < current_position && current_position - car_position[j] % MAX_LANE_CAPACITY >= (EXIT_TIME + SWITCH_LANES_TIME) * current_speed / 60) {
                        //Switch lanes
                        current_lane += 1;
                        car_position[i] = current_lane * MAX_LANE_CAPACITY + current_position;
                        break;
                    }
                }
            }
        }

        //Print the positions and speeds of each car in the simulation
        printf("Time %d - Positions and speeds:\n", time);
        for (int i = 0; i < NUM_CARS; i++) {
            printf("Car %d: Lane %d, Position %d, Speed %d\n", i + 1, car_position[i] / MAX_LANE_CAPACITY, car_position[i] % MAX_LANE_CAPACITY, car_speed[i]);
        }
    }

    //Exit the program
    return 0;
}