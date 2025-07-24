//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include<stdio.h>

int fibonacci_series(int num) {
    int result;
    if(num == 0 || num == 1) {
        result = num; // Base case.
        return result;
    }
    else {
        result = fibonacci_series(num-1) + fibonacci_series(num-2); // Recursive definition.
        return result;
    }
}

int main() {
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("\nFibonacci Series: ");
    for(i = 0; i < n; i++) {
        printf("%d ", fibonacci_series(i)); // Calling the recursive function.
    }
    printf("\n");
    return 0;
}