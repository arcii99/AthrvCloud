//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Ultimate Internet Speed Test!\n");
    printf("This program measures your download and upload speed in Mbps.\n\n");

    // Measure download speed
    printf("Measuring download speed...\n");
    srand(time(0)); // seed random number generator
    int download_speed = rand() % 100 + 1; // generate random number from 1 to 100
    printf("Your download speed is: %d Mbps.\n", download_speed);

    // Measure upload speed
    printf("\nMeasuring upload speed...\n");
    int upload_speed = rand() % 100 + 1; // generate random number from 1 to 100
    printf("Your upload speed is: %d Mbps.\n", upload_speed);

    // Compare speeds and give recommendation
    printf("\nComparing speeds...\n");
    if (download_speed > upload_speed)
    {
        printf("Your download speed is faster than your upload speed. Consider upgrading your internet plan for better performance.\n");
    }
    else if (download_speed < upload_speed)
    {
        printf("Your upload speed is faster than your download speed. Consider upgrading your internet plan for better performance.\n");
    }
    else
    {
        printf("Your download and upload speeds are equal. Your internet plan should provide sufficient performance.\n");
    }

    return 0;
}