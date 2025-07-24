//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: futuristic
#include <stdio.h>

int main() {
   // Initialization of variables
   int num1, num2, num3;
   int max, min, avg, diff;
   
   // Input three numbers from user
   printf("Enter three integer numbers: ");
   scanf("%d%d%d",&num1,&num2,&num3);
   
   // Finding the Maximum Number
   if(num1 > num2 && num1 > num3)
        max = num1;
    else if(num2 > num1 && num2 > num3)
        max = num2;
    else
        max = num3;
   
   // Finding the Minimum Number
   if(num1 < num2 && num1 < num3)
        min = num1;
    else if(num2 < num1 && num2 < num3)
        min = num2;
    else
        min = num3;
        
   // Finding the Average
    avg = (num1 + num2 + num3) / 3;
    
   // Finding the Difference between Maximum and Minimum
   diff = max - min;

   // Outputting the results
   printf("The Maximum Number is: %d\n",max);
   printf("The Minimum Number is: %d\n",min);
   printf("The Average is: %d\n",avg);
   printf("The Difference between Maximum and Minimum is: %d\n",diff);
   
   return 0;
}