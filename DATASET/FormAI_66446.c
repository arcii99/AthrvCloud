//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define KB_TO_BIT 8192
#define MB_TO_BIT 8388608

int main(void) {
    struct timespec start_time, end_time;
    double elapsed_time;

    // flushes the input and output buffers, 
    // ensuring the output is printed before starting the measuring
    setbuf(stdout, NULL);

    // start measuring time
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // perform the download speed test via HTTP
    system("curl -o /dev/null https://speedtest.tele2.net/100MB.zip");

    // end measuring time
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    // calculate the time elapsed in seconds
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) + 
                   (double)(end_time.tv_nsec - start_time.tv_nsec) / 1000000000;

    // calculate download speed in Mbps and Kbps
    double mbps = (100 / elapsed_time) / MB_TO_BIT;
    double kbps = mbps * KB_TO_BIT;

    // print the results
    printf("Download speed: %.2f Mbps or %.2f Kbps\n", mbps, kbps);

    return 0;
}