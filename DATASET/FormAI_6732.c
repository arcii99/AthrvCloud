//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Internet Speed Test App!\n\n");

    // start timer
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();

    // simulate a download speed of 10-1000 Mbps
    srand(time(NULL));
    int download_speed = rand() % 991 + 10;
    printf("Testing your download speed...\n");
    printf("Download speed: %d Mbps\n", download_speed);

    // simulate an upload speed of 1-100 Mbps
    int upload_speed = rand() % 100 + 1;
    printf("\nTesting your upload speed...\n");
    printf("Upload speed: %d Mbps\n", upload_speed);

    // end timer and calculate total time
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("\nTest completed in %.2f seconds\n", total_t);

    return 0;
}