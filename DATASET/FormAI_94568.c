//FormAI DATASET v1.0 Category: Recursive ; Style: futuristic
#include <stdio.h>

//This program is a futuristic example of a recursive function that calculates the Fibonacci sequence up to a certain number of terms specified by the user.

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int terms;
    printf("Welcome to the Fibonacci sequence calculator!\n");
    printf("Enter the number of terms you want to see: ");
    scanf("%d", &terms);
    printf("Here is the Fibonacci sequence up to %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\nThank you for using the Fibonacci sequence calculator!\n");
    return 0;
}