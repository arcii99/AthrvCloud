//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: post-apocalyptic
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    printf("Welcome to the Fibonacci sequence visualizer!\n\n");
    printf("Enter the length of the sequence you would like to generate (up to 20): ");
    int n;
    scanf("%d", &n);

    if (n > 20 || n <= 0) {
        printf("\nInvalid input. Please enter a number between 1 and 20.\n");
        return 1;
    }

    printf("\nGenerating sequence...\n\n");

    // Code adapted from Parthiban Vijayaraghavan's code on Stack Overflow
    int seq[n];
    int i;
    for (i = 0; i < n; i++) {
        seq[i] = fibonacci(i);
    }

    // Output code inspired by post-apocalyptic aesthetic
    printf("--------------------\n");
    printf("| FIBONACCI SEQUENCE |\n");
    printf("--------------------\n\n");
    printf("    ___       ___       ___       ___\n");
    printf("   /   \\     /   \\     /   \\     /   \\\n");
    printf(" _|___|_   _|___|_   _|___|_   _|___|_\n");
    printf("|       | |       | |       | |       |\n");
    printf("|");
    for (i = 0; i < n; i++) {
        printf("  %4d  |", seq[i]);
    }
    printf("\n|_______| |_______| |_______| |_______|\n");

    return 0;
}