//FormAI DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
   double number=0;
   double result=0;
   double rand_num=0;
   int count=0;
   
   srand(time(0)); //set seed for rand function using current time
   
   printf("Enter any number:");
   scanf("%lf",&number);
   
   if(number<0){
       printf("ERROR: Please enter a positive number!\n");
       return 0;
   }
   
   result=sqrt(number); //find square root of the number
   printf("Square root of %lf is %lf \n", number, result);
   
   result=log(number); //find natural logarithmic value of the number
   printf("Natural logarithmic value of %lf is %lf \n", number, result);
   
   printf("Random numbers between %d and %d are: \n", (int)number+1, (int)number*10);
   for(count=0;count<5;count++){ //generate 5 random numbers within the range
       rand_num=((double)rand()/(double)RAND_MAX)*((int)number*10-(int)number+1)+(int)number;
       printf("%.2lf\n",rand_num);
   }
   
   result=pow(number,2); //find the square of the number
   printf("Square of %lf is %lf \n", number, result);
   
   result=pow(number,3); //find the cube of the number
   printf("Cube of %lf is %lf \n", number, result);

   return 0;
}