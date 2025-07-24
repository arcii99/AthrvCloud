//FormAI DATASET v1.0 Category: Movie Rating System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
   int rating;
   printf("Welcome to the C Movie Rating System\n");
   printf("Please rate the movie from 1 to 10: ");
   scanf("%d", &rating); // get user input for rating
   printf("You rated the movie a %d\n", rating);

   if (rating >= 1 && rating <= 3) {
      printf("Terrible movie\n");
   } else if (rating >= 4 && rating <= 6) {
      printf("Average movie\n");
   } else if (rating >= 7 && rating <= 9) {
      printf("Great movie\n");
   } else if (rating == 10) {
      printf("Outstanding movie\n");
   } else {
      printf("Invalid rating\n");
   }

   return 0;
}