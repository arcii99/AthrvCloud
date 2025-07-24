//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include<stdio.h>

int main() {
    int a,b;
    printf("Enter the value of a:\n");
    scanf("%d",&a);
    
    printf("Enter the value of b:\n");
    scanf("%d",&b);

    printf("a&b = %d\n",a&b); // bitwise AND operation
    printf("a|b = %d\n",a|b); // bitwise OR operation
    printf("a^b = %d\n",a^b); // bitwise XOR operation
    printf("~a = %d\n",~a);   // bitwise NOT operation with a
    printf("~b = %d\n",~b);  // bitwise NOT operation with b
 
    printf("a<<2 = %d\n",a<<2); // left shift operator a by 2
    printf("b<<2 = %d\n",b<<2);  // left shift operator b by 2
    printf("a>>2 = %d\n",a>>2); // right shift operator a by 2
    printf("b>>2 = %d\n",b>>2); // right shift operator b by 2

    return 0;
}