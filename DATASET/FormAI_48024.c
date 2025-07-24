//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate internet speed test
void internet_speed_test() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate random upload and download speeds
    float upload_speed = (float)(rand() % 1000) / 10;
    float download_speed = (float)(rand() % 1000) / 10;

    // Print out the results
    printf("Testing internet speed...\n");
    printf("Upload speed: %.1f Mbps\n", upload_speed);
    printf("Download speed: %.1f Mbps\n", download_speed);
}

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");

    // Loop indefinitely until the user decides to quit
    while (1) {
        printf("Press 's' to start the speed test or 'q' to quit: ");

        // Get user input
        char input = getchar();

        // Flush the input buffer
        while (getchar() != '\n');

        // Determine the user's choice
        if (input == 's') {
            internet_speed_test();
        } else if (input == 'q') {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}