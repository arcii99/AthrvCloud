//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int downloadSpeed, uploadSpeed;
    srand(time(NULL)); // set random seed for download/upload speed
    
    // generate random download and upload speeds between 1 and 100 Mbps
    downloadSpeed = rand() % 100 + 1;
    uploadSpeed = rand() % 100 + 1;
    
    // display download and upload speeds
    printf("Your download speed is %d Mbps\n", downloadSpeed);
    printf("Your upload speed is %d Mbps\n", uploadSpeed);
    
    // check if download speed meets minimum requirement of 25 Mbps
    if (downloadSpeed >= 25) {
        printf("Your download speed meets the minimum requirement of 25 Mbps!\n");
    } else {
        printf("Your download speed does not meet the minimum requirement of 25 Mbps.\n");
    }
    
    // check if upload speed meets minimum requirement of 3 Mbps
    if (uploadSpeed >= 3) {
        printf("Your upload speed meets the minimum requirement of 3 Mbps!\n");
    } else {
        printf("Your upload speed does not meet the minimum requirement of 3 Mbps.\n");
    }
    
    return 0;
}