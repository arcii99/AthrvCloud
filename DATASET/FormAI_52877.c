//FormAI DATASET v1.0 Category: Movie Rating System ; Style: genious
#include <stdio.h>

int main() {
  int rating;
  printf("Welcome to the Genius Movie Rating System!\n");
  printf("Please rate the movie on a scale of 1-10: ");
  scanf("%d", &rating);

  if (rating >= 9) {
    printf("Wow, that's a genius movie!\n");
  }
  else if (rating >= 7) {
    printf("It's a pretty good movie!\n");
  }
  else if (rating >= 5) {
    printf("It's an average movie.\n");
  }
  else if (rating >= 3) {
    printf("It's not so great.\n");
  }
  else {
    printf("That movie is awful.\n");
  }

  return 0;
}