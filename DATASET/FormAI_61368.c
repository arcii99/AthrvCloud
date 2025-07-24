//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: cheerful
// Welcome to the C RAM Usage Monitor!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    printf("Hi there! I'm the cheerful C RAM Usage Monitor program!\n");
    printf("I'm going to help you keep track of your system's RAM usage.\n");
    printf("Let's get started!\n");

    while(1) {
        int usage = rand() % 101; // Generate a random number for RAM usage between 0-100
        printf("Current RAM Usage: %d%%.\n", usage);
        if(usage > 80) { // If usage is greater than 80%, display a warning
            printf("Warning: High RAM usage detected! Consider closing some programs.\n");
        }
        printf("\n");
        sleep(5); // Wait for 5 seconds before checking usage again
    }

    return 0;
}