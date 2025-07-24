//FormAI DATASET v1.0 Category: Movie Rating System ; Style: careful
#include <stdio.h>

int main() {
   int rating;
   printf("Welcome to the C Movie Rating System\n");

   /* Get user rating */
   printf("Please rate the movie on a scale of 1-10: ");
   scanf("%d", &rating);

   /* Determine the appropriate rating */
   if (rating >= 8) {
      printf("Excellent rating! This movie is highly recommended!\n");
   } else if (rating >= 6) {
      printf("Good rating. You would enjoy watching this movie!\n");
   } else if (rating >= 4) {
      printf("Average rating. The movie is watchable, but not outstanding.\n");
   } else if (rating >= 2) {
      printf("Poor rating. The movie is not worth watching.\n");
   } else {
      printf("Terrible rating. This movie is an absolute dud.\n");
   }
   
   return 0;
}