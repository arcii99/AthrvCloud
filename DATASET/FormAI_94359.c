//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int present_time = 2022;
int traveler_time = 1888;

void *time_travel(void *arg)
{
    while (traveler_time < present_time)
    {
        printf("Traveler from %d is catching up to present time...\n", traveler_time);
        traveler_time++;
        sleep(1);
    }
    printf("The traveler has arrived in the present time!\n");
    return NULL;
}

int main()
{
    pthread_t t1;
    int status;

    printf("The present time is %d.\n", present_time);

    // Create thread for time traveler
    status = pthread_create(&t1, NULL, time_travel, NULL);
    if (status != 0)
    {
        printf("Error creating thread. Exiting...\n");
        exit(-1);
    }

    // Wait for thread to finish
    pthread_join(t1, NULL);

    printf("Simulation complete.\n");

    return 0;
}