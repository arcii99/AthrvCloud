//FormAI DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include <stdio.h>

int main() {
   int rating;
   char feedback[100];

   printf("Welcome to the Unique C Movie Rating System!\n");
   printf("Please enter your rating (1-10): ");
   scanf("%d", &rating);

   if (rating <= 5) {
      printf("Hmm, doesn't look like you enjoyed the movie. Please enter your feedback: ");
      scanf(" %[^\n]s", feedback);
      printf("Thank you for your feedback: %s\n", feedback);
   } else if (rating <= 8) {
      printf("Good to know you enjoyed the movie! Please enter your feedback: ");
      scanf(" %[^\n]s", feedback);
      printf("Thank you for your feedback: %s\n", feedback);
   } else if (rating == 9) {
      printf("Woah! Looks like you really loved the movie! Please enter your feedback: ");
      scanf(" %[^\n]s", feedback);
      printf("Thank you for the amazing feedback: %s\n", feedback);
   } else {
      printf("Oh my god! A perfect rating! Please enter your feedback: ");
      scanf(" %[^\n]s", feedback);
      printf("Thank you for the fantastic feedback: %s\n", feedback);
   }

   return 0;
}