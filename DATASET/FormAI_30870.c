//FormAI DATASET v1.0 Category: Movie Rating System ; Style: grateful
#include <stdio.h>

int main() {
  int rating;

  printf("Welcome to the Unique C Movie Rating System\n\n");

  printf("Please enter your rating for the movie out of 10: ");
  scanf("%d", &rating);

  if(rating >= 0 && rating <= 3) {
    printf("Wow, that was terrible. Save your money next time.\n");
  } else if (rating >= 4 && rating <= 6) {
    printf("Meh, could have been better, could have been worse.\n");
  } else if (rating >= 7 && rating <= 9) {
    printf("That was pretty good! I'd recommend it to others.\n");
  } else if (rating == 10) {
    printf("PERFECTION! Enjoy your Oscar, you deserve it!\n");
  } else {
    printf("Invalid rating. Please enter a number between 0 and 10.\n");
  }

  return 0;
}