//FormAI DATASET v1.0 Category: System boot optimizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOT_TIME_MAX 30

int main() {
    // User input for boot time
    int bootTime;
    printf("Enter the estimated boot time in seconds: ");
    scanf("%d", &bootTime);
    
    // Ensure boot time is within reasonable range
    if (bootTime > BOOT_TIME_MAX) {
        printf("Estimated boot time exceeds maximum limit of %d seconds.\n", BOOT_TIME_MAX);
        exit(1);
    }
    
    // Boot optimization algorithm
    int optimizedBootTime = 0;
    int i, j, k;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 10; k++) {
                optimizedBootTime += (i * j + k);
            }
        }
    }
    
    // Output results and improvement percentage
    printf("Estimated boot time: %d seconds\n", bootTime);
    printf("Optimized boot time: %d seconds\n", optimizedBootTime);
    double improvementPercentage = ((double)(bootTime - optimizedBootTime) / (double)bootTime) * 100;
    printf("Improvement: %.2f%%\n", improvementPercentage);
    
    return 0;
}