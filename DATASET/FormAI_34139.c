//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: light-weight
#include <stdio.h>

void fibonacci(int num);

int main() {
    int num; //to store the number of terms to be printed
    printf("Enter the number of terms you want to print: ");
    scanf("%d", &num);

    fibonacci(num); //function call
    return 0;
}

void fibonacci(int num) {
    int i, first = 0, second = 1, next;
    printf("%d %d ", first, second); //printing the first two terms

    for (i = 3; i <= num; i++) {
        next = first + second; //calculating the next term
        printf("%d ", next);
        first = second; //updating variables
        second = next;
    }
}