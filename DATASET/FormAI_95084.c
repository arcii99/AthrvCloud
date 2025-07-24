//FormAI DATASET v1.0 Category: Bitwise operations ; Style: scalable
#include <stdio.h>

int main() {
    int a,b;
    printf("Enter two integers: ");
    scanf("%d%d",&a,&b);
    
    printf("\nBitwise AND Operation (&):\n");
    printf("a & b = %d\n", a & b);
    
    printf("\nBitwise OR Operation (|):\n");
    printf("a | b = %d\n", a | b);
    
    printf("\nBitwise XOR Operation (^):\n");
    printf("a ^ b = %d\n", a ^ b);
    
    printf("\nBitwise NOT Operation (~):\n");
    printf("~a = %d, ~b = %d\n", ~a, ~b);
    
    printf("\nLeft Shift Operation (<<):\n");
    printf("a << 1 = %d, b << 2 = %d\n", a << 1, b << 2);
    
    printf("\nRight Shift Operation (>>):\n");
    printf("a >> 1 = %d, b >> 2 = %d\n", a >> 1, b >> 2);
    
    return 0;
}