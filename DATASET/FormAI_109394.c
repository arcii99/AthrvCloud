//FormAI DATASET v1.0 Category: Movie Rating System ; Style: random
#include <stdio.h>

struct movie {
   char title[50];
   int rating;
};

int main() {
 
   struct movie moviesDB[5];
   int i;

   printf("Welcome to the C Movie Rating System! Please enter the following details for your five favorite movies:\n");

   // Get user input for movie title and rating
   for (i = 0; i < 5; i++) {
      printf("\nMovie #%d:\n", i+1);
      printf("Title: ");
      fgets(moviesDB[i].title, 50, stdin);
      printf("Rating (1-10): ");
      scanf("%d", &moviesDB[i].rating);
      while (moviesDB[i].rating < 1 || moviesDB[i].rating > 10) { // Validate rating input
         printf("Invalid rating. Please enter a rating between 1-10: ");
         scanf("%d", &moviesDB[i].rating);
      }
      getchar(); // Clear input buffer before reading next movie title
   }

   printf("\nThank you for entering your movie ratings! Here are your top-rated movies:\n");
   int topRating = 0; // Initialize topRating variable 

   // Iterate through moviesDB to find highest rating and store in topRating
   for (i = 0; i < 5; i++) {
      if (moviesDB[i].rating > topRating) {
         topRating = moviesDB[i].rating;
      }
   }

   // Print out top-rated movies
   for (i = 0; i < 5; i++) {
      if (moviesDB[i].rating == topRating) {
         printf("%s", moviesDB[i].title);
      }
   }

   return 0;
}