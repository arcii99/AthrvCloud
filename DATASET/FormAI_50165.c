//FormAI DATASET v1.0 Category: System boot optimizer ; Style: recursive
#include <stdio.h>

// Function to optimize the system boot process
void optimizeBoot(int count) {
    if(count == 0) {
        printf("System boot optimized successfully!\n");
        return;
    }
    printf("%d...\n", count);

    // Perform optimization tasks here
    printf("Task %d complete\n", count);

    optimizeBoot(count-1);
}

int main() {
    int count = 10;

    printf("Optimizing system boot process...\n");
    optimizeBoot(count);

    return 0;
}