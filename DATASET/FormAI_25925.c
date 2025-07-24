//FormAI DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>

int main() {
  int rating;
  printf("Welcome to the Unique Movie Rating System!\n");
  printf("Please rate the movie you watched on a scale of 1-10: ");
  scanf("%d", &rating);

  // Check if rating is within range
  if (rating < 1 || rating > 10) {
    printf("Invalid rating!\n");
    return 0;
  }

  switch (rating) {
    case 1:
      printf("Wow, that was terrible. Why did you even bother watching?\n");
      break;
    case 2:
      printf("Yikes, that wasn't good at all. Maybe try a new genre next time.\n");
      break;
    case 3:
      printf("Not the worst movie ever, but definitely not worth recommending.\n");
      break;
    case 4:
      printf("Could have been better, but a decent effort.\n");
      break;
    case 5:
      printf("A mediocre movie. Nothing really stood out.\n");
      break;
    case 6:
      printf("An okay movie. It had some good moments but also some bad ones.\n");
      break;
    case 7:
      printf("A solid movie overall. Worth recommending to friends.\n");
      break;
    case 8:
      printf("A great movie! Definitely worth watching and talking about.\n");
      break;
    case 9:
      printf("An incredible movie that will leave you thinking about it long after it's over.\n");
      break;
    case 10:
      printf("A masterpiece! You will be talking about this movie for years to come.\n");
      break;
  }

  printf("Thanks for using the Unique Movie Rating System!\n");

  return 0;
}