//FormAI DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>

int main() {
  float rating;
  
  printf("Welcome to the C Movie Rating System!\n");
  printf("Please rate the movie on a scale of 0-10:\n");
  scanf("%f", &rating);
  
  if (rating > 10 || rating < 0) {
    printf("Invalid rating. Please rate the movie on a scale of 0-10:\n");
    scanf("%f", &rating);
  }
  
  if (rating < 5) {
    printf("Your rating was %.1f, which means this movie was not very good.\n", rating);
  }
  else if (rating < 8) {
    printf("Your rating was %.1f, which means this was a decent movie.\n", rating);
  }
  else {
    printf("Your rating was %.1f, which means this was an excellent movie!\n", rating);
  }
  
  printf("Thank you for using the C Movie Rating System. Goodbye!\n");
  
  return 0;
}