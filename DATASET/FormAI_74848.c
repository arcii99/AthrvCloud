//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, num1, num2, num3, num4, num5;

   srand(time(NULL)); //ensure that the random numbers are unique each time

   //print the user's fortune
   printf("\nWelcome to the Automatic Fortune Teller! Here is your fortune:\n");

   //generate five random numbers between 1 and 20 inclusive
   num1 = rand() % 20 + 1;
   num2 = rand() % 20 + 1;
   num3 = rand() % 20 + 1;
   num4 = rand() % 20 + 1;
   num5 = rand() % 20 + 1;

   //use the random numbers to generate the user's fortune
   if (num1 == num2 && num2 == num3 && num3 == num4 && num4 == num5) {
       printf("You will have an amazing and successful future. All your dreams will come true! Believe in it!\n");
   }
   else if (num1 == num2 || num2 == num3 || num3 == num4 || num4 == num5) {
       printf("Be cautious today. While fortune may smile upon you at times, there are hidden dangers as well.\n");
       if (num1 == num2 || num2 == num3) {
           printf("You will experience a significant change in your life in the near future. Embrace it.\n");
       }
       if (num3 == num4 || num4 == num5) {
           printf("You will face great success and triumph in the things you pursue. Be confident.\n");
       }
   }
   else {
       printf("Today you have good luck! Keep your eyes peeled for new opportunities and take risks if they present themselves.\n");

       if (num1 < 10 || num2 < 10 || num3 < 10 || num4 < 10 || num5 < 10) {
           printf("Your lucky number for today is %d. Be sure to make a note of it!\n", rand() % 10 + 1);
       }
   }
   return 0;
}