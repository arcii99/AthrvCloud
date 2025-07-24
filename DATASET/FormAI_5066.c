//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int download_speed, upload_speed;
    srand(time(NULL)); // initialize random seed
    
    download_speed = rand() % 101 + 1; // generate random download speed between 1 and 100 Mbps 
    upload_speed = rand() % 101 + 1; // generate random upload speed between 1 and 100 Mbps 

    printf("Your internet speed test results:\n");
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed);

    if (download_speed >= 50 && upload_speed >= 10) {
        printf("Congratulations! Your internet speed is excellent!");
    } else if (download_speed >= 20 && upload_speed >= 5) {
        printf("Your internet speed is good, but could be better.");
    } else {
        printf("Uh oh, your internet speed is below average. Consider upgrading your plan.");
    }
    
    return 0;
}