//FormAI DATASET v1.0 Category: Movie Rating System ; Style: introspective
#include <stdio.h>

int main()
{
   int rating;
   
   printf("Welcome to the Unique C Movie Rating System!\n");
   printf("Please enter your rating from 1 to 10:\n");
   scanf("%d", &rating);
   
   if(rating < 1 || rating > 10)
   {
      printf("Invalid rating. Please enter a rating from 1 to 10.\n"); 
      scanf("%d", &rating);
   }
   
   switch(rating)
   {
      case 1:
         printf("Uh oh, this movie must have been pretty bad.\n");
         break;
      case 2:
         printf("Yikes, this movie wasn't very good.\n");
         break;
      case 3:
         printf("Not the best movie, but it had some redeeming qualities.\n");
         break;
      case 4:
         printf("This movie was okay, but nothing special.\n");
         break;
      case 5:
         printf("This movie was decent, definitely worth watching.\n");
         break;
      case 6:
         printf("A solid movie, definitely recommend it.\n");
         break;
      case 7:
         printf("A great movie, definitely worth watching again.\n");
         break;
      case 8:
         printf("This movie was amazing, definitely one of the best.\n");
         break;
      case 9:
         printf("Absolutely incredible, a must-see movie.\n");
         break;
      case 10:
         printf("A masterpiece, one of the greatest movies of all time.\n");
         break;
   }
   
   return 0;
}