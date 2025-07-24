//FormAI DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>

// function to get the total rating from user
int getRating() {
   int rating;

   // loop until rating is valid
   do {
      printf("Enter rating (1-10): ");
      scanf("%d", &rating);
   } while (rating < 1 || rating > 10);

   return rating;
}

// function to display the movie rating
void displayRating(char* movieTitle, int totalRating, int numRatings) {
   printf("\nMovie Title: %s\n", movieTitle);
   printf("Total Rating: %d out of %d ratings\n", totalRating, numRatings);
   printf("Average Rating: %.2f\n\n", (float) totalRating / numRatings);
}

int main() {
   char* movieTitle;
   int totalRating = 0, numRatings = 0, rating;

   // get movie title from user
   printf("Enter movie title: ");
   scanf("%s", &movieTitle);

   // get ratings from user until user enters 0
   printf("\nEnter ratings (Enter 0 to quit):\n");
   do {
      rating = getRating();
      if (rating != 0) {
         totalRating += rating;
         numRatings++;
      }
   } while (rating != 0);

   // display the movie rating
   displayRating(movieTitle, totalRating, numRatings);

   return 0;
}