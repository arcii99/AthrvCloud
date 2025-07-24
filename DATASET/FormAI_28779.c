//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables
    int downloadSpeed, uploadSpeed;
    float latency;

    // Set seed for rand function
    srand(time(NULL));

    // Simulate internet speed tests
    downloadSpeed = rand() % 100 + 1;
    uploadSpeed = rand() % 100 + 1;
    latency = (float)(rand() % 50) / 10;

    // Display results
    printf("Internet Speed Test Result:\n");
    printf("Download Speed: %d Mbps\n", downloadSpeed);
    printf("Upload Speed: %d Mbps\n", uploadSpeed);
    printf("Latency: %.1f ms\n", latency);

    // Determine internet quality based on results
    if (downloadSpeed >= 50 && uploadSpeed >= 10 && latency <= 20)
    {
        printf("Internet Quality: Excellent!\n");
    }
    else if (downloadSpeed >= 25 && uploadSpeed >= 5 && latency <= 50)
    {
        printf("Internet Quality: Good.\n");
    }
    else if (downloadSpeed >= 10 && uploadSpeed >= 3 && latency <= 100)
    {
        printf("Internet Quality: Fair.\n");
    }
    else
    {
        printf("Internet Quality: Poor.\n");
    }

    return 0;
}