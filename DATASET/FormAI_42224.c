//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_FLOOR 10

int main()
{
    int elevator_floor = 1, elevator_direction = 0; // Start at floor 1, not moving
    int passengers_waiting[MAX_FLOOR] = {0}; // No passengers in the beginning
    int passengers_in_elevator = 0; // No passengers in the beginning
    srand(time(NULL)); // Initialize random seed

    printf("Elevator simulation starts at floor %d\n", elevator_floor);

    while(1) // Run the simulation indefinitely
    {
        // Check if anyone wants to get off at the current floor
        if(passengers_in_elevator > 0 && passengers_in_elevator == elevator_floor)
        {
            printf("The elevator has arrived at floor %d. %d passengers have left the elevator.\n", elevator_floor, passengers_in_elevator);
            passengers_in_elevator = 0; // All passengers have left the elevator
        }

        // Check if anyone wants to get in at the current floor
        if(passengers_waiting[elevator_floor-1] > 0)
        {
            int new_passengers = rand() % (passengers_waiting[elevator_floor-1] + 1); // Maximum number of new passengers is the number of waiting passengers at this floor

            printf("%d passengers have entered the elevator at floor %d.\n", new_passengers, elevator_floor);

            passengers_in_elevator += new_passengers;
            passengers_waiting[elevator_floor-1] -= new_passengers; // Update waiting passenger count
        }

        // Change direction if the elevator reaches the top or bottom floor
        if(elevator_floor == MAX_FLOOR)
            elevator_direction = -1;
        else if(elevator_floor == 1)
            elevator_direction = 1;

        // Move the elevator one floor in the current direction
        elevator_floor += elevator_direction;

        printf("The elevator is now at floor %d with %d passengers onboard.\n", elevator_floor, passengers_in_elevator);

        // Generate new passengers waiting at each floor
        for(int i = 0; i < MAX_FLOOR; i++)
        {
            if(i+1 != elevator_floor) // Don't generate passengers on the floor with the elevator
            {
                int new_passengers = rand() % 3; // Maximum of 2 new passengers waiting at each floor

                printf("%d passengers are waiting at floor %d.\n", new_passengers, i+1);

                passengers_waiting[i] += new_passengers; // Update waiting passenger count
            }
        }

        // Wait for 2 seconds before continuing the simulation
        sleep(2);
    }

    return 0;
}