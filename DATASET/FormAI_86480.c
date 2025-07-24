//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

// Global variable for temperature
int temperature = 25;

// Function to simulate a temperature change
void* changeTemperature(void* arg) {
    while (1) {
        if (rand() % 2 == 0) {
            temperature++;      // Increase temperature
        }
        else {
            temperature--;      // Decrease temperature
        }
        printf("Temperature changing... New temperature is %dC\n", temperature);
        sleep(3);               // Wait for 3 seconds
    }
}

// Function to display temperature every 5 seconds
void* displayTemperature(void* arg) {
    while (1) {
        printf("Current temperature is %dC\n", temperature);
        sleep(5);               // Wait for 5 seconds
    }
}

int main() {
    pthread_t thread_1, thread_2;

    // Create two threads to handle temperature changes and display
    pthread_create(&thread_1, NULL, changeTemperature, NULL);
    pthread_create(&thread_2, NULL, displayTemperature, NULL);

    // Wait for the threads to finish
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    return 0;
}