//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool checkInternetSpeed()
{
    int numIterations = 5;
    int numBytesToDownload = 100000000;

    for(int i = 0; i < numIterations; i++)
    {
        clock_t startTime = clock();

        char* data = (char*)malloc(numBytesToDownload * sizeof(char));

        clock_t endTime = clock();

        double timeElapsed = (double)(endTime - startTime) / CLOCKS_PER_SEC;

        double downloadSpeedMbps = ((numBytesToDownload / 1000000) * 8) / timeElapsed;

        printf("Iteration %d: Download Speed = %.2f Mbps\n", i+1, downloadSpeedMbps);

        free(data);

        if(downloadSpeedMbps < 50.0) 
        {
            printf("Your internet connection is too slow. Please contact your internet service provider.\n");
            return false;
        }
    }

    printf("Congratulations! Your internet connection is fast enough.\n");
    return true;
}

int main()
{
    printf("Welcome to the Internet Speed Test Application\n");
    bool internetSpeedCheck = checkInternetSpeed();
    printf("\nThank you for using the Internet Speed Test Application\n");

    return 0;
}