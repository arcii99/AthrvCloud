//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    printf("Starting internet speed test...\n\n");
    
    // Generate random download speed
    srand(time(NULL));
    int download_speed = rand() % 100 + 1;
    printf("Download speed: %d Mb/s\n", download_speed);
    
    // Generate random upload speed
    int upload_speed = rand() % 50 + 1;
    printf("Upload speed: %d Mb/s\n", upload_speed);
    
    // Simulate speed test by waiting for a few seconds
    printf("\nRunning speed test...\n");
    sleep(2);
    printf("Speed test complete!\n\n");
    
    // Display results
    printf("Download speed: %d Mb/s\n", download_speed);
    printf("Upload speed: %d Mb/s\n", upload_speed);
    
    return 0;
}