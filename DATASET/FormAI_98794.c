//FormAI DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>

int main() {
   float rating;
   printf("Welcome to the Unique C Movie Rating System\n");
   printf("Please rate the movie on a scale of 1.0 to 10.0: ");
   scanf("%f", &rating);
   
   if (rating >= 9.0) {
      printf("Wow! You really loved the movie!\n");
   } else if (rating >= 7.5 && rating < 9.0) {
      printf("That's a good rating! Glad you enjoyed the movie.\n");
   } else if (rating >= 6.0 && rating < 7.5) {
      printf("Thanks for watching! Your rating is appreciated.\n");
   } else if (rating >= 4.0 && rating < 6.0) {
      printf("Sorry to hear you didn't enjoy the movie as much.\n");
   } else {
      printf("Yikes, that's not a good rating. We'll do better next time.\n");
   }

   printf("Thank you for rating the movie.\n");

   return 0;
}