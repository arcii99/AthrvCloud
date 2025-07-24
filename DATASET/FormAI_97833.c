//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main() {
   char name[20];
   int rating;
   printf("Enter the name of the movie: ");
   scanf("%s", &name);
   printf("Enter the rating (out of 5): ");
   scanf("%d", &rating);

   if (rating > 5 || rating < 0) {
       printf("Error: rating can only be between 0 and 5");
       return 0;
   }

   printf("The movie \"%s\" has been rated %d out of 5\n", name, rating);

   if (rating >= 4 && rating <= 5) {
       printf("This is an excellent movie!");
   } else if (rating >= 2 && rating < 4) {
       printf("This movie is alright, not the best but not the worst either");
   } else {
       printf("This movie is not worth watching, avoid it");
   }

   return 0;
}