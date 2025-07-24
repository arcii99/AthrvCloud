//FormAI DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>

int main() {
  float rating;
  printf("Welcome to the C Movie Rating System!\n");
  printf("Please rate the movie between 0 and 10: ");
  scanf("%f", &rating);

  if (rating < 0) {
    printf("Error: Rating cannot be less than 0.\n");
  } else if (rating >= 0 && rating < 4) {
    printf("This movie was terrible! Rating: %f\n", rating);
  } else if (rating >= 4 && rating < 6) {
    printf("This movie was below average. Rating: %f\n", rating);
  } else if (rating >= 6 && rating < 8) {
    printf("This movie was good. Rating: %f\n", rating);
  } else if (rating >= 8 && rating < 10) {
    printf("This movie was excellent! Rating: %f\n", rating);
  } else if (rating == 10) {
    printf("This movie was a masterpiece! Rating: %f\n", rating);
  } else {
    printf("Error: Rating cannot be more than 10.\n");
  }

  return 0;
}