//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Romeo and Juliet
#include<stdio.h>
int main()
{
   int choice;
   float temp_f, temp_c;
   printf("Welcome, O worthy users Romeo and Juliet!\n");
   printf("What would you like to convert?\n");
   printf("1. Celsius to Fahrenheit\n");
   printf("2. Fahrenheit to Celsius\n");
   printf("Enter your choice: ");
   scanf("%d",&choice);

   switch(choice)
   {
      case 1:
         printf("Enter temperature in Celsius: ");
         scanf("%f",&temp_c);
         temp_f = (temp_c * 9/5) + 32;
         printf("Temperature in Fahrenheit: %.2f F\n",temp_f);
         break;

      case 2:
         printf("Enter temperature in Fahrenheit: ");
         scanf("%f",&temp_f);
         temp_c = (temp_f - 32) * 5/9;
         printf("Temperature in Celsius: %.2f C\n",temp_c);
         break;

      default:
         printf("Invalid Choice!\n");
   }
   return 0;
}