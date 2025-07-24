//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int num, i;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    if(num < 1) {
        printf("Invalid input! Please enter a positive integer.\n");
        exit(0);
    }
    int fib[num];
    fib[0] = 0; fib[1] = 1;

    // Display the Fibonacci sequence in a stylish way
    printf("The Fibonacci sequence for the first %d terms is:\n", num);
    printf("%d %s", fib[0], "|");
    for(i=1; i<num; i++) {
        printf("%d ", fib[i]);
        usleep(60000);
        printf("%s", "|");
    }

    // Generate the next Fibonacci number and display it
    int next;
    for(i=2; i<num; i++) {
        next = fib[i-1] + fib[i-2];
        fib[i] = next;
        usleep(60000);
        printf("\n%d %s", next, "|");
    }
    printf("\n");
    return 0;
}