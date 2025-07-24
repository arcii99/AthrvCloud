//FormAI DATASET v1.0 Category: Weather simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int temp, rain;
   srand(time(0));

   printf("\n\nWelcome to the Weather Simulation Program!\n\n");
   printf("Enter the current temperature in degrees Celsius: ");
   scanf("%d", &temp);

   if (temp <= 0)
   {
      printf("\nIt's freezing outside!\n");
      printf("Stay inside and keep warm!\n");
   }
   else if (temp < 15)
   {
      printf("\nIt's chilly outside.\n");
      printf("Don't forget to wear a jacket!\n");
   }
   else if (temp < 25)
   {
      printf("\nIt's pleasant outside.\n");
      printf("Enjoy the weather!\n");
   }
   else
   {
      printf("\nIt's hot outside!\n");
      printf("Stay hydrated and avoid too much direct sunlight!\n");
   }

   printf("\nEnter the chance of rain (in percentage): ");
   scanf("%d", &rain);

   if (rain >= 50)
   {
      printf("\nIt's going to rain today!\n");
      printf("Don't forget to bring an umbrella!\n");
   }
   else
   {
      printf("\nNo rain today, enjoy your day!\n");
   }

   return 0;
}