//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clearScreen() {
    if (system("clear"))
        printf("Error clearing the screen.\n");
}

void displayFibonacci(int n) {
    int first = 0, second = 1, next;
    
    clearScreen();
    printf("\nFibonacci sequence for first %d terms is: \n\n", n);

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }

        printf("%d ", next);
        fflush(stdout);
        sleep(1);
    }
}

int main() {
    int n;

    printf("Enter the number of terms to display: ");
    scanf("%d", &n);

    displayFibonacci(n);

    printf("\n\n");
    return 0;
}