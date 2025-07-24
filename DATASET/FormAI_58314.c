//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: relaxed
#include <stdio.h>
#define MAX_FLOOR 10 // maximum number of floors in the building

int main()
{
    int current_floor = 1; // initialize the elevator to start at the first floor
    int destination_floor = 0;
    int direction = 1; // 1 is up, -1 is down
    int floors_to_go[MAX_FLOOR] = {0};
    int num_floors_to_go = 0; // initialize number of floors to go to be zero
    int i;

    printf("Welcome to the Elevator Simulation Program!\n");

    while (1)
    {
        printf("The elevator is currently on floor %d.\n", current_floor);

        // check if there are any pending floors to go
        if (num_floors_to_go > 0)
        {
            printf("There are currently %d floors to go.\n", num_floors_to_go);
            // check if the current floor matches the destination
            if (current_floor == destination_floor)
            {
                printf("Ding! You have arrived at floor %d.\n", destination_floor);
                direction = (direction == 1) ? -1 : 1; // change the direction of the elevator
                printf("The elevator is now going %s.\n", (direction == 1) ? "up" : "down");
                num_floors_to_go--;
                for (i = 0; i < num_floors_to_go; i++)
                {
                    if (floors_to_go[i] == destination_floor)
                    {
                        // remove the floor from the queue
                        for (int j = i; j < num_floors_to_go - 1; j++)
                        {
                            floors_to_go[j] = floors_to_go[j + 1];
                        }
                        num_floors_to_go--;
                        break;
                    }
                }
            }
            else
            {
                printf("The elevator is currently going %s.\n", (direction == 1) ? "up" : "down");
            }
        }
        else
        {
            printf("There are currently no pending floors.\n");
            break;
        }

        if (num_floors_to_go > 0)
        {
            // determine the next floor to go to based on the direction of the elevator
            if (direction == 1)
            {
                // go up
                for (i = current_floor + 1; i <= MAX_FLOOR; i++)
                {
                    if (floors_to_go[i - 1] == 1)
                    {
                        destination_floor = i;
                        break;
                    }
                }
                if (destination_floor == 0)
                {
                    for (i = current_floor - 1; i >= 1; i--)
                    {
                        if (floors_to_go[i - 1] == 1)
                        {
                            destination_floor = i;
                            break;
                        }
                    }
                }
            }
            else
            {
                // go down
                for (i = current_floor - 1; i >= 1; i--)
                {
                    if (floors_to_go[i - 1] == 1)
                    {
                        destination_floor = i;
                        break;
                    }
                }
                if (destination_floor == 0)
                {
                    for (i = current_floor + 1; i <= MAX_FLOOR; i++)
                    {
                        if (floors_to_go[i - 1] == 1)
                        {
                            destination_floor = i;
                            break;
                        }
                    }
                }
            }

            // update the current floor
            if (destination_floor != 0)
            {
                current_floor = destination_floor;
            }
        }
    }

    printf("Thank you for using the Elevator Simulation Program!\n");

    return 0;
}