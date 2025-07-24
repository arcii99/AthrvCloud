//FormAI DATASET v1.0 Category: System boot optimizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int boot_time, optimized_time;
    double optimization_factor;
    
    printf("Enter the time it currently takes for the system to boot up (in seconds):");
    scanf("%d", &boot_time);
    
    srand(time(NULL));
    optimization_factor = (double)(rand() % 50) / 100.0 + 0.5;
    
    optimized_time = (int)(boot_time * optimization_factor);
    
    printf("\nSystem Optimization Factors:\n");
    printf("Random factor generated: %.2f\n", optimization_factor);
    printf("Optimized boot time: %d seconds\n", optimized_time);
    
    return 0;
}