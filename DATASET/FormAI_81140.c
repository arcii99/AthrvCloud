//FormAI DATASET v1.0 Category: Movie Rating System ; Style: funny
#include <stdio.h>

int main()
{
  int rating;

  printf("Welcome to the Unique C Movie Rating System!\n");
  printf("Please rate the movie you just watched on a scale of 1-10:\n");

  scanf("%d", &rating);

  if (rating < 1 || rating > 10) {
    printf("Invalid rating. Please enter a number between 1 and 10.\n");

    //Wait for a second before asking again
    sleep(1);

    //Reuse the rating variable
    scanf("%d", &rating);
  }

  printf("Thank you for rating the movie a %d out of 10.\n", rating);

  if (rating < 5) {
    printf("Ouch, that's a rough rating. Maybe try watching the movie again to see if your opinion changes?\n");
  }
  else if (rating < 8) {
    printf("Not a bad rating, but room for improvement. Maybe tell your friends to watch this movie with you next time?\n");
  }
  else if (rating < 10) {
    printf("Great rating! You must have really enjoyed the movie. Don't forget to leave a positive review online!\n");
  }
  else {
    printf("Perfect 10 out of 10?! Wow, this movie must be an instant classic. Tell all your friends about it!\n");
  }

  return 0;
}