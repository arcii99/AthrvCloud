//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void internetSpeedTest() {
    printf("Starting internet speed test...\n");
    srand(time(NULL));
    int downloadSpeed = rand() % 101;
    int uploadSpeed = rand() % 101;
    printf("Download speed: %d Mbps\n", downloadSpeed);
    printf("Upload speed: %d Mbps\n", uploadSpeed);
    if (downloadSpeed < 10 || uploadSpeed < 5) {
        printf("Your internet speed is too slow.\n");
    } else {
        printf("Your internet speed is good.\n");
    }
}

int main() {
    char choice;

    do {
        printf("Press Enter to start the internet speed test or enter 'Q' to quit.");
        choice = getchar();
        if (choice != 'Q') {
            internetSpeedTest();
        }
        fflush(stdin); // Clear input buffer
    } while (choice != 'Q');

    return 0;
}