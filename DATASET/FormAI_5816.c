//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("This program will help you determine your current internet speed.\n");

    // Randomly generate a download speed between 1 and 100 Mbps
    srand(time(NULL));
    int downloadSpeed = (rand() % 100) + 1;
    printf("\nDownloading at %d Mbps...\n", downloadSpeed);

    // Randomly generate an upload speed between 1 and 100 Mbps
    int uploadSpeed = (rand() % 100) + 1;
    printf("Uploading at %d Mbps...\n\n", uploadSpeed);

    printf("Your internet speed test results are in:\n");
    printf("Download Speed: %d Mbps\n", downloadSpeed);
    printf("Upload Speed: %d Mbps\n", uploadSpeed);

    if(downloadSpeed >= 50 && uploadSpeed >= 50) {
        printf("\nWow, you have a really fast internet connection!\n");
    }
    else if(downloadSpeed >= 25 && uploadSpeed >= 25) {
        printf("\nYour internet connection seems to be stable and fast.\n");
    }
    else {
        printf("\nYour internet connection could be better. Consider upgrading your plan.\n");
    }

    printf("\nThank you for using our Internet Speed Test Application!\n");

    return 0;
}