//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include <stdio.h>
#include <unistd.h> // Required for sleep() function
#include <stdlib.h> // Required for rand() function

int main(){
    float cpu_usage; // Define a variable to store CPU usage
    int i; // Define a variable to use in loop
    printf("CPU Monitor:\n");

    for(i=0; i<10; i++){
        // Generate random CPU usage between 0 and 100
        cpu_usage = (float)rand()/(float)(RAND_MAX/100);
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        sleep(1); // Wait for 1 second
    }

    return 0;
}