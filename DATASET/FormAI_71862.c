//FormAI DATASET v1.0 Category: Weather simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4    // Define the number of threads to simulate different weather conditions

// Define a custom structure to hold the weather data
typedef struct {
    float temperature;
    float humidity;
    float wind_speed;
    float precipitation;
} WeatherData;

// Function to simulate temperature changes
void *temperatureChange(void *args)
{
    WeatherData *data = args;
    srand((unsigned int) time(NULL));
    float change;
    while(1) {
        change = ((float)rand()/(float)(RAND_MAX)) * 10.0;  // Generate a random change between 0 and 10
        if(data->temperature > 20.0) {
            data->temperature -= change;
        } else {
            data->temperature += change;
        }
        printf("Temperature: %.2f C\n", data->temperature);
        sleep(2);   // Sleep for 2 seconds
    }
    pthread_exit(NULL);
}

// Function to simulate humidity changes
void *humidityChange(void *args)
{
    WeatherData *data = args;
    srand((unsigned int) time(NULL));
    float change;
    while(1) {
        change = ((float)rand()/(float)(RAND_MAX)) * 5.0;   // Generate a random change between 0 and 5
        if(data->humidity > 50.0) {
            data->humidity -= change;
        } else {
            data->humidity += change;
        }
        printf("Humidity: %.2f %%\n", data->humidity);
        sleep(3);   // Sleep for 3 seconds
    }
    pthread_exit(NULL);
}

// Function to simulate wind speed changes
void *windSpeedChange(void *args)
{
    WeatherData *data = args;
    srand((unsigned int) time(NULL));
    float change;
    while(1) {
        change = ((float)rand()/(float)(RAND_MAX)) * 10.0;   // Generate a random change between 0 and 10
        if(data->wind_speed > 10.0) {
            data->wind_speed -= change;
        } else {
            data->wind_speed += change;
        }
        printf("Wind Speed: %.2f km/h\n", data->wind_speed);
        sleep(4);   // Sleep for 4 seconds
    }
    pthread_exit(NULL);
}

// Function to simulate precipitation changes
void *precipitationChange(void *args)
{
    WeatherData *data = args;
    srand((unsigned int) time(NULL));
    float change;
    while(1) {
        change = ((float)rand()/(float)(RAND_MAX)) * 5.0;   // Generate a random change between 0 and 5
        if(data->precipitation > 10.0) {
            data->precipitation -= change;
        } else {
            data->precipitation += change;
        }
        printf("Precipitation: %.2f mm\n", data->precipitation);
        sleep(5);   // Sleep for 5 seconds
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    WeatherData data = {20.0, 60.0, 15.0, 5.0};    // Set the initial weather conditions

    // Create threads to simulate different weather conditions
    if(pthread_create(&threads[0], NULL, temperatureChange, &data)) {
        printf("Error creating temperature thread!\n");
        exit(1);
    }

    if(pthread_create(&threads[1], NULL, humidityChange, &data)) {
        printf("Error creating humidity thread!\n");
        exit(1);
    }

    if(pthread_create(&threads[2], NULL, windSpeedChange, &data)) {
        printf("Error creating wind speed thread!\n");
        exit(1);
    }

    if(pthread_create(&threads[3], NULL, precipitationChange, &data)) {
        printf("Error creating precipitation thread!\n");
        exit(1);
    }

    // Wait for all threads to finish
    for(int i = 0; i < NUM_THREADS; i++) {
        if(pthread_join(threads[i], NULL)) {
            printf("Error joining thread %d!\n", i);
            exit(1);
        }
    }

    return 0;
}