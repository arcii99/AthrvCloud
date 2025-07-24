//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator

    // generate random speed test results
    int download_speed = rand() % 1000 + 1; // download speed between 1 and 1000 Mbps
    int upload_speed = rand() % 1000 + 1; // upload speed between 1 and 1000 Mbps
    
    printf("Welcome to the Internet Speed Test Application\n\n");
    printf("Testing download speed...\n");
    printf("Download Speed: %d Mbps\n", download_speed);
    printf("Testing upload speed...\n");
    printf("Upload Speed: %d Mbps\n\n", upload_speed);

    // determine internet speed quality based on speed test results
    if (download_speed > 500 && upload_speed > 500) {
        printf("Your internet speed is excellent!\n");
    } else if (download_speed > 250 && upload_speed > 250) {
        printf("Your internet speed is good!\n");
    } else if (download_speed > 100 && upload_speed > 100) {
        printf("Your internet speed is average.\n");
    } else {
        printf("Your internet speed is poor. Consider upgrading your plan.\n");
    }

    return 0;
}