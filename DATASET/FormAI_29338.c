//FormAI DATASET v1.0 Category: Weather simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// Function prototypes
void *simulateWeather(void *arg);
int generateTemperature();
int generateHumidity();

// Main function
int main() {
    //Initialize random seed
    srand(time(NULL));
    
    //Create threads
    pthread_t north, south, east, west;
    pthread_create(&north, NULL, simulateWeather, (void *)"North");
    pthread_create(&south, NULL, simulateWeather, (void *)"South");
    pthread_create(&east, NULL, simulateWeather, (void *)"East");
    pthread_create(&west, NULL, simulateWeather, (void *)"West");
    
    //Join threads
    pthread_join(north, NULL);
    pthread_join(south, NULL);
    pthread_join(east, NULL);
    pthread_join(west, NULL);
    
    return 0;
}

// Function to simulate weather in different directions
void *simulateWeather(void *arg) {
    char *direction = (char*)arg;
    int temperature, humidity;
    for(int i=0; i<5; i++) {
        temperature = generateTemperature();
        humidity = generateHumidity();
        printf("The temperature in %s is %dC and the humidity is %d%%\n", direction, temperature, humidity);
        sleep(2);
    }
    pthread_exit(NULL);
}

// Function to generate random temperature between 5C to 40C
int generateTemperature() {
    int temperature = (rand() % 36) + 5;
    return temperature;
}

// Function to generate random humidity between 20% to 100%
int generateHumidity() {
    int humidity = (rand() % 81) + 20;
    return humidity;
}