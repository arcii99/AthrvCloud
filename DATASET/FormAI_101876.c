//FormAI DATASET v1.0 Category: Movie Rating System ; Style: lively
#include <stdio.h>

int main() {
   int rating;
   
   printf("Welcome to the unique C Movie Rating System!\n");
   printf("Please rate the movie you just watched on a scale of 1 to 10.\n");
   
   scanf("%d", &rating);
   
   if (rating >= 1 && rating <= 3) {
      printf("Wow, that was terrible! We give it a 1 out of 10.\n");
   } else if (rating >= 4 && rating <= 6) {
      printf("Eh, it was alright. We give it a 5 out of 10.\n");
   } else if (rating >= 7 && rating <= 9) {
      printf("Nice! We really enjoyed it. We give it a 8 out of 10.\n");
   } else if (rating == 10) {
      printf("Perfection! We give it a 10 out of 10.\n");
   } else {
      printf("Invalid rating. Please rate the movie on a scale of 1 to 10.\n");
   }
   
   return 0;
}