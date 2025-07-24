//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    // Define variables
    int download_speed, upload_speed;
    int download_counter = 0, upload_counter = 0;
    int download_total = 0, upload_total = 0;
    
    // Print welcome message
    printf("Welcome to the Internet Speed Test!\n\n");
    
    // Perform download speed test
    printf("Testing download speed...\n");
    srand(time(0)); // Initialize random number generator
    while (download_counter < 10) {
        int speed = rand() % 100; // Generate a random speed between 0 and 100 Mbps
        printf("Download Speed: %d Mbps\n", speed);
        download_total += speed;
        download_counter++;
        sleep(1); // Pause for 1 second
    }
    download_speed = download_total / 10;
    printf("Download speed test complete!\n\n");
    
    // Perform upload speed test
    printf("Testing upload speed...\n");
    srand(time(0)); // Initialize random number generator
    while (upload_counter < 10) {
        int speed = rand() % 10; // Generate a random speed between 0 and 10 Mbps
        printf("Upload Speed: %d Mbps\n", speed);
        upload_total += speed;
        upload_counter++;
        sleep(1); // Pause for 1 second
    }
    upload_speed = upload_total / 10;
    printf("Upload speed test complete!\n\n");
    
    // Print results
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed);
    if (download_speed > 50 && upload_speed > 5) {
        printf("Congratulations! Your internet speed is excellent!\n");
    } else if (download_speed > 20 && upload_speed > 2) {
        printf("Your internet speed is good, but could be better.\n");
    } else {
        printf("Your internet speed is poor. Please contact your internet service provider.\n");
    }
    
    return 0;
}