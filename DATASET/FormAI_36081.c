//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Function to simulate internet speed test */
double speedTest() {

    double start_time, end_time, speed;
    char random_data[1048576];  // One MegaByte of data
    int i;

    /* get current time */
    start_time = (double)clock()/(double)CLOCKS_PER_SEC;

    /* random data generation */
    for(i=0; i<1048576; i++) {
        random_data[i] = rand() % 256;
    }

    /* get current time after data generation */
    end_time = (double)clock()/(double)CLOCKS_PER_SEC;

    /* calculate speed */
    speed = (double)(1048576*8)/(end_time - start_time)/(double)1000000;

    return speed;
}

int main() {

    printf("Starting Internet Speed Test...\n\n");

    /* Seed for random number generation */
    srand((unsigned int)time(NULL));

    /* Execute simulated speed test */
    double speed = speedTest();

    /* Print the results */
    printf("Your internet speed is: %.2f Mb/s\n", speed);

    if(speed >= 100) {
        printf("Great! You have an excellent internet connection.\n");
    } else if(speed >= 50) {
        printf("Your internet connection is good.\n");
    } else if(speed >= 10) {
        printf("Your internet connection is average.\n");
    } else {
        printf("Your internet speed is slow. You may want to contact your internet service provider.\n");
    }

    return 0;
}