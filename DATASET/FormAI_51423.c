//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
  int rating;

  printf("Welcome to the C Movie Rating System!\n");
  printf("Please rate the movie you have just seen on a scale of 1 to 10.\n");
  scanf("%d", &rating);

  if (rating >= 1 && rating <= 10) {
    printf("Thank you for rating the movie.\n");

    if (rating >= 8) {
      printf("This is an excellent movie!\n");
    } else if (rating >= 6) {
      printf("This is a good movie.\n");
    } else {
      printf("This movie needs improvement.\n");
    }
  } else {
    printf("Invalid rating. Please rate the movie on a scale of 1 to 10.\n");
  }

  return 0;
}