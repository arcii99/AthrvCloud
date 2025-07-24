//FormAI DATASET v1.0 Category: Arithmetic ; Style: Alan Touring
#include <stdio.h>

int main() {
    int a, b, c, d, result;
    
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // Perform arithmetic operations
    result = ((a + b) * c) / d;
    
    // Print result
    printf("(%d + %d) * %d / %d = %d", a, b, c, d, result);
    
    return 0;
}