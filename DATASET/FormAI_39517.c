//FormAI DATASET v1.0 Category: Weather simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5 // number of cities in simulation
#define SIM_DURATION 10 // simulation duration in seconds

int temps[NUM_CITIES] = {0}; // array to hold temperature values for each city

// function to simulate temperature change for a given city
void simulateCityTemp(int index) {
    int base_temp = temps[index]; // current temperature
    int rand_num = rand() % 11 - 5; // random number between -5 and 5
    temps[index] = base_temp + rand_num; // update temperature with random value
}

// asynchronous function to simulate temperature change for all cities
void simulateWeather(void* arg) {
    time_t start = time(NULL);
    while (difftime(time(NULL), start) < SIM_DURATION) {
        for (int i = 0; i < NUM_CITIES; i++) {
            simulateCityTemp(i);
        }
        // sleep for 1 second between temperature updates
        #ifdef _WIN32
            Sleep(1000);
        #else
            usleep(1000000);
        #endif
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t simulationThread;
    srand(time(NULL)); // seed random number generator
    printf("Starting weather simulation...\n");
    // initialize temperatures for each city to a random value between 0 and 100
    for (int i = 0; i < NUM_CITIES; i++) {
        temps[i] = rand() % 101;
        printf("City %d temperature: %dF\n", i + 1, temps[i]);
    }
    // create asynchronous thread to simulate weather
    pthread_create(&simulationThread, NULL, simulateWeather, NULL);
    // wait for simulation to finish
    pthread_join(simulationThread, NULL);
    // print final temperature values for each city
    printf("Simulation finished.\nFinal temperatures:\n");
    for (int i = 0; i < NUM_CITIES; i++) {
        printf("City %d temperature: %dF\n", i + 1, temps[i]);
    }
    return 0;
}