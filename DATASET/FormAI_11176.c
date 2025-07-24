//FormAI DATASET v1.0 Category: Movie Rating System ; Style: satisfied
#include <stdio.h>

int main() {
   int movie_rating;
   printf("Welcome to our unique Movie Rating System!\n");
   printf("Please rate the movie you have just watched from 1 (worst) to 10 (best):\n");
   
   // Ask for user input
   scanf("%d", &movie_rating);
   
   // Check if user input is valid
   if (movie_rating < 1 || movie_rating > 10) {
      printf("Invalid rating! Please enter a rating from 1 to 10.\n");
   } else {
      // Display the corresponding message based on the rating
      switch (movie_rating) {
         case 1:
            printf("That was a terrible movie.");
            break;
         case 2:
            printf("That movie was not good at all.");
            break;
         case 3:
            printf("That movie was okay, but not great.");
            break;
         case 4:
            printf("That movie was decent.");
            break;
         case 5:
            printf("That movie was pretty good.");
            break;
         case 6:
            printf("That movie was really good!");
            break;
         case 7:
            printf("That movie was fantastic!");
            break;
         case 8:
            printf("That movie was amazing!");
            break;
         case 9:
            printf("That was one of the best movies I've ever seen!");
            break;
         case 10:
            printf("That was the best movie I've ever seen!");
            break;
         default:
            printf("Invalid rating! Please enter a rating from 1 to 10.\n");
            break;
      }
   }
   return 0;
}