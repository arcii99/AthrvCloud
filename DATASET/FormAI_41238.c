//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int current_cpu_usage;
    time_t current_time;
    
    srand(time(NULL));
    
    while(1) {
        current_cpu_usage = rand() % 101; // Generate random integer from 0 to 100 
        current_time = time(NULL); // Set current time
        
        // Print CPU usage with a medieval flair!
        printf("CPU usage at %s: %d percent. 'Tis a strong and sturdy machine!", ctime(&current_time), current_cpu_usage);
        
        sleep(3); // Wait for a few seconds before iterating again
    }
    
    return 0;
}