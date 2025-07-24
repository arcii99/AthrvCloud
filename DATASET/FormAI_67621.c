//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
/* Internet Speed Test Application */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables
    int download_speed, upload_speed, ping_time;
    float download_time, upload_time;

    // Generate random speed and time values
    srand(time(NULL));
    download_speed = rand() % 101;
    upload_speed = rand() % 101;
    ping_time = rand() % 101;

    // Calculate download and upload times
    download_time = (float)100.0 / download_speed;
    upload_time = (float)100.0 / upload_speed;

    // Print results
    printf("Welcome to the Internet Speed Test!\n\n");
    printf("Your download speed is: %d Mbps\n", download_speed);
    printf("Your upload speed is: %d Mbps\n", upload_speed);
    printf("Your ping time is: %d ms\n", ping_time);
    printf("It would take %.2f seconds to download a 100 MB file at this speed.\n", download_time);
    printf("It would take %.2f seconds to upload a 100 MB file at this speed.\n", upload_time);

    return 0;
}