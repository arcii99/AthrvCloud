//FormAI DATASET v1.0 Category: Movie Rating System ; Style: immersive
#include <stdio.h>

int main() {
   int rating;
   printf("Welcome To The Unique C Movie Rating System\n");
   printf("Please Rate The Movie You Have Recently Watched\n (Ratings should be between 1-10)\n");
   scanf("%d", &rating);

   if (rating < 1) {
      printf("Invalid rating. Please don't be too harsh on the movie.\n");
   }
   else if (rating >= 1 && rating <= 3) {
      printf("The movie was not so great, but not absolutely terrible. We would rate it 2 stars.\n");
   }
   else if (rating >= 4 && rating <= 6) {
      printf("The movie was okay, but not amazing. We would rate it 3 stars.\n");
   }
   else if (rating >= 7 && rating <= 8) {
      printf("The movie was good, but not excellent. We would rate it 4 stars.\n");
   }
   else if (rating == 9 || rating == 10) {
      printf("The movie was exceptional, and we would rate it 5 stars. You made a great choice!\n");
   }
   else {
      printf("Invalid rating. Please rate the movie between 1-10.\n");
   }

   return 0;
}