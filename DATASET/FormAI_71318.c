//FormAI DATASET v1.0 Category: Error handling ; Style: post-apocalyptic
/* Post-Apocalyptic C Error Handling Example Program: Survival or Failure */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a custom error type
typedef enum {
    SURVIVAL_ERROR = -1,
    SANITIZATION_ERROR = -2,
    COMMUNICATION_ERROR = -3,
    NAVIGATION_ERROR = -4
} ErrorType;

// Function prototypes
void attemptSanitization();
void attemptCommunication();
void attemptNavigation();

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Attempt sanitization
    attemptSanitization();

    // Attempt communication
    attemptCommunication();

    // Attempt navigation
    attemptNavigation();

    // If we made it this far, we survived!
    printf("We made it out alive!\n");
    return 0;
}

// Attempt to sanitize the surroundings
void attemptSanitization() {
    int chance = rand() % 10;
    if (chance < 3) {
        printf("Sanitization failed!\n");
        exit(SANITIZATION_ERROR);
    }
    else {
        printf("Sanitization successful.\n");
    }
}

// Attempt to establish communication with other survivors
void attemptCommunication() {
    int chance = rand() % 10;
    if (chance < 5) {
        printf("Communication failed!\n");
        exit(COMMUNICATION_ERROR);
    }
    else {
        printf("Communication successful.\n");
    }
}

// Attempt to navigate to safety
void attemptNavigation() {
    int chance = rand() % 10;
    if (chance < 7) {
        printf("Navigation failed!\n");
        exit(NAVIGATION_ERROR);
    }
    else {
        printf("Navigation successful.\n");
    }
}