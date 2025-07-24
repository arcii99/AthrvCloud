//FormAI DATASET v1.0 Category: System boot optimizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC)
        ;
}

int main() {
    printf("Welcome to the C System boot optimizer!\n\n");
    printf("Scanning for errors...\n");
    delay(3);
    printf("No errors found!\n");
    printf("Optimizing boot process...\n");
    delay(5);
    printf("Boot process optimized!\n");
    printf("Cleaning up temporary files...\n");
    delay(2);
    printf("Temporary files cleaned up!\n");
    printf("Defragmenting hard drive...\n");
    delay(10);
    printf("Hard drive defragmented!\n");
    printf("Deleting unnecessary registry entries...\n");
    delay(5);
    printf("Registry entries deleted!\n");
    printf("\nAll optimizations complete!\n");
    return 0;
}