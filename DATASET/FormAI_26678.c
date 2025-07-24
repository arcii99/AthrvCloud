//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BILLION 1000000000

int main()
{
    int downloadSpeed, uploadSpeed;
    long long int downloadStart, downloadEnd, uploadStart, uploadEnd;
    struct timespec start, end;

    // Download Test
    printf("Starting download speed test...\n");

    clock_gettime(CLOCK_REALTIME, &start);
    downloadStart = start.tv_nsec;

    // Simulating download by delaying for 5 seconds
    sleep(5);

    clock_gettime(CLOCK_REALTIME, &end);
    downloadEnd = end.tv_nsec;

    // Calculate download speed
    downloadSpeed = (int)((BILLION * 8) / ((double)(downloadEnd - downloadStart)));

    printf("Download speed: %d Mbps\n", downloadSpeed);

    // Upload Test
    printf("Starting upload speed test...\n");

    clock_gettime(CLOCK_REALTIME, &start);
    uploadStart = start.tv_nsec;

    // Simulating upload by delaying for 7 seconds
    sleep(7);

    clock_gettime(CLOCK_REALTIME, &end);
    uploadEnd = end.tv_nsec;

    // Calculate upload speed
    uploadSpeed = (int)((BILLION * 8) / ((double)(uploadEnd - uploadStart)));

    printf("Upload speed: %d Mbps\n", uploadSpeed);

    return 0;
}