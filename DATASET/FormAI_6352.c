//FormAI DATASET v1.0 Category: Bitwise operations ; Style: post-apocalyptic
#include<stdio.h>

int main(){
    int a, b, c;
    printf("Welcome to the post-apocalyptic world!\n");
    printf("Please enter the values for integers A and B:\n");
    scanf("%d %d",&a,&b);
    
    //Bitwise OR operator
    c = a | b;
    printf("\nBitwise OR Result: %d (decimal)\n",c);
    
    //Bitwise AND operator
    c = a & b;
    printf("\nBitwise AND Result: %d (decimal)\n",c);
    
    //Bitwise XOR operator
    c = a ^ b;
    printf("\nBitwise XOR Result: %d (decimal)\n",c);
    
    //Bitwise complement operator
    c = ~a;
    printf("\nBitwise Complement Result of A: %d (decimal)\n",c);
    c = ~b;
    printf("\nBitwise Complement Result of B: %d (decimal)\n",c);
    
    //Bitwise shift left operator
    c = a << 2;
    printf("\nBitwise Shift Left Result of A: %d (decimal)\n",c);
    c = b << 2;
    printf("\nBitwise Shift Left Result of B: %d (decimal)\n",c);
    
    //Bitwise shift right operator
    c = a >> 2;
    printf("\nBitwise Shift Right Result of A: %d (decimal)\n",c);
    c = b >> 2;
    printf("\nBitwise Shift Right Result of B: %d (decimal)\n",c);
    
    printf("\nThanks for trying my program. Good luck out there!");
    return 0;
}