//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complex
#include <stdio.h>

int main() {
  int rating;
  printf("Welcome to the C Movie Rating System!\n");
  printf("Please rate the movie from 1 to 10:\n");
  scanf("%d", &rating);

  if (rating < 1 || rating > 10) {
    printf("Invalid rating! Please enter a number between 1 and 10.\n");
  } else {
    printf("Thank you for rating the movie!\n");
    printf("You gave it a rating of %d/10.\n", rating);
    if (rating <= 3) {
      printf("This movie was terrible!\n");
    } else if (rating <= 5) {
      printf("This movie was just okay.\n");
    } else if (rating <= 7) {
      printf("This movie was pretty good!\n");
    } else if (rating <= 9) {
      printf("This movie was great!\n");
    } else {
      printf("This movie was amazing!\n");
    }
  }

  return 0;
}