//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random internet speed
double generateSpeed() {
    double speed = rand() % 50 + 1; // Generates a random speed between 1 and 50
    return speed;
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    // Display welcome message and instructions
    printf("Welcome to the Internet Speed Test Program\n");
    printf("Press 'Enter' to begin the speed test\n");

    char input; // Variable to hold user input
    scanf("%c", &input); // Wait for user to press Enter

    printf("Generating internet speed...\n\n");

    // Call generateSpeed function to generate a random internet speed
    double speed = generateSpeed();

    // Display the internet speed to the user
    printf("Your internet speed is %.2f Mbps\n", speed);

    // Determine the quality of the internet speed
    if (speed >= 25) {
        printf("Excellent speed\n");
    } else if (speed >= 10) {
        printf("Good speed\n");
    } else if (speed >= 5) {
        printf("Average speed\n");
    } else {
        printf("Poor speed\n");
    }

    return 0; // Exit program
}