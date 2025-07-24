//FormAI DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>

int main() 
{
    int num1, num2, num3;
    printf("Enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int sum = num1 + num2 + num3;
    int product = num1 * num2 * num3;

    if (num1 > num2 && num1 > num3) 
    {
        printf("%d is the largest number.\n", num1);
    } 
    else if (num2 > num1 && num2 > num3) 
    {
        printf("%d is the largest number.\n", num2);
    } 
    else 
    {
        printf("%d is the largest number.\n", num3);
    }

    if (num1 < num2 && num1 < num3) 
    {
        printf("%d is the smallest number.\n", num1);
    } 
    else if (num2 < num1 && num2 < num3) 
    {
        printf("%d is the smallest number.\n", num2);
    } 
    else 
    {
        printf("%d is the smallest number.\n", num3);
    }

    printf("The sum of the three numbers is: %d\n", sum);
    printf("The product of the three numbers is: %d\n", product);

    return 0;
}