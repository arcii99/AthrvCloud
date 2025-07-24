//FormAI DATASET v1.0 Category: Arithmetic ; Style: excited
#include<stdio.h>
int main()
{
    int num1, num2, ans;         
    printf("Are you ready for some exciting maths?\n");
    printf("Enter the first number: ");
    scanf("%d",&num1);              
    printf("\nEnter the second number: ");
    scanf("%d",&num2);             
    ans = num1 + num2;           
    printf("\nWoo-hoo! The sum of %d and %d is: %d", num1, num2, ans); 
    ans = num1 - num2;           
    printf("\nOh yeah! The difference between %d and %d is: %d", num1, num2, ans);
    ans = num1 * num2;          
    printf("\nIncredible! The product of %d and %d is: %d", num1, num2, ans);
    ans = num1 / num2;           
    printf("\nFantastic! The quotient of %d and %d is: %d", num1, num2, ans);
    printf("\nBut wait, there's more!\n");
    ans = num1 % num2;           
    printf("The remainder when %d is divided by %d is: %d", num1, num2, ans);
    ans = ++num1;               
    printf("\nGet ready, coz %d + 1 = %d",num1, ans);
    ans = --num2;               
    printf("\nAnd %d - 1 = %d! Can't stop now, let's multiply %d and %d to get %d",num2, ans, num1, num2, num1*num2);
    ans = num1++;                
    printf("\nOh yeah! The post-increment of %d is: %d",num1-1, ans);
    ans = num2--;                
    printf("\nThe post-decrement of %d is: %d",num2+1, ans);
    printf("\nIt's time for more action...\nEnter two new numbers: ");
    scanf("%d %d",&num1, &num2); 
    ans = (num1 * num1) - (num2 * num2);          
    printf("\nThe difference between the square of %d and %d is: %d", num1, num2, ans);
    ans = (num1 * num1) + (num2 * num2);          
    printf("\nAnd the sum of squares of %d and %d is: %d\n", num1, num2, ans);
    return 0;
}