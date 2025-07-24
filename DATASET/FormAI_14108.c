//FormAI DATASET v1.0 Category: Movie Rating System ; Style: careful
#include <stdio.h>

int main() {
  int rating;
  printf("Welcome to the Unique C Movie Rating System!\n");
  printf("Please rate the movie on a scale of 1-10: ");
  scanf("%d", &rating);

  switch(rating) {
    case 1:
    case 2:
      printf("Ouch, that's a terrible rating.\n");
      break;
    case 3:
    case 4:
      printf("That's not a great rating, but not entirely bad either.\n");
      break;
    case 5:
      printf("That's a mediocre rating.\n");
      break;
    case 6:
      printf("That's a decent rating. The movie must have been okay.\n");
      break;
    case 7:
      printf("That's a good rating! You must have enjoyed the movie.\n");
      break;
    case 8:
    case 9:
      printf("Wow, that's an excellent rating! You really loved the movie.\n");
      break;
    case 10:
      printf("Perfect score! This movie is a masterpiece!\n");
      break;
    default:
      printf("Sorry, that is not a valid rating.\n");
      break;
  }

  return 0;
}