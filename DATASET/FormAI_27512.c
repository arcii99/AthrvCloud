//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    // Retrieve the current time
    time_t start = time(NULL);

    // Use wget to download a test file
    system("wget -O /dev/null http://speedtest.tele2.net/100MB.zip");

    // Calculate the elapsed time
    time_t end = time(NULL);
    double elapsed_time = difftime(end, start);

    // Calculate the download speed in megabytes per second
    double speed = 100.0 / (1000000.0 * elapsed_time);

    // Print out the results
    printf("Your internet speed is: %.2f Mbps\n", speed);

    return 0;
}