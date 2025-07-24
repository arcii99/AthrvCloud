//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ELEVATOR_CAPACITY 5
#define FLOOR_RANGE 7
#define WAIT_TIME_SECONDS 2
#define MAX_TIME_SECONDS 5

int main()
{
    srand(time(NULL));
    int floors[FLOOR_RANGE] = {0, 1, 2, 3, 4, 5, 6}; // Floors in the building
    int elevator[ELEVATOR_CAPACITY]; // Array to hold passengers inside the elevator
    int elevator_position = 0; // The starting position of the elevator
    int num_passengers = 0; // Number of passengers currently in the elevator
    int direction = 1; // 1 for going up, -1 for going down

    while(1)
    {
        // Print the current position and direction of the elevator
        printf("Elevator at floor %d going %s\n", floors[elevator_position], direction == 1 ? "up" : "down");

        // Check if there are any passengers waiting on the current floor
        for(int i = 0; i < ELEVATOR_CAPACITY; i++)
        {
            if(elevator[i] == floors[elevator_position])
            {
                printf("Passenger %d gets off the elevator at floor %d\n", i+1, floors[elevator_position]);
                elevator[i] = -1;
                num_passengers--;
            }
        }

        // Check if there are any passengers waiting on other floors
        for(int i = 0; i < ELEVATOR_CAPACITY; i++)
        {
            if(elevator[i] == -1)
            {
                // Select a random floor for the passenger to get on the elevator
                int passenger_floor = rand() % FLOOR_RANGE;

                // Check if the passenger is going in the same direction as the elevator
                if((passenger_floor > floors[elevator_position] && direction == 1) || (passenger_floor < floors[elevator_position] && direction == -1))
                {
                    // Wait for a random amount of time before letting the passenger on the elevator
                    int wait_time = rand() % MAX_TIME_SECONDS + WAIT_TIME_SECONDS;
                    printf("Waiting for %d seconds for passenger %d at floor %d\n", wait_time, i+1, floors[elevator_position]);
                    sleep(wait_time);

                    // Passenger gets on the elevator
                    printf("Passenger %d gets on the elevator at floor %d\n", i+1, floors[elevator_position]);
                    elevator[i] = floors[elevator_position];
                    num_passengers++;

                    // If the elevator is full, wait for a random amount of time before departing
                    if(num_passengers == ELEVATOR_CAPACITY)
                    {
                        int wait_time = rand() % MAX_TIME_SECONDS + WAIT_TIME_SECONDS;
                        printf("Elevator is full, waiting for %d seconds before departing\n", wait_time);
                        sleep(wait_time);
                        break;
                    }
                }
            }
        }

        // Move the elevator one floor in the current direction
        elevator_position += direction;

        // If the elevator has reached the top floor or bottom floor, change direction
        if(elevator_position == FLOOR_RANGE - 1)
            direction = -1;
        else if(elevator_position == 0)
            direction = 1;

        // If there are no more passengers waiting, exit the simulation
        if(num_passengers == 0)
            break;
    }

    printf("Simulation complete\n");

    return 0;
}