//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SPEED 1000 // maximum speed allowed in megabits per second

int main()
{
    srand(time(NULL)); // initialize random number generator

    printf("Welcome to the Brave Internet Speed Test Application!\n");
    printf("This application will test your internet speed by simulating a download.\n");
    printf("Please enter your internet speed in megabits per second: ");

    float speed;
    scanf("%f", &speed);

    if (speed > MAX_SPEED)
    {
        printf("Sorry, your internet speed exceeds the maximum allowed speed of %d Mbps.\n", MAX_SPEED);
        return 1; // exit program with error code
    }

    printf("Simulating download...\n\n");

    float progress = 0.0;
    float download_speed = speed / 8.0; // convert megabits to megabytes per second

    while (progress < 100.0)
    {
        float random_number = (float)rand() / (float)RAND_MAX; // generate random number between 0 and 1
        float download_time = 1.0 / download_speed + random_number; // simulate download time with random delay
        progress += download_speed / speed * 100.0; // calculate progress as percentage of total download size
        printf("Downloaded %.2f%% at %.2f MB/s\n", progress, download_speed);
        sleep(download_time); // simulate download time
    }

    printf("\nDownload complete at %.2f MB/s!\n", download_speed);

    return 0; // exit program with success code
}