//FormAI DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
  int rating;
  char movieTitle[50];
  printf("Welcome to the Unique C Movie Rating System!\n");
  printf("Please enter the title of the movie you want to rate: ");
  scanf("%[^\n]%*c", movieTitle);
  // %[^\n]%*c reads in a full line (up to newline) and discards the newline character
  printf("Please rate the movie from 1-10: ");
  scanf("%d", &rating);

  if (rating == 10) {
    printf("Wow, %s is a masterpiece! Perfect 10/10!\n", movieTitle);
  } else if (rating > 7 && rating < 10) {
    printf("%s is a great movie, definitely worth watching! %d/10\n", movieTitle, rating);
  } else if (rating > 5 && rating <= 7) {
    printf("%s is an alright movie, not too bad. %d/10\n", movieTitle, rating);
  } else if (rating > 0 && rating <= 5) {
    printf("%s is not a good movie, sorry to say. %d/10\n", movieTitle, rating);
  } else {
    printf("Invalid rating input, please try again.\n");
  }

  printf("Thank you for using the Unique C Movie Rating System!\n");

  return 0;
}