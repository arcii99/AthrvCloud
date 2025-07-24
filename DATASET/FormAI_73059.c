//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int i;
   srand(time(0)); //seed for random number generator
   
   char* fortunes[6] = {"You will have a successful day.", "Expect a surprise soon.", "You will travel abroad in the near future.", "A new opportunity is coming your way.", "Good news is on the horizon.", "Your hard work will soon be rewarded."};
   
   printf("Welcome to the Automated Fortune Teller!\n");
   
   for(i=0; i<3; i++)
   {
      printf("\nPlease enter a number from 1-6: ");
      int num;
      scanf("%d", &num);
      
      if(num < 1 || num > 6)
      {
         printf("\nInvalid input, please try again.\n");
         continue;
      }
      
      printf("\nYour fortune is: %s\n", fortunes[num-1]);
   }
   
   printf("\nThank you for using the Automated Fortune Teller. Have a great day!\n");
   
   return 0;
}