//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Get download speed
int download_speed() {
    srand(time(NULL));
    int download = rand() % 101; // Generate random download speed from 0 to 100 Mbps
    return download;
}

// Get upload speed
int upload_speed() {
    srand(time(NULL));
    int upload = rand() % 101; // Generate random upload speed from 0 to 100 Mbps
    return upload;
}

// Main function
int main() {
    int download = download_speed();
    int upload = upload_speed();

    printf("Welcome to the Internet Speed Test!\n\n");
    printf("Your download speed is: %d Mbps\n", download);
    printf("Your upload speed is: %d Mbps\n\n", upload);

    if(download > 50 && upload > 50) {
        printf("Congratulations! Your internet speed is very fast!\n");
    } else if(download > 20 && upload > 20) {
        printf("Your internet speed is good, but could be faster.\n");
    } else {
        printf("We recommend that you upgrade your internet speed.\n");
    }

    return 0;
}