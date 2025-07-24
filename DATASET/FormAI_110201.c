//FormAI DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>

int main() {
   int rating;
   
   printf("Welcome to the C Movie Rating System! \n");
   printf("Please rate the movie you just watched on a scale of 1 to 10: ");
   scanf("%d", &rating);
   
   if (rating <= 0 || rating >= 11) {
      printf("Invalid rating. Please enter a rating between 1-10. \n");
      return 0;
   } else if (rating <= 5) {
      printf("We're sorry you didn't enjoy the movie. We hope your day gets better! \n");
   } else if (rating <= 7) {
      printf("Glad to hear you liked the movie. Have a great day! \n");
   } else {
      printf("Wow, a perfect rating! We're thrilled you enjoyed the movie. Thanks for watching! \n");
   }
   
   return 0;
}