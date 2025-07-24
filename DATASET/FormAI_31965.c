//FormAI DATASET v1.0 Category: Weather simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Global variables for temperature and humidity
int temperature = 25;
int humidity = 50;

// Function for simulating temperature changes
void* temperatureSimulation(void* arg) {
    srand(time(NULL));
    while (1) {
        int tempChange = rand() % 5 - 2; // -2 to 2 degree Celsius change
        temperature += tempChange;
        printf("Temperature: %d°C\n", temperature);
        sleep(1);
    }
    return NULL;
}

// Function for simulating humidity changes
void* humiditySimulation(void* arg) {
    srand(time(NULL));
    while (1) {
        int humChange = rand() % 10 - 5; // -5% to 5% humidity change
        humidity += humChange;
        printf("Humidity: %d%%\n", humidity);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t tid1, tid2;

    // Creating thread for temperature simulation
    if (pthread_create(&tid1, NULL, temperatureSimulation, NULL) != 0) {
        printf("Failed to create thread");
        return 1;
    }

    // Creating thread for humidity simulation
    if (pthread_create(&tid2, NULL, humiditySimulation, NULL) != 0) {
        printf("Failed to create thread");
        return 1;
    }

    // Waiting for threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}