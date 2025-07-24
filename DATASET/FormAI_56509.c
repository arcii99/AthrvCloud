//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: future-proof
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Enum to represent the state of the traffic light
typedef enum {
    RED, YELLOW, GREEN
} traffic_light_state_t;

traffic_light_state_t traffic_light_state = RED;

// Function to handle the switching of the traffic light
void handle_traffic_light() {
    switch (traffic_light_state) {
        case RED:
            printf("Traffic Light: RED\n");
            traffic_light_state = GREEN;
            break;
        case YELLOW:
            printf("Traffic Light: YELLOW\n");
            traffic_light_state = RED;
            break;
        case GREEN:
            printf("Traffic Light: GREEN\n");
            traffic_light_state = YELLOW;
            break;
    }
}

// Function to handle the signal interrupt and exit the program
void handle_signal(int signal_num) {
    printf("\nExiting Traffic Light Controller\n");
    exit(signal_num);
}

int main(int argc, char const *argv[]) {

    // Handle the interrupt signal
    signal(SIGINT, handle_signal);

    while (true) {

        // Get the current time
        time_t current_time = time(NULL);

        // Use the last 2 digits of the time as the random seed
        srand(current_time % 100);

        // Get a random number between 1 and 10
        int random_num = rand() % 10 + 1;

        // Delay the program for the random amount of time
        sleep(random_num);

        // Handle the switching of the traffic light
        handle_traffic_light();
    }

    return 0;
}