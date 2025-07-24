//FormAI DATASET v1.0 Category: Bitwise operations ; Style: realistic
#include <stdio.h>

int main(){
    int a = 10; 
    int b = 22;
    int c;

    printf("Bitwise AND : %d\n", a&b );
    printf("Bitwise OR : %d\n", a|b );
    printf("Bitwise XOR : %d\n", a^b );
    printf("Bitwise Complement : %d\n", ~a );
    
    c = a << 2; 
    printf("Left Shift of a by 2 : %d\n", c );

    c = b >> 2; 
    printf("Right Shift of b by 2 : %d\n", c );

    printf("Size of int : %ld bytes\n", sizeof(int));
    return 0;
}