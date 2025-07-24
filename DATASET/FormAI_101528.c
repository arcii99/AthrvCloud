//FormAI DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>

int main() {
  int rating;
  char movie[50];

  printf("Welcome to the Unique C Movie Rating System!\n");
  
  printf("Please enter the name of the movie: ");
  scanf("%s", movie);

  printf("Please rate the movie from 1 to 10: ");
  scanf("%d", &rating);

  if (rating < 1 || rating > 10) {
    printf("Invalid rating. Please rate the movie from 1 to 10 only.\n");
  } else if (rating < 4) {
    printf("Sorry to hear that you didn't enjoy %s. We hope you'll have a better experience with our other movies.\n", movie);
  } else if (rating < 7) {
    printf("Thanks for watching %s. Your feedback is appreciated.\n", movie);
  } else if (rating < 9) {
    printf("Glad to hear you enjoyed %s. Thank you for rating it.\n", movie);
  } else {
    printf("Wow, perfect rating for %s! Thank you for taking the time to rate it and we hope you have a great day.\n", movie);
  }

  return 0;
}