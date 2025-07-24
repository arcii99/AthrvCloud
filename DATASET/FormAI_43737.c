//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Global variable to hold the vehicle position
int vehicle_position = 0;

// Thread functions to move the vehicle
void* move_forward(void* arg)
{
    printf("Moving the vehicle forward...\n");
    while(vehicle_position < 100)
    {
        vehicle_position += 10;
        printf("Vehicle position: %d\n", vehicle_position);
        sleep(1);
    }
    printf("Vehicle has reached the destination!\n");
    return NULL;
}

void* move_backward(void* arg)
{
    printf("Moving the vehicle backward...\n");
    while(vehicle_position > -100)
    {
        vehicle_position -= 10;
        printf("Vehicle position: %d\n", vehicle_position);
        sleep(1);
    }
    printf("Vehicle has reached the starting point!\n");
    return NULL;
}

int main()
{
    pthread_t forward_thread;
    pthread_t backward_thread;

    // Create threads to move the vehicle
    int result1 = pthread_create(&forward_thread, NULL, move_forward, NULL);
    int result2 = pthread_create(&backward_thread, NULL, move_backward, NULL);

    // Check if threads created successfully
    if(result1 != 0 || result2 != 0)
    {
        printf("Error: Failed to create threads!\n");
        exit(EXIT_FAILURE);
    }

    // Wait for threads to finish
    pthread_join(forward_thread, NULL);
    pthread_join(backward_thread, NULL);

    return 0;
}