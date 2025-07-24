//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// function to simulate internet speed test
void internet_speed_test() {
    srand(time(NULL));
    double time_taken = rand()/(double)RAND_MAX * 10; // randomly generate time taken (0-10 seconds)
    printf("Running internet speed test...\n");
    usleep(time_taken * 1000000); // delay program execution for time taken
    double speed = 1024/(time_taken + 1); // calculate speed in kilobytes per second
    printf("Test complete. Your internet speed is %0.2f Kbps.\n", speed);
}

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Press any key to start the test...\n");
    getchar(); // wait for user input
    internet_speed_test(); // run internet speed test
    return 0;
}