//FormAI DATASET v1.0 Category: Weather simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Struct to hold weather data
typedef struct {
    float temperature;
    float humidity;
    float pressure;
} WeatherData;

// Function to simulate random weather data
void* simulate_weather(void* ptr) {
    WeatherData* data = (WeatherData*)ptr;
    while (1) {
        data->temperature = (float)(rand() % 100);
        data->humidity = (float)(rand() % 100);
        data->pressure = (float)(rand() % 100);
        // Wait for a random amount of time from 1 to 5 seconds
        int wait_time = (rand() % 5) + 1;
        sleep(wait_time);
    }
}

// Function to print weather data
void print_weather_data(WeatherData* data) {
    printf("Temperature: %.2f\n", data->temperature);
    printf("Humidity: %.2f\n", data->humidity);
    printf("Pressure: %.2f\n", data->pressure);
}

int main() {
    // Seed random number generator
    srand(time(0));
    
    // Create weather data struct
    WeatherData data = {0.0, 0.0, 0.0};
    
    // Create weather simulation thread
    pthread_t thread;
    int rc = pthread_create(&thread, NULL, simulate_weather, (void*)&data);
    if (rc) {
        printf("Error creating thread\n");
        exit(-1);
    }
    
    // Loop to print weather data every 2 seconds
    while (1) {
        print_weather_data(&data);
        // Wait for 2 seconds
        sleep(2);
    }
    
    // Should never get here (looping indefinitely)
    return 0;
}