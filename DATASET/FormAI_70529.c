//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    srand(time(0));
    int speed = rand() % 100; // Generates a random Internet Speed value between 0 and 100
    printf("Connecting to the Internet...\n");
    printf("Establishing a secure connection...\n");
    printf("Connection established!\n");
    printf("Running Internet speed test...\n");
    printf("Calculating download speed...\n");
    printf("Calculating upload speed...\n");
    printf("Your Internet speed is %d Mbps.\n", speed);
    
    if (speed <= 10) {
        printf("Your speed is slower than a turtle!\n");
    } else if (speed <= 25) {
        printf("Your speed is slower than a snail!\n");
    } else if (speed <= 50) {
        printf("Your speed is slower than a cheetah!\n");
    } else if (speed <= 75) {
        printf("Your speed is faster than a gazelle!\n");
    } else {
        printf("Your speed is faster than a lightning bolt!\n");
    }
    
    return 0;
}