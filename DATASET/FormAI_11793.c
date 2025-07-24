//FormAI DATASET v1.0 Category: Recursive ; Style: retro
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    printf("Welcome to the Fibonacci retro program!\n");
    printf("Please enter a number to generate the Fibonacci sequence up to that number:\n");
    int num;
    scanf("%d", &num);
    printf("The Fibonacci sequence up to %d is:\n", num);
    for (int i = 0; i <= num; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\nThank you for using our program. Have a nice day!\n");
    return 0;
}