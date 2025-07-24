//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    printf("Welcome to the Internet Speed Test Application\n\n");

    // Initialize random number generator
    srand(time(NULL));

    // Generate random speed (in Mbps) between 1 and 100
    int speed = rand() % 100 + 1;

    printf("Testing your internet speed...\n\n");
    printf("Your internet speed is %d Mbps.\n\n", speed);

    if (speed > 50) {
        printf("Congratulations! Your internet speed is above average.\n\n");
    } else if (speed > 10) {
        printf("Your internet speed is average.\n\n");
    } else {
        printf("Uh oh! Your internet speed is below average.\n\n");
    }

    printf("Thank you for using the Internet Speed Test Application!\n");

    return 0;
}