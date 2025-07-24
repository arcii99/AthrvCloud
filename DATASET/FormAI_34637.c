//FormAI DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>

int main() {
   int rating;
   printf("Please rate the movie on a scale of 1-10: ");
   scanf("%d", &rating);

   switch (rating) {
      case 1:
      case 2:
         printf("This movie is a complete disaster. Avoid at all costs.\n");
         break;
      case 3:
      case 4:
         printf("This movie is below average. Not worth your time.\n");
         break;
      case 5:
      case 6:
         printf("This is an average movie. It may be worth watching, but don't expect too much.\n");
         break;
      case 7:
      case 8:
         printf("This movie is above average. You'll likely enjoy it.\n");
         break;
      case 9:
      case 10:
         printf("This is an outstanding movie. Don't miss it!\n");
         break;
      default:
         printf("Invalid rating. Please enter a number between 1 and 10.\n");
   }

   return 0;
}