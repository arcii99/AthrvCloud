//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start_time, end_time;
    double cpu_time_used;
    
    while(1) {
        start_time = clock();
        
        // Code to monitor CPU usage goes here
        // This can be as simple or complex as desired
        
        end_time = clock();
        
        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        printf("CPU usage: %f\n", cpu_time_used);
        
        // Sleep for one second before checking CPU usage again
        sleep(1);
    }
    
    return 0;
}