//FormAI DATASET v1.0 Category: Bitwise operations ; Style: active
#include<stdio.h>

// This program demonstrates the use of bitwise operators to perform various operations on binary numbers.

int main(){

    int a=10,b=5;
    int bitwise_and=a&b;     //performing bitwise AND operation
    int bitwise_or=a|b;      //performing bitwise OR operation
    int bitwise_xor=a^b;     //performing bitwise XOR operation
    int bitwise_not=~a;      //performing bitwise Complement operation

    printf("The Binary representation of %d is %d%d%d%d\n",a,(a>>3)&1,(a>>2)&1,(a>>1)&1,a&1);
    printf("The Binary representation of %d is %d%d%d%d\n",b,(b>>3)&1,(b>>2)&1,(b>>1)&1,b&1);
    printf("\nResults of the Bitwise operations:\n");

    printf("%d & %d = %d\n",a,b,bitwise_and);
    printf("%d | %d = %d\n",a,b,bitwise_or);
    printf("%d ^ %d = %d\n",a,b,bitwise_xor);
    printf("~%d = %d\n\n",a,bitwise_not);

    printf("To check if a number is even or odd using Bitwise AND:\n");
    int num1=12,num2=7;
    printf("The Binary representation of %d is %d%d%d%d\n",num1,(num1>>3)&1,(num1>>2)&1,(num1>>1)&1,num1&1);
    printf("The Binary representation of %d is %d%d%d%d\n",num2,(num2>>3)&1,(num2>>2)&1,(num2>>1)&1,num2&1);

    if(num1&1==0)
        printf("%d is Even.\n",num1);
    else
        printf("%d is Odd.\n",num1);

    if(num2&1==0)
        printf("%d is Even.\n",num2);
    else
        printf("%d is Odd.\n",num2);

    printf("\nTo toggle the bits in a number:\n");
    int num3=8;
    printf("The Binary representation of %d is %d%d%d%d\n",num3,(num3>>3)&1,(num3>>2)&1,(num3>>1)&1,num3&1);
    int toggled=num3^15;    // 15 is represented in Binary as 1111. So, every bit of the number will be toggled when XORed with 15.
    printf("After toggling all bits in %d, we get %d which has Binary representation %d%d%d%d\n",num3,toggled,(toggled>>3)&1,(toggled>>2)&1,(toggled>>1)&1,toggled&1);

    printf("\nChecking for power of two:\n");
    int num4=64;    
    printf("The Binary representation of %d is %d%d%d%d%d%d%d\n",num4,(num4>>7)&1,(num4>>6)&1,(num4>>5)&1,(num4>>4)&1,
                (num4>>3)&1,(num4>>2)&1,(num4>>1)&1,num4&1);
    if(num4&(num4-1))        // If num4 is a power of two, bitwise AND of num4 and (num4-1) will be zero.
        printf("%d is not a power of two.\n",num4);
    else
        printf("%d is a power of two.\n",num4);

    return 0;
}