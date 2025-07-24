//FormAI DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>

int main() {
   int rating;

   printf("Welcome to the C Movie Rating System!\n");
   printf("Please rate the following movies on a scale of 1 to 5 stars:\n");

   printf("The Shawshank Redemption: ");
   scanf("%d", &rating);
   if (rating < 1 || rating > 5) {
      printf("Invalid rating entered. Please rate again: ");
      scanf("%d", &rating);
   }

   printf("The Godfather: ");
   scanf("%d", &rating);
   if (rating < 1 || rating > 5) {
      printf("Invalid rating entered. Please rate again: ");
      scanf("%d", &rating);
   }

   printf("The Dark Knight: ");
   scanf("%d", &rating);
   if (rating < 1 || rating > 5) {
      printf("Invalid rating entered. Please rate again: ");
      scanf("%d", &rating);
   }

   printf("Inception: ");
   scanf("%d", &rating);
   if (rating < 1 || rating > 5) {
      printf("Invalid rating entered. Please rate again: ");
      scanf("%d", &rating);
   }

   printf("Forrest Gump: ");
   scanf("%d", &rating);
   if (rating < 1 || rating > 5) {
      printf("Invalid rating entered. Please rate again: ");
      scanf("%d", &rating);
   }

   printf("\nThank you for rating the movies!\n");

   return 0;
}