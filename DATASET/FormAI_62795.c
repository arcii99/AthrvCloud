//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    printf("Welcome to the Happy C RAM Usage Monitor!\n");
    printf("This program will help you monitor your RAM usage in real-time!\n\n");

    int i = 0;
    int allocated_memory = 0;

    while(1) {
        printf("Iteration %d:\n", i);

        // Allocate some memory
        int* ptr = (int*) malloc(sizeof(int) * 1024);
        if (ptr == NULL) {
            printf("Error allocating memory!\n");
            return 1;
        }

        // Fill the allocated memory with some random values
        for (int j = 0; j < 1024; j++) {
            ptr[j] = rand() % 100;
        }

        // Display the current RAM usage
        allocated_memory += (sizeof(int) * 1024);
        printf("Current RAM usage: %d bytes\n", allocated_memory);

        // Free some memory after every 10 iterations
        if (i == 10) {
            printf("Freeing up some memory...\n");
            free(ptr);
            allocated_memory -= (sizeof(int) * 1024);
            printf("Current RAM usage after freeing memory: %d bytes\n", allocated_memory);
            i = 0;
        }

        // Wait for 1 second before the next iteration
        printf("\n");
        sleep(1);
        i++;
    }

    return 0;
}