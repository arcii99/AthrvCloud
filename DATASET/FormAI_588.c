//FormAI DATASET v1.0 Category: Movie Rating System ; Style: minimalist
#include <stdio.h>

int main() {
  int rating;

  printf("Welcome to the Unique C Movie Rating System!\n");
  printf("Please rate the movie you just watched from 1-10:\n");
  scanf("%d", &rating);

  if (rating >= 1 && rating <= 10) {
    printf("Your rating for the movie is %d out of 10!\n", rating);
  } else {
    printf("Invalid rating! Please rate the movie from 1-10.\n");
  }

  return 0;
}