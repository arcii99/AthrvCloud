//FormAI DATASET v1.0 Category: Bitwise operations ; Style: curious
#include<stdio.h>

int main(){
    int a,b;
    printf("Enter two numbers:\n");
    scanf("%d %d",&a,&b);

    printf("Bitwise AND: %d\n",a&b);
    printf("Bitwise OR: %d\n",a|b);
    printf("Bitwise XOR: %d\n",a^b);

    printf("Bitwise Complement of %d: %d\n",a,~a);
    printf("Bitwise Complement of %d: %d\n",b,~b);

    printf("%d left shift by 2 bits: %d\n",a,a<<2);
    printf("%d right shift by 2 bits: %d\n",a,a>>2);

    printf("Checking if %d is even: %d\n",a,a&1);
    printf("Checking if %d is even: %d\n",b,b&1);

    printf("Setting the %dth bit in %d to 1: %d\n",3,a,a|(1<<3));
    printf("Setting the %dth bit in %d to 0: %d\n",1,b,b&~(1<<1));

    printf("Toggling the %dth bit in %d: %d\n",2,a,a^(1<<2));
    printf("Toggling the %dth bit in %d: %d\n",4,b,b^(1<<4));

    return 0;
}