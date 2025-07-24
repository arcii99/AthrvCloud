//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multivariable
#include <stdio.h>

int main() {
    // Input variables
    int a, b, c, d;
    printf("Enter the values of a, b, c, and d: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // Bitwise operations
    int result1 = a & b;
    int result2 = c | d;
    int result3 = ~a;
    int result4 = b << 2;
    int result5 = c >> 1;
    int result6 = a ^ b;
    
    // Output results
    printf("a & b = %d\n", result1);
    printf("c | d = %d\n", result2);
    printf("~a = %d\n", result3);
    printf("b << 2 = %d\n", result4);
    printf("c >> 1 = %d\n", result5);
    printf("a ^ b = %d\n", result6);
    
    return 0;
}