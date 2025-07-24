//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int pushupCount = 0;
   int situpCount = 0;
   int squatCount = 0;
   int dayCount = 0;
   char response;

   printf("Welcome to the Fitness Tracker!\n");
   printf("Are you ready to get fit? (y/n)\n");
   scanf(" %c", &response);
   
   while(response == 'y'){
       dayCount++;
       printf("Day %d\n", dayCount);
       printf("=================\n");
       printf("Enter your pushup count: ");
       scanf("%d", &pushupCount);
       printf("Enter your situp count: ");
       scanf("%d", &situpCount);
       printf("Enter your squat count: ");
       scanf("%d", &squatCount);

       printf("=================\n");
       printf("Today's Results\n");
       printf("=================\n");
       printf("Pushups: %d\n", pushupCount);
       printf("Situps: %d\n", situpCount);
       printf("Squats: %d\n\n", squatCount);

       printf("Do you want to continue? (y/n): ");
       scanf(" %c", &response);

       if(response == 'n'){
           printf("Thanks for using Fitness Tracker!\n");
           printf("Good luck with your fitness journey!\n");
           break;
       }
   }

   return 0;
}