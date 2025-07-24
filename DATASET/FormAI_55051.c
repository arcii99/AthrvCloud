//FormAI DATASET v1.0 Category: Recursive ; Style: realistic
#include<stdio.h>

int fibonacci(int num) {
    if(num <= 1) {
        return num;
    }
    return fibonacci(num-1) + fibonacci(num-2);
}

int main() {
    int number;
    printf("Enter the number of terms: ");
    scanf("%d", &number);
    printf("Fibonacci series of %d terms:\n", number);
    for(int i=0; i<number; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}