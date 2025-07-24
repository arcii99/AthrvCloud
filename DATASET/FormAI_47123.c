//FormAI DATASET v1.0 Category: Bitwise operations ; Style: real-life
#include<stdio.h>
#include<stdlib.h>

int main(){
    unsigned char a=67, b=21, c;
    unsigned char mask1 = 0xF0; //11110000
    unsigned char mask2 = 0x0F; //00001111

    //Bitwise AND
    c = a & b;
    printf("%d & %d = %d\n", a, b, c);

    //Bitwise OR
    c = a | b;
    printf("%d | %d = %d\n", a, b, c);

    //Bitwise XOR
    c = a ^ b;
    printf("%d ^ %d = %d\n", a, b, c);

    //Bitwise NOT
    c = ~a;
    printf("~%d = %d\n", a, c);

    //Bitwise Left Shift
    c = a << 2;
    printf("%d << 2 = %d\n", a, c);

    //Bitwise Right Shift
    c = a >> 2;
    printf("%d >> 2 = %d\n", a, c);

    //Bitwise AND with mask
    c = a & mask1;
    printf("%d & %d = %d\n", a, mask1, c);

    //Bitwise OR with mask
    c = a | mask1;
    printf("%d | %d = %d\n", a, mask1, c);

    //Bitwise XOR with mask
    c = a ^ mask1;
    printf("%d ^ %d = %d\n", a, mask1, c);

    //Bitwise NOT with mask
    c = ~a;
    c = c & mask1;
    printf("~%d = %d\n", a, c);

    //Nibble swap
    c = (a & mask1) >> 4 | (a & mask2) << 4;
    printf("Nibble Swap of %d = %d\n", a, c);

    return 0;
}