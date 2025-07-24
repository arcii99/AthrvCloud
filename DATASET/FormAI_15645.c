//FormAI DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>

int main() {
   int rating;
   printf("Welcome to the C Movie Rating System.\n");
   printf("Please rate the movie from 1 to 10: ");
   scanf("%d", &rating);
   if (rating < 1) {
      printf("Invalid input. Rating must be between 1 and 10.");
   } else if (rating >= 1 && rating < 5) {
      printf("This movie needs serious improvements. Rating: %d / 10", rating);
   } else if (rating >= 5 && rating < 7) {
      printf("This is an average movie. Rating: %d / 10", rating);
   } else if (rating >= 7 && rating <= 8) {
      printf("This is a good movie. Rating: %d / 10", rating);
   } else if (rating > 8 && rating <= 9) {
      printf("This is an excellent movie! Rating: %d / 10", rating);
   } else if (rating > 9 && rating <= 10) {
      printf("This movie is a masterpiece! Rating: %d / 10", rating);
   } else {
      printf("Invalid input. Rating must be between 1 and 10.");
   }
   return 0;
}