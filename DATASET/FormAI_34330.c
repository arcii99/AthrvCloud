//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float download_speed, upload_speed;
    int ping, speed_test_id;
    time_t current_time;
    char result[20];

    // Generate random values for download speed, upload speed, and ping
    srand(time(NULL));
    download_speed = (float)(rand() % 1000) + ((float)(rand() % 100) / 100);
    upload_speed = (float)(rand() % 1000) + ((float)(rand() % 100) / 100);
    ping = rand() % 100;

    // Generate a unique speed test ID and current time
    speed_test_id = rand() % 10000;
    time(&current_time);

    // Determine the internet speed result based on download speed
    if(download_speed >= 1000)
        strcpy(result, "Excellent");
    else if(download_speed >= 500)
        strcpy(result, "Good");
    else if(download_speed >= 100)
        strcpy(result, "Average");
    else if(download_speed >= 50)
        strcpy(result, "Poor");
    else
        strcpy(result, "Very Poor");

    // Display the speed test results
    printf("Speed Test Results\n");
    printf("------------------\n");
    printf("Download Speed: %.2f Mbps\n", download_speed);
    printf("Upload Speed: %.2f Mbps\n", upload_speed);
    printf("Ping: %d ms\n", ping);
    printf("Internet Speed: %s\n", result);
    printf("Speed Test ID: %d\n", speed_test_id);
    printf("Time of test: %s", ctime(&current_time));

    return 0;
}