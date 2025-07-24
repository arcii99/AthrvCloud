//FormAI DATASET v1.0 Category: Arithmetic ; Style: light-weight
#include <stdio.h>

int main() {
    int a = 11;
    int b = 7;
    float c = 5.0;
    double d = 2.5;
    int e = 0;
    
    printf("Initial values:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %.1f\n", c);
    printf("d = %.1f\n", d);
    
    // Increment, Decrement and Assignment Operators
    a++;
    b--;
    c += 2.0;
    d -= 1.0;
    e = a + b;
    
    printf("\nAfter using Increment, Decrement and Assignment Operators:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %.1f\n", c);
    printf("d = %.1f\n", d);
    printf("e = %d\n", e);
    
    // Relational and Logical Operators
    if(a > b && c < d) {
        printf("\na is greater than b and c is less than d\n");
    } else {
        printf("\na is not greater than b or c is not less than d\n");
    }
    
    // Bitwise Operators
    int f = 5;
    int g = 9;
    int h = f | g;
    
    printf("\nAfter using Bitwise Operator:\n");
    printf("h = %d\n", h);
    
    // Conditional Operator
    int i = 2;
    int j = i % 2 == 0 ? 4 : 6;
    
    printf("\nAfter using Conditional Operator:\n");
    printf("j = %d\n", j);
    
    return 0;
}