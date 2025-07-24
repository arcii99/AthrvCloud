//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_TIME 20 // maximum time to run the simulation (in seconds)
#define GREEN 0     // green light state
#define YELLOW 1    // yellow light state
#define RED 2       // red light state
#define NORTH 0     // northbound direction
#define SOUTH 1     // southbound direction
#define EAST 2      // eastbound direction
#define WEST 3      // westbound direction

int time_elapsed = 0; // time elapsed since simulation started
int north_south_state = GREEN;
int east_west_state = RED;
bool stop_simulation = false;

pthread_mutex_t north_south_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t east_west_mutex = PTHREAD_MUTEX_INITIALIZER;

void *north_south_controller(void *arg)
{
    while (!stop_simulation)
    {
        pthread_mutex_lock(&north_south_mutex);
        if (north_south_state == GREEN)
        {
            printf("\n[North-South] Green light ON!");
            printf("\n");
            sleep(5); // Green for 5 seconds
            north_south_state = YELLOW;
        }
        else if (north_south_state == YELLOW)
        {
            printf("\n[North-South] Yellow light ON!");
            printf("\n");
            sleep(2); // Yellow for 2 seconds
            north_south_state = RED;
        }
        else if (north_south_state == RED)
        {
            printf("\n[North-South] Red light ON!");
            printf("\n");
            sleep(4); // Red for 4 seconds
            north_south_state = GREEN;
        }
        pthread_mutex_unlock(&north_south_mutex);
    }
    pthread_exit(NULL);
}

void *east_west_controller(void *arg)
{
    while (!stop_simulation)
    {
        pthread_mutex_lock(&east_west_mutex);
        if (east_west_state == GREEN)
        {
            printf("\n[East-West] Green light ON!");
            printf("\n");
            sleep(5); // Green for 5 seconds
            east_west_state = YELLOW;
        }
        else if (east_west_state == YELLOW)
        {
            printf("\n[East-West] Yellow light ON!");
            printf("\n");
            sleep(2); // Yellow for 2 seconds
            east_west_state = RED;
        }
        else if (east_west_state == RED)
        {
            printf("\n[East-West] Red light ON!");
            printf("\n");
            sleep(4); // Red for 4 seconds
            east_west_state = GREEN;
        }
        pthread_mutex_unlock(&east_west_mutex);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t north_south_tid, east_west_tid;

    // Create threads for both controllers
    if (pthread_create(&north_south_tid, NULL, north_south_controller, NULL) != 0)
    {
        printf("Error: Failed to create north-south thread.\n");
        return 1;
    }

    if (pthread_create(&east_west_tid, NULL, east_west_controller, NULL) != 0)
    {
        printf("Error: Failed to create east-west thread.\n");
        return 1;
    }

    // Wait for simulation to finish
    while (time_elapsed < MAX_TIME)
    {
        sleep(1);
        time_elapsed++;
    }

    // Stop the simulation
    printf("\nSimulation completed.\n");
    stop_simulation = true;

    // Wait for threads to finish
    pthread_join(north_south_tid, NULL);
    pthread_join(east_west_tid, NULL);

    return 0;
}