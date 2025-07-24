//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed for random number generation

    printf("Welcome to the Retro Speed Test\n");
    printf("------------------------------------\n");
    printf("Press any key to start.\n");
    getchar(); // Wait for user to hit a key

    int download_speed = rand() % 101; // Generate a random download speed between 0 and 100
    int upload_speed = rand() % 101; // Generate a random upload speed between 0 and 100

    printf("Testing Download Speed...\n");
    for(int i = 0; i <= download_speed; i++) {
        printf("Download: %d%%\n", i);
        sleep(1); // Pause for 1 second to simulate speed test
    }

    printf("Testing Upload Speed...\n");
    for(int i = 0; i <= upload_speed; i++) {
        printf("Upload: %d%%\n", i);
        sleep(1); // Pause for 1 second to simulate speed test
    }

    printf("Download Speed: %d Mbps\n", download_speed); // Display download speed
    printf("Upload Speed: %d Mbps\n", upload_speed); // Display upload speed

    printf("\nThanks for using the Retro Speed Test!\n");
    return 0;
}