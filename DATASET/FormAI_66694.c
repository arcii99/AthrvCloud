//FormAI DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include<stdio.h>

/* Bitwise Operations Example Program */

int main(){
    unsigned int a = 1199, b = 672;
    printf("a =  %0110d\n", a);
    printf("b =  %0110d\n", b);
    
    // Bitwise Operations
    printf("\nBitwise Operations:\n");
    printf("& (AND): %0110d\n", a&b);
    printf("| (OR):  %0110d\n", a|b);
    printf("^ (XOR): %0110d\n", a^b);
    printf("~ (NOT): %0110d %0110d\n", ~a, ~b);
    printf("<< (LEFT SHIFT): %0110d\n", a<<2);
    printf(">> (RIGHT SHIFT): %0110d\n", b>>2);
    
    // Bitwise AND Operation to Determine Odd/Even
    printf("\nBitwise AND to Determine Odd/Even:\n");
    for(int i=1; i<=10; i++){
        if(i&1){
            printf("%d is odd\n", i);
        }else{
            printf("%d is even\n", i);
        }
    }
    
    // Bitwise Left Shift to Multiply by 2
    printf("\nBitwise Left Shift to Multiply by 2:\n");
    unsigned int num = 27;
    printf("num = %d\n", num);
    num = num<<1;
    printf("num<<1 = %d\n", num);
    
    // Bitwise Right Shift to Divide by 2
    printf("\nBitwise Right Shift to Divide by 2:\n");
    num = 54;
    printf("num = %d\n", num);
    num = num>>1;
    printf("num>>1 = %d\n", num);
    
    return 0;
}