//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Set the seed for the random number generator
    srand(time(NULL));

    // Generate a random speed between 1 and 100 Mbps
    int speed = rand() % 100 + 1;

    // Print the speed to the console
    printf("Your internet speed is %d Mbps\n", speed);

    // Check if the speed is fast or slow
    if (speed >= 50) {
        printf("Your internet is fast!\n");
    } else {
        printf("Your internet is slow. You may want to check your connection.\n");
    }

    return 0;
}