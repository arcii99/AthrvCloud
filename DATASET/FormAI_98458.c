//FormAI DATASET v1.0 Category: Syntax parsing ; Style: irregular
#include<stdio.h>
int main()
{
    int num1 , num2 , sum ;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    sum = num1 + num2 ;
    printf("The sum is: %d", sum);
    if(sum % 2 == 0 )
    {
      printf("\nSum is even.");
    }
    else
    {
      printf("\nSum is odd.");
    }
    while (num1>=0 && num2>=0 )
    {
    if (num1 % 2 == 0 && num2 % 2 == 0)
        {
        printf("\nThe numbers are even.");
        }
        else
        {
        printf("\nThe numbers are odd.");
        }
    break;
    }
    return 0;
}