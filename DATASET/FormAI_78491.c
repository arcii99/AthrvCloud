//FormAI DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>

int main() {
  int rating;

  printf("Welcome to the C Movie Rating System!");

  printf("\n\nPlease rate the movie from 1-5: ");
  scanf("%d", &rating);

  if(rating == 1) {
    printf("\n\nThe movie was terrible. I could barely watch it.");
  } else if(rating == 2) {
    printf("\n\nThe movie was bad, but it had some redeeming qualities.");
  } else if(rating == 3) {
    printf("\n\nThe movie was average. Nothing special, but it wasn't terrible either.");
  } else if(rating == 4) {
    printf("\n\nThe movie was good. I enjoyed it and would recommend it to others.");
  } else if(rating == 5) {
    printf("\n\nThe movie was amazing! It blew me away and exceeded my expectations.");
  } else {
    printf("\n\nInvalid rating. Please rate the movie from 1-5.");
  }

  return 0;
}