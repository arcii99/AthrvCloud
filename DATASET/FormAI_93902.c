//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100000

// Function to simulate a memory intensive task
void memoryHog() {
    int* ptr;
    ptr = (int*) malloc(MAX * sizeof(int));
    for (int i = 0; i < MAX; i++) {
        ptr[i] = i;
    }
}

int main() {
    int memory = 0;
    
    // Continuously run a task to see increase in memory usage
    while (1) {
        // Call function to simulate memory intensive task
        memoryHog();
        
        // Calculate and display RAM usage in medieval style
        memory += MAX * sizeof(int);
        printf("Current RAM usage: %d bytes\n", memory);
        if (memory >= 1000000) {
            printf("Thou hath exceeded thy memory limit.\n");
            break;
        }
        
        // Delay before next task is run
        sleep(1);
    }
    
    return 0;
}