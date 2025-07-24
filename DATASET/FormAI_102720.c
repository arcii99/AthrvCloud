//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: beginner-friendly
#include <stdio.h>

int fibonacci_recursive(int n){
    if (n <= 1){
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_iterative(int n){
    int a = 0, b = 1, i, temp;
    if (n == 0){
        return a;
    }
    for (i = 2; i <= n; i++){
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main(){
    int num, choice, fib;
    printf("Enter a number to calculate the corresponding fibonacci number: ");
    scanf("%d", &num);
    printf("\n");
    printf("Choose an option:\n");
    printf("1. Recursive\n");
    printf("2. Iterative\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            fib = fibonacci_recursive(num);
            printf("The %dth fibonacci number is: %d\n", num, fib);
            break;
        case 2:
            fib = fibonacci_iterative(num);
            printf("The %dth fibonacci number is: %d\n", num, fib);
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}