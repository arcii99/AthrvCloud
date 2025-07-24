//FormAI DATASET v1.0 Category: Movie Rating System ; Style: scalable
#include <stdio.h>

int main() {
  int movieRating;
  
  printf("Welcome to the C Movie Rating System!\n");
  printf("Please rate the movie on a scale of 1 to 10: ");
  scanf("%d", &movieRating);
  
  if (movieRating < 1 || movieRating > 10) {
    printf("Invalid rating. Please rate the movie on a scale of 1 to 10:");
    scanf("%d", &movieRating);
  }
  
  if (movieRating >= 9) {
    printf("Great movie! We give it an A rating.\n");
  } else if (movieRating >= 7 && movieRating < 9) {
    printf("Good movie. We give it a B rating.\n");
  } else if (movieRating >= 5 && movieRating < 7) {
    printf("Okay movie. We give it a C rating.\n");
  } else {
    printf("Bad movie. We give it a D rating.\n");
  }
  
  return 0;
}