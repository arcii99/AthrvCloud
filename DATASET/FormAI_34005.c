//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Prompt user to start the test
    printf("Welcome to the Happy Internet Speed Test!\n");
    printf("Press [ENTER] to start...");
    getchar();

    // Generate random numbers to simulate download and upload speeds
    srand(time(NULL));
    int downloadSpeed = rand() % 100 + 50; // 50-149 Mbps
    int uploadSpeed = rand() % 50 + 10;   // 10-59 Mbps

    // Display results
    printf("\nYour download speed is: %d Mbps\n", downloadSpeed);
    printf("Your upload speed is: %d Mbps\n", uploadSpeed);

    // Determine internet quality based on speeds
    if (downloadSpeed >= 100 && uploadSpeed >= 50) {
        printf("Wow! Your internet speed is fantastic! You must be very happy!\n");
    }
    else if (downloadSpeed >= 50 && uploadSpeed >= 25) {
        printf("Your internet speed is pretty good. You should be happy with that!\n");
    }
    else if (downloadSpeed >= 25 && uploadSpeed >= 10) {
        printf("Your internet speed is okay, but there's room for improvement. Don't worry, be happy!\n");
    }
    else {
        printf("Uh oh, your internet speed is too slow. You may not be happy with this result...\n");
    }

    return 0;
}