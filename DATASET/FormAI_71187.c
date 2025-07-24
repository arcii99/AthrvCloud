//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

#define MAX_USAGE 100
#define MIN_USAGE 0
#define SLEEP_TIME 1 // in seconds

int main(){
    // Initialize Random Seed
    srand(time(0)); 

    while(1){
        int usage = (rand() % (MAX_USAGE - MIN_USAGE + 1)) + MIN_USAGE; // Generate Random CPU Usage
        printf("Current CPU Usage: %d%%\n", usage);
        sleep(SLEEP_TIME); // Wait for SLEEP_TIME seconds
    }

    return 0;
}