//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   srand(time(NULL));
   int x = rand() % 10 + 1; //random location for x-coordinate
   int y = rand() % 10 + 1; //random location for y-coordinate
   
   printf("You are in a Cyberpunk world and your GPS system is online.\n");
   printf("Your current location is (%d, %d).\n", x, y);
   printf("Where would you like to go? Enter a destination coordinate (x,y): ");
   
   int dx, dy; //destination coordinates
   scanf("(%d,%d)", &dx, &dy);
   
   while (dx != x || dy != y) //keep searching until destination is reached
   {
      if (dx > x)
      {
         printf("Go right.\n");
         x++;
      }
      else if (dx < x)
      {
         printf("Go left.\n");
         x--;
      }
      if (dy > y)
      {
         printf("Go up.\n");
         y++;
      }
      else if (dy < y)
      {
         printf("Go down.\n");
         y--;
      }
   }
   printf("You have arrived at your destination at (%d,%d).\n", dx, dy);
   printf("Thank you for using Cyberpunk GPS!");
   return 0;
}