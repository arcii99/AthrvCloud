//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    srand(time(NULL)); // initialize random seed

    // variables to hold simulated download and upload speeds,
    // measured in megabits per second (Mbps)
    float download = (float) (rand() % 100) / 10; // simulate download speed between 0 and 10 Mbps
    float upload = (float) (rand() % 50) / 10; // simulate upload speed between 0 and 5 Mbps

    printf("Your internet speed test results:\n");
    printf("Download speed: %.1f Mbps\n", download);
    printf("Upload speed: %.1f Mbps\n", upload);
}