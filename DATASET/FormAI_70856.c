//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>

int main(void) {
  int rating;
  
  printf("Welcome to the C Movie Rating System!\n");

  // Ask for user's rating
  printf("Please rate the movie on a scale of 1-10: ");
  scanf("%d", &rating);

  // Evaluate user's rating and display appropriate message
  if (rating < 5) {
    printf("You did not enjoy the movie.\n");
  } else if (rating < 8) {
    printf("You thought the movie was average.\n");
  } else {
    printf("You really enjoyed the movie!\n");
  }

  // Thank user for using the rating system
  printf("Thank you for using the C Movie Rating System. Goodbye!\n");

  return 0;
}