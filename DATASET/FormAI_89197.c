//FormAI DATASET v1.0 Category: Scientific ; Style: expert-level
#include<stdio.h>

int main()
{
   int num1, num2, num3;
   printf("Enter three numbers: ");
   scanf("%d %d %d", &num1, &num2, &num3);
   
   //largest number
   if(num1 > num2 && num1 > num3)
       printf("%d is the largest number.", num1);
   else if(num2 > num1 && num2 > num3)
       printf("%d is the largest number.", num2);
   else
       printf("%d is the largest number.", num3);
       
   //smallest number
   if(num1 < num2 && num1 < num3)
       printf("\n%d is the smallest number.", num1);
   else if(num2 < num1 && num2 < num3)
       printf("\n%d is the smallest number.", num2);
   else
       printf("\n%d is the smallest number.", num3);
       
   //mean
   float mean = (num1 + num2 + num3) / 3.0;
   printf("\nMean of the three numbers is %.2f.", mean);
   
   //standard deviation
   float deviation = sqrt((((num1-mean)*(num1-mean))+((num2-mean)*(num2-mean))+((num3-mean)*(num3-mean)))/3.0);
   printf("\nStandard deviation of the three numbers is %.2f.", deviation);
   
   return 0;
}