//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed the random number generator

    int download_speed = rand() % 101; // Generate a random download speed between 0 and 100 Mbps
    int upload_speed = rand() % 101; // Generate a random upload speed between 0 and 100 Mbps

    printf("Welcome to the Internet Speed Test Application!\n");
    printf("This test will measure your download and upload speeds.\n\n");

    printf("Testing your download speed...\n");
    for (int i = 0; i < 10; i++) {
        printf(". ");
        fflush(stdout); // Flush the output buffer to ensure the dots are printed immediately
        sleep(1); // Wait for 1 second to simulate testing
    }
    printf("\nDownload speed: %d Mbps\n\n", download_speed);

    printf("Testing your upload speed...\n");
    for (int i = 0; i < 10; i++) {
        printf(". ");
        fflush(stdout); // Flush the output buffer to ensure the dots are printed immediately
        sleep(1); // Wait for 1 second to simulate testing
    }
    printf("\nUpload speed: %d Mbps\n\n", upload_speed);

    printf("Thank you for using the Internet Speed Test Application!\n");
    return 0;
}