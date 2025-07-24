//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// Global variables
pthread_mutex_t lock;
bool time_machine = true;

// Time display function
void display_time(int year, int month, int day, int hour, int minute, int second) {
    printf("%02d/%02d/%d %02d:%02d:%02d\n", day, month, year, hour, minute, second);
}

// Time travel function
void time_travel() {
    int years = rand() % 5001;
    int months = rand() % 12;
    int days = rand() % 31;
    int hours = rand() % 24;
    int minutes = rand() % 60;
    int seconds = rand() % 60;

    pthread_mutex_lock(&lock);
    // Display current time
    printf("Current time: ");
    display_time(2021, 5, 10, 22, 30, 0);
    // Display time travel destination
    printf("Time travel destination: ");
    display_time(2021 - years, 5 - months, 10 - days, 22 - hours, 30 - minutes, -seconds);
    pthread_mutex_unlock(&lock);

    // Sleep for some time to simulate time travel
    sleep(5);

    pthread_mutex_lock(&lock);
    // Display time after time travel
    printf("Time after time travel: ");
    display_time(2021 - years, 5 - months, 10 - days, 22 - hours, 30 - minutes, -seconds);
    pthread_mutex_unlock(&lock);
}

// Time machine function
void* time_machine_function(void* arg) {
    while(time_machine) {
        // Wait for some time
        sleep(10);

        // Random time travel
        time_travel();
    }
}

int main() {
    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Seed random number generator
    srand(time(0));

    // Start time machine thread
    pthread_t time_machine_thread;
    pthread_create(&time_machine_thread, NULL, time_machine_function, NULL);

    // Wait for user input to stop time machine
    getchar();
    time_machine = false;

    // Wait for time machine thread to finish
    pthread_join(time_machine_thread, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    return 0;
}