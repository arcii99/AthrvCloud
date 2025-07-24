//FormAI DATASET v1.0 Category: Recursive ; Style: thoughtful
#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int choice, num, result;
    
    do {
        printf("Which function would you like to use?\n");
        printf("1. Factorial\n");
        printf("2. Fibonacci\n");
        printf("3. Quit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                result = factorial(num);
                printf("Factorial of %d is %d\n", num, result);
                break;
            case 2:
                printf("Enter a number: ");
                scanf("%d", &num);
                result = fibonacci(num);
                printf("Fibonacci of %d is %d\n", num, result);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}