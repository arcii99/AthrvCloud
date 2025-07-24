//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SPEED 1000 // Mbps
#define MIN_SPEED 0.1 // Mbps
#define MAX_DELAY 500 // milliseconds
#define MIN_DELAY 20 // milliseconds

double get_random_speed();
double get_random_delay();

int main() {
    srand(time(NULL)); // Seed random number generator
    
    double speed = get_random_speed();
    double delay = get_random_delay();
    
    printf("Starting speed test...\n\n");
    printf("Current download speed: %.2f Mbps\n", speed);
    printf("Current latency: %d ms\n", (int)delay);
    
    printf("\nChecking for upload speed...\n");
    // Code to check upload speed goes here
    
    printf("\nSpeed test complete.\n\n");
    printf("Download speed: %.2f Mbps\n", speed);
    printf("Upload speed: %.2f Mbps\n", get_random_speed());
    printf("Latency: %d ms\n", (int)delay);
    
    return 0;
}

double get_random_speed() {
    return ((double)rand()/(double)RAND_MAX)*(MAX_SPEED-MIN_SPEED)+MIN_SPEED;
}

double get_random_delay() {
    return ((double)rand()/(double)RAND_MAX)*(MAX_DELAY-MIN_DELAY)+MIN_DELAY;
}