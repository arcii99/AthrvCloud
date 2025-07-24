//FormAI DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include <stdio.h>

int main() {
   int rating;
 
   printf("Welcome to the movie rating system!\n");
 
   printf("Please rate the movie on a scale of 1-5 (5 being the best):\n");
   scanf("%d", &rating);
   
   if (rating == 5) {
      printf("You are my perfect 5 stars");
   } else if (rating >= 3 && rating <= 4) {
      printf("You are the love of my life, but this movie is just okay.\n");
   } else if (rating == 2) {
      printf("If you prefer this movie over me, then maybe we should take a break.\n");
   } else if (rating == 1) {
      printf("I'm sorry, but this relationship is not working out. Goodbye.\n");
   } else {
      printf("That's not a valid rating. Please try again with a number between 1-5.");
   }
 
   return 0;
}