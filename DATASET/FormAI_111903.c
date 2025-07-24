//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int download_speed;
    int upload_speed;
    int ping;

    // Simulate download speed calculation
    srand(time(NULL));
    download_speed = rand() % 1000 + 1;

    // Simulate upload speed calculation
    upload_speed = rand() % 1000 + 1;

    // Simulate ping calculation
    ping = rand() % 50 + 1;

    // Display results
    printf("Your Internet Speed Test Results:\n");
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed);
    printf("Ping: %d ms\n", ping);

    // Give recommendations based on results
    if (download_speed < 5) {
        printf("Your download speed is below average. Consider upgrading your internet plan.\n");
    } else if (download_speed < 10) {
        printf("Your download speed is average. Consider upgrading if you frequently download large files.\n");
    } else {
        printf("Your download speed is above average. Great job!\n");
    }

    if (upload_speed < 1) {
        printf("Your upload speed is below average. Consider upgrading your internet plan.\n");
    } else if (upload_speed < 5) {
        printf("Your upload speed is average. Consider upgrading if you frequently upload large files.\n");
    } else {
        printf("Your upload speed is above average. Great job!\n");
    }

    if (ping < 20) {
        printf("Your ping is excellent. You should have no issues with online gaming or video conferencing.\n");
    } else if (ping < 50) {
        printf("Your ping is average. You may experience slight delays in online gaming or video conferencing.\n");
    } else {
        printf("Your ping is poor. You may experience significant delays in online gaming or video conferencing.\n");
    }

    return 0;
}