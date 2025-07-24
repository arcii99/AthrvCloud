//FormAI DATASET v1.0 Category: Recursive ; Style: thoughtful
#include<stdio.h>

int calculateGCD(int num1, int num2){
   if(num1 == 0) return num2;
   if(num2 == 0) return num1;

   if(num1 == num2) return num1;

   if(num1 > num2) return calculateGCD(num1 - num2, num2);
	
   return calculateGCD(num1, num2 - num1);
}

int main(){
    int num1, num2, gcd;

    printf("Enter first number: ");
    scanf("%d",&num1);

    printf("Enter second number: ");
    scanf("%d",&num2);

    gcd = calculateGCD(num1, num2);

    printf("GCD of %d and %d is %d", num1, num2, gcd);
    return 0;
}