//FormAI DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include<stdio.h>

int main(){

    int a,b;
    float c,d,sum,diff,prod,quo;
    
    printf("Enter two integers:\n");
    scanf("%d%d",&a,&b);

    sum = a+b;
    diff = a-b;
    prod = a*b;
    quo = (float)a/b;

    printf("Sum of %d and %d is: %f\n",a,b,sum);
    printf("Difference of %d and %d is: %f\n",a,b,diff);
    printf("Product of %d and %d is: %f\n",a,b,prod);
    printf("Quotient of %d and %d is: %f\n",a,b,quo);

    printf("\nEnter two floating point numbers:\n");
    scanf("%f%f",&c,&d);

    sum = c+d;
    diff = c-d;
    prod = c*d;
    quo = c/d;

    printf("Sum of %f and %f is: %f\n",c,d,sum);
    printf("Difference of %f and %f is: %f\n",c,d,diff);
    printf("Product of %f and %f is: %f\n",c,d,prod);
    printf("Quotient of %f and %f is: %f\n",c,d,quo);

    return 0;
}