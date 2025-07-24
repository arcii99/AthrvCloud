//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {

    float cpuUsage = 0.0f;
    int cycles = 0;

    while(1) {
        
        for(int i = 0; i < 10000000; i++) {
            cpuUsage += 0.01f; // Simulate CPU usage
        }

        printf("CPU usage: %.2f%%\n", cpuUsage);

        if(cycles % 10 == 0) {
            printf("Warning: High CPU usage detected!\n");
        }

        if(cpuUsage >= 90.0f) { // If CPU usage is over 90%
            printf("CRITICAL ALERT! System overload imminent!\n");
            printf("Please close unnecessary programs and applications\n");
            printf("Press any key to exit...\n");
            getchar();
            exit(1);
        }

        cycles++;
    }

    return 0;
}