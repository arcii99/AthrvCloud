//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Brave Internet Speed Test Application!\n\n");

    srand(time(NULL));
    int download_speed = rand() % 1001; // generate a random download speed between 0 and 1000 Mbps
    int upload_speed = rand() % 1001; // generate a random upload speed between 0 and 1000 Mbps

    printf("Your download speed is: %d Mbps\n", download_speed);
    printf("Your upload speed is: %d Mbps\n", upload_speed);

    if (download_speed < 25 && upload_speed < 5) {
        printf("\nWow, your internet speed is painfully slow! You might want to consider upgrading your plan.\n");
    }
    else if (download_speed >= 25 && download_speed < 50 && upload_speed >= 5 && upload_speed < 10) {
        printf("\nYour internet speed is okay, but there's definitely room for improvement.\n");
    }
    else if (download_speed >= 50 && download_speed < 100 && upload_speed >= 10 && upload_speed < 20) {
        printf("\nLooks like you've got a pretty decent internet speed!\n");
    }
    else if (download_speed >= 100 && upload_speed >= 20) {
        printf("\nWow, your internet speed is blazing fast! You're definitely getting your money's worth.\n");
    }
    else {
        printf("\nThere seems to be an issue with your internet speed test results. Please try again later.\n");
    }

    return 0;
}