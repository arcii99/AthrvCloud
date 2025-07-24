//FormAI DATASET v1.0 Category: Temperature monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

// Function to handle SIGINT signal
void sigint_handler(int sig) {
    printf("\nTemperature monitoring stopped.\n");
    exit(0);
}

int main() {
    int temp;
    time_t current_time;

    signal(SIGINT, sigint_handler); // register signal handler

    printf("Temperature monitoring started...\n");

    while(1) {
        temp = rand() % 100;    // simulate temperature readings between 0-99
        current_time = time(NULL);  // get current time

        // Print temperature readings and time
        printf("Temperature: %d°C\tTime: %s", temp, asctime(localtime(&current_time)));

        sleep(1);   // wait for 1 second before taking next reading
    }

    return 0;
}