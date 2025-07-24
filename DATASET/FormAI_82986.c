//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printFibonacci(int n);

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printFibonacci(n);
    return 0;
}

void printFibonacci(int n) {
    int i, a = 0, b = 1, c;
    for(i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;

        printf("\033[;35m  ");

        for(int space=1; space<=20-a/2; space++){   // Artistic style design
            printf("*");
            }

        for(int star=1; star <= a/2; star++){
            printf("Fibonacci");
            }

        for(int space1=1; space1 <= 20-a/2; space1++){
            printf("*");
            }

        printf("  \033[0m\n");

        usleep(50000);   // 50 milliseconds delay
    }
}