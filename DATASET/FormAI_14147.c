//FormAI DATASET v1.0 Category: Temperature monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_TEMP 100.0
#define MIN_TEMP 0.0
#define NUM_SENSORS 5

// Global Variables
float curr_temps[NUM_SENSORS] = { 0 };
bool shutdown_flag = false;

// Function Declaration
void* sensor_task(void* pArg);
void* display_task(void* pArg);

int main()
{
    // Initialize sensor threads
    pthread_t threads[NUM_SENSORS];
    for(int i = 0; i < NUM_SENSORS; i++)
    {
        pthread_create(&threads[i], NULL, sensor_task, &i);
        usleep(500);
    }

    // Initialize display thread
    pthread_t disp_thread;
    pthread_create(&disp_thread, NULL, display_task, NULL);

    // Wait for sensor and display thread to join
    for(int i = 0; i < NUM_SENSORS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    pthread_join(disp_thread, NULL);

    printf("\nShutting down Temperature Monitor...\n");
    return 0;
}

void* sensor_task(void* pArg)
{
    int index = *(int*)pArg;
    float temp = 20.0;

    while(!shutdown_flag)
    {
        // Simulate temperature reading
        usleep(500000);
        temp += (rand() % 5) - 2;

        // Check temperature limits
        if(temp < MIN_TEMP)
            temp = MIN_TEMP;
        else if(temp > MAX_TEMP)
            temp = MAX_TEMP;

        // Update global temperature array
        curr_temps[index] = temp;
    }
    return NULL;
}

void* display_task(void* pArg)
{
    while(!shutdown_flag)
    {
        // Wait for all temperature readings to be updated
        usleep(1000);

        // Print current temperature readings
        printf("\rCurrent Temperatures: ");
        for(int i = 0; i < NUM_SENSORS; i++)
        {
            printf("%d: %.1f  ", i+1, curr_temps[i]);
        }
        fflush(stdout);
    }
    return NULL;
}