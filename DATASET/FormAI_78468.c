//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int speed, time_taken;
    clock_t start, end;

    printf("Starting the internet speed test...\n\n");

    start = clock();

    // Simulate downloading a file of size 100 MB
    for(int i=0; i<100; i++) {
       for(int j=0; j<1048576; j++);
    }

    end = clock();

    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    speed = 100 / time_taken;

    printf("Download Speed: %d MB/s\n", speed);

    return 0;
}