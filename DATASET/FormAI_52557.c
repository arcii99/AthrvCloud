//FormAI DATASET v1.0 Category: Movie Rating System ; Style: retro
#include <stdio.h>

int main() {
   char movieTitle[50], rating;
   int userRating;

   printf("Enter the title of the movie: ");
   scanf("%s", movieTitle);

   printf("Enter your rating of the movie (A-F): ");
   scanf(" %c", &rating);

   switch(rating) {
      case 'A':
      case 'a':
         userRating = 90;
         break;
      case 'B':
      case 'b':
         userRating = 80;
         break;
      case 'C':
      case 'c':
         userRating = 70;
         break;
      case 'D':
      case 'd':
         userRating = 60;
         break;
      case 'F':
      case 'f':
         userRating = 50;
         break;
      default:
         userRating = -1;
         break;
   }

   if(userRating != -1) {
      printf("You rated the movie \"%s\" as a %c, which gives it a score of %d.\n", movieTitle, rating, userRating);
   } else {
      printf("Invalid rating.\n");
   }

   return 0;
}