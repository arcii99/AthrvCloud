//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

// Global Variables
int fuel = 500; // Fuel for Spacecraft
int distance_traveled = 0; // Distance Traveled by Spacecraft

// Function to travel a kilometer
void travel_kilometer()
{
    if(fuel >= 5) // Check if there is enough fuel
    {
        fuel -= 5;
        distance_traveled++;

        printf("Distance traveled: %d km | Fuel remaining: %d units\n", distance_traveled, fuel);
    } 
    else
    {
        printf("Not enough fuel!\n");
    }   
}

// Function to refill fuel
void refill_fuel()
{
    fuel = 500;
    printf("Fuel refilled!\n");
}

// Function to check mission status
void check_status()
{
    printf("Current status:\n");
    printf("Distance traveled: %d km | Fuel remaining: %d units\n", distance_traveled, fuel);
}

// Thread function
void *operate_spacecraft(void *arg)
{
    char *command = (char *) arg; // Command received by the thread

    if(*command == 't')
    {
        travel_kilometer();
    }
    else if(*command == 'r')
    {
        refill_fuel();
    }
    else if(*command == 's')
    {
        check_status();
    }
    else
    {
        printf("Invalid Command!\n");
    }

    pthread_exit(0); // Exit the thread
}

int main()
{
    int i=0;
    char commands[4][1] = {"t", "r", "s", "x"}; // Commands to be sent to the thread

    pthread_t threads[4];

    // Create threads
    while(i<4)
    {
        pthread_create(&threads[i], NULL, operate_spacecraft, (void *) &commands[i]);
        i++;
    }
    
    // Join threads
    i = 0;
    while(i<4)
    {
        pthread_join(threads[i], NULL);
        i++;
    }

    return 0;
}