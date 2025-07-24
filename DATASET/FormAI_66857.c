//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {

    time_t current_time;
    struct tm * tme;
    char * time_str;

    // Get the current local time and output it
    current_time = time(NULL);
    tme = localtime(&current_time);
    printf("Current time: %s", asctime(tme));

    // Simulate time travel
    printf("\nEntering time travel mode...\n\n");
    current_time -= 31536000; // travel one year back in time
    tme = localtime(&current_time);
    printf("Time travel successful. Current time: %s", asctime(tme));

    // Display a list of major events that occurred during the travelled time period
    printf("\nMajor events during this time period:\n");

    if (current_time >= -31536000 && current_time < 0) {
        printf(" - The first iPhone was released.\n");
    }
    if (current_time >= -315360000 && current_time < -31536000) {
        printf(" - The World Wide Web was invented by Tim Berners-Lee.\n");
    }
    if (current_time >= -3153600000 && current_time < -315360000) {
        printf(" - The first personal computers were released, including the Apple II and Commodore PET.\n");
    }
    if (current_time >= -31536000000 && current_time < -3153600000) {
        printf(" - The first moon landing occurred.\n");
    }

    // Simulate returning to the present
    printf("\nReturning to the present...\n\n");
    current_time = time(NULL);
    tme = localtime(&current_time);
    printf("Time travel successful. Current time: %s", asctime(tme));

    return 0;
}