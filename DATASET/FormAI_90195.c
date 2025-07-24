//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int speed = rand() % 101; // Generate random speed between 0 and 100 Mbps
    printf("Testing internet speed...");
    for (int i = 0; i < 3; i++) { // Simulate testing for 3 seconds
        printf(".");
        sleep(1); // Sleep for 1 second
    }
    printf("\n\nYour internet speed is: %d Mbps\n\n", speed);
    if (speed < 10) {
        printf("Your internet speed is very slow. Consider upgrading your plan.\n");
    } else if (speed < 50) {
        printf("Your internet speed is average.\n");
    } else {
        printf("Your internet speed is great! Enjoy your fast internet.\n");
    }
    return 0;
}