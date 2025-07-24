//FormAI DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include <stdio.h>

int main() {
   float rating = 0;
   int num_ratings = 0;
   int total = 0;
   char response;

   printf("Welcome to the Peaceful Movie Rating System!\n");

   do {
      printf("Please rate the movie out of 10: ");
      scanf("%f", &rating);

      if(rating < 0 || rating > 10) {
         printf("Invalid rating. Please enter a rating between 0 and 10.\n");
         continue;
      }

      total += rating;
      num_ratings++;

      printf("Thank you for your rating!\n");

      printf("Would you like to enter another rating? (y/n): ");
      scanf(" %c", &response);

   } while(response == 'y');

   if(num_ratings > 0) {
      float average = (float)total / (float)num_ratings;
      printf("Number of ratings: %d\n", num_ratings);
      printf("Average rating: %.2f\n", average);
   } else {
      printf("No ratings have been entered.\n");
   }

   printf("Thank you for using the Peaceful Movie Rating System!\n");

   return 0;
}