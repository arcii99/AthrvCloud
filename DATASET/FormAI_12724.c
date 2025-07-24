//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* function to calculate internet speed in Mbps */
double calculateSpeed(double fileSize, double time) {
    double speed = (fileSize / time) * 8; /* convert fileSize and time to bits and calculate speed */
    speed = speed / 1000000; /* convert speed to Mbps */
    return speed;
}

/* main function */
int main() {
    printf("Welcome to Internet Speed Test Application!\n");

    /* generate a random file size between 100 MB and 500 MB */
    srand(time(NULL));
    double fileSize = (rand() % 401) + 100;
    printf("File size: %.0f MB\n", fileSize);

    /* calculate expected download time based on internet speed */
    double maximumSpeed = 100; /* maximum internet speed in Mbps */
    double expectedTime = (fileSize * 8) / (maximumSpeed * 1000000);
    printf("Expected download time: %.2f seconds\n", expectedTime);

    /* simulate download time with a progress bar */
    printf("Downloading...");
    double progress = 0;
    double increment = 0.05; /* increment progress by 5% */
    while (progress < 1) {
        /* simulate network latency */
        double latency = (rand() % 101) / 1000.0; /* random latency between 0 and 0.1 seconds */
        double speed = calculateSpeed(fileSize, expectedTime + latency);
        
        /* update progress bar */
        progress += increment;
        int barWidth = 40;
        int pos = round(barWidth * progress);
        printf("\r[");
        for (int i = 0; i < barWidth; i++) {
            if (i < pos) printf("=");
            else if (i == pos) printf(">");
            else printf(" ");
        }
        printf("] %.0f%% %.2f Mbps", progress * 100, speed);

        /* wait for 0.1 seconds before updating progress bar again */
        struct timespec delay = { 0, 100000000 };
        nanosleep(&delay, NULL);
    }
    printf("\nDownload complete!\n");

    return 0;
}