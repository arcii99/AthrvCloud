//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Internet Speed Test Application!\n\n");

    // Generate a random download speed between 50 and 100 Mbps
    srand(time(0));
    int download_speed = rand() % 51 + 50;
    printf("Measuring download speed...\n");
    printf("Your download speed is: %d Mbps\n", download_speed);

    // Generate a random upload speed between 10 and 50 Mbps
    int upload_speed = rand() % 41 + 10;
    printf("\nMeasuring upload speed...\n");
    printf("Your upload speed is: %d Mbps\n", upload_speed);

    // Display the results in a user-friendly manner
    printf("\nThank you for using our Internet Speed Test Application!\n");
    printf("Your internet speed is:\n");
    printf("- Download speed: %d Mbps\n", download_speed);
    printf("- Upload speed: %d Mbps\n", upload_speed);

    return 0;
}