//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MB 1048576

int main() {
    int speed; // speed variable to hold the Internet Speed
    time_t t; // time_t variable to seed random number generator
    srand((unsigned) time(&t)); // seed random number generator
    
    // generate a random speed between 1 MBPS and 100 MBPS
    speed = (rand() % 100) + 1;
    speed *= MB;
    
    printf("Welcome to the C Internet Speed Test Application\n");
    printf("Testing...\n");
    printf("Your Internet Speed is: %d MBPS\n", speed/MB);
    
    // check if Internet Speed is less than 10 MBPS
    if (speed < 10*MB) {
        printf("Your Internet Speed is slower than 10 MBPS. Please contact your Internet Service Provider\n");
    } else {
        printf("Your Internet Speed is faster than 10 MBPS. Happy browsing!\n");
    }
    
    return 0;
}