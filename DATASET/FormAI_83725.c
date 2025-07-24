//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Alan Touring
// This program calculates the sum of all even numbers between 1 and n

#include <stdio.h>

int main() {
    
    printf("Enter value of n: ");
    int n;
    scanf("%d", &n);
    
    int sum = 0;
    for (int i = 2; i <= n; i += 2) {
        sum += i;
    }
    
    printf("Sum of all even numbers between 1 and %d is: %d\n", n, sum);
    
    return 0;
    
}