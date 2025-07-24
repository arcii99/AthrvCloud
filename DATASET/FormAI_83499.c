//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int download = 0, upload = 0;
    srand(time(NULL)); // set random seed for testing purposes

    // simulate internet speed test
    for (int i = 0; i < 10; i++) {
        // download speed (random number between 5 and 30)
        int d = (rand() % 26) + 5; 
        // upload speed (random number between 2 and 15)
        int u = (rand() % 14) + 2;
        printf("Test %d - download: %d Mbps, upload: %d Mbps\n", i+1, d, u);
        download += d;
        upload += u;
    }

    // calculate average speed
    download /= 10;
    upload /= 10;

    printf("\nAverage speed - download: %d Mbps, upload: %d Mbps\n", download, upload);

    return 0;
}