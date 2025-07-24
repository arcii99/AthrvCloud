//FormAI DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>

int main() {
   int rating;
   printf("Please enter a rating between 1 and 10: ");
   scanf("%d", &rating);

   switch(rating) {
      case 1:
      case 2:
      case 3:
         printf("This movie is not recommended.\n");
         break;
      case 4:
      case 5:
         printf("This movie is okay.\n");
         break;
      case 6:
      case 7:
         printf("This movie is good.\n");
         break;
      case 8:
      case 9:
         printf("This movie is great!\n");
         break;
      case 10:
         printf("This movie is a masterpiece!\n");
         break;
      default:
         printf("Invalid rating entered.\n");
         break;
   }

   return 0;
}