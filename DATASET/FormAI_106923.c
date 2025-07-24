//FormAI DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a = 10, b = 5;
    printf("Integer Values:\n a = %d \t b = %d\n",a,b);
    //Bitwise AND Operation
    int res_and = a&b;
    printf("Bitwise AND Result:\n %d & %d = %d\n",a,b,res_and);
    //Bitwise OR Operation
    int res_or = a|b;
    printf("Bitwise OR Result:\n %d | %d = %d\n",a,b,res_or);
    //Bitwise XOR Operation
    int res_xor = a^b;
    printf("Bitwise XOR Result:\n %d ^ %d = %d\n",a,b,res_xor);
    //Bitwise Complement Operation
    int res_comp_a = ~a;
    printf("Bitwise Complement of A Result:\n ~%d = %d\n",a,res_comp_a);
    int res_comp_b = ~b;
    printf("Bitwise Complement of B Result:\n ~%d = %d\n",b,res_comp_b);
    //Bitwise Left Shift Operation
    int res_leftshift = a<<1;
    printf("Left Shift Operation Result:\n %d << 1 = %d\n",a,res_leftshift);
    //Bitwise Right Shift Operation
    int res_rightshift = b>>1;
    printf("Right Shift Operation Result:\n %d >> 1 = %d\n",b,res_rightshift);
    return 0;
}