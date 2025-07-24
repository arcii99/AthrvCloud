//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int num) {
    if (num == 0) {
        return 0;
    } else if (num == 1) {
        return 1;
    } else {
        return (fibonacci(num - 1) + fibonacci(num - 2));
    }
}

void print_fibonacci(int num) {
    int i;
    printf("\n\n\t\t\tHAPPY VALENTINE'S DAY MY LOVE!\n\n");

    for (i = 0; i < num; i++) {
        if (i == 0) printf("\t\t\t     %d", fibonacci(i));
        else if (i % 2 == 0) printf(" \t\t%d", fibonacci(i));
        else if (i % 2 == 1) printf(" %d\n", fibonacci(i));
    }
}

int main() {
    int num;

    printf("\n\n\t\t\tHAPPY VALENTINE'S DAY MY LOVE!\n\n");
    printf("Enter the number of Fibonacci terms to be printed: ");
    scanf("%d", &num);

    print_fibonacci(num);

    return 0;
}