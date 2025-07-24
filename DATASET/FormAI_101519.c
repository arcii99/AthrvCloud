//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Puzzling function to calculate CPU usage
int calculateCPUUsage() {
    int result = 0;
    for (int i = 0; i < 1000000000; i++) {
        result += i*i;
    }
    return result;
}

int main() {
    int totalUsage = 0;
    int count = 0;
    while (1) {
        int currentUsage = calculateCPUUsage();
        int usageDiff = currentUsage - totalUsage;
        if (usageDiff > 0) {
            printf("CPU usage increased by: %d\n", usageDiff);
            totalUsage = currentUsage;
            count++;
        }

        if (count == 50) {
            printf("*********************************\n");
            printf("*   Congratulations! You have   *\n");
            printf("*  solved the CPU usage puzzle *\n");
            printf("*********************************\n");
            
            while (1) { // Loop to prevent program from exiting
            }
        }
        sleep(1);
    }
    return 0;
}