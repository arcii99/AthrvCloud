//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    int usage = rand() % 101; // generate a random CPU usage between 0 and 100
    printf("CPU usage: %d%%\n", usage);

    // Puzzling loop to calculate and display a countdown timer until CPU usage drops below 50%
    int countdown = 10;
    while(usage >= 50) {
        usage -= (rand() % 11) + 10; // decrease usage by a random value between 10 and 20
        countdown--; // decrease countdown by 1
        printf("Waiting for CPU usage to drop below 50%%... %d seconds remaining.\n", countdown);
        sleep(1); // pause program for 1 second
    }

    printf("CPU usage has dropped below 50%%. Monitoring stopped.\n");
    return 0;
}