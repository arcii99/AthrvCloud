//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void delay(int seconds) {
    int milli_seconds = 1000 * seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) ;
}

int main() {
    srand(time(NULL)); // seed for random numbers
    int incoming_traffic = rand() % 100;
    int outgoing_traffic = rand() % 100;
    int priority_traffic = rand() % 10;
    int total_traffic = incoming_traffic + outgoing_traffic + priority_traffic;

    printf("Welcome to the Cyberpunk Network QoS monitor!\n");
    delay(2);
    printf("Incoming traffic: %d%%\n", incoming_traffic);
    delay(1);
    printf("Outgoing traffic: %d%%\n", outgoing_traffic);
    delay(1);
    printf("Priority traffic: %d%%\n", priority_traffic);
    delay(1);
    printf("Total traffic: %d%%\n", total_traffic);
    delay(1);
    
    if (total_traffic > 80) {
        printf("WARNING: Network congestion detected!\n");
        delay(1);
        printf("Initiating traffic control measures...\n");
        delay(2);
        printf("QoS priority set to maximum: %d%%\n", priority_traffic);
        delay(1);
        printf("Non-priority traffic may experience delays.\n");
        delay(1);
    } else {
        printf("Network traffic within acceptable limits.\n");
    }
    
    return 0;
}