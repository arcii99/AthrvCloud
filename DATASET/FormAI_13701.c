//FormAI DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>

int main(){
    int a = 5, b = 6;
    int result;

    printf("The value of 'a' is %d.\n", a);
    printf("The value of 'b' is %d.\n", b);
    
    printf("Performing Bitwise AND operation...\n");
    result = a & b;
    printf("The result of a & b is %d.\n", result);

    printf("Performing Bitwise OR operation...\n");
    result = a | b;
    printf("The result of a | b is %d.\n", result);

    printf("Performing Bitwise XOR operation...\n");
    result = a ^ b;
    printf("The result of a ^ b is %d.\n", result);

    printf("Performing Bitwise One's Complement operation...\n");
    result = ~a;
    printf("The result of ~a is %d.\n", result);
    
    printf("Performing Bitwise Left Shift operation...\n");
    result = a << 2;
    printf("The result of a << 2 is %d.\n", result);

    printf("Performing Bitwise Right Shift operation...\n");
    result = b >> 2;
    printf("The result of b >> 2 is %d.\n", result);

    return 0;
}