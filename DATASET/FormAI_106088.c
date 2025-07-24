//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed random number generator
    int cycle_count = 0;
    int green_time = 60; // duration of green light in seconds
    int yellow_time = 10; // duration of yellow light in seconds
    int red_time = 70; // duration of red light in seconds
    
    while (cycle_count < 10) { // perform 10 cycles
        int random_traffic = rand() % 100; // generate random traffic percentage
        int total_time = green_time + yellow_time + red_time; // calculate total time of one cycle
        int green_percent = (random_traffic <= 50) ? 50 : (100 - random_traffic); // decide green light percentage based on traffic
        int green_duration = (green_percent * total_time) / 100; // calculate green light duration
        int yellow_duration = yellow_time; // assign yellow light duration
        int red_duration = total_time - green_duration - yellow_duration; // calculate red light duration
        
        printf("Cycle %d:\n", cycle_count+1);
        printf("Traffic percentage: %d%%\n", random_traffic);
        printf("Green light duration: %d seconds\n", green_duration);
        printf("Yellow light duration: %d seconds\n", yellow_duration);
        printf("Red light duration: %d seconds\n\n", red_duration);
        
        cycle_count++; // increment cycle count
    }
    
    return 0;
}