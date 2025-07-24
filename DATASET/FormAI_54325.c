//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <term>\n", argv[0]);
        return 1;
    }

    int term = atoi(argv[1]);

    if (term < 1) {
        printf("Error: Term must be greater than 0.\n");
        return 1;
    }

    long long fibo[term];
    int i;

    printf("Generating Fibonacci sequence of term %d...\n", term);

    fibo[0] = 0;
    fibo[1] = 1;

    for (i = 2; i < term; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    printf("Done.\n");

    printf("Printing Fibonacci sequence...\n");

    for (i = 0; i < term; i++) {
        printf("%lld\n", fibo[i]);
        usleep(50000);
    }

    printf("Done.\n");

    return 0;
}