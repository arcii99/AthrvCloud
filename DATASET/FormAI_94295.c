//FormAI DATASET v1.0 Category: Arithmetic ; Style: scientific
#include<stdio.h>

int main(){
    //Initializing integer variables
    int a = 4, b = 6, c = 10;

    //Performing addition of variables a and b
    int sum = a + b;
    printf("The sum of %d and %d is %d\n", a, b, sum);

    //Performing subtraction of variables a and b
    int difference = b - a;
    printf("The difference between %d and %d is %d\n", b, a, difference);

    //Performing multiplication of variables a and c
    int product = a * c;
    printf("The product of %d and %d is %d\n", a, c, product);

    //Performing division of variables c by a
    float quotient = (float)c / (float)a;
    printf("The quotient of %d and %d is %.2f\n", c, a, quotient);

    //Performing modulus of variables c by b
    int modulus = c % b;
    printf("The modulus of %d and %d is %d\n", c, b, modulus);

    //Performing exponential of variable b by a
    int exponential = 1;
    for(int i=1;i<=a;i++){
        exponential *= b;
    }
    printf("%d raised to the power of %d is %d\n", b, a, exponential);

    return 0;
}