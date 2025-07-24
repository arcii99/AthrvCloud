//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    char* url = "https://www.google.com";
    char buffer[1024];
    FILE* speedTest = fopen("speedTest.txt", "w");

    fprintf(speedTest, "Internet Speed Test Results - %s", url);

    for (int i = 0; i < 10; i++) {
        long startTime = time(NULL);
        sprintf(buffer, "curl --output /dev/null --silent --head --write-out 'Speed: %{speed_download}s' %s", url);
        system(buffer);
        long endTime = time(NULL);

        double latency = difftime(endTime, startTime);
        double speed = atof(buffer);

        fprintf(speedTest, "\nTest %d - Latency: %lf seconds\tSpeed: %lf Mbps", i+1, latency, speed);
    }

    fclose(speedTest);

    return 0;
}