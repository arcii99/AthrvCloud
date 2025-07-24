//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FULL_BLOCK 0x2588

int main() {
    int num1 = 0;
    int num2 = 1;
    int limit = 20;
    printf("Enter the limit of sequence to be printed: ");
    scanf("%d", &limit);
    printf("Calculating Fibonacci sequence up to %d...\n", limit);
    sleep(1);
    system("clear");

    printf("   _______________\n");
    printf("  /               \\ \n");
    printf(" /  Fibonacci Bot  \\\n");
    printf("/_____       _____\\\n");
    printf("     /      \\ \n");
    printf("    /        \\ \n");
    printf("   /    __    \\ \n");
    printf("  /    /  \\    \\ \n");
    printf(" /____/____\\____\\ \n\n");

    for(int i=0; i<limit; i++) {
        printf("Calculating: ");
        for(int j=0; j<i; j++) {
            printf("%c", FULL_BLOCK);
        }
        printf("\r"); // Moving the cursor to the beginning of the line
        fflush(stdout); // Flushing the output buffer
        usleep(500000); // Pausing for 0.5 seconds

        int next = num1 + num2;
        num1 = num2;
        num2 = next;

        printf("%d\n", num1);
    }

    printf("\nFinished calculating Fibonacci sequence up to %d!\n", limit);

    return 0;
}