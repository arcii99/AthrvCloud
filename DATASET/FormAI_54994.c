//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main()
{
   int state = RED;

   while(1)
   {
      switch (state)
      {
         case RED:
            printf("Red light on\n");
            sleep(5); // wait for 5 seconds
            state = GREEN;
            break;

         case GREEN:
            printf("Green light on\n");
            sleep(10); // wait for 10 seconds
            state = YELLOW;
            break;

         case YELLOW:
            printf("Yellow light on\n");
            sleep(2); // wait for 2 seconds
            state = RED;
            break;

         default:
            printf("Invalid state\n");
            exit(EXIT_FAILURE);
      }

      printf("\n");
   }

   return 0;
}