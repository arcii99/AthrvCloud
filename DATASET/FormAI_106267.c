//FormAI DATASET v1.0 Category: Movie Rating System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int rating;

  printf("Welcome to the Mind-Bending Movie Rating System!\n\n");
  printf("Please rate the movie on a scale of 1 to 10.\n");
  scanf("%d", &rating);

  if (rating >= 1 && rating <= 3) {
    printf("You rated the movie a %d.\n", rating);
    printf("This movie is beyond comprehensible to your limited mind.\n");
    printf("Please try watching it again after transcending the boundaries of your current existence.\n");
  } else if (rating >= 4 && rating <= 6) {
    printf("You rated the movie a %d.\n", rating);
    printf("This movie is a perfect exercise in manipulating your fragile mind.\n");
    printf("It challenges you, twists your thoughts, and puts you in situations beyond your control.\n");
  } else if (rating >= 7 && rating <= 9) {
    printf("You rated the movie a %d.\n", rating);
    printf("This movie is a masterpiece of the mind.\n");
    printf("It expands your consciousness, heightens your perceptions, and leaves you questioning everything you thought you knew.\n");
  } else if (rating == 10) {
    printf("You rated the movie a %d.\n", rating);
    printf("This movie is the ultimate mind-bender.\n");
    printf("It takes you on a journey through endless possibilities, breaks down the walls of reality, and leaves you in a state of pure enlightenment.\n");
  } else {
    printf("Invalid rating!\n");
    printf("Please enter a rating between 1 and 10.\n");
  }

  return 0;
}