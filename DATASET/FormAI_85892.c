//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int speed;
    srand(time(NULL)); // set the seed for random number generation
    
    printf("Welcome to the Internet Speed test!\n");
    printf("Press enter to begin the test...");
    getchar(); // wait for user to press enter
    
    printf("\nTesting download speed...");
    speed = rand() % 100 + 1; // generate a random speed between 1 and 100
    printf("\nYour download speed is: %d Mbps", speed);
    
    printf("\n\nTesting upload speed...");
    speed = rand() % 50 + 1; // generate a random speed between 1 and 50
    printf("\nYour upload speed is: %d Mbps", speed);

    printf("\n\nThank you for using the Internet Speed test!");
    return 0;
}