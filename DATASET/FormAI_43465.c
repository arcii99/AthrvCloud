//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>

int main() {
   int rating;
   char movie[50];

   printf("Enter movie name: ");
   scanf("%s", &movie); // Get movie name from user

   printf("Rate the movie out of 10: ");
   scanf("%d", &rating); // Get rating from user

   if (rating >= 8 && rating <= 10) {
      printf("%s is an excellent movie! It deserves a rating of %d\n", movie, rating);
   } else if (rating >= 6 && rating <= 7) {
      printf("%s is a good movie. It deserves a rating of %d\n", movie, rating);
   } else if (rating >= 4 && rating <= 5) {
      printf("%s is an average movie. It deserves a rating of %d\n", movie, rating);
   } else {
      printf("%s is a below average movie. It deserves a rating of %d\n", movie, rating);
   }

   return 0;
}