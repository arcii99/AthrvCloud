//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: genious
#include <stdio.h>

// function to print the fibonacci sequence
void printFibonacci(int num) {
    int a = 0, b = 1, c = 0;
    printf("%d, ", a);
    printf("%d, ", b);
    for(int i = 2; i < num; i++){
        c = a + b;
        printf("%d, ", c);
        a = b;
        b = c;     
    }
}

int main() {
    int num;
    printf("Please enter the number of terms you want to see in the Fibonacci sequence: ");
    scanf("%d", &num);
    printf("The first %d numbers in the Fibonacci sequence are: \n", num);

    // calling the function to print the sequence
    printFibonacci(num);
    return 0;
}