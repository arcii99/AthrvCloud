//FormAI DATASET v1.0 Category: Movie Rating System ; Style: mind-bending
#include <stdio.h>

int main() {
  int rating;
  printf("Welcome to the Mind-Bending C Movie Rating System!\n");
  printf("Please rate the movie: ");

  scanf("%d", &rating);
  printf("\n");

  if (rating <= 5) {
    printf("You rated the movie a %d.\n", rating);
    printf("This movie was clearly not mind-bending at all.\n");
    printf("We recommend you find another movie that suits your taste.\n");
  }
  else if (rating > 5 && rating <= 7) {
    printf("You rated the movie a %d.\n", rating);
    printf("This movie was somewhat mind-bending, but could have been better.\n");
    printf("We recommend you try another movie similar to this one.\n");
  }
  else if (rating > 7 && rating <= 9) {
    printf("You rated the movie a %d.\n", rating);
    printf("This movie was definitely mind-bending!\n");
    printf("We recommend you share this movie with all your friends.\n");
  }
  else if (rating == 10) {
    printf("You rated the movie a %d.\n", rating);
    printf("This movie was the most mind-bending experience you've ever had.\n");
    printf("We recommend you watch this movie over and over again.\n");
  }
  else {
    printf("Invalid rating. Please choose a number between 1 and 10.\n");
  }

  return 0;
}